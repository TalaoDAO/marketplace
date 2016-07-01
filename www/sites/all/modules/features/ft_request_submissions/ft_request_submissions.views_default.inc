<?php
/**
 * @file
 * ft_request_submissions.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ft_request_submissions_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'request_submissions';
  $view->description = '';
  $view->tag = 'default';
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
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Webform submissions */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::emh_points_give_points' => array(
      'selected' => 1,
      'postpone_processing' => 0,
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
  $handler->display->display_options['fields']['completed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['completed']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['completed']['second_date_format'] = 'long';
  /* Field: Webform submissions: Answer */
  $handler->display->display_options['fields']['emh_answer']['id'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['emh_answer']['field'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['label'] = '';
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
  /* Filter criterion: Webform submissions: Draft */
  $handler->display->display_options['filters']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['filters']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['filters']['is_draft']['value'] = array(
    0 => '0',
  );

  /* Display: (B) Request submissions */
  $handler = $view->new_display('block', '(B) Request submissions', 'block_request_submissions');
  $export['request_submissions'] = $view;

  return $export;
}
