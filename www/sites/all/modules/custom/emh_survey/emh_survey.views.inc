<?php


/**
 * Implements hook_views_data_alter().
 */
function emh_survey_views_data_alter(&$data) {
  // Changes the handler for the webform submission count field
  $data['node']['webform_submission_count_node']['field']['handler'] = 'emh_survey_handler_field_submission_count';
}
