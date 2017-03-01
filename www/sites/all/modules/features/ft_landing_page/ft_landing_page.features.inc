<?php
/**
 * @file
 * ft_landing_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ft_landing_page_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ft_landing_page_node_info() {
  $items = array(
    'landing_page' => array(
      'name' => t('Landing page'),
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
