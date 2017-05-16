<?php
/**
 * @file
 * ft_circle.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ft_circle_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['emh_circles-membership-infos'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'membership-infos',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'emh_circles',
    'node_types' => array(
      0 => 'circle',
    ),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'title_right',
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
        'region' => 'title_right',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -38,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
