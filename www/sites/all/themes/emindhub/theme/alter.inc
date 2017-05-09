<?php
/**
 * @file
 * alter.inc
 *
 * Contains various implementations of hook_*_alter().
 */

/**
 * Implements hook_css_alter().
 */
function emindhub_css_alter(&$css) {
  // Remove jQuery UI css files
  // http://drupal.stackexchange.com/a/38592
  $disabled_drupal_css = array(
    'misc/ui/jquery.ui.core.css',
    'misc/ui/jquery.ui.theme.css',
    'misc/ui/jquery.ui.datepicker.css',
    'misc/ui/jquery.ui.resizable.css',
    'misc/ui/jquery.ui.button.css',
    'misc/ui/jquery.ui.dialog.css',
    'misc/ui/jquery.ui.menu.css',
    'misc/ui/jquery.ui.autocomplete.css',
    'sites/all/modules/contrib/hybridauth/plugins/icon_pack/hybridauth_32/hybridauth_32.css',
    'sites/all/modules/sandbox/bootstrap_languages/bootstrap_languages.css',
    'sites/all/modules/patched/field_collection/field_collection.theme.css',
  );

  // Remove drupal default css files.
  foreach ($css as $key => $item) {
    if (in_array($key, $disabled_drupal_css)) {
      // Remove css and its altered version that can be added by jquery_update.
      unset($css[$css[$key]['data']]);
      unset($css[$key]);
    }
  }
}
