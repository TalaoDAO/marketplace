<?php

/**
 * @file pcp.views.inc
 *
 * Declare Profile Complete Percent fields.
 */

/**
 * Implements hook_views_data_alter().
 *
 * Here we define pseudo-fields for the {profile} table.
 */
function pcp_views_data_alter(&$data) {

  $data['users']['profile_completeness'] = array(
    'title' => t('Profile Completeness'),
    'help' => t('Profile completeness expressed as a percentage 0..100'),
    'field' => array(
      'handler' => 'pcp_handler_field_profile_completeness_core',
      'click sortable' => FALSE,
    ),
    // Cannot support sort or filter as 'profile_completeness_core' cannot be
    // expressed through SQL.
  );
  $data['profile']['profile_completeness'] = array(
    'title' => t('Profile Completeness'),
    'help' => t('Profile2 completeness expressed as a percentage 0..100'),
    'field' => array(
      'handler' => 'pcp_handler_field_profile_completeness',
      'click sortable' => FALSE,
    ),
    // Cannot support sort or filter as 'profile_completeness' cannot be
    // expressed through SQL.
  );

}
