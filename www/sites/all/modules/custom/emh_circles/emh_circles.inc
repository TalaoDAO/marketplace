<?php

/**
 * @file
 * EMH Circles module custom functions.
 */

function emh_circles_enable_strings() {
  global $language;

  $lang = $language->language;
  $strings = variable_get("locale_custom_strings_$lang", array());
  foreach (_emh_circles_string_overrides() as $string => $override) {
    $strings[''][$string] = $override;
  }
  variable_set("locale_custom_strings_$lang", $strings);
}

function emh_circles_disable_strings() {
  global $language;

  $lang = $language->language;
  $strings = variable_get("locale_custom_strings_$lang", array());
  foreach (_emh_circles_string_overrides() as $string => $override) {
    unset($strings[''][$string]);
  }
  variable_set("locale_custom_strings_$lang", $strings);
}

/**
 * Provides string overrides.
 */
function _emh_circles_string_overrides() {
  return array(
    "%1's groups" => "My circles",
    "Member's groups" => "Member's circles",
    "Subscribe to group" => "Join",
    "Unsubscribe from group" => "Leave circle",
    "Request group membership" => "Join circle",
    "Are you sure you want to join the group %title?" => "Join %title circle",
    "Are you sure you want to unsubscribe from the group %title?" => "Leave %title circle",
    "Group" => "Circle",
    "Active" => "Member",
    "Manage the group members." => "Manage the circle members.",
    "Group overview" => "Circle overview",
    "People in group @group" => "People in circle @group",
    "Group manager" => "Circle manager",
    "Edit membership in group @group" => "Edit membership in circle @group",
    "Edit a group membership in %group" => "Edit a circle membership in %group",
    "This is the text a user may send to the group administrators." => "This is the text a user may send to the circle administrators.",
    "You already have a pending membership for the group @group." => "You already have a pending membership for the circle @group.",
    "@user already has a pending membership for the  the group @group." => "@user already has a pending membership for the  the circle @group.",
  );
}

/**
 * Get circle manager.
 */
function _emh_circles_get_group_manager($group = NULL) {
  if (empty($group)) {
    $group = og_context();
    $group = entity_metadata_wrapper($group['group_type'], $group['gid']);
  }

  $entity_type = $group->type();
  $entity_id = $group->getIdentifier();

  // Not a group.
  if (!og_is_group($entity_type, $group)) {
    return;
  }

  $node = node_load($entity_id);
  $manager_uid = $node->uid;

  return $manager_uid;
}

/**
 * Get circle admins.
 */
function _emh_circles_get_group_admins($group = NULL) {
  if (empty($group)) {
    $group = og_context();
    $group = entity_metadata_wrapper($group['group_type'], $group['gid']);
  }

  $entity_type = $group->type();
  $entity_id = $group->getIdentifier();

  // Not a group.
  if (!og_is_group($entity_type, $group)) {
    return;
  }

  // Get the group roles.
  $roles = og_roles($entity_type, $group->getBundle(), $entity_id);
  $admin_rid = array_search(OG_ADMINISTRATOR_ROLE, $roles);

  // Bail out if we can't figure out the admin role id.
  if (!$admin_rid) {
    return;
  }

  $admins_uid = array();

  // Get the group admins for the group.
  $members_uid = db_select('og_users_roles', 'our')
    ->fields('our', array('uid'))
    ->condition('our.gid', $entity_id)
    ->condition('our.group_type', $entity_type)
    ->condition('our.rid', $admin_rid)
    ->execute()
    ->fetchCol();

  $admins_uid = array_merge($admins_uid, $members_uid);

  // Remove duplicate items.
  $admins_uid = array_keys(array_flip($admins_uid));

  return $admins_uid;
}

function _emh_circles_user_is_groups_referent($uid, $gids) {
  $roleID = db_select('og_role', 'og')
    ->condition('name', 'Referent member', '=')
    ->distinct()
    ->fields('og', array('rid'))
    ->execute();
  $roleID = $roleID->fetchAssoc();

  if (!empty($roleID)) {
    foreach ($gids as $gid) {
      $isReferentMember = db_select('og_users_roles', 'og')
        ->condition('gid', $gid, '=')
        ->condition('uid', $uid, '=')
        ->condition('rid', $roleID['rid'], '=')
        ->distinct()
        ->fields('og', array('rid'))
        ->execute();
      $isReferentMember = $isReferentMember->fetchAssoc();
      if (!empty($isReferentMember)) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

function _emh_circles_user_is_groups_admin($uid, $gids) {
  $roleID = db_select('og_role', 'og')
    ->condition('name', 'administrator member', '=')
    ->condition('group_bundle', 'circle', '=')
    ->distinct()
    ->fields('og', array('rid'))
    ->execute();
  $roleID = $roleID->fetchAssoc();

  if (!empty($roleID)) {
    foreach ($gids as $gid) {
      $isAdminMember = db_select('og_users_roles', 'og')
        ->condition('gid', $gid, '=')
        ->condition('uid', $uid, '=')
        ->condition('rid', $roleID['rid'], '=')
        ->distinct()
        ->fields('og', array('rid'))
        ->execute();
      $isAdminMember = $isAdminMember->fetchAssoc();
      if (!empty($isAdminMember)) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

function _emh_circles_user_is_groups_manager($uid, $gids) {
  foreach ($gids as $gid) {
    $result = db_select('node', 'n')
      ->condition('nid', $gid, '=')
      ->distinct()
      ->fields('n', array('uid'))
      ->execute();
    $node_uid = $result->fetchAssoc();
    if ($node_uid['uid'] == $uid) {
      return TRUE;
    }
  }
  return FALSE;
}
