<?php

/**
 * @file
 * Contains a FormatterPluginInterface
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 */

namespace Drupal\ghost\Core\Formatters\Plugins;

use Drupal\ghost\Plugin\GhostPluginInterface;

/**
 * Interface FormatterPluginInterface
 * @package Drupal\formatters
 */
interface FormatterPluginInterface extends GhostPluginInterface {

  /**
   * Get info for a plugin.
   *
   * @return array
   *   The plugin's info.
   */
  public function info();

  /**
   * Get a settings form.
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
   * @param array $settings
   *   (Optional) An array of settings.
   *
   * @return array
   *   The form elements.
   */
  public function settingsForm($field, $instance, $view_mode, $form, &$form_state, array $settings = array());

  /**
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
   * @param array $settings
   *   The forms settings.
   *
   * @return NULL|string
   *   The summary or NULL
   */
  public function settingsSummary($field, $instance, $view_mode, $settings);

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
  public function view($entity_type, $entity, $field, $instance, $langcode, $items, $display);

  /**
   * Callback for hook_theme().
   */
  public function theme();
}
