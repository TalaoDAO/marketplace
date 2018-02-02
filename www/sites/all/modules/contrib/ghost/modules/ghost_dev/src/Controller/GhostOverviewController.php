<?php
namespace Drupal\ghost_dev\Controller;
use Drupal\ghost\Page\PageController;
use Drupal\ghost\Page\PageControllerInterface;

/**
 * Class GhostOverviewController.
 *
 * @package Drupal\ghost_dev\Controller
 */
class GhostOverviewController extends PageController implements PageControllerInterface {

  /**
   * View callback for 'admin/config/development/ghost'.
   *
   * @return string
   *   Rendered output.
   */
  public function view() {

    module_load_include('inc', 'system', 'system.admin');
    return \system_admin_menu_block_page();
  }

}
