<?php

//require_once('templates/PHPDebug.php');
require_once('templates/includes/string_list.php');

require_once('inc/html.php');
require_once('inc/nodes.php');
require_once('inc/forms.php');
require_once('inc/menus.php');
require_once('inc/regions.php');
require_once('inc/blocks.php');


/**
 * Implements hook_css_alter().
 *
 * @param $css
 *   The array of CSS files.
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
  );

  // Remove drupal default css files.
  foreach ($css as $key => $item) {
    if (in_array($key, $disabled_drupal_css)) {
      // Remove css and its altered version that can be added by jquery_update.
      unset($css[$css[$key]['data']]);
      unset($css[$key]);
    }
  }

  // echo '<pre>' . print_r($css, TRUE) . '</pre>'; die;
}


function emindhub_file($variables) {
	$element = $variables['element'];
	$element['#attributes']['type'] = 'file';
	element_set_attributes($element, array('id', 'name', 'size'));
	_form_set_class($element, array('form-file'));

	return sprintf('<input type="text" disabled data-fileinputtext="%s" class="file-return"><div class="file-upload"><span>%s</span><input' . drupal_attributes($element['#attributes']) . ' /></div>', $element['#id'], c_szChooseFile);
}


/**
 * Additional page variables
 */
function emindhub_preprocess_page(&$vars, &$variables) {

	// CUSTOMIZABLE TEXT  ==============================================================
	// $vars['banniereText'] = sprintf(c_szTextBanniere, "<p>", "</p>');
	$vars['openBurgerImg'] = theme('image', array(
		'path' => imagePath('menuBtn.png'),
		'alt' => '',
		'getsize' => FALSE,
	));

}


/*
 * USEFUL FUNCTIONS
 */
function isBusinessUser($account = null) {
	global $user;
  return (in_array('business', array_values($user->roles)) || in_array('business-preview', array_values($user->roles)));
}

function isExpertUser($account = null) {
	global $user;
  return (in_array('expert', array_values($user->roles)) || in_array('expert-preview', array_values($user->roles)));
}

function isWebmasterUser() {
	global $user;
	return (in_array('webmaster', array_values($user->roles)));
}

function isAdminUser() {
	global $user;
	return (in_array('administrator', array_values($user->roles)));
}

function getImgSrc($fileName) {
	return sprintf('%s/images/%s', base_path().path_to_theme(), $fileName);
}

function imagePath($fileName) {
	return sprintf('%s/images/%s', path_to_theme(), $fileName);
}

function isHomePage() {
	$isHomePage = drupal_is_front_page();
	if (!$isHomePage) {
		if (drupal_get_path_alias() == 'homepage') {
			$isHomePage = TRUE;
		}
	}
	return $isHomePage;
}


function pp($arr){
	$retStr = '<ul>';
	if (is_array($arr)){
		foreach ($arr as $key=>$val){
			if (is_array($val)){
				$retStr .= '<li>' . $key . ' => ' . pp($val) . '</li>';
			}else{
				$retStr .= '<li>' . $key . ' => ' . $val . '</li>';
			}
		}
	}
	$retStr .= '</ul>';
	return $retStr;
}


function customDSM($input, $name = NULL, $type = 'status') {
  $export = kprint_r($input, TRUE, $name);
  drupal_set_message($export, $type);
}


// YBA : hide env indicator switcher
function emindhub_environment_indicator_switches($variables) {
  return '';
}


function emindhub_beautiful_welcome_message() {
  if ( drupal_is_front_page() && user_is_logged_in() ) {
    global $user;
    $account = user_load($user->uid);
    $firstName = '';
    if (isset($account->field_first_name[LANGUAGE_NONE]) && $account->field_first_name[LANGUAGE_NONE]) {
      $firstName = $account->field_first_name[LANGUAGE_NONE][0]['value'];
    }
    $lastName = '';
    if (isset($account->field_last_name[LANGUAGE_NONE]) && $account->field_last_name[LANGUAGE_NONE]) {
      $lastName = $account->field_last_name[LANGUAGE_NONE][0]['value'];
    }
    return t('Welcome') . '&nbsp;<span>' . $firstName . '&nbsp;' . $lastName . '</span>';
  } else {
    return '';
  }
}


