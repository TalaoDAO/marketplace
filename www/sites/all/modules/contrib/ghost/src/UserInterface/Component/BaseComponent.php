<?php

/**
 * @file
 * Contains a
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2014 Christopher Skene
 */

namespace Drupal\ghost\UserInterface\Component;


/**
 * Class BaseComponent
 * @package Drupal\ghost\UserInterface\Component
 */
abstract class BaseComponent implements ComponentInterface {

  /**
   * Lazy constructor.
   *
   * @return static
   *   An instance of ComponentInterface
   * @static
   */
  static public function init() {

    return new static();
  }
}
