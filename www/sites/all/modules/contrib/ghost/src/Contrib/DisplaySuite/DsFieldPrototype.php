<?php
/**
 * @file
 * The main Display Suite Field Prototypes class.
 *
 * @copyright Copyright(c) 2012 Christopher Skene
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 */

namespace Drupal\ghost\Contrib\DisplaySuite;

use Drupal\ghost\Utilities\RandomNameGenerator;

/**
 * Helper class for building Display Suite fields.
 */
class DsFieldPrototype {

  /**
   * The name of the field.
   *
   * @var string
   */
  public $name;

  /**
   * The field type
   */
  public $type;

  /**
   * The module which is declaring the field.
   *
   * @var string
   */
  public $module;

  /**
   * Settings for the field.
   *
   * @var array
   */
  protected $configuration = array();

  /**
   * Properties.
   *
   * @var array
   */
  protected $properties = array();

  /**
   * Field constructor.
   *
   * @param string $module
   *   The module creating the field.
   * @param string $machine_name
   *   The machine name of the field.
   * @param string $name
   *   The field name.
   * @param int $type
   *   (optional) The type of field. Defaults to DS_FIELD_TYPE_FUNCTION.
   *
   * @return DsFieldPrototype
   *   A field prototype.
   */
  static public function create($module, $machine_name, $name, $type = DS_FIELD_TYPE_FUNCTION) {

    $field = new static($module, $machine_name, $type);
    $field->setTitle($name);

    return $field;
  }

  /**
   * DsFieldPrototype constructor.
   *
   * @param string $module
   *   The module creating the field.
   * @param string $machine_name
   *   The machine name of the field.
   * @param int $type
   *   (optional) The type of field. Defaults to DS_FIELD_TYPE_FUNCTION.
   */
  public function __construct($module, $machine_name, $type = DS_FIELD_TYPE_FUNCTION) {
    $this->name = $machine_name;
    $this->module = $module;

    $this->setTitle($this->randName());
    $this->setFieldType($type);
    // Add the default formatter.
    $this->addFormatter('default', 'Default');

    $this->setProperty('settings', array());
    $this->setProperty('default', array());
  }

  /**
   * Return the information for the field.
   *
   * @return array
   *   An array of field information
   */
  public function getFieldDefinition() {
    $field_settings = $this->configuration;
    $field_settings['properties'] = $this->properties;
    $field_settings['field_type'] = $this->type;
    return $field_settings;
  }

  /**
   * Set the field type.
   *
   * Can be one of:
   * - DS_FIELD_TYPE_FUNCTION   : calls a custom function.
   *
   * Untested:
   * - DS_FIELD_TYPE_THEME      : calls a theme function.
   * - DS_FIELD_TYPE_CODE       : calls ds_render_code_field().
   * - DS_FIELD_TYPE_BLOCK      : calls ds_render_block_field().
   * - DS_FIELD_TYPE_PREPROCESS : calls nothing, just takes a key from the
   *                              variable field that is passed on.
   * - DS_FIELD_TYPE_IGNORE     : calls nothing, use this if you simple want to
   *                              drag and drop. The field itself will have a
   *                              theme function.
   *
   * @param string $type
   *   The field type to set.
   *
   * @return DsFieldPrototype
   *   The field prototype for chaining.
   */
  public function setFieldType($type) {
    $this->type = $type;

    $this->resetConfig();

    switch ($this->type) {
      case DS_FIELD_TYPE_FUNCTION:
        $default_function = $this->module . '_' . $this->name . '_field';
        $this->setFunction($default_function);
        break;

      case DS_FIELD_TYPE_THEME:
        break;

      case DS_FIELD_TYPE_CODE:
        $this->setProperty('code', '');
        $this->setProperty('use_token', TRUE);
        break;

      case DS_FIELD_TYPE_BLOCK:
        // Set the module and delta of the block, only for block fields.
        $this->setProperty('block', '');
        // Block render type, only for block fields.
        // - DS_BLOCK_CONTENT       : render through block template file.
        // - DS_BLOCK_TITLE_CONTENT : render only title and content.
        // - DS_BLOCK_CONTENT       : render only content.
        $this->setProperty('block_render', DS_BLOCK_CONTENT);
        break;

      case DS_FIELD_TYPE_PREPROCESS:
        break;

      case DS_FIELD_TYPE_IGNORE:
        break;
    }

    return $this;
  }

