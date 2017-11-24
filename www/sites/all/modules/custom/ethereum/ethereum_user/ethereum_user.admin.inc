<?php

/**
 * @file
 * Ethereum user settings.
 */

/**
 * Implements hook_admin_form().
 */
function ethereum_user_admin_form() {
  $form = array();

  $form['ethereum_user_register_drupal_deployed_contract_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Deployed contract address for your Ethereum Drupal user registry'),
    '#default_value' => variable_get('ethereum_user_register_drupal_deployed_contract_address'),
  );

  $form['ethereum_user_register_drupal_deployed_contract_abi'] = array(
    '#type' => 'textarea',
    '#title' => t('Deployed contract ABI for your Ethereum Drupal user registry'),
    '#default_value' => variable_get('ethereum_user_register_drupal_deployed_contract_abi'),
  );

  $form['ethereum_user_register_drupal_fallback_node'] = array(
    '#type' => 'textfield',
    '#title' => t('Fallback Ethereum node'),
    '#default_value' => variable_get('ethereum_user_register_drupal_fallback_node', 'http://localhost:8545'),
  );

  return system_settings_form($form);
}
