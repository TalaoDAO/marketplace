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
      'left_table' => 'users',
      'left_field' => 'uid',
      'table' => 'emh_points_txn',
      'field' => 'dest_id',
      'type' => 'INNER',
      'extra' => array(array('field' => 'dest_type', 'value' => 'user', 'operator' => '=')),
    ),
    'node' => array(
      'left_table' => 'node',
      'left_field' => 'nid',
      'table' => 'emh_points_txn',
      'field' => 'dest_id',
      'type' => 'INNER',
      'extra' => array(array('field' => 'dest_type', 'value' => 'node', 'operator' => '=')),
    ),
  );
  $data['emh_points_total']['table']['group'] = t('Points');
  $data['emh_points_total']['table']['join'] = array(
    'users' => array(
      'left_table' => 'users',
      'table' => 'emh_points_total',
      'left_field' => 'uid',
      'field' => 'entity_id',
      'extra' => array(array('field' => 'entity_type', 'value' => 'user', 'operator' => '=')),
    ),
    'node' => array(
      'left_table' => 'node',
      'table' => 'emh_points_total',
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
  $data['emh_points_txn']['source_id'] = array(
    'title' => t('Source ID'),
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
  $data['emh_points_txn']['source_type'] = array(
    'title'=> t('Source type'),
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
  $data['emh_points_txn']['dest_id'] = array(
    'title' => t('Destination ID'),
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
  $data['emh_points_txn']['dest_type'] = array(
    'title'=> t('Destination type'),
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
  $data['emh_points_total']['total_points'] = array(
    'title' => 'Total Points',
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
  // Double join on TXN.
  $data['emh_points_txn_source'] = $data['emh_points_txn'];
  $data['emh_points_txn_source']['table']['join']['users']['field'] = 'source_id';
  $data['emh_points_txn_source']['table']['join']['users']['extra'][0]['field'] = 'source_type';
  $data['emh_points_txn_source']['table']['join']['node']['field'] = 'source_id';
  $data['emh_points_txn_source']['table']['join']['node']['extra'][0]['field'] = 'source_type';
  $data['emh_points_txn_dest'] = $data['emh_points_txn'];
  $data['emh_points_txn_dest']['table']['join']['users']['field'] = 'dest_id';
  $data['emh_points_txn_dest']['table']['join']['users']['extra'][0]['field'] = 'dest_type';
  $data['emh_points_txn_dest']['table']['join']['node']['field'] = 'dest_id';
  $data['emh_points_txn_dest']['table']['join']['node']['extra'][0]['field'] = 'dest_type';
  unset($data['emh_points_txn']);
  return $data;
}