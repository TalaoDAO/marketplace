<?php

/**
 * @file
 * Contains a
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Core\Variable;

use Drupal\ghost\Type\Storable\Storable;
use Drupal\ghost\Type\Storable\StorableInterface;

/**
 * Class Variable
 *
 * @package Drupal\ghost\Core\Variable
 */
class Variable extends Storable implements StorableInterface {

  /**
   * The variable key.
   *
   * @var string
   */
  public $key;

  /**
   * The variable value.
   *
   * @var mixed
   */
  public $value;

  /**
   * Get the storage identifier.
   *
   * @return mixed
   *   The key for storage.
   */
  public function getIdentifier() {
    return $this->getKey();
  }

  /**
   * Get database write values for this block.
   *
   * @return array
   *   An array suitable for database writes.
   */
  public function getStorableValues() {
    return $this->value;
  }

  /**
   * Getter for key.
   *
   * @return string
   *   The key.
   */
  public function getKey() {

    return $this->key;
  }

  /**
   * Setter for key.
   *
   * @param string $key
   *   The value for key.
   */
  public function setKey($key) {

    $this->key = $key;
  }

  /**
   * Getter for value.
   *
   * @return mixed
   *   The value
   */
  public function getValue() {

    return $this->value;
  }

  /**
   * Setter for value.
   *
   * @param mixed $value
   *   The value for value.
   */
  public function setValue($value) {

    $this->value = $value;
  }
}
