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
  pet_send_mail('notify_request_author_new_answer', array(array('mail' => $mail, 'uid' => $node->uid)), $params);
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

/**
 * Implements hook_mail().
 */
function emh_request_submission_mail($key, &$message, $params) {
  switch ($key) {
    case 'notify_request_author_new_answer':
      $message['subject'] = t('New answer to the request @title', $params);
      $message['body'] = array();
      $message['body'][] = t('Dear @author,', $params);
      $message['body'][] = t('You received a new answer to the request') . ' <strong><a href="' . t('@url', $params) . '&amp;pk_kwd=link&amp;utm_content=link" title="' .  t('@title', $params) . '" target="_blank" style="font-weight:bold!important;">' . t('@title', $params) . '</a></strong>.';
      $message['body'][] = t('Just log into the platform to see this answer.');
      $message['body'][] = '<table style="min-width:100%;" width="100%" border="0" cellpadding="0" cellspacing="0" class="emailButton">
        <tbody>
          <tr>
            <td style="padding-top:0;padding-right:18px;padding-bottom:18px;padding-left:18px;" valign="top" align="center">
              <table style="border-collapse:separate!important;border-radius:0px;background-color:rgb(0,159,227);" border="0" cellpadding="0" cellspacing="0">
                <tbody>
                  <tr>
                    <td style="font-family:Arial;font-size:16px;padding:15px;color:rgb(255, 255, 255);" valign="middle" align="center">
                      <a href="' . t('@url', $params) . '&amp;pk_kwd=calltoaction&amp;utm_content=cta" title="' . t('Log in to eMindHub') . '" target="_blank" style="font-weight:bold!important;letter-spacing:normal;line-height:100%;text-align:center;text-decoration:none;color:#FFFFFF!important;">' . t('Log in to eMindHub') . ' </a>
                    </td>
                  </tr>
                </tbody>
              </table>
            </td>
          </tr>
        </tbody>
      </table>';
      break;

    default:
      break;
  }
}
