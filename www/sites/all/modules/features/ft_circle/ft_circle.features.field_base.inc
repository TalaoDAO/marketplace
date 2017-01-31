<?php
/**
 * @file
 * ft_circle.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ft_circle_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_circle_logo'.
  $field_bases['field_circle_logo'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_circle_logo',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'imagefield_crop',
    'settings' => array(
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'imagefield_crop',
  );

  // Exported field_base: 'field_free_circle'.
  $field_bases['field_free_circle'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_free_circle',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Paying circle',
        1 => 'Free circle',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
