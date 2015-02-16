<?php

/**
 * @file
 * Providing extra functionality for the WebformSubmissionEntity UI via views.
 */


/**
 * Implements hook_views_data()
 */
function webform_submission_entity_views_data_alter(&$data) { 
  $data['webform_submission_entity']['link_webform_submission_entity'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the webform_submission_entity.'),
      'handler' => 'webform_submission_entity_handler_link_field',
    ),
  );
  $data['webform_submission_entity']['webform_submission_entity_form_name'] = array(
    'field' => array(
      'title' => t('Form name'),
      'help' => t('Provide the name of the form the submission is related to.'),
      'handler' => 'webform_submission_entity_handler_form_name',
    ),
  );
}