<?php

/**
 * Get group managers from a group.
 */
function _emh_circles_get_managers_from_group($group) {
  $group = entity_metadata_wrapper($group['group_type'], $group['gid']);

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

  $admins = array();

  // Get the group admins for the group.
  $members = db_select('og_users_roles', 'our')
    ->fields('our', array('uid'))
    ->condition('our.gid', $entity_id)
    ->condition('our.group_type', $entity_type)
    ->condition('our.rid', $admin_rid)
    ->execute()
    ->fetchCol();

  $admins = array_merge($admins, $members);

  // Remove duplicate items.
  $admins = array_keys(array_flip($admins));

  return array('group_managers' => $admins);
}

function _emh_circles_check_user_is_referentmember_of_groups($uid, $gids) {
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

function _emh_circles_check_user_is_adminmember_of_groups($uid, $gids) {
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

function _emh_circles_check_user_is_admin_of_groups($uid, $gids) {
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
