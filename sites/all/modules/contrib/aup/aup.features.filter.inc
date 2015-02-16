<?php
/**
 * @file
 * aup.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function aup_filter_default_formats() {
  $formats = array();

  // Exported format: PHP code.
  $formats['php_code'] = array(
    'format' => 'php_code',
    'name' => 'PHP code',
    'cache' => '0',
    'status' => '1',
    'weight' => '11',
    'filters' => array(
      'php_code' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
