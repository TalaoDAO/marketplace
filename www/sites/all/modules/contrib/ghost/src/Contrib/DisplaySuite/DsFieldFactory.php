<?php

/**
 * @file
 * Contains a DsFieldFactory
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Contrib\DisplaySuite;

/**
 * Class DsFieldFactory
 * @package Drupal\ghost\DisplaySuite
 */
class DsFieldFactory {

  /**
   * Name of the module calling this factory.
   *
   * @var string
   */
  protected $moduleName;

  /**
   * The field prototypes.
   *
   * @var DsFieldPrototype[]
   */
  protected $fields;

  /**
   * Lazy constructor.
   *
   * @param string $module_name
   *   Name of the module to make fields for.
   *
   * @return static
   *   Returns an instance of DsFieldFactory
   * @static
   */
  public static function create($module_name) {

    $factory = new static();
    $factory->setModuleName($module_name);

    return $factory;
  }

  /**
   * The name of the module for which the fields are created.
   *
   * @param string $module_name
   *   The module name.
   */
  public function setModuleName($module_name) {
    $this->moduleName = $module_name;
  }

  /**
   * Make a field.
   *
   * @param string $machine_name
   *   The machine name.
   * @param string $name
   *   The human readable name
   * @param int $type
   *   The Display Suite type.
   *
   * @return DsFieldPrototype
   *   A Display Suite Field Prototype
   */
  public function addField($machine_name, $name, $type = DS_FIELD_TYPE_FUNCTION) {

    $this->fields[$machine_name] = DsFieldPrototype::create($this->moduleName, $machine_name, $name, $type);

    return $this->getField($machine_name);
  }

  /**
   * Get a field.
   *
   * @param string $machine_name
   *   Name of the fields.
   *
   * @return DsFieldPrototype|null
   *   A field prototype.
   */
  public function getField($machine_name) {

    if (isset($this->fields[$machine_name])) {
      return $this->fields[$machine_name];
    }

    return NULL;
  }

  /**
   * Return field definitions.
   *
   * @return array
   *   An array of field definitions
   */
  public function getFields() {
    $fields = array();
    if (!empty($this->fields)) {
      foreach ($this->fields as $field_key => $field) {
        $fields[$field_key] = $field->getFieldDefinition();
      }
    }
    return $fields;
  }
}
