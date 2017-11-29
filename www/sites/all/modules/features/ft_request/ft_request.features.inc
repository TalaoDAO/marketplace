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
 * Implements hook_views_api().
 */
function ft_request_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function ft_request_flag_default_flags() {
  $flags = array();
  // Exported flag: "Feedback answer".
  $flags['comment_answer'] = array(
    'entity_type' => 'webform_submission',
    'title' => 'Feedback answer',
    'global' => 1,
    'types' => array(
      0 => 'webform_submission',
    ),
    'flag_short' => '<span class="glyphicon glyphicon-comment" aria-hidden="true"></span>',
    'flag_long' => 'Leave a feedback for the expert',
    'flag_message' => 'Thank you for leaving a feedback to the expert!',
    'unflag_short' => 'Yes, delete',
    'unflag_long' => 'Delete your feedback',
    'unflag_message' => 'Feedback deleted.',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(),
    'show_as_field' => FALSE,
    'show_on_form' => FALSE,
    'access_author' => '',
    'show_contextual_link' => 0,
    'flag_confirmation' => 'Please write down your feedback on the expert answer',
    'unflag_confirmation' => 'Do you want to delete your feedback?',
    'module' => 'ft_request',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Answer selected".
  $flags['interesting_answer'] = array(
    'entity_type' => 'webform_submission',
    'title' => 'Answer selected',
    'global' => 1,
    'types' => array(
      0 => 'webform_submission',
    ),
    'flag_short' => '<span class="glyphicon glyphicon-thumbs-up" aria-hidden="true"></span>',
    'flag_long' => 'Select the answer',
    'flag_message' => 'Answer selected',
    'unflag_short' => '<span class="glyphicon glyphicon-thumbs-up" aria-hidden="true"></span>',
    'unflag_long' => 'Unselect the answer',
    'unflag_message' => 'You unselected this answer.',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(),
    'show_as_field' => FALSE,
    'show_on_form' => FALSE,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'ft_request',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
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
      'summary' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'ft_request',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_default_log_type().
 */
function ft_request_default_log_type() {
  $items = array();
  $items['log_opencalais'] = entity_import('log_type', '{
    "type" : "log_opencalais",
    "label" : "LogOpenCalais",
    "weight" : 0,
    "name_pattern" : "Log [log:id]",
    "name_edit" : "0",
    "done" : "0",
    "emh_earnings" : 0
  }');
  return $items;
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
