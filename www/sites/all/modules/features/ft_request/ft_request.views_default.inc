<?php
/**
 * @file
 * ft_request.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ft_request_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'request_submissions';
  $view->description = '';
  $view->tag = 'undefined';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Request submissions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Submissions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Bulk operations: Webform submissions */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::emh_user_profile_purchase_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Webform submissions: EMH Author */
  $handler->display->display_options['fields']['emh_author']['id'] = 'emh_author';
  $handler->display->display_options['fields']['emh_author']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['emh_author']['field'] = 'emh_author';
  $handler->display->display_options['fields']['emh_author']['label'] = '';
  $handler->display->display_options['fields']['emh_author']['element_label_colon'] = FALSE;
  /* Field: Webform submissions: Completed */
  $handler->display->display_options['fields']['completed']['id'] = 'completed';
  $handler->display->display_options['fields']['completed']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['completed']['field'] = 'completed';
  $handler->display->display_options['fields']['completed']['label'] = '';
  $handler->display->display_options['fields']['completed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['completed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['completed']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['completed']['second_date_format'] = 'long';
  /* Field: Webform submissions: Answer */
  $handler->display->display_options['fields']['emh_answer']['id'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['emh_answer']['field'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['label'] = '';
  $handler->display->display_options['fields']['emh_answer']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['emh_answer']['alter']['text'] = '<span class="submission-date">[completed]&nbsp;–&nbsp;</span>[emh_answer]';
  $handler->display->display_options['fields']['emh_answer']['element_label_colon'] = FALSE;
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_submission']['access_check'] = 1;
  /* Sort criterion: Webform submissions: Completed */
  $handler->display->display_options['sorts']['completed']['id'] = 'completed';
  $handler->display->display_options['sorts']['completed']['table'] = 'webform_submissions';
  $handler->display->display_options['sorts']['completed']['field'] = 'completed';
  $handler->display->display_options['sorts']['completed']['order'] = 'DESC';
  /* Contextual filter: Webform submissions: Node */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['is_draft']['group'] = 1;
  $handler->display->display_options['filters']['is_draft']['exposed'] = TRUE;
  $handler->display->display_options['filters']['is_draft']['expose']['operator_id'] = 'is_draft_op';
  $handler->display->display_options['filters']['is_draft']['expose']['label'] = 'Draft';
  $handler->display->display_options['filters']['is_draft']['expose']['operator'] = 'is_draft_op';
  $handler->display->display_options['filters']['is_draft']['expose']['identifier'] = 'is_draft';

  /* Display: (B) Request submissions */
  $handler = $view->new_display('block', '(B) Request submissions', 'block_request_submissions');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Submission(s)';
  $handler->display->display_options['block_description'] = 'Submission(s)';

  /* Display: (B) Submissions to my requests */
  $handler = $view->new_display('block', '(B) Submissions to my requests', 'block_my_requests_submissions');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Submissions to my requests';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field' => 'title_field',
    'emh_author' => 'emh_author',
    'completed' => 'completed',
    'emh_answer' => 'emh_answer',
    'view_submission' => 'view_submission',
  );
  $handler->display->display_options['style_options']['default'] = 'completed';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'emh_author' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'completed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'emh_answer' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_submission' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You have not yet submitted any request.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title_field']['label'] = 'Request';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Webform submissions: EMH Author */
  $handler->display->display_options['fields']['emh_author']['id'] = 'emh_author';
  $handler->display->display_options['fields']['emh_author']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['emh_author']['field'] = 'emh_author';
  $handler->display->display_options['fields']['emh_author']['label'] = 'Author';
  $handler->display->display_options['fields']['emh_author']['element_label_colon'] = FALSE;
  /* Field: Webform submissions: Completed */
  $handler->display->display_options['fields']['completed']['id'] = 'completed';
  $handler->display->display_options['fields']['completed']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['completed']['field'] = 'completed';
  $handler->display->display_options['fields']['completed']['label'] = '';
  $handler->display->display_options['fields']['completed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['completed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['completed']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['completed']['second_date_format'] = 'long';
  /* Field: Webform submissions: Answer */
  $handler->display->display_options['fields']['emh_answer']['id'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['emh_answer']['field'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['emh_answer']['alter']['text'] = '<span class="submission-date">[completed]&nbsp;–&nbsp;</span>[emh_answer]';
  $handler->display->display_options['fields']['emh_answer']['element_label_colon'] = FALSE;
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_submission']['access_check'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: (B) My submissions */
  $handler = $view->new_display('block', '(B) My submissions', 'block_my_submissions');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My submissions';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'is_draft' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'All',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field' => 'title_field',
    'completed' => 'completed',
    'emh_answer' => 'emh_answer',
    'is_draft' => 'is_draft',
    'view_submission' => 'view_submission',
  );
  $handler->display->display_options['style_options']['default'] = 'completed';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'completed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'emh_answer' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'is_draft' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_submission' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You have not yet answered any request.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title_field']['label'] = 'Request';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Webform submissions: Completed */
  $handler->display->display_options['fields']['completed']['id'] = 'completed';
  $handler->display->display_options['fields']['completed']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['completed']['field'] = 'completed';
  $handler->display->display_options['fields']['completed']['label'] = '';
  $handler->display->display_options['fields']['completed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['completed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['completed']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['completed']['second_date_format'] = 'long';
  /* Field: Webform submissions: Answer */
  $handler->display->display_options['fields']['emh_answer']['id'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['emh_answer']['field'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['emh_answer']['alter']['text'] = '<span class="submission-date">[completed]&nbsp;–&nbsp;</span>[emh_answer]';
  $handler->display->display_options['fields']['emh_answer']['element_label_colon'] = FALSE;
  /* Field: Webform submissions: Draft */
  $handler->display->display_options['fields']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['fields']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['fields']['is_draft']['label'] = 'Status';
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_submission']['access_check'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['group'] = 1;
  $handler->display->display_options['filters']['is_draft']['exposed'] = TRUE;
  $handler->display->display_options['filters']['is_draft']['expose']['operator_id'] = 'is_draft_op';
  $handler->display->display_options['filters']['is_draft']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['is_draft']['expose']['operator'] = 'is_draft_op';
  $handler->display->display_options['filters']['is_draft']['expose']['identifier'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $export['request_submissions'] = $view;

  return $export;
}
