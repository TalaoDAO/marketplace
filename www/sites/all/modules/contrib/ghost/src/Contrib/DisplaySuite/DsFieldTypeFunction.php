<?php

/**
 * @file
 * Contains a
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Contrib\DisplaySuite;


/**
 * Class DsFieldTypeFunction
 * @package Drupal\ghost\DisplaySuite
 */
class DsFieldTypeFunction {

  /**
   * Render vars
   *
   * @var array
   */
  protected $vars;

  /**
   * Build vars
   *
   * @var array
   */
  protected $buildVars = array();

  /**
   * Render a field.
   *
   * @return string
   *   The result of the build function.
   * @static
   */
  static public function view($vars) {

    $field = new static($vars);

    $field->build();

    return $field->render();
  }

  /**
   * Constructor.
   *
   * @param array $vars
   *   Render vars.
   */
  public function __construct($vars) {
    $this->vars = $vars;
  }

  /**
   * Build.
   */
  public function build() {

    return NULL;
  }

  /**
   * Render the build vars.
   *
   * @return string
   *   Rendered value.
   */
  public function render() {

    return implode(' ', $this->buildVars);
  }
}
