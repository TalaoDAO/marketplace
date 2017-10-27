<?php
/**
 * @file
 * ft_request.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ft_request_taxonomy_default_vocabularies() {
  return array(
    'request_type' => array(
      'name' => 'Request type',
      'machine_name' => 'request_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
      'emh_earnings' => 0,
    ),
  );
}
