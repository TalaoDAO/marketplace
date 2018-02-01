<?php

/**
 * @file
 * Contains a BlockPluginInterface
 *
 * @copyright Copyright(c) 2014 Christopher Skene
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 */

namespace Drupal\ghost\Core\Block\Plugin;

use Drupal\ghost\Plugin\GhostPluginInterface;

/**
 * Interface BlockPluginInterface.
 *
 * Defines an interface for block_plugins plugins.
 *
 * @package Drupal\BlockPlugins
 */
interface BlockPluginInterface extends GhostPluginInterface {

  /**
   * Local implementation of hook_block_info().
   *
   * @see hook_block_info()
   *
   * @return array
   *   An array of block information for this block.
   */
  public function blockInfo();

  /**
   * Return the human readable block subject.
   *
   * This is the 'subject' key from hook_block_view().
   *
   * @see hook_block_view()
   *
   * @return string
   *   The subject.
   */
  public function blockSubject();

  /**
   * Return the content for the block.
   *
   * This is the 'content' key from hook_block_view().
   *
   * @see hook_block_view()
   *
   * @return mixed
   *   A view implementation.
   */
  public function blockContent();

  /**
   * Implements hook_preprocess_block().
   */
  public function preprocess(&$vars);
}
