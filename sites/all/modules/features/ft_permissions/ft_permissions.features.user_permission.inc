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
      'authenticated user' => 'authenticated user',
      'webmaster' => 'webmaster',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
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

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access ckeditor link'.
  $permissions['access ckeditor link'] = array(
    'name' => 'access ckeditor link',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'business preview' => 'business preview',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'ckeditor_link',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
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

  // Exported permission: 'access environment indicator'.
  $permissions['access environment indicator'] = array(
    'name' => 'access environment indicator',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator demo'.
  $permissions['access environment indicator demo'] = array(
    'name' => 'access environment indicator demo',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator dev'.
  $permissions['access environment indicator dev'] = array(
    'name' => 'access environment indicator dev',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator overwritten_environment'.
  $permissions['access environment indicator overwritten_environment'] = array(
    'name' => 'access environment indicator overwritten_environment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator preprod'.
  $permissions['access environment indicator preprod'] = array(
    'name' => 'access environment indicator preprod',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator preview'.
  $permissions['access environment indicator preview'] = array(
    'name' => 'access environment indicator preview',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access epostcard'.
  $permissions['access epostcard'] = array(
    'name' => 'access epostcard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'forward',
  );

  // Exported permission: 'access forward'.
  $permissions['access forward'] = array(
    'name' => 'access forward',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'forward',
  );

  // Exported permission: 'access image styles mapping reports'.
  $permissions['access image styles mapping reports'] = array(
    'name' => 'access image styles mapping reports',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'image_styles_mapping',
  );

  // Exported permission: 'access mb content'.
  $permissions['access mb content'] = array(
    'name' => 'access mb content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'mb_content',
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
      'business preview' => 'business preview',
      'expert preview' => 'expert preview',
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
      'business' => 'business',
      'business preview' => 'business preview',
      'expert' => 'expert',
      'expert preview' => 'expert preview',
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

  // Exported permission: 'act as administrator member in og node:circle'.
  $permissions['act as administrator member in og node:circle'] = array(
    'name' => 'act as administrator member in og node:circle',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'og_role_override',
  );

  // Exported permission: 'act as administrator member in og node:working_group'.
  $permissions['act as administrator member in og node:working_group'] = array(
    'name' => 'act as administrator member in og node:working_group',
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

  // Exported permission: 'act as member in og node:working_group'.
  $permissions['act as member in og node:working_group'] = array(
    'name' => 'act as member in og node:working_group',
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

  // Exported permission: 'act as non-member in og node:working_group'.
  $permissions['act as non-member in og node:working_group'] = array(
    'name' => 'act as non-member in og node:working_group',
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

  // Exported permission: 'admin_classes'.
  $permissions['admin_classes'] = array(
    'name' => 'admin_classes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds',
  );

  // Exported permission: 'admin_fields'.
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_view_modes'.
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'administer EU Cookie Compliance popup'.
  $permissions['administer EU Cookie Compliance popup'] = array(
    'name' => 'administer EU Cookie Compliance popup',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'eu_cookie_compliance',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer autoassignrole'.
  $permissions['administer autoassignrole'] = array(
    'name' => 'administer autoassignrole',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'autoassignrole',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer block classes'.
  $permissions['administer block classes'] = array(
    'name' => 'administer block classes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block_class',
  );

  // Exported permission: 'administer block groups'.
  $permissions['administer block groups'] = array(
    'name' => 'administer block groups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'blockgroup',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer ckeditor link'.
  $permissions['administer ckeditor link'] = array(
    'name' => 'administer ckeditor link',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ckeditor_link',
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

  // Exported permission: 'administer css injection'.
  $permissions['administer css injection'] = array(
    'name' => 'administer css injection',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'css_injector',
  );

  // Exported permission: 'administer dependencies'.
  $permissions['administer dependencies'] = array(
    'name' => 'administer dependencies',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'conditional_fields',
  );

  // Exported permission: 'administer entity legal'.
  $permissions['administer entity legal'] = array(
    'name' => 'administer entity legal',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'entity_legal',
  );

  // Exported permission: 'administer environment indicator settings'.
  $permissions['administer environment indicator settings'] = array(
    'name' => 'administer environment indicator settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'environment_indicator',
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

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
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

  // Exported permission: 'administer forums'.
  $permissions['administer forums'] = array(
    'name' => 'administer forums',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'forum',
  );

  // Exported permission: 'administer forward'.
  $permissions['administer forward'] = array(
    'name' => 'administer forward',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'forward',
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

  // Exported permission: 'administer homebox'.
  $permissions['administer homebox'] = array(
    'name' => 'administer homebox',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'homebox',
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
      'webmaster' => 'webmaster',
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

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer more buttons'.
  $permissions['administer more buttons'] = array(
    'name' => 'administer more buttons',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'mb',
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

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer piwik'.
  $permissions['administer piwik'] = array(
    'name' => 'administer piwik',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'piwik',
  );

  // Exported permission: 'administer privatecomments forms'.
  $permissions['administer privatecomments forms'] = array(
    'name' => 'administer privatecomments forms',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'privatecomments',
  );

  // Exported permission: 'administer privatemsg settings'.
  $permissions['administer privatemsg settings'] = array(
    'name' => 'administer privatemsg settings',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'administer quicktabs'.
  $permissions['administer quicktabs'] = array(
    'name' => 'administer quicktabs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'quicktabs',
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

  // Exported permission: 'administer scheduler'.
  $permissions['administer scheduler'] = array(
    'name' => 'administer scheduler',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'shortcut',
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
      'webmaster' => 'webmaster',
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
      'webmaster' => 'webmaster',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
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

  // Exported permission: 'administer user alert'.
  $permissions['administer user alert'] = array(
    'name' => 'administer user alert',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'user_alert',
  );

  // Exported permission: 'administer user field roles'.
  $permissions['administer user field roles'] = array(
    'name' => 'administer user field roles',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
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

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer views calc'.
  $permissions['administer views calc'] = array(
    'name' => 'administer views calc',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views_calc',
  );

  // Exported permission: 'administer views_send'.
  $permissions['administer views_send'] = array(
    'name' => 'administer views_send',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'views_send',
  );

  // Exported permission: 'administer voting api'.
  $permissions['administer voting api'] = array(
    'name' => 'administer voting api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'votingapi',
  );

  // Exported permission: 'allow disabling privatemsg'.
  $permissions['allow disabling privatemsg'] = array(
    'name' => 'allow disabling privatemsg',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'privatemsg',
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

  // Exported permission: 'blog: comment on any blog content'.
  $permissions['blog: comment on any blog content'] = array(
    'name' => 'blog: comment on any blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_perm',
  );

  // Exported permission: 'blog: comment without approval on any blog content'.
  $permissions['blog: comment without approval on any blog content'] = array(
    'name' => 'blog: comment without approval on any blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_perm',
  );

  // Exported permission: 'blog: comment without approval on own blog content'.
  $permissions['blog: comment without approval on own blog content'] = array(
    'name' => 'blog: comment without approval on own blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_perm',
  );

  // Exported permission: 'blog: edit own comments on blog content'.
  $permissions['blog: edit own comments on blog content'] = array(
    'name' => 'blog: edit own comments on blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_perm',
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

  // Exported permission: 'cancel own vote'.
  $permissions['cancel own vote'] = array(
    'name' => 'cancel own vote',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'poll',
  );

  // Exported permission: 'challenge: comment on any challenge content'.
  $permissions['challenge: comment on any challenge content'] = array(
    'name' => 'challenge: comment on any challenge content',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_perm',
  );

  // Exported permission: 'challenge: comment without approval on any challenge content'.
  $permissions['challenge: comment without approval on any challenge content'] = array(
    'name' => 'challenge: comment without approval on any challenge content',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_perm',
  );

  // Exported permission: 'challenge: comment without approval on own challenge content'.
  $permissions['challenge: comment without approval on own challenge content'] = array(
    'name' => 'challenge: comment without approval on own challenge content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_perm',
  );

  // Exported permission: 'challenge: edit own comments on challenge content'.
  $permissions['challenge: edit own comments on challenge content'] = array(
    'name' => 'challenge: edit own comments on challenge content',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_perm',
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
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create blog content'.
  $permissions['create blog content'] = array(
    'name' => 'create blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create challenge content'.
  $permissions['create challenge content'] = array(
    'name' => 'create challenge content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create circle content'.
  $permissions['create circle content'] = array(
    'name' => 'create circle content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create corporate content'.
  $permissions['create corporate content'] = array(
    'name' => 'create corporate content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_picto'.
  $permissions['create field_picto'] = array(
    'name' => 'create field_picto',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'create forum content'.
  $permissions['create forum content'] = array(
    'name' => 'create forum content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'business' => 'business',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
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

  // Exported permission: 'create poll content'.
  $permissions['create poll content'] = array(
    'name' => 'create poll content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create private message tags'.
  $permissions['create private message tags'] = array(
    'name' => 'create private message tags',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'privatemsg_filter',
  );

  // Exported permission: 'create question1 content'.
  $permissions['create question1 content'] = array(
    'name' => 'create question1 content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
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

  // Exported permission: 'create user_alert content'.
  $permissions['create user_alert content'] = array(
    'name' => 'create user_alert content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create views calc'.
  $permissions['create views calc'] = array(
    'name' => 'create views calc',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views_calc',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create working_group content'.
  $permissions['create working_group content'] = array(
    'name' => 'create working_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'shortcut',
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

  // Exported permission: 'delete any blog content'.
  $permissions['delete any blog content'] = array(
    'name' => 'delete any blog content',
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
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any circle content'.
  $permissions['delete any circle content'] = array(
    'name' => 'delete any circle content',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any corporate content'.
  $permissions['delete any corporate content'] = array(
    'name' => 'delete any corporate content',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any forum content'.
  $permissions['delete any forum content'] = array(
    'name' => 'delete any forum content',
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

  // Exported permission: 'delete any poll content'.
  $permissions['delete any poll content'] = array(
    'name' => 'delete any poll content',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any question1 content'.
  $permissions['delete any question1 content'] = array(
    'name' => 'delete any question1 content',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any user_alert content'.
  $permissions['delete any user_alert content'] = array(
    'name' => 'delete any user_alert content',
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
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any working_group content'.
  $permissions['delete any working_group content'] = array(
    'name' => 'delete any working_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own blog content'.
  $permissions['delete own blog content'] = array(
    'name' => 'delete own blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own challenge content'.
  $permissions['delete own challenge content'] = array(
    'name' => 'delete own challenge content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own circle content'.
  $permissions['delete own circle content'] = array(
    'name' => 'delete own circle content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
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

  // Exported permission: 'delete own forum content'.
  $permissions['delete own forum content'] = array(
    'name' => 'delete own forum content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'référent' => 'référent',
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

  // Exported permission: 'delete own poll content'.
  $permissions['delete own poll content'] = array(
    'name' => 'delete own poll content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own question1 content'.
  $permissions['delete own question1 content'] = array(
    'name' => 'delete own question1 content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own user_alert content'.
  $permissions['delete own user_alert content'] = array(
    'name' => 'delete own user_alert content',
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
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete own working_group content'.
  $permissions['delete own working_group content'] = array(
    'name' => 'delete own working_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete privatemsg'.
  $permissions['delete privatemsg'] = array(
    'name' => 'delete privatemsg',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'business' => 'business',
      'business preview' => 'business preview',
      'expert' => 'expert',
      'expert preview' => 'expert preview',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'privatemsg',
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

  // Exported permission: 'display EU Cookie Compliance popup'.
  $permissions['display EU Cookie Compliance popup'] = array(
    'name' => 'display EU Cookie Compliance popup',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eu_cookie_compliance',
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

  // Exported permission: 'edit any blog content'.
  $permissions['edit any blog content'] = array(
    'name' => 'edit any blog content',
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
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any checklistapi checklist'.
  $permissions['edit any checklistapi checklist'] = array(
    'name' => 'edit any checklistapi checklist',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'checklistapi',
  );

  // Exported permission: 'edit any circle content'.
  $permissions['edit any circle content'] = array(
    'name' => 'edit any circle content',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any corporate content'.
  $permissions['edit any corporate content'] = array(
    'name' => 'edit any corporate content',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any forum content'.
  $permissions['edit any forum content'] = array(
    'name' => 'edit any forum content',
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

  // Exported permission: 'edit any poll content'.
  $permissions['edit any poll content'] = array(
    'name' => 'edit any poll content',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any question1 content'.
  $permissions['edit any question1 content'] = array(
    'name' => 'edit any question1 content',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any user_alert content'.
  $permissions['edit any user_alert content'] = array(
    'name' => 'edit any user_alert content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any working_group content'.
  $permissions['edit any working_group content'] = array(
    'name' => 'edit any working_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_picto'.
  $permissions['edit field_picto'] = array(
    'name' => 'edit field_picto',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own blog content'.
  $permissions['edit own blog content'] = array(
    'name' => 'edit own blog content',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own challenge content'.
  $permissions['edit own challenge content'] = array(
    'name' => 'edit own challenge content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own circle content'.
  $permissions['edit own circle content'] = array(
    'name' => 'edit own circle content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
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

  // Exported permission: 'edit own field_picto'.
  $permissions['edit own field_picto'] = array(
    'name' => 'edit own field_picto',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'edit own forum content'.
  $permissions['edit own forum content'] = array(
    'name' => 'edit own forum content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
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

  // Exported permission: 'edit own poll content'.
  $permissions['edit own poll content'] = array(
    'name' => 'edit own poll content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own question1 content'.
  $permissions['edit own question1 content'] = array(
    'name' => 'edit own question1 content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own user_alert content'.
  $permissions['edit own user_alert content'] = array(
    'name' => 'edit own user_alert content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'business preview' => 'business preview',
      'expert' => 'expert',
      'expert preview' => 'expert preview',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit own working_group content'.
  $permissions['edit own working_group content'] = array(
    'name' => 'edit own working_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'node',
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
      'expert preview' => 'expert preview',
      'référent' => 'référent',
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
      'expert preview' => 'expert preview',
      'référent' => 'référent',
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
      'expert preview' => 'expert preview',
      'référent' => 'référent',
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
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'execute auto_entitylabel_entity_update_action'.
  $permissions['execute auto_entitylabel_entity_update_action'] = array(
    'name' => 'execute auto_entitylabel_entity_update_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute comment_publish_action'.
  $permissions['execute comment_publish_action'] = array(
    'name' => 'execute comment_publish_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute comment_save_action'.
  $permissions['execute comment_save_action'] = array(
    'name' => 'execute comment_save_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute comment_unpublish_action'.
  $permissions['execute comment_unpublish_action'] = array(
    'name' => 'execute comment_unpublish_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute comment_unpublish_by_keyword_action'.
  $permissions['execute comment_unpublish_by_keyword_action'] = array(
    'name' => 'execute comment_unpublish_by_keyword_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute flag_comment_action'.
  $permissions['execute flag_comment_action'] = array(
    'name' => 'execute flag_comment_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute flag_node_action'.
  $permissions['execute flag_node_action'] = array(
    'name' => 'execute flag_node_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute flag_user_action'.
  $permissions['execute flag_user_action'] = array(
    'name' => 'execute flag_user_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_assign_owner_action'.
  $permissions['execute node_assign_owner_action'] = array(
    'name' => 'execute node_assign_owner_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_make_sticky_action'.
  $permissions['execute node_make_sticky_action'] = array(
    'name' => 'execute node_make_sticky_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_make_unsticky_action'.
  $permissions['execute node_make_unsticky_action'] = array(
    'name' => 'execute node_make_unsticky_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_promote_action'.
  $permissions['execute node_promote_action'] = array(
    'name' => 'execute node_promote_action',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_publish_action'.
  $permissions['execute node_publish_action'] = array(
    'name' => 'execute node_publish_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_save_action'.
  $permissions['execute node_save_action'] = array(
    'name' => 'execute node_save_action',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpromote_action'.
  $permissions['execute node_unpromote_action'] = array(
    'name' => 'execute node_unpromote_action',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpublish_action'.
  $permissions['execute node_unpublish_action'] = array(
    'name' => 'execute node_unpublish_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpublish_by_keyword_action'.
  $permissions['execute node_unpublish_by_keyword_action'] = array(
    'name' => 'execute node_unpublish_by_keyword_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute og_membership_delete_action'.
  $permissions['execute og_membership_delete_action'] = array(
    'name' => 'execute og_membership_delete_action',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute og_set_state_action'.
  $permissions['execute og_set_state_action'] = array(
    'name' => 'execute og_set_state_action',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute og_user_roles_action'.
  $permissions['execute og_user_roles_action'] = array(
    'name' => 'execute og_user_roles_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_node_update_action'.
  $permissions['execute pathauto_node_update_action'] = array(
    'name' => 'execute pathauto_node_update_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_taxonomy_term_update_action'.
  $permissions['execute pathauto_taxonomy_term_update_action'] = array(
    'name' => 'execute pathauto_taxonomy_term_update_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_user_update_action'.
  $permissions['execute pathauto_user_update_action'] = array(
    'name' => 'execute pathauto_user_update_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_block_ip_action'.
  $permissions['execute system_block_ip_action'] = array(
    'name' => 'execute system_block_ip_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_goto_action'.
  $permissions['execute system_goto_action'] = array(
    'name' => 'execute system_goto_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_message_action'.
  $permissions['execute system_message_action'] = array(
    'name' => 'execute system_message_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_send_email_action'.
  $permissions['execute system_send_email_action'] = array(
    'name' => 'execute system_send_email_action',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute term_merge_action'.
  $permissions['execute term_merge_action'] = array(
    'name' => 'execute term_merge_action',
    'roles' => array(),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute user_block_user_action'.
  $permissions['execute user_block_user_action'] = array(
    'name' => 'execute user_block_user_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_archive_action'.
  $permissions['execute views_bulk_operations_archive_action'] = array(
    'name' => 'execute views_bulk_operations_archive_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_argument_selector_action'.
  $permissions['execute views_bulk_operations_argument_selector_action'] = array(
    'name' => 'execute views_bulk_operations_argument_selector_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_delete_item'.
  $permissions['execute views_bulk_operations_delete_item'] = array(
    'name' => 'execute views_bulk_operations_delete_item',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_delete_revision'.
  $permissions['execute views_bulk_operations_delete_revision'] = array(
    'name' => 'execute views_bulk_operations_delete_revision',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_modify_action'.
  $permissions['execute views_bulk_operations_modify_action'] = array(
    'name' => 'execute views_bulk_operations_modify_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_script_action'.
  $permissions['execute views_bulk_operations_script_action'] = array(
    'name' => 'execute views_bulk_operations_script_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_user_cancel_action'.
  $permissions['execute views_bulk_operations_user_cancel_action'] = array(
    'name' => 'execute views_bulk_operations_user_cancel_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_user_roles_action'.
  $permissions['execute views_bulk_operations_user_roles_action'] = array(
    'name' => 'execute views_bulk_operations_user_roles_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_extra_handlers_node_revision_publish_status_action'.
  $permissions['execute views_extra_handlers_node_revision_publish_status_action'] = array(
    'name' => 'execute views_extra_handlers_node_revision_publish_status_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_extra_handlers_node_revision_unpublish_status_action'.
  $permissions['execute views_extra_handlers_node_revision_unpublish_status_action'] = array(
    'name' => 'execute views_extra_handlers_node_revision_unpublish_status_action',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'filter private messages'.
  $permissions['filter private messages'] = array(
    'name' => 'filter private messages',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'privatemsg_filter',
  );

  // Exported permission: 'flag my_selection'.
  $permissions['flag my_selection'] = array(
    'name' => 'flag my_selection',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'expert preview' => 'expert preview',
      'webmaster' => 'webmaster',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag winner_calls3'.
  $permissions['flag winner_calls3'] = array(
    'name' => 'flag winner_calls3',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag winner_challenge'.
  $permissions['flag winner_challenge'] = array(
    'name' => 'flag winner_challenge',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag winner_question1'.
  $permissions['flag winner_question1'] = array(
    'name' => 'flag winner_question1',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
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
      'webmaster' => 'webmaster',
    ),
    'module' => 'media',
  );

  // Exported permission: 'inspect all votes'.
  $permissions['inspect all votes'] = array(
    'name' => 'inspect all votes',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'poll',
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
      'webmaster' => 'webmaster',
    ),
    'module' => 'features',
  );

  // Exported permission: 'mass mailing with views_send'.
  $permissions['mass mailing with views_send'] = array(
    'name' => 'mass mailing with views_send',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'views_send',
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
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge skill terms'.
  $permissions['merge skill terms'] = array(
    'name' => 'merge skill terms',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'term_merge',
  );

  // Exported permission: 'merge tags terms'.
  $permissions['merge tags terms'] = array(
    'name' => 'merge tags terms',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'piwik',
  );

  // Exported permission: 'override email address'.
  $permissions['override email address'] = array(
    'name' => 'override email address',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'forward',
  );

  // Exported permission: 'override flood control'.
  $permissions['override flood control'] = array(
    'name' => 'override flood control',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'forward',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'privatecomments challenge view all'.
  $permissions['privatecomments challenge view all'] = array(
    'name' => 'privatecomments challenge view all',
    'roles' => array(
      'administrator' => 'administrator',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'privatecomments',
  );

  // Exported permission: 'privatecomments forum view all'.
  $permissions['privatecomments forum view all'] = array(
    'name' => 'privatecomments forum view all',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'privatecomments',
  );

  // Exported permission: 'publish comments on own article nodes'.
  $permissions['publish comments on own article nodes'] = array(
    'name' => 'publish comments on own article nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'publish comments on own blog nodes'.
  $permissions['publish comments on own blog nodes'] = array(
    'name' => 'publish comments on own blog nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'publish comments on own challenge nodes'.
  $permissions['publish comments on own challenge nodes'] = array(
    'name' => 'publish comments on own challenge nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'business preview' => 'business preview',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'publish comments on own circle nodes'.
  $permissions['publish comments on own circle nodes'] = array(
    'name' => 'publish comments on own circle nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'publish comments on own corporate nodes'.
  $permissions['publish comments on own corporate nodes'] = array(
    'name' => 'publish comments on own corporate nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'publish comments on own forum nodes'.
  $permissions['publish comments on own forum nodes'] = array(
    'name' => 'publish comments on own forum nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'publish comments on own page nodes'.
  $permissions['publish comments on own page nodes'] = array(
    'name' => 'publish comments on own page nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'publish comments on own poll nodes'.
  $permissions['publish comments on own poll nodes'] = array(
    'name' => 'publish comments on own poll nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'publish comments on own question1 nodes'.
  $permissions['publish comments on own question1 nodes'] = array(
    'name' => 'publish comments on own question1 nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'business preview' => 'business preview',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'publish comments on own user_alert nodes'.
  $permissions['publish comments on own user_alert nodes'] = array(
    'name' => 'publish comments on own user_alert nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'publish comments on own webform nodes'.
  $permissions['publish comments on own webform nodes'] = array(
    'name' => 'publish comments on own webform nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'business preview' => 'business preview',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'publish comments on own working_group nodes'.
  $permissions['publish comments on own working_group nodes'] = array(
    'name' => 'publish comments on own working_group nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'question1: comment on any question1 content'.
  $permissions['question1: comment on any question1 content'] = array(
    'name' => 'question1: comment on any question1 content',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_perm',
  );

  // Exported permission: 'question1: comment without approval on any question1 content'.
  $permissions['question1: comment without approval on any question1 content'] = array(
    'name' => 'question1: comment without approval on any question1 content',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_perm',
  );

  // Exported permission: 'question1: comment without approval on own question1 content'.
  $permissions['question1: comment without approval on own question1 content'] = array(
    'name' => 'question1: comment without approval on own question1 content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_perm',
  );

  // Exported permission: 'question1: edit own comments on question1 content'.
  $permissions['question1: edit own comments on question1 content'] = array(
    'name' => 'question1: edit own comments on question1 content',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_perm',
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

  // Exported permission: 'read all private messages'.
  $permissions['read all private messages'] = array(
    'name' => 'read all private messages',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'business preview' => 'business preview',
      'expert' => 'expert',
      'expert preview' => 'expert preview',
      'webmaster' => 'webmaster',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'read privatemsg'.
  $permissions['read privatemsg'] = array(
    'name' => 'read privatemsg',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'reply only privatemsg'.
  $permissions['reply only privatemsg'] = array(
    'name' => 'reply only privatemsg',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'référent' => 'référent',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'report private messages to mollom'.
  $permissions['report private messages to mollom'] = array(
    'name' => 'report private messages to mollom',
    'roles' => array(),
    'module' => 'privatemsg',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'backup_migrate',
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
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'save_draft',
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

  // Exported permission: 'schedule (un)publishing of nodes'.
  $permissions['schedule (un)publishing of nodes'] = array(
    'name' => 'schedule (un)publishing of nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'référent' => 'référent',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'select text format for privatemsg'.
  $permissions['select text format for privatemsg'] = array(
    'name' => 'select text format for privatemsg',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'expert' => 'expert',
      'référent' => 'référent',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'tag private messages'.
  $permissions['tag private messages'] = array(
    'name' => 'tag private messages',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'privatemsg_filter',
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

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'unflag my_selection'.
  $permissions['unflag my_selection'] = array(
    'name' => 'unflag my_selection',
    'roles' => array(
      'administrator' => 'administrator',
      'expert' => 'expert',
      'expert preview' => 'expert preview',
      'webmaster' => 'webmaster',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag winner_calls3'.
  $permissions['unflag winner_calls3'] = array(
    'name' => 'unflag winner_calls3',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag winner_challenge'.
  $permissions['unflag winner_challenge'] = array(
    'name' => 'unflag winner_challenge',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag winner_question1'.
  $permissions['unflag winner_question1'] = array(
    'name' => 'unflag winner_question1',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'webmaster' => 'webmaster',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unpublish comments on own article nodes'.
  $permissions['unpublish comments on own article nodes'] = array(
    'name' => 'unpublish comments on own article nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'unpublish comments on own blog nodes'.
  $permissions['unpublish comments on own blog nodes'] = array(
    'name' => 'unpublish comments on own blog nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'unpublish comments on own challenge nodes'.
  $permissions['unpublish comments on own challenge nodes'] = array(
    'name' => 'unpublish comments on own challenge nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'business preview' => 'business preview',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'unpublish comments on own circle nodes'.
  $permissions['unpublish comments on own circle nodes'] = array(
    'name' => 'unpublish comments on own circle nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'unpublish comments on own corporate nodes'.
  $permissions['unpublish comments on own corporate nodes'] = array(
    'name' => 'unpublish comments on own corporate nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'unpublish comments on own forum nodes'.
  $permissions['unpublish comments on own forum nodes'] = array(
    'name' => 'unpublish comments on own forum nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'unpublish comments on own page nodes'.
  $permissions['unpublish comments on own page nodes'] = array(
    'name' => 'unpublish comments on own page nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'unpublish comments on own poll nodes'.
  $permissions['unpublish comments on own poll nodes'] = array(
    'name' => 'unpublish comments on own poll nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'unpublish comments on own question1 nodes'.
  $permissions['unpublish comments on own question1 nodes'] = array(
    'name' => 'unpublish comments on own question1 nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'business preview' => 'business preview',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'unpublish comments on own user_alert nodes'.
  $permissions['unpublish comments on own user_alert nodes'] = array(
    'name' => 'unpublish comments on own user_alert nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'unpublish comments on own webform nodes'.
  $permissions['unpublish comments on own webform nodes'] = array(
    'name' => 'unpublish comments on own webform nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'business' => 'business',
      'business preview' => 'business preview',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
  );

  // Exported permission: 'unpublish comments on own working_group nodes'.
  $permissions['unpublish comments on own working_group nodes'] = array(
    'name' => 'unpublish comments on own working_group nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'comment_publish',
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

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'piwik',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'référent' => 'référent',
    ),
    'module' => 'search',
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
      'webmaster' => 'webmaster',
    ),
    'module' => 'bootstrap_optimizer',
  );

  // Exported permission: 'use bulk exporter'.
  $permissions['use bulk exporter'] = array(
    'name' => 'use bulk exporter',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'bulk_export',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use dbtng migrator'.
  $permissions['use dbtng migrator'] = array(
    'name' => 'use dbtng migrator',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'dbtng_migrator',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use text format ds_code'.
  $permissions['use text format ds_code'] = array(
    'name' => 'use text format ds_code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format php_code'.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use tokens in privatemsg'.
  $permissions['use tokens in privatemsg'] = array(
    'name' => 'use tokens in privatemsg',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'view any checklistapi checklist'.
  $permissions['view any checklistapi checklist'] = array(
    'name' => 'view any checklistapi checklist',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'checklistapi',
  );

  // Exported permission: 'view checklistapi checklists report'.
  $permissions['view checklistapi checklists report'] = array(
    'name' => 'view checklistapi checklists report',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'checklistapi',
  );

  // Exported permission: 'view field_picto'.
  $permissions['view field_picto'] = array(
    'name' => 'view field_picto',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
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

  // Exported permission: 'view own field_picto'.
  $permissions['view own field_picto'] = array(
    'name' => 'view own field_picto',
    'roles' => array(
      'administrator' => 'administrator',
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

  // Exported permission: 'view roles recipients'.
  $permissions['view roles recipients'] = array(
    'name' => 'view roles recipients',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'privatemsg_roles',
  );

  // Exported permission: 'view scheduled content'.
  $permissions['view scheduled content'] = array(
    'name' => 'view scheduled content',
    'roles' => array(
      'administrator' => 'administrator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'scheduler',
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

  // Exported permission: 'vote on polls'.
  $permissions['vote on polls'] = array(
    'name' => 'vote on polls',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'référent' => 'référent',
    ),
    'module' => 'poll',
  );

  // Exported permission: 'write privatemsg'.
  $permissions['write privatemsg'] = array(
    'name' => 'write privatemsg',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'référent' => 'référent',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'write privatemsg to all roles'.
  $permissions['write privatemsg to all roles'] = array(
    'name' => 'write privatemsg to all roles',
    'roles' => array(),
    'module' => 'privatemsg_roles',
  );

  // Exported permission: 'write privatemsg to role administrator'.
  $permissions['write privatemsg to role administrator'] = array(
    'name' => 'write privatemsg to role administrator',
    'roles' => array(),
    'module' => 'privatemsg_roles',
  );

  // Exported permission: 'write privatemsg to role authenticated user'.
  $permissions['write privatemsg to role authenticated user'] = array(
    'name' => 'write privatemsg to role authenticated user',
    'roles' => array(),
    'module' => 'privatemsg_roles',
  );

  // Exported permission: 'write privatemsg to role business'.
  $permissions['write privatemsg to role business'] = array(
    'name' => 'write privatemsg to role business',
    'roles' => array(),
    'module' => 'privatemsg_roles',
  );

  // Exported permission: 'write privatemsg to role business preview'.
  $permissions['write privatemsg to role business preview'] = array(
    'name' => 'write privatemsg to role business preview',
    'roles' => array(),
    'module' => 'privatemsg_roles',
  );

  // Exported permission: 'write privatemsg to role expert'.
  $permissions['write privatemsg to role expert'] = array(
    'name' => 'write privatemsg to role expert',
    'roles' => array(),
    'module' => 'privatemsg_roles',
  );

  // Exported permission: 'write privatemsg to role expert preview'.
  $permissions['write privatemsg to role expert preview'] = array(
    'name' => 'write privatemsg to role expert preview',
    'roles' => array(),
    'module' => 'privatemsg_roles',
  );

  // Exported permission: 'write privatemsg to role référent'.
  $permissions['write privatemsg to role référent'] = array(
    'name' => 'write privatemsg to role référent',
    'roles' => array(),
    'module' => 'privatemsg_roles',
  );

  // Exported permission: 'write privatemsg to role webmaster'.
  $permissions['write privatemsg to role webmaster'] = array(
    'name' => 'write privatemsg to role webmaster',
    'roles' => array(),
    'module' => 'privatemsg_roles',
  );

  return $permissions;
}
