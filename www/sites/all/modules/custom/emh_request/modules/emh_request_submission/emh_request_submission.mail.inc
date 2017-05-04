<?php

/**
 * @file
 * Code of the eMindHub request submission email features.
 */

function emh_request_submission_send_mail($node) {
  $author = user_load($node->uid);
  $mail = $author->mail;
  $params = array(
    'nid' => $node->nid,
  );
  pet_send_mail('notify_request_author_new_answer', array(array('mail' => $mail, 'uid' => $node->uid)), $params, $node->language);
}

/**
 * Implements hook_token_info().
 */
function emh_request_submission_token_info() {
    $node_trim['tracking_url'] =  array(
      'name' => t("Node tracking URL"),
      'description' => t("Node URL with tracking info."),
    );
    return array(
      'tokens' => array(
        'node' => $node_trim,
      ),
    );
}

/**
 * Implements hook_tokens().
 */
function emh_request_submission_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if($type == 'node'){
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'tracking_url':
          $node = $data['node'];
          $key = 'notify_request_author_new_answer';
          $piwik_tracking = 'pk_campaign=' . $key . '_' . $node->nid;
          $ga_tracking = 'utm_medium=email&utm_source=' . $key . '&utm_campaign=' . $key . '_' . $node->nid;
          $tracking_url = url('node/' . $node->nid . '/webform-results?' . $piwik_tracking . '&' . $ga_tracking, array('absolute' => TRUE));
          $replacements[$original] = $tracking_url;
          break;
      }
    }
  }
  return $replacements;
}

