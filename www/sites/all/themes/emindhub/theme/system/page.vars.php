<?php
/**
 * @file
 * page.vars.php
 */

/**
 * Implements hook_preprocess_page().
 *
 * @see page.tpl.php
 */
function emindhub_preprocess_page(&$variables) {
  // Burger menu icon
  $variables['openBurgerImg'] = theme('image', array(
    'path' => imagePath('menuBtn.png'),
    'alt' => '',
    'getsize' => FALSE,
  ));

  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-md-7"';
  }
  elseif (!empty($variables['page']['sidebar_first']) && empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-md-10"';
  }
  elseif (empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-md-9"';
  }
  else {
    $variables['content_column_class'] = ' class="col-md-12"';
  }

  $variables['baseline'] = emindhub_beautiful_baseline();

  // Landing pages
  if (isset($variables['node']) && !(arg(2) == 'edit')) {
    $variables['theme_hook_suggestion'] = 'page__node_'.$variables['node']->type;
  }

  drupal_add_js('https://cdnjs.cloudflare.com/ajax/libs/slick-carousel/1.6.0/slick.min.js', 'external');
  drupal_add_css('https://cdnjs.cloudflare.com/ajax/libs/slick-carousel/1.6.0/slick.min.css', 'external');
}
