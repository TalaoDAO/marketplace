<?php
// $Id: comment_publish.views_default.inc,v 1.1.2.2.2.2 2010/10/20 15:18:26 elliottf Exp $

/**
 * @file
 *
 * Default views for the comment_publish module.
 *
 * @author: Elliott Foster
 * @copyright: NewMBC 2010
 */

/**
 * Implements hook_views_default_views().
 */
function comment_publish_views_default_views() {
  $views = array();

  $view = new view;
  $view->name = 'comment_publish';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'comment';
  $view->is_cacheable = FALSE;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
  'subject' => 'subject',
  'name' => 'name',
  'created' => 'created',
  'status' => 'status',
  'publish_comment' => 'publish_comment',
);
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
  'subject' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'name' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'created' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'status' => array(
    'sortable' => 1,
    'align' => '',
    'separator' => '',
  ),
  'publish_comment' => array(
    'align' => '',
    'separator' => '',
  ),
);
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Relationship: Comment: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = 0;
  /* Field: Comment: Title */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['subject']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['subject']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['html'] = 0;
  $handler->display->display_options['fields']['subject']['hide_empty'] = 0;
  $handler->display->display_options['fields']['subject']['empty_zero'] = 0;
  $handler->display->display_options['fields']['subject']['link_to_comment'] = 1;
  /* Field: Comment: Author */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'comment';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  /* Field: Comment: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'comment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  /* Field: Comment: In moderation */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'comment';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Comment: Comment (un)publish link */
  $handler->display->display_options['fields']['publish_comment']['id'] = 'publish_comment';
  $handler->display->display_options['fields']['publish_comment']['table'] = 'comment_publish';
  $handler->display->display_options['fields']['publish_comment']['field'] = 'publish_comment';
  $handler->display->display_options['fields']['publish_comment']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['publish_comment']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['publish_comment']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['publish_comment']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['publish_comment']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['publish_comment']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['publish_comment']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['publish_comment']['alter']['html'] = 0;
  $handler->display->display_options['fields']['publish_comment']['hide_empty'] = 0;
  $handler->display->display_options['fields']['publish_comment']['empty_zero'] = 0;
  $handler->display->display_options['fields']['publish_comment']['comment_publish_format'] = '0';
  /* Argument: Node: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'node/%/comment_publish';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Comments';
  $handler->display->display_options['menu']['weight'] = '0';

  $views[$view->name] = $view;

  return $views;
}

