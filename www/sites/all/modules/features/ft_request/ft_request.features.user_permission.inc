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

  // Exported permission: 'flag comment_answer'.
  $permissions['flag comment_answer'] = array(
    'name' => 'flag comment_answer',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag interesting_answer'.
  $permissions['flag interesting_answer'] = array(
    'name' => 'flag interesting_answer',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag comment_answer'.
  $permissions['unflag comment_answer'] = array(
    'name' => 'unflag comment_answer',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag interesting_answer'.
  $permissions['unflag interesting_answer'] = array(
    'name' => 'unflag interesting_answer',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
