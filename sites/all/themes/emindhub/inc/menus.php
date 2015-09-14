<?php

function emindhub_menu_alter(&$items) {
  unset($items['user/register']);
}


function emindhub_preprocess_menu_link(&$vars) {
  // TODO : altérer uniquement le lien spécifique et non pas le lien par URL

  // Reference the menu item
  $element = &$vars['element'];

  switch ($element['#href']) {
    case 'user':
      global $user;
      $account = user_load($user->uid);
      $firstName = "";
      if (isset($account->field_first_name[LANGUAGE_NONE]) && $account->field_first_name[LANGUAGE_NONE]) {
        $firstName = $account->field_first_name[LANGUAGE_NONE][0]['value'];
      }
      $lastName = "";
      if (isset($account->field_last_name[LANGUAGE_NONE]) && $account->field_last_name[LANGUAGE_NONE]) {
        $lastName = $account->field_last_name[LANGUAGE_NONE][0]['value'];
      }
      $name = $firstName . '&nbsp;<span class="emh-blue bold text-uppercase">' . $lastName . '</span>';
      $element['#title'] = $name;
      $element['#localized_options']['html'] = 1;
      break;
  }

}


/**
 * Overrides theme_menu_tree().
 */
function bootstrap_menu_tree__user_menu(&$variables) {
  return '<ul class="menu nav navbar-nav navbar-emh-separator">' . $variables['tree'] . '</ul>';
}
function bootstrap_menu_tree__menu_top(&$variables) {
  return '<ul class="menu nav nav-justified">' . $variables['tree'] . '</ul>';
}
function bootstrap_menu_tree__menu_top_anonymous(&$variables) {
  return '<ul class="menu nav nav-justified">' . $variables['tree'] . '</ul>';
}
// function bootstrap_menu_tree__menu_burger_menu(&$variables) {
//   return '<ul class="menu nav navbar-emh-burger">' . $variables['tree'] . '</ul>';
// }
function bootstrap_menu_tree__menu_footer_menu(&$variables) {
  return '<ul class="menu nav navbar-nav navbar-emh-separator navbar-right">' . $variables['tree'] . '</ul>';
}
