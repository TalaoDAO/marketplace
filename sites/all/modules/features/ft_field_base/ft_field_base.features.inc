<?php
/**
 * @file
 * ft_field_base.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function ft_field_base_flag_default_flags() {
  $flags = array();
  // Exported flag: "Winner calls3".
  $flags['winner_calls3'] = array(
    'entity_type' => 'webform_submission_entity',
    'title' => 'Winner calls3',
    'global' => 0,
    'types' => array(
      0 => 'webform',
    ),
    'flag_short' => 'Choose',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unchoose',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'ft_field_base',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Winner challenge".
  $flags['winner_challenge'] = array(
    'entity_type' => 'comment',
    'title' => 'Winner challenge',
    'global' => 0,
    'types' => array(
      0 => 'comment_node_challenge',
    ),
    'flag_short' => 'Choose',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unchoose',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'ft_field_base',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Winner question".
  $flags['winner_question'] = array(
    'entity_type' => 'node',
    'title' => 'Winner question',
    'global' => 0,
    'types' => array(
      0 => 'answer',
    ),
    'flag_short' => 'Choose',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unchoose',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'question' => 0,
      'token' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'ft_field_base',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
