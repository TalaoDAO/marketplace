<?php
/**
 * @file
 * ft_public_request.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ft_public_request_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'open_requests';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Open requests';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Open requests';
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'Access the latest client requests';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Access the latest client requests';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Field: Content: Request reference */
  $handler->display->display_options['fields']['field_prequest_reference']['id'] = 'field_prequest_reference';
  $handler->display->display_options['fields']['field_prequest_reference']['table'] = 'field_data_field_prequest_reference';
  $handler->display->display_options['fields']['field_prequest_reference']['field'] = 'field_prequest_reference';
  $handler->display->display_options['fields']['field_prequest_reference']['label'] = '';
  $handler->display->display_options['fields']['field_prequest_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_prequest_reference']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_prequest_reference']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Choose a request type */
  $handler->display->display_options['fields']['field_request_type']['id'] = 'field_request_type';
  $handler->display->display_options['fields']['field_request_type']['table'] = 'field_data_field_request_type';
  $handler->display->display_options['fields']['field_request_type']['field'] = 'field_request_type';
  $handler->display->display_options['fields']['field_request_type']['label'] = '';
  $handler->display->display_options['fields']['field_request_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_request_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_request_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Domain(s) */
  $handler->display->display_options['fields']['field_domaine']['id'] = 'field_domaine';
  $handler->display->display_options['fields']['field_domaine']['table'] = 'field_data_field_domaine';
  $handler->display->display_options['fields']['field_domaine']['field'] = 'field_domaine';
  $handler->display->display_options['fields']['field_domaine']['label'] = '';
  $handler->display->display_options['fields']['field_domaine']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_domaine']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_domaine']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_domaine']['delta_offset'] = '0';
  /* Field: Content: Sticky */
  $handler->display->display_options['fields']['sticky']['id'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['table'] = 'node';
  $handler->display->display_options['fields']['sticky']['field'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['label'] = '';
  $handler->display->display_options['fields']['sticky']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sticky']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['sticky']['type'] = 'custom';
  $handler->display->display_options['fields']['sticky']['type_custom_true'] = 'Urgent';
  $handler->display->display_options['fields']['sticky']['not'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '400',
  );
  /* Field: Content: Confidential */
  $handler->display->display_options['fields']['field_prequest_confidential']['id'] = 'field_prequest_confidential';
  $handler->display->display_options['fields']['field_prequest_confidential']['table'] = 'field_data_field_prequest_confidential';
  $handler->display->display_options['fields']['field_prequest_confidential']['field'] = 'field_prequest_confidential';
  $handler->display->display_options['fields']['field_prequest_confidential']['label'] = '';
  $handler->display->display_options['fields']['field_prequest_confidential']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_prequest_confidential']['element_default_classes'] = FALSE;
  /* Field: Content: Circle */
  $handler->display->display_options['fields']['field_prequest_circles']['id'] = 'field_prequest_circles';
  $handler->display->display_options['fields']['field_prequest_circles']['table'] = 'field_data_field_prequest_circles';
  $handler->display->display_options['fields']['field_prequest_circles']['field'] = 'field_prequest_circles';
  $handler->display->display_options['fields']['field_prequest_circles']['label'] = '';
  $handler->display->display_options['fields']['field_prequest_circles']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_prequest_circles']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_prequest_circles']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_prequest_circles']['delta_offset'] = '0';
  /* Field: Content: Service links */
  $handler->display->display_options['fields']['service_links']['id'] = 'service_links';
  $handler->display->display_options['fields']['service_links']['table'] = 'node';
  $handler->display->display_options['fields']['service_links']['field'] = 'service_links';
  $handler->display->display_options['fields']['service_links']['label'] = '';
  $handler->display->display_options['fields']['service_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['service_links']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'public_request' => 'public_request',
  );

  /* Display: (P) Open requests */
  $handler = $view->new_display('page', '(P) Open requests', 'public_requests_page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Access the latest requests';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['path'] = 'open-requests';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Open requests';
  $handler->display->display_options['menu']['weight'] = '-47';
  $handler->display->display_options['menu']['name'] = 'menu-top-anonymous';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: (B) Open requests */
  $handler = $view->new_display('block', '(B) Open requests', 'public_requests_block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['defaults']['header'] = FALSE;

  /* Display: (B) EMH Live */
  $handler = $view->new_display('block', '(B) EMH Live', 'public_requests_block_live');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'EMH Live';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Access the latest client requests';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'public_request' => 'public_request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'EMH Live (Public requests)';
  $export['open_requests'] = $view;

  return $export;
}
