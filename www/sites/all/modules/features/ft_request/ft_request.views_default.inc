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
  $view->name = 'query_list';
  $view->description = '';
  $view->tag = 'emh, request';
  $view->base_table = 'node';
  $view->human_name = 'Requests';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Last requests';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
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
    'field_request_type_tid_i18n' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'field_domaine_tid_i18n' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'field_tags_tid_i18n' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'total_points' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No request yet.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Flags: my_selection */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'my_selection';
  /* Field: Node: EMH Request type */
  $handler->display->display_options['fields']['request_type']['id'] = 'request_type';
  $handler->display->display_options['fields']['request_type']['table'] = 'node';
  $handler->display->display_options['fields']['request_type']['field'] = 'request_type';
  $handler->display->display_options['fields']['request_type']['label'] = '';
  $handler->display->display_options['fields']['request_type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Domain(s) */
  $handler->display->display_options['fields']['field_domaine']['id'] = 'field_domaine';
  $handler->display->display_options['fields']['field_domaine']['table'] = 'field_data_field_domaine';
  $handler->display->display_options['fields']['field_domaine']['field'] = 'field_domaine';
  $handler->display->display_options['fields']['field_domaine']['label'] = '';
  $handler->display->display_options['fields']['field_domaine']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_domaine']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_domaine']['delta_offset'] = '0';
  /* Field: Node: EMH Request status */
  $handler->display->display_options['fields']['request_status']['id'] = 'request_status';
  $handler->display->display_options['fields']['request_status']['table'] = 'node';
  $handler->display->display_options['fields']['request_status']['field'] = 'request_status';
  $handler->display->display_options['fields']['request_status']['label'] = '';
  $handler->display->display_options['fields']['request_status']['element_label_colon'] = FALSE;
  /* Field: Node: EMH Total Answers */
  $handler->display->display_options['fields']['total_answers']['id'] = 'total_answers';
  $handler->display->display_options['fields']['total_answers']['table'] = 'node';
  $handler->display->display_options['fields']['total_answers']['field'] = 'total_answers';
  $handler->display->display_options['fields']['total_answers']['label'] = '';
  $handler->display->display_options['fields']['total_answers']['element_label_colon'] = FALSE;
  /* Field: Node: EMH Request language */
  $handler->display->display_options['fields']['request_language']['id'] = 'request_language';
  $handler->display->display_options['fields']['request_language']['table'] = 'node';
  $handler->display->display_options['fields']['request_language']['field'] = 'request_language';
  $handler->display->display_options['fields']['request_language']['label'] = '';
  $handler->display->display_options['fields']['request_language']['element_label_colon'] = FALSE;
  /* Field: Content: Choose circle of experts */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['label'] = '';
  $handler->display->display_options['fields']['og_group_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['og_group_ref']['delta_offset'] = '0';
  /* Field: Node: EMH Request organisation name - if not hidden by user */
  $handler->display->display_options['fields']['request_nothidden_entreprise']['id'] = 'request_nothidden_entreprise';
  $handler->display->display_options['fields']['request_nothidden_entreprise']['table'] = 'node';
  $handler->display->display_options['fields']['request_nothidden_entreprise']['field'] = 'request_nothidden_entreprise';
  $handler->display->display_options['fields']['request_nothidden_entreprise']['label'] = 'Organisation';
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
    'challenge' => 'challenge',
    'question1' => 'question1',
    'webform' => 'webform',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'challenge' => 'challenge',
    'question1' => 'question1',
    'webform' => 'webform',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Field: Domain(s) (field_domaine) (translated) */
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['id'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['table'] = 'field_data_field_domaine';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['field'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['operator_id'] = 'field_domaine_tid_i18n_op';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['label'] = 'Domain(s)';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['operator'] = 'field_domaine_tid_i18n_op';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['identifier'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['vocabulary'] = 'domaine';
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = 'All';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  $handler->display->display_options['filters']['uid_current']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid_current']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['uid_current']['expose']['label'] = 'Only my contributions';
  $handler->display->display_options['filters']['uid_current']['expose']['operator'] = 'uid_current_op';
  $handler->display->display_options['filters']['uid_current']['expose']['identifier'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = 'All';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: Field: Domain(s) (field_domaine) (translated) */
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['id'] = 'field_domaine_tid_i18n_1';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['table'] = 'field_data_field_domaine';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['field'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['expose']['operator_id'] = 'field_domaine_tid_i18n_1_op';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['expose']['label'] = 'Domain(s)';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['expose']['operator'] = 'field_domaine_tid_i18n_1_op';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['expose']['identifier'] = 'field_domaine_tid_i18n_1';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['vocabulary'] = 'domaine';
  /* Filter criterion: Credits: Total Credits */
  $handler->display->display_options['filters']['total_points']['id'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['table'] = 'emh_points_total';
  $handler->display->display_options['filters']['total_points']['field'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['exposed'] = TRUE;
  $handler->display->display_options['filters']['total_points']['expose']['operator_id'] = 'total_points_op';
  $handler->display->display_options['filters']['total_points']['expose']['label'] = 'Total Points';
  $handler->display->display_options['filters']['total_points']['expose']['operator'] = 'total_points_op';
  $handler->display->display_options['filters']['total_points']['expose']['identifier'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['total_points']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['total_points']['group_info']['identifier'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Open',
      'operator' => '!=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Closed',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: P - All requests */
  $handler = $view->new_display('page', 'P - All requests', 'page_all_requests');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All requests';
  $handler->display->display_options['field_language'] = 'und';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_entreprise_target_id']['id'] = 'field_entreprise_target_id';
  $handler->display->display_options['relationships']['field_entreprise_target_id']['table'] = 'field_data_field_entreprise';
  $handler->display->display_options['relationships']['field_entreprise_target_id']['field'] = 'field_entreprise_target_id';
  $handler->display->display_options['relationships']['field_entreprise_target_id']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['field_entreprise_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by keywords';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field: Organisation (field_entreprise) (reference filter) */
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['id'] = 'field_entreprise_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['table'] = 'field_data_field_entreprise';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['field'] = 'field_entreprise_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['operator_id'] = 'field_entreprise_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['label'] = 'Entreprise';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['operator'] = 'field_entreprise_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['identifier'] = 'field_entreprise_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['reference_display'] = 'entreprise_list:entityreference_entreprise';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'request' => 'request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Choose circle of experts (og_group_ref) (reference filter) */
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['id'] = 'og_group_ref_target_id_entityreference_filter';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['field'] = 'og_group_ref_target_id_entityreference_filter';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['operator_id'] = 'og_group_ref_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['label'] = 'Circle';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['operator'] = 'og_group_ref_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['identifier'] = 'og_group_ref_target_id_entityreference_filter';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['reference_display'] = 'circles:entityreference_1';
  /* Filter criterion: Content: Choose a public request type (field_request_type) (translated) */
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['id'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['table'] = 'field_data_field_request_type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['field'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['operator_id'] = 'field_request_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['operator'] = 'field_request_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['identifier'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['group_info']['label'] = 'Choose a request type (field_request_type) (translated)';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['group_info']['identifier'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['vocabulary'] = 'request_type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['hierarchy'] = 1;
  /* Filter criterion: Credits: Total Credits */
  $handler->display->display_options['filters']['total_points']['id'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['table'] = 'emh_points_total';
  $handler->display->display_options['filters']['total_points']['field'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['group'] = 1;
  $handler->display->display_options['filters']['total_points']['exposed'] = TRUE;
  $handler->display->display_options['filters']['total_points']['expose']['operator_id'] = 'total_points_op';
  $handler->display->display_options['filters']['total_points']['expose']['label'] = 'Total Points';
  $handler->display->display_options['filters']['total_points']['expose']['operator'] = 'total_points_op';
  $handler->display->display_options['filters']['total_points']['expose']['identifier'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['total_points']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['total_points']['group_info']['identifier'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Open',
      'operator' => '!=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Closed',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Field: Domain(s) (field_domaine) (translated) */
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['id'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['table'] = 'field_data_field_domaine';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['field'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['operator_id'] = 'field_domaine_tid_i18n_op';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['label'] = 'Domain(s)';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['operator'] = 'field_domaine_tid_i18n_op';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['identifier'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['vocabulary'] = 'domaine';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['error_message'] = FALSE;
  /* Filter criterion: Content: Tags (field_tags) (translated) */
  $handler->display->display_options['filters']['field_tags_tid_i18n']['id'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['field'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['operator_id'] = 'field_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['operator'] = 'field_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['identifier'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_tags_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['vocabulary'] = 'tags';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['error_message'] = FALSE;
  /* Filter criterion: Global: Dependent filter */
  $handler->display->display_options['filters']['views_dependent_filter']['id'] = 'views_dependent_filter';
  $handler->display->display_options['filters']['views_dependent_filter']['table'] = 'views';
  $handler->display->display_options['filters']['views_dependent_filter']['field'] = 'views_dependent_filter';
  $handler->display->display_options['filters']['views_dependent_filter']['group'] = 1;
  $handler->display->display_options['filters']['views_dependent_filter']['controller_filter'] = 'field_entreprise_target_id_entityreference_filter';
  $handler->display->display_options['filters']['views_dependent_filter']['controller_values'] = '';
  $handler->display->display_options['filters']['views_dependent_filter']['dependent_filters'] = array(
    'field_hide_organisation_value' => 'field_hide_organisation_value',
  );
  /* Filter criterion: Content: Hide my organisation (field_hide_organisation) */
  $handler->display->display_options['filters']['field_hide_organisation_value']['id'] = 'field_hide_organisation_value';
  $handler->display->display_options['filters']['field_hide_organisation_value']['table'] = 'field_data_field_hide_organisation';
  $handler->display->display_options['filters']['field_hide_organisation_value']['field'] = 'field_hide_organisation_value';
  $handler->display->display_options['filters']['field_hide_organisation_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_hide_organisation_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_hide_organisation_value']['group'] = 1;
  $handler->display->display_options['views_navigation'] = TRUE;
  $handler->display->display_options['views_navigation_cycle'] = FALSE;
  $handler->display->display_options['path'] = 'requests';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'All requests';
  $handler->display->display_options['menu']['weight'] = '-50';
  $handler->display->display_options['menu']['name'] = 'menu-top';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: B - Last requests */
  $handler = $view->new_display('block', 'B - Last requests', 'block_last_requests');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More requests';
  $handler->display->display_options['field_language'] = 'und';
  $handler->display->display_options['field_language_add_to_query'] = 0;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_entreprise_target_id']['id'] = 'field_entreprise_target_id';
  $handler->display->display_options['relationships']['field_entreprise_target_id']['table'] = 'field_data_field_entreprise';
  $handler->display->display_options['relationships']['field_entreprise_target_id']['field'] = 'field_entreprise_target_id';
  $handler->display->display_options['relationships']['field_entreprise_target_id']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['field_entreprise_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by keywords';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  /* Filter criterion: Field: Organisation (field_entreprise) (reference filter) */
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['id'] = 'field_entreprise_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['table'] = 'field_data_field_entreprise';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['field'] = 'field_entreprise_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['operator_id'] = 'field_entreprise_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['label'] = 'Entreprise';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['operator'] = 'field_entreprise_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['identifier'] = 'field_entreprise_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['reference_display'] = 'entreprise_list:entityreference_entreprise';
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
    'request' => 'request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Choose circle of experts (og_group_ref) (reference filter) */
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['id'] = 'og_group_ref_target_id_entityreference_filter';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['field'] = 'og_group_ref_target_id_entityreference_filter';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['operator_id'] = 'og_group_ref_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['label'] = 'Circle';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['operator'] = 'og_group_ref_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['identifier'] = 'og_group_ref_target_id_entityreference_filter';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['reference_display'] = 'circles:entityreference_1';
  /* Filter criterion: Content: Choose a public request type (field_request_type) (translated) */
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['id'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['table'] = 'field_data_field_request_type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['field'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['operator_id'] = 'field_request_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['operator'] = 'field_request_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['identifier'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['vocabulary'] = 'request_type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['hierarchy'] = 1;
  /* Filter criterion: Credits: Total Credits */
  $handler->display->display_options['filters']['total_points']['id'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['table'] = 'emh_points_total';
  $handler->display->display_options['filters']['total_points']['field'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['group'] = 1;
  $handler->display->display_options['filters']['total_points']['exposed'] = TRUE;
  $handler->display->display_options['filters']['total_points']['expose']['operator_id'] = 'total_points_op';
  $handler->display->display_options['filters']['total_points']['expose']['label'] = 'Total Points';
  $handler->display->display_options['filters']['total_points']['expose']['operator'] = 'total_points_op';
  $handler->display->display_options['filters']['total_points']['expose']['identifier'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['total_points']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['total_points']['group_info']['identifier'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Open',
      'operator' => '!=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Closed',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Field: Domain(s) (field_domaine) (translated) */
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['id'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['table'] = 'field_data_field_domaine';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['field'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['operator_id'] = 'field_domaine_tid_i18n_op';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['label'] = 'Domain(s)';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['operator'] = 'field_domaine_tid_i18n_op';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['identifier'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['vocabulary'] = 'domaine';
  /* Filter criterion: Content: Tags (field_tags) (translated) */
  $handler->display->display_options['filters']['field_tags_tid_i18n']['id'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['field'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['operator_id'] = 'field_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['operator'] = 'field_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['identifier'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_tags_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['vocabulary'] = 'tags';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['error_message'] = FALSE;
  /* Filter criterion: Global: Dependent filter */
  $handler->display->display_options['filters']['views_dependent_filter']['id'] = 'views_dependent_filter';
  $handler->display->display_options['filters']['views_dependent_filter']['table'] = 'views';
  $handler->display->display_options['filters']['views_dependent_filter']['field'] = 'views_dependent_filter';
  $handler->display->display_options['filters']['views_dependent_filter']['group'] = 1;
  $handler->display->display_options['filters']['views_dependent_filter']['controller_filter'] = 'field_entreprise_target_id_entityreference_filter';
  $handler->display->display_options['filters']['views_dependent_filter']['controller_values'] = '';
  $handler->display->display_options['filters']['views_dependent_filter']['dependent_filters'] = array(
    'field_hide_organisation_value' => 'field_hide_organisation_value',
  );
  /* Filter criterion: Content: Hide my organisation (field_hide_organisation) */
  $handler->display->display_options['filters']['field_hide_organisation_value']['id'] = 'field_hide_organisation_value';
  $handler->display->display_options['filters']['field_hide_organisation_value']['table'] = 'field_data_field_hide_organisation';
  $handler->display->display_options['filters']['field_hide_organisation_value']['field'] = 'field_hide_organisation_value';
  $handler->display->display_options['filters']['field_hide_organisation_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_hide_organisation_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_hide_organisation_value']['group'] = 1;
  $handler->display->display_options['views_navigation'] = TRUE;
  $handler->display->display_options['views_navigation_cycle'] = FALSE;
  $handler->display->display_options['views_navigation_title'] = TRUE;

  /* Display: P - My selection */
  $handler = $view->new_display('page', 'P - My selection', 'page_selected_requests');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Saved requests';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'flag my_selection';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
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
    'field_domaine_tid_i18n' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_select_all_none_nested' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'field_tags_tid_i18n' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'total_points' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
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
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You did not have select any request yet.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: my_selection */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'my_selection';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_entreprise_target_id']['id'] = 'field_entreprise_target_id';
  $handler->display->display_options['relationships']['field_entreprise_target_id']['table'] = 'field_data_field_entreprise';
  $handler->display->display_options['relationships']['field_entreprise_target_id']['field'] = 'field_entreprise_target_id';
  $handler->display->display_options['relationships']['field_entreprise_target_id']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['field_entreprise_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by keywords';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field: Organisation (field_entreprise) (reference filter) */
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['id'] = 'field_entreprise_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['table'] = 'field_data_field_entreprise';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['field'] = 'field_entreprise_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['operator_id'] = 'field_entreprise_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['label'] = 'Entreprise';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['operator'] = 'field_entreprise_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['identifier'] = 'field_entreprise_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_entreprise_target_id_entityreference_filter']['reference_display'] = 'entreprise_list:entityreference_entreprise';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'request' => 'request',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Choose circle of experts (og_group_ref) (reference filter) */
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['id'] = 'og_group_ref_target_id_entityreference_filter';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['field'] = 'og_group_ref_target_id_entityreference_filter';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['operator_id'] = 'og_group_ref_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['label'] = 'Circle';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['operator'] = 'og_group_ref_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['identifier'] = 'og_group_ref_target_id_entityreference_filter';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['reference_display'] = 'circles:entityreference_1';
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '1';
  $handler->display->display_options['filters']['flagged']['group'] = 1;
  /* Filter criterion: Content: Choose a public request type (field_request_type) (translated) */
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['id'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['table'] = 'field_data_field_request_type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['field'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['operator_id'] = 'field_request_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['operator'] = 'field_request_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['identifier'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['vocabulary'] = 'request_type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['hierarchy'] = 1;
  /* Filter criterion: Credits: Total Credits */
  $handler->display->display_options['filters']['total_points']['id'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['table'] = 'emh_points_total';
  $handler->display->display_options['filters']['total_points']['field'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['group'] = 1;
  $handler->display->display_options['filters']['total_points']['exposed'] = TRUE;
  $handler->display->display_options['filters']['total_points']['expose']['operator_id'] = 'total_points_op';
  $handler->display->display_options['filters']['total_points']['expose']['label'] = 'Total Points';
  $handler->display->display_options['filters']['total_points']['expose']['operator'] = 'total_points_op';
  $handler->display->display_options['filters']['total_points']['expose']['identifier'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['total_points']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['total_points']['group_info']['identifier'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Open',
      'operator' => '!=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Closed',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Field: Domain(s) (field_domaine) (translated) */
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['id'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['table'] = 'field_data_field_domaine';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['field'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['operator_id'] = 'field_domaine_tid_i18n_op';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['label'] = 'Domain(s)';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['operator'] = 'field_domaine_tid_i18n_op';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['identifier'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['vocabulary'] = 'domaine';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['hierarchy'] = 1;
  /* Filter criterion: Content: Tags (field_tags) (translated) */
  $handler->display->display_options['filters']['field_tags_tid_i18n']['id'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['field'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['operator_id'] = 'field_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['operator'] = 'field_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['identifier'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_tags_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['vocabulary'] = 'tags';
  /* Filter criterion: Global: Dependent filter */
  $handler->display->display_options['filters']['views_dependent_filter']['id'] = 'views_dependent_filter';
  $handler->display->display_options['filters']['views_dependent_filter']['table'] = 'views';
  $handler->display->display_options['filters']['views_dependent_filter']['field'] = 'views_dependent_filter';
  $handler->display->display_options['filters']['views_dependent_filter']['group'] = 1;
  $handler->display->display_options['filters']['views_dependent_filter']['controller_filter'] = 'field_entreprise_target_id_entityreference_filter';
  $handler->display->display_options['filters']['views_dependent_filter']['controller_values'] = '';
  $handler->display->display_options['filters']['views_dependent_filter']['dependent_filters'] = array(
    'field_hide_organisation_value' => 'field_hide_organisation_value',
  );
  /* Filter criterion: Content: Hide my organisation (field_hide_organisation) */
  $handler->display->display_options['filters']['field_hide_organisation_value']['id'] = 'field_hide_organisation_value';
  $handler->display->display_options['filters']['field_hide_organisation_value']['table'] = 'field_data_field_hide_organisation';
  $handler->display->display_options['filters']['field_hide_organisation_value']['field'] = 'field_hide_organisation_value';
  $handler->display->display_options['filters']['field_hide_organisation_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_hide_organisation_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_hide_organisation_value']['group'] = 1;
  $handler->display->display_options['views_navigation'] = TRUE;
  $handler->display->display_options['views_navigation_cycle'] = FALSE;
  $handler->display->display_options['path'] = 'requests/selection';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Saved requests';
  $handler->display->display_options['menu']['weight'] = '-48';
  $handler->display->display_options['menu']['name'] = 'menu-top';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: P - My requests */
  $handler = $view->new_display('page', 'P - My requests', 'page_my_requests');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My requests';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You have not yet published any request.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by keywords';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'request' => 'request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Choose circle of experts (og_group_ref) (reference filter) */
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['id'] = 'og_group_ref_target_id_entityreference_filter';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['field'] = 'og_group_ref_target_id_entityreference_filter';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['operator_id'] = 'og_group_ref_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['label'] = 'Circle';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['operator'] = 'og_group_ref_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['identifier'] = 'og_group_ref_target_id_entityreference_filter';
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['og_group_ref_target_id_entityreference_filter']['reference_display'] = 'circles:entityreference_1';
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  $handler->display->display_options['filters']['uid_current']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['uid_current']['expose']['label'] = 'Only my contributions';
  $handler->display->display_options['filters']['uid_current']['expose']['operator'] = 'uid_current_op';
  $handler->display->display_options['filters']['uid_current']['expose']['identifier'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Choose a public request type (field_request_type) (translated) */
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['id'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['table'] = 'field_data_field_request_type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['field'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['operator_id'] = 'field_request_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['operator'] = 'field_request_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['identifier'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['vocabulary'] = 'request_type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['hierarchy'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = 'All';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  /* Filter criterion: Field: Domain(s) (field_domaine) (translated) */
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['id'] = 'field_domaine_tid_i18n_1';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['table'] = 'field_data_field_domaine';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['field'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['group'] = 1;
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['expose']['operator_id'] = 'field_domaine_tid_i18n_1_op';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['expose']['label'] = 'Domain(s)';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['expose']['operator'] = 'field_domaine_tid_i18n_1_op';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['expose']['identifier'] = 'field_domaine_tid_i18n_1';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['vocabulary'] = 'domaine';
  $handler->display->display_options['filters']['field_domaine_tid_i18n_1']['hierarchy'] = 1;
  /* Filter criterion: Content: Tags (field_tags) (translated) */
  $handler->display->display_options['filters']['field_tags_tid_i18n']['id'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['field'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['operator_id'] = 'field_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['operator'] = 'field_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['identifier'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_tags_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['vocabulary'] = 'tags';
  $handler->display->display_options['views_navigation'] = TRUE;
  $handler->display->display_options['views_navigation_cycle'] = FALSE;
  $handler->display->display_options['path'] = 'requests/manage';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My requests';
  $handler->display->display_options['menu']['weight'] = '-49';
  $handler->display->display_options['menu']['name'] = 'menu-top';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: (P) Circle requests */
  $handler = $view->new_display('page', '(P) Circle requests', 'page_circle_requests');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Circle requests';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['field_language'] = 'und';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'og_context';
  $handler->display->display_options['access']['perm'] = 'create request content';
  $handler->display->display_options['access']['group_id_arg'] = '1';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No request yet.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['gid']['title'] = '%1 requests';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  $handler->display->display_options['arguments']['gid']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search by keywords';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
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
    'request' => 'request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Choose a public request type (field_request_type) (translated) */
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['id'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['table'] = 'field_data_field_request_type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['field'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['operator_id'] = 'field_request_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['operator'] = 'field_request_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['identifier'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['group_info']['label'] = 'Choose a request type (field_request_type) (translated)';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['group_info']['identifier'] = 'field_request_type_tid_i18n';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['vocabulary'] = 'request_type';
  $handler->display->display_options['filters']['field_request_type_tid_i18n']['hierarchy'] = 1;
  /* Filter criterion: Credits: Total Credits */
  $handler->display->display_options['filters']['total_points']['id'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['table'] = 'emh_points_total';
  $handler->display->display_options['filters']['total_points']['field'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['group'] = 1;
  $handler->display->display_options['filters']['total_points']['exposed'] = TRUE;
  $handler->display->display_options['filters']['total_points']['expose']['operator_id'] = 'total_points_op';
  $handler->display->display_options['filters']['total_points']['expose']['label'] = 'Total Points';
  $handler->display->display_options['filters']['total_points']['expose']['operator'] = 'total_points_op';
  $handler->display->display_options['filters']['total_points']['expose']['identifier'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['total_points']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['total_points']['group_info']['identifier'] = 'total_points';
  $handler->display->display_options['filters']['total_points']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Open',
      'operator' => '!=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Closed',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Field: Domain(s) (field_domaine) (translated) */
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['id'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['table'] = 'field_data_field_domaine';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['field'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['operator_id'] = 'field_domaine_tid_i18n_op';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['label'] = 'Domain(s)';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['operator'] = 'field_domaine_tid_i18n_op';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['identifier'] = 'field_domaine_tid_i18n';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['vocabulary'] = 'domaine';
  $handler->display->display_options['filters']['field_domaine_tid_i18n']['error_message'] = FALSE;
  /* Filter criterion: Content: Tags (field_tags) (translated) */
  $handler->display->display_options['filters']['field_tags_tid_i18n']['id'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['table'] = 'field_data_field_tags';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['field'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['operator_id'] = 'field_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['operator'] = 'field_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['identifier'] = 'field_tags_tid_i18n';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_tags_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_tags_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['vocabulary'] = 'tags';
  $handler->display->display_options['filters']['field_tags_tid_i18n']['error_message'] = FALSE;
  /* Filter criterion: OG membership: Group_type */
  $handler->display->display_options['filters']['group_type']['id'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['group_type']['field'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['group_type']['value'] = array(
    'node' => 'node',
  );
  $handler->display->display_options['filters']['group_type']['group'] = 1;
  $handler->display->display_options['views_navigation'] = TRUE;
  $handler->display->display_options['views_navigation_cycle'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/requests';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Requests';
  $handler->display->display_options['menu']['description'] = 'Circle requests';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: (B) Circle requests */
  $handler = $view->new_display('block', '(B) Circle requests', 'block_circle_requests');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest requests';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More requests';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_circle_requests';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'og_context';
  $handler->display->display_options['access']['perm'] = 'create request content';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
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
    'request' => 'request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: OG membership: Group_type */
  $handler->display->display_options['filters']['group_type']['id'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['group_type']['field'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['group_type']['value'] = array(
    'node' => 'node',
  );
  $handler->display->display_options['filters']['group_type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Latest requests';
  $export['query_list'] = $view;

  $view = new view();
  $view->name = 'request_submissions';
  $view->description = '';
  $view->tag = 'undefined';
  $view->base_table = 'webform_submissions';
  $view->human_name = 'Request answers';
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
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Flags: interesting_answer */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'flag-helpful-answer';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'interesting_answer';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
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
  /* Field: Webform submissions: EMH Answer */
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
  $handler->display->display_options['filters']['is_draft']['expose']['operator_id'] = 'is_draft_op';
  $handler->display->display_options['filters']['is_draft']['expose']['label'] = 'Draft';
  $handler->display->display_options['filters']['is_draft']['expose']['operator'] = 'is_draft_op';
  $handler->display->display_options['filters']['is_draft']['expose']['identifier'] = 'is_draft';

  /* Display: (B) Request submissions */
  $handler = $view->new_display('block', '(B) Request submissions', 'block_request_submissions');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Answer(s)';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No answer yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_user';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'uid';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::emh_user_profile_purchase_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
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
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_submission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_submission']['access_check'] = 1;
  /* Field: Webform submissions: EMH Answer */
  $handler->display->display_options['fields']['emh_answer']['id'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['emh_answer']['field'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['label'] = '';
  $handler->display->display_options['fields']['emh_answer']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['emh_answer']['alter']['text'] = '<span class="submission-date">[completed]&nbsp;–&nbsp;</span>[emh_answer] [view_submission]';
  $handler->display->display_options['fields']['emh_answer']['element_label_colon'] = FALSE;
  /* Field: Webform submissions: EMH Submission flags */
  $handler->display->display_options['fields']['emh_submission_flags']['id'] = 'emh_submission_flags';
  $handler->display->display_options['fields']['emh_submission_flags']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['emh_submission_flags']['field'] = 'emh_submission_flags';
  $handler->display->display_options['fields']['emh_submission_flags']['label'] = '';
  $handler->display->display_options['fields']['emh_submission_flags']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Answer(s)';

  /* Display: (P) My answers */
  $handler = $view->new_display('page', '(P) My answers', 'page_my_answers');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My answers';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
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
        'any_label' => '',
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You did not answer any request yet.';
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Webform submissions: Draft */
  $handler->display->display_options['fields']['is_draft']['id'] = 'is_draft';
  $handler->display->display_options['fields']['is_draft']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['is_draft']['field'] = 'is_draft';
  $handler->display->display_options['fields']['is_draft']['label'] = '';
  $handler->display->display_options['fields']['is_draft']['exclude'] = TRUE;
  $handler->display->display_options['fields']['is_draft']['element_label_colon'] = FALSE;
  /* Field: Webform submissions: Completed */
  $handler->display->display_options['fields']['completed']['id'] = 'completed';
  $handler->display->display_options['fields']['completed']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['completed']['field'] = 'completed';
  $handler->display->display_options['fields']['completed']['label'] = '';
  $handler->display->display_options['fields']['completed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['completed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['completed']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['completed']['second_date_format'] = 'long';
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_submission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_submission']['access_check'] = 1;
  /* Field: Webform submissions: EMH Answer */
  $handler->display->display_options['fields']['emh_answer']['id'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['emh_answer']['field'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['label'] = '';
  $handler->display->display_options['fields']['emh_answer']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['emh_answer']['alter']['text'] = '<span class="user-submission-status [is_draft]">[is_draft]</span><span class="submission-date">[completed]&nbsp;–&nbsp;</span>[emh_answer] [view_submission]';
  $handler->display->display_options['fields']['emh_answer']['element_label_colon'] = FALSE;
  /* Field: Webform submissions: EMH Submission flags */
  $handler->display->display_options['fields']['emh_submission_flags']['id'] = 'emh_submission_flags';
  $handler->display->display_options['fields']['emh_submission_flags']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['emh_submission_flags']['field'] = 'emh_submission_flags';
  $handler->display->display_options['fields']['emh_submission_flags']['label'] = '';
  $handler->display->display_options['fields']['emh_submission_flags']['alter']['text'] = '[flagged][emh_submission_flags]';
  $handler->display->display_options['fields']['emh_submission_flags']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['path'] = 'answers/my';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My answers';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-top';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: (P) Answers to my requests */
  $handler = $view->new_display('page', '(P) Answers to my requests', 'page_answers_to_me');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Answers to my requests';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
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
  $handler->display->display_options['empty']['area']['content'] = 'You did not have any answer yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Webform submissions: Node */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Request';
  /* Field: Webform submissions: EMH Author */
  $handler->display->display_options['fields']['emh_author']['id'] = 'emh_author';
  $handler->display->display_options['fields']['emh_author']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['emh_author']['field'] = 'emh_author';
  $handler->display->display_options['fields']['emh_author']['label'] = 'Expert';
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
  /* Field: Webform submissions: View link */
  $handler->display->display_options['fields']['view_submission']['id'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['view_submission']['field'] = 'view_submission';
  $handler->display->display_options['fields']['view_submission']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_submission']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_submission']['access_check'] = 1;
  /* Field: Webform submissions: EMH Answer */
  $handler->display->display_options['fields']['emh_answer']['id'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['emh_answer']['field'] = 'emh_answer';
  $handler->display->display_options['fields']['emh_answer']['label'] = 'Answer';
  $handler->display->display_options['fields']['emh_answer']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['emh_answer']['alter']['text'] = '<span class="submission-date">[completed]&nbsp;–&nbsp;</span>[emh_answer] [view_submission]';
  $handler->display->display_options['fields']['emh_answer']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['path'] = 'answers/to-me';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Answers to my requests';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'menu-top';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['request_submissions'] = $view;

  return $export;
}
