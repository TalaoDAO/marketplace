<?php
/**
 * @file
 * ft_faq.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ft_faq_taxonomy_default_vocabularies() {
  return array(
    'faq' => array(
      'name' => 'FAQ',
      'machine_name' => 'faq',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
