<?php
namespace Drupal\ghost_dev\UserInterface;
use Drupal\ghost\Exception\InvalidServiceException;
use Drupal\ghost\Service\ServiceFactory;
use Drupal\ghost\Service\ServiceFactoryInterface;
use Drupal\ghost\UserInterface\Component\ItemTable;

/**
 * Class ServiceListing.
 *
 * @package Drupal\ghost_dev\UserInterface
 */
class ServiceListing extends ItemTable {

  /**
   * Render a table of plugin information.
   *
   * @param ServiceFactoryInterface $service_factory
   *   An instance of ServiceFactory.
   */
  public function tableElement(ServiceFactoryInterface $service_factory) {

    $this->setEmpty('No plugins found.');
    $columns = array(
      'title' => t('Title'),
      'description' => t('Description'),
      'type' => t('Type'),
      'handler' => t('Handler'),
      'status' => t('Status'),
    );
    $this->setColumns($columns);

    $services = $service_factory->getServices();
    $types = $service_factory->getServiceTypes();

    if (!empty($services)) {

      foreach ($services as $index => $service_definition) {
        $row = array(
          'title' => isset($service_definition['name']) ? check_plain($service_definition['name']) : '',
          'description' => isset($service_definition['description']) ? check_plain($service_definition['description']) : '',
          'handler' => $service_definition['handler'],
          'type' => '',
        );

        if (!empty($service_definition['type']) && !empty($types)) {
          if (array_key_exists($service_definition['type'], $types)) {
            $row['type'] = check_plain($types[$service_definition['type']]['name']);
          }
        }

        if ($service_factory->testService($index)) {
          $row['status'] = t('OK');
        }
        else {
          try {
            $service_factory->getService($index);
          }
          catch (InvalidServiceException $e) {
            $row['status'] = $e->getMessage();
          }
        }

        $this->setItem($index, $row);
      }
    }
  }

}