  /**
   * Set the function to use as a callback.
   *
   * @param string $function_name
   *   Name of the function to set.
   * @param string|null $file
   *   (optional) An optional file to load. This can also be set separately
   *   using setFile().
   *
   * @return DsFieldPrototype
   *   The field prototype for chaining.
   */
  public function setFunction($function_name, $file = NULL) {
    if ($this->type == DS_FIELD_TYPE_FUNCTION) {
      $this->configuration['function'] = $function_name;
      if (isset($file) && !empty($file)) {
        $this->setFile($file);
      }
    }
    else {
      watchdog('ds_fp', 'Field %name does not support using functions as a callback', array('%name' => $this->name), WATCHDOG_WARNING);
    }

    return $this;
  }

  /**
   * Set a file to call when using a function.
   *
   * @param string $file_name
   *   The name of the file.
   *
   * @return DsFieldPrototype
   *   The field prototype for chaining.
   */
  public function setFile($file_name) {
    if ($this->type == DS_FIELD_TYPE_FUNCTION) {
      $this->configuration['file'] = $file_name;
    }
    else {
      watchdog('ds_fp', 'Field %name does not support the "file" key', array('%name' => $this->name), WATCHDOG_WARNING);
    }

    return $this;
  }

  /**
   * Add a new formatter.
   *
   * Optional if a function is used. In case the field_type is
   * DS_FIELD_TYPE_THEME, you also need to register these formatters as a theme
   * function since the key will be called with theme('function'). The title is
   * used in the selection config on Field UI.
   *
   * @param string $name
   *   Machine name for the formatter.
   * @param string $title
   *   Human-readable name for the formatter. Includes translation substitution.
   *
   * @return DsFieldPrototype
   *   The field prototype for chaining.
   */
  public function addFormatter($name, $title) {
    $formatters = $this->getProperty('formatters');
    $formatters[$name] = $title;

    $this->setProperty('formatters', $formatters);

    return $this;
  }

  /**
   * Remove formatters.
   *
   * This is useful to remove the default formatter.
   *
   * @param string $name
   *   Machine name for the formatter.
   *
   * @return DsFieldPrototype
   *   The field prototype for chaining.
   */
  public function removeFormatter($name) {
    $formatters = $this->getProperty('formatters');
    if (!empty($formatters) && isset($formatters[$name])) {
      unset($formatters[$name]);
    }

    return $this;
  }

  /**
   * Limit fields to show based on bundles or view modes.
   *
   * The values are always in the form of $bundle|$view_mode. You may use * to
   * select all. Make sure you use the machine name.
   *
   * e.g.
   *  $field->uiLimit(array('article|*', 'news|teaser'));
   *
   * @param array $settings
   *   Settings for the UI limit.
   *
   * @return DsFieldPrototype
   *   The field prototype for chaining.
   */
  public function setUiLimit(array $settings) {
    $this->setConfig('ui_limit', $settings);

    return $this;
  }

  /**
   * Set the title.
   *
   * This function also performs translation substitution, so you don't have to
   * call t().
   *
   * @param string $title
   *   The title to set.
   *
   * @return DsFieldPrototype
   *   The field prototype for chaining.
   */
  public function setTitle($title) {
    $title_setting = t("@title", array('@title' => $title));
    $this->setConfig('title', $title_setting);
    return $this;
  }

  /**
   * Clean up settings used by different field types.
   *
   * Called internally to ensure no unnecessary keys are present when changing a
   * field type.
   */
  protected function resetConfig() {
    $clean = array(
      DS_FIELD_TYPE_FUNCTION => array('function', 'file'),
    );

    foreach ($clean as $field_type) {
      foreach ($field_type as $key) {
        if (isset($this->configuration[$key])) {
          unset($key);
        }
      }
    }
  }

  /**
   * Generate a random name.
   *
   * @return string
   *   The random string.
   */
  protected function randName() {
    return RandomNameGenerator::randomName();
  }

  /**
   * Set a Setting.
   *
   * @param string $key
   *   A key.
   * @param mixed $setting
   *   The setting.
   */
  public function setConfig($key, $setting) {

    $this->configuration[$key] = $setting;
  }

  /**
   * Get a setting.
   *
   * @param string $key
   *   The key to look for.
   *
   * @return mixed
   *   Value of the setting.
   */
  public function getConfig($key) {
    if (isset($this->configuration[$key])) {
      return $this->configuration[$key];
    }

    return FALSE;
  }

  /**
   * Set a Setting.
   *
   * @param string $key
   *   A key.
   * @param mixed $property
   *   The property.
   */
  public function setProperty($key, $property) {

    $this->properties[$key] = $property;
  }

  /**
   * Get a property.
   *
   * @param string $key
   *   Key to retrieve.
   * @param mixed|null $default
   *   A default value.
   *
   * @return mixed
   *   Value of the property.
   */
  public function getProperty($key, $default = NULL) {
    if (isset($this->properties[$key])) {
      return $this->properties[$key];
    }

    return FALSE;
  }
}
