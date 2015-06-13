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
  // Exported flag: "My selection".
  $flags['my_selection'] = array(
    'entity_type' => 'node',
    'title' => 'My selection',
    'global' => 0,
    'types' => array(
      0 => 'blog',
      1 => 'challenge',
      2 => 'forum',
      3 => 'question1',
      4 => 'webform',
    ),
    'flag_short' => 'Save in my selection',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove from my selection',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -10,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
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
    'weight' => -9,
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
    'weight' => -8,
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
    'weight' => -7,
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
    'status' => FALSE,
  );
  // Exported flag: "Winner question1".
  $flags['winner_question1'] = array(
    'entity_type' => 'comment',
    'title' => 'Winner question1',
    'global' => 0,
    'types' => array(
      0 => 'comment_node_question1',
    ),
    'flag_short' => 'Choose',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unchoose',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -6,
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
  return $flags;

}
