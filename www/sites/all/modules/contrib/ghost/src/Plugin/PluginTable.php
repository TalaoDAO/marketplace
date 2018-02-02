<?php

/**
 * @file
 * Contains a
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2014 Christopher Skene
 */

namespace Drupal\ghost\Plugin;

use Drupal\ghost\UserInterface\Component\BaseComponent;

/**
 * Class PluginTable
 * @package Drupal\ghost\UserInterface\Component
 */
class PluginTable extends BaseComponent {

  /**
   * Render a table of plugin information.
   *
   * @param array $plugins
   *   An array of plugin information.
   *
   * @return string
   *   A rendered table.
   */
  public function tableElement($plugins) {

    $rows = array();
    $header = array(
      t('Title'),
      t('Description'),
      t('Provider'),
      t('Visibility'),
    );

    foreach ($plugins as $plugin) {
      $row = array(
        $plugin['title'],
        $plugin['description'],
        $plugin['module'],
        isset($plugin['hidden']) && $plugin['hidden'] == TRUE ? t('Hidden') : '',
      );
      $rows[] = $row;
    }

    $vars = array(
      'header' => $header,
      'rows' => $rows,
      'empty' => t('No plugins found.'),
    );

    $output = theme('table', $vars);

    return $output;
  }
}
