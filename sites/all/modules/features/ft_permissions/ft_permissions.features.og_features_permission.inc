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
    'roles' => array(),
  );

  // Exported og permission: 'node:circle:access own webform submissions'
  $permissions['node:circle:access own webform submissions'] = array(
    'roles' => array(),
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

  // Exported og permission: 'node:circle:create blog content'
  $permissions['node:circle:create blog content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:create challenge content'
  $permissions['node:circle:create challenge content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:create forum content'
  $permissions['node:circle:create forum content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:circle:create poll content'
  $permissions['node:circle:create poll content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:circle:create question1 content'
  $permissions['node:circle:create question1 content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:create webform content'
  $permissions['node:circle:create webform content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:delete all webform submissions'
  $permissions['node:circle:delete all webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:circle:delete any blog content'
  $permissions['node:circle:delete any blog content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:delete any challenge content'
  $permissions['node:circle:delete any challenge content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:delete any forum content'
  $permissions['node:circle:delete any forum content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:delete any poll content'
  $permissions['node:circle:delete any poll content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:delete any question1 content'
  $permissions['node:circle:delete any question1 content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:delete any webform content'
  $permissions['node:circle:delete any webform content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:delete own blog content'
  $permissions['node:circle:delete own blog content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:delete own challenge content'
  $permissions['node:circle:delete own challenge content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:circle:delete own forum content'
  $permissions['node:circle:delete own forum content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:circle:delete own poll content'
  $permissions['node:circle:delete own poll content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:circle:delete own question1 content'
  $permissions['node:circle:delete own question1 content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:circle:delete own webform content'
  $permissions['node:circle:delete own webform content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:circle:delete own webform submissions'
  $permissions['node:circle:delete own webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:circle:edit all webform submissions'
  $permissions['node:circle:edit all webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:circle:edit own webform submissions'
  $permissions['node:circle:edit own webform submissions'] = array(
    'roles' => array(),
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
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:circle:subscribe without approval'
  $permissions['node:circle:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:circle:unsubscribe'
  $permissions['node:circle:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:circle:update any blog content'
  $permissions['node:circle:update any blog content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:update any challenge content'
  $permissions['node:circle:update any challenge content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:update any forum content'
  $permissions['node:circle:update any forum content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:update any poll content'
  $permissions['node:circle:update any poll content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:update any question1 content'
  $permissions['node:circle:update any question1 content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:update any webform content'
  $permissions['node:circle:update any webform content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:update group'
  $permissions['node:circle:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:update own blog content'
  $permissions['node:circle:update own blog content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:circle:update own challenge content'
  $permissions['node:circle:update own challenge content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:circle:update own forum content'
  $permissions['node:circle:update own forum content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:circle:update own poll content'
  $permissions['node:circle:update own poll content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:circle:update own question1 content'
  $permissions['node:circle:update own question1 content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:circle:update own webform content'
  $permissions['node:circle:update own webform content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:access all webform results'
  $permissions['node:working_group:access all webform results'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:access own webform submissions'
  $permissions['node:working_group:access own webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:add user'
  $permissions['node:working_group:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:administer group'
  $permissions['node:working_group:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:approve and deny subscription'
  $permissions['node:working_group:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:create blog content'
  $permissions['node:working_group:create blog content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:create challenge content'
  $permissions['node:working_group:create challenge content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:create forum content'
  $permissions['node:working_group:create forum content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:create poll content'
  $permissions['node:working_group:create poll content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:create question1 content'
  $permissions['node:working_group:create question1 content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:create webform content'
  $permissions['node:working_group:create webform content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete all webform submissions'
  $permissions['node:working_group:delete all webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete any blog content'
  $permissions['node:working_group:delete any blog content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete any challenge content'
  $permissions['node:working_group:delete any challenge content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete any forum content'
  $permissions['node:working_group:delete any forum content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:delete any poll content'
  $permissions['node:working_group:delete any poll content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:delete any question1 content'
  $permissions['node:working_group:delete any question1 content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete any webform content'
  $permissions['node:working_group:delete any webform content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete own blog content'
  $permissions['node:working_group:delete own blog content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete own challenge content'
  $permissions['node:working_group:delete own challenge content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete own forum content'
  $permissions['node:working_group:delete own forum content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:delete own poll content'
  $permissions['node:working_group:delete own poll content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:delete own question1 content'
  $permissions['node:working_group:delete own question1 content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete own webform content'
  $permissions['node:working_group:delete own webform content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete own webform submissions'
  $permissions['node:working_group:delete own webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:edit all webform submissions'
  $permissions['node:working_group:edit all webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:edit own webform submissions'
  $permissions['node:working_group:edit own webform submissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:manage members'
  $permissions['node:working_group:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:manage permissions'
  $permissions['node:working_group:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:manage roles'
  $permissions['node:working_group:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:subscribe'
  $permissions['node:working_group:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:working_group:subscribe without approval'
  $permissions['node:working_group:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:unsubscribe'
  $permissions['node:working_group:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:update any blog content'
  $permissions['node:working_group:update any blog content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:update any challenge content'
  $permissions['node:working_group:update any challenge content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:update any forum content'
  $permissions['node:working_group:update any forum content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:update any poll content'
  $permissions['node:working_group:update any poll content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:update any question1 content'
  $permissions['node:working_group:update any question1 content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:update any webform content'
  $permissions['node:working_group:update any webform content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:update group'
  $permissions['node:working_group:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:update own blog content'
  $permissions['node:working_group:update own blog content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:update own challenge content'
  $permissions['node:working_group:update own challenge content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:update own forum content'
  $permissions['node:working_group:update own forum content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:update own poll content'
  $permissions['node:working_group:update own poll content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:update own question1 content'
  $permissions['node:working_group:update own question1 content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:update own webform content'
  $permissions['node:working_group:update own webform content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
