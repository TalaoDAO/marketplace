<?php
/**
 * @file
 * Views integration for the views_fieldset module.
 */

/**
 * Implements hook_views_plugins().
 */
function views_fieldset_views_plugins() {
  $plugins = array();

  $plugins['style']['fieldset'] = array(
    'title' => t('Fieldset'),
    'help' => t('Renders the full views output in a fieldset'),
    'handler' => 'views_plugin_style_fieldset',
    'theme' => 'views_view_fieldset',
    'uses row plugin' => TRUE,
    'uses fields' => FALSE,
    'uses row class' => TRUE,
    'uses grouping' => FALSE,
    'uses options' => TRUE,
    'type' => 'normal',
  );

  return $plugins;
}
