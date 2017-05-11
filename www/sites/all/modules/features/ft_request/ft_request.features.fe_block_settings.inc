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

  $export['block-hp_challenge'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_challenge',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
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
        'region' => 'content',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -42,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['emh_request-request_help_challenge'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'request_help_challenge',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'emh_request',
    'node_types' => array(),
    'pages' => 'node/add/challenge',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -41,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -100,
      ),
      'smartmobility' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => -42,
      ),
    ),
    'title' => 'Help_challenges',
    'visibility' => 1,
  );

  $export['emh_request-request_help_question1'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'request_help_question1',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'emh_request',
    'node_types' => array(),
    'pages' => 'node/add/question1',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -41,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -100,
      ),
      'smartmobility' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => -42,
      ),
    ),
    'title' => 'Help_questions',
    'visibility' => 1,
  );

  $export['emh_request-request_help_request'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'request_help_request',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'emh_request',
    'node_types' => array(
      0 => 'request',
    ),
    'pages' => 'node/add/request
node/*/edit',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -41,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -100,
      ),
      'smartmobility' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => -42,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['emh_request-request_help_webform'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'request_help_webform',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'emh_request',
    'node_types' => array(),
    'pages' => 'node/add/webform',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -41,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -100,
      ),
      'smartmobility' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => -42,
      ),
    ),
    'title' => 'Help_missions',
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
        'weight' => -42,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'smartmobility' => array(
        'region' => 'topmenu',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -42,
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
        'weight' => -43,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 1,
      ),
      'smartmobility' => array(
        'region' => 'topmenu',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => -41,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['emh_request_workflow-timeline'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'timeline',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'emh_request_workflow',
    'node_types' => array(
      0 => 'request',
    ),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'title_bottom',
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
        'region' => 'topmenu',
        'status' => 1,
        'theme' => 'smartmobility',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

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
    'pages' => 'node/add/request
node/*/edit',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -36,
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
        'weight' => -37,
      ),
    ),
    'title' => 'Answer(s)',
    'visibility' => 0,
  );

  $export['views-ebd3d59bc59a77db1ff1c0c9be295d26'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'ebd3d59bc59a77db1ff1c0c9be295d26',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
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
        'region' => '',
        'status' => 0,
        'theme' => 'smartmobility',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-query_list-block_last_requests'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'query_list-block_last_requests',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'homepage
node
node/323
fr
fr/homepage
fr/node
fr/node/323',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -37,
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
        'weight' => -40,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
