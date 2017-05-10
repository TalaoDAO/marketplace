<?php

/**
 * @file
 * Views hooks implemented for the EMH Request Workflow module.
 */

/**
 * Implements hook_views_data().
 * @ingroup views
 */
function emh_request_workflow_views_data() {
  $data = array();

  $data['node']['request_status'] = array(
    'group' => t('Node'),
    'title' => 'EMH Request status',
    'field' => array(
      'handler' => 'views_handler_field_emh_request_workflow_status',
    ),
  );

  return $data;
}
