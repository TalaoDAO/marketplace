<?php
/**
 * @file
 * Internal functions for the Serial module.
 *
 * Note: This module uses php in SQL to support dynamic table names.
 * (required because each serial field needs a dedicated dynamic table).
 * However, all table names are safe (passed through db_escape_table).
 *
 * It seems that this is better than using table names as arguments, e.g.
 *   $query = 'INSERT INTO %s (nid) VALUES(%d)';
 *   db_query($query, db_prefix_tables('{'. $table .'}'), $nid);
 */

/**
 * Creates an assistant serial table for a new created field.
 *
 * @param array $field
 *   Serial field.
 * @param array $instance
 *   New instance of that serial field.
 */
function _serial_create_table(array $field, array $instance) {
  $table = _serial_get_field_table_name($field, $instance);

  if (!db_table_exists($table)) {
    db_create_table($table, _serial_get_table_schema());
  }
}

/**
 * Drops an assistant serial table for a deleted field.
 *
 * @param array $field
 *   Serial field.
 * @param array $instance
 *   Deleted instance of that serial field.
 */
function _serial_drop_table(array $field, array $instance) {
  db_drop_table(_serial_get_field_table_name($field, $instance));
}

/**
 * Renames serial table(s) when a entity bundle us renamed.
 *
 * @param string $entity_type
 *   Type of entity.
 * @param string $bundle_old
 *   An old entity bundle machine name.
 * @param string $bundle_new
 *   A new entity bundle machine name.
 */
function _serial_rename_tables($entity_type, $bundle_old, $bundle_new) {
  // Build the query to find all affected tables.
  $query = db_select('field_config', 'f')
    ->fields('f', array('field_name'));

  $query->join('field_config_instance', 'i', '(f.field_name = i.field_name)');

  $query->condition('f.type', SERIAL_FIELD_TYPE);
  $query->condition('i.entity_type', $entity_type);
  $query->condition('i.bundle', $bundle_new);

  // Rename each affected table.
  foreach ($query->addTag('node_access')->execute() as $record) {
    db_rename_table(
      _serial_get_table_name($entity_type, $bundle_old, $record->field_name),
      _serial_get_table_name($entity_type, $bundle_new, $record->field_name)
    );
  }
}

/**
 * Gets the name of the assistant table for a specific field.
 *
 * @param array $field
 *   Serial field.
 * @param array $instance
 *   An instance of that serial field.
 *
 * @return string
 *   The name of the assistant table of the specified field instance.
 */
function _serial_get_field_table_name(array $field, array $instance) {
  return _serial_get_table_name($instance['entity_type'], $instance['bundle'], $field['field_name']);
}

/**
 * Gets the name of the assistant table for a specific field.
 *
 * @param string $entity_type
 *   Type of entity (e.g. node)
 * @param string $bundle
 *   The name of the entity type that contains the field (e.g. content type)
 * @param string $field_name
 *   The name of the field.
 *
 * @return string
 *   The name of the assistant table of the specified field.
 */
function _serial_get_table_name($entity_type, $bundle, $field_name) {
  // Remember about max length of MySQL tables - 64 symbols.
  // @todo Think about improvement for this.
  return db_escape_table('serial_' . md5("{$entity_type}_{$bundle}_{$field_name}"));
}

/**
 * Gets the schema of the assistant tables for generating serial values.
 *
 * @return array
 *   Assistant table schema.
 */
function _serial_get_table_schema() {
  return array(
    'fields' => array(
      'sid' => array(
        'type' => SERIAL_FIELD_TYPE,
        'not null' => TRUE,
        'unsigned' => TRUE,
        'description' => 'The atomic serial field.',
      ),
      'uniqid' => array(
        'type' => 'varchar',
        'length' => 23,
        'default' => '',
        'not null' => TRUE,
        'description' => 'Unique temporary allocation Id.',
      ),
    ),
    'primary key' => array('sid'),
    'unique keys' => array(
      'uniqid' => array('uniqid'),
    ),
  );
}

/**
 * Generates a unique serial value (unique per entity bundle).
 *
 * @param string $entity_type
 *   Type of entity (e.g. node)
 * @param string $bundle
 *   Containing bundle (e.g. content type).
 * @param string $field_name
 *   The field name.
 * @param bool $delete
 *   Indicates if temporary records should be deleted.
 *
 * @return int
 *   the unique serial value number.
 *
 * @throws \Exception
 */
function _serial_generate_value($entity_type, $bundle, $field_name, $delete = TRUE) {
  $transaction = db_transaction();

  try {
    // Get the name of the relevant table.
    $table = _serial_get_table_name($entity_type, $bundle, $field_name);
    // Insert a temporary record to get a new unique serial value.
    $uniqid = uniqid('', TRUE);
    $sid = db_insert($table)
      ->fields(array('uniqid' => $uniqid))
      ->execute();

    // If there's a reason why it's come back undefined, reset it.
    $sid = isset($sid) ? $sid : 0;

    // Delete the temporary record.
    if ($delete && $sid && ($sid % 10) == 0) {
      db_delete($table)
        ->condition('sid', $sid, '<')
        ->execute();
    }

    // Return the new unique serial value.
    return $sid;
  }
  catch (Exception $e) {
    $transaction->rollback();
    watchdog_exception('serial', $e);
    throw $e;
  }
}

/**
 * Initializes the value of a new serial field in existing entities.
 *
 * @param string $entity_type
 *   Type of entity (e.g. node)
 * @param string $bundle
 *   Containing bundle (e.g. content type).
 * @param string $field_name
 *   The field name.
 *
 * @return int
 *   Number of existing entities that have been initialized.
 */
function _serial_init_old_entities($entity_type, $bundle, $field_name) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', $entity_type)
    ->fieldCondition($field_name);

  // The "comment" entity type does not support bundle conditions.
  // @see https://api.drupal.org/api/drupal/includes!entity.inc/function/EntityFieldQuery%3A%3AentityCondition/7
  if ('comment' !== $entity_type) {
    $query->entityCondition('bundle', $bundle);
  }

  $results = $query->execute();

  if (!empty($results[$entity_type])) {
    foreach ($results[$entity_type] as $entity) {
      list($id, , $bundle) = entity_extract_ids($entity_type, $entity);

      $entity = entity_load_unchanged($entity_type, $id);
      $entity->{$field_name} = array(
        LANGUAGE_NONE => array(
          array(
            'value' => _serial_generate_value($entity_type, $bundle, $field_name, FALSE),
          ),
        ),
      );

      field_attach_insert($entity_type, $entity);
    }

    return count($results[$entity_type]);
  }

  return 0;
}

/**
 * Retrieves all the managed serial fields.
 *
 * @return string[]
 *   Result set containing entity type, entity bundle, field name.
 */
function _serial_get_all_fields() {
  $query = db_select('field_config', 'f');
  $query->join('field_config_instance', 'i', 'i.field_name = f.field_name');

  return $query
    ->fields('i', array('entity_type', 'bundle', 'field_name'))
    ->condition('f.type', SERIAL_FIELD_TYPE)
    ->condition('i.deleted', 0)
    ->execute()
    ->fetchAll();
}
