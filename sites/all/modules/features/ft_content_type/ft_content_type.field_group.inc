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
  $field_group->identifier = 'group_account|user|user|form';
  $field_group->group_name = 'group_account';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Account',
    'weight' => '0',
    'children' => array(
      0 => 'og_user_node',
      1 => 'account',
      2 => 'picture',
      3 => 'group_oneliner',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-account field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_account|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|user|user|form';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'background',
    'weight' => '0',
    'children' => array(
      0 => 'group_account',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'background',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-background field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_background|user|user|form'] = $field_group;

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
    'weight' => '7',
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
  $field_group->identifier = 'group_common|node|webform|form';
  $field_group->group_name = 'group_common';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Common',
    'weight' => '7',
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
    'weight' => '9',
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
  $field_group->identifier = 'group_hidden|user|user|form';
  $field_group->group_name = 'group_hidden';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hidden',
    'weight' => '3',
    'children' => array(
      0 => 'tmgmt_translation_skills',
      1 => 'masquerade',
      2 => 'privatemsg',
      3 => 'timezone',
      4 => 'contact',
      5 => 'locale',
      6 => 'wysiwyg',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Hidden',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-hidden field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_hidden|user|user|form'] = $field_group;

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
  $field_group->identifier = 'group_oneliner|field_collection_item|field_skills_set|form';
  $field_group->group_name = 'group_oneliner';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_skills_set';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Oneliner',
    'weight' => '0',
    'children' => array(
      0 => 'field_skill',
      1 => 'field_year_of_experiences',
      2 => 'field_skill_autoeval',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Oneliner',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-oneliner field-group-div oneliner',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_oneliner|field_collection_item|field_skills_set|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personnal|profile2|expert|form';
  $field_group->group_name = 'group_personnal';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'expert';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personnal',
    'weight' => '0',
    'children' => array(
      0 => 'field_referent',
      1 => 'field_address',
      2 => 'field_link_to_my_blog',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-personnal field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_personnal|profile2|expert|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_professional|profile2|expert|form';
  $field_group->group_name = 'group_professional';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'expert';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Professionnal',
    'weight' => '1',
    'children' => array(
      0 => 'field_titre_metier',
      1 => 'field_entreprise',
      2 => 'field_entreprise_visibility',
      3 => 'field_working_status',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-professional field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_professional|profile2|expert|form'] = $field_group;

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
    'weight' => '8',
    'children' => array(
      0 => 'field_domaine',
      1 => 'field_employment_history',
      2 => 'field_skills_set',
      3 => 'field_skills_visibility',
      4 => 'field_interests',
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
    'weight' => '2',
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

  return $export;
}
