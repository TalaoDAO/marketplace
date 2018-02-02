<?php
namespace Drupal\ghost_dev\Controller;

use Drupal\ghost\Page\PageController;
use Drupal\ghost\Page\PageControllerInterface;
use Drupal\ghost\Core\Block\BlockPluginFactory;
use Drupal\ghost\UserInterface\Component\PluginTable;

/**
 * Class BlockPluginListController.
 *
 * @package Drupal\ghost_dev\Controller
 */
class BlockPluginListController extends PageController implements PageControllerInterface {

  /**
   * Page callback for the plugin listing page.
   *
   * @return string
   *   Rendered plugin view.
   */
  public function view() {

    $plugins = BlockPluginFactory::init()->loadAllPluginDefinitions();

    $table_manager = PluginTable::init();
    $table_manager->tableElement($plugins);

    return $table_manager->render();
  }

}
