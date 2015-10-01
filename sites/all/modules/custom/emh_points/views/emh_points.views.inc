<?php

/**
 * @file
 * EMH Points Views integration.
 */

/**
 * Implements hook_views_data().
 * @ingroup views
 */
function emh_points_views_data() {
  $data = array();
  // We declare the tables.
  $data['emh_points']['table']['group'] = t('Points');
  $data['emh_points']['table']['base'] = array(
    'field' => 'pid',
    'title' => t('Points'),
    'defaults' => array(
      'field' => 'points',
    ),
  );
  $data['emh_points']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'entity_id',
      'extra' => array(array('field' => 'entity_type', 'value' => 'user', 'operator' => '=')),
    ),
    'node' => array(
      'left_field' => 'nid',
      'field' => 'entity_id',
      'extra' => array(array('field' => 'entity_type', 'value' => 'node', 'operator' => '=')),
    ),
  );
  $data['emh_points_txn']['table']['group'] = t('Points Transaction');
  $data['emh_points_txn']['table']['base'] = array(
    'field' => 'txn_id',
    'title' => t('Points Transactions'),
    'defaults' => array(
      'field' => 'description',
    ),
  );
  $data['emh_points_txn']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'entity_id',
      'extra' => array(array('field' => 'entity_type', 'value' => 'user', 'operator' => '=')),
    ),
    'node' => array(
      'left_field' => 'nid',
      'field' => 'entity_id',
      'extra' => array(array('field' => 'entity_type', 'value' => 'node', 'operator' => '=')),
    ),
  );
  // Then the fields.
  $data['emh_points']['pid'] = array(
    'title' => 'Pid',
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
  $data['emh_points']['entity_id'] = array(
    'title' => 'Entity ID',
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
  $data['emh_points']['max_points'] = array(
    'title' => 'Max points',
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
  $data['emh_points']['points'] = array(
    'title' => 'Points',
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
  $data['emh_points']['last_update'] = array(
    'title' => t('Last update date'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['emh_points']['expiration_date'] = array(
    'title' => t('Expiration date'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['emh_points']['entity_type'] = array(
    'title'=> t('Entity type'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['emh_points']['bundle'] = array(
    'title'=> t('Bundle'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['emh_points_txn']['txn_id'] = array(
    'title' => 'Transaction ID',
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
  $data['emh_points_txn']['uid'] = array(
    'title' => t('Author of the transaction'),
    'relationship' => array(
      'title' => t('Author of the transaction'),
      'help' => t('Relate content to the user who created it.'),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('author of the point transaction'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_name',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'field' => array(
      'handler' => 'views_handler_field_user',
    ),
  );
  $data['emh_points_txn']['points'] = array(
    'title' => 'Points',
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
  $data['emh_points_txn']['time_stamp'] = array(
    'title' => t('Timestamp'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['emh_points_txn']['description'] = array(
    'title' => t('Description of the transaction'),
    'field' => array(
      'click sortable' => FALSE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  $data['emh_points_txn']['entity_id'] = array(
    'title' => 'Entity ID',
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
  $data['emh_points_txn']['entity_type'] = array(
    'title'=> t('Entity type'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  $data['emh_points_txn']['operation'] = array(
    'title'=> t('Operation'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
  return $data;
}
