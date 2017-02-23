<?php
/**
 * @file
 * ft_flags.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function ft_flags_flag_default_flags() {
  $flags = array();
  // Exported flag: "Interesting answer".
  $flags['interesting_answer'] = array(
    'entity_type' => 'webform_submission',
    'title' => 'Interesting answer',
    'global' => 1,
    'types' => array(
      0 => 'webform_submission',
    ),
    'flag_short' => 'Was this answer helpful?',
    'flag_long' => 'Click to mark this answer as helpful.',
    'flag_message' => 'You marked this answer as interesting.',
    'unflag_short' => 'This answer was helpful <span class="glyphicon glyphicon-ok" aria-hidden="true"></span>',
    'unflag_long' => 'Click to unmark this answer as interesting.',
    'unflag_message' => 'You unmarked this answer as interesting.',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(),
    'show_as_field' => FALSE,
    'show_on_form' => FALSE,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'ft_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
