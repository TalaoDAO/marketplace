<?php
/**
 * @file
 * ft_public_request.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ft_public_request_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create public_request content'.
  $permissions['create public_request content'] = array(
    'name' => 'create public_request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any public_request content'.
  $permissions['delete any public_request content'] = array(
    'name' => 'delete any public_request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own public_request content'.
  $permissions['delete own public_request content'] = array(
    'name' => 'delete own public_request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any public_request content'.
  $permissions['edit any public_request content'] = array(
    'name' => 'edit any public_request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own public_request content'.
  $permissions['edit own public_request content'] = array(
    'name' => 'edit own public_request content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
