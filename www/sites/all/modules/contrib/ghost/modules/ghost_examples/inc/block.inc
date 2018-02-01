<?php

/**
 * @file
 * Examples for the block controller
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

use Drupal\ghost\Core\Block\BlockFactory;

/**
 * Example of how to insert a block with the block factory.
 */
function ghost_examples_insert_block() {

  $block_factory = BlockFactory::create();

  $block = $block_factory->createBlockInstance();

  $block->setModule('ghost_examples');
  $block->setDelta('foo');
  $block->setTheme('bartik');

  $block_factory->upsertBlock($block);
}
