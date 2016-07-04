<?php
/**
 * @file
 * ft_request.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ft_request_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function ft_request_flag_default_flags() {
  $flags = array();
  // Exported flag: "Save request".
  $flags['my_selection'] = array(
    'entity_type' => 'node',
    'title' => 'Save request',
    'global' => 0,
    'types' => array(
      0 => 'challenge',
      1 => 'webform',
      2 => 'question1',
      3 => 'request',
    ),
    'flag_short' => 'Save',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unsave',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -10,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => 'others',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'ft_request',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function ft_request_node_info() {
  $items = array(
    'request' => array(
      'name' => t('Request'),
      'base' => 'node_content',
      'description' => t('Content type to address question(s) to the experts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
