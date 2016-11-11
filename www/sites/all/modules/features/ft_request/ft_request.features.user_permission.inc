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

  // Exported permission: 'create request content'.
  $permissions['create request content'] = array(
    'name' => 'create request content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any request content'.
  $permissions['delete any request content'] = array(
    'name' => 'delete any request content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own request content'.
  $permissions['delete own request content'] = array(
    'name' => 'delete own request content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any request content'.
  $permissions['edit any request content'] = array(
    'name' => 'edit any request content',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own request content'.
  $permissions['edit own request content'] = array(
    'name' => 'edit own request content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

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
