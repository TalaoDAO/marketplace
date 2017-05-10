<?php

/**
 * @file
 * Code of the eMindHub Request custom features.
 */

/**
 * Helper function to render a submission.
 */
function emh_request_render_submission($submission) {
  $output = '';

  foreach ($submission->data as $submission) {
    $output .= $submission[0] . '&nbsp;';
  }

  return strip_tags(views_trim_text(
    array(
      'max_length' => 480,
      'word_boundary' => TRUE,
      'ellipsis' => TRUE,
      'html' => TRUE,
    ),
    truncate_utf8($output, 480, FALSE, TRUE)
  ));
}

/**
 * Helper function to retrieve the type of a request.
 */
function emh_request_get_request_type($node = NULL) {
  if ($node === NULL) {
    $node = menu_get_object();
  }
  elseif (is_numeric($node)) {
    $node = node_load($node);
  }

  if (empty($node)) {
    return;
  }

  $node_wrapper = entity_metadata_wrapper('node', $node);
  $term = $node_wrapper->field_request_type->value();

  if (empty($term)) {
    return;
  }

  return $term;
}

/**
 * Helper to get request type image.
 */
function emh_request_get_type_image($term, $size = 25, $style = NULL) {
  global $base_url, $language;

  $term_wrapper = entity_metadata_wrapper('taxonomy_term', $term);
  $term_name = $term_wrapper->language($language->language)->name_field->value();
  $term_safe_name = preg_replace('/[^A-Za-z0-9\-]/', '', strtolower($term_name));
  $style = isset($style) ? '-' . $style : '';
  return '<img src="' . $base_url . '/' . drupal_get_path('module', 'emh_request') . '/images/ico-' . $term_safe_name . $style . '.svg" width="' . $size . '" height="' . $size . '" alt="' . $term_name . '">';
}

/**
 * Helper to get request type image.
 */
function emh_request_get_request_type_image($node = NULL, $size = 25, $style = NULL) {
  $term = emh_request_get_request_type($node);
  if (empty($term)) {
    return;
  }

  return emh_request_get_type_image($term, $size, $style);
}

/**
 * Helper to get request type name.
 */
function emh_request_get_request_type_name($node = NULL) {
  global $base_url, $language;

  $term = emh_request_get_request_type($node);
  if (empty($term)) {
    return;
  }

  $term_wrapper = entity_metadata_wrapper('taxonomy_term', $term);
  $term_name = $term_wrapper->language($language->language)->name_field->value();
  return '<span class="request-type-name">' . $term_name . '</span>';
}

/**
 * Helper function to retrieve answers count.
 *
 * @param object $node
 *   The request.
 *
 * @return int
 *   Request answer count.
 */
function emh_request_count_answers($node) {
  if (is_numeric($node)) {
    $node = node_load($node);
  }

  $count = 0;

  if (!empty($node)) {
    switch ($node->type) {
      case 'request':
      case 'webform':
        include_once drupal_get_path('module', 'webform') . '/includes/webform.submissions.inc';
        $count = webform_get_submission_count($node->nid);
        break;

      case 'question1':
      case 'challenge':
        if (isset($node->comment_count)) {
          $count = $node->comment_count;
        }
        break;
    }
  }

  return $count;
}

/**
 * Save as draft access callback.
 *
 * @param int $nid
 *   Request nid.
 * @param object $account
 *   User account.
 *
 * @return bool
 *   TRUE or FALSE
 */
function emh_request_save_draft_access_callback($nid, $account = NULL) {
  if (empty($account)) {
    global $user;
    $account = $user;
  }

  $node = node_load($nid);

  // If current user is the circle admin, grant him/her the right to save it
  // as draft.
  if (module_exists('emh_circles')) {
    if (isset($node->og_group_ref) && ($circle_items = field_get_items('node', $node, 'og_group_ref'))) {
      $circles = array();

      foreach ($circle_items as $delta => $item) {
        $circles[] = $item['target_id'];
      }

      if (_emh_circles_user_is_groups_admin($account->uid, $circles)) {
        return TRUE;
      }
    }
  }

  // If request is already published, avoid author to save it as draft again.
  if (!empty($nid) && $node->status == NODE_PUBLISHED) {
    return FALSE;
  }

  return TRUE;
}

/**
 * Save as draft disabled callback.
 *
 * @param int $nid
 *   Request nid.
 *
 * @return bool
 *   TRUE or FALSE
 */
function emh_request_save_draft_disabled_callback($nid) {
  $node = node_load($nid);

  // If request has one and more answer OR has credits.
  return ((emh_request_count_answers($nid) != 0) || (emh_points_custom_request_count_options_cost($node) != 0));
}

/**
 * Save as draft attributes callback.
 *
 * @param int $nid
 *   Request nid.
 * @param object $account
 *   User account.
 *
 * @return array
 *   Attributes.
 */
function emh_request_save_draft_attributes_callback($nid, $account = NULL) {
  $node = node_load($nid);
  $attributes = array();

  // If request has one and more answer OR has credits, no frackin' way to save
  // it as draft!
  if (emh_request_count_answers($nid) != 0 || emh_points_custom_request_count_options_cost($node) != 0) {
    $attributes = array(
      'data-toggle' => 'tooltip',
      'data-placement' => 'top',
      'title' => t('You cannot unpublish this request:') . ' ',
    );

    $answers_title = t('there is one or more published answer');
    $credits_title = t('credits have been allocated');

    if (emh_request_count_answers($nid) != 0 && emh_points_custom_request_count_options_cost($node) != 0) {
      $attributes['title'] .= $answers_title . ', ' . $credits_title;
    }
    if (emh_request_count_answers($nid) != 0) {
      $attributes['title'] .= $answers_title;
    }
    if (emh_points_custom_request_count_options_cost($node) != 0) {
      $attributes['title'] .= $credits_title;
    }
    $attributes['title'] .= '.';
  }

  return $attributes;
}

/**
 * Save as draft submit callback.
 */
function emh_request_save_draft_submit_callback($form, &$form_state) {
  global $user;
  $account = $user;

  $node = node_load($form_state['node']->nid);

  // If current user is the circle admin, redirect on frontpage.
  if (module_exists('emh_circles')) {
    if (isset($node->og_group_ref) && ($circle_items = field_get_items('node', $node, 'og_group_ref'))) {
      $circles = array();

      foreach ($circle_items as $delta => $item) {
        $circles[] = $item['target_id'];
      }

      if (_emh_circles_user_is_groups_admin($account->uid, $circles)) {
        $form_state['redirect'] = '<front>';
      }
    }
  }
}
