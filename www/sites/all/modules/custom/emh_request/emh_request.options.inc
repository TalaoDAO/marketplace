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
    'anonymous' => array(
      'label' => t("Anonymous"),
      'description' => t("Hide my name and/or my company"),
      'fields' => array(
        'field_anonymous',
        'field_show_entreprise',
        'field_use_my_entreprise',
        'field_entreprise_description',
      ),
      'behavior' => array(
        'state' => '!visible',
      ),
    ),
//    'description' => array(
//      'label' => t("Description"),
//      'description' => t("Add information to describe my request"),
//      'fields' => array('body'),
//    ),
    'duration' => array(
      'label' => t("Duration"),
      'description' => t("Add a duration of the mission and a desired starting date"),
      'fields' => array('field_duration_of_the_mission', 'field_start_date'),
    ),
    'files' => array(
      'label' => t("Upload files"),
      'description' => t("Add documents explaining my request"),
      'fields' => array('field_document'),
    ),
    'private' => array(
      'label' => t("Private answers"),
      'description' => t("Answers are only visible by me"),
    ),
    'questionnaire' => array(
      'label' => t("Questionnaire"),
      'description' => t("Identify best experts profiles through a questionnaire"),
      'after_build' => 'emh_request_questionnaire_after_build',
    ),
//    'bounty' => array(
//      'label' => t("Bounty"),
//      'description' => t("Offer a bounty for the best answers"),
//      'fields' => array('field_reward'),
//    ),
  );
}
