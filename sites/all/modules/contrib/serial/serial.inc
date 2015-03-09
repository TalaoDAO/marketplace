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
 * @param $field
 *   a serial field
 * @param $instance
 *   a new instance of that serial field
 */
function _serial_create_table($field, $instance) {
  $table = _serial_get_field_table_name($field, $instance);
  $schema = _serial_get_table_schema();
  db_create_table($table, $schema);
}

/**
 * Drops an assistant serial table for a deleted field.
 *
 * @param $field
 *   a serial field
 * @param $instance
 *   a deleted instance of that serial field
 */
function _serial_drop_table($field, $instance) {
  $table = _serial_get_field_table_name($field, $instance);
  db_drop_table($table);
}

/**
 * Renames serial table(s) when a content type us renamed.
 *
 * @param $old_type
 *   an old node type machine name
 * @param $new_type
 *   a new node type machine name
 */
function _serial_rename_tables($old_type, $new_type) {

  // Build the query to find all affected tables.
  $query = db_select('field_config', 'f')->fields('f', array('field_name'));
  $table_joined_alias = $query->join(
      'field_config_instance', 'i',
      '(f.field_name = i.field_name) AND ' .
      '(f.type = :field_type) AND (i.bundle = :bundle_type)',
      array(':field_type' => 'serial', ':bundle_type' => $new_type)
  );

  // Add an access check and execute it.
  $result = $query->addTag('node_access')->execute();

  // Rename each affected table.
  foreach ($result as $record) {
    $old_table = _serial_get_table_name($old_type, $record->field_name);
    $new_table = _serial_get_table_name($new_type, $record->field_name);
    db_rename_table($old_table, $new_table);
  }
}

/**
 * Gets the name of the assistant table for a specific field.
 *
 * @param $field
 *   a serial field
 * @param $instance
 *   an instance of that serial field
 * @return
 *   the name of the assistant table of the specified field instance.
 */
function _serial_get_field_table_name($field, $instance) {
  return _serial_get_table_name($instance['bundle'], $field['field_name']);
}

/**
 * Gets the name of the assistant table for a specific field.
 *
 * @param $bundle
 *   the name of the entity type that contains the field
 * @param $field_name
 *   the name of the field
 * @return
 *   the name of the assistant table of the specified field.
 */
function _serial_get_table_name($bundle, $field_name) {
  return db_escape_table( // be on the safe side
    'serial_' . $bundle . '_' . $field_name);
}

/**
 * Gets the schema of the assistant tables for generating serial values.
 *
 * @return
 *   the assistant table schema.
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
 * @param $nid
 *   id of the node for which to generate a serial value
 * @param $bundle
 *   a containing bundle (e.g. content type)
 * @param $field_name
 *   the field name
 * @param $delete
 *   indicates if temporary records should be deleted
 * @return
 *   the unique serial value number.
 */
function _serial_generate_value($bundle, $field_name, $delete = TRUE) {

  // Get the name of the relevant table.
  $table = _serial_get_table_name($bundle, $field_name);

  // Insert a temporary record to get a new unique serial value.
  $uniqid = uniqid('', TRUE);
  $sid = db_insert($table)
    ->fields(array(
      'uniqid' => $uniqid,
    ))
    ->execute();

  // If there's a reason why it's come back undefined, reset it.
  $sid = isset($sid) ? $sid : 0;

  // Delete the temporary record.
  if ($delete && ($sid % 10) == 0) {
  db_delete($table)
    ->condition('uniqid', $uniqid, '=')
    ->execute();
  }

  // Return the new unique serial value.
  return $sid;
}

/**
 * Initializes the value of a new serial field in existing nodes.
 *
 * @param $bundle
 *   a containing bundle (e.g. content type)
 * @param $field_name
 *   the field name
 * @return
 *   the number of existing nodes that have been initialized.
 */
function _serial_init_old_nodes($bundle, $field_name) {
  // Retrieve all the node ids of that type:
  $query = "SELECT nid FROM {node} WHERE type = :type ORDER BY nid";
    // TODO: Currently works only for nodes - should support comments and users.
  $result = db_query($query, array('type' => $bundle));

  // Allocate a serial number for every old node:
  $count = 0;
  foreach ($result as $node) {
    $nid = $node->nid;
    $node = node_load($nid);
    $sid = _serial_generate_value($bundle, $field_name, FALSE);
    $node->{$field_name} = array('und' => array(array('value' => $sid)));
    node_save($node);
    $count++;
  }

  // Return the number of existing nodes that have been initialized:
  return $count;
}

/**
 * Retrieves all the managed serial fields.
 *
 * @return result set containing pairs of (node type name, field name).
 */
function _serial_get_all_fields() {
  $query = db_select('field_config', 'f');
  $query->join('field_config_instance', 'i', 'i.field_name = f.field_name');
  $query->fields('i', array('bundle', 'field_name'))
        ->condition('f.type', 'serial', '=')
        ->condition('i.deleted', 0, '=');
  $result = $query->execute();
  return $result->fetchAll();
}

