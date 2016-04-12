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
 * Renames serial table(s) when a content type us renamed.
 *
 * @param string $old_type
 *   An old node type machine name.
 * @param string $new_type
 *   A new node type machine name.
 */
function _serial_rename_tables($old_type, $new_type) {
  // Build the query to find all affected tables.
  $query = db_select('field_config', 'f')
    ->fields('f', array('field_name'));

  $query->join(
    'field_config_instance',
    'i',
    "f.field_name = i.field_name AND f.type = 'serial' AND i.bundle = '$new_type'"
  );

  // Rename each affected table.
  foreach ($query->addTag('node_access')->execute() as $record) {
    db_rename_table(
      _serial_get_table_name($old_type, $record->field_name),
      _serial_get_table_name($new_type, $record->field_name)
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
  return _serial_get_table_name($instance['bundle'], $field['field_name']);
}

/**
 * Gets the name of the assistant table for a specific field.
 *
 * @param string $bundle
 *   The name of the entity type that contains the field.
 * @param string $field_name
 *   The name of the field.
 *
 * @return string
 *   the name of the assistant table of the specified field.
 */
function _serial_get_table_name($bundle, $field_name) {
  return db_escape_table('serial_' . $bundle . '_' . $field_name);
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
        'type' => 'serial',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => 'The atomic serial field.',
      ),
      'uniqid' => array(
        'description' => 'Unique temporary allocation Id.',
        'type' => 'varchar',
        'length' => 23,
        'not null' => TRUE,
        'default' => ''),
    ),
    'primary key' => array('sid'),
    'unique keys' => array(
      'uniqid' => array('uniqid'),
    ),
  );
}

/**
 * Generates a unique serial value (unique per node type).
 *
 * @param string $bundle
 *   Containing bundle (e.g. content type).
 * @param string $field_name
 *   The field name.
 * @param bool $delete
 *   Indicates if temporary records should be deleted.
 *
 * @return int
 *   the unique serial value number.
 */
function _serial_generate_value($bundle, $field_name, $delete = TRUE) {
  // Get the name of the relevant table.
  $table = _serial_get_table_name($bundle, $field_name);

  // Insert a temporary record to get a new unique serial value.
  $uniqid = uniqid('', TRUE);
  $sid = db_insert($table)
    ->fields(array('uniqid' => $uniqid))
    ->execute();

  // If there's a reason why it's come back undefined, reset it.
  $sid = isset($sid) ? $sid : 0;

  // Delete the temporary record.
  if ($delete && ($sid % 10) == 0) {
    db_delete($table)
      ->condition('uniqid', $uniqid)
      ->execute();
  }

  // Return the new unique serial value.
  return $sid;
}

/**
 * Initializes the value of a new serial field in existing nodes.
 *
 * @todo Currently works only for nodes - should support comments and users.
 *
 * @param string $bundle
 *   Containing bundle (e.g. content type).
 * @param string $field_name
 *   The field name.
 *
 * @return int
 *   Number of existing nodes that have been initialized.
 */
function _serial_init_old_nodes($bundle, $field_name) {
  $nodes = node_load_multiple(array(), array('type' => $bundle));

  // Allocate a serial number for every old node.
  foreach ($nodes as $node) {
    $node->{$field_name} = array(
      LANGUAGE_NONE => array(
        array(
          'value' => _serial_generate_value($bundle, $field_name, FALSE),
        ),
      ),
    );

    node_save($node);
  }

  // Return the number of existing nodes that have been initialized.
  return count($nodes);
}

/**
 * Retrieves all the managed serial fields.
 *
 * @return array
 *   Pairs of node type name, field name.
 */
function _serial_get_all_fields() {
  $query = db_select('field_config', 'f');
  $query->join('field_config_instance', 'i', 'i.field_name = f.field_name');

  return $query->fields('i', array('bundle', 'field_name'))
    ->condition('f.type', 'serial')
    ->condition('i.deleted', 0)
    ->execute()
    ->fetchAll();
}
