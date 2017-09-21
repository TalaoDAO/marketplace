<?php
/**
 * @file
 * ft_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ft_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access EMH answers'.
  $permissions['access EMH answers'] = array(
    'name' => 'access EMH answers',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'emh_answer',
  );

  // Exported permission: 'access EMH profiles'.
  $permissions['access EMH profiles'] = array(
    'name' => 'access EMH profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'emh_user',
  );

  // Exported permission: 'access EMH requests'.
  $permissions['access EMH requests'] = array(
    'name' => 'access EMH requests',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'emh_request',
  );

  // Exported permission: 'access admin theme'.
  $permissions['access admin theme'] = array(
    'name' => 'access admin theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_theme',
  );

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'expert' => 'expert',
      'référent' => 'référent',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access environment indicator'.
  $permissions['access environment indicator'] = array(
    'name' => 'access environment indicator',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator clone'.
  $permissions['access environment indicator clone'] = array(
    'name' => 'access environment indicator clone',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator demo'.
  $permissions['access environment indicator demo'] = array(
    'name' => 'access environment indicator demo',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator dev'.
  $permissions['access environment indicator dev'] = array(
    'name' => 'access environment indicator dev',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator overwritten_environment'.
  $permissions['access environment indicator overwritten_environment'] = array(
    'name' => 'access environment indicator overwritten_environment',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator preprod'.
  $permissions['access environment indicator preprod'] = array(
    'name' => 'access environment indicator preprod',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator prod'.
  $permissions['access environment indicator prod'] = array(
    'name' => 'access environment indicator prod',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator test'.
  $permissions['access environment indicator test'] = array(
    'name' => 'access environment indicator test',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access language en'.
  $permissions['access language en'] = array(
    'name' => 'access language en',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'language_access',
  );

  // Exported permission: 'access language fr'.
  $permissions['access language fr'] = array(
    'name' => 'access language fr',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'webmaster' => 'webmaster',
    ),
    'module' => 'language_access',
  );

  // Exported permission: 'access mail logger'.
  $permissions['access mail logger'] = array(
    'name' => 'access mail logger',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'mail_logger',
  );

  // Exported permission: 'access own authorizations'.
  $permissions['access own authorizations'] = array(
    'name' => 'access own authorizations',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access own consumers'.
  $permissions['access own consumers'] = array(
    'name' => 'access own consumers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'business' => 'business',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'business' => 'business',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access service links'.
  $permissions['access service links'] = array(
    'name' => 'access service links',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'business' => 'business',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'service_links',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user contact forms'.
  $permissions['access user contact forms'] = array(
    'name' => 'access user contact forms',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'référent' => 'référent',
    ),
    'module' => 'user',
  );

  // Exported permission: 'act as Creator member in og node:circle'.
  $permissions['act as Creator member in og node:circle'] = array(
    'name' => 'act as Creator member in og node:circle',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'og_role_override',
  );

  // Exported permission: 'act as Referent member in og node:circle'.
  $permissions['act as Referent member in og node:circle'] = array(
    'name' => 'act as Referent member in og node:circle',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'og_role_override',
  );

  // Exported permission: 'act as administrator member in og node:circle'.
  $permissions['act as administrator member in og node:circle'] = array(
    'name' => 'act as administrator member in og node:circle',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'og_role_override',
  );

  // Exported permission: 'act as member in og node:circle'.
  $permissions['act as member in og node:circle'] = array(
    'name' => 'act as member in og node:circle',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'og_role_override',
  );

  // Exported permission: 'act as non-member in og node:circle'.
  $permissions['act as non-member in og node:circle'] = array(
    'name' => 'act as non-member in og node:circle',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'og_role_override',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'admin queue_ui'.
  $permissions['admin queue_ui'] = array(
    'name' => 'admin queue_ui',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'queue_ui',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer consumers'.
  $permissions['administer consumers'] = array(
    'name' => 'administer consumers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer contact forms'.
  $permissions['administer contact forms'] = array(
    'name' => 'administer contact forms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'administer content translations'.
  $permissions['administer content translations'] = array(
    'name' => 'administer content translations',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'i18n_node',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer credits'.
  $permissions['administer credits'] = array(
    'name' => 'administer credits',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'emh_points',
  );

  // Exported permission: 'administer dependencies'.
  $permissions['administer dependencies'] = array(
    'name' => 'administer dependencies',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'conditional_fields',
  );

  // Exported permission: 'administer earnings'.
  $permissions['administer earnings'] = array(
    'name' => 'administer earnings',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'emh_points_earnings',
  );

  // Exported permission: 'administer entity legal'.
  $permissions['administer entity legal'] = array(
    'name' => 'administer entity legal',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_legal',
  );

  // Exported permission: 'administer entity translation'.
  $permissions['administer entity translation'] = array(
    'name' => 'administer entity translation',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'administer environment indicator settings'.
  $permissions['administer environment indicator settings'] = array(
    'name' => 'administer environment indicator settings',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'administer fancy file delete'.
  $permissions['administer fancy file delete'] = array(
    'name' => 'administer fancy file delete',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'fancy_file_delete',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer fields'.
  $permissions['administer fields'] = array(
    'name' => 'administer fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field',
  );

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer formtips'.
  $permissions['administer formtips'] = array(
    'name' => 'administer formtips',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'formtips',
  );

  // Exported permission: 'administer group'.
  $permissions['administer group'] = array(
    'name' => 'administer group',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'og',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer mail templates'.
  $permissions['administer mail templates'] = array(
    'name' => 'administer mail templates',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'mail_edit',
  );

  // Exported permission: 'administer mailsystem'.
  $permissions['administer mailsystem'] = array(
    'name' => 'administer mailsystem',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mailsystem',
  );

  // Exported permission: 'administer media'.
  $permissions['administer media'] = array(
    'name' => 'administer media',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu attributes'.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'menu_attributes',
  );

  // Exported permission: 'administer menu_token'.
  $permissions['administer menu_token'] = array(
    'name' => 'administer menu_token',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu_token',
  );

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer oauth'.
  $permissions['administer oauth'] = array(
    'name' => 'administer oauth',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer pcp'.
  $permissions['administer pcp'] = array(
    'name' => 'administer pcp',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pcp',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
      'roleswitcher' => 'roleswitcher',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer rules forms'.
  $permissions['administer rules forms'] = array(
    'name' => 'administer rules forms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules_forms',
  );

  // Exported permission: 'administer rules forms rules'.
  $permissions['administer rules forms rules'] = array(
    'name' => 'administer rules forms rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules_forms',
  );

  // Exported permission: 'administer simplify'.
  $permissions['administer simplify'] = array(
    'name' => 'administer simplify',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'simplify',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer string overrides'.
  $permissions['administer string overrides'] = array(
    'name' => 'administer string overrides',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'stringoverrides',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer user field roles'.
  $permissions['administer user field roles'] = array(
    'name' => 'administer user field roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user_role_field',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer voting api'.
  $permissions['administer voting api'] = array(
    'name' => 'administer voting api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'votingapi',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'cashout earnings'.
  $permissions['cashout earnings'] = array(
    'name' => 'cashout earnings',
    'roles' => array(),
    'module' => 'emh_points_earnings',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create challenge content'.
  $permissions['create challenge content'] = array(
    'name' => 'create challenge content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create circle content'.
  $permissions['create circle content'] = array(
    'name' => 'create circle content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create corporate content'.
  $permissions['create corporate content'] = array(
    'name' => 'create corporate content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_force_public_answer'.
  $permissions['create field_force_public_answer'] = array(
    'name' => 'create field_force_public_answer',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_referent'.
  $permissions['create field_referent'] = array(
    'name' => 'create field_referent',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_request_circle'.
  $permissions['create field_request_circle'] = array(
    'name' => 'create field_request_circle',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_tracking_key'.
  $permissions['create field_tracking_key'] = array(
    'name' => 'create field_tracking_key',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_tracking_referer'.
  $permissions['create field_tracking_referer'] = array(
    'name' => 'create field_tracking_referer',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create public_request content'.
  $permissions['create public_request content'] = array(
    'name' => 'create public_request content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create question1 content'.
  $permissions['create question1 content'] = array(
    'name' => 'create question1 content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create request content'.
  $permissions['create request content'] = array(
    'name' => 'create request content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any challenge content'.
  $permissions['delete any challenge content'] = array(
    'name' => 'delete any challenge content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any circle content'.
  $permissions['delete any circle content'] = array(
    'name' => 'delete any circle content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any corporate content'.
  $permissions['delete any corporate content'] = array(
    'name' => 'delete any corporate content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any public_request content'.
  $permissions['delete any public_request content'] = array(
    'name' => 'delete any public_request content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any question1 content'.
  $permissions['delete any question1 content'] = array(
    'name' => 'delete any question1 content',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own challenge content'.
  $permissions['delete own challenge content'] = array(
    'name' => 'delete own challenge content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own circle content'.
  $permissions['delete own circle content'] = array(
    'name' => 'delete own circle content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own corporate content'.
  $permissions['delete own corporate content'] = array(
    'name' => 'delete own corporate content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own public_request content'.
  $permissions['delete own public_request content'] = array(
    'name' => 'delete own public_request content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own question1 content'.
  $permissions['delete own question1 content'] = array(
    'name' => 'delete own question1 content',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in domaine'.
  $permissions['delete terms in domaine'] = array(
    'name' => 'delete terms in domaine',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in forums'.
  $permissions['delete terms in forums'] = array(
    'name' => 'delete terms in forums',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in known_how'.
  $permissions['delete terms in known_how'] = array(
    'name' => 'delete terms in known_how',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in notification_frequencies'.
  $permissions['delete terms in notification_frequencies'] = array(
    'name' => 'delete terms in notification_frequencies',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in position'.
  $permissions['delete terms in position'] = array(
    'name' => 'delete terms in position',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in publications'.
  $permissions['delete terms in publications'] = array(
    'name' => 'delete terms in publications',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in request_type'.
  $permissions['delete terms in request_type'] = array(
    'name' => 'delete terms in request_type',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in skill'.
  $permissions['delete terms in skill'] = array(
    'name' => 'delete terms in skill',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in userpoints'.
  $permissions['delete terms in userpoints'] = array(
    'name' => 'delete terms in userpoints',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any challenge content'.
  $permissions['edit any challenge content'] = array(
    'name' => 'edit any challenge content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any circle content'.
  $permissions['edit any circle content'] = array(
    'name' => 'edit any circle content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any corporate content'.
  $permissions['edit any corporate content'] = array(
    'name' => 'edit any corporate content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any public_request content'.
  $permissions['edit any public_request content'] = array(
    'name' => 'edit any public_request content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any question1 content'.
  $permissions['edit any question1 content'] = array(
    'name' => 'edit any question1 content',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_force_public_answer'.
  $permissions['edit field_force_public_answer'] = array(
    'name' => 'edit field_force_public_answer',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_referent'.
  $permissions['edit field_referent'] = array(
    'name' => 'edit field_referent',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_request_circle'.
  $permissions['edit field_request_circle'] = array(
    'name' => 'edit field_request_circle',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_tracking_key'.
  $permissions['edit field_tracking_key'] = array(
    'name' => 'edit field_tracking_key',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_tracking_referer'.
  $permissions['edit field_tracking_referer'] = array(
    'name' => 'edit field_tracking_referer',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit media'.
  $permissions['edit media'] = array(
    'name' => 'edit media',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'business' => 'business',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'media',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit mimemail user settings'.
  $permissions['edit mimemail user settings'] = array(
    'name' => 'edit mimemail user settings',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own challenge content'.
  $permissions['edit own challenge content'] = array(
    'name' => 'edit own challenge content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own circle content'.
  $permissions['edit own circle content'] = array(
    'name' => 'edit own circle content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own corporate content'.
  $permissions['edit own corporate content'] = array(
    'name' => 'edit own corporate content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_force_public_answer'.
  $permissions['edit own field_force_public_answer'] = array(
    'name' => 'edit own field_force_public_answer',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_referent'.
  $permissions['edit own field_referent'] = array(
    'name' => 'edit own field_referent',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_request_circle'.
  $permissions['edit own field_request_circle'] = array(
    'name' => 'edit own field_request_circle',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_tracking_key'.
  $permissions['edit own field_tracking_key'] = array(
    'name' => 'edit own field_tracking_key',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_tracking_referer'.
  $permissions['edit own field_tracking_referer'] = array(
    'name' => 'edit own field_tracking_referer',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own public_request content'.
  $permissions['edit own public_request content'] = array(
    'name' => 'edit own public_request content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own question1 content'.
  $permissions['edit own question1 content'] = array(
    'name' => 'edit own question1 content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own request content'.
  $permissions['edit own request content'] = array(
    'name' => 'edit own request content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit terms in domaine'.
  $permissions['edit terms in domaine'] = array(
    'name' => 'edit terms in domaine',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in forums'.
  $permissions['edit terms in forums'] = array(
    'name' => 'edit terms in forums',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in known_how'.
  $permissions['edit terms in known_how'] = array(
    'name' => 'edit terms in known_how',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in notification_frequencies'.
  $permissions['edit terms in notification_frequencies'] = array(
    'name' => 'edit terms in notification_frequencies',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in position'.
  $permissions['edit terms in position'] = array(
    'name' => 'edit terms in position',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in publications'.
  $permissions['edit terms in publications'] = array(
    'name' => 'edit terms in publications',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in request_type'.
  $permissions['edit terms in request_type'] = array(
    'name' => 'edit terms in request_type',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in skill'.
  $permissions['edit terms in skill'] = array(
    'name' => 'edit terms in skill',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in userpoints'.
  $permissions['edit terms in userpoints'] = array(
    'name' => 'edit terms in userpoints',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'flag my_contacts'.
  $permissions['flag my_contacts'] = array(
    'name' => 'flag my_contacts',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag my_selection'.
  $permissions['flag my_selection'] = array(
    'name' => 'flag my_selection',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'import media'.
  $permissions['import media'] = array(
    'name' => 'import media',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'media',
  );

  // Exported permission: 'invite experts'.
  $permissions['invite experts'] = array(
    'name' => 'invite experts',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'emh_virality',
  );

  // Exported permission: 'legal re-accept terms_of_use'.
  $permissions['legal re-accept terms_of_use'] = array(
    'name' => 'legal re-accept terms_of_use',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'entity_legal',
  );

  // Exported permission: 'legal view terms_of_use'.
  $permissions['legal view terms_of_use'] = array(
    'name' => 'legal view terms_of_use',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'entity_legal',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'merge domaine terms'.
  $permissions['merge domaine terms'] = array(
    'name' => 'merge domaine terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge forums terms'.
  $permissions['merge forums terms'] = array(
    'name' => 'merge forums terms',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge known_how terms'.
  $permissions['merge known_how terms'] = array(
    'name' => 'merge known_how terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge notification_frequencies terms'.
  $permissions['merge notification_frequencies terms'] = array(
    'name' => 'merge notification_frequencies terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge position terms'.
  $permissions['merge position terms'] = array(
    'name' => 'merge position terms',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge publications terms'.
  $permissions['merge publications terms'] = array(
    'name' => 'merge publications terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge request_type terms'.
  $permissions['merge request_type terms'] = array(
    'name' => 'merge request_type terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge skill terms'.
  $permissions['merge skill terms'] = array(
    'name' => 'merge skill terms',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge tags terms'.
  $permissions['merge tags terms'] = array(
    'name' => 'merge tags terms',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge terms'.
  $permissions['merge terms'] = array(
    'name' => 'merge terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge userpoints terms'.
  $permissions['merge userpoints terms'] = array(
    'name' => 'merge userpoints terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'modify requests'.
  $permissions['modify requests'] = array(
    'name' => 'modify requests',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'emh_request',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'oauth authorize any consumers'.
  $permissions['oauth authorize any consumers'] = array(
    'name' => 'oauth authorize any consumers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'oauth register any consumers'.
  $permissions['oauth register any consumers'] = array(
    'name' => 'oauth register any consumers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'rate content'.
  $permissions['rate content'] = array(
    'name' => 'rate content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fivestar',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'save comment draft'.
  $permissions['save comment draft'] = array(
    'name' => 'save comment draft',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'emh_answer',
  );

  // Exported permission: 'save draft'.
  $permissions['save draft'] = array(
    'name' => 'save draft',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'expert' => 'expert',
      'référent' => 'référent',
    ),
    'module' => 'save_draft',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'send arbitrary files'.
  $permissions['send arbitrary files'] = array(
    'name' => 'send arbitrary files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'toggle field translatability'.
  $permissions['toggle field translatability'] = array(
    'name' => 'toggle field translatability',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate any entity'.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate content'.
  $permissions['translate content'] = array(
    'name' => 'translate content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate node entities'.
  $permissions['translate node entities'] = array(
    'name' => 'translate node entities',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate taxonomy_term entities'.
  $permissions['translate taxonomy_term entities'] = array(
    'name' => 'translate taxonomy_term entities',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'unflag my_contacts'.
  $permissions['unflag my_contacts'] = array(
    'name' => 'unflag my_contacts',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
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

  // Exported permission: 'use PHP for label patterns'.
  $permissions['use PHP for label patterns'] = array(
    'name' => 'use PHP for label patterns',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'auto_entitylabel',
  );

  // Exported permission: 'use PHP for service visibility'.
  $permissions['use PHP for service visibility'] = array(
    'name' => 'use PHP for service visibility',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'service_links',
  );

  // Exported permission: 'use PHP for settings'.
  $permissions['use PHP for settings'] = array(
    'name' => 'use PHP for settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'php',
  );

  // Exported permission: 'use advancedform'.
  $permissions['use advancedform'] = array(
    'name' => 'use advancedform',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'advancedform',
  );

  // Exported permission: 'use bootstrap optimizer'.
  $permissions['use bootstrap optimizer'] = array(
    'name' => 'use bootstrap optimizer',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bootstrap_optimizer',
  );

  // Exported permission: 'use bulk exporter'.
  $permissions['use bulk exporter'] = array(
    'name' => 'use bulk exporter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bulk_export',
  );

  // Exported permission: 'use credits'.
  $permissions['use credits'] = array(
    'name' => 'use credits',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'emh_points',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use hybridauth'.
  $permissions['use hybridauth'] = array(
    'name' => 'use hybridauth',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'hybridauth',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'view field_force_public_answer'.
  $permissions['view field_force_public_answer'] = array(
    'name' => 'view field_force_public_answer',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_referent'.
  $permissions['view field_referent'] = array(
    'name' => 'view field_referent',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_request_circle'.
  $permissions['view field_request_circle'] = array(
    'name' => 'view field_request_circle',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_tracking_key'.
  $permissions['view field_tracking_key'] = array(
    'name' => 'view field_tracking_key',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view hidden fields'.
  $permissions['view hidden fields'] = array(
    'name' => 'view hidden fields',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'simplify',
  );

  // Exported permission: 'view media'.
  $permissions['view media'] = array(
    'name' => 'view media',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'business' => 'business',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'media',
  );

  // Exported permission: 'view others credits history'.
  $permissions['view others credits history'] = array(
    'name' => 'view others credits history',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'emh_points',
  );

  // Exported permission: 'view others invitations history'.
  $permissions['view others invitations history'] = array(
    'name' => 'view others invitations history',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'emh_virality',
  );

  // Exported permission: 'view own earnings'.
  $permissions['view own earnings'] = array(
    'name' => 'view own earnings',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'emh_points_earnings',
  );

  // Exported permission: 'view own field_force_public_answer'.
  $permissions['view own field_force_public_answer'] = array(
    'name' => 'view own field_force_public_answer',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_referent'.
  $permissions['view own field_referent'] = array(
    'name' => 'view own field_referent',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_request_circle'.
  $permissions['view own field_request_circle'] = array(
    'name' => 'view own field_request_circle',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_tracking_key'.
  $permissions['view own field_tracking_key'] = array(
    'name' => 'view own field_tracking_key',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_tracking_referer'.
  $permissions['view own field_tracking_referer'] = array(
    'name' => 'view own field_tracking_referer',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'business' => 'business',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'system',
  );

  return $permissions;
}
