<?php
/**
 * @file
 * ft_faq.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ft_faq_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-faq-faq_client_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'faq-faq_client_block',
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

  $export['views-faq-faq_expert_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'faq-faq_expert_block',
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

  return $export;
}
