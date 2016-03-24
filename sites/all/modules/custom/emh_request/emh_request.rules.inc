<?php

/**
 * Implements hook_rules_event_info().
 * @ingroup rules
 */
function emh_request_rules_event_info() {
  $events = array();

  $events['emh_request_notify_new_request'] = array(
    'label' => t('A new request should be notified'),
    'module' => 'emh_request',
    'group' => t('EMH'),
    'variables' => _emh_request_event_variables(),
  );

  return $events;
}

/**
 * Helper function for event variables.
 *
 * @return
 *   All available variables for the rules events provided by emh_request.
 */
function _emh_request_event_variables() {
  return array(
    'user' => array(
      'type' => 'user',
      'label' => t('User'),
    ),
    'node' => array(
      'type' => 'node',
      'label' => t('Node'),
    ),
  );
}
