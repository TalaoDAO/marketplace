<?php

/**
 * @file
 * Contains a VariableController
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Core\Variable\VariableController;

use Drupal\ghost\Controller\ControllerInterface;
use Drupal\ghost\Type\Storable\StorableInterface;

/**
 * Class VariableController
 *
 * @package Drupal\ghost\Core\Variable\VariableController
 */
class VariableController implements ControllerInterface {

  /**
   * Create a new instance.
   *
   * @return static
   *   A new instance of ControllerInterface.
   * @static
   */
  public static function create() {

    return new static();
  }

  /**
   * Insert an item.
   *
   * @param \Drupal\ghost\Type\Storable\StorableInterface $item
   *   The item to insert.
   */
  public function insert(StorableInterface $item) {
    $this->set($item->getIdentifier(), $item->getProperty('value'));
  }

  /**
   * Update an item.
   *
   * @param \Drupal\ghost\Type\Storable\StorableInterface $item
   *   The item to insert.
   */
  public function update(StorableInterface $item) {
    $this->insert($item);
  }

  /**
   * Delete an item.
   *
   * @param \Drupal\ghost\Type\Storable\StorableInterface $item
   *   The item to delete.
   */
  public function delete(StorableInterface $item) {
    variable_del($item->getIdentifier());
  }

  /**
   * Load a single item.
   *
   * @param mixed $identifier
   *   The item to load.
   *
   * @return mixed
   *   The result of the load operation.
   */
  public function load($identifier) {
    return $this->get($identifier);
  }

  /**
   * Load many.
   *
   * @param array $identifiers
   *   An array of identifiers.
   *
   * @return array
   *   An array of items.
   */
  public function loadMany(array $identifiers) {
    $items = array();
    if (!empty($identifiers)) {
      foreach ($identifiers as $id) {
        $items[$id] = $this->get($id);
      }
    }
    return $items;
  }

  /**
   * Get all items.
   *
   * @return array
   *   An array items.
   */
  public function fetchAll() {
    $result = db_select('variable', 'v')
      ->fields('v')
      ->execute();

    return $result->fetchAssoc();
  }

  /**
   * Set a variable.
   *
   * @param string $key
   *   Variable key.
   * @param mixed $value
   *   Value for the variable
   */
  public function set($key, $value) {
    variable_set($key, $value);
  }

  /**
   * Get a variable.
   *
   * @param string $key
   *   Key for the variable.
   * @param null|mixed $default
   *   A default
   *
   * @return mixed
   *   Result of the variable, or the default, or NULL.
   */
  public function get($key, $default = NULL) {
    return variable_get($key, $default);
  }

  /**
   * Insert multiple items.
   *
   * @param array $items
   *   An array of items.
   */
  public function insertMany(array $items) {
    // TODO: Implement insertMany() method.
  }

  /**
   * Update multiple items.
   *
   * @param array $items
   *   An array of StorableInterface items.
   */
  public function updateMany(array $items) {
    // TODO: Implement updateMany() method.
  }

}
