<?php

/**
 * @file
 * Page Controller example for Ghost
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2014 Christopher Skene
 */

/**
 * Implements hook_menu().
 */
function ghost_examples_menu() {

  $menu = array();
  $menu['my/page/callback'] = array(

    // Your page callback should always be the same.
    'page callback' => '\Drupal\\ghost\\Page\\PageController::createPage',

    // Your page arguments should start with your Controller, and the method
    // to call.
    'page arguments' => array(
      '\Drupal\\ghost_examples\\Page\\PageControllerExample',
      'myPageControllerViewCallback',
    ),

  );

  return $menu;
}
