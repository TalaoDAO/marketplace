<?php
/**
 * @file
 * answers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function answers_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function answers_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function answers_node_info() {
  $items = array(
    'answer' => array(
      'name' => t('Answer'),
      'base' => 'node_content',
      'description' => t('An answer provided to question asked by a member of the community'),
      'has_title' => '1',
      'title_label' => t('Answer'),
      'help' => '',
    ),
    'question' => array(
      'name' => t('Question'),
      'base' => 'node_content',
      'description' => t('A question which can be answered by other users'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
  );
  return $items;
}
