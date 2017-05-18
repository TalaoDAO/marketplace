<?php

/**
 * Implements hook_views_data().
 */
function one_time_login_views_data() {
  $data['users']['one_time_login_url'] = array(
    'field' => array(
      'title' => t('One-time login URL'),
      'help' => t('A one-time login URL for the user'),
      'handler' => 'views_handler_field_one_time_login_url',
      'additional fields' => array('login', 'pass', 'uid'),
    ),
  );
  $data['users']['one_time_login_expiry'] = array(
    'field' => array(
      'title' => t('One-time login expiry'),
      'help' => t('Expiration date of the one-time login URL'),
      'handler' => 'views_handler_field_one_time_login_expiry',
      'additional fields' => array('login'),
    ),
  );
  return $data;
}

