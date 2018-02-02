<?php

/**
 * @file
 * Contains a BlockPluginFactory.
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 */

namespace Drupal\ghost\Core\Block;

use Drupal\ghost\Plugin\GhostPluginFactory;

/**
 * Class BlockPluginFactory
 *
 * @package Drupal\ghost\Block
 */
class BlockPluginFactory extends GhostPluginFactory {

  /**
   * Lazy factory constructor.
   *
   * @return GhostPluginFactory
   *   This factory.
   */
  static public function init() {

    return new static(GHOST_PLUGIN_TYPE_BLOCK);
  }
}
