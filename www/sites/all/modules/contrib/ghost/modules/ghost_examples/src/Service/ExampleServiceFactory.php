<?php
namespace Drupal\ghost_examples\Service;
use Drupal\ghost\Service\ServiceFactory;
use Drupal\ghost\Service\ServiceFactoryInterface;

/**
 * Class ExampleServiceFactory.
 *
 * @package Drupal\ghost_examples\Service
 */
class ExampleServiceFactory extends ServiceFactory implements ServiceFactoryInterface {

  /**
   * Return default services for your application.
   */
  public function getDefaultServices() {
    return array(
      'service_1' => array(
        'handler' => '\Drupal\ghost_examples\Services\Foo\FooService',
      ),
    );
  }

  /**
   * Helper to return a hinted service.
   *
   * @param string $service_name
   *   Name of the service.
   *
   * @return ExampleServiceInterface
   *   An instance of ExampleServiceInterface
   *
   * @throws \Drupal\ghost\Exception\GhostException
   */
  public function getFooService($service_name) {
    return $this->getService($service_name);
  }

}
