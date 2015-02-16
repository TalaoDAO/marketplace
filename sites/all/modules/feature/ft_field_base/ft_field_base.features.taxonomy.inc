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
    'domaine' => array(
      'name' => 'Domains',
      'machine_name' => 'domaine',
      'description' => 'Domaine de compétences',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 4,
    ),
    'forums' => array(
      'name' => 'Forums',
      'machine_name' => 'forums',
      'description' => 'Forum navigation vocabulary',
      'hierarchy' => 1,
      'module' => 'forum',
      'weight' => -10,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
