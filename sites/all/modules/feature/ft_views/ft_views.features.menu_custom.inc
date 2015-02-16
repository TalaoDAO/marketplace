<?php
/**
 * @file
 * ft_views.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ft_views_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-ask.
  $menus['menu-ask'] = array(
    'menu_name' => 'menu-ask',
    'title' => 'Ask',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-burger-menu.
  $menus['menu-burger-menu'] = array(
    'menu_name' => 'menu-burger-menu',
    'title' => 'Burger Menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-findexpert.
  $menus['menu-findexpert'] = array(
    'menu_name' => 'menu-findexpert',
    'title' => 'FindExpert',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-footer-menu.
  $menus['menu-footer-menu'] = array(
    'menu_name' => 'menu-footer-menu',
    'title' => 'Footer menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-respond.
  $menus['menu-respond'] = array(
    'menu_name' => 'menu-respond',
    'title' => 'Respond',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-top-menu.
  $menus['menu-top-menu'] = array(
    'menu_name' => 'menu-top-menu',
    'title' => 'Top menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Ask');
  t('Burger Menu');
  t('FindExpert');
  t('Footer menu');
  t('Respond');
  t('Top menu');


  return $menus;
}
