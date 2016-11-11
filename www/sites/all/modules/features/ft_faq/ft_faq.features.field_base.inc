<?php
/**
 * @file
 * ft_faq.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ft_faq_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_faq_role'.
  $field_bases['field_faq_role'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_faq_role',
    'field_permissions' => array(
      'owner_field' => 'Comment',
      'type' => 0,
    ),
    'indexes' => array(
      'rid' => array(
        0 => 'rid',
      ),
    ),
    'locked' => 0,
    'module' => 'rolereference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'referenceable_roles' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 4,
        5 => 5,
        6 => 0,
        7 => 0,
        10 => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'rolereference',
  );

  return $field_bases;
}
