<?php

/**
 * @file
 * Code of the eMindHub request submission form features.
 */

/**
 * Implements hook_form_alter().
 */
function emh_request_submission_form_alter(&$form, &$form_state, $form_id) {
  if (!isset($form['#node']) || $form['#node']->type !== 'request') {
    return;
  }

  if (isset($form['#node']->nid) && ($form_id == 'webform_client_form_' . $form['#node']->nid)) {
    // Changes the submit button label for "Publish".
    if (!empty($form['#is_draft']) || empty($form['#submission'])) {
      $form['actions']['submit']['#value'] = t('Publish');
    }

    // Disables the form components if the user is not allowed to answer.
    if (!emh_access_user_can_post_answer($form['#node']->nid) && !empty($form['submitted'])) {
      foreach ($form['submitted'] as $key => $element) {
        if (is_array($element) && !empty($element['#type']) && $element['#type'] == 'textarea') {
          $form['submitted'][$key]['#disabled'] = TRUE;
        }
      }
      $form['actions']['#access'] = FALSE;
    }

    // Hides the uniq field label in the request if not a questionnaire.
    if (!emh_request_has_option($form['#node'], 'questionnaire') && !empty($form['submitted'])) {
      foreach ($form['submitted'] as $key => $element) {
        if (is_array($element) && !empty($element['#type']) && $element['#type'] == 'textarea') {
          $form['submitted'][$key]['#title_display'] = 'invisible';
        }
      }
    }

    // Show specific message for Private option.
    if (emh_request_has_option($form['#node'], 'private') && !empty($form['submitted'])) {
      $form['actions']['#prefix'] = '<div class="user-submission-option-private-info">' . t("Your answer will only be visible by the request's author.") . '</div>';
    }

    // Draft to ...
    if (!empty($form['#is_draft']) || empty($form['#submission'])) {
      $form['#submit'][] = '_emh_request_submission_form_submit';
    }
    // Published again.
    if (empty($form['#is_draft']) || !empty($form['#submission'])) {
      $form['#submit'][] = '_emh_request_submission_form_submit_again';
    }

    // Add the Unpublish button.
    if (empty($form['#is_draft']) && !empty($form['#submission'])) {
      $node = node_load($form['#node']->nid);
      $submission = webform_get_submission($form['#submission']->nid, $form['#submission']->sid);
      if ($node->webform['allow_draft'] && emh_request_submission_unpublish_access_callback($node, $submission)) {
        $buttons_pre_render = array_merge(element_info_property('submit', '#pre_render', array()), array('webform_pre_render_remove_id'));

        $form['actions']['draft'] = array(
          '#type' => 'submit',
          '#value' => t('Unpublish'),
          '#weight' => -2,
          '#validate' => array('webform_client_form_prevalidate'),
          '#attributes' => array(
            'formnovalidate' => 'formnovalidate',
            'class' => array('webform-draft'),
          ),
          '#pre_render' => $buttons_pre_render,
        );
      }
    }
  }
}

/**
 * Submit handler: Status Draft to Published.
 */
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

/**
 * Submit handler: Published again.
 */
function _emh_request_submission_form_submit_again($form, &$form_state) {
  $node = $form['#node'];
  $form_state['redirect'] = 'node/' . $node->nid;
}
