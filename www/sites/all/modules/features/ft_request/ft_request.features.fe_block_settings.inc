<?php
/**
 * @file
 * ft_request.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ft_request_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['emh_request-request_help_request'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'request_help_request',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'emh_request',
    'node_types' => array(),
    'pages' => 'node/add/request',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -100,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -100,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
