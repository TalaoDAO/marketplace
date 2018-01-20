<?php

/**
 * @file
 * Ghost examples for Form Controllers.
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2014 Christopher Skene
 */

/**
 * How to call a form within a function.
 */
function ghost_examples_form_controller() {

  $form = drupal_get_form('ghost_form', 'Drupal\ghost_examples\Form\ExampleForm');
  $output = drupal_render($form);

  return $output;
}

/**
 * Implements hook_menu().
 *
 * Calling your form from a menu callback.
 */
function ghost_examples_menu() {

  $menu = array();
  $menu['my/page/callback'] = array(

    // Your page callback should always be the same.
    'page callback' => 'drupal_get_form',

    // Your page arguments should start with your Controller, and the method
    // to call.
    'page arguments' => array(
      'ghost_form',
      'Drupal\ghost_examples\Form\ExampleForm',
    ),

  );

  return $menu;
}
