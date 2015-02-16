<?php
/**
 * @file
 * og_visibility.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function og_visibility_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-group-group_visibility'
  $field_instances['node-group-group_visibility'] = array(
    'bundle' => 'group',
    'default_value' => array(
      0 => array(
        'value' => '0',
      ),
    ),
    'deleted' => '0',
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'group_visibility',
    'label' => 'Group and content visibility',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'view modes' => array(
      'full' => array(
        'label' => 'above',
        'type' => 'list_default',
      ),
      'teaser' => array(
        'label' => 'above',
        'type' => 'list_default',
      ),
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
    'widget_type' => 'options_select',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Group and content visibility');

  return $field_instances;
}
