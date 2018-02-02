<?php

/**
 * @file
 * Contains a FormPluginFactory
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Core\Form\Plugins;

use Drupal\ghost\Plugin\GhostPluginFactory;

/**
 * Class FormPluginFactory
 *
 * @package Drupal\ghost\Core\Form\Plugins
 */
class FormPluginFactory extends GhostPluginFactory {

  /**
   * Lazy factory constructor.
   *
   * @return GhostPluginFactory
   *   This factory.
   */
  static public function init() {

    return new static(GHOST_PLUGIN_TYPE_FORM);
  }

  /**
   * Load a ghost plugin.
   *
   * @param string $name
   *   Name of the plugin
   *
   * @return array
   *   An array of plugin information
   */
  public function loadPluginDefinition($name) {

    $plugins = $this->loadAllPluginDefinitions();
    if (array_key_exists($name, $plugins)) {
      return $plugins[$name];
    }

    return NULL;
  }
}
