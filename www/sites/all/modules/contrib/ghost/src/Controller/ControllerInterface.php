<?php

/**
 * @file
 * Contains a ControllerInterface
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Controller;

use Drupal\ghost\Type\Storable\StorableInterface;

/**
 * Interface ControllerInterface
 *
 * @package Drupal\ghost\Controller
 */
interface ControllerInterface {

  /**
   * Create a new instance.
   *
   * @return static
   *   A new instance of ControllerInterface.
   * @static
   */
  public static function create();

  /**
   * Insert an item.
   *
   * @param \Drupal\ghost\Type\Storable\StorableInterface $item
   *   The item to insert.
   */
  public function insert(StorableInterface $item);

  /**
   * Insert multiple items.
   *
   * @param array $items
   *   An array of items.
   */
  public function insertMany(array $items);

  /**
   * Update an item.
   *
   * @param \Drupal\ghost\Type\Storable\StorableInterface $item
   *   The item to insert.
   */
  public function update(StorableInterface $item);

  /**
   * Update multiple items.
   *
   * @param array $items
   *   An array of StorableInterface items.
   */
  public function updateMany(array $items);

  /**
   * Delete an item.
   *
   * @param \Drupal\ghost\Type\Storable\StorableInterface $item
   *   The item to delete.
   */
  public function delete(StorableInterface $item);

  /**
   * Load a single item.
   *
   * @param mixed $identifier
   *   The item to load.
   *
   * @return mixed
   *   The result of the load operation.
   */
  public function load($identifier);

  /**
   * Load many.
   *
   * @param array $identifiers
   *   An array of identifiers.
   *
   * @return array
   *   An array of items.
   */
  public function loadMany(array $identifiers);

  /**
   * Get all items.
   *
   * @return array
   *   An array items.
   */
  public function fetchAll();

}
