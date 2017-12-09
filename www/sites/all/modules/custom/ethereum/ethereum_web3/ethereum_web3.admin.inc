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

    drupal_set_message(
      t(
        'Web3.js locally installed, version @version. <a href="@report">Full report</a>', array(
          '@version' => $library['version'],
          '@report' => url('admin/reports/libraries/web3'),
        )
      )
    );

    $form['ethereum_web3_local_injection'] = array(
      '#type' => 'checkbox',
      '#title' => t('Inject local Web3.js library'),
      '#description' => t('Check to inject Web3.js locally. You need to specify an Ethereum node to connect to, or have a local node running at the usual http://localhost:8545. Local Web3.js injection is not compatible with injection from Metamask.'),
      '#default_value' => variable_get('ethereum_web3_local_injection', FALSE),
    );
  }

  // Else don't provide settings.
  else {
    drupal_set_message(t('Web3.js not locally installed.'), 'warning');
  }

  $form['ethereum_web3_node'] = array(
    '#type' => 'textfield',
    '#title' => t('Ethereum node'),
    '#description' => t('Ethereum node to connect to. Defaults to http://localhost:8545.'),
    '#default_value' => variable_get('ethereum_web3_node', 'http://localhost:8545'),
  );

  return system_settings_form($form);
}
