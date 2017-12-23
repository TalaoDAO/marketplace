<?php

/**
 * @file
 * Ethereum registry admin.
 */

/**
 * List the users who signed the Ethereum registry.
 */
function _ethereum_registry_list() {

  $header = array(
    t('User'),
    t('Ethereum address'),
  );

  $rows = array();

  $table = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'caption' => t('Users who signed this Ethereum Drupal Registry'),
    'attributes' => array(
      'id' => 'ethereum_registry_list',
    ),
  ));

  // Security token for the Ajax callback to retrieve the Drupal user.
  $token = drupal_random_key();
  variable_set('ethereum_registry_list_token', $token);

  $settings = array(
    'token' => $token,
  );

  $build = array();
  $build['ethereum_registry_list'] = array(
    '#type' => 'markup',
    '#markup' => $table,
    '#attached' => array(
      'js' => array(
        array(
          'data' => array(
            'ethereum_registry' => $settings,
          ),
          'type' => 'setting',
        ),
        array(
          'type' => 'file',
          'data' => drupal_get_path('module', 'ethereum_registry') . '/js/ethereum_registry_list.js',
          array(
            'scope' => 'footer',
          ),
        ),
      ),
    ),
  );
  $build['ethereum_registry_list']['#attached']['library'][] = array('ethereum_smartcontract', 'register_drupal');

  return $build;
}
