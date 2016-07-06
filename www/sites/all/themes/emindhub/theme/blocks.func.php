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

    case 'block-bootstrap-languages':
      // $classes[] = 'col-md-2 col-xs-3'; // TODO
      break;

    // Registration block : expert/client
    case 'block-2':
      $classes[] = 'col-xs-6 col-md-12 emh-block-dark';
      break;

    case 'block-5':
      $classes[] = 'col-xs-6 col-md-12';
      break;

    // eMindHub is looking for experts
    case 'block-6':
      $classes[] = 'col-xs-6 col-md-12 emh-block-gold';
      break;

    // HP - Create a request
    case 'block-8':
      $classes[] = 'emh-block-grey';
      break;

    // HP - About experts
    case 'block-10':
      $classes[] = 'col-md-12';
      $classes[] = 'emh-block-dark-title';
      $content = '';
      break;

    // HP - Rapidity
    case 'block-20':
      $classes[] = 'col-md-4';
      $classes[] = 'emh-block-blue';
      break;

    // HP - Security
    case 'block-21':
      $classes[] = 'col-md-4';
      $classes[] = 'emh-block-blue';
      break;

    // HP - Quality
    case 'block-19':
      $classes[] = 'col-md-4';
      $classes[] = 'emh-block-blue';
      break;

    // HP - Welcome
    case 'block-17':
      $classes[] = 'col-md-8';
      $classes[] = 'emh-block-blue-main-title';
      $content = '';
      break;

    // HP - Business - Question
    case 'block-15':
      $content = '<a href="' . url('client/register') . '">' . $content . '</a>';
      break;

    // HP - Expert - Question
    case 'block-9':
      $content = '<a href="' . url('expert/register') . '">' . $content . '</a>';
      break;

    // HP - Business - You are
    case 'block-18':
      $classes[] = 'emh-block-light';
      $classes[] = 'emh-block-dark-title';
      $content = '<a href="' . url('client/register') . '">' . $content . '</a>';
      break;

    // HP - Expert - You are
    case 'block-11':
      $classes[] = 'emh-block-light';
      $classes[] = 'emh-block-dark-title';
      $content = '<a href="' . url('expert/register') . '">' . $content . '</a>';
      break;

    // HP - Business - Get a free trial
    case 'block-13':
      $classes[] = 'emh-block-light';
      $content = '<a href="' . url('client/register') . '">' . $content . '</a>';
      break;

    // HP - Expert - Sign up for free
    case 'block-12':
      $classes[] = 'emh-block-light';
      $content = '<a href="' . url('expert/register') . '">' . $content . '</a>';
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

    // News
    case 'views-news_thread-block':
      $classes[] = 'emh-block-dark';
      $classes[] = 'emh-block-slider';
      if (user_is_logged_in()) :
        $classes[] = 'emh-block-blue-title';
      else :
        $classes[] = 'emh-block-dark-title';
      endif;
      break;

    // News (1 items)
    // case 'views-news_thread-block_2':
    //   $classes[] = 'emh-block-blue-title';
    //   $classes[] = 'emh-block-dark';
    //   break;

    // More about us?
    case 'formblock-contact_site':
      $classes[] = 'emh-block-dark-title';
      break;

    // Main content
    case 'system-main':
      // $classes[] = 'emh-block-dark-title';
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

  // echo '<pre>' . print_r($variables['block'], TRUE) . '</pre>';

}
