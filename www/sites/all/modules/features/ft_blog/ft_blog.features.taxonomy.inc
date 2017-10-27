<?php
/**
 * @file
 * ft_blog.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ft_blog_taxonomy_default_vocabularies() {
  return array(
    'publications' => array(
      'name' => 'Publications',
      'machine_name' => 'publications',
      'description' => 'Publications taxonomy',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'emh_earnings' => 0,
    ),
  );
}
