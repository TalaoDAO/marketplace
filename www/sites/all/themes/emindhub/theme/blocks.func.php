<?php

/**
 * Implements hook_preprocess_block()
 */
function emindhub_preprocess_block(&$variables) {
  $block_id = $variables['block']->module . '-' . $variables['block']->delta;
  // print_r($block_id);
  // print_r($variables['block']);
  $classes = &$variables['classes_array'];
  $title_classes = &$variables['title_attributes_array']['class'];
  $content_classes = &$variables['content_attributes_array']['class'];
  $title = &$variables['block']->title;
  $content = &$variables['content'];

  /* Add global classes to all blocks */
  // $title_classes[] = 'block-title';
  // $content_classes[] = 'block-content';
  // $classes[] = 'block-class';

  /* Uncomment the line below to see variables you can use to target a field */
  #print $block_id . '<br/>';

  // Structure
    // col-md-4
    // col-md-6
    // col-md-12 etc.

  // Styles de titre
    // emh-block-blue-title
    // emh-block-dark-title
    // emh-block-dark

  // Styles de bloc
    // emh-block-dark
    // emh-block-blue
    // emh-block-grey
    // emh-block-expert

  // Styles spéciaux
    // emh-block-slider

  switch ($block_id) {

    case 'menu-menu-top-anonymous':
      $classes[] = 'col-sm-11 col-md-11';
      break;

    case 'menu-menu-top':
      $classes[] = 'col-sm-6 col-md-6';
      break;

    case 'menu-menu-footer-menu':
      $classes[] = 'col-sm-9 col-md-9';
      break;

    case 'menu-menu-networks':
      $classes[] = 'col-sm-3 col-md-3';
      break;

    case 'search-form':
      $classes[] = 'col-md-4 col-md-offset-1';
      break;

    case 'system-user-menu':
      $classes[] = 'col-sm-6 col-md-6';
      break;

    // User Login block
    case 'user-login':
      $classes[] = 'col-md-4 col-md-offset-8';
      break;

    // HP - Create a request
    case 'block-8':
      $classes[] = 'emh-block-grey';
      break;

    // HP - Welcome
    case 'block-17':
      $classes[] = 'col-md-8';
      $classes[] = 'emh-block-blue-main-title';
      $content = '';
      break;

    // They use
    case 'views-entreprise_list-block':
      $classes[] = 'col-md-6';
      $classes[] = 'emh-block-blue-title';
      $classes[] = 'emh-block-slider';
      break;

    // They are
    case 'views-users_list-block_2':
      $classes[] = 'col-md-6';
      $classes[] = 'emh-block-blue-title';
      $classes[] = 'emh-block-slider';
      break;

    // More about us?
    case 'formblock-contact_site':
      $classes[] = 'emh-block-dark-title';
      break;

    // Burger menu > Shortcuts
    case 'menu-menu-burger-menu':
      $classes[] = 'emh-block-blue-title-big';
      break;

    // Burger menu > Filters
    case 'global_filter-global_filter_1':
      $classes[] = 'emh-block-blue-title-big';
      break;

    // Timeline
    case 'progress_tracker-progress_tracker':
      $classes[] = 'emh-block-blue-title';
      break;

    // Tabs submenu
    case 'emh_submenu-submenu':
    case 'emh_mission-mission_add_submenu':
      $classes[] = 'emh-block-light';
      break;

    // Parrainage
    case 'emh_virality-invitation_form':
      $classes[] = 'emh-block-blue-title';
      break;

    // Profile percent complete
    case 'pcp-pcp_profile_percent_complete':
      $classes[] = 'col-md-12';
      break;

    default:
      break;
  }
}
