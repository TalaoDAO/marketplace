<?php


/**
 * Implements hook_preprocess_block()
 */
function emindhub_preprocess_block(&$vars) {
  // echo '<pre>' . print_r($vars['block'], TRUE) . '</pre>';
  $block_id = $vars['block']->module . '-' . $vars['block']->delta;
  // print_r($block_id);
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  $title = &$vars['block']->title;
  $content = &$vars['content'];

  /* Add global classes to all blocks */
  // $title_classes[] = 'block-title';
  // $content_classes[] = 'block-content';
  // $classes[] = 'block-class';

  /* Uncomment the line below to see variables you can use to target a field */
  #print $block_id . '<br/>';

  // Structure
    // col-sm-4
    // col-sm-6
    // col-sm-12 etc.

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

    case 'menu-menu-footer-menu':
      $classes[] = 'col-sm-8';
      break;

    case 'menu-menu-networks':
      $classes[] = 'col-sm-3';
      break;

    case 'search-form':
      $classes[] = 'col-sm-4 col-sm-offset-1 col-xs-12';
      break;

    case 'system-user-menu':
      $classes[] = 'col-sm-12 col-xs-12';
      break;

    // User Login block
    case 'user-login':
      $classes[] = 'col-sm-4 col-sm-offset-8 col-xs-8';
      break;

    case 'block-bootstrap-languages':
      // $classes[] = 'col-sm-2 col-xs-3'; // TODO
      break;

    // Registration block : expert/business
    case 'block-2':
      $classes[] = 'emh-block-dark';
      break;

    // HP - eMindHub is looking for experts
    case 'block-6':
      $classes[] = 'emh-block-gold';
      break;

    // HP - Ask a question
    case 'block-14':
      $classes[] = 'col-sm-4';
      $classes[] = 'emh-block-grey';
      break;

    // HP - Start a challenge
    case 'block-8':
      $classes[] = 'col-sm-4';
      $classes[] = 'emh-block-grey';
      break;

    // HP - Create a survey
    case 'block-16':
      $classes[] = 'col-sm-4';
      $classes[] = 'emh-block-grey';
      break;

    // HP - How to mobilize the experts ?
    case 'block-13':
      $classes[] = 'col-sm-12';
      $classes[] = 'emh-block-dark-title';
      $content = '';
      break;

    // HP - About experts
    case 'block-10':
      $classes[] = 'col-sm-12';
      $classes[] = 'emh-block-dark-title';
      $content = '';
      break;

    // HP - Experts : text
    case 'block-12':
      $classes[] = 'col-sm-4';
      break;

    // HP - Experts : picto
    case 'block-11':
      $classes[] = 'col-sm-8';
      break;

    // HP - Why use eMindHub ?
    case 'block-18':
      $classes[] = 'col-sm-12';
      $classes[] = 'emh-block-dark-title';
      $content = '';
      break;

    // HP - Rapidity
    case 'block-20':
      $classes[] = 'col-sm-4';
      $classes[] = 'emh-block-blue';
      break;

    // HP - Security
    case 'block-21':
      $classes[] = 'col-sm-4';
      $classes[] = 'emh-block-blue';
      break;

    // HP - Quality
    case 'block-19':
      $classes[] = 'col-sm-4';
      $classes[] = 'emh-block-blue';
      break;

    // HP - Welcome
    case 'block-17':
      $classes[] = 'col-sm-8';
      $classes[] = 'emh-block-blue-main-title';
      $content = '';
      break;

    // They use
    case 'views-entreprise_list-block':
      $classes[] = 'col-sm-6';
      $classes[] = 'emh-block-blue-title';
      $classes[] = 'emh-block-slider';
      break;

    // They are
    case 'views-users_list-block_2':
      $classes[] = 'col-sm-6';
      $classes[] = 'emh-block-blue-title';
      $classes[] = 'emh-block-slider';
      break;

    // Query list
    case 'views-query_list-block':
    case 'views-query_list-block_1':
      $classes[] = 'emh-block-blue-title';
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

    // More about us ?
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
    case 'emh_survey-survey_add_submenu':
      $classes[] = 'emh-block-light';
      break;

    // Parrainage
    case 'emh_virality-invitation_form':
      $classes[] = 'emh-block-blue-title';
      break;
  }

  // echo '<pre>' . print_r($vars, TRUE) . '</pre>';

}
