<?php
/**
 * @file
 * ft_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ft_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-hp_welcome'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_welcome',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'title',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -39,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => 'title',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -39,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['bootstrap_languages-language'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'language',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'bootstrap_languages',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -43,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -40,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['devel-switch_user'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'switch_user',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'devel',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'administrator' => 3,
      'webmaster' => 6,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'burgermenu',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => 'burgermenu',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-footer-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'footer_top',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -39,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => 'footer_top',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -39,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-top'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-top',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -42,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -39,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-top-anonymous'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-top-anonymous',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -41,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => -38,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['og_extras-node_links'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'node_links',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'og_extras',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -39,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => -39,
      ),
    ),
    'title' => 'Participate to the Challenge',
    'visibility' => 0,
  );

  $export['progress_tracker-progress_tracker'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'progress_tracker',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'progress_tracker',
    'node_types' => array(
      0 => 'challenge',
      1 => 'question1',
      2 => 'webform',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -39,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => -39,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['roleswitcher-switcher'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'switcher',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'roleswitcher',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'roleswitcher' => 10,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -37,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -45,
      ),
      'smartmobility' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => -35,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-help'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'help',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -39,
      ),
      'seven' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -39,
      ),
      'smartmobility' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -39,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -39,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -40,
      ),
      'smartmobility' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -38,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -23,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => -23,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -39,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -36,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -40,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -39,
      ),
      'smartmobility' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -37,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-entreprise_list-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'entreprise_list-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -13,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => -13,
      ),
    ),
    'title' => 'Scope of services in aerospace',
    'visibility' => 1,
  );

  $export['views-og_members-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'og_members-block_1',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -39,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => -39,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-sponsors-partners_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'sponsors-partners_block',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/267',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -39,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => -39,
      ),
    ),
    'title' => 'Partners',
    'visibility' => 1,
  );

  $export['views-sponsors-sponsors_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'sponsors-sponsors_block',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/267',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -39,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => -39,
      ),
    ),
    'title' => 'Sponsors',
    'visibility' => 1,
  );

  $export['views-users_list-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'users_list-block_2',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => 1,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => 1,
      ),
    ),
    'title' => 'They are experts in eMindHub',
    'visibility' => 1,
  );

  return $export;
}
