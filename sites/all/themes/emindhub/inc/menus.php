<?php

function emindhub_menu_alter(&$items) {
  unset($items['user/register']);
  $items['user/%user/hybridauth']['access callback'] = FALSE;
  $items['user/%user/edit']['title'] = 'Edit account';
}


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
        $firstName = $account->field_first_name[LANGUAGE_NONE][0]['value'];
      }
      $lastName = "";
      if (!empty($account->field_last_name[LANGUAGE_NONE])) {
        $lastName = $account->field_last_name[LANGUAGE_NONE][0]['value'];
      }
      $name = $firstName . '&nbsp;<span class="emh-blue bold text-uppercase">' . $lastName . '</span>';
      $element['#title'] = $name;
      $element['#localized_options']['html'] = 1;
      break;

  }
  switch ($element['#href']) {

    // User menu > Points
    case 'points':
      $element['#localized_options']['html'] = 1;
      break;

  }

}


/**
 * Overrides theme_menu_tree().
 */
function emindhub_menu_tree__user_menu(&$variables) {
  return '<ul class="menu nav navbar-nav navbar-emh-separator">' . $variables['tree'] . '</ul>';
}
function emindhub_menu_tree__menu_top(&$variables) {
  return '<ul class="menu nav nav-justified">' . $variables['tree'] . '</ul>';
}
function emindhub_menu_tree__menu_top_anonymous(&$variables) {
  return '<ul class="menu nav nav-justified">' . $variables['tree'] . '</ul>';
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
