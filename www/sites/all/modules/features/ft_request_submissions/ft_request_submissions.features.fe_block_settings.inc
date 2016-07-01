<?php
/**
 * @file
 * ft_request_submissions.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ft_request_submissions_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-1af75971ad2e240a760d76804eef15fe'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '1af75971ad2e240a760d76804eef15fe',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(
      0 => 'request',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
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
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
