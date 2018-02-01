<?php
namespace Drupal\ghost_examples\Service;
use Drupal\ghost\Service\ServiceInterface;

/**
 * Interface ExampleService.
 *
 * @package Drupal\ghost_examples\Service
 */
interface ExampleServiceInterface extends ServiceInterface {

  /**
   * When foobar, do baz.
   *
   * @return mixed
   *   Some return value.
   */
  public function baz();

}

