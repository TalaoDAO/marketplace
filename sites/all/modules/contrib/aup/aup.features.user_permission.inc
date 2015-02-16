<?php
/**
 * @file
 * aup.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function aup_user_default_permissions() {
  $permissions = array();

  // Exported permission: view own userpoints.
  $permissions['view own userpoints'] = array(
    'name' => 'view own userpoints',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: view rate results page.
  $permissions['view rate results page'] = array(
    'name' => 'view rate results page',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'rate',
  );

  // Exported permission: view userpoints.
  $permissions['view userpoints'] = array(
    'name' => 'view userpoints',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'userpoints',
  );

  return $permissions;
}
