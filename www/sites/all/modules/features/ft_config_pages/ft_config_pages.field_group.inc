<?php
/**
 * @file
 * ft_config_pages.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ft_config_pages_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hp_clients|config_pages|homepage|form';
  $field_group->group_name = 'group_hp_clients';
  $field_group->entity_type = 'config_pages';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Clients',
    'weight' => '3',
    'children' => array(
      0 => 'field_hp_clients',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Clients',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-hp-clients field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hp_domains|config_pages|homepage|form';
  $field_group->group_name = 'group_hp_domains';
  $field_group->entity_type = 'config_pages';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Domains',
    'weight' => '2',
    'children' => array(
      0 => 'field_hp_domains_title',
      1 => 'field_hp_domains',
      2 => 'field_hp_domains_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Domains',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-hp-domains field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hp_hero|config_pages|homepage|form';
  $field_group->group_name = 'group_hp_hero';
  $field_group->entity_type = 'config_pages';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hero',
    'weight' => '0',
    'children' => array(
      0 => 'field_hp_hero_link',
      1 => 'field_hp_hero_experts',
      2 => 'field_hp_hero_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Hero',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-hp-hero field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hp_how|config_pages|homepage|form';
  $field_group->group_name = 'group_hp_how';
  $field_group->entity_type = 'config_pages';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'How we work',
    'weight' => '7',
    'children' => array(
      0 => 'field_hp_how_title',
      1 => 'field_hp_how_need',
      2 => 'field_hp_how_have',
      3 => 'field_hp_how_text',
      4 => 'field_hp_how_need_slides',
      5 => 'field_hp_how_have_slides',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'How we work',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-hp-how field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hp_solutions|config_pages|homepage|form';
  $field_group->group_name = 'group_hp_solutions';
  $field_group->entity_type = 'config_pages';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Solutions',
    'weight' => '4',
    'children' => array(
      0 => 'field_hp_solutions_title',
      1 => 'field_hp_solutions_link',
      2 => 'field_hp_solutions_slides_blue',
      3 => 'field_hp_solutions_slides_orange',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Solutions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-hp-solutions field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hp_testimonies|config_pages|homepage|form';
  $field_group->group_name = 'group_hp_testimonies';
  $field_group->entity_type = 'config_pages';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Testimonies',
    'weight' => '5',
    'children' => array(
      0 => 'field_hp_testimonies',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Testimonies',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-hp-testimonies field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hp_why|config_pages|homepage|form';
  $field_group->group_name = 'group_hp_why';
  $field_group->entity_type = 'config_pages';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Why eMindHub',
    'weight' => '6',
    'children' => array(
      0 => 'field_hp_why_title',
      1 => 'field_hp_why_need',
      2 => 'field_hp_why_have',
      3 => 'field_hp_why_need_slides',
      4 => 'field_hp_why_have_slides',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Why eMindHub',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-hp-why field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Clients');
  t('Domains');
  t('Hero');
  t('How we work');
  t('Solutions');
  t('Testimonies');
  t('Why eMindHub');

  return $field_groups;
}
