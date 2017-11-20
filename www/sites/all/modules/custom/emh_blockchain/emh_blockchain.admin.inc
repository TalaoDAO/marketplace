<?php

/**
 * @file
 * EMH Blockchain settings.
 */

/**
 * Implements hook_admin_form().
 */
function emh_blockchain_admin_form() {
  $form = array();

  $form['emh_blockchain_voting_deployed_contract_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Voting: deployed contract address'),
    '#default_value' => variable_get('emh_blockchain_voting_deployed_contract_address'),
  );

  $form['emh_blockchain_voting_deployed_contract_address_fallback'] = array(
    '#type' => 'textfield',
    '#title' => t('Voting: deployed contract address fallback'),
    '#default_value' => variable_get('emh_blockchain_voting_deployed_contract_address_fallback'),
  );

  $form['emh_blockchain_register_drupal_deployed_contract_address_fallback'] = array(
    '#type' => 'textfield',
    '#title' => t('Register drupal: deployed contract address fallback'),
    '#default_value' => variable_get('emh_blockchain_register_drupal_deployed_contract_address_fallback'),
  );

  $form['emh_blockchain_RegisterDrupal_deployed_contract_ABI'] = array(
    '#type' => 'textarea',
    '#title' => t('Register drupal: deployed contract ABI'),
    '#default_value' => variable_get('emh_blockchain_RegisterDrupal_deployed_contract_ABI'),
  );

  return system_settings_form($form);
}
