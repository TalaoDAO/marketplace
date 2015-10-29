<?php
/**
 * @file
 * ft_permissions.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function ft_permissions_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:circle:access all webform results'
  $permissions['node:circle:access all webform results'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:access own webform submissions'
  $permissions['node:circle:access own webform submissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:add user'
  $permissions['node:circle:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:administer group'
  $permissions['node:circle:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:approve and deny subscription'
  $permissions['node:circle:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:delete all webform submissions'
  $permissions['node:circle:delete all webform submissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:delete own webform submissions'
  $permissions['node:circle:delete own webform submissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:edit all webform submissions'
  $permissions['node:circle:edit all webform submissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:edit own webform submissions'
  $permissions['node:circle:edit own webform submissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:manage members'
  $permissions['node:circle:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:manage permissions'
  $permissions['node:circle:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:manage roles'
  $permissions['node:circle:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:subscribe'
  $permissions['node:circle:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:circle:subscribe without approval'
  $permissions['node:circle:subscribe without approval'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:circle:unsubscribe'
  $permissions['node:circle:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:circle:update group'
  $permissions['node:circle:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  return $permissions;
}
