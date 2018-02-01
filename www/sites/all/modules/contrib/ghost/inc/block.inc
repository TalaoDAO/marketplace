<?php

/**
 * @file
 * Block functionality for Ghost
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2014 Christopher Skene
 */

use Drupal\ghost\Core\Block\BlockPluginFactory;
use Drupal\ghost\Core\Block\Plugin\BlockPluginInterface;

/**
 * Implements hook_block_info().
 */
function ghost_block_info() {

  $blocks = array();

  $block_plugins = BlockPluginFactory::init()->loadAllPlugins();

  if (!empty($block_plugins)) {
    foreach ($block_plugins as $block_plugin) {
      /* @var BlockPluginInterface $block_plugin */
      $blocks[$block_plugin->getMachineName()] = $block_plugin->blockInfo();
    }
  }

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function ghost_block_view($delta = '') {

  // This example is adapted from node.module.
  $block = array();

  $block_plugin = BlockPluginFactory::init()->loadPlugin($delta);
  if (empty($block_plugin)) {
    return array();
  }

  /* @var BlockPluginInterface $block_plugin */

  $block['subject'] = $block_plugin->blockSubject();
  $block['content'] = $block_plugin->blockContent();

  return $block;
}

/**
 * Implements hook_preprocess_block().
 */
function ghost_preprocess_block(&$vars) {

  if ($vars['block']->module == 'ghost') {
    $block_plugin = BlockPluginFactory::init()
      ->loadPlugin($vars['block']->delta);
    if (empty($block_plugin)) {
      return;
    }

    /* @var BlockPluginInterface $block_plugin */

    $block_plugin->preprocess($vars);
  }
}
