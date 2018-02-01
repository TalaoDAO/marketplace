<?php

/**
 * @file
 * Configure the user hash module.
 */

/**
 * Menu callback: user hash settings form.
 */
function user_hash_settings_form($form, &$form_state) {
  $form['user_hash_algorithm'] = array(
    '#type' => 'select',
    '#title' => t('Hash algorithms'),
    '#description' => t('Choose which hash algorithm to use.'),
    '#options' => drupal_map_assoc(hash_algos()),
    '#default_value' => variable_get('user_hash_algorithm', USER_HASH_ALGORITHM_DEFAULT),
  );

  $form['user_hash_random_bytes'] = array(
    '#type' => 'textfield',
    '#title' => t('Random bytes'),
    '#description' => t('Configure how many characters to use for the random value at hash generation. See <a href="@drupal_random_bytes" target="_blank">drupal_random_bytes()</a>.', array('@drupal_random_bytes' => 'https://api.drupal.org/api/drupal/includes!bootstrap.inc/function/drupal_random_bytes/7')),
    '#default_value' => variable_get('user_hash_random_bytes', USER_HASH_RANDOM_BYTES_DEFAULT),
    '#size' => 10,
    '#element_validate' => array('element_validate_integer_positive'),
  );

  return system_settings_form($form);
}
