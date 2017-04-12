<?php

/**
 * @file
 * Code of the eMindHub request submission block features.
 */

/**
 * Implements hook_block_info().
 */
function emh_request_submission_block_info() {
  $blocks = array();

  $blocks['submission_count'] = array(
    'info' => t("Request - Answer count"),
    'cache' => DRUPAL_CACHE_PER_ROLE,
    'weight' => 1,
    'status' => 1,
    'region' => 'title_right',
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
function emh_request_submission_block_view($delta = '') {
  $block = array();

  switch ($delta) {
    case 'submission_count':
      $node = menu_get_object();
      if ($node && $node->status == NODE_PUBLISHED) {
        $submissions_count = emh_request_count_answers($node->nid);
        $value = '<a href="#request-submissions" class="btn btn-submission">';
        if ($submissions_count == 0) {
          $value .= t('No answer');
        }
        else {
          $value .= format_plural($submissions_count, '1 answer', '@count answers');
        }
        $value .= '</a>';
      }
      else {
        $value = '';
      }

      $block = array(
        'subject' => '<none>',
        'content' => $value,
      );
      break;
  }

  return $block;
}
