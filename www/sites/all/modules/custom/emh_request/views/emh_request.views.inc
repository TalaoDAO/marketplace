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
    'title' => 'EMH Answer',
    'field' => array(
      'handler' => 'views_handler_field_emh_comment_answer',
    ),
  );

  // Pseudo-field on webform submissions.
  $data['webform_submissions']['emh_answer'] = array(
    'group' => t('Webform submissions'),
    'real field' => 'sid',
    'help' => 'Answer',
    'title' => 'EMH Answer',
    'field' => array(
      'handler' => 'views_handler_field_emh_webform_answer',
    ),
  );

  // Pseudo-field on request submissions answers count.
  $data['node']['total_answers'] = array(
    'group' => t('Node'),
    'title' => 'EMH Total Answers',
    'field' => array(
      'handler' => 'views_handler_field_emh_request_answer_count',
    ),
  );

  $data['node']['request_type'] = array(
    'group' => t('Node'),
    'title' => 'EMH Request type',
    'field' => array(
      'handler' => 'views_handler_field_emh_request_type',
    ),
  );

  $data['node']['request_language'] = array(
    'group' => t('Node'),
    'title' => 'EMH Request language',
    'field' => array(
      'handler' => 'views_handler_field_emh_request_language',
    ),
  );

  $data['node']['request_nothidden_entreprise'] = array(
    'group' => t('Node'),
    'title' => 'EMH Request organisation name - if not hidden by user',
    'field' => array(
      'handler' => 'views_handler_field_emh_request_nothidden_entreprise',
    ),
  );

  return $data;
}

function emh_request_views_data_alter(&$data) {
  $data['webform_submissions']['is_draft']['field']['handler'] = 'emh_request_webform_handler_field_is_draft';
  $data['webform_submissions']['is_draft']['filter']['handler'] = 'emh_request_webform_handler_filter_is_draft';
}