// TODO: use global $author
function emindhub_beautiful_user_name( $object, $link = FALSE ) {

  // print_r($object);

  switch ($object) {
    case 'user':
      $account = user_load(arg(1));
      break;
    case 'node':
      $node = node_load(arg(1));
      $account = user_load($node->uid);
      break;
    case 'comment':
      $account = user_load($comment->uid);
      break;
  }

  $output = '';

  $firstName = '';
  if (isset($account->field_first_name[LANGUAGE_NONE]) && $account->field_first_name[LANGUAGE_NONE]) {
    $firstName = $account->field_first_name[LANGUAGE_NONE][0]['value'];
  }
  $lastName = '';
  if (isset($account->field_last_name[LANGUAGE_NONE]) && $account->field_last_name[LANGUAGE_NONE]) {
    $lastName = $account->field_last_name[LANGUAGE_NONE][0]['value'];
  }
  $userName = $account->name;

  global $base_url;
  $profileLink = drupal_get_path_alias('user/' . $account->uid);

  if ($link == TRUE) $output = '<a href="' . $base_url . '/' . $profileLink . '">';
  // $output .= $firstName . '&nbsp;' . $lastName . '&nbsp;<span class="username badge">@' . $userName . '</span>';
  $output .= $firstName . '&nbsp;' . $lastName;
  if ($link == TRUE) $output .= '</a>';

  return $output;

}


function emindhub_beautiful_user_profile_link( $author = TRUE ) {

  $profileLink = '';

  if ( $author = TRUE ) {
    $profileLink = drupal_get_path_alias('user/' . $node->uid);
  }
  else {
    global $user;
    $account = user_load($user->uid);
    if ($account = menu_get_object('user')) {
      $profileLink = drupal_get_path_alias('user/' . $account->uid);
    }
  }

  if (isset($profileLink)) {
    global $base_url;
    return '<a href="' . $base_url . '/' . $profileLink . '">' . $base_url . '/' . $profileLink . '</a>';
  }

}


/**
 * Implements hook_preprocess_field()
 * http://atendesigngroup.com/blog/adding-css-classes-fields-drupal
 */

function emindhub_preprocess_field(&$vars) {

  // echo '<pre>' . print_r($vars, TRUE) . '</pre>';

  /* Set shortcut variables. Hooray for less typing! */
  $name = $vars['element']['#field_name'];
  $bundle = $vars['element']['#bundle'];
  $mode = $vars['element']['#view_mode'];
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  $item_classes = array();

  /* Global field classes */
  // $classes[] = 'field-wrapper';
  // $title_classes[] = 'field-label';
  // $content_classes[] = 'field-items';
  // $item_classes[] = 'field-item';

  /* Uncomment the lines below to see variables you can use to target a field */
  // print '<strong>Name:</strong> ' . $name . '<br/>';
  // print '<strong>Bundle:</strong> ' . $bundle  . '<br/>';
  // print '<strong>Mode:</strong> ' . $mode .'<br/>';

  /* Add specific classes to targeted fields */
  switch ($mode) {
    /* All teasers */
    // case 'teaser':
    //   switch ($name) {
    //     /* Teaser read more links */
    //     case 'node_link':
    //       $item_classes[] = 'more-link';
    //       break;
    //     /* Teaser descriptions */
    //     case 'body':
    //     case 'field_description':
    //       $item_classes[] = 'description';
    //       break;
    //   }
    //   break;
    case 'full':
      switch ($name) {
        case 'field_photo':
          $classes[] = 'col-sm-2';
          break;

        case 'field_first_name':
        case 'field_titre_metier':
        case 'field_entreprise':
        case 'field_address':
          $classes[] = 'col-sm-10';
          break;

        case 'field_link_to_my_blog':
        case 'field_domaine':
        case 'field_tags':
        case 'field_skills_set':
        case 'field_position_list':
        case 'field_employment_history':
        case 'field_other_areas':
          $classes[] = 'col-sm-12';
          break;
      }
      break;
  }

  // switch ($name) {
  //   case 'field_authors':
  //     $title_classes[] = 'inline';
  //     $content_classes[] = 'authors';
  //     $item_classes[] = 'author';
  //     break;
  // }

  // Apply odd or even classes along with our custom classes to each item */
  foreach ($vars['items'] as $delta => $item) {
    $vars['item_attributes_array'][$delta]['class'] = $item_classes;
    $vars['item_attributes_array'][$delta]['class'][] = $delta % 2 ? 'even' : 'odd';
  }
}


