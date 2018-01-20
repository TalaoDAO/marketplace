<?php

namespace Drupal\ghost\UserInterface\Component;


/**
 * Class PluginTable.
 *
 * @package Drupal\ghost\UserInterface\Component
 */
class PluginTable extends ItemTable {

  /**
   * Render a table of plugin information.
   *
   * @param array $plugins
   *   An array of plugin information.
   */
  public function tableElement($plugins) {

    $columns = array(
      'title' => t('Title'),
      'description' => t('Description'),
      'provider' => t('Provider'),
      'visibility' => t('Visibility'),
    );

    $this->setColumns($columns);

    foreach ($plugins as $index => $plugin) {
      $row = array(
        'title' => $plugin['title'],
        'description' => $plugin['description'],
        'provider' => $plugin['module'],
        'visibility' => isset($plugin['hidden']) && $plugin['hidden'] == TRUE ? t('Hidden') : t('Default'),
      );

      $this->setItem($index, $row);
    }

    $this->setEmpty('No plugins found.');
  }

}
