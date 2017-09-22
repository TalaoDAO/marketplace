<?php
/**
 * @file
 * ft_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ft_content_type_taxonomy_default_vocabularies() {
  return array(
    'domaine' => array(
      'name' => 'Domains',
      'machine_name' => 'domaine',
      'description' => 'Domaine de compétences',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'emh_earnings' => 0,
    ),
    'known_how' => array(
      'name' => 'How have you heard of us',
      'machine_name' => 'known_how',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'emh_earnings' => 0,
    ),
    'notification_frequencies' => array(
      'name' => 'Notification frequencies',
      'machine_name' => 'notification_frequencies',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'emh_earnings' => 0,
    ),
    'position' => array(
      'name' => 'Position',
      'machine_name' => 'position',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'emh_earnings' => 0,
    ),
    'skill' => array(
      'name' => 'Skills',
      'machine_name' => 'skill',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'emh_earnings' => 0,
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
      'emh_earnings' => 0,
    ),
  );
}
