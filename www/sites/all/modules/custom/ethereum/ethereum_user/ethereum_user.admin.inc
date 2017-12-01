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

/**
 * List the users who signed the Ethereum registry.
 */
function _ethereum_user_registry_list() {

  $header = array(
    t('User Ethereum address'),
    t('User hash'),
    t('User'),
  );

  $rows = array(
  );

  $table = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'caption' => t('Users who signed this site\'s Ethereum user registry'),
    'attributes' => array(
      'id' => 'ethereum_user_registry_list',
    ),
  ));

  $settings = array(
    'contract' => array(
      'address' => variable_get('ethereum_user_register_drupal_deployed_contract_address'),
      'abi' => variable_get('ethereum_user_register_drupal_deployed_contract_abi'),
    ),
    'fallback_node' => variable_get('ethereum_user_register_drupal_fallback_node'),
  );

  $render['ethereum_user_registry_list'] = array(
    '#type' => 'markup',
    '#markup' => $table,
    '#attached' => array(
      'js' => array(
        array(
          'data' => array(
            'ethereum_user' => $settings,
          ),
          'type' => 'setting',
        ),
        drupal_get_path('module', 'ethereum_user') . '/js/ethereum_user_registry_list.js',
      ),
    ),
  );
  $render['ethereum_user_registry_list']['#attached']['libraries_load'][] = array('web3');
  return $render;
}
