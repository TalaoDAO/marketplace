<?php

/**
 * @file
 * Contains a BlockFactory
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Core\Block;

use Drupal\ghost\Core\Block\Controller\BlockController;
use Drupal\ghost\Core\Variable\VariableController\VariableController;

/**
 * Class BlockFactory
 *
 * @package Drupal\ghost\Core\Block
 */
class BlockFactory {

  /**
   * The BlockController.
   *
   * @var BlockController;
   */
  protected $blockController;

  /**
   * The VariableController.
   *
   * @var VariableController
   */
  protected $variableController;

  /**
   * Lazy constructor.
   *
   * @return static
   *   An instance of BlockFactory
   * @static
   */
  static public function create() {
    $factory = new static();

    $block_controller = BlockController::create();
    $factory->setBlockController($block_controller);

    return $factory;
  }

  /**
   * Create a new block instance.
   *
   * @return \Drupal\ghost\Core\Block\BlockInstanceInterface
   *   An instance of BlockInstanceInterface.
   */
  public function createBlockInstance() {

    return BlockInstance::create();
  }

  /**
   * Create initial block placement for a block which hasn't been used before.
   *
   * @param BlockInstanceInterface $block
   *   A Block, either created by calling BlockInstanceInterface::create(), or
   *   BlockFactory::createBlockInstance().
   *
   * @throws \Exception
   * @return bool
   *   TRUE if the block is inserted, or FALSE on an error.
   */
  public function upsertBlock(BlockInstanceInterface $block) {

    $existing_block = $this->getBlockController()->loadByDelta($block->getDelta(), $block->getModule(), $block->getTheme());

    try {
      if (empty($existing_block)) {
        $this->blockController->insert($block);
      }
      else {
        $block->bid = $existing_block->bid;
        $this->blockController->update($block);
      }
    }
    catch (\Exception $e) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Getter for blockController.
   *
   * @return BlockController
   *   A BlockController.
   */
  public function getBlockController() {

    return $this->blockController;
  }

  /**
   * Setter for blockController.
   *
   * @param BlockController $block_controller
   *   The value for blockController.
   */
  public function setBlockController(BlockController $block_controller) {

    $this->blockController = $block_controller;
  }
}
