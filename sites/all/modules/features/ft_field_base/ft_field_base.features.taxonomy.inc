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
      'i18n_mode' => 0,
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
    'known_how' => array(
      'name' => 'How have you heard of us',
      'machine_name' => 'known_how',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'notification_frequencies' => array(
      'name' => 'Notification frequencies',
      'machine_name' => 'notification_frequencies',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'skill' => array(
      'name' => 'Skills',
      'machine_name' => 'skill',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
