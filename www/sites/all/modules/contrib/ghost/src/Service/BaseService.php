<?php

namespace Drupal\ghost\Service;

/**
 * Class BaseService.
 *
 * @package Drupal\ghost\Service
 */
abstract class BaseService implements ServiceInterface {

  /**
   * Lazy constructor.
   *
   * @return static
   *   An instance of ServiceFactory.
   */
  static public function create() {

    return new static();
  }

}
