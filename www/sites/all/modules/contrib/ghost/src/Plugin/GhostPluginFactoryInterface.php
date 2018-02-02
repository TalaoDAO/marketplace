<?php

/**
 * @file
 * Contains a GhostPluginFactoryInterface
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 */

namespace Drupal\ghost\Plugin;

use Drupal\ghost\Exception\InvalidPluginException;

/**
 * Interface GhostPluginFactoryInterface
 * @package Drupal\ghost\Plugin
 */
interface GhostPluginFactoryInterface {

  /**
   * Lazy factory constructor.
   *
   * @param string $plugin_type
   *   The plugin type in use.
   *
   * @return GhostPluginFactory
   *   This factory.
   */
  public static function factory($plugin_type);

  /**
   * Load an individual plugin.
   *
   * @param string $name
   *   Name of the plugin.
   *
   * @return bool|GhostPluginInterface
   *   a Ghost Plugin, or FALSE.
   */
  public function loadPlugin($name);

  /**
   * Create a plugin.
   *
   * @param array $definition
   *   The ctools plugin definition.
   *
   * @return GhostPluginInterface|null
   *   A Plugin class.
   */
  public function createPlugin($definition);

  /**
   * Load all block_plugin plugins.
   *
   * @return GhostPluginInterface[]
   *   An array of plugins
   */
  public function loadAllPlugins();

  /**
   * Load a ghost plugin.
   *
   * @param string $name
   *   Name of the plugin
   *
   * @return array
   *   An array of plugin information
   */
  public function loadPluginDefinition($name);

  /**
   * Load all block_plugin plugins.
   *
   * @return array
   *   An array of plugin information
   */
  public function loadAllPluginDefinitions();

  /**
   * Get the Plugin owner.
   *
   * @return string
   *   Name of the module which owns the plugins.
   */
  public function getPluginOwner();
}
