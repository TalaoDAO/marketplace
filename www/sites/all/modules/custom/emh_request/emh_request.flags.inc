<?php

/**
 * @file
 * Code of the eMindHub request flags feature.
 */

/**
 * Implements hook_flag_access().
 */
function emh_request_flag_access($flag, $entity_id, $action, $account) {
  switch ($flag->name) {
    case 'interesting_answer':
    case 'comment_answer':
      module_load_include('inc', 'webform', 'includes/webform.submissions');
      $submissions = webform_get_submissions(array('sid' => $entity_id));
      $node = node_load($submissions[$entity_id]->nid);
      return $account->uid != $node->uid ? FALSE : NULL;
  }
}

/**
 * Implements hook_flag_access_multiple().
 */
function emh_request_flag_access_multiple($flag, $entity_ids, $account) {
  $access = array();

  switch ($flag->name) {
    case 'interesting_answer':
    case 'comment_answer':
      module_load_include('inc', 'webform', 'includes/webform.submissions');
      foreach ($entity_ids as $entity_id => $action) {
        $submissions = webform_get_submissions(array('sid' => $entity_id));
        $node = node_load($submissions[$entity_id]->nid);
        $access[$entity_id] = $node->uid != $account->uid ? FALSE : NULL;
      }
  }

  return $access;
}
