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

/**
 * Get submission status.
 *
 * @param object $submission
 *
 * @return array
 */
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

/**
 * Does a user can edit another user answer?
 *
 * @param object $node
 * @param object $submission
 * @param object $account
 *   Optional; NULL for current user. The user to filter the permission by.
 *
 * @return bool
 */
function emh_request_submission_edit_access_callback($node, $submission, $account = NULL) {
  if (user_is_anonymous()) {
    return;
  }

  if (empty($account)) {
    global $user;
    $account = $user;
  }

  if (user_access('access EMH answers')) {
    return TRUE;
  }

  foreach ($node->og_group_ref['und'] as $group) {
    if (og_user_access('node', $group['target_id'], 'edit all webform submissions', $account) || (og_user_access('node', $group['target_id'], 'edit own webform submissions', $account) && $submission->uid == $account->uid)) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * Does a user can list request answers?
 *
 * @param object $node
 * @param object $account
 *   Optional; NULL for current user. The user to filter the permission by.
 *
 * @return bool
 */
function emh_request_submission_list_access_callback($node, $account = NULL) {
  if (user_is_anonymous()) {
    return;
  }

  if (empty($account)) {
    global $user;
    $account = $user;
  }

  if (user_access('access EMH answers')) {
    return TRUE;
  }

  if (user_access('access all webform results')) {
    return TRUE;
  }

  // Request author.
  if ($node->uid == $account->uid) {
    return TRUE;
  }

  foreach ($node->og_group_ref['und'] as $group) {
    if (og_user_access('node', $group['target_id'], 'access all webform submissions', $account)) {
      return TRUE;
    }
    if (og_user_access('node', $group['target_id'], 'access all webform results', $account)) {
      return TRUE;
    }
  }

  // Public answers.
  if (!emh_request_has_option($node, 'private')) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Does a user can unpublish another user answer?
 *
 * @param object $node
 * @param object $submission
 * @param object $account
 *   Optional; NULL for current user. The user to filter the permission by.
 *
 * @return bool
 */
function emh_request_submission_unpublish_access_callback($node, $submission, $account = NULL) {
  if (user_is_anonymous()) {
    return;
  }

  if (empty($account)) {
    global $user;
    $account = $user;
  }

  foreach ($node->og_group_ref['und'] as $group) {
    if (og_user_access('node', $group['target_id'], 'unpublish all webform submissions', $account)) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * Does a user can edit another user answer values?
 *
 * @param object $submission
 * @param object $account
 *   Optional; NULL for current user. The user to filter the permission by.
 *
 * @return bool
 */
function emh_request_submission_edit_values_access_callback($submission, $account = NULL) {
  if (user_is_anonymous()) {
    return;
  }

  if (empty($account)) {
    global $user;
    $account = $user;
  }

  // Submission author.
  if (!empty($submission->sid) && ($submission->uid === $account->uid)) {
    return TRUE;
  }

  return FALSE;
}
