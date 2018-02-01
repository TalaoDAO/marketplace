<?php

/**
 * @file
 * Contains an HtmlOutput
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Type;


/**
 * Class HtmlOutput
 * @package Drupal\ghost\Output
 */
class HtmlOutput {

  /**
   * Outputs.
   *
   * @var array
   */
  protected $outputs = array();

  /**
   * Init.
   *
   * @return static
   *   This.
   * @static
   */
  static public function init() {

    return new static();
  }

  /**
   * Add output.
   *
   * @param string $string
   *   HTML.
   *
   * @return HtmlOutput
   *   This.
   */
  public function addOutput($string) {

    $this->outputs[] = $string;

    return $this;
  }

  /**
   * Getter for outputs.
   *
   * @return string
   *   Rendered HTML output.
   */
  public function getOutput() {

    return implode("\n", $this->outputs);
  }
}
