<?php
/**
 * @file views_dependent_filters.views.inc
 * Contains implementations of views hooks.
 */

/**
 * Implements hook_views_data_alter().
 */
function views_dependent_filters_views_data_alter(&$data) {
  // Add our filter handler as a global.
  $data['views']['views_dependent_filter'] = array(
    'filter' => array(
      'title' => t('Dependent filter'),
      'help' => t("Does not provide a filter itself but allows the values of one exposed filter to control the presence of other filters."),
      'handler' => 'views_dependent_filters_handler_filter_dependent',
    ),
  );
}
