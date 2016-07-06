<?php
/**
 * @file
 * ft_request.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ft_request_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'flag my_selection'.
  $permissions['flag my_selection'] = array(
    'name' => 'flag my_selection',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag my_selection'.
  $permissions['unflag my_selection'] = array(
    'name' => 'unflag my_selection',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
