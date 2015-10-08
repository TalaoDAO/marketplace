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
      0 => 'field_first_name',
      1 => 'field_last_name',
      2 => 'field_name_visibility',
      3 => 'field_entreprise_visibility',
      4 => 'field_entreprise',
      5 => 'field_photo',
      6 => 'account',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Account',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-account field-group-div',
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
        'classes' => 'group-address field-group-div',
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
    'weight' => '10',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(),
    ),
  );
  $export['group_background|node|question1|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background|user|user|default';
  $field_group->group_name = 'group_background';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'My background',
    'weight' => '2',
    'children' => array(
      0 => 'field_employment_history',
      1 => 'field_position_list',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'My background',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'profile-section profile-section-background field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_background|user|user|default'] = $field_group;

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
    'weight' => '3',
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
        'classes' => 'group-complement field-group-div',
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
  $field_group->identifier = 'group_container_background|user|user|default';
  $field_group->group_name = 'group_container_background';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_background';
  $field_group->data = array(
    'label' => 'Container background',
    'weight' => '4',
    'children' => array(
      0 => 'field_employment_history',
      1 => 'field_position_list',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Container background',
      'instance_settings' => array(
        'classes' => 'section-container group-container-background field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_container_background|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_container_interests|user|user|default';
  $field_group->group_name = 'group_container_interests';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_interests';
  $field_group->data = array(
    'label' => 'Interests container',
    'weight' => '45',
    'children' => array(
      0 => 'field_other_areas',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Interests container',
      'instance_settings' => array(
        'classes' => 'section-container group-container-interests field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_container_interests|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_container_public_darken|user|user|default';
  $field_group->group_name = 'group_container_public_darken';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_public_profile';
  $field_group->data = array(
    'label' => 'public container darken',
    'weight' => '9',
    'children' => array(
      0 => 'field_link_to_my_blog',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'public container darken',
      'instance_settings' => array(
        'classes' => 'section-container section-container-darken group-container-public-darken field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_container_public_darken|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_container_public|user|user|default';
  $field_group->group_name = 'group_container_public';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_public_profile';
  $field_group->data = array(
    'label' => 'public container',
    'weight' => '8',
    'children' => array(
      0 => 'group_row',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'public container',
      'instance_settings' => array(
        'classes' => 'section-container group-container-public field-group-html-element ',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_container_public|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_container_skills|user|user|default';
  $field_group->group_name = 'group_container_skills';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_skills';
  $field_group->data = array(
    'label' => 'Skills container',
    'weight' => '39',
    'children' => array(
      0 => 'field_domaine',
      1 => 'field_skills_set',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Skills container',
      'instance_settings' => array(
        'classes' => 'section-container group-container-skills field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_container_skills|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_container_testimony|user|user|default';
  $field_group->group_name = 'group_container_testimony';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_testimony';
  $field_group->data = array(
    'label' => 'Testimony container',
    'weight' => '8',
    'children' => array(
      0 => 'field_testimony',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Testimony container',
      'instance_settings' => array(
        'classes' => 'section-container group-container-testimony field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_container_testimony|user|user|default'] = $field_group;

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
      3 => 'group_sponsorship',
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
    'weight' => '22',
    'children' => array(),
    'format_type' => 'html-element',
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
        'element' => 'div',
        'attributes' => '',
        'required_fields' => 1,
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
      1 => 'field_is_sponsor',
      2 => 'field_is_promoted',
      3 => 'field_is_partner',
      4 => 'ckeditor',
      5 => 'piwik',
      6 => 'privatemsg',
      7 => 'timezone',
      8 => 'contact',
      9 => 'locale',
      10 => 'group_testimony',
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
  $field_group->identifier = 'group_interests|user|user|default';
  $field_group->group_name = 'group_interests';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'My interests',
    'weight' => '3',
    'children' => array(
      0 => 'field_other_areas',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'My interests',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'profile-section profile-section-interests field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_interests|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_label2|node|challenge|form';
  $field_group->group_name = 'group_label2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_oneliner3';
  $field_group->data = array(
    'label' => 'Your organisation *',
    'weight' => '24',
    'children' => array(
      0 => 'field_show_entreprise',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Your organisation *',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-label field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_label2|node|challenge|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_label2|node|question1|form';
  $field_group->group_name = 'group_label2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'question1';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_oneliner3';
  $field_group->data = array(
    'label' => 'Your organisation *',
    'weight' => '5',
    'children' => array(
      0 => 'field_show_entreprise',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Your organisation *',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-label field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'label',
        'attributes' => '',
      ),
    ),
  );
  $export['group_label2|node|question1|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_label2|node|webform|form';
  $field_group->group_name = 'group_label2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_oneliner3';
  $field_group->data = array(
    'label' => 'Your activity',
    'weight' => '41',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Your activity',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-label field-group-html-element field_use_my_entreprise',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_label2|node|webform|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_label2|user|user|form';
  $field_group->group_name = 'group_label2';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_complement';
  $field_group->data = array(
    'label' => 'How did you hear about us?',
    'weight' => '6',
    'children' => array(
      0 => 'field_known_how',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'How did you hear about us?',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-label field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'label',
        'attributes' => '',
      ),
    ),
  );
  $export['group_label2|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_label3|node|challenge|form';
  $field_group->group_name = 'group_label3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_oneliner3';
  $field_group->data = array(
    'label' => 'Your activity *',
    'weight' => '25',
    'children' => array(
      0 => 'field_use_my_entreprise',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Your activity *',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-label field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_label3|node|challenge|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_label3|node|question1|form';
  $field_group->group_name = 'group_label3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'question1';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_oneliner3';
  $field_group->data = array(
    'label' => 'Your activity *',
    'weight' => '6',
    'children' => array(
      0 => 'field_use_my_entreprise',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Your activity *',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-label field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'label',
        'attributes' => '',
      ),
    ),
  );
  $export['group_label3|node|question1|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_label3|node|webform|form';
  $field_group->group_name = 'group_label3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_oneliner3';
  $field_group->data = array(
    'label' => 'Your organisation',
    'weight' => '40',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Your organisation',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-label field-group-html-element field_show_entreprise',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_label3|node|webform|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_label3|user|user|form';
  $field_group->group_name = 'group_label3';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_misc';
  $field_group->data = array(
    'label' => 'Name of my sponsor',
    'weight' => '11',
    'children' => array(
      0 => 'field_sponsor1',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Name of my sponsor',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-label field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'label',
        'attributes' => '',
      ),
    ),
  );
  $export['group_label3|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_label|node|challenge|form';
  $field_group->group_name = 'group_label';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_oneliner3';
  $field_group->data = array(
    'label' => 'Your name *',
    'weight' => '23',
    'children' => array(
      0 => 'field_anonymous',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Your name *',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-label field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_label|node|challenge|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_label|node|question1|form';
  $field_group->group_name = 'group_label';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'question1';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_oneliner3';
  $field_group->data = array(
    'label' => 'Your name *',
    'weight' => '4',
    'children' => array(
      0 => 'field_anonymous',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Your name *',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-label field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'label',
        'attributes' => '',
      ),
    ),
  );
  $export['group_label|node|question1|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_label|node|webform|form';
  $field_group->group_name = 'group_label';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_oneliner3';
  $field_group->data = array(
    'label' => 'Your name',
    'weight' => '39',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Your name',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-label field-group-html-element field_anonymous',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_label|node|webform|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_label|user|user|form';
  $field_group->group_name = 'group_label';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_complement';
  $field_group->data = array(
    'label' => 'How often do you want to receive emindhub\'s notifications?',
    'weight' => '5',
    'children' => array(
      0 => 'field_notification_frequency',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'How often do you want to receive emindhub\'s notifications?',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-label field-group-html-element',
        'element' => 'div',
        'show_label' => '1',
        'label_element' => 'label',
        'attributes' => '',
      ),
    ),
  );
  $export['group_label|user|user|form'] = $field_group;

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
      2 => 'field_position',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Misc',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-misc field-group-div',
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
  $field_group->identifier = 'group_organisation_wrapper|field_collection_item|field_position_list|default';
  $field_group->group_name = 'group_organisation_wrapper';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_position_list';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Organisation wrapper',
    'weight' => '7',
    'children' => array(
      0 => 'field_entreprise',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Organisation wrapper',
      'instance_settings' => array(
        'classes' => 'group-wrapper-organisation field-group-html-element  col-xs-12 col-md-2',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_organisation_wrapper|field_collection_item|field_position_list|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_position_wrapper|field_collection_item|field_position_list|default';
  $field_group->group_name = 'group_position_wrapper';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_position_list';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Position wrapper',
    'weight' => '6',
    'children' => array(
      0 => 'field_position',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Position wrapper',
      'instance_settings' => array(
        'classes' => 'group-wrapper-position field-group-html-element col-xs-12 col-md-6',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_position_wrapper|field_collection_item|field_position_list|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_public_profile|user|user|default';
  $field_group->group_name = 'group_public_profile';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'My public profile',
    'weight' => '0',
    'children' => array(
      0 => 'field_first_name',
      1 => 'field_entreprise',
      2 => 'field_address',
      3 => 'field_titre_metier',
      4 => 'field_photo',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'My public profile',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'profile-section profile-section-public field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_public_profile|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_public_wrapper_image|user|user|default';
  $field_group->group_name = 'group_public_wrapper_image';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Image wrapper',
    'weight' => '8',
    'children' => array(
      0 => 'field_photo',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Image wrapper',
      'instance_settings' => array(
        'classes' => 'group-public-wrapper-image field-group-html-element col-xs-4 col-sm-2',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_public_wrapper_image|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_public_wrapper_info|user|user|default';
  $field_group->group_name = 'group_public_wrapper_info';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Info wrapper',
    'weight' => '9',
    'children' => array(
      0 => 'field_entreprise',
      1 => 'field_address',
      2 => 'group_row_names',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Info wrapper',
      'instance_settings' => array(
        'classes' => 'group-public-wrapper-info field-group-html-element col-xs-8 col-sm-10',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_public_wrapper_info|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_names_left|user|user|default';
  $field_group->group_name = 'group_row_names_left';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row_names';
  $field_group->data = array(
    'label' => 'left',
    'weight' => '32',
    'children' => array(
      0 => 'name',
      1 => 'group_oneliner',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'left',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-row-names-left field-group-div col-xs-12 col-sm-4',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_row_names_left|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_names_right|user|user|default';
  $field_group->group_name = 'group_row_names_right';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row_names';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '33',
    'children' => array(
      0 => 'field_titre_metier',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-row-names-left field-group-div col-xs-12 col-sm-8',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_row_names_right|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row_names|user|user|default';
  $field_group->group_name = 'group_row_names';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_public_wrapper_info';
  $field_group->data = array(
    'label' => 'row',
    'weight' => '29',
    'children' => array(
      0 => 'group_row_names_left',
      1 => 'group_row_names_right',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'row',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-row-names field-group-div row margin-after',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_row_names|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row|field_collection_item|field_position_list|default';
  $field_group->group_name = 'group_row';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_position_list';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row',
    'weight' => '0',
    'children' => array(
      0 => 'group_organisation_wrapper',
      1 => 'group_position_wrapper',
      2 => 'group_wrapper_years',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Row',
      'instance_settings' => array(
        'classes' => 'group-row field-group-html-element row',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_row|field_collection_item|field_position_list|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row|field_collection_item|field_skills_set|default';
  $field_group->group_name = 'group_row';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_skills_set';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Row',
    'weight' => '2',
    'children' => array(
      0 => 'group_wrapper_skill',
      1 => 'group_wrapper_self_appraisal',
      2 => 'group_wrapper_years',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Row',
      'instance_settings' => array(
        'classes' => 'group-row field-group-html-element row',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_row|field_collection_item|field_skills_set|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_row|user|user|default';
  $field_group->group_name = 'group_row';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_container_public';
  $field_group->data = array(
    'label' => 'Row',
    'weight' => '7',
    'children' => array(
      0 => 'group_public_wrapper_image',
      1 => 'group_public_wrapper_info',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Row',
      'instance_settings' => array(
        'classes' => 'group-row field-group-html-element row',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_row|user|user|default'] = $field_group;

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
        'classes' => 'group-scope field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
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
        'classes' => 'group-scope field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
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
        'classes' => 'group-scope field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
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
  $field_group->identifier = 'group_skills|user|user|default';
  $field_group->group_name = 'group_skills';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'My skills',
    'weight' => '1',
    'children' => array(
      0 => 'field_domaine',
      1 => 'field_skills_set',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'My skills',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'profile-section profile-section-skills field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_skills|user|user|default'] = $field_group;

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
    'weight' => '4',
    'children' => array(
      0 => 'field_titre_metier',
      1 => 'field_domaine',
      2 => 'field_skills_visibility',
      3 => 'field_skills_set',
      4 => 'field_employment_history',
      5 => 'field_entreprise_description',
      6 => 'field_other_areas',
      7 => 'field_specific_skills3',
      8 => 'field_cv',
      9 => 'field_position_list',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Skills',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-skills field-group-div',
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
  $field_group->identifier = 'group_sponsorship|user|user|form';
  $field_group->group_name = 'group_sponsorship';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_expert';
  $field_group->data = array(
    'label' => 'Sponsorship',
    'weight' => '3',
    'children' => array(
      0 => 'field_sponsorship',
      1 => 'field_sponsor1',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Sponsorship',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-sponsorship field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_sponsorship|user|user|form'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'field_expiration_date',
      1 => 'og_group_ref',
      2 => 'field_request_circle',
      3 => 'field_other_members',
      4 => 'field_reward',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Target',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-target field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
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
    'weight' => '5',
    'children' => array(
      0 => 'field_expiration_date',
      1 => 'og_group_ref',
      2 => 'field_request_circle',
      3 => 'field_other_members',
      4 => 'field_reward',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Target',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-target field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
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
    'weight' => '6',
    'children' => array(
      0 => 'og_group_ref',
      1 => 'field_expiration_date',
      2 => 'field_request_circle',
      3 => 'field_other_members',
      4 => 'field_reward',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Target',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
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
  $field_group->identifier = 'group_testimony|user|user|default';
  $field_group->group_name = 'group_testimony';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'My testimony',
    'weight' => '4',
    'children' => array(
      0 => 'field_testimony',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'My testimony',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'profile-section profile-section-testimony field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_testimony|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_testimony|user|user|form';
  $field_group->group_name = 'group_testimony';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_hidden';
  $field_group->data = array(
    'label' => 'Share your experience',
    'weight' => '2',
    'children' => array(
      0 => 'field_testimony',
      1 => 'field_partner_why',
      2 => 'field_sponsor_why',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Share your experience',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-testimony field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
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
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'title',
    'weight' => '11',
    'children' => array(),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(),
    ),
  );
  $export['group_title|node|question1|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_visibility|node|challenge|form';
  $field_group->group_name = 'group_visibility';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'challenge';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Choose to make visible',
    'weight' => '3',
    'children' => array(
      0 => 'field_entreprise_description',
      1 => 'field_anonymous',
      2 => 'field_show_entreprise',
      3 => 'field_use_my_entreprise',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Choose to make visible',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-visibility field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_visibility|node|challenge|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_visibility|node|question1|form';
  $field_group->group_name = 'group_visibility';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'question1';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Choose to make visible',
    'weight' => '3',
    'children' => array(
      0 => 'field_entreprise_description',
      1 => 'field_anonymous',
      2 => 'field_use_my_entreprise',
      3 => 'field_show_entreprise',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Choose to make visible',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-visibility field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_visibility|node|question1|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_visibility|node|webform|form';
  $field_group->group_name = 'group_visibility';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webform';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Choose to make visible',
    'weight' => '3',
    'children' => array(
      0 => 'field_entreprise_description',
      1 => 'field_anonymous',
      2 => 'field_show_entreprise',
      3 => 'field_use_my_entreprise',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Choose to make visible',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-visibility field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_visibility|node|webform|form'] = $field_group;

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
      1 => 'field_document',
      2 => 'field_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'What',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-what field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
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
        'classes' => 'group-what field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
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
      4 => 'field_document',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'What',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-what field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h2',
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
      0 => 'group_oneliner4',
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
    'weight' => '4',
    'children' => array(
      0 => 'group_oneliner',
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
      0 => 'group_oneliner1',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_wrapper_self_appraisal|field_collection_item|field_skills_set|default';
  $field_group->group_name = 'group_wrapper_self_appraisal';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_skills_set';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'self appraisal wrapper',
    'weight' => '9',
    'children' => array(
      0 => 'field_skill_autoeval',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'self appraisal wrapper',
      'instance_settings' => array(
        'classes' => 'group-wrapper-self-appraisal field-group-html-element  col-xs-12 col-md-2',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_wrapper_self_appraisal|field_collection_item|field_skills_set|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_wrapper_skill|field_collection_item|field_skills_set|default';
  $field_group->group_name = 'group_wrapper_skill';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_skills_set';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'skill wrapper',
    'weight' => '8',
    'children' => array(
      0 => 'field_skill2',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'skill wrapper',
      'instance_settings' => array(
        'classes' => 'group-wrapper-skill field-group-html-element col-xs-12 col-md-6',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_wrapper_skill|field_collection_item|field_skills_set|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_wrapper_years|field_collection_item|field_position_list|default';
  $field_group->group_name = 'group_wrapper_years';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_position_list';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Years of experiences wrapper',
    'weight' => '8',
    'children' => array(
      0 => 'field_year_of_experiences',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Years of experiences wrapper',
      'instance_settings' => array(
        'classes' => 'group-wrapper-years field-group-html-element  col-xs-12 col-md-4',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_wrapper_years|field_collection_item|field_position_list|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_wrapper_years|field_collection_item|field_skills_set|default';
  $field_group->group_name = 'group_wrapper_years';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_skills_set';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_row';
  $field_group->data = array(
    'label' => 'Years of experiences wrapper',
    'weight' => '10',
    'children' => array(
      0 => 'field_year_of_experiences',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Years of experiences wrapper',
      'instance_settings' => array(
        'classes' => 'group-wrapper-years field-group-html-element  col-xs-12 col-md-4',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $export['group_wrapper_years|field_collection_item|field_skills_set|default'] = $field_group;

  return $export;
}
