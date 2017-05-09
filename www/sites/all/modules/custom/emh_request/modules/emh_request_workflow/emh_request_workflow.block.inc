<?php

/**
 * @file
 * Code of the eMindHub Request Workflow blocks feature.
 */

/**
 * Implements hook_block_info().
 */
function emh_request_workflow_block_info() {
  $blocks['timeline'] = array(
    'info' => t("Request - Timeline"),
    'cache' => DRUPAL_CACHE_PER_ROLE,
    'weight' => 0,
    'status' => 1,
    'region' => 'title',
    'visibility' => BLOCK_VISIBILITY_LISTED,
    'pages' => 'node/*',
    'node_types' => array(
      0 => 'request',
    ),
  );

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function emh_request_workflow_block_view($delta) {
  switch ($delta) {
    case 'timeline':
      $block = array(
        'subject' => '<none>',
        'content' => _emh_request_workflow_view(),
      );
      break;
  }
  return $block;
}

/**
 * Helper for timeline block view.
 *
 * @return array
 *   Themed timeline.
 */
function _emh_request_workflow_view() {
  $request = menu_get_object();

  if (!$request || $request->status == NODE_NOT_PUBLISHED) {
    return;
  }

  $timeline = emh_request_workflow_get_timeline($request);

  if ($timeline['status'] == 'open') {
    if ($timeline['soon'] === TRUE) {
      $class = 'warning';
    }
    else {
      $class = 'success';
    }
  }
  else {
    $class = 'inactive';
  }

  return theme('timeline', array(
    'class' => $class,
    'created' => $timeline['created'],
    'deadline' => $timeline['deadline'],
    'progression' => $timeline['progression'],
    'left' => $timeline['left'],
  ));
}
