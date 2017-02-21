<?php

/**
 * @file
 * Code for EMH Smart Mobility block feature.
 */

/**
 * Implements hook_block_info().
 */
function emh_smartmobility_block_info() {
  $blocks = array();

  $blocks['persona'] = array(
    'info' => t('EMH Smart Mobility - Persona'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
    'weight' => 0,
    'status' => 1,
    'region' => 'top',
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => 'smart-mobility',
  );

  $blocks['partners'] = array(
    'info' => t('EMH Smart Mobility - Partners'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
    'weight' => 0,
    'status' => 1,
    'region' => 'content',
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => 'smart-mobility',
  );

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function emh_smartmobility_block_view($delta = '') {
  $block = array();

  switch ($delta) {
    case 'persona':
      $block = array(
        'subject' => 'Smart Mobility',
        'content' => 'content',
      );
      break;

    case 'partners':
      $block = array(
        'subject' => 'Une initiative réalisée en partenariat entre',
        'content' => 'content',
      );
      break;
  }

  return $block;
}