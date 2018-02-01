<?php

/**
 * @file
 * Contains a BlockPluginBase.
 *
 * @copyright Copyright(c) 2014 Christopher Skene
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 */

namespace Drupal\ghost\Core\Block\Plugin;

/**
 * Class BlockPluginBase
 *
 * @package Drupal\BlockPlugins
 */
abstract class BlockPluginBase
  implements BlockPluginInterface {

  /**
   * Plugin settings.
   */
  public $settings;

  /**
   * Constructor.
   *
   * @param array $settings
   *   The plugin settings.
   *
   * @return BlockPluginBase
   *   This block plugin, for chaining.
   */
  public function __construct($settings) {

    $this->settings = $settings;

    return $this;
  }

  /**
   * Return a unique machine name for this block.
   *
   * @return string
   *   The machine name.
   */
  public function getMachineName() {

    return $this->settings['name'];
  }

  /**
   * Local implementation of hook_block_info().
   *
   * @see hook_block_info()
   *
   * @return array
   *   An array of block information for this block.
   */
  abstract public function blockInfo();

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
  abstract public function blockSubject();

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
  abstract public function blockContent();

  /**
   * Implements hook_preprocess_block().
   */
  public function preprocess(&$vars) {
    // Nothing to do.
  }
}
