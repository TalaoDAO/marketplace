<?php

/**
 * @file
 * EMH Request Views integration.
 */

/**
 * Implements hook_views_data().
 * @ingroup views
 */
function emh_request_views_data() {
  $data = array();

  // Pseudo-field on comment.
  $data['comment']['emh_answer'] = array(
    'group' => 'Comment',
    'real field' => 'cid',
    'help' => 'Answer',
    'title' => 'Answer',
    'field' => array(
      'handler' => 'views_handler_field_emh_comment_answer',
    ),
  );
  // Pseudo-field on webform submissions.
  $data['webform_submissions']['emh_answer'] = array(
    'group' => t('Webform submissions'),
    'real field' => 'sid',
    'help' => 'Answer',
    'title' => 'Answer',
    'field' => array(
      'handler' => 'views_handler_field_emh_webform_answer',
    ),
  );

  return $data;
}
