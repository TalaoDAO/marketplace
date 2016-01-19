<?php


//require_once('templates/PHPDebug.php');
require_once('templates/includes/string_list.php');

require_once('theme/alter.inc');
require_once('theme/blocks.func.php');
require_once('theme/common.inc');
require_once('theme/forms.func.php');
require_once('theme/html.func.php');
require_once('theme/menus.func.php');
require_once('theme/nodes.func.php');
require_once('theme/regions.func.php');
require_once('theme/menu/menu-local-tasks.func.php');
require_once('theme/system/button.vars.php');
require_once('theme/system/form-element.func.php');
require_once('theme/system/form-element-label.func.php');
require_once('theme/system/page.vars.php');


function emindhub_file($variables) {
	$element = $variables['element'];
	$element['#attributes']['type'] = 'file';
	element_set_attributes($element, array('id', 'name', 'size'));
	_form_set_class($element, array('form-file'));

	return sprintf('<input type="text" disabled data-fileinputtext="%s" class="file-return"><div class="file-upload"><span>%s</span><input' . drupal_attributes($element['#attributes']) . ' /></div>', $element['#id'], c_szChooseFile);
}


/*
 * USEFUL FUNCTIONS
 */
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
    if (!empty($account->field_first_name[LANGUAGE_NONE])) {
      $firstName = $account->field_first_name[LANGUAGE_NONE][0]['value'];
    }
    $lastName = '';
    if (!empty($account->field_last_name[LANGUAGE_NONE])) {
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
  if (!empty($account->field_first_name[LANGUAGE_NONE])) {
    $firstName = $account->field_first_name[LANGUAGE_NONE][0]['value'];
  }
  $lastName = '';
  if (!empty($account->field_last_name[LANGUAGE_NONE])) {
    $lastName = $account->field_last_name[LANGUAGE_NONE][0]['value'];
  }
  $userName = $account->name;

  global $base_url;
  $profileLink = drupal_get_path_alias('user/' . $account->uid);

  if ($link) $output = '<a href="' . $base_url . '/' . $profileLink . '">';
  // $output .= $firstName . '&nbsp;' . $lastName . '&nbsp;<span class="username badge">@' . $userName . '</span>';
  $output .= $firstName . '&nbsp;' . $lastName;
  if ($link) $output .= '</a>';

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

  if (!empty($profileLink)) {
    global $base_url;
    return '<a href="' . $base_url . '/' . $profileLink . '">' . $base_url . '/' . $profileLink . '</a>';
  }

}


/**
 * Implements hook_preprocess_field()
 * http://atendesigngroup.com/blog/adding-css-classes-fields-drupal
 */

