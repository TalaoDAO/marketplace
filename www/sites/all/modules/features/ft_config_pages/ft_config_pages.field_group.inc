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
    'weight' => '2',
    'children' => array(
      0 => 'field_hp_clients_client',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-hp-clients field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
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
    'weight' => '1',
    'children' => array(
      0 => 'field_hp_domains_title',
      1 => 'field_hp_domains',
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
  $field_group->identifier = 'group_hp_solutions|config_pages|homepage|form';
  $field_group->group_name = 'group_hp_solutions';
  $field_group->entity_type = 'config_pages';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Solutions',
    'weight' => '3',
    'children' => array(
      0 => 'field_hp_solutions_title',
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
    'weight' => '4',
    'children' => array(
      0 => 'field_hp_testimonies',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-hp-testimonies field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Clients');
  t('Domains');
  t('Solutions');
  t('Testimonies');

  return $field_groups;
}
