<?php

/**
 * Implements hook_rules_action_info()
 */
function og_role_field_rules_action_info() {
  $actions = array();
/** BROKEN **
  // Loads a role reference and returns a "role" object
  $actions['og_role_field_rules_load_role_reference'] = array(
    'label' => t('Load a group role reference from a field'),
    'group' => t('Organic groups'),
    'parameter' => array(
      'rid' => array(
        'type' => 'number',
        'label' => t('The field to search'),
      ),
    ),
    'provides' => array(
      'og_role' => array(
        'type' => 'og_role',
        'label' => t('Group Role'),
        'wrapped' => TRUE,
      ),
    ),
  );
  // Grants a group role to a user.
  $actions['og_role_field_rules_grant_role'] = array(
    'label' => t('Grant a group role to a user'),
    'group' => t('Organic groups'),
    'parameter' => array(
      'account' => array(
        'type' => 'user',
        'label' => t('The user which will be a granted a role.'),
      ),
      'og_role' => array(
        'type' => 'og_role',
        'label' => t('The role to be granted'),
      ),
    ),
  );
  // Revokes a group role from a user.
  $actions['og_role_field_rules_revoke_user_role'] = array(
    'label' => t('Revoke a group role from a user'),
    'group' => t('Organic groups'),
    'parameter' => array(
      'account' => array(
        'type' => 'user',
        'label' => t('The user which will lose a role.'),
      ),
      'og_role' => array(
        'type' => 'og_role',
        'label' => t('The role to be revoked from the user.'),
      ),
    ),
  );
/**/
  return $actions;
}

/**
 * Implements hook_rules_condition_info()
 */
function og_role_field_rules_condition_info() {
  $conditions = array();
/** BROKEN **
  // Checks if a group role is actually a global role.
  $conditions['og_role_field_rules_group_role_is_global'] = array(
    'label' => t('Is a group role a global role?'),
    'group' => t('Organic groups'),
    'parameter' => array(
      'og_role' => array(
        'type' => 'og_role',
        'label' => t('The role anticipated within the group.'),
      ),
    ),
  );
  // Checks if a role exists within a group.
  $conditions['og_role_field_rules_group_contains_role'] = array(
    'label' => t('A group contains a role'),
    'group' => t('Organic groups'),
    'parameter' => array(
      'group' => array(
        'type' => 'group',
        'label' => t('The group which roles belong to.'),
      ),
      'og_role' => array(
        'type' => 'og_role',
        'label' => t('The role anticipated within the group.'),
      ),
    ),
  );
  // Checks if a user has a role within a group.
  $conditions['og_role_field_rules_user_has_group_role'] = array(
    'label' => t('A user has a group role'),
    'group' => t('Organic groups'),
    'parameter' => array(
      'account' => array(
        'type' => 'user',
        'label' => t('The user in question.'),
      ),
      'og_role' => array(
        'type' => 'og_role',
        'label' => t('The role anticipated within the group.'),
      ),
    ),
  );
/**/
  return $conditions;
}

/**
 * Implements hook_rules_event_info()
 */
function og_role_field_rules_event_info() {
  // Allows the system to react on a newly granted group role.
  $events['og_role_field_rules_role_granted_to_user'] = array(
    'label' => t('A group role has been granted to a user'),
    'group' => t('Organic groups'),
    'variables' => array(
      'account' => array(
        'type' => 'user',
        'label' => t('The user which was granted a group role.'),
      ),
      'group' => array(
        'type' => 'integer',
        'label' => t('The group GID whose role(s) were granted to the user.'),
      ),
      'role' => array(
        'type' => 'integer',
        'label' => t('The role RID granted to the user.'),
      ),
    ),
  );
  // Allows the system to react on a revoked group role.
  $events['og_role_field_rules_role_revoked_from_user'] = array(
    'label' => t('A group role has been revoked from a user'),
    'group' => t('Organic groups'),
    'variables' => array(
      'account' => array(
        'type' => 'user',
        'label' => t('The user which lost access to a group role.'),
      ),
      'group' => array(
        'type' => 'integer',
        'label' => t('The group GID whose role(s) were revoked from the user.'),
      ),
      'role' => array(
        'type' => 'integer',
        'label' => t('The role RID revoked from the user.'),
      ),
    ),
  );
}

/**
 * Implements hook_rules_data_info() on behalf of the system module.
 * @see rules_core_modules()
 */
function og_role_field_rules_data_info() {
  return array(
    'og_role' => array(
      'label' => t('Group Role'),
      'group' => t('Organic groups'),
      'wrapped' => TRUE,
      'property info' => _og_role_field_rules_entry_info(),
    ),
  );
}

/**
 * Defines property info for watchdog log entries, used by the log entry data
 * type to provide an useful metadata wrapper.
 */
