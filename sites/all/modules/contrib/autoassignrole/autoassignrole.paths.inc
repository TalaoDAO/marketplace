<?php

/**
 * @file
 * Paths used for autoassignrole created user pages.
 *
 * Autoassignrole allows an admin to create specific register, login and reset
 * password pages for a particular set of roles. The menu callback arguments
 * for these pages are defined here.
 *
 * These functions simply call the standard user forms from Drupal core, the
 * reason we wrap them like this is so that we can detect when one of our
 * role-specific pages are being called rather than the default ones.
 */

//We require this file from the user module to get the user_pass form.
require_once drupal_get_path('module', 'user') . '/user.pages.inc';

/**
 * Loads the user registration form.
 *
 * $rid is not actually used in the function but by passing it we can find out
 * which roles are meant to be added to the new user by using
 * autoassignrole_get_active_path_rid();
 *
 * @see autoassignrole.module
 *
 * @param $rid
 *   $rid is the 'rid_page_id' of the page we are currently generating.
 *
 * @return string
 *   User registration form renderer.
 */
function autoassignrole_register($rid) {
  $output = drupal_get_form('user_register_form');
  return $output;
}

/**
 * Loads the user login form
 */
function autoassignrole_login() {
  $output = drupal_get_form('user_login');
  return $output;
}

/**
 * Loads the password reset form
 */
function autoassignrole_password() {
  $output = drupal_get_form('user_pass');
  return $output;
}
