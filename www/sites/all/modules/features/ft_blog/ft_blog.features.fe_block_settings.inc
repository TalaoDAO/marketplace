<?php
/**
 * @file
 * ft_blog.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ft_blog_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-58462e19e23ccfccdcc6b91a103ef1cd'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '58462e19e23ccfccdcc6b91a103ef1cd',
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
        'region' => 'header',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -49,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-news_thread-publications_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'news_thread-publications_block',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'bottom',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -49,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
