<?php

/**
 * @file
 * Code of the eMindHub Request Timeline custom features.
 */

/**
 * Helper function to retrieve the status of a request.
 *
 * @param object $node
 *   The request node.
 *
 * @return array
 *   Status infos. Can be draft / open / expired / closed.
 */
function emh_request_workflow_get_status($node = NULL) {
  if ($node === NULL) {
    $node = menu_get_object();
  }
  elseif (is_numeric($node)) {
    $node = node_load($node);
  }

  $workflow = array();
  $today = $deadline = '';

  if ($node->status == 0) {
    $workflow = array(
      'status' => 'draft',
      'label' => t('Draft'),
    );
  }
  else {
    if (!emh_points_get_points_closed_status($node->nid)) {
      $today = date('Y-m-d H:i:s');
      $items = field_get_items('node', $node, 'field_expiration_date');
      $deadline = isset($items[0]['value']) ? $items[0]['value'] : '';
      $deadline = date('Y-m-d H:i:s', strtotime("$deadline +1 day"));

      if ($today < $deadline) {
        $workflow = array(
          'status' => 'open',
          'label' => t('Open'),
        );
      }
      else {
        $workflow = array(
          'status' => 'expired',
          'label' => t('Expired'),
        );
      }
    }
    else {
      $workflow = array(
        'status' => 'closed',
        'label' => t('Closed'),
      );
    }
  }

  return $workflow;
}

/**
 * Get Submission status & timeline.
 *
 * @param object $request
 *   The request node.
 *
 * @return array
 *   Timeline infos.
 */
function emh_request_workflow_get_timeline($request) {
  $timeline = array();

  $status = emh_request_workflow_get_status($request->nid);
  $status = $status['status'];

  $now = date('Y/m/d');
  $nowDate = new DateTime($now);

  $created = date('Y/m/d', $request->created);
  $createdDate = new DateTime($created);

  $deadline = field_get_items('node', $request, 'field_expiration_date');
  $deadlineDate = new DateTime($deadline[0]['value']);

  $intervalNow = $createdDate->diff($nowDate);
  $intervalNow = $intervalNow->format('%a day(s)');

  $intervalDeadline = $createdDate->diff($deadlineDate);
  $intervalDeadline = $intervalDeadline->format('%a day(s)');

  if ($status != 'closed') {
    if ($nowDate < $deadlineDate) {
      $intervalLeft = $nowDate->diff($deadlineDate);
      $intervalLeft = $intervalLeft->format('%a day(s) left');
    }
    elseif ($nowDate == $deadlineDate) {
      $intervalLeft = 'Last chance to answer!';
    }
    else {
      $intervalLeft = 'Expired';
    }
  }
  else {
    $intervalLeft = t('Closed');
  }

  $progression = round(($intervalNow / $intervalDeadline) * 100);

  $timeline = array(
    'status' => $status,
    'now' => $now,
    'created' => $created,
    'deadline' => $deadlineDate->format('Y/m/d'),
    'progression' => $progression,
    'left' => $intervalLeft,
    'soon' => ($progression >= 90 || $nowDate == $deadlineDate),
  );

  return $timeline;
}
