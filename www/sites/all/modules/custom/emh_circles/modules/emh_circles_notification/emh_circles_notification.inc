<?php

/**
 * @file
 * Code for eMindHub circle notification custom features.
 */

/**
 * When a membership is requested, send an email notification.
 *
 * @param object $group
 * @param object $user
 * @param object $node
 */
function _emh_circles_notification_membership_requested($group, $user, $node) {
  $accounts_uid = _emh_circles_get_group_admins($group);
  $accounts_uid[] = _emh_circles_get_group_manager($group);

  // Remove duplicate users.
  $accounts_uid = array_keys(array_flip($accounts_uid));
  $accounts = user_load_multiple($accounts_uid);

  foreach ($accounts as $account) {
    // Note: should use a queue if there are too many admins.
    rules_invoke_event('_emh_circles_notification_membership_requested', $node, $account, $user);
  }
}
