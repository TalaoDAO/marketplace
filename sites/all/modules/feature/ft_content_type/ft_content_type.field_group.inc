<?php
/**
 * @file
 * ft_content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ft_content_type_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_complement|profile2|expert|form';
  $field_group->group_name = 'group_complement';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'expert';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Complement',
    'weight' => '13',
    'children' => array(
      0 => 'field_notification_frequency',
      1 => 'field_known_how',
      2 => 'field_known_specific',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-complement field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_complement|profile2|expert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mission|node|webform|form';
  $field_group->group_name = 'group_mission';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Mission',
    'weight' => '3',
    'children' => array(
      0 => 'body',
      1 => 'field_nom_de_l_organisation',
      2 => 'field_duration_of_the_mission',
      3 => 'field_start_date',
      4 => 'field_salary_range',
      5 => 'field_reference',
      6 => 'field_object_of_the_mission',
      7 => 'field_anonymous',
      8 => 'field_has_salary',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-mission field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_mission|node|webform|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_skills|profile2|expert|form';
  $field_group->group_name = 'group_skills';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'expert';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Skills',
    'weight' => '10',
    'children' => array(
      0 => 'field_domaine',
      1 => 'field_skills_set',
      2 => 'field_skills_visibility',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Skills',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-skills field-group-fieldset',
        'description' => 'Searched skills',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_skills|profile2|expert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sponsor|profile2|expert|form';
  $field_group->group_name = 'group_sponsor';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'expert';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sponsor',
    'weight' => '8',
    'children' => array(
      0 => 'field_sponsorship',
      1 => 'field_sponsor',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sponsor field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_sponsor|profile2|expert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_visibility|profile2|main|form';
  $field_group->group_name = 'group_visibility';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Visibility',
    'weight' => '4',
    'children' => array(
      0 => 'field_name_visibility',
      1 => 'field_entreprise_visibility',
      2 => 'field_profile_visibility',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-visibility field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_visibility|profile2|main|form'] = $field_group;

  return $export;
}
