<?php

/**
 * @file
 * Notification functionality for 'Answers' to inform users of answers.
 *
 * @author Chip Cleary
 *
 */
module_load_include('inc', 'answers', 'includes/answers.field_utils');

/**
 * Add settings to the notification form
 */
function _answers_notify_settings() {
  $form = array();

  $form['answers_notification'] = array(
    '#type' => 'fieldset',
    '#title' => t('"New Answer" Notification Email'),
    '#description' => t('Users can ask to be notified by email when a new answer is posted to their question. Settings for the email.'),
  );

  $form['answers_notification']['answers_new_answer_notice_allow_p'] = array(
    '#type' => 'checkbox',
    '#title' => t('Give users the option to be notified'),
    '#default_value' => variable_get('answers_new_answer_notice_allow_p', TRUE),
    '#description' => t('If disabled, users will not be offered the option to receive notifications. Also, any new answers to questions will not trigger notifications, even if their authors had previously requested notification. '),
  );

  $form['answers_notification']['answers_new_answer_notice_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject line'),
    '#default_value' => variable_get('answers_new_answer_notice_subject', ANSWERS_DEFAULT_NEW_ANSWER_NOTICE_SUBJECT),
    '#description' => t('Dynamic variables available: !question_user_name, !answer_user_name, !question_title, !question_url, !site and !site_url'),
    '#required' => TRUE
  );


  $form['answers_notification']['answers_new_answer_notice_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => variable_get('answers_new_answer_notice_body', ANSWERS_DEFAULT_NEW_ANSWER_NOTICE_BODY),
    '#description' => t('Dynamic variables available: !question_user_name, !answer_user_name, !question_title, !question_url, !site and !site_url'),
    '#required' => TRUE
  );

  return $form;
}

/**
 * Pseudo implementation of hook_node_insert
 *
 * @see answers_node_insert()
 */
function _answers_notify_node_insert($node) {
  if ($node->type=='answer' && variable_get('answers_new_answer_notice_allow_p', TRUE)) {
    $question = answers_field_get_node_reference($node, 'field_answer_question'); // extract the nid of the question
    if ($question->nid) {
      answers_notify_new_answer($question->nid);
    }
  }
}

/**
 * If configured to, notify question author of an answer.
 *
 * @param $nid
 *   Numeric node NID of question.
 */
function answers_notify_new_answer($nid) {
  global $user;
  global $base_url;

  $question = node_load($nid);
  $notify_p = answers_field_get_value($question, 'field_notify_p'); // extract the nid of the question

  if ($notify_p) {

    $question_user = user_load($question->uid);

    $params = array(
      '!question_user_name'  => $question_user->name,
      '!answer_user_name'    => $user->uid == 0 ? 'anonymous' : $user->name,
      '!question_title'      => $question->title,
      '!question_url'        => url('node/' . $nid, array('absolute' => TRUE, 'target' => '_blank')),
      '!site'                => variable_get('site_name', 'drupal'),
      '!site_url'            => $base_url,
      );

    drupal_mail('answers', 'new_answer', $question_user->mail, user_preferred_language($question_user), $params);

  };
}

/**
 * Implements hook_mail().
 */
function answers_mail($key, &$message, $params) {
  $langcode = $message['language']->language;
  $message['headers']['Content-Type'] = 'text/html; charset=UTF-8; format=flowed';
  if (!module_exists('mimemail')){
    $message['headers']['Mime-Version'] = '1.0';
  }

  switch ($key) {
    case 'new_answer':
      $subject_template = variable_get('answers_new_answer_notice_subject', ANSWERS_DEFAULT_NEW_ANSWER_NOTICE_SUBJECT);
      $message['subject'] = t(check_plain($subject_template), $params, array('langcode' => $langcode));
      $body_template = variable_get('answers_new_answer_notice_body', ANSWERS_DEFAULT_NEW_ANSWER_NOTICE_BODY);
      $message['body'][] = t(filter_xss($body_template), $params, array('langcode' => $langcode));
      break;
  }
}
