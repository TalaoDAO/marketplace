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

  // Exported menu: menu-footer-menu.
  $menus['menu-footer-menu'] = array(
    'menu_name' => 'menu-footer-menu',
    'title' => 'Footer menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-top.
  $menus['menu-top'] = array(
    'menu_name' => 'menu-top',
    'title' => 'Dashboard menu',
    'description' => 'Top navigation for authentificated users.',
    'language' => 'und',
    'i18n_mode' => 5,
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
  t('Dashboard menu');
  t('Footer menu');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('Top anonymous');
  t('Top navigation for authentificated users.');
  t('User menu');

  return $menus;
}
