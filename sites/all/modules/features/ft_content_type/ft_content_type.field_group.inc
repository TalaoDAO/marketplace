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
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Account',
    'weight' => '0',
    'children' => array(
      0 => 'field_name_visibility',
      1 => 'field_entreprise_visibility',
      2 => 'field_entreprise',
      3 => 'account',
      4 => 'picture',
      5 => 'group_oneliner',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Account',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_account|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_address|user|user|form';
  $field_group->group_name = 'group_address';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_expert';
  $field_group->data = array(
    'label' => 'Address',
    'weight' => '1',
    'children' => array(
      0 => 'field_telephone',
      1 => 'field_address',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Address',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-address field-group-div field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_address|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|node|question1|default';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'question1';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'background',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_domaine',
      2 => 'field_reward',
      3 => 'field_expiration_date',
      4 => 'field_picto',
      5 => 'field_tags',
      6 => 'og_group_ref',
      7 => 'group_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'background',
      'instance_settings' => array(
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
  $export['group_background|node|question1|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_business|user|user|form';
  $field_group->group_name = 'group_business';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Business',
    'weight' => '3',
    'children' => array(
      0 => 'group_testimony',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Business',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_business|user|user|form'] = $field_group;

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
    'weight' => '10',
    'children' => array(
      0 => 'field_reward',
      1 => 'field_expiration_date',
      2 => 'og_group_ref',
      3 => 'field_domaine',
      4 => 'field_tags',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Common',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-common field-group-fieldset group-background',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_common|node|challenge|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_common|node|question1|form';
  $field_group->group_name = 'group_common';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'question1';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Common',
    'weight' => '3',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_domaine',
      2 => 'field_reward',
      3 => 'field_expiration_date',
      4 => 'field_picto',
      5 => 'field_tags',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Common',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-common field-group-fieldset group-background',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_common|node|question1|form'] = $field_group;

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
      0 => 'og_group_ref',
      1 => 'field_expiration_date',
      2 => 'field_reward',
      3 => 'field_picto',
      4 => 'field_domaine',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Common',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-common field-group-fieldset group-background',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_common|node|webform|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_common|user|user|form';
  $field_group->group_name = 'group_common';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Common',
    'weight' => '1',
    'children' => array(
      0 => 'field_telephone',
      1 => 'field_domaine',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Common',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_common|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_complement|user|user|form';
  $field_group->group_name = 'group_complement';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Complement',
    'weight' => '2',
    'children' => array(
      0 => 'field_notification_frequency',
      1 => 'field_known_how',
      2 => 'field_known_specific',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Complement',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_complement|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_expert|user|user|form';
  $field_group->group_name = 'group_expert';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Expert',
    'weight' => '1',
    'children' => array(
      0 => 'group_address',
      1 => 'group_misc',
      2 => 'group_skills',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Expert',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_expert|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hidden|node|question1|form';
  $field_group->group_name = 'group_hidden';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'question1';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hidden',
    'weight' => '5',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-hidden field-group-div',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_hidden|node|question1|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hidden|user|user|default';
  $field_group->group_name = 'group_hidden';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'hidden',
    'weight' => '10',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'label' => 'hidden',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-hidden field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_hidden|user|user|default'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'og_user_node',
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
        'show_label' => '0',
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
  $field_group->identifier = 'group_misc|user|user|form';
  $field_group->group_name = 'group_misc';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_expert';
  $field_group->data = array(
    'label' => 'Misc',
    'weight' => '2',
    'children' => array(
      0 => 'field_link_to_my_blog',
      1 => 'field_working_status',
      2 => 'field_sponsorship',
      3 => 'field_sponsor',
      4 => 'field_sponsor1',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Misc',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-misc field-group-div field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_misc|user|user|form'] = $field_group;

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
      0 => 'field_year_of_experiences',
      1 => 'field_skill_autoeval',
      2 => 'field_skill2',
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
  $field_group->identifier = 'group_oneliner|node|challenge|form';
  $field_group->group_name = 'group_oneliner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_what';
  $field_group->data = array(
    'label' => 'Oneliner',
    'weight' => '5',
    'children' => array(
      0 => 'field_document',
      1 => 'field_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Oneliner',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-oneliner field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_oneliner|node|challenge|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oneliner|user|user|form';
  $field_group->group_name = 'group_oneliner';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_account';
  $field_group->data = array(
    'label' => 'Oneliner',
    'weight' => '3',
    'children' => array(
      0 => 'field_first_name',
      1 => 'field_last_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Oneliner',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-oneliner field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_oneliner|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scope|node|challenge|form';
  $field_group->group_name = 'group_scope';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Scope',
    'weight' => '2',
    'children' => array(
      0 => 'field_domaine',
      1 => 'field_tags',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Scope',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-scope field-group-div group-oneliner field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_scope|node|challenge|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scope|node|question1|form';
  $field_group->group_name = 'group_scope';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'question1';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Scope',
    'weight' => '3',
    'children' => array(
      0 => 'field_domaine',
      1 => 'field_tags',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Scope',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_scope|node|question1|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scope|node|webform|form';
  $field_group->group_name = 'group_scope';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Scope',
    'weight' => '2',
    'children' => array(
      0 => 'field_domaine',
      1 => 'field_tags',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Scope',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-scope field-group-div group-oneliner field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_scope|node|webform|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_skills|user|user|form';
  $field_group->group_name = 'group_skills';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_expert';
  $field_group->data = array(
    'label' => 'Skills',
    'weight' => '3',
    'children' => array(
      0 => 'field_titre_metier',
      1 => 'field_domaine',
      2 => 'field_interests',
      3 => 'field_skills_visibility',
      4 => 'field_skills_set',
      5 => 'field_employment_history',
      6 => 'field_entreprise_description',
      7 => 'field_other_areas',
      8 => 'field_specific_skills3',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Skills',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-skills field-group-div field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_skills|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target|node|challenge|form';
  $field_group->group_name = 'group_target';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Target',
    'weight' => '4',
    'children' => array(
      0 => 'field_reward',
      1 => 'field_expiration_date',
      2 => 'og_group_ref',
      3 => 'field_request_circle',
      4 => 'field_pre_members',
      5 => 'field_other_members',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Target',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_target|node|challenge|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target|node|poll|form';
  $field_group->group_name = 'group_target';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'poll';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Target',
    'weight' => '2',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_domaine',
      2 => 'field_tags',
      3 => 'field_reward',
      4 => 'field_expiration_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-target field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_target|node|poll|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target|node|question1|form';
  $field_group->group_name = 'group_target';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'question1';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Target',
    'weight' => '7',
    'children' => array(
      0 => 'field_reward',
      1 => 'field_expiration_date',
      2 => 'field_pre_members',
      3 => 'og_group_ref',
      4 => 'field_request_circle',
      5 => 'field_other_members',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Target',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_target|node|question1|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_target|node|webform|form';
  $field_group->group_name = 'group_target';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Target',
    'weight' => '4',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_expiration_date',
      2 => 'field_reward',
      3 => 'field_request_circle',
      4 => 'field_pre_members',
      5 => 'field_other_members',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Target',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_target|node|webform|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_testimony|user|user|form';
  $field_group->group_name = 'group_testimony';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_business';
  $field_group->data = array(
    'label' => 'I wish to share my experience with emindhub',
    'weight' => '4',
    'children' => array(
      0 => 'field_testimony',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'I wish to share my experience with emindhub',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-testimony field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_testimony|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_title|node|question1|default';
  $field_group->group_name = 'group_title';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'question1';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'title',
    'weight' => '8',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-title field-group-div',
        'id' => '',
      ),
    ),
  );
  $export['group_title|node|question1|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_what|node|challenge|form';
  $field_group->group_name = 'group_what';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'group_oneliner',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'What',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_what|node|challenge|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_what|node|poll|form';
  $field_group->group_name = 'group_what';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'poll';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What',
    'weight' => '1',
    'children' => array(
      0 => 'field_description',
      1 => 'title',
      2 => 'choice_wrapper',
      3 => 'settings',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-what field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_what|node|poll|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_what|node|question1|form';
  $field_group->group_name = 'group_what';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'question1';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What',
    'weight' => '1',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'What',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_what|node|question1|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_what|node|webform|form';
  $field_group->group_name = 'group_what';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_duration_of_the_mission',
      2 => 'field_start_date',
      3 => 'field_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'What',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_what|node|webform|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_who|node|challenge|form';
  $field_group->group_name = 'group_who';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Who',
    'weight' => '3',
    'children' => array(
      0 => 'field_use_my_entreprise',
      1 => 'field_entreprise_description',
      2 => 'field_anonymous',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Who',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_who|node|challenge|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_who|node|poll|form';
  $field_group->group_name = 'group_who';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'poll';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Who',
    'weight' => '0',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-who field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_who|node|poll|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_who|node|question1|form';
  $field_group->group_name = 'group_who';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'question1';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Who',
    'weight' => '6',
    'children' => array(
      0 => 'field_anonymous',
      1 => 'field_use_my_entreprise',
      2 => 'field_entreprise_description',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Who',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_who|node|question1|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_who|node|webform|form';
  $field_group->group_name = 'group_who';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Who',
    'weight' => '3',
    'children' => array(
      0 => 'field_anonymous',
      1 => 'field_use_my_entreprise',
      2 => 'field_entreprise_description',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Who',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_who|node|webform|form'] = $field_group;

  return $export;
}
