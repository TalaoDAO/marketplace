<?php

function emindhub_preprocess_menu_link(&$vars) {

  // Reference the menu item
  $element = &$vars['element'];

  // echo '<pre>' . print_r($element, TRUE) . '</pre>';

  // TODO: se baser sur le chemin system ?

  switch ($element['#original_link']['mlid']) {

    // User menu > Account
    case '7829': // Local
    case '7702': // PreProd
    case '7579': // Prod
      global $user;
      $account = user_load($user->uid);
      $firstName = "";
      if (!empty($account->field_first_name[LANGUAGE_NONE])) {
        $firstName = check_plain($account->field_first_name[LANGUAGE_NONE][0]['value']);
      }
      $lastName = "";
      if (!empty($account->field_last_name[LANGUAGE_NONE])) {
        $lastName = check_plain($account->field_last_name[LANGUAGE_NONE][0]['value']);
      }
      $name = $firstName . '&nbsp;<span class="emh-blue bold text-uppercase">' . $lastName . '</span>';
      $element['#title'] = $name;
      $element['#localized_options']['html'] = 1;
      break;
  }
}


/**
 * Overrides theme_menu_link().
 */
function emindhub_menu_link__user_menu(&$vars) {
  $element = &$vars['element'];

  if (module_exists('emh_points')) {
    if ($element['#href'] == 'credits') {
      global $user;

      // Loads the whole user data
      if (!isset($user->emh_points)) {
        $user = user_load($user->uid);
      }

      $element['#title'] = '<span class="badge">' . t('@amount credits', array('@amount' => $user->emh_points)) . '</span>';
      $element['#localized_options']['html'] = TRUE;
    }
  }

  return bootstrap_menu_link($vars);
}


/**
 * Overrides theme_menu_tree().
 */
function emindhub_menu_tree__user_menu(&$variables) {
  return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}
function emindhub_menu_tree__menu_top(&$variables) {
  return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}
function emindhub_menu_tree__menu_top_anonymous(&$variables) {
  return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}
// function emindhub_menu_tree__main_menu(&$variables) {
//   return '<ul class="menu nav nav-justified">' . $variables['tree'] . '</ul>';
// }
// function emindhub_menu_tree__menu_burger_menu(&$variables) {
//   return '<ul class="menu nav navbar-emh-burger">' . $variables['tree'] . '</ul>';
// }
function emindhub_menu_tree__menu_footer_menu(&$variables) {
  return '<ul class="menu nav navbar-nav navbar-emh-separator navbar-right">' . $variables['tree'] . '</ul>';
}
function emindhub_menu_tree__menu_networks(&$variables) {
  return '<ul class="menu nav navbar-nav navbar-emh-separator navbar-right">' . $variables['tree'] . '</ul>';
}
