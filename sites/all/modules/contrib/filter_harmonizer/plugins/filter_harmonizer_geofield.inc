<?php

/**
 * @file
 * filter_harmonizer_geofield.inc
 */

/**
 * Implements hook_filter_harmonizer_set_alter().
 *
 * You could argue this implementation belongs in the Geofield module.
 */
function filter_harmonizer_filter_harmonizer_set_alter(&$data) {

  list($form, $form_state, $contextual_filter, $regular_filter, $filter_values) = $data;

  if ($contextual_filter->field != 'field_geofield_distance') {
    return;
  }
  $geofield = &$form['field_geofield_distance'];

  if (isset($form['field_geofield_distance']['origin']['lat']['#value'])) {
    $lat_lon_dist = $contextual_filter->parseLatLonDistArg($value);
    if (!$lat_lon_dist) {
      // Fallback, but should not happen.
      $lat_lon_dist = $contextual_filter->parseAddress($value);
    }
    if ($lat_lon_dist) {
      $geofield['origin']['lat']['#value'] = $lat_lon_dist['latitude'];
      $geofield['origin']['lon']['#value'] = $lat_lon_dist['longitude'];
      $geofield['distance']['#value'] = $lat_lon_dist['distance'];
    }
  }
  else {
    // See if there are contextual arguments in the URL.
    $args = array_slice(arg(), $contextual_filter->position + 1);
    $is_default = empty($args);
    if ($is_default) {
      $dist = $contextual_filter->getDefaultDist();
      $loc = $contextual_filter->get_default_argument(FALSE);
    }
    else {
      // There are args in the URL.
      $dist = is_numeric(end($args)) ? array_pop($args) : $contextual_filter->getDefaultDist();
      $loc = implode(', ', $args);
    }
    $geofield['distance']['#value'] = $dist;
    $geofield['origin']['#value'] = $loc;
  }
}
