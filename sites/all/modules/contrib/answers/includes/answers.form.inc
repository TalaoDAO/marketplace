<?php

/**
 * @file
 * Form utility functions for the 'Answers' module.
 */

/**
 * Add settings related to question/answer form.
 */
function _answers_form_settings() {
  $form = array();

  $form['answers_form'] = array(
    '#type' => 'fieldset',
    '#title' => t('Form Settings'),
  );

  $form['answers_form']['answers_question_create_button_text'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Submit button text while creating new question'),
    '#default_value' => variable_get('answers_question_create_button_text', t('Ask Your Question')),
  );

  $form['answers_form']['answers_question_edit_button_text'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Submit button text while editing question'),
    '#default_value' => variable_get('answers_question_edit_button_text', t('Update Your Question')),
  );

  $form['answers_form']['answers_answer_create_button_text'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Submit button text while creating new answer'),
    '#default_value' => variable_get('answers_answer_create_button_text', t('Post Your Answer')),
  );

  $form['answers_form']['answers_answer_edit_button_text'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Submit button text while editing answer'),
    '#default_value' => variable_get('answers_answer_edit_button_text', t('Update Your Answer')),
  );

  return $form;
}
