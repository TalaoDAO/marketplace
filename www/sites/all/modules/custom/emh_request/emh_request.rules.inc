<?php

/**
 * Implements hook_rules_event_info().
 * @ingroup rules
 */
function emh_request_rules_event_info() {
  $events = array();
  $events['emh_request_notify_new_request'] = array(
    'label' => t('A new content should be notified'),
    'module' => 'emh_request',
    'group' => t('EMH'),
    'variables' => array(
      'node' => array('type' => 'node', 'label' => t('The created content')),
      'user' => array('type' => 'user', 'label' => t('The user to notify')),
    ),
  );
  return $events;
}
