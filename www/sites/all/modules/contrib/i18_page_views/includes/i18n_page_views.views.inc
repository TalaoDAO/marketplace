<?php

/**
 * Implementation of hook_views_plugins().
 */
function i18n_page_views_views_plugins() {
  return array(
    'module' => 'i18n_page_views',
    'display' => array(
      'parent' => array(
        // this isn't really a display but is necessary so the file can
        // be included.
        'no ui' => TRUE,
        'handler' => 'views_plugin_display',
        'parent' => '',
      ),
      'i18n_page' => array(
        'title' => t('I18n page'),
        'help' => t('Display the view as a page, with a multiple URL'),
        'handler' => 'views_plugin_display_i18n_page',
        'theme' => 'views_view',
        'uses hook menu' => TRUE,
        'use ajax' => TRUE,
        'use pager' => TRUE,
        'accept attachments' => TRUE,
        'admin' => t('I18n page'),
        'help topic' => 'display-i18n-page',
      ),
    ),
  );
}
