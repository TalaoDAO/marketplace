<?php
/**
 * @file
 * ft_permissions.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function ft_permissions_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:circle:Creator member'.
  $roles['node:circle:Creator member'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'circle',
    'name' => 'Creator member',
  );

  // Exported OG Role: 'node:circle:Referent member'.
  $roles['node:circle:Referent member'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'circle',
    'name' => 'Referent member',
  );

  return $roles;
}
