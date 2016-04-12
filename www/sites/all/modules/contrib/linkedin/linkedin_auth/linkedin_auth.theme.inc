<?php

/*
 * @file Overridable theme functions
 */

/*
 * Renders the "login using LinkedIn" block button
 * Possible displays are :
 * drupal_login_page
 * drupal_login_block
 * linkedin_login_block
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function theme_linkedin_auth_display_login_block_button($variables) {
  $display = $variables['display'];
  $path = $variables['path'];
  $text = $variables['text'];
  drupal_add_css(drupal_get_path('module', 'linkedin_auth') . '/linkedin_auth.css');
  $data = l(t($text), $path);
  $class = 'linkedin-auth-login-link';
  if ($display) {
    $class .= '-' . str_replace('_', '-', $display);
  }
  $items[] = array(
    'data' => $data,
    'attributes' => array(
      'class' => $class,
    ),
  );
  return theme('item_list', array('items' => $items));
}
