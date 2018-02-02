<?php
namespace Drupal\ghost\Service;

/**
 * Class ServiceContainer.
 *
 * @package Drupal\ghost\Service
 */
class ServiceContainer {


  /**
   * Holds the ServiceContainer.
   *
   * @var ServiceFactoryInterface
   */
  protected static $instance;

  /**
   * An array of service information.
   *
   * @var array
   */
  public $services;

  /**
   * Lazy constructor.
   *
   * @return static
   *   An instance of ServiceFactoryInterface
   */
  static public function init() {

    if (!isset(self::$instance)) {
      $c = __CLASS__;
      self::$instance = new $c();
    }

    if (!isset(self::$instance->services)) {
      self::$instance->data = array();
    }

    return self::$instance;
  }

  /**
   * A private constructor; prevents direct creation of object.
   */
  private function __construct() {
    // Prevent direct creation (we are a singleton).
  }

  /**
   * Prevent object cloning (we are a singleton).
   */
  public function __clone() {
    trigger_error('Clone is not allowed.', E_USER_ERROR);
  }

}
