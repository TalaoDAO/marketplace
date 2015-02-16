<?php
/**
 * @file
 * answers.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function answers_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-using-answers.
  $menus['menu-using-answers'] = array(
    'menu_name' => 'menu-using-answers',
    'title' => 'Using Answers',
    'description' => 'The "Using Answers" menu contains several links that are helpful for using the Q&A service',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('The "Using Answers" menu contains several links that are helpful for using the Q&A service');
  t('Using Answers');


  return $menus;
}
