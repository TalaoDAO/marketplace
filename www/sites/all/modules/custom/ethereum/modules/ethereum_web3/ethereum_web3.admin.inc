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

    // Ethereum network.
    $form['ethereum_web3_network'] = array(
      '#type' => 'select',
      '#title' => t('Ethereum network'),
      '#description' => t('Specify which Ethereum network to use: main, ropsten or private.'),
      '#options' => array(
        'main' => t('Main network'),
        'morden' => t('Morden test network'),
        'ropsten' => t('Ropsten test network'),
        'private' => t('Private network'),
      ),
      '#default_value' => variable_get('ethereum_web3_network', 'ropsten'),
    );

    // Web3.js messages selector.
    $form['ethereum_web3_messages_selector'] = array(
      '#type' => 'textfield',
      '#title' => t('Web3.js messages selector'),
      '#description' => t('Enter a jQuery element selector to append a Web3.js messages div.'),
      '#default_value' => variable_get('ethereum_web3_messages_selector'),
    );

    // Web3.js base message class(es).
    $form['ethereum_web3_messages_base'] = array(
      '#type' => 'textfield',
      '#title' => t('Base CSS class(es) for Web3.js status message'),
      '#default_value' => variable_get('ethereum_web3_messages_base'),
    );

    // Web3.js status message class.
    $form['ethereum_web3_messages_status'] = array(
      '#type' => 'textfield',
      '#title' => t('CSS class for Web3.js status message'),
      '#default_value' => variable_get('ethereum_web3_messages_status'),
    );

    // Web3.js warning message class.
    $form['ethereum_web3_messages_warning'] = array(
      '#type' => 'textfield',
      '#title' => t('CSS class for Web3.js warning message'),
      '#default_value' => variable_get('ethereum_web3_messages_warning'),
    );

    // Web3.js error message class.
    $form['ethereum_web3_messages_error'] = array(
      '#type' => 'textfield',
      '#title' => t('CSS class for Web3.js error message'),
      '#default_value' => variable_get('ethereum_web3_messages_error'),
    );

    // Ethereum node to connect to for Backoffice tasks.
    $form['ethereum_web3_node'] = array(
      '#type' => 'textfield',
      '#title' => t('Ethereum node'),
      '#description' => t('Ethereum node to connect to for Backoffice tasks. Defaults to http://localhost:8545.'),
      '#default_value' => variable_get('ethereum_web3_node', 'http://localhost:8545'),
    );
  }

  // Else don't provide settings.
  else {
    drupal_set_message(t('Web3.js not locally installed.'), WATCHDOG_ERROR);
  }

  return system_settings_form($form);
}
