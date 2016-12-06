<?php

/**
 * Implements hook_form_alter().
 * node/add/request
 * node/%/edit
 */
function emindhub_form_request_node_form_alter(&$form, &$form_state, $form_id) {
  global $user;

  if ($form['field_request_type']) {
    $form['field_request_type']['#prefix'] .= '<div class="section step1"><h2>' . t('What do you want to do?') . '</h2>';
    $form['field_request_type']['#suffix'] .= '</div>';
  }

  if ($form['title_field'] && $form['body']) {
    $form['title_field']['#prefix'] .= '<div class="section step2"><h2>' . t('What is your request about?') . '</h2>';
    $form['body']['#suffix'] .= '</div>';
  }

  if ($form['field_domaine'] && $form['language']) {
    $form['field_domaine']['#prefix'] .= '<div class="section step3"><h2>' . t('Tell us more about your request:') . '</h2>';
    $form['language']['#suffix'] .= '</div>';
  }
  $form['field_domaine'][LANGUAGE_NONE]['#title'] = t('Fields of expertise');

  $form['og_group_ref']['#prefix'] .= '<div class="section step4"><h2>' . t('Select circle(s) of experts you want to address your request') . '</h2>';
  $form['og_group_ref']['#suffix'] .= '</div>';

  $form['field_options']['#prefix'] .= '<div class="section step5"><h2>' . t('Add options and get the most from your request!') . '</h2>';
  $form['field_options']['#prefix'] .= '<p class="emh-credits-buy">' . t('Do you need more credits? Please contact us at <a href="mailto:credits@emindhub.com?Subject=Credits%20needed%20by%20!current_user&Body=Your%20company%3A%0AYour%20position%3A%0APhone%20number%3A%0AAmount%20of%20credits%20needed%3A">credits@emindhub.com</a>', array(
        '!current_user' => format_username($user),
  )) . '</p>';
  $form['field_options'][LANGUAGE_NONE]['#type'] = 'div';
  $form['field_options']['#suffix'] .= '</div>';

  $form['field_options'][LANGUAGE_NONE]['questionnaire']['enabled']['#suffix'] .= '<div class="form-item-description">' . $form['field_options'][LANGUAGE_NONE]['questionnaire']['enabled']['#description'] . '</div>';
  $form['field_options'][LANGUAGE_NONE]['questionnaire']['enabled']['#description'] = '';
  $form['field_request_questions'][LANGUAGE_NONE]['add_more']['#value'] = t('Add another question');

  $form['field_options'][LANGUAGE_NONE]['private']['enabled']['#suffix'] .= '<div class="form-item-description">' . $form['field_options'][LANGUAGE_NONE]['private']['enabled']['#description'] . '</div>';
  $form['field_options'][LANGUAGE_NONE]['private']['enabled']['#description'] = '';

  $form['field_options'][LANGUAGE_NONE]['files']['enabled']['#suffix'] .= '<div class="form-item-description">' . $form['field_options'][LANGUAGE_NONE]['files']['enabled']['#description'] . '</div>';
  $form['field_options'][LANGUAGE_NONE]['files']['enabled']['#description'] = '';

  $form['field_options'][LANGUAGE_NONE]['duration']['enabled']['#suffix'] .= '<div class="form-item-description">' . $form['field_options'][LANGUAGE_NONE]['duration']['enabled']['#description'] . '</div>';
  $form['field_options'][LANGUAGE_NONE]['duration']['enabled']['#description'] = '';

  $form['field_options'][LANGUAGE_NONE]['anonymous']['enabled']['#suffix'] .= '<div class="form-item-description">' . $form['field_options'][LANGUAGE_NONE]['anonymous']['enabled']['#description'] . '</div>';
  $form['field_options'][LANGUAGE_NONE]['anonymous']['enabled']['#description'] = '';

  if ($form['field_hide_name'] && $form['field_hide_organisation']) {
    $form['field_hide_name']['#prefix'] .= '<div class="request-option-anonymous">';
    $form['field_hide_organisation']['#suffix'] .= '</div>';
  }
}
