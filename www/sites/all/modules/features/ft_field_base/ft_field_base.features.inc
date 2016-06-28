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
  // Exported flag: "My contacts".
  $flags['my_contacts'] = array(
    'entity_type' => 'user',
    'title' => 'My contacts',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Add to my contacts',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unflag this item',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Your cannot undo this action',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 0,
    'access_uid' => 'others',
    'module' => 'ft_field_base',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "My selection".
  $flags['my_selection'] = array(
    'entity_type' => 'node',
    'title' => 'My selection',
    'global' => 0,
    'types' => array(
      0 => 'challenge',
      1 => 'webform',
      2 => 'question1',
    ),
    'flag_short' => 'Add to my selection',
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
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
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
