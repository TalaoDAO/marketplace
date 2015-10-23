<?php
/**
 * @file
 * ft_content_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ft_content_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_picto'
  $field_bases['field_picto'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_picto',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 2,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'profile2_private' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}
