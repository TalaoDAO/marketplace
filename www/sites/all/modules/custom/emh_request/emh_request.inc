<?php

/**
 * @file
 * Code of the eMindHub request custom features.
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
  if (empty($term)) return;

  $term_wrapper = entity_metadata_wrapper('taxonomy_term', $term);
  $term_name = $term_wrapper->language($language->language)->name_field->value();
  return '<span class="request-type-name">' . $term_name . '</span>';
}
