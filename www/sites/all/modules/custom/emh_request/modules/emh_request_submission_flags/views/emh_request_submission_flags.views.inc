<?php

/**
 * @file
 * Views hooks implemented for the EMH Request Submission Flags module.
 */

/**
 * Implements hook_views_data().
 * @ingroup views
 */
function emh_request_submission_flags_views_data() {
  $data = array();

  $data['webform_submissions']['emh_submission_flags'] = array(
    'group' => t('Webform submissions'),
    'real field' => 'sid',
    'help' => 'Submission flags',
    'title' => 'EMH Submission flags',
    'field' => array(
      'handler' => 'views_handler_field_emh_webform_submission_flags',
    ),
  );

  return $data;
}
