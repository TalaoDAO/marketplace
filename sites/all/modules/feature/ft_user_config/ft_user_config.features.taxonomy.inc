<?php
/**
 * @file
 * ft_user_config.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ft_user_config_taxonomy_default_vocabularies() {
  return array(
    'known_how' => array(
      'name' => 'How have you heard of us',
      'machine_name' => 'known_how',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 4,
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
    ),
    'skill' => array(
      'name' => 'Skills',
      'machine_name' => 'skill',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 4,
    ),
  );
}
