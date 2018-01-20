<?php
namespace Drupal\ghost\Service;
use Drupal\ghost\Exception\GhostException;
use Drupal\ghost\Exception\InvalidServiceException;

/**
 * Interface ServiceFactoryInterface.
 *
 * @package Drupal\ghost\Service
 */
interface ServiceFactoryInterface {

  /**
   * Lazy constructor.
   *
   * @return static
   *   An instance of ServiceFactoryInterface
   */
  public static function init();

  /**
   * Get a specific service handler.
   *
   * Returns a defined service handler.
   *
   * @param string $service_name
   *   Name of the service.
   *
   * @return ServiceInterface
   *   An instance of ServiceInterface
   *
   * @throws \Exception
   */
  public function getService($service_name);

  /**
   * Get the Services array.
   *
   * This returns the current $services array, not the class handlers, and
   * does not reload or rebuild the information.
   *
   * @return array
   *   An array of Service information.
   */
  public function getServices();

  /**
   * Load service definitions.
   *
   * This reloads all service definitions, by default from a $conf array,
   * and repopulates the $services array. It is called when the Factory is
   * initialised, and can be called again to "reset" the Factory.
   *
   * @return array
   *   An array of service definitions.
   */
  public function loadServiceDefinitions();

  /**
   * Get default service information.
   *
   * Returns an array of default services. This is empty by default, but
   * can be overridden to provided a hard-coded set of services.
   *
   * @return array
   *   Default service definitions.
   */
  public function getDefaultServices();

  /**
   * Determine if a Service exists.
   *
   * @param string $service_name
   *   Name of the Service.
   *
   * @return bool
   *   TRUE if the service is present, or FALSE if not.
   */
  public function serviceExists($service_name);

  /**
   * Remove a service.
   *
   * @param string $service_name
   *   Name of the service to remove.
   */
  public function removeService($service_name);

  /**
   * Add a service definition.
   *
   * @param string $service_name
   *   Name of the service definition.
   * @param array $service_definition
   *   A service definition.
   * @param bool $overwrite
   *   (Optional) If FALSE, an existing service wont be overwritten. This throws
   *   a GhostException, so its worth catching that if you set this. Otherwise,
   *   any existing service is replaced.
   *
   * @throws \Drupal\ghost\Exception\GhostException
   */
  public function addService($service_name, array $service_definition, $overwrite = TRUE);

  /**
   * Test whether a service handler is available.
   *
   * @param string $service_name
   *   Name of the service.
   *
   * @return bool
   *   TRUE if the service loads, FALSE if not. If this function returns FALSE,
   *   calling ::getService() on the same name should return the result in the
   *   exception message.
   */
  public function testService($service_name);

  /**
   * Get information about Service Types.
   *
   * @return array
   *   An array of type information.
   */
  public function getServiceTypes();

}
