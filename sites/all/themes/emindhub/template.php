<?php

//require_once("templates/PHPDebug.php");
require_once("templates/includes/string_list.php");

require_once("inc/forms.php");
require_once("inc/menus.php");
require_once("inc/regions.php");
require_once("inc/blocks.php");


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

	return sprintf('<input type="text" disabled data-fileinputtext="%s" class="file-return"><div class="file-upload"><span>%s</span><input' . drupal_attributes($element['#attributes']) . ' /></div>', $element["#id"], c_szChooseFile);
}


/**
 * Additional page variables
 */
function emindhub_preprocess_page(&$vars, &$variables) {

	// CUSTOMIZABLE TEXT  ==============================================================
	// $vars['banniereText'] = sprintf(c_szTextBanniere, "<p>", "</p>");
	$vars['openBurgerImg'] = theme('image', array(
		'path' => imagePath("menuBtn.png"),
		'alt' => '',
		'getsize' => FALSE,
	));

}

function emindhub_preprocess_html(&$variables) {
	drupal_add_css('http://fonts.googleapis.com/css?family=Lato:400,700,400italic,700italic' , array('type' => 'external'));

  global $user;
  foreach ( $user->roles as $role_id => $role ) {
    // $variables['classes_array'][] = "role-id-".$role_id;
    $variables['classes_array'][] = "role-".strtolower(drupal_clean_css_identifier($role));
  }
  // $variables['classes_array'][] = "user-uid-".$user->uid;
}

function emindhub_preprocess_node(&$variables, $hook) {
	if (isset($variables['node']->type)) {
		$function = __FUNCTION__ . '__' . $variables['node']->type;
		if (function_exists($function)) {
			$function($variables, $hook);
		}
	}
}

function emindhub_preprocess_node__challenge(&$variables) {
	node_informations_add($variables);
}

function emindhub_preprocess_node__question(&$variables) {
	node_informations_add($variables);
}

function emindhub_preprocess_node__question1(&$variables) {
	node_informations_add($variables);
}


function emindhub_preprocess_node__webform(&$variables) {
	node_informations_add($variables);
}

function node_informations_add(&$variables) {
	$variables['company_name'] = "";
	$variables['company_description'] = "";
	$variables['user_name'] = "";
	if (isset($variables['elements']['body'])) {
		$user = user_load_by_name($variables['elements']['body']['#object']->name);
		$account = user_load($user->uid);

		if ($account) {
			$firstName = "";
			if (isset($account->field_first_name[LANGUAGE_NONE]) && $account->field_first_name[LANGUAGE_NONE]) {
				$firstName = $account->field_first_name[LANGUAGE_NONE][0]['value'];
			}
			$lastName = "";
			if (isset($account->field_last_name[LANGUAGE_NONE]) && $account->field_last_name[LANGUAGE_NONE]) {
				$lastName = $account->field_last_name[LANGUAGE_NONE][0]['value'];
			}
			$variables['user_name'] = $lastName . ' ' . $firstName;

			if ($account->field_entreprise) {
				$targetId = $account->field_entreprise[LANGUAGE_NONE][0]['target_id'];
				$entity = node_load($targetId);
        // echo '<pre>' . print_r($entity, TRUE) . '</pre>'; die;
				if ($entity) {
					$variables['company_name'] = $entity->title;
					if ($entity->body)
						$variables['company_description'] = $entity->body[LANGUAGE_NONE][0]["value"];
				}
			}
		}
	}
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
	return sprintf("%s/images/%s", base_path().path_to_theme(), $fileName);
}

function imagePath($fileName) {
	return sprintf("%s/images/%s", path_to_theme(), $fileName);
}

function isHomePage() {
	$isHomePage = drupal_is_front_page();
	if (!$isHomePage) {
		if (drupal_get_path_alias() == "homepage") {
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


function emindhub_welcome_message() {
  if ( drupal_is_front_page() && user_is_logged_in() ) {
    global $user;
    $account = user_load($user->uid);
    $firstName = "";
    if (isset($account->field_first_name[LANGUAGE_NONE]) && $account->field_first_name[LANGUAGE_NONE]) {
      $firstName = $account->field_first_name[LANGUAGE_NONE][0]['value'];
    }
    $lastName = "";
    if (isset($account->field_last_name[LANGUAGE_NONE]) && $account->field_last_name[LANGUAGE_NONE]) {
      $lastName = $account->field_last_name[LANGUAGE_NONE][0]['value'];
    }
    return t('Welcome') . '&nbsp;<span>' . $firstName . '&nbsp;' . $lastName . '</span>';
  } else {
    return '';
  }
}


function emindhub_beautiful_user_name( $link = FALSE ) {

  $context = arg(0);
  // print_r($context);
  switch ($context) {
    case 'user':
      $account = user_load(arg(1));
      break;
    case 'node':
      $node = node_load(arg(1));
      $account = user_load($node->uid);
      break;
  }

  $firstName = "";
  if (isset($account->field_first_name[LANGUAGE_NONE]) && $account->field_first_name[LANGUAGE_NONE]) {
    $firstName = $account->field_first_name[LANGUAGE_NONE][0]['value'];
  }
  $lastName = "";
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


function emindhub_beautiful_user_profile_link() {
  if ($account = menu_get_object('user')) {
    $account = user_load($account->uid);
    $userName = $account->name;
    global $base_url;
    $profileLink = drupal_get_path_alias('user/' . $account->uid);
    return '<a href="' . $base_url . '/' . $profileLink . '">' . $base_url . '/' . $profileLink . '</a>';
  } else {
    return '';
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
