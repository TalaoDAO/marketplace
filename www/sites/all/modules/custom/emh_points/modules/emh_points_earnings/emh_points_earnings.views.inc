<?php

/**
 * @file
 * EMH Earnings Views integration.
 */

/**
 * Implements hook_views_data().
 *
 * @ingroup views
 */
function emh_points_earnings_views_data() {
  $data = array();

  // We declare the tables.
  $data['emh_points_earnings']['table']['group'] = t('Earnings');
  $data['emh_points_earnings']['table']['join'] = array(
    'users' => array(
      'left_table' => 'users',
      'table' => 'emh_points_earnings',
      'left_field' => 'uid',
      'field' => 'entity_id',
      'extra' => array(
        array('field' => 'entity_type', 'value' => 'user', 'operator' => '='),
      ),
    ),
  );
  // Then the fields.
  $data['emh_points_earnings']['earnings'] = array(
    'title' => 'Total Earnings',
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}
