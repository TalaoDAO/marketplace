<?php

function emindhub_preprocess_region(&$variables, $hook) {

  $region_id = $variables['region'];
  $classes = &$variables['classes_array'];

  switch ($region_id) {
    case 'topmenu':
      $classes[] = 'row';
      break;
    case 'navigation':
      $classes[] = 'row';
      break;
    case 'header':
      if (drupal_is_front_page()) :
        $classes[] = 'col-sm-6';
      else :
        $classes[] = 'col-sm-9';
      endif;
      break;
    case 'header_right':
      if (drupal_is_front_page()) :
        $classes[] = 'col-sm-6 col-sm-offset-6';
      else :
        $classes[] = 'col-sm-3';
      endif;
      break;
    case 'title':
    case 'top':
      $classes[] = 'row';
      break;
    case 'highlighted':
      $classes[] = 'row';
      break;
    case 'bottom':
      $classes[] = 'col-sm-8';
      break;
    case 'bottom_right':
      $classes[] = 'col-sm-4';
      break;
    case 'sidebar_first':
      $classes = array('region region-sidebar-first' ); // HACK for removing well class
      break;
  }

}
