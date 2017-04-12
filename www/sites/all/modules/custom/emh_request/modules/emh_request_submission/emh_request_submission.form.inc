<?php

/**
 * @file
 * Code of the eMindHub request submission form features.
 */

/**
 * Implements hook_form_alter().
 */
function emh_request_submission_form_alter(&$form, &$form_state, $form_id) {
  if (isset($form['#node']->nid)) {
    $request_ID = $form['#node']->nid;
    switch ($form_id) {
      case "webform_client_form_$request_ID":
        // Draft to ...
        if (!empty($form['#is_draft']) || empty($form['#submission'])) {
          $form['#submit'][] = '_emh_request_submission_form_submit';
        }
        // Published again.
        if (empty($form['#is_draft']) || !empty($form['#submission'])) {
          $form['#submit'][] = '_emh_request_submission_form_submit_again';
        }
        break;

      default:
        break;
    }
  }
}

function _emh_request_submission_form_submit($form, &$form_state) {
  $node = $form['#node'];

  // Check if this form is sending an email.
  $is_draft = (int) !empty($form_state['save_draft']);
  if (!$is_draft) {
    emh_request_submission_send_mail($node);
    drupal_set_message(t('Your answer has been published.'));
  }

  $form_state['redirect'] = 'node/' . $node->nid;
}

function _emh_request_submission_form_submit_again($form, &$form_state) {
  $node = $form['#node'];
  $form_state['redirect'] = 'node/' . $node->nid;
}
