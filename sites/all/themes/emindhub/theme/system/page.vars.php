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

  // Beta version
  if ( drupal_is_front_page() && user_is_logged_in() ) {
    global $base_url;
    drupal_set_message(t('<strong>Welcome to eMindHub!</strong> Thank you for being among the first users of our platform! This is a beta version, for any suggestion or comment please leave a message through the <a href="' . $base_url . '/contact">contact form</a>.'), 'info');
  }

  // Experts points info
  if ( drupal_is_front_page() && user_access('use points') ) {
    if (module_exists('emh_points')) {
      drupal_set_message(t('You can earn points by responding to a request and when the client recognize the value of your contribution. You can therefore monetize your points once you have reached a threshold of at least ' . variable_get('emh_points_monetization_threshold', '1500') . ' points.'), 'info');
    }
  }

  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-sm-7"';
  }
  elseif (!empty($variables['page']['sidebar_first']) && empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-sm-10"';
  }
  elseif (empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="col-sm-9"';
  }
  else {
    $variables['content_column_class'] = ' class="col-sm-12"';
  }

  $variables['baseline'] = emindhub_beautiful_baseline();
}
