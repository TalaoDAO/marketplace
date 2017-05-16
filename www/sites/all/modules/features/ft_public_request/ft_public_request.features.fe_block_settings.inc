<?php
/**
 * @file
 * ft_public_request.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ft_public_request_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-6ab7fcd12a377687c35b7d6396f1daee'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '6ab7fcd12a377687c35b7d6396f1daee',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
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
        'weight' => -40,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-e55ab575e8f94eb37181542a5c863be7'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'e55ab575e8f94eb37181542a5c863be7',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
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
        'weight' => -38,
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
        'weight' => -36,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
