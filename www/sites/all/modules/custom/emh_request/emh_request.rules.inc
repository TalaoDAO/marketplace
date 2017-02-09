<?php

/**
 * Implements hook_rules_event_info().
 * @ingroup rules
 */
function emh_request_rules_event_info() {
  $events = array();
  $events['emh_request_notification_notify_trigger'] = array(
    'label' => t('Trigger the scheduling of the request notification.'),
    'module' => 'emh_request',
    'group' => t('Request'),
    'variables' => array(
      'node' => array('type' => 'node', 'label' => t('The created content')),
      'user' => array('type' => 'user', 'label' => t('The user to notify')),
    ),
  );
  $events['emh_request_notification_moderate_trigger'] = array(
    'label' => t('Trigger the moderation email sending action.'),
    'module' => 'emh_request',
    'group' => t('Request'),
    'variables' => array(
      'node' => array('type' => 'node', 'label' => t('The created content')),
      'user' => array('type' => 'user', 'label' => t('The user to notify')),
    ),
  );
  return $events;
}

/**
 * Implement hook_rules_action_info().
 */
function emh_request_rules_action_info() {
  return array(
    '_emh_request_notification_notify_build_queue' => array(
      'label' => t('Build the email queue for the content notification.'),
      'group' => t('Request'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('The content to notificate'),
        ),
      ),
    ),
  );
}
