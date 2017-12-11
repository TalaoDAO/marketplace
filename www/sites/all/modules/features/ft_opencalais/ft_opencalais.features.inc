<?php
/**
 * @file
 * ft_opencalais.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ft_opencalais_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_log_type().
 */
function ft_opencalais_default_log_type() {
  $items = array();
  $items['log_opencalais'] = entity_import('log_type', '{
    "type" : "log_opencalais",
    "label" : "Log Opencalais",
    "weight" : 0,
    "name_pattern" : "Log [log:id]",
    "name_edit" : "0",
    "done" : "0",
    "emh_earnings" : 0
  }');
  return $items;
}
