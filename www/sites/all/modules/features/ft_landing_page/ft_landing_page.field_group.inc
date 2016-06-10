<?php
/**
 * @file
 * ft_landing_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ft_landing_page_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_landingpage_how|node|landing_page|form';
  $field_group->group_name = 'group_landingpage_how';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Zone 2',
    'weight' => '1',
    'children' => array(
      0 => 'field_landingpage_how_title',
      1 => 'field_landingpage_how_text',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Zone 2',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-landingpage-how field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_landingpage_how|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_landingpage_intro|node|landing_page|form';
  $field_group->group_name = 'group_landingpage_intro';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Zone 1',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_landingpage_image',
      2 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Zone 1',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-landingpage-intro field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_landingpage_intro|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_landingpage_media|node|landing_page|form';
  $field_group->group_name = 'group_landingpage_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Zone 3',
    'weight' => '2',
    'children' => array(
      0 => 'field_landingpage_media_title',
      1 => 'field_landingpage_media_text',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Zone 3',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-landingpage-media field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_landingpage_media|node|landing_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Zone 1');
  t('Zone 2');
  t('Zone 3');

  return $field_groups;
}
