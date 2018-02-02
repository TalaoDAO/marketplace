<?php

/**
 * @file
 * Contains an InitialiserTrait
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Traits;


/**
 * Trait InitialiserTrait
 * @package Drupal\ghost\Traits
 */
trait InitialiserTrait {

  /**
   * Static constructor.
   *
   * @return static
   *   An instance of this object.
   * @static
   */
  static public function init() {

    return new static();
  }

}
