<?php
/**
 * @file
 * Default Views for answers management.
 */


/**
 * Implements hook_views_default_views().
 * @ingroup views
 */
function emh_request_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'answers_test';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'emh_answer';
  $view->human_name = 'Answers';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  /* Field: Answer: Request type */
  $handler->display->display_options['fields']['request_type']['id'] = 'request_type';
  $handler->display->display_options['fields']['request_type']['table'] = 'emh_answer';
  $handler->display->display_options['fields']['request_type']['field'] = 'request_type';
  $handler->display->display_options['fields']['request_type']['label'] = 'Type';
  /* Field: Answer: Request title */
  $handler->display->display_options['fields']['request_title']['id'] = 'request_title';
  $handler->display->display_options['fields']['request_title']['table'] = 'emh_answer';
  $handler->display->display_options['fields']['request_title']['field'] = 'request_title';
  $handler->display->display_options['fields']['request_title']['label'] = 'Request';
  /* Field: Answer: Date */
  $handler->display->display_options['fields']['creation_date']['id'] = 'creation_date';
  $handler->display->display_options['fields']['creation_date']['table'] = 'emh_answer';
  $handler->display->display_options['fields']['creation_date']['field'] = 'creation_date';
  $handler->display->display_options['fields']['creation_date']['label'] = 'Answer date';
  /* Field: Answer: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'emh_answer';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Answer';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'answers';

  $views[$view->name] = $view;

  return $views;
}