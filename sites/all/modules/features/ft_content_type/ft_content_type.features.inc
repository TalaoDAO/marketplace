<?php
/**
 * @file
 * ft_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ft_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ft_content_type_node_info() {
  $items = array(
    'challenge' => array(
      'name' => t('Challenge'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'circle' => array(
      'name' => t('Circle'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'corporate' => array(
      'name' => t('Corporate'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Calls'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'working_group' => array(
      'name' => t('Working Group'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_profile2_type().
 */
function ft_content_type_default_profile2_type() {
  $items = array();
  $items['business'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "business",
    "label" : "Business",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 0 }
  }');
  $items['expert'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "expert",
    "label" : "Expert",
    "weight" : "10",
    "data" : { "registration" : 0, "use_page" : 0 }
  }');
  return $items;
}
