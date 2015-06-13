<?php
/**
 * @file
 * Default administrative views provided by Entity Legal.
 */

/**
 * Implements hook_views_default_views().
 */
function entity_legal_views_default_views() {
  $view = new view();
  $view->name = 'legal_document_acceptances';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'entity_legal_document_acceptance';
  $view->human_name = 'Legal document acceptances';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Legal document acceptances';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer entity legal';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'document_version_name' => 'document_version_name',
    'name' => 'name',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'document_version_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
  );
  /* Relationship: Legal document acceptance: Entity legal document version */
  $handler->display->display_options['relationships']['document_version_name']['id'] = 'document_version_name';
  $handler->display->display_options['relationships']['document_version_name']['table'] = 'entity_legal_document_acceptance';
  $handler->display->display_options['relationships']['document_version_name']['field'] = 'document_version_name';
  $handler->display->display_options['relationships']['document_version_name']['label'] = 'Version name';
  /* Relationship: Legal document acceptance: The user who accepted */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'entity_legal_document_acceptance';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Legal document version: The document associated with the version */
  $handler->display->display_options['relationships']['document_name']['id'] = 'document_name';
  $handler->display->display_options['relationships']['document_name']['table'] = 'entity_legal_document_version';
  $handler->display->display_options['relationships']['document_name']['field'] = 'document_name';
  $handler->display->display_options['relationships']['document_name']['relationship'] = 'document_version_name';
  /* Field: Legal document acceptance: Document_version_name */
  $handler->display->display_options['fields']['document_version_name']['id'] = 'document_version_name';
  $handler->display->display_options['fields']['document_version_name']['table'] = 'entity_legal_document_acceptance';
  $handler->display->display_options['fields']['document_version_name']['field'] = 'document_version_name';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Legal document version: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entity_legal_document_version';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'document_version_name';
  $handler->display->display_options['fields']['created']['label'] = 'Accepted';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Contextual filter: Legal document version: Document_name */
  $handler->display->display_options['arguments']['document_name']['id'] = 'document_name';
  $handler->display->display_options['arguments']['document_name']['table'] = 'entity_legal_document_version';
  $handler->display->display_options['arguments']['document_name']['field'] = 'document_name';
  $handler->display->display_options['arguments']['document_name']['relationship'] = 'document_version_name';
  $handler->display->display_options['arguments']['document_name']['default_action'] = 'access denied';
  $handler->display->display_options['arguments']['document_name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['document_name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['document_name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['document_name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['document_name']['limit'] = '0';
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'User name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/structure/legal/manage/%/acceptances';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Acceptances';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  // Return the view.
  $views['legal_document_acceptances'] = $view;
  return $views;
}
