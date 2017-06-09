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
    'pages' => EMH_SMARTMOBILITY_HOMEPAGE,
  );

  $blocks['partners'] = array(
    'info' => t('EMH Smart Mobility - Partners'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
    'weight' => 0,
    'status' => 1,
    'region' => 'content',
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => EMH_SMARTMOBILITY_HOMEPAGE,
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
        'subject' => t('Smart Mobility'),
        'content' => emh_smartmobility_persona_block_content(),
      );
      break;

    case 'partners':
      $block = array(
        'subject' => t('An initiative in partnership with'),
        'content' => emh_smartmobility_partners_block_content(),
      );
      break;
  }

  return $block;
}

/**
 * Callback implemented by hook_block_view().
 */
function emh_smartmobility_persona_block_content() {
  return theme('emh_smartmobility_block_persona', array(
    'title' => t('Smart Mobility'),
    'content' => '',
  )
  );
}

/**
 * Callback implemented by hook_block_view().
 */
function emh_smartmobility_partners_block_content() {
  return theme('emh_smartmobility_block_partners', array(
    'title' => t('An initiative in partnership with'),
    'content' => '',
  )
  );
}
