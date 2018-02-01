<?php

/**
 * @file
 * Contains a FieldViewer
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Core\Field;


/**
 * Class FieldViewer
 * @package Drupal\ghost\Field
 */
class FieldViewer {

  /**
   * The entity type.
   *
   * @var string
   */
  protected $entityType;

  /**
   * The entity.
   *
   * @var object
   */
  protected $entity;

  /**
   * Display settings.
   *
   * @var array
   */
  protected $display = array();

  /**
   * A view mode to use.
   *
   * @var string
   */
  protected $viewMode;

  /**
   * Constructor.
   *
   * @param string $entity_type
   *   The type of $entity; e.g., 'node' or 'user'.
   * @param object $entity
   *   The entity containing the field to display. Must at least contain the id
   *   key and the field data to display.
   */
  public function __construct($entity_type, $entity) {

    $this->entityType = $entity_type;
    $this->entity = $entity;
  }

  /**
   * View a field value.
   *
   * @param string $entity_type
   *   The type of $entity; e.g., 'node' or 'user'.
   * @param object $entity
   *   The entity containing the field to display. Must at least contain the id
   *   key and the field data to display.
   *
   * @return static
   *   An instance of FieldViewer
   *
   * @static
   */
  static public function view($entity_type, $entity) {

    return new static($entity_type, $entity);
  }

  /**
   * Returns a renderable array for the value of a single field in an entity.
   *
   * The resulting output is a fully themed field with label and multiple
   * values.
   *
   * This function can be used by third-party modules that need to output an
   * isolated field.
   * - Do not use inside node (or any other entity) templates; use
   *   render($content[FIELD_NAME]) instead.
   * - Do not use to display all fields in an entity; use
   *   field_attach_prepare_view() and field_attach_view() instead.
   * - The field_view_value() function can be used to output a single formatted
   *   field value, without label or wrapping field markup.
   *
   * The function takes care of invoking the prepare_view steps. It also
   * respects field access permissions.
   *
   * @param string $field_name
   *   The name of the field to display.
   * @param string $langcode
   *   (Optional) The language the field values are to be shown in. The site's
   *   current language fallback logic will be applied no values are available
   *   for the language. If no language is provided the current language will be
   *   used.
   *
   * @return array
   *   A renderable array for the field value.
   *
   * @see field_view_value()
   */
  public function getRenderArray($field_name, $langcode = NULL) {

    if (empty($this->viewMode)) {
      $display = $this->display;
      // When using custom display settings, fill in default values.
      $display = $this->rehashFieldDefaults($field_name, $display);
    }
    else {
      $display = $this->viewMode;
    }

    return field_view_field($this->entityType, $this->entity, $field_name, $display, $langcode);
  }

  /**
   * Get the value of the field.
   *
   * @param string $field_name
   *   Name of the field to get a value for.
   *
   * @return mixed
   *   Result of the field.
   * @throws \EntityMetadataWrapperException
   */
  public function getValue($field_name) {

    if (function_exists('entity_metadata_wrapper')) {
      $wrapper = entity_metadata_wrapper($this->entityType, $this->entity);
      return $wrapper->{$field_name}->value();
    }

    return field_get_items($this->entityType, $this->entity, $field_name);
  }

  /**
   * Set the display to use default settings.
   */
  public function useDisplayDefaults() {
    $this->display = array(
      'label' => 'hidden',
      'type' => 'default_formatter',
    );
    $this->viewMode = NULL;
  }

  /**
   * Getter for display.
   *
   * @return array
   *   The display settings.
   */
  public function getDisplay() {

    return $this->display;
  }

  /**
   * Setter for display.
   *
   * @param array $display
   *   An array of display settings, as found in the 'display' entry of
   *   $instance definitions. The following key/value pairs are allowed:
   *   - label: (string) Position of the label. The default 'field' theme
   *     implementation supports the values 'inline', 'above' and 'hidden'.
   *     Defaults to 'above'.
   *   - type: (string) The formatter to use. Defaults to the
   *     'default_formatter' for the field type, specified in
   *     hook_field_info(). The default formatter will also be used if the
   *     requested formatter is not available.
   *   - settings: (array) Settings specific to the formatter. Defaults to the
   *     formatter's default settings, specified in
   *     hook_field_formatter_info().
   *   - weight: (float) The weight to assign to the renderable element.
   *     Defaults to 0.
   */
  public function setDisplay($display) {

    $this->display = $display;
  }

  /**
   * Set the display to use a view mode.
   *
   * @param string $view_mode
   *   A view mode name.
   */
  public function useViewMode($view_mode) {
    $this->display = array();
    $this->viewMode = $view_mode;
  }

  /**
   * Getter for entityType.
   *
   * @return string
   *   The entity type.
   */
  public function getEntityType() {

    return $this->entityType;
  }

  /**
   * Setter for entityType.
   *
   * @param string $entity_type
   *   The value for entity type.
   */
  public function setEntityType($entity_type) {

    $this->entityType = $entity_type;
  }

  /**
   * Getter for entity.
   *
   * @return object
   *   The entity.
   */
  public function getEntity() {

    return $this->entity;
  }

  /**
   * Setter for entity.
   *
   * @param object $entity
   *   The value for entity.
   */
  public function setEntity($entity) {

    $this->entity = $entity;
  }

  /**
   * Rehash field settings.
   *
   * @param string $field_name
   *   Field to rehash for.
   * @param array $display
   *   Existing display settings.
   *
   * @return array
   *   An array of settings.
   */
  protected function rehashFieldDefaults($field_name, $display) {

    $field = field_info_field($field_name);
    $cache = _field_info_field_cache();
    $display = $cache->prepareInstanceDisplay($display, $field["type"]);

    return $display;
  }
}
