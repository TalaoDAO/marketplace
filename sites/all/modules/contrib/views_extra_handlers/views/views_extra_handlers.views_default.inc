<?php
// $Id$
/**
 * @file
 * Contains default views on behalf of the views_extra_handlers module.
 */

/**
 * Implementation of hook_default_view_views().
 */
function views_extra_handlers_views_default_views() {
$view = new view;
$view->name = 'node_types_defaults';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node_type';
$view->human_name = 'node_types';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = TRUE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'node_types';
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Node Type: type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node_type';
$handler->display->display_options['fields']['type']['field'] = 'type';
$handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['type']['alter']['external'] = 0;
$handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['type']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['type']['alter']['trim'] = 0;
$handler->display->display_options['fields']['type']['alter']['html'] = 0;
$handler->display->display_options['fields']['type']['element_label_colon'] = 1;
$handler->display->display_options['fields']['type']['element_default_classes'] = 1;
$handler->display->display_options['fields']['type']['hide_empty'] = 0;
$handler->display->display_options['fields']['type']['empty_zero'] = 0;
$handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
/* Field: Node Type: Body */
$handler->display->display_options['fields']['description']['id'] = 'description';
$handler->display->display_options['fields']['description']['table'] = 'node_type';
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
$handler->display->display_options['fields']['description']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['description']['alter']['trim'] = 0;
$handler->display->display_options['fields']['description']['alter']['html'] = 0;
$handler->display->display_options['fields']['description']['element_label_colon'] = 1;
$handler->display->display_options['fields']['description']['element_default_classes'] = 1;
$handler->display->display_options['fields']['description']['hide_empty'] = 0;
$handler->display->display_options['fields']['description']['empty_zero'] = 0;
$handler->display->display_options['fields']['description']['hide_alter_empty'] = 1;
/* Field: Node Type: name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'node_type';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['name']['alter']['external'] = 0;
$handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['name']['alter']['trim'] = 0;
$handler->display->display_options['fields']['name']['alter']['html'] = 0;
$handler->display->display_options['fields']['name']['element_label_colon'] = 1;
$handler->display->display_options['fields']['name']['element_default_classes'] = 1;
$handler->display->display_options['fields']['name']['hide_empty'] = 0;
$handler->display->display_options['fields']['name']['empty_zero'] = 0;
$handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'node-types';



$views[$view->name] = $view;


$view = new view;
$view->name = 'fields_info_defaults';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'field_config_instance';
$view->human_name = 'fields_info';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'fields_info';
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'bundle',
    'rendered' => 1,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['style_options']['columns'] = array(
  'id' => 'id',
  'bundle' => 'bundle',
  'entity_type' => 'entity_type',
  'field_id' => 'field_id',
  'field_name' => 'field_name',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'bundle' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'entity_type' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['override'] = 1;
$handler->display->display_options['style_options']['sticky'] = 0;
$handler->display->display_options['style_options']['empty_table'] = 0;
/* Field: Fields: ID */
$handler->display->display_options['fields']['id']['id'] = 'id';
$handler->display->display_options['fields']['id']['table'] = 'field_config_instance';
$handler->display->display_options['fields']['id']['field'] = 'id';
/* Field: Fields: bundle */
$handler->display->display_options['fields']['bundle']['id'] = 'bundle';
$handler->display->display_options['fields']['bundle']['table'] = 'field_config_instance';
$handler->display->display_options['fields']['bundle']['field'] = 'bundle';
$handler->display->display_options['fields']['bundle']['label'] = '';
$handler->display->display_options['fields']['bundle']['exclude'] = TRUE;
$handler->display->display_options['fields']['bundle']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['bundle']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['bundle']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['bundle']['alter']['external'] = 0;
$handler->display->display_options['fields']['bundle']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['bundle']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['bundle']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['bundle']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['bundle']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['bundle']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['bundle']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['bundle']['alter']['trim'] = 0;
$handler->display->display_options['fields']['bundle']['alter']['html'] = 0;
$handler->display->display_options['fields']['bundle']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['bundle']['element_default_classes'] = 1;
$handler->display->display_options['fields']['bundle']['hide_empty'] = 0;
$handler->display->display_options['fields']['bundle']['empty_zero'] = 0;
$handler->display->display_options['fields']['bundle']['hide_alter_empty'] = 1;
/* Field: Fields: entity_type */
$handler->display->display_options['fields']['entity_type']['id'] = 'entity_type';
$handler->display->display_options['fields']['entity_type']['table'] = 'field_config_instance';
$handler->display->display_options['fields']['entity_type']['field'] = 'entity_type';
$handler->display->display_options['fields']['entity_type']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['entity_type']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['entity_type']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['entity_type']['alter']['external'] = 0;
$handler->display->display_options['fields']['entity_type']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['entity_type']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['entity_type']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['entity_type']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['entity_type']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['entity_type']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['entity_type']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['entity_type']['alter']['trim'] = 0;
$handler->display->display_options['fields']['entity_type']['alter']['html'] = 0;
$handler->display->display_options['fields']['entity_type']['element_label_colon'] = 1;
$handler->display->display_options['fields']['entity_type']['element_default_classes'] = 1;
$handler->display->display_options['fields']['entity_type']['hide_empty'] = 0;
$handler->display->display_options['fields']['entity_type']['empty_zero'] = 0;
$handler->display->display_options['fields']['entity_type']['hide_alter_empty'] = 1;
/* Field: Fields: field_id */
$handler->display->display_options['fields']['field_id']['id'] = 'field_id';
$handler->display->display_options['fields']['field_id']['table'] = 'field_config_instance';
$handler->display->display_options['fields']['field_id']['field'] = 'field_id';
$handler->display->display_options['fields']['field_id']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_id']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_id']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_id']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_id']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_id']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_id']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_id']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_id']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_id']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['field_id']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_id']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_id']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_id']['element_label_colon'] = 1;
$handler->display->display_options['fields']['field_id']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_id']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_id']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_id']['hide_alter_empty'] = 1;
$handler->display->display_options['fields']['field_id']['separator'] = '';
$handler->display->display_options['fields']['field_id']['format_plural'] = 0;
/* Field: Fields: field_name */
$handler->display->display_options['fields']['field_name']['id'] = 'field_name';
$handler->display->display_options['fields']['field_name']['table'] = 'field_config_instance';
$handler->display->display_options['fields']['field_name']['field'] = 'field_name';
$handler->display->display_options['fields']['field_name']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_name']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_name']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_name']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_name']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_name']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_name']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_name']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_name']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_name']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['field_name']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_name']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_name']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_name']['element_label_colon'] = 1;
$handler->display->display_options['fields']['field_name']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_name']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_name']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_name']['hide_alter_empty'] = 1;
/* Field: Fields: Widget */
$handler->display->display_options['fields']['data_widget']['id'] = 'data_widget';
$handler->display->display_options['fields']['data_widget']['table'] = 'field_config_instance';
$handler->display->display_options['fields']['data_widget']['field'] = 'data_widget';
$handler->display->display_options['fields']['data_widget']['label'] = 'Widget Type';
$handler->display->display_options['fields']['data_widget']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['data_widget']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['data_widget']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['data_widget']['alter']['external'] = 0;
$handler->display->display_options['fields']['data_widget']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['data_widget']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['data_widget']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['data_widget']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['data_widget']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['data_widget']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['data_widget']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['data_widget']['alter']['trim'] = 0;
$handler->display->display_options['fields']['data_widget']['alter']['html'] = 0;
$handler->display->display_options['fields']['data_widget']['element_label_colon'] = 0;
$handler->display->display_options['fields']['data_widget']['element_default_classes'] = 1;
$handler->display->display_options['fields']['data_widget']['hide_empty'] = 0;
$handler->display->display_options['fields']['data_widget']['empty_zero'] = 0;
$handler->display->display_options['fields']['data_widget']['hide_alter_empty'] = 1;
/* Filter criterion: Fields: entity_type */
$handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
$handler->display->display_options['filters']['entity_type']['table'] = 'field_config_instance';
$handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
$handler->display->display_options['filters']['entity_type']['value'] = 'node';
/* Filter criterion: Fields: Widget */
$handler->display->display_options['filters']['data_widget']['id'] = 'data_widget';
$handler->display->display_options['filters']['data_widget']['table'] = 'field_config_instance';
$handler->display->display_options['filters']['data_widget']['field'] = 'data_widget';
$handler->display->display_options['filters']['data_widget']['value'] = 'text_textarea_with_summary';
$handler->display->display_options['filters']['data_widget']['expose']['operator_id'] = 'data_widget_op';
$handler->display->display_options['filters']['data_widget']['expose']['label'] = 'Widget';
$handler->display->display_options['filters']['data_widget']['expose']['use_operator'] = FALSE;
$handler->display->display_options['filters']['data_widget']['expose']['operator'] = 'data_widget_op';
$handler->display->display_options['filters']['data_widget']['expose']['identifier'] = 'data_widget';
$handler->display->display_options['filters']['data_widget']['expose']['required'] = FALSE;
$handler->display->display_options['filters']['data_widget']['expose']['remember'] = FALSE;
$handler->display->display_options['filters']['data_widget']['expose']['multiple'] = FALSE;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'fields-info';

$views[$view->name] = $view;

return $views;
}
