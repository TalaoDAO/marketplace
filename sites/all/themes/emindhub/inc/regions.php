<?php

function emindhub_preprocess_region(&$variables, $hook) {

  $region_id = $variables['region'];
  $classes = &$variables['classes_array'];

  switch ($region_id) {
    case 'topmenu':
      $classes[] = 'text-right row';
      break;
    case 'navigation':
      // $classes[] = 'text-right';
      break;
    case 'header':
      if (drupal_is_front_page()) :
        $classes[] = 'col-sm-5';
      else :
        $classes[] = 'col-sm-9';
      endif;
      break;
    case 'header_right':
      if (drupal_is_front_page()) :
        $classes[] = 'col-sm-3 col-sm-offset-4';
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
  }

}