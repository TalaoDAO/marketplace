<?php

/**
 * Implements hook_form_FORM_ID_alter().
 */
function emh_circles_form_og_ui_edit_membership_alter(&$form, &$form_state) {
  global $user;

  $form['og_user']['roles']['#access'] = og_user_access_entity('administer group', arg(1), node_load(arg(2)), $user);
}
