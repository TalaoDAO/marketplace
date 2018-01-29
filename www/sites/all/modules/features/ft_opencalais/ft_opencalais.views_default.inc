<?php
/**
 * @file
 * ft_opencalais.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ft_opencalais_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'open_calais_log';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'log';
  $view->human_name = 'open-calais-log';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'open-calais-log';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_body_request' => 'field_body_request',
    'field_request' => 'field_request',
    'field_nb_tags' => 'field_nb_tags',
    'field_tags_opencalais' => 'field_tags_opencalais',
    'timestamp' => 'timestamp',
    'url' => 'url',
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
    'field_body_request' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_request' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_nb_tags' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tags_opencalais' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'url' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 0,
    'bordered' => 0,
    'hover' => 0,
    'condensed' => 0,
  );
  /* Field: Log: Log ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'log';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Log: Body Request */
  $handler->display->display_options['fields']['field_body_request']['id'] = 'field_body_request';
  $handler->display->display_options['fields']['field_body_request']['table'] = 'field_data_field_body_request';
  $handler->display->display_options['fields']['field_body_request']['field'] = 'field_body_request';
  /* Field: Log: Request nid */
  $handler->display->display_options['fields']['field_request']['id'] = 'field_request';
  $handler->display->display_options['fields']['field_request']['table'] = 'field_data_field_request';
  $handler->display->display_options['fields']['field_request']['field'] = 'field_request';
  $handler->display->display_options['fields']['field_request']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Log: Number of tags  */
  $handler->display->display_options['fields']['field_nb_tags']['id'] = 'field_nb_tags';
  $handler->display->display_options['fields']['field_nb_tags']['table'] = 'field_data_field_nb_tags';
  $handler->display->display_options['fields']['field_nb_tags']['field'] = 'field_nb_tags';
  $handler->display->display_options['fields']['field_nb_tags']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Log: Number of tags submitted */
  $handler->display->display_options['fields']['field_nb_tags_submitted']['id'] = 'field_nb_tags_submitted';
  $handler->display->display_options['fields']['field_nb_tags_submitted']['table'] = 'field_data_field_nb_tags_submitted';
  $handler->display->display_options['fields']['field_nb_tags_submitted']['field'] = 'field_nb_tags_submitted';
  $handler->display->display_options['fields']['field_nb_tags_submitted']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Log: Opencalais tags  */
  $handler->display->display_options['fields']['field_tags_opencalais']['id'] = 'field_tags_opencalais';
  $handler->display->display_options['fields']['field_tags_opencalais']['table'] = 'field_data_field_tags_opencalais';
  $handler->display->display_options['fields']['field_tags_opencalais']['field'] = 'field_tags_opencalais';
  /* Field: Log: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'log';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'long';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: Log: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_log';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Log: Mode to generate the tags */
  $handler->display->display_options['fields']['field_mode_generate_tags']['id'] = 'field_mode_generate_tags';
  $handler->display->display_options['fields']['field_mode_generate_tags']['table'] = 'field_data_field_mode_generate_tags';
  $handler->display->display_options['fields']['field_mode_generate_tags']['field'] = 'field_mode_generate_tags';
  /* Filter criterion: Log: Log type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'log';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'log_opencalais' => 'log_opencalais',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'open-calais-log';
  $export['open_calais_log'] = $view;

  return $export;
}