function _og_role_field_rules_entry_info() {
  return array(
    'rid' => array(
      'type' => 'integer',
      'label' => t('The role RID of the role.'),
    ),
    'gid' => array(
      'type' => 'integer',
      'label' => ('The group GID the role belongs to.'),
    ),
    'name' => array(
      'type' => 'text',
      'label' => t('The name of the role'),
      'sanitized' => true,
    ),
  );
}

/**
 * Processes 'og_role_rules_grant_role' action.
 * Generates 'warnings' to the user if the role cannot be granted,
 * the group cannot be found,
 * or the role cannot be loaded.
 *
 * @param $account_uid
 *  The user ID to lose a role.
 * @param $rid
 *  The group role to be granted.
 */
function og_role_field_rules_grant_role($account, $rid) {
  $group = $role = NULL;
  // Try to find the role provided.
  if (FALSE == ($role = og_role_load($rid))) {
    throw new RulesEvaluationException('Unable to load group role with rid "@rid"', array('@rid' => $rid));
  }
  // Try to find the group provided.
  if (FALSE == ($group = og_load($role->gid))) {
    throw new RulesEvaluationException('Unable to load group with gid "@gid"', array('@gid' => $role->gid));
  }
  // Make it so.
  og_role_grant($group->gid, $account->uid, $role->rid);
  // Tell the user about their new permissions!
  if (count(drupal_get_messages()) < 1) {
    drupal_set_message(t('You may now access the group "@group" as "@role".', array('@role' => $role->name, '@group' => $group->label)));
  }
  return;
}

/**
 * Processes 'og_role_rules_revoke_user_role' action.
 * Generates 'warnings' to the user if
 * the group cannot be found,
 * or the role cannot be loaded.
 *
 * @param $account
 *  The user to be granted new roles.
 * @param $rid
 *  The role to revoke.
 */
function og_role_field_rules_revoke_user_role($account, $rid) {
  $group = $role = NULL;
  // Try to find the role provided.
  if (FALSE == ($role = og_role_load($rid))) {
    throw new RulesEvaluationException('Unable to load group role with rid "@rid"', array('@rid' => $rid));
    // Stop processing the rule here
    return;
  }
  // Try to find the group provided.
  if (FALSE == ($group = og_load($role->gid))) {
    throw new RulesEvaluationException('Unable to load group with gid "@gid"', array('@gid' => $role->gid));
    // Stop processing the rule here
    return;
  }
  // Make it so.
  og_role_revoke($role->gid, $account->uid, $role->rid);
  // Tell the user about their new permissions!
  if (count(drupal_get_messages()) < 1) {
    drupal_set_message(t('Access to the role "@role" in group "@group" has been revoked.', array('@role' => $role->name, '@group' => $group->label)));
  }
  return;
}

/**
 * Checks if a role exists within a group.
 * @param $group_gid
 *  The group to check.
 * @param $role_rid
 *  The role to look for.
 * @return bool
 */
function og_role_field_rules_group_contains_role($group_gid, $role_rid) {
  $group = $role = NULL;
  // Check that role exists
  if (FALSE == ($role = og_role_load($role_rid))) {
    // Role doesn't exist.
    return FALSE;
  }
  // This must be a STRICT comparison or global group IDs (0) may act as FALSE.
  return ($group_gid === $role->gid);
}

/**
 * Checks if a user has a group role.
 * @param $account
 *  The user in question.
 * @param $role_rid
 *  The role in question.
 */
function og_role_field_rules_user_has_group_role($account, $role_rid) {
  $group = $role = NULL;
  // Check that role exists
  if (FALSE == ($role = og_role_load($role_rid))) {
    throw new RulesEvaluationException('Unable to load group role with rid "@rid"', array('@rid' => $role_rid));
  }
  // Check that group of role exists
  if (FALSE == ($group = og_load($role->gid))) {
    throw new RulesEvaluationException('Unable to load group from role with gid "@gid" and rid "@rid"', array('@rid' => $role_rid, '@gid' => $role->gid));
  }
  // Og_get_user_roles returns a keyed array.
  // If the role_id provided exists, it will be present in our resulting array.
  $roles = og_get_user_roles($group->gid, $account->uid);
  return isset($roles[$role_rid]);
}

/**
 * Checks if a group role is actually a global role.
 * @param $role_rid
 *  The role in question.
 */
function og_role_field_rules_group_role_is_global($role_rid) {
  // Load up organic groups' global roles.
  // These results are keyed by role id.
  $roles = og_get_global_roles();
  return isset($roles[$role_rid]);
}

/**
 * Loads a role for manipulation by rules.
 * @param $rid
 *  The role ID to load from.
 * @return stdObject
 */
function og_role_field_rules_load_role($rid) {
  $role = FALSE;
  if (FALSE !== ($role = og_role_load($rid))) {
    return array('og_role' => $role);
  }
  throw new RulesEvaluationException('Unable to load group role with rid "@rid"', array('@rid' => $rid));
}

