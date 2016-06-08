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