// TODO
// function emindhub_preprocess_user_picture(&$variables) {
//   global $user;
//   $account = user_load($user->uid);
//   $variables['user_picture'] = '';
//   // if (variable_get('user_pictures', 0)) {
//     $account = $variables['account'];
//     if (!empty($account->picture)) {
//       // print '1';
//       // @TODO: Ideally this function would only be passed file objects, but
//       // since there's a lot of legacy code that JOINs the {users} table to
//       // {node} or {comments} and passes the results into this function if we
//       // a numeric value in the picture field we'll assume it's a file id
//       // and load it for them. Once we've got user_load_multiple() and
//       // comment_load_multiple() functions the user module will be able to load
//       // the picture files in mass during the object's load process.
//       if (is_numeric($account->picture)) {
//         $account->picture = file_load($account->picture);
//       }
//       if (!empty($account->picture->uri)) {
//         $filepath = $account->picture->uri;
//       }
//     }
//     // elseif (variable_get('user_picture_default', '')) {
//     //   print '2';
//     //   $filepath = variable_get('user_picture_default', '');
//     // }
//     else {
//       // print '3';
//       $filepath = $account->field_photo[LANGUAGE_NONE][0]['uri'];
//     }
//     if (isset($filepath)) {
//       $alt = t("@user's picture", array('@user' => format_username($account)));
//       // If the image does not have a valid Drupal scheme (for eg. HTTP),
//       // don't load image styles.
//       if (module_exists('image') && file_valid_uri($filepath) && $style = variable_get('user_picture_style', '')) {
//         $variables['user_picture'] = theme('image_style', array('style_name' => $style, 'path' => $filepath, 'alt' => $alt, 'title' => $alt));
//       }
//       else {
//         $variables['user_picture'] = theme('image', array('path' => $filepath, 'alt' => $alt, 'title' => $alt));
//       }
//       if (!empty($account->uid) && user_access('access user profiles')) {
//         $attributes = array('attributes' => array('title' => t('View user profile.')), 'html' => TRUE);
//         $variables['user_picture'] = l($variables['user_picture'], "user/$account->uid", $attributes);
//       }
//     }
//   // }
// }


function emindhub_author_has_picture( $node ) {

  $account = user_load($node->uid);

  if ( field_get_items('user', $account, 'field_first_name') ) return TRUE;

}


function emindhub_beautiful_author_picture( $node, $class ) {

  $account = user_load($node->uid);
  $photo_uri = field_get_items('user', $account, 'field_photo');

  $photo = '';

  if ( emindhub_author_has_picture( $node ) == TRUE ) {
    $photo = image_style_url('thumbnail', $photo_uri[0]['uri']);
    $photo = '<img src="' . $photo . '" class="' . $class . '" />';
  } else {
    $photo = '<div class="user-badge '. $class . '"></div>';
  }

  return $photo;

}


function emindhub_beautiful_comment_list_text( $node ) {

  $comment_add_text = t('Comments');

  switch ($node->type) {

    case 'question1':
      $comment_add_text = t('Responses');
      break;

    case 'challenge':
      $comment_add_text = t('Responses');
      break;

  }

  return $comment_add_text;

}


function emindhub_beautiful_comment_add_text( $node ) {

  $comment_add_text = t('Add new comment');

  switch ($node->type) {

    case 'question1':
      $comment_add_text = t('Answer the question');
      break;

    case 'challenge':
      $comment_add_text = t('Answer the challenge');
      break;

  }

  return $comment_add_text;

}
