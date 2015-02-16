<?php
/**
 * @file
 * og_visibility.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function og_visibility_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'group_visibility'
  $field_bases['group_visibility'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'group_visibility',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => '0',
    'module' => 'list',
    'no_ui' => TRUE,
    'settings' => array(
      'allowed_values' => array(
        0 => 'Public - group and content visible to everyone',
        1 => 'Private - group visible to everyone, content restricted to group members',
        2 => 'Hidden - group and content visible only to group members',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'type' => 'list_integer',
  );

  return $field_bases;
}
