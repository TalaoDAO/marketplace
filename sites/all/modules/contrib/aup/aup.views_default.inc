<?php
/**
 * @file
 * aup.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function aup_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'answers_user_reputation';
  $view->description = 'Show a listing of Answers Reputation transactions in each user\'s profile';
  $view->tag = 'default';
  $view->base_table = 'userpoints_txn';
  $view->human_name = 'Answers User Reputation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Answers User Reputation';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'points' => 'points',
    'operation' => 'operation',
    'description' => 'description',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'points' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
    ),
    'operation' => array(
      'align' => 'views-align-center',
      'separator' => '',
    ),
    'description' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = FALSE;
  $handler->display->display_options['footer']['area']['content'] = '<?php
$view = views_get_current_view();
$uid = $view->args[0];
$terms = taxonomy_get_term_by_name(\'Answers Reputation\');
$term = array_shift($terms);
$tid = $term->tid;
$points = userpoints_get_current_points($uid, $tid);
return(\'You have a total of \' . $points . \' reputation points.\');
?>';
  $handler->display->display_options['footer']['area']['format'] = 'php_code';
  $handler->display->display_options['footer']['area']['tokenize'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results behavior';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<em>You have not yet earned any reputation points ...</em>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Userpoints Transactions: Entity ID */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'userpoints_txn';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['entity_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['entity_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['entity_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['entity_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['entity_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['entity_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['entity_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['entity_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['entity_id']['hide_alter_empty'] = 0;
  /* Field: Userpoints Transactions: Timestamp */
  $handler->display->display_options['fields']['time_stamp']['id'] = 'time_stamp';
  $handler->display->display_options['fields']['time_stamp']['table'] = 'userpoints_txn';
  $handler->display->display_options['fields']['time_stamp']['field'] = 'time_stamp';
  $handler->display->display_options['fields']['time_stamp']['label'] = 'Date';
  $handler->display->display_options['fields']['time_stamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['time_stamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['time_stamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['time_stamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['time_stamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['time_stamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['time_stamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['time_stamp']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['time_stamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['time_stamp']['custom_date_format'] = 'M j, Y';
  /* Field: Userpoints Transactions: Operation */
  $handler->display->display_options['fields']['operation']['id'] = 'operation';
  $handler->display->display_options['fields']['operation']['table'] = 'userpoints_txn';
  $handler->display->display_options['fields']['operation']['field'] = 'operation';
  $handler->display->display_options['fields']['operation']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['operation']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['operation']['alter']['path'] = 'node/[entity_id]';
  $handler->display->display_options['fields']['operation']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['operation']['alter']['external'] = 0;
  $handler->display->display_options['fields']['operation']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['operation']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['operation']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['operation']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['operation']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['operation']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['operation']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['operation']['alter']['html'] = 0;
  $handler->display->display_options['fields']['operation']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['operation']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['operation']['hide_empty'] = 0;
  $handler->display->display_options['fields']['operation']['empty_zero'] = 0;
  $handler->display->display_options['fields']['operation']['hide_alter_empty'] = 0;
  /* Field: Userpoints Transactions: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'userpoints_txn';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 0;
  /* Field: Userpoints Transactions: Points */
  $handler->display->display_options['fields']['points']['id'] = 'points';
  $handler->display->display_options['fields']['points']['table'] = 'userpoints_txn';
  $handler->display->display_options['fields']['points']['field'] = 'points';
  /* Sort criterion: Userpoints Transactions: Timestamp */
  $handler->display->display_options['sorts']['time_stamp']['id'] = 'time_stamp';
  $handler->display->display_options['sorts']['time_stamp']['table'] = 'userpoints_txn';
  $handler->display->display_options['sorts']['time_stamp']['field'] = 'time_stamp';
  $handler->display->display_options['sorts']['time_stamp']['order'] = 'DESC';
  /* Contextual filter: Userpoints Transactions: User */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'userpoints_txn';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/questions/reputation';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Reputation';
  $handler->display->display_options['menu']['description'] = 'Transactions which affect the user\'s reputation';
  $handler->display->display_options['menu']['weight'] = '30';
  $export['answers_user_reputation'] = $view;

  return $export;
}
