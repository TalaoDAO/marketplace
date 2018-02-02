<?php

namespace Drupal\ghost\Service;
use Drupal\ghost\Exception\GhostException;
use Drupal\ghost\Exception\InvalidServiceException;

/**
 * Class ServiceFactory.
 *
 * @package Drupal\ghost\Service
 */
class ServiceFactory implements ServiceFactoryInterface {

  /**
   * An array of service information.
   *
   * @var ServiceContainer
   */
  protected $container;

  /**
   * Lazy constructor.
   *
   * @return static
   *   An instance of ServiceFactoryInterface
   */
  static public function init() {

    $container = ServiceContainer::init();
    return new static($container);
  }

  /**
   * A private constructor; prevents direct creation of object.
   */
  public function __construct(ServiceContainer $container) {

    $this->container = $container;

    $this->loadServiceDefinitions();
  }

  /**
   * Load service definitions.
   */
  public function loadServiceDefinitions() {

    $defaults = $this->getDefaultServices();
    foreach (array_keys($defaults) as $default_key) {
      $defaults[$default_key]['action'] = 'default';
    }

    $hooked = module_invoke_all('ghost_services');
    foreach (array_keys($hooked) as $hooked_key) {
      $hooked[$hooked_key]['action'] = 'hook';
    }

    $merged = array();
    if (!empty($defaults)) {
      if (!empty($hooked)) {
        $merged = array_merge_recursive($defaults, $hooked);
      }
      else {
        $merged = $defaults;
      }
    }
    else {
      if (!empty($hooked)) {
        $merged = $hooked;
      }
    }

    drupal_alter('ghost_services', $merged);

    $overrides = variable_get('ghost_services', array());

    if (!empty($overrides)) {
      foreach ($overrides as $override_key => $override) {
        if (array_key_exists($override_key, $merged)) {
          $merged[$override_key] = array_merge($merged[$override_key], $override);
          $merged[$override_key]['action'] = 'override';
        }
      }
    }

    $this->container->services = $merged;
  }

  /**
   * Get default service information.
   *
   * @return array
   *   Default service definitions.
   */
  public function getDefaultServices() {
    return array();
  }

  /**
   * Get a specific service handler.
   *
   * @param string $service_name
   *   Name of the service.
   *
   * @return ServiceInterface
   *   An instance of ServiceInterface
   *
   * @throws \Exception
   */
  public function getService($service_name) {

    $service_definitions = $this->getServices();

    if (array_key_exists($service_name, $service_definitions)) {

      if (class_exists($service_definitions[$service_name]['handler'])) {
        $service_handler = new $service_definitions[$service_name]['handler']();

        if ($service_handler instanceof ServiceInterface) {
          return $service_handler;
        }

        throw new InvalidServiceException(sprintf('Service %s is not an instance of ServiceInterface', $service_handler));
      }
      else {
        throw new InvalidServiceException(sprintf('Service %s does not exist', $service_definitions[$service_name]['handler']));
      }
    }
    else {
      throw new InvalidServiceException(sprintf('%s was not found in the Services index', $service_name));
    }

  }

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
  public function testService($service_name) {
    try {
      $this->getService($service_name);
    }
    catch (InvalidServiceException $e) {

      return FALSE;
    }

    return TRUE;
  }

  /**
   * Get the Services array.
   *
   * @return array
   *   An array of Service information.
   */
  public function getServices() {
    return $this->container->services;
  }

  /**
   * Determine if a Service exists.
   *
   * @param string $service_name
   *   Name of the Service.
   *
   * @return bool
   *   TRUE if the service is present, or FALSE if not.
   */
  public function serviceExists($service_name) {

    if (array_key_exists($service_name, $this->container->services)) {
      return TRUE;
    }

    return FALSE;
  }

  /**
   * Remove a service.
   *
   * @param string $service_name
   *   Name of the service to remove.
   */
  public function removeService($service_name) {

    if ($this->serviceExists($service_name)) {
      unset($this->container->services[$service_name]);
    }
  }

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
  public function addService($service_name, array $service_definition, $overwrite = TRUE) {

    if ($overwrite == FALSE && $this->serviceExists($service_name)) {
      throw new GhostException(sprintf('Service %s already exists'));
    }

    $this->container->services[$service_name] = $service_definition;
  }

  /**
   * Get information about Service Types.
   *
   * @return array
   *   An array of type information.
   */
  public function getServiceTypes() {
    return module_invoke_all('ghost_service_types');
  }

}
