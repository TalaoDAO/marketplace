<?php
/**
 * @file
 * Implements hooks invoked by the module.
 */


/**
 * Implements hook_emh_request_option_info().
 */
function emh_request_emh_request_option_info() {
  return array(
//    'description' => array(
//      'label' => t("Description"),
//      'description' => t("Add information to describe my request"),
//      'fields' => array('body'),
//    ),
    'files' => array(
      'label' => t("Upload files"),
      'description' => t("Add any images or documents that might be helpful in explaining your request brief here"),
      'cost' => 200,
      'fields' => array('field_request_documents'),
    ),
    'duration' => array(
      'label' => t("Duration"),
      'description' => t("Add duration of the mission and desired starting date"),
      'cost' => 200,
      'fields' => array('field_duration_of_the_mission', 'field_start_date'),
    ),
    'questionnaire' => array(
      'label' => t("Questionnaire"),
      'description' => t("Identify best answers through a questionnaire"),
      'cost' => 500,
      'after_build' => 'emh_request_questionnaire_after_build',
    ),
    'anonymous' => array(
      'label' => t("Anonymous"),
      'description' => t("Hide your name and/or your company"),
      'cost' => 300,
      'fields' => array(
        'field_hide_name',
        'field_hide_organisation',
        'field_activity',
      ),
    ),
    'private' => array(
      'label' => t("Private submissions"),
      'description' => t("Submissions are visible only by you"),
      'cost' => 300,
    ),
//    'bounty' => array(
//      'label' => t("Bounty"),
//      'description' => t("Offer a bounty for the best answers"),
//      'fields' => array('field_reward'),
//    ),
  );
}
