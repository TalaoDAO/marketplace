<?php
/**
 * @file
 * ft_content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ft_content_type_field_group_info() {
  $field_groups = array();

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
    'label' => 'Personal information',
    'weight' => '0',
    'children' => array(
      0 => 'field_first_name',
      1 => 'field_last_name',
      2 => 'field_entreprise',
      3 => 'field_address',
      4 => 'field_link_to_my_blog',
      5 => 'field_titre_metier',
      6 => 'field_working_status',
      7 => 'field_domaine',
      8 => 'field_skills_set',
      9 => 'field_employment_history',
      10 => 'field_entreprise_description',
      11 => 'field_other_areas',
      12 => 'field_photo',
      13 => 'field_position',
      14 => 'field_cv',
      15 => 'field_position_list',
      16 => 'field_needs_for_expertise',
      17 => 'field_availability',
      18 => 'field_education',
      19 => 'field_emh_usage',
      20 => 'field_linkedin',
      21 => 'field_twitter',
      22 => 'field_activities_linkedin',
      23 => 'account',
      24 => 'group_skills',
      25 => 'group_needs',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Personal information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-account field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_account|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_address|user|user|form';
  $field_group->group_name = 'group_address';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_hidden';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '13',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact',
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
  $field_groups['group_address|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_complement|user|user|form';
  $field_group->group_name = 'group_complement';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_hidden';
  $field_group->data = array(
    'label' => 'Complement',
    'weight' => '18',
    'children' => array(),
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
  $field_groups['group_complement|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_expert|user|user|form';
  $field_group->group_name = 'group_expert';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_hidden';
  $field_group->data = array(
    'label' => 'Expert',
    'weight' => '19',
    'children' => array(),
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
  $field_groups['group_expert|user|user|form'] = $field_group;

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
      0 => 'og_user_node',
      1 => 'field_telephone',
      2 => 'field_specific_skills3',
      3 => 'field_is_sponsor',
      4 => 'field_is_promoted',
      5 => 'field_is_partner',
      6 => 'field_mail',
      7 => 'field_profile_purchased',
      8 => 'field_nb_contacts_linkedin',
      9 => 'field_tracking_key',
      10 => 'field_tracking_referer',
      11 => 'ckeditor',
      12 => 'mimemail',
      13 => 'timezone',
      14 => 'contact',
      15 => 'locale',
      16 => 'group_testimony',
      17 => 'group_address',
      18 => 'group_organisation',
      19 => 'group_sponsorship',
      20 => 'group_complement',
      21 => 'group_expert',
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
  $field_groups['group_hidden|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_misc|user|user|form';
  $field_group->group_name = 'group_misc';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Other',
    'weight' => '1',
    'children' => array(
      0 => 'field_notification_frequency',
      1 => 'field_known_how',
      2 => 'field_known_specific',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Other',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-misc field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_misc|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_needs|user|user|form';
  $field_group->group_name = 'group_needs';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_account';
  $field_group->data = array(
    'label' => 'You need expertise',
    'weight' => '48',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'You need expertise',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-needs field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_needs|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organisation|user|user|form';
  $field_group->group_name = 'group_organisation';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_hidden';
  $field_group->data = array(
    'label' => 'Organisation',
    'weight' => '15',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Organisation',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-organisation field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_organisation|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_skills|user|user|form';
  $field_group->group_name = 'group_skills';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_account';
  $field_group->data = array(
    'label' => 'You have expertise to offer',
    'weight' => '40',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'You have expertise to offer',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-skills field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_skills|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sponsorship|user|user|form';
  $field_group->group_name = 'group_sponsorship';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_hidden';
  $field_group->data = array(
    'label' => 'Sponsorship',
    'weight' => '17',
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
  $field_groups['group_sponsorship|user|user|form'] = $field_group;

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
    'weight' => '8',
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
        'classes' => 'group-testimony field-group-fieldset',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_testimony|user|user|form'] = $field_group;

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
  $field_groups['group_wrapper_years|field_collection_item|field_skills_set|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Complement');
  t('Contact');
  t('Expert');
  t('Hidden');
  t('Organisation');
  t('Other');
  t('Personal information');
  t('Share your experience');
  t('Sponsorship');
  t('Years of experiences wrapper');
  t('You have expertise to offer');
  t('You need expertise');

  return $field_groups;
}
