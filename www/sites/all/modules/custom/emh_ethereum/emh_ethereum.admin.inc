<?php

/**
 * @file
 * EMH Ethereum admin.
 */

/**
 * Implements hook_admin_form().
 */
function emh_ethereum_admin_form() {
  $form = array();

  $form['emh_ethereum_marketplace'] = array(
    '#type' => 'textfield',
    '#title' => t('Marketplace Ethereum address'),
    '#description' => t('Ethereum address of the Marketplace, used when signing joinDaoFromMarketplace().'),
    '#default_value' => variable_get('emh_ethereum_marketplace'),
  );

  $form['emh_ethereum_dao'] = array(
    '#type' => 'textfield',
    '#title' => t('Talao DAO root URL'),
    '#description' => t('Root URL of the Talao DAO.'),
    '#default_value' => variable_get('emh_ethereum_dao'),
  );

  return system_settings_form($form);
}

/**
 * Lists the active freelancers on the DAO.
 */
function _emh_ethereum_freelancer_list() {

  $header = array(
    t('User (link to account on Marketplace)'),
    t('Ethereum address (link to profile on Talao DAO)'),
  );

  $rows = array();

  $table = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'caption' => t('Active Freelancers in the Talao DAO'),
    'attributes' => array(
      'id' => 'emh_ethereum_Freelancer_list',
    ),
  ));

  // Security token for the Ajax callback to retrieve the Drupal user.
  $token = drupal_random_key();
  variable_set('emh_ethereum_freelancer_list_token', $token);

  $settings = array(
    'marketplace' => variable_get('emh_ethereum_marketplace'),
    'token' => $token,
  );

  $build = array();
  $build['emh_ethereum_Freelancer_list'] = array(
    '#type' => 'markup',
    '#markup' => $table,
    '#attached' => array(
      'js' => array(
        array(
          'data' => array(
            'emh_ethereum_Freelancer_list' => $settings,
          ),
          'type' => 'setting',
        ),
        array(
          'type' => 'file',
          'data' => drupal_get_path('module', 'emh_ethereum') . '/js/emh_ethereum_admin_people_freelancer.js',
          array(
            'scope' => 'footer',
          ),
        ),
      ),
    ),
  );
  $build['ethereum_registry_list']['#attached']['library'][] = array('ethereum_smartcontract', 'freelancer');

  return $build;
}
