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
<<<<<<< HEAD
      $submissions = webform_get_submissions(array('sid' => $entity_id));
      $node = node_load($submissions[$entity_id]->nid);
=======
      $sid = $entity_id;
      $submission = webform_get_submissions(array('sid' => $sid));
      $node = node_load($submission[$sid]->nid);
>>>>>>> ADD: behat tests & export views
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
<<<<<<< HEAD
      $submissions = webform_get_submissions(array('sid' => $entity_id));
      $node = node_load($submissions[$entity_id]->nid);
=======
      $submission = webform_get_submissions(array('sid' => $entity_id));
      $node = node_load($submission[$entity_id]->nid);
>>>>>>> ADD: behat tests & export views
      $access[$entity_id] = $node->uid != $account->uid ? FALSE : NULL;
    }
  }

  return $access;
}
