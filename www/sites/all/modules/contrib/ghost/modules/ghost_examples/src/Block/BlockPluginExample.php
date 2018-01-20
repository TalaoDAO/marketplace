<?php

/**
 * @file
 * Contains a BlockPluginExample
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2014 Christopher Skene
 */

namespace Drupal\ghost_examples\Block;

use Drupal\ghost\Core\Block\Plugin\BlockPluginInterface;
use Drupal\ghost\Core\Block\Plugin\BlockPluginBase;

$plugin = array(
  'title' => t('Example block'),
  'description' => t('Block plugin example block'),
  'class' => 'Drupal\ghost_examples\Block\BlockPluginExample',
  // Remove this line in your own plugins...
  'hidden' => TRUE,
);

/**
 * Class BlockPluginExample
 *
 * @package Drupal\ghost\Block\Plugin
 */
class BlockPluginExample
  extends BlockPluginBase
  implements BlockPluginInterface {

  /**
   * Local implementation of hook_block_info().
   *
   * @see hook_block_info()
   *
   * @return array
   *   An array of block information for this block.
   */
  public function blockInfo() {
    return array(
      'info' => t('Example block'),
      'cache' => DRUPAL_NO_CACHE,
    );
  }

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
  public function blockSubject() {
    return t('Example block');
  }

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
  public function blockContent() {
    return 'Some content';
  }

}
