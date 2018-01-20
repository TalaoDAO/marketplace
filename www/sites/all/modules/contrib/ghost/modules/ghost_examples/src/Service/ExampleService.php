<?php
namespace Drupal\ghost_examples\Service;
use Drupal\ghost\Service\BaseService;

/**
 * Class ExampleService.
 *
 * @package Drupal\ghost_examples\Service
 */
class ExampleService extends BaseService implements ExampleServiceInterface {

  /**
   * {@inheritdoc}
   */
  public function baz() {
    // Do some foo or baz here.
  }

}
