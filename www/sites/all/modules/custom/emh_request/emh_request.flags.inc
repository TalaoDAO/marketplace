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
      module_load_include('inc', 'webform', 'includes/webform.submissions');
      $submission = webform_get_submissions(array('sid' => $entity_id));
      $node = node_load($submission[$entity_id]->nid);
      return $account->uid != $node->uid ? FALSE : NULL;
  }
}

/**
 * Implements hook_flag_access_multiple().
 */
function emh_request_flag_access_multiple($flag, $entity_ids, $account) {
  $access = array();

  if ($flag->name == 'interesting_answer') {
    module_load_include('inc', 'webform', 'includes/webform.submissions');
    foreach ($entity_ids as $entity_id => $action) {
      $submission = webform_get_submissions(array('sid' => $entity_id));
      $node = node_load($submission[$entity_id]->nid);
      $access[$entity_id] = $node->uid != $account->uid ? FALSE : NULL;
    }
  }

  return $access;
}
