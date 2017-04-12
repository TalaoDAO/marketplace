<?php

/**
 * @file
 * Code of the eMindHub request submission custom features.
 */

/**
 * Return a count of the total number of submissions for a user.
 *
 * @param int $uid
 *   Optional; NULL for current user. The user ID to filter the submissions by.
 * @param bool $is_draft
 *   Optional; NULL for all, truthy for drafts only, falsy for completed only.
 *   The default is completed submissions only.
 *
 * @return int
 *   An integer value of the number of submissions.
 */
function emh_request_submission_get_user_submission_count($uid = NULL, $is_draft = 0) {
  if (!isset($uid)) {
    global $user;
    $uid = $user->uid;
  }

  $counts = &drupal_static(__FUNCTION__);

  if (!isset($counts[$uid])) {
    $query = db_select('webform_submissions', 'ws')
      ->addTag('emh_request_submission_get_user_submission_count')
      ->condition('ws.uid', $uid);
    if ($uid === 0) {
      $submissions = isset($_SESSION['webform_submission']) ? $_SESSION['webform_submission'] : NULL;
      if ($submissions) {
        $query->condition('ws.sid', $submissions, 'IN');
      }
      else {
        // Intentionally never match anything if the anonymous user has no
        // submissions.
        $query->condition('ws.sid', 0);
      }
    }
    if (isset($is_draft)) {
      $query->condition('ws.is_draft', $is_draft);
    }

    $counts[$uid] = $query->countQuery()->execute()->fetchField();
  }

  return $counts[$uid];
}

function emh_request_submission_get_status($submission) {
  $workflow = array();

  if (!empty($submission)) {
    if (!empty($submission->is_draft)) {
      $workflow = array('status' => 'draft', 'label' => t('Draft'));
    }
    else {
      $workflow = array('status' => 'published', 'label' => t('Published'));
    }
  }

  return $workflow;
}
