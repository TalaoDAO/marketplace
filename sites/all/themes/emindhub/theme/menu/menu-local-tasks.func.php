<?php
/**
 * @file
 * menu-local-tasks.func.php
 */

/**
 * Overrides theme_menu_local_tasks().
 */
function emindhub_menu_local_tasks(&$variables) {
  $output = '';

  echo '<pre>' . print_r($variables, TRUE) . '</pre>';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs--primary nav nav-tabs">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }

  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs--secondary pagination pagination-sm">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

function emindhub_menu_tabs_primary($tabs) {

  if (count($tabs['#primary']) <= '1') return '';
  else return $tabs['#primary'];

}
