<?php

/**
 * @file
 * Views hooks implemented for the EMH Request module.
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

  // Is draft.
  $data['webform_submissions']['status'] = array(
    'title' => t('Submission - Status'),
    'help' => t('Whether or not the submission is a draft.'),
    'field' => array(
      'handler' => 'emh_request_webform_handler_field_is_draft',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'emh_request_webform_handler_filter_is_draft',
    ),
    'sort' => array(
       'handler' => 'views_handler_sort',
    ),
  );

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

  $data['node']['request_type'] = array(
    'group' => t('Node'),
    'title' => 'Request type',
    'field' => array(
      'handler' => 'views_handler_field_emh_request_type',
    ),
  );

  return $data;
}
