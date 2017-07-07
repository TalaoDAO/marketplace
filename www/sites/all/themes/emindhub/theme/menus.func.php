<?php

function emindhub_preprocess_menu_link(&$vars) {
  // Reference the menu item
  $element = &$vars['element'];

  // TODO: se baser sur le chemin system ?
  switch ($element['#original_link']['mlid']) {
    // User menu > Account
    case '7702':
      global $user;
      $account = user_load($user->uid);
      $element['#title'] = format_username($account);
      break;
  }
}

/**
 * Implements theme_menu_link__MENU_NAME().
 */
function emindhub_menu_link__user_menu(&$vars) {
  $element = &$vars['element'];

  if (module_exists('emh_points')) {
    if ($element['#href'] == 'credits') {
      global $user;

      // Loads the whole user data.
      if (!isset($user->emh_points)) {
        $user = user_load($user->uid);
      }

      $element['#title'] = '<span class="credits">' . $user->emh_points . '</span>';
      $element['#localized_options']['html'] = TRUE;
    }
  }

  return bootstrap_menu_link($vars);
}

/**
 * Implements theme_menu_tree__MENU_NAME().
 */
function emindhub_menu_tree__user_menu(&$variables) {
  return '<ul id="system-user-menu" class="menu nav navbar-nav navbar-right">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_tree__MENU_NAME().
 */
function emindhub_menu_tree__menu_top(&$variables) {
  return '<ul id="menu-menu-top" class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_tree__MENU_NAME().
 */
function emindhub_menu_tree__menu_top_anonymous(&$variables) {
  return '<ul id="menu-menu-top-anonymous" class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_tree__MENU_NAME().
 */
function emindhub_menu_tree__menu_footer_menu(&$variables) {
  return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_tree__MENU_NAME().
 */
function emindhub_menu_tree__menu_networks(&$variables) {
  return '<ul class="menu nav navbar-nav navbar-right">' . $variables['tree'] . '</ul>';
}
