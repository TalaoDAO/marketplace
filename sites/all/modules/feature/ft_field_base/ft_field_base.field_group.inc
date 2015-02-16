<?php
/**
 * @file
 * ft_field_base.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ft_field_base_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_common|node|challenge|form';
  $field_group->group_name = 'group_common';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Common',
    'weight' => '13',
    'children' => array(
      0 => 'field_reward',
      1 => 'field_expiration_date',
      2 => 'og_group_ref',
      3 => 'field_picto',
      4 => 'field_domaine',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-common field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_common|node|challenge|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_common|node|question|form';
  $field_group->group_name = 'group_common';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'question';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Common',
    'weight' => '7',
    'children' => array(
      0 => 'field_domaine',
      1 => 'field_expiration_date',
      2 => 'field_reward',
      3 => 'og_group_ref',
      4 => 'field_picto',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-common field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_common|node|question|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_common|node|webform|form';
  $field_group->group_name = 'group_common';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Common',
    'weight' => '3',
    'children' => array(
      0 => 'field_domaine',
      1 => 'og_group_ref',
      2 => 'field_expiration_date',
      3 => 'field_reward',
      4 => 'field_picto',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-common field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_common|node|webform|form'] = $field_group;

  return $export;
}
