<?php

/**
 * @file
 * Contains a GhostPluginInterface
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2014 Christopher Skene
 */

namespace Drupal\ghost\Plugin;


/**
 * Interface GhostPluginInterface
 * @package Drupal\ghost\Plugin
 */
interface GhostPluginInterface {

  /**
   * Get the machine name for the plugin.
   *
   * @return string
   *   The machine name.
   */
  public function getMachineName();
}
