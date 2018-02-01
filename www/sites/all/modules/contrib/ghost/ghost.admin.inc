<?php

/**
 * @file
 * Contains admin.
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 */

use Drupal\ghost\Core\Block\BlockPluginFactory;

/**
 * Overview page for Block plugins.
 *
 * @return string
 *   A page view.
 */
function ghost_block_plugin_overview_page() {

  $plugins = BlockPluginFactory::init()->loadAllPluginDefinitions();

  $table_manager = \Drupal\ghost\UserInterface\Component\PluginTable::init();
  $table_manager->tableElement($plugins);

  return $table_manager->render();
}
