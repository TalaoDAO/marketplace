<?php
/**
 * @file
 * simple_timeline.views.inc
 * Created by JetBrains PhpStorm.
 * User: alan
 */

/**
 * Implements hook_views_plugin().
 */
function simple_timeline_views_plugins() {
  return array(
    'style' => array(
      'simple_timeline_style' => array(
        'title' => t('Simple Timeline'),
        'handler' => 'simple_timeline_style_plugin',
        'uses options' => TRUE,
        'help' => t('Display the selected items on a timeline.'),
        'theme' => 'views_view_list',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses grouping' => FALSE,
        'type' => 'normal',
      ),
    ),
    'row' => array(
      'simple_timeline_row' => array(
        'title' => t('Simple Timeline Item'),
        'handler' => 'simple_timeline_row_plugin',
        'uses options' => TRUE,
        'help' => t('Renderer for a timeline item.'),
        'theme' => 'simple_timeline_fields',
        'uses fields' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}
