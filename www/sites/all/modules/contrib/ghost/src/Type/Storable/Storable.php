<?php

/**
 * @file
 * Contains a
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Type\Storable;

/**
 * Class Storable
 *
 * @package Drupal\ghost\Type\Storable
 */
abstract class Storable implements StorableInterface {

  /**
   * The identifier.
   *
   * @var mixed
   */
  public $identifier;

  /**
   * Get the unique identifier.
   *
   * @return mixed
   *   The key for storage.
   */
  public function getIdentifier() {
    return $this->identifier;
  }

  /**
   * Fetch a property.
   *
   * @param string $name
   *   Property to fetch
   *
   * @return mixed
   *   Value of the property.
   */

  /**
   * Fetch a property.
   *
   * @param string $name
   *   Property to fetch
   *
   * @return mixed
   *   Value of the property.
   */
  public function getProperty($name) {
    if (property_exists($this, $name)) {
      return $this->$name;
    }
  }

}
