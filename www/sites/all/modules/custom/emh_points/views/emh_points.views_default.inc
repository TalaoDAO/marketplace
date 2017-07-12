<?php

/**
 * @file
 * Default Views for credits management.
 */

/**
 * Implements hook_views_default_views().
 * @ingroup views
 */
function emh_points_views_default_views() {
  $views = array();

  // Credits statement
  $view = new view();
  $view->name = 'points_history';
  $view->description = '';
  $view->tag = 'EMH, credits';
  $view->base_table = 'users';
  $view->human_name = 'Credits statement';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Credits statement';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'use credits';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Credits Transaction (source): Timestamp */
  $handler->display->display_options['fields']['time_stamp']['id'] = 'time_stamp';
  $handler->display->display_options['fields']['time_stamp']['table'] = 'emh_points_txn_source';
  $handler->display->display_options['fields']['time_stamp']['field'] = 'time_stamp';
  $handler->display->display_options['fields']['time_stamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['time_stamp']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Credits Transaction (source): Operation */
  $handler->display->display_options['fields']['operation']['id'] = 'operation';
  $handler->display->display_options['fields']['operation']['table'] = 'emh_points_txn_source';
  $handler->display->display_options['fields']['operation']['field'] = 'operation';
  /* Field: Credits Transaction (source): Context */
  $handler->display->display_options['fields']['context']['id'] = 'context';
  $handler->display->display_options['fields']['context']['table'] = 'emh_points_txn_source';
  $handler->display->display_options['fields']['context']['field'] = 'context';
  /* Field: Credits Transaction (source): Credits */
  $handler->display->display_options['fields']['points']['id'] = 'points';
  $handler->display->display_options['fields']['points']['table'] = 'emh_points_txn_source';
  $handler->display->display_options['fields']['points']['field'] = 'points';
  /* Field: Credits Transaction (source): Description of the transaction */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'emh_points_txn_source';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  /* Sort criterion: Credits Transaction (source): Timestamp */
  $handler->display->display_options['sorts']['time_stamp']['id'] = 'time_stamp';
  $handler->display->display_options['sorts']['time_stamp']['table'] = 'emh_points_txn_source';
  $handler->display->display_options['sorts']['time_stamp']['field'] = 'time_stamp';
  $handler->display->display_options['sorts']['time_stamp']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';

  /* Display: History */
  $handler = $view->new_display('page', 'History', 'history');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'points_history:page_1';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Credits Transaction (source): Timestamp */
  $handler->display->display_options['fields']['time_stamp']['id'] = 'time_stamp';
  $handler->display->display_options['fields']['time_stamp']['table'] = 'emh_points_txn_source';
  $handler->display->display_options['fields']['time_stamp']['field'] = 'time_stamp';
  $handler->display->display_options['fields']['time_stamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['time_stamp']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Credits Transaction (source): Operation */
  $handler->display->display_options['fields']['operation']['id'] = 'operation';
  $handler->display->display_options['fields']['operation']['table'] = 'emh_points_txn_source';
  $handler->display->display_options['fields']['operation']['field'] = 'operation';
  /* Field: Credits Transaction (source): Context */
  $handler->display->display_options['fields']['context']['id'] = 'context';
  $handler->display->display_options['fields']['context']['table'] = 'emh_points_txn_source';
  $handler->display->display_options['fields']['context']['field'] = 'context';
  /* Field: Credits Transaction (source): Credits */
  $handler->display->display_options['fields']['points']['id'] = 'points';
  $handler->display->display_options['fields']['points']['table'] = 'emh_points_txn_source';
  $handler->display->display_options['fields']['points']['field'] = 'points';
  $handler->display->display_options['fields']['points']['prefix'] = '-';
  /* Field: Credits Transaction (source): Description of the transaction */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'emh_points_txn_source';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'history';
  $handler->display->display_options['menu']['title'] = 'History';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['block_description'] = 'Credits statement';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Credits Transaction (destination): Timestamp */
  $handler->display->display_options['fields']['time_stamp']['id'] = 'time_stamp';
  $handler->display->display_options['fields']['time_stamp']['table'] = 'emh_points_txn_dest';
  $handler->display->display_options['fields']['time_stamp']['field'] = 'time_stamp';
  $handler->display->display_options['fields']['time_stamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['time_stamp']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Credits Transaction (destination): Operation */
  $handler->display->display_options['fields']['operation']['id'] = 'operation';
  $handler->display->display_options['fields']['operation']['table'] = 'emh_points_txn_dest';
  $handler->display->display_options['fields']['operation']['field'] = 'operation';
  /* Field: Credits Transaction (destination): Context */
  $handler->display->display_options['fields']['context']['id'] = 'context';
  $handler->display->display_options['fields']['context']['table'] = 'emh_points_txn_dest';
  $handler->display->display_options['fields']['context']['field'] = 'context';
  /* Field: Credits Transaction (destination): Credits */
  $handler->display->display_options['fields']['points']['id'] = 'points';
  $handler->display->display_options['fields']['points']['table'] = 'emh_points_txn_dest';
  $handler->display->display_options['fields']['points']['field'] = 'points';
  $handler->display->display_options['fields']['points']['prefix'] = '+';
  /* Field: Credits Transaction (destination): Description of the transaction */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'emh_points_txn_dest';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Credits Transaction (destination): Timestamp */
  $handler->display->display_options['sorts']['time_stamp']['id'] = 'time_stamp';
  $handler->display->display_options['sorts']['time_stamp']['table'] = 'emh_points_txn_dest';
  $handler->display->display_options['sorts']['time_stamp']['field'] = 'time_stamp';
  $handler->display->display_options['sorts']['time_stamp']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'user/%/history_dest';
  $handler->display->display_options['menu']['title'] = 'History (destination)';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/history_source';
  $handler->display->display_options['menu']['title'] = 'History (source)';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'transaction_log';
  $view->description = '';
  $view->tag = 'EMH, credits';
  $view->base_table = 'emh_points_txn';
  $view->human_name = 'Transaction log';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Transaction log';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer credits';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'txn_id' => 'txn_id',
    'time_stamp' => 'time_stamp',
    'operation' => 'operation',
    'context' => 'context',
    'source_type' => 'source_type',
    'source_id' => 'source_id',
    'dest_type' => 'dest_type',
    'dest_id' => 'dest_id',
    'points' => 'points',
    'description' => 'description',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'txn_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'time_stamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'operation' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'context' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'source_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'source_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'dest_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'dest_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'points' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'description' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Credits Transaction: Transaction ID */
  $handler->display->display_options['fields']['txn_id']['id'] = 'txn_id';
  $handler->display->display_options['fields']['txn_id']['table'] = 'emh_points_txn';
  $handler->display->display_options['fields']['txn_id']['field'] = 'txn_id';
  /* Field: Credits Transaction: Timestamp */
  $handler->display->display_options['fields']['time_stamp']['id'] = 'time_stamp';
  $handler->display->display_options['fields']['time_stamp']['table'] = 'emh_points_txn';
  $handler->display->display_options['fields']['time_stamp']['field'] = 'time_stamp';
  $handler->display->display_options['fields']['time_stamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['time_stamp']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Credits Transaction: Operation */
  $handler->display->display_options['fields']['operation']['id'] = 'operation';
  $handler->display->display_options['fields']['operation']['table'] = 'emh_points_txn';
  $handler->display->display_options['fields']['operation']['field'] = 'operation';
  /* Field: Credits Transaction: Context */
  $handler->display->display_options['fields']['context']['id'] = 'operation';
  $handler->display->display_options['fields']['context']['table'] = 'emh_points_txn';
  $handler->display->display_options['fields']['context']['field'] = 'context';
  /* Field: Credits Transaction: Source type */
  $handler->display->display_options['fields']['source_type']['id'] = 'source_type';
  $handler->display->display_options['fields']['source_type']['table'] = 'emh_points_txn';
  $handler->display->display_options['fields']['source_type']['field'] = 'source_type';
  /* Field: Credits Transaction: Source ID */
  $handler->display->display_options['fields']['source_id']['id'] = 'source_id';
  $handler->display->display_options['fields']['source_id']['table'] = 'emh_points_txn';
  $handler->display->display_options['fields']['source_id']['field'] = 'source_id';
  /* Field: Credits Transaction: Destination type */
  $handler->display->display_options['fields']['dest_type']['id'] = 'dest_type';
  $handler->display->display_options['fields']['dest_type']['table'] = 'emh_points_txn';
  $handler->display->display_options['fields']['dest_type']['field'] = 'dest_type';
  /* Field: Credits Transaction: Destination ID */
  $handler->display->display_options['fields']['dest_id']['id'] = 'dest_id';
  $handler->display->display_options['fields']['dest_id']['table'] = 'emh_points_txn';
  $handler->display->display_options['fields']['dest_id']['field'] = 'dest_id';
  /* Field: Credits Transaction: Credits */
  $handler->display->display_options['fields']['points']['id'] = 'points';
  $handler->display->display_options['fields']['points']['table'] = 'emh_points_txn';
  $handler->display->display_options['fields']['points']['field'] = 'points';
  /* Field: Credits Transaction: Description of the transaction */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'emh_points_txn';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  /* Sort criterion: Credits Transaction: Timestamp */
  $handler->display->display_options['sorts']['time_stamp']['id'] = 'time_stamp';
  $handler->display->display_options['sorts']['time_stamp']['table'] = 'emh_points_txn';
  $handler->display->display_options['sorts']['time_stamp']['field'] = 'time_stamp';
  $handler->display->display_options['sorts']['time_stamp']['order'] = 'DESC';
  /* Filter criterion: Credits Transaction: Source type */
  $handler->display->display_options['filters']['source_type']['id'] = 'source_type';
  $handler->display->display_options['filters']['source_type']['table'] = 'emh_points_txn';
  $handler->display->display_options['filters']['source_type']['field'] = 'source_type';
  $handler->display->display_options['filters']['source_type']['group'] = 1;
  $handler->display->display_options['filters']['source_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['source_type']['expose']['operator_id'] = 'source_type_op';
  $handler->display->display_options['filters']['source_type']['expose']['label'] = 'Source type';
  $handler->display->display_options['filters']['source_type']['expose']['operator'] = 'source_type_op';
  $handler->display->display_options['filters']['source_type']['expose']['identifier'] = 'source_type';
  /* Filter criterion: Credits Transaction: Destination type */
  $handler->display->display_options['filters']['dest_type']['id'] = 'dest_type';
  $handler->display->display_options['filters']['dest_type']['table'] = 'emh_points_txn';
  $handler->display->display_options['filters']['dest_type']['field'] = 'dest_type';
  $handler->display->display_options['filters']['dest_type']['group'] = 1;
  $handler->display->display_options['filters']['dest_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['dest_type']['expose']['operator_id'] = 'dest_type_op';
  $handler->display->display_options['filters']['dest_type']['expose']['label'] = 'Destination type';
  $handler->display->display_options['filters']['dest_type']['expose']['operator'] = 'dest_type_op';
  $handler->display->display_options['filters']['dest_type']['expose']['identifier'] = 'dest_type';
  /* Filter criterion: Credits Transaction: Context */
  $handler->display->display_options['filters']['context']['id'] = 'context';
  $handler->display->display_options['filters']['context']['table'] = 'emh_points_txn';
  $handler->display->display_options['filters']['context']['field'] = 'context';
  $handler->display->display_options['filters']['context']['operator'] = 'contains';
  $handler->display->display_options['filters']['context']['group'] = 1;
  $handler->display->display_options['filters']['context']['exposed'] = TRUE;
  $handler->display->display_options['filters']['context']['expose']['operator_id'] = 'context_op';
  $handler->display->display_options['filters']['context']['expose']['label'] = 'Context';
  $handler->display->display_options['filters']['context']['expose']['operator'] = 'context_op';
  $handler->display->display_options['filters']['context']['expose']['identifier'] = 'context';
  /* Filter criterion: Credits Transaction: Timestamp */
  $handler->display->display_options['filters']['time_stamp']['id'] = 'time_stamp';
  $handler->display->display_options['filters']['time_stamp']['table'] = 'emh_points_txn';
  $handler->display->display_options['filters']['time_stamp']['field'] = 'time_stamp';
  $handler->display->display_options['filters']['time_stamp']['operator'] = 'between';
  $handler->display->display_options['filters']['time_stamp']['group'] = 1;
  $handler->display->display_options['filters']['time_stamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['time_stamp']['expose']['operator_id'] = 'time_stamp_op';
  $handler->display->display_options['filters']['time_stamp']['expose']['label'] = 'Timestamp';
  $handler->display->display_options['filters']['time_stamp']['expose']['operator'] = 'time_stamp_op';
  $handler->display->display_options['filters']['time_stamp']['expose']['identifier'] = 'time_stamp';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'IDs';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'source_id' => 'source_id',
    'dest_id' => 'dest_id',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/emindhub/credits/transaction-log';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Transaction Log';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'give_user_points';
  $view->description = '';
  $view->tag = 'EMH, credits';
  $view->base_table = 'users';
  $view->human_name = 'Give user credits';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Give user credits';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer credits';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'name' => 'name',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'total_points' => 'total_points',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'total_points' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::emh_points_give_points' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Give credits',
    ),
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Full name';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_first_name] [field_last_name]';
  /* Field: Credits: Total Credits */
  $handler->display->display_options['fields']['total_points']['id'] = 'total_points';
  $handler->display->display_options['fields']['total_points']['table'] = 'emh_points_total';
  $handler->display->display_options['fields']['total_points']['field'] = 'total_points';
/* Field: User: Uid */
  $handler->display->display_options['fields']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['fields']['uid_1']['table'] = 'users';
  $handler->display->display_options['fields']['uid_1']['field'] = 'uid';
  $handler->display->display_options['fields']['uid_1']['label'] = 'Source history';
  $handler->display->display_options['fields']['uid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid_1']['alter']['text'] = 'Source';
  $handler->display->display_options['fields']['uid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['uid_1']['alter']['path'] = 'user/[uid_1]/history_source';
  $handler->display->display_options['fields']['uid_1']['link_to_user'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid_2']['id'] = 'uid_2';
  $handler->display->display_options['fields']['uid_2']['table'] = 'users';
  $handler->display->display_options['fields']['uid_2']['field'] = 'uid';
  $handler->display->display_options['fields']['uid_2']['label'] = 'Destination history';
  $handler->display->display_options['fields']['uid_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid_2']['alter']['text'] = 'Destination';
  $handler->display->display_options['fields']['uid_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['uid_2']['alter']['path'] = 'user/[uid_2]/history_dest';
  $handler->display->display_options['fields']['uid_2']['link_to_user'] = FALSE;
  /* Sort criterion: User: Uid */
  $handler->display->display_options['sorts']['uid']['id'] = 'uid';
  $handler->display->display_options['sorts']['uid']['table'] = 'users';
  $handler->display->display_options['sorts']['uid']['field'] = 'uid';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/emindhub/credits/give-user-credits';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Give user credits';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'og_points_repartition';
  $view->description = '';
  $view->tag = 'EMH, credits';
  $view->base_table = 'users';
  $view->human_name = 'OG Arrange Credits';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Distribute credits';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::emh_points_arrange_group_points' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Full name';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_first_name] [field_last_name]';
  /* Field: Credits: Total Credits */
  $handler->display->display_options['fields']['total_points']['id'] = 'total_points';
  $handler->display->display_options['fields']['total_points']['table'] = 'emh_points_total';
  $handler->display->display_options['fields']['total_points']['field'] = 'total_points';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/credits-repartition';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Distribute credits';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'answers';
  $view->description = '';
  $view->tag = 'EMH, credits';
  $view->base_table = 'comment';
  $view->human_name = 'Question / Challenge answers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Answers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'cid' => 'cid',
    'type' => 'type',
    'uid' => 'uid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_first_name',
    'views_bulk_operations' => 'views_bulk_operations',
    'created' => 'created',
    'nothing' => 'nothing',
    'comment_body' => 'comment_body',
    'field_private_comment_body' => 'field_private_comment_body',
    'nothing_1' => 'nothing_1',
    'comment_body_1' => 'comment_body_1',
    'views_conditional' => 'views_conditional',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'cid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_private_comment_body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_body_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_conditional' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Relationship: Comment: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Relationship: Comment: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'comment';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Comment */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'comment';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::emh_points_arrange_node_points' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Distribute credits',
    ),
  );
  /* Field: Comment: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'comment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Answer date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short_date';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Comment: EMH Author */
  $handler->display->display_options['fields']['emh_author']['id'] = 'emh_author';
  $handler->display->display_options['fields']['emh_author']['table'] = 'comment';
  $handler->display->display_options['fields']['emh_author']['field'] = 'emh_author';
  $handler->display->display_options['fields']['emh_author']['label'] = 'Author';
  /* Field: Comment: Answer */
  $handler->display->display_options['fields']['emh_answer']['id'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['table'] = 'comment';
  $handler->display->display_options['fields']['emh_answer']['field'] = 'emh_answer';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = '%1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'question1' => 'question1',
    'challenge' => 'challenge',
  );
  /* Filter criterion: Comment: Approved */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_node']['id'] = 'status_node';
  $handler->display->display_options['filters']['status_node']['table'] = 'node';
  $handler->display->display_options['filters']['status_node']['field'] = 'status';
  $handler->display->display_options['filters']['status_node']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_node']['value'] = 1;
  $handler->display->display_options['filters']['status_node']['group'] = 1;
  $handler->display->display_options['filters']['status_node']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/answers';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Answers';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views[$view->name] = $view;

  // Return all views
  return $views;
}

/**
 * Implements hook_views_default_views_alter().
 * @ingroup views
 */
function emh_points_views_default_views_alter(&$views) {
  if (isset($views['webform_results'])) {
    $view = new view();
    $view->name = 'webform_results';
    $view->description = '';
    $view->tag = 'webform';
    $view->base_table = 'webform_submissions';
    $view->human_name = 'Mission answers';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'none';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '50';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['pager']['options']['id'] = '0';
    $handler->display->display_options['pager']['options']['quantity'] = '9';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 50, 100, 200, 500, 1000';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
    $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = 'All';
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
      'views_bulk_operations' => 'views_bulk_operations',
      'submitted' => 'submitted',
      'field_first_name' => 'field_first_name',
      'field_last_name' => 'field_last_name',
      'view_user' => 'view_user',
      'emh_answer' => 'emh_answer',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
      'views_bulk_operations' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'submitted' => array(
        'sortable' => 1,
        'default_sort_order' => 'desc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_first_name' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'field_last_name' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'view_user' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'emh_answer' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
    $handler->display->display_options['style_options']['sticky'] = TRUE;
    $handler->display->display_options['style_options']['empty_table'] = TRUE;
    /* No results behavior: Global: Unfiltered text */
    $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
    $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
    $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
    $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
    $handler->display->display_options['empty']['area_text_custom']['content'] = 'There are no answers for this mission.';
    $handler->display->display_options['empty']['area_text_custom']['tokenize'] = TRUE;
    /* Relationship: Webform submissions: User */
    $handler->display->display_options['relationships']['uid']['id'] = 'uid';
    $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
    $handler->display->display_options['relationships']['uid']['field'] = 'uid';
    /* Field: Bulk operations: Webform submissions */
    $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
    $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'webform_submissions';
    $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
    $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
    $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
    $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
    $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
    $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
    $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
    $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
      'action::emh_points_arrange_node_points' => array(
        'selected' => 1,
        'skip_confirmation' => 1,
        'override_label' => 1,
        'label' => 'Distribute credits',
      ),
    );
    /* Field: Webform submissions: Submitted */
    $handler->display->display_options['fields']['submitted']['id'] = 'submitted';
    $handler->display->display_options['fields']['submitted']['table'] = 'webform_submissions';
    $handler->display->display_options['fields']['submitted']['field'] = 'submitted';
    $handler->display->display_options['fields']['submitted']['label'] = 'Answer date';
    $handler->display->display_options['fields']['submitted']['date_format'] = 'short_date';
    $handler->display->display_options['fields']['submitted']['second_date_format'] = 'long';
    /* Field: Webform submissions: EMH Author */
    $handler->display->display_options['fields']['emh_author']['id'] = 'emh_author';
    $handler->display->display_options['fields']['emh_author']['table'] = 'webform_submissions';
    $handler->display->display_options['fields']['emh_author']['field'] = 'emh_author';
    $handler->display->display_options['fields']['emh_author']['label'] = 'Author';
    /* Field: Webform submissions: Answer */
    $handler->display->display_options['fields']['emh_answer']['id'] = 'emh_answer';
    $handler->display->display_options['fields']['emh_answer']['table'] = 'webform_submissions';
    $handler->display->display_options['fields']['emh_answer']['field'] = 'emh_answer';
    /* Contextual filter: Webform submissions: Node */
    $handler->display->display_options['arguments']['nid']['id'] = 'nid';
    $handler->display->display_options['arguments']['nid']['table'] = 'webform_submissions';
    $handler->display->display_options['arguments']['nid']['field'] = 'nid';
    $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
    $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
    $handler->display->display_options['arguments']['nid']['title'] = '%1';
    $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
    $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
    $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
      'webform' => 'webform',
    );
    /* Filter criterion: Webform submissions: Draft */
    $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
    $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
    $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
    $handler->display->display_options['filters']['is_draft']['value'] = array(
      0 => '0',
    );

    /* Display: Page */
    $handler = $view->new_display('page', 'Page', 'page_1');
    $handler->display->display_options['path'] = 'node/%/results';
    $handler->display->display_options['menu']['type'] = 'tab';
    $handler->display->display_options['menu']['title'] = 'Answers';
    $handler->display->display_options['menu']['weight'] = '10';
    $handler->display->display_options['menu']['name'] = 'main-menu';
    $handler->display->display_options['menu']['context'] = 0;
    $handler->display->display_options['menu']['context_only_inline'] = 0;

    $views['webform_results'] = $view;
  }
}
