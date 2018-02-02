<?php

/**
 * @file
 * Contains a DataAccess interface.
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 */

namespace Drupal\ghost\Data;

/**
 * Interface DataAccess
 *
 * @package Drupal\ghost\Data
 */
interface DataAccessInterface {

  /**
   * Create a new item.
   *
   * @param array|object $item
   *   The item. Either an object or an array can be passed.
   *
   * @return bool
   *   TRUE on success or FALSE on failure.
   */
  public function create($item);

  /**
   * Update an existing item.
   *
   * @param string $id
   *   The identifier to update.
   * @param array|object $item
   *   The item. Either an object or an array can be passed.
   *
   * @return bool
   *   TRUE on success or FALSE on failure.
   */
  public function update($id, $item);

  /**
   * Read an item.
   *
   * @param string $id
   *   The identifier to update.
   *
   * @return object
   *   The result of the read operation, as an object.
   */
  public function read($id);

  /**
   * Delete an item.
   *
   * @param string $id
   *   The identifier to update.
   *
   * @return bool
   *   TRUE on success and FALSE on failure.
   */
  public function delete($id);
}
