<?php

function emindhub_preprocess_region(&$variables, $hook) {

  $region_id = $variables['region'];
  $classes = &$variables['classes_array'];

  switch ($region_id) {
    case 'header':
      if (!drupal_is_front_page()) :
        $classes[] = 'col-md-9';
      endif;
      break;
    case 'header_right':
      if (drupal_is_front_page()) :
        $classes[] = 'col-md-6 col-md-offset-6';
      else :
        $classes[] = 'col-md-3';
      endif;
      break;
    case 'title':
    case 'top':
      $classes[] = 'row';
      break;
    case 'highlighted':
      $classes[] = 'row';
      break;
    case 'sidebar_first':
      $classes = array('region region-sidebar-first' ); // HACK for removing well class
      break;
    default:
      break;
  }

}
