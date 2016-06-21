<?php
/**
 * @file
 * ft_request.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ft_request_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_options'.
  $field_bases['field_options'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_options',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'emh_request',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'emh_option_selector',
  );

  // Exported field_base: 'field_request_documents'.
  $field_bases['field_request_documents'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_request_documents',
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
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'profile2_private' => FALSE,
      'uri_scheme' => 'private',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  return $field_bases;
}
