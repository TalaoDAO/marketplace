<?php

/**
 * @file
 * Code for eMindHub User custom features.
 */

/**
 * Helper function to get user realname instead of username.
 */
function emh_user_get_beautiful_realname($account) {
  global $user;
  $user1 = user_load($user->uid);
  $user2 = user_load($account->uid);

  $name = ''; $items = ''; $firstname = ''; $lastname = '';
  $items = field_get_items('user', $user2, 'field_first_name');
  $firstname = isset($items[0]['value']) ? check_plain(ucwords($items[0]['value'])) : '';

  if (module_exists('emh_access') && emh_access_user_can_see_full_user($user1->uid, $user2->uid)) {
    $items = field_get_items('user', $user2, 'field_last_name');
    $lastname = isset($items[0]['value']) ? check_plain(ucwords($items[0]['value'])) : '';
  }

  $name = !empty($firstname) ? $firstname : $account->name;
  $name .= !empty($lastname) ? ' ' . strtoupper($lastname) : '';

  return $name;
}

/**
 * Helper function to check if current user has access to other user's realname.
 *
 * @TODO: remove this useless function!
 */
function emh_user_get_beautiful_author($node) {
  if (empty($node)) {
    $node = node_load(arg(1));
  }

  return (emh_access_author_name($node)) ? emh_user_get_beautiful_realname($node->uid) : '<span class="author anonymous">' . t('Anonymous') . '</span>';
}

/**
 * Helper function to check access to user profile url.
 *
 * @TODO: remove this useless function!
 */
function emh_user_get_beautiful_profile_link($uid) {
  global $user;
  $name = emh_user_get_beautiful_realname($uid);

  return (emh_access_user_can_see_full_user($user->uid, $uid)) ? '<a href="' . url('user/' . $uid) . '">' . $name . '</a>' : $name;
}
