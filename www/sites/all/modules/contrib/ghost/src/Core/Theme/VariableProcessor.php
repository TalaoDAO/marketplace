<?php

/**
 * @file
 * Contains a VariableProcessor
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2016 Christopher Skene
 */

namespace Drupal\ghost\Core\Theme;

/**
 * Class VariableProcessor
 *
 * @package Drupal\ghost\Core\Theme
 */
class VariableProcessor {
  /**
   * Vars.
   *
   * @var array
   */
  protected $vars;

  /**
   * Static constructor.
   *
   * @return static
   *   An instance of this object.
   * @static
   */
  static public function init(array $vars) {

    return new static($vars);
  }

  /**
   * ProductPreprocessController constructor.
   *
   * @param array $vars
   *   The vars.
   */
  public function __construct(array $vars) {

    $this->vars = $vars;
  }

  /**
   * Preprocess.
   */
  public function preprocess() {

    return $this->vars;
  }

  /**
   * Get a var.
   *
   * @param string $key
   *   The key
   *
   * @return mixed
   *   The value
   */
  public function getVar($key) {
    if (isset($this->vars[$key])) {
      return $this->vars[$key];
    }

    return FALSE;
  }

  /**
   * Set a value
   *
   * @param string $key
   *   The key
   * @param mixed $value
   *   The value.
   *
   * @return $this
   *   An instance of ProductPreprocessController
   */
  public function setVar($key, $value) {
    $this->vars[$key] = $value;

    return $this;
  }
}
