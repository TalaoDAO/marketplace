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

  // $data['webform_submissions']['emh_answer'] = array(
  //   'group' => t('Webform submissions'),
  //   'real field' => 'sid',
  //   'help' => 'Answer',
  //   'title' => 'Answer',
  //   'field' => array(
  //     'handler' => 'views_handler_field_emh_webform_answer',
  //   ),
  // );

  // Pseudo-field on request submissions answers count.
  $data['node']['total_answers'] = array(
    'group' => t('Node'),
    'title' => 'Total Answers',
    'field' => array(
      'handler' => 'views_handler_field_emh_request_answer_count',
    ),
  );

  $data['node']['request_status'] = array(
    'group' => t('Node'),
    'title' => 'Request status',
    'field' => array(
      'handler' => 'views_handler_field_emh_request_status',
    ),
  );

  return $data;
}
