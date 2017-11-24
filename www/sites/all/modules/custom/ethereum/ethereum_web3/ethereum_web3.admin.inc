<?php

/**
 * @file
 * Ethereum web3 settings.
 */

/**
 * Implements hook_admin_form().
 */
function ethereum_web3_admin_form() {
  $form = array();

  // Try to load a local Web3.js.
  $library = libraries_load('web3');
  if ($library && !empty($library['loaded'])) {

    drupal_set_message(t('Web3.js locally installed, using it as a fallback.'));

    $form['ethereum_web3_local_injection'] = array(
      '#type' => 'checkbox',
      '#title' => t('Inject local Web3.js library as a fallback?'),
      '#description' => t('Check to inject Web3.js locally, as a fallback if no other Web3.js is already injected.'),
      '#default_value' => variable_get('ethereum_web3_local_injection', FALSE),
    );
  }

  // Else don't provide settings.
  else {
    drupal_set_message(t('Web3.js not locally installed, no fallback.'), 'warning');
  }

  return system_settings_form($form);
}
