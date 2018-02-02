<?php

/**
 * @file
 * Contains a FormatterManager
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 */

namespace Drupal\ghost\Core\Formatters;

use Drupal\ghost\Core\Formatters\Plugins\FormatterPluginInterface;
use Drupal\ghost\Core\Formatters\FormatterPluginFactory;

/**
 * Class FormatterManager
 * @package Drupal\formatters
 */
class FormatterManager {

  /**
   * All formatter plugins.
   *
   * @var array
   */
  protected $plugins;

  /**
   * The FormatterPluginFactory
   *
   * @var FormatterPluginFactory
   */
  protected $pluginManager;

  /**
   * Static constructor.
   *
   * @return static
   *   This.
   * @static
   */
  static public function init() {

    $plugin_manager = FormatterPluginFactory::init();

    return new static($plugin_manager);
  }

  /**
   * Constructor.
   *
   * @param FormatterPluginFactory $plugin_manager
   *   A plugin manager
   */
  public function __construct(FormatterPluginFactory $plugin_manager) {

    $this->pluginManager = $plugin_manager;

    $this->plugins = $this->pluginManager->loadAllPluginDefinitions();
  }

  /**
   * Callback for hook_field_formatter_info().
   *
   * @return array
   *   An array of formatter info.
   */
  public function fieldFormatterInfo() {
    $info = array();

    if (!empty($this->plugins)) {
      foreach ($this->plugins as $plugin) {

        $formatter = $this->loadFormatter($plugin);
        if (empty($formatter)) {
          continue;
          // @todo: should be a warning
        }

        $info[$formatter->getMachineName()] = $formatter->info();
      }
    }

    return $info;
  }

  /**
   * Callback for hook_field_formatter_settings_form().
   *
   * @param mixed $field
   *   The field structure being configured.
   * @param array $instance
   *   The instance structure being configured.
   * @param string $view_mode
   *   The view mode being configured.
   * @param array $form
   *   The (entire) configuration form array, which will usually have no use
   *   here.
   * @param array $form_state
   *   The form state of the (entire) configuration form.
   *
   * @return array|bool
   *   The settings form, or FALSE.
   */
  public function fieldFormatterSettingsForm($field, $instance, $view_mode, $form, &$form_state) {
    // This gets the view_mode where our settings are stored.
    $display = $instance['display'][$view_mode];
    // This gets the actual settings.
    $settings = $display['settings'];

    if (isset($this->plugins[$display['type']])) {
      $formatter = $this->loadFormatter($this->plugins[$display['type']]);
      if (!empty($formatter) && $formatter instanceof FormatterPluginInterface) {

        return $formatter->settingsForm($field, $instance, $view_mode, $form, $form_state, $settings);
      }
    }

    return FALSE;
  }

  /**
   * Callback for hook_field_formatter_settings_summary().
   *
   * Return a short summary for the current formatter settings of an instance.
   *
   * If an empty result is returned, the formatter is assumed to have no
   * configurable settings, and no UI will be provided to display a
   * settings form.
   *
   * @param mixed $field
   *   The field structure.
   * @param array $instance
   *   The instance structure.
   * @param string $view_mode
   *   The view mode for which a settings summary is requested.
   *
   * @return NULL|string
   *   The summary or NULL
   */
  public function fieldFormatterSettingsSummary($field, $instance, $view_mode) {

    // This gets the view_mode where our settings are stored.
    $display = $instance['display'][$view_mode];
    // This gets the actual settings.
    $settings = $display['settings'];

    if (isset($this->plugins[$display['type']])) {
      $formatter = $this->loadFormatter($this->plugins[$display['type']]);
      if (!empty($formatter) && $formatter instanceof FormatterPluginInterface) {

        return $formatter->settingsSummary($field, $instance, $view_mode, $settings);
      }
    }

    return FALSE;
  }

  /**
   * Callback for hook_field_formatter_view().
   *
   * Builds a renderable array for a field value.
   *
   * @param string $entity_type
   *   The type of entity.
   * @param object $entity
   *   The entity being displayed.
   * @param array $field
   *   The field structure.
   * @param array $instance
   *   The field instance.
   * @param string $langcode
   *   The language associated with items.
   * @param array $items
   *   Array of values for this field.
   * @param array $display
   *   The display settings to use, as found in the 'display' entry of
   *   instance definitions. The array notably contains the following keys and
   *   values:
   *   - type: The name of the formatter to use
   *   - settings: The array of formatter settings.
   *
   * @return array
   *   A renderable array for the $items, as an array of child elements
   *   keyed by numeric indexes starting from 0.
   */
  public function fieldFormatterView($entity_type, $entity, $field, $instance, $langcode, $items, $display) {

    if (isset($this->plugins[$display['type']])) {
      $formatter = $this->loadFormatter($this->plugins[$display['type']]);
      if (!empty($formatter) && $formatter instanceof FormatterPluginInterface) {

        return $formatter->view($entity_type, $entity, $field, $instance, $langcode, $items, $display);
      }
    }

    return NULL;
  }

  /**
   * Callback for hook_field_theme().
   *
   * @return array
   *   An array of formatter theme info.
   */
  public function theme() {
    $info = array();

    if (!empty($this->plugins)) {
      foreach ($this->plugins as $plugin) {

        $formatter = $this->loadFormatter($plugin);
        if (empty($formatter)) {
          continue;
          // @todo: should be a warning
        }

        $theme_info = $formatter->theme();

        if (!empty($theme_info)) {

        }
        $info += $theme_info;
      }
    }

    return $info;
  }

  /**
   * Load a Formatter class.
   *
   * @param array $plugin
   *   An array of plugin settings.
   *
   * @return \Drupal\ghost\Core\Formatters\Plugins\FormatterPluginInterface
   *   A Formatter
   */
  public function loadFormatter($plugin) {

    if (class_exists($plugin['class']) && is_callable(array($plugin['class'], 'init'))) {
      return new $plugin['class']();
    }

    return FALSE;
  }
}
