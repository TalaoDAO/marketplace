<?php
/**
 * @file
 * ft_circle.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ft_circle_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_circle_instructions|node|circle|form';
  $field_group->group_name = 'group_circle_instructions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'circle';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'How it works?',
    'weight' => '6',
    'children' => array(
      0 => 'field_circle_instructions',
      1 => 'field_circle_qa',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'How it works?',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-circle-instructions field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_circle_instructions|node|circle|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('How it works?');

  return $field_groups;
}
