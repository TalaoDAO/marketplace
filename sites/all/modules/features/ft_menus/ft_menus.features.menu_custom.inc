<?php
/**
 * @file
 * ft_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ft_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
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
    'i18n_mode' => 0,
  );
  // Exported menu: menu-findexpert.
  $menus['menu-findexpert'] = array(
    'menu_name' => 'menu-findexpert',
    'title' => 'FindExpert',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
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
  // Exported menu: menu-top.
  $menus['menu-top'] = array(
    'menu_name' => 'menu-top',
    'title' => 'Top',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 1,
  );
  // Exported menu: menu-top-anonymous.
  $menus['menu-top-anonymous'] = array(
    'menu_name' => 'menu-top-anonymous',
    'title' => 'Top anonymous',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Ask');
  t('Burger Menu');
  t('FindExpert');
  t('Footer menu');
  t('Main menu');
  t('Respond');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('Top');
  t('Top anonymous');
  t('User menu');


  return $menus;
}
