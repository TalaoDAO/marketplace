<?php
/**
 * @file
 * ft_user_config.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ft_user_config_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: business.
  $roles['business'] = array(
    'name' => 'business',
    'weight' => 4,
  );

  // Exported role: expert.
  $roles['expert'] = array(
    'name' => 'expert',
    'weight' => 3,
  );

  // Exported role: référent.
  $roles['référent'] = array(
    'name' => 'référent',
    'weight' => 6,
  );

  // Exported role: webmaster.
  $roles['webmaster'] = array(
    'name' => 'webmaster',
    'weight' => 5,
  );

  return $roles;
}
