<?php

/**
 * @file
 * Includes any rules integration provided by the module.
 */

/**
 * Implements hook_rules_event_info().
 *
 * @ingroup rules
 */
function emh_circles_notification_rules_event_info() {
  $events = array();
  $events['_emh_circles_notification_notify'] = array(
    'label' => t('Trigger the circle administrators notification.'),
    'module' => 'emh_circles',
    'group' => t('Circle'),
    'variables' => array(
      'node' => array('type' => 'node', 'label' => t('The group')),
      'user' => array('type' => 'user', 'label' => t('The user to notify')),
    ),
  );
  return $events;
}
