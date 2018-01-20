<?php

/**
 * @file
 * Contains a GhostPluginFactory
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 */

namespace Drupal\ghost\Plugin;

use Drupal\ghost\Exception\InvalidPluginException;

/**
 * Class GhostPluginFactory
 * @package Drupal\ghost\Plugin
 */
class GhostPluginFactory implements GhostPluginFactoryInterface {

  /**
   * The plugin type in use.
   *
   * @var string
   */
  protected $pluginType;

  /**
   * Constructor.
   *
   * @param string $plugin_type
   *   The plugin type in use.
   */
  public function __construct($plugin_type) {

    $this->pluginType = $plugin_type;
  }

  /**
   * Lazy factory constructor.
   *
   * @param string $plugin_type
   *   The plugin type in use.
   *
   * @return GhostPluginFactory
   *   This factory.
   */
  static public function factory($plugin_type) {

    return new static($plugin_type);
  }

  /**
   * Load an individual plugin.
   *
   * @param string $name
   *   Name of the plugin.
   *
   * @return bool|GhostPluginInterface
   *   a Ghost Plugin, or FALSE.
   */
  public function loadPlugin($name) {

    $definition = $this->loadPluginDefinition($name);
    if (empty($definition)) {

      return FALSE;
    }

    return $this->createPlugin($definition);
  }

  /**
   * Create a plugin.
   *
   * @param array $definition
   *   The ctools plugin definition.
   *
   * @return GhostPluginInterface|null
   *   A Plugin class.
   */
  public function createPlugin($definition) {

    $plugin = NULL;

    if (isset($definition['class']) && class_exists($definition['class'])) {
      try {
        $plugin = new $definition['class']($definition);

        if (!$plugin instanceof GhostPluginInterface) {
          throw new InvalidPluginException();
        }
      }
      catch (\Exception $e) {
        watchdog_exception('ghost', $e, $e->getMessage());
      }
    }

    return $plugin;
  }

  /**
   * Load all block_plugin plugins.
   *
   * @return GhostPluginInterface[]
   *   An array of plugins
   */
  public function loadAllPlugins() {

    $plugins = array();

    $definitions = $this->loadAllPluginDefinitions();

    if (empty($definitions)) {
      return $plugins;
    }

    foreach ($definitions as $definition) {
      $plugin = $this->createPlugin($definition);

      if (!empty($plugin)) {
        $plugins[$plugin->getMachineName()] = $plugin;
      }
    }

    return $plugins;
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

    ctools_include('plugins');
    return ctools_get_plugins($this->getPluginOwner(), $this->pluginType, $name);
  }

  /**
   * Load all block_plugin plugins.
   *
   * @return array
   *   An array of plugin information
   */
  public function loadAllPluginDefinitions() {

    $plugins = array();

    ctools_include('plugins');
    $raw_plugins = ctools_get_plugins($this->getPluginOwner(), $this->pluginType);
    foreach ($raw_plugins as $class_name => $plugin) {
      $plugin['class_name'] = $class_name;
      $plugins[$plugin['name']] = $plugin;
    }

    return $plugins;
  }

  /**
   * Get the Plugin owner.
   *
   * @return string
   *   Name of the module which owns the plugins.
   */
  public function getPluginOwner() {

    return 'ghost';
  }
}
