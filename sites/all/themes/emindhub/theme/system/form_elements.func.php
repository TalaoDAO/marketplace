<?php

/**
 * Display the text associated with a static star display.
 *
 * Note that passing in explicit data types is extremely important when using
 * this function. A NULL value will exclude the value entirely from display,
 * while a 0 value indicates that the text should be shown but it has no value
 * yet.
 *
 * All ratings are from 0 to 100.
 *
 * @param $user_rating
 *   The current user's rating.
 * @param $average
 *   The average rating.
 * @param $votes
 *   The total number of votes.
 * @param $stars
 *   The number of stars being displayed.
 * @return
 *   A themed HTML string representing the star widget.
 */
function emindhub_fivestar_summary($variables) {
  // We hide public profile legend : there's only one vote, user's one
  $output = '';
  return $output;
}


function emindhub_date_combo($variables) {
  // Retourne le champ date de manière simplifiée
  return theme('form_element', $variables);
}


function emindhub_my_file_element_process(&$element, &$form_state, $form) {

  $element = file_managed_file_process($element, $form_state, $form);
  // $element['upload_button']['#attributes']['class'][] = 'btn-info';

  return $element;

}


// Bootstrap compliance : design select
function emindhub_preprocess_select_as_checkboxes(&$variables) {
  $element = &$variables['element'];
  // Remove form-control class added to original "select" element
  if (($key = array_search('form-control', $element['#attributes']['class'])) !== false) {
    unset($element['#attributes']['class'][$key]);
  }
}
