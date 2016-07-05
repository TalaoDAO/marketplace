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

  $export['emh_request_flag_save-flag_save'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'flag_save',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'emh_request_flag_save',
    'node_types' => array(
      0 => 'request',
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
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['emh_request_submission-submission_count'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'submission_count',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'emh_request_submission',
    'node_types' => array(
      0 => 'request',
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
        'weight' => 1,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 1,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['emh_request_timeline-timeline'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'timeline',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'emh_request_timeline',
    'node_types' => array(
      0 => 'request',
    ),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'title',
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
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
