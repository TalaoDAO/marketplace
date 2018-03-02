<?php

/**
 * @file
 * EMH Blockchain settings.
 */

/**
 * Implements hook_admin_form().
 */
function ethereum_token_admin_form() {
  $form = array();

  $form['emh_blockchain_TokenEMH_deployed_contract_address_fallback'] = array(
    '#type' => 'textfield',
    '#title' => t('TokenEMH: deployed contract address fallback'),
    '#default_value' => variable_get('emh_blockchain_TokenEMH_deployed_contract_address_fallback'),
  );

  $form['emh_blockchain_TokenEMH_deployed_contract_ABI'] = array(
    '#type' => 'textarea',
    '#title' => t('TokenEMH: deployed contract ABI'),
    '#default_value' => variable_get('emh_blockchain_TokenEMH_deployed_contract_ABI'),
  );

  return system_settings_form($form);
}

