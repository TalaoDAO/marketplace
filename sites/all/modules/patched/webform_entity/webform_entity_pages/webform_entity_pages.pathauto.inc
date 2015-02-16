<?php

/**
 * @file
 * Pathauto integration for webform submission entities.
 */

/**
 * Batch processing callback; Generate aliases for webform submissions.
 */
function webform_entity_pages_pathauto_bulk_update_batch_process(&$context) {
  if (!isset($context['sandbox']['current'])) {
    $context['sandbox']['count'] = 0;
    $context['sandbox']['current'] = 0;
  }

  // Get the total amount of items to process.
  if (!isset($context['sandbox']['total'])) {
    $sids = db_select('webform_submissions', 'w')
      ->fields('w', array('sid'))
      ->orderBy('w.sid')
      ->execute()
      ->fetchCol();

    $query = db_select('webform_submissions', 'w')
      ->fields('w', array('sid'))
      ->orderBy('w.sid');
    $query->innerJoin('url_alias', 'ua', "CONCAT('webform-submission/', w.sid) = ua.source");
    $aliased_sids = $query
      ->execute()
      ->fetchCol();

    $sids = array_diff($sids, $aliased_sids);

    $context['sandbox']['total'] = count($sids);
    $context['sandbox']['sids'] = array_chunk($sids, 25);
    // If there are no nodes to update, then stop immediately.
    if (!$context['sandbox']['total']) {
      $context['finished'] = 1;
      return;
    }
  }
  $sids = array_values(array_shift($context['sandbox']['sids']));
  webform_entity_pages_update_alias_multiple($sids);
  $context['sandbox']['count'] += count($sids);
  $context['sandbox']['current'] = max($sids);
  $context['message'] = t('Updated alias for webform submission @sid.', array('@sid' => end($sids)));
  if ($context['sandbox']['count'] != $context['sandbox']['total']) {
    $context['finished'] = $context['sandbox']['count'] / $context['sandbox']['total'];
  }
}

/**
 * Update the URL aliases for multiple webform submissions.
 *
 * @param $sids
 *   An array of submission IDs.
 * @param $options
 *   An optional array of additional options.
 */
function webform_entity_pages_update_alias_multiple(array $sids, array $options = array()) {
  $options += array('message' => FALSE);
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  foreach ($sids as $sid) {
    $submission = array_shift(webform_get_submissions(array('sid' => $sid)));
    $node = node_load($submission->nid);
    webform_entity_pages_update_alias($node, $submission, 'bulkupdate', $options);
  }
  if (!empty($options['message'])) {
    drupal_set_message(format_plural(count($sids), 'Updated URL alias for 1 submission.', 'Updated URL aliases for @count submissions.'));
  }
}

/**
 * Update the URL aliases for an individual webform submission.
 *
 * @param $node
 *   A node object.
 * @param $submission
 *   A webform submission object.
 * @param $op
 *   Operation being performed on the term ('insert', 'update' or 'bulkupdate').
 * @param $options
 *   An optional array of additional options.
 */
function webform_entity_pages_update_alias($node, $submission, $op, array $options = array()) {

  $module = 'webform_entity_pages';
  // Skip processing if the term has no pattern.
  if (!pathauto_pattern_load_by_entity($module, $node->type)) {
    return;
  }

  module_load_include('inc', 'pathauto');
  $uri = entity_uri('webform_submission_entity', $submission);
  pathauto_create_alias($module, $op, $uri['path'], array('webform_submission_entity' => $submission, 'node' => $node), $node->type, LANGUAGE_NONE);
}

