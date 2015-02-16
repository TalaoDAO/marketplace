<?php
/**
 * @file
 * Documentation of the API functions exposed by this module.
 */

/**
 * Implements hook_og_menu_admin_menu_overview_form_tableselect().
 *
 * Useful for other module that extend the functionality of the og menu admin
 * overview form.
 * When a module returns TRUE, the menu table will be rendered with checkboxes
 * in the left column.
 *
 * @return bool
 */
function og_menu_og_menu_admin_menu_overview_form_tableselect() {
  return TRUE;
}

/**
 * Implements hook_og_menu_audience_fields_alter().
 */
function og_menu_og_menu_audience_fields(&$group_audience_fields, $type) {
  if ($type == 'group_page') {
    unset($group_audience_fields['some_field']);
  }
}