function emindhub_preprocess_field(&$variables) {

  // echo '<pre>' . print_r($variables, TRUE) . '</pre>';

  /* Set shortcut variables. Hooray for less typing! */
  $name = $variables['element']['#field_name'];
  $bundle = $variables['element']['#bundle'];
  $mode = $variables['element']['#view_mode'];
  $classes = &$variables['classes_array'];
  $title_classes = &$variables['title_attributes_array']['class'];
  $content_classes = &$variables['content_attributes_array']['class'];
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
        case 'field_telephone':
        case 'field_mail':
					$user = user_load(arg(1));
					$field = field_get_items('user', $user, 'field_photo');
					if ($field) {
						$classes[] = 'col-sm-10 col-sm-offset-2';
					} else {
						$classes[] = 'col-sm-12';
					}
          break;

				default:
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
  foreach ($variables['items'] as $delta => $item) {
    $variables['item_attributes_array'][$delta]['class'] = $item_classes;
    $variables['item_attributes_array'][$delta]['class'][] = $delta % 2 ? 'even' : 'odd';
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

  if ( emindhub_author_has_picture( $node ) ) {
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
    case 'challenge':
      $comment_add_text = t('Answers');
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

/**
 * Implements hook_preprocess_comment().
 */
function emindhub_preprocess_comment(&$variables) {
  unset($variables['content']['links']['comment']['#links']['comment-reply']);
  if ($variables['elements']['#node']->comment == COMMENT_NODE_CLOSED) {
    unset($variables['content']['links']['comment']['#links']);
  }
}


function emindhub_beautiful_baseline() {
  $baseline = '';
  $type = '';
  $show_help = FALSE;

  if (arg(1) == 'add') {
    $type = arg(2);
    $show_help = TRUE;
  }
  // else if (arg(2) == 'edit') {
  //   $type = node_load(arg(1))->type;
  //   $show_help = TRUE;
  // }
	// else if ($args[0] == 'my-relationships') {
	// 	$show_help = TRUE;
	// }

  if ($show_help) {
    switch ($type) {

      case 'question1':
        $baseline = t('Ask a question online and get multiple answers from experts');
        break;
      case 'webform':
        $baseline = t('Create a survey to identify best experts profiles for a specific task or mission');
        break;
      case 'challenge':
        $baseline = t('Request for service proposals to innovate or solve a problem');
        break;
      default:
        $baseline = '';
        break;

    }
  }

  return $baseline;
}


function emindhub_beautiful_form_actions(&$form, $actions, $label = 'primary') {

	$first = FALSE;
	foreach( $actions as $action => $value ) {
    $actions[$action] = array(
			'loaded' => FALSE,
			'first' => FALSE,
			'last' => FALSE,
		);
    if ( !empty($form['actions'][$action]) ) {
			if ( !isset($form['actions'][$action]['#access']) || $form['actions'][$action]['#access'] == TRUE ) {
				$actions[$action]['loaded'] = TRUE;
				if ( !$first ) {
	        $first = TRUE;
	        $actions[$action]['first'] = TRUE;

					if ( $label == 'primary' ) $pull_right = ' pull-right';
					else $pull_right = '';
	        $form['actions'][$action]['#prefix'] = '<div class="btn-group btn-group-' . $label . $pull_right . '" role="group" aria-label="' . $label . ' actions">';
	      }
			}
    }
	}

	$actions = array_reverse($actions);
	$last = FALSE;
	foreach( $actions as $action => $value ) {
    if ( $actions[$action]['loaded'] == TRUE && !$last ) {
      $last = TRUE;
      $actions[$action]['last'] = TRUE;
			$form['actions'][$action]['#suffix'] = '</div> <!-- END .btn-group -->';
    }
	}
	$actions = array_reverse($actions);

	if (!empty($actions)) return $form['actions'];

}


/**
* Generic function for adding aria-describedby attribute to form elements. Note
* the attribute only needs to be added if the element includes a description.
*/
function emindhub_add_aria_attributes(&$variables) {
	if (!empty($variables['element']['#description'])) {
		$variables['element']['#attributes']['aria-describedby'] = $variables['element']['#id'] . '-description';
	}
}

/**
* Preprocess textareas to add in aria attributes.
*/
function emindhub_preprocess_textarea(&$variables) {
	emindhub_add_aria_attributes($variables);
}

/**
* Preprocess textfield to add in aria attributes.
*/
function emindhub_preprocess_textfield(&$variables) {
	emindhub_add_aria_attributes($variables);
}

/**
* Preprocess radios to add in aria attributes.
*/
function emindhub_preprocess_radios(&$variables) {
	emindhub_add_aria_attributes($variables);
}

/**
* Preprocess checkboxes to add in aria attributes.
*/
function emindhub_preprocess_checkboxes(&$variables) {
	emindhub_add_aria_attributes($variables);
}

/**
* Preprocess select to add in aria attributes.
*/
function emindhub_preprocess_select(&$variables) {
	emindhub_add_aria_attributes($variables);
}

/**
* Preprocess date to add in aria attributes.
*/
function emindhub_preprocess_date(&$variables) {
	emindhub_add_aria_attributes($variables);
}

/**
* Preprocess webform_email to add in aria attributes.
*/
function emindhub_preprocess_webform_email(&$variables) {
	emindhub_add_aria_attributes($variables);
}

/**
* Preprocess webform_number to add in aria attributes.
*/
function emindhub_preprocess_webform_number(&$variables) {
	emindhub_add_aria_attributes($variables);
}
