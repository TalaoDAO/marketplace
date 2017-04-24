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
  $events['_emh_circles_notification_membership_requested'] = array(
    'label' => t('Trigger the membership request email sending action.'),
    'module' => 'emh_circles_notification',
    'group' => t('Circle'),
    'variables' => array(
      'node' => array('type' => 'node', 'label' => t('The created content')),
      'account' => array('type' => 'user', 'label' => t('The user to notify')),
      'user' => array('type' => 'user', 'label' => t('The user requesting membership')),
    ),
  );
  return $events;
}
