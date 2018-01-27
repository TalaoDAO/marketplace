<?php
/**
 * @file
 * ft_front.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ft_front_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-emh_hp_community'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'emh_hp_community',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>
open-requests',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -34,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -34,
      ),
    ),
    'title' => 'Profitez des avantages des communautés privées',
    'visibility' => 1,
  );

  $export['block-emh_hp_domains'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'emh_hp_domains',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'top',
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
        'region' => 'top',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -37,
      ),
    ),
    'title' => 'Domains of expertise',
    'visibility' => 1,
  );

  $export['block-emh_hp_how'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'emh_hp_how',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'top',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -40,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => 'top',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -38,
      ),
    ),
    'title' => 'How it works?',
    'visibility' => 1,
  );

  $export['block-emh_hp_persona'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'emh_hp_persona',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'top',
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
        'region' => 'top',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -39,
      ),
    ),
    'title' => 'The best aviation experts answer your questions',
    'visibility' => 1,
  );

  $export['block-emh_hp_references'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'emh_hp_references',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -32,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -32,
      ),
    ),
    'title' => 'Ils nous ont fait confiance',
    'visibility' => 1,
  );

  $export['block-emh_login_connexion'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'emh_login_connexion',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'footer_bottom',
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
        'region' => 'footer_bottom',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -39,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
