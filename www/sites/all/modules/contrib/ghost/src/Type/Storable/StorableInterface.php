<?php

/**
 * @file
 * Contains a StorableInterface
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Type\Storable;

/**
 * Interface StorableInterface
 *
 * @package Drupal\ghost\Type\Storable
 *
 * @todo Key/Value stores have different models to record-based stores.
 *   Should we accommodate that?
 */
interface StorableInterface {

  /**
   * Get the storage identifier.
   *
   * @return mixed
   *   The key for storage.
   */
  public function getIdentifier();

  /**
   * Fetch a property.
   *
   * @param string $name
   *   Property to fetch
   *
   * @return mixed
   *   Value of the property.
   */
  public function getProperty($name);

  /**
   * Get database write values for this block.
   *
   * @return array
   *   An array suitable for database writes.
   */
  public function getStorableValues();
}
