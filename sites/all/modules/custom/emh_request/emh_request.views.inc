<?php


/**
 * Implements hook_views_data().
 */
function emh_request_views_data() {
  $data = array();

//  $data['answer']['table']['group'] = t('Answer');
//  $data['answer']['table']['base'] = array(
//    'field' => 'answer_id',
//    'title' => t('Answer'),
//  );
//
//  $data['exposed']['id'] = array(
//    'title' => t('Count'),
//    'help' => t('Number of answers.'),
//    'field' => array(
//      'handler' => 'views_handler_field_numeric',
//    ),
//  );

  return $data;
}


/**
 * Implements hook_views_data_alter().
 */
function emh_request_views_data_alter(&$data) {
  // Answers from nodes
  $data['node']['emh_answer'] = array(
    'title' => t('Answers'),
    'help' => t('Answers of the given request node'),
    'relationship' => array(
      'base' => 'emh_answer',
      'base field' => 'request_id',
      'handler' => 'views_handler_relationship',
      'label' => t('Answers'),
    ),
  );

  $data['node']['table']['join']['emh_answer'] = array(
    'field' => 'nid',
    'left_field' => 'request_id',
    'left_table' => 'emh_answer',
  );

  // Answers count (node).
  $data['node']['emh_answer_count'] = array(
    'group' => t('Answer'),
    'field' => array(
      'title' => t('Answers count'),
      'help' => t('The number of answers for this request (node).'),
      'handler' => 'emh_request_handler_field_answers_count',
      //'count_type' => 'node',
    ),
  );

  // Last answer's user name.
  $data['node']['emh_answer_last_user'] = array(
    'group' => t('Answer'),
    'field' => array(
      'title' => t('Last answer\'s user'),
      'help' => t('Username of the last answer for this request (node).'),
      'handler' => 'emh_request_handler_field_last_answer_user',
    ),
  );
}