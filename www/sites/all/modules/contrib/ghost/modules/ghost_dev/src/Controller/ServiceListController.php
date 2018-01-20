<?php
namespace Drupal\ghost_dev\Controller;
use Drupal\ghost\Page\PageController;
use Drupal\ghost\Page\PageControllerInterface;
use Drupal\ghost\Service\ServiceFactory;
use Drupal\ghost_dev\UserInterface\ServiceListing;

/**
 * Class ServiceListController.
 *
 * @package Drupal\ghost_dev\Controller
 */
class ServiceListController extends PageController implements PageControllerInterface {

  /**
   * Render a list of Services.
   *
   * @return string
   *   Rendered output.
   */
  public function view() {

    $service_factory = ServiceFactory::init();

    $service_list = ServiceListing::init();
    $service_list->tableElement($service_factory);

    return $service_list->render();
  }

}
