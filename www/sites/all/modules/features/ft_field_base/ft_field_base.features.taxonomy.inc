<?php
/**
 * @file
 * ft_field_base.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ft_field_base_taxonomy_default_vocabularies() {
  return array(
    'expertise' => array(
      'name' => 'Expertise',
      'machine_name' => 'expertise',
      'description' => 'Fields of expertise',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 32768,
      'emh_earnings' => 0,
    ),
  );
}
