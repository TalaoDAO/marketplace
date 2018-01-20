<?php

/**
 * @file
 * Contains a
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\UserInterface\Component;


/**
 * Interface ComponentInterface
 * @package Drupal\ghost\UserInterface\Component
 */
interface ComponentInterface {

  /**
   * Return rendered output for this component.
   *
   * @return string
   *   Fully rendered output.
   */
  public function render();
}
