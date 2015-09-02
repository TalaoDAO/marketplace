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


function emindhub_theme() {
	return array(
	  // 'user_picture' => array(
  	// 	'path' => drupal_get_path('theme', 'emindhub').'/templates/user',
  	// 	'template' => 'user_picture',
  	// 	'render element' => 'image',
	  // ),
	);
}


function emindhub_file($variables) {
	$element = $variables['element'];
	$element['#attributes']['type'] = 'file';
	element_set_attributes($element, array('id', 'name', 'size'));
	_form_set_class($element, array('form-file'));

	return sprintf('<input type="text" disabled data-fileinputtext="%s" class="file-return"><div class="file-upload"><span>%s</span><input' . drupal_attributes($element['#attributes']) . ' /></div>', $element["#id"], c_szChooseFile);
}


// function emindhub_preprocess_user_picture(&$variables) {
// 	$variables['user_picture'] = '';
// 	//if (variable_get('user_pictures', TRUE)) {
// 		if (isset($variables['account'])) {
// 			$account = $variables['account'];
// 			if (!empty($account->picture)) {
// 				// @TODO: Ideally this function would only be passed file objects, but
// 				// since there's a lot of legacy code that JOINs the {users} table to
// 				// {node} or {comments} and passes the results into this function if we
// 				// a numeric value in the picture field we'll assume it's a file id
// 				// and load it for them. Once we've got user_load_multiple() and
// 				// comment_load_multiple() functions the user module will be able to load
// 				// the picture files in mass during the object's load process.
// 				if (is_numeric($account->picture)) {
// 					$account->picture = file_load($account->picture);
// 				}
// 				if (!empty($account->picture->uri)) {
// 					$filepath = $account->picture->uri;
// 				}
// 			}
// 			elseif (variable_get('user_picture_default', '')) {
// 				$filepath = variable_get('user_picture_default', '');
// 			}
// 			if (isset($filepath)) {
// 				$alt = t("@user's picture", array('@user' => format_username($account)));
// 				// If the image does not have a valid Drupal scheme (for eg. HTTP),
// 				// don't load image styles.
// 				if (module_exists('image') && file_valid_uri($filepath) && $style = variable_get('user_picture_style', '')) {
// 					$variables['user_picture'] = theme('user_picture', array(
// 							'style_name' => $style,
// 							'path' => $filepath,
// 							'alt' => $alt,
// 							'title' => $alt
// 						));
// 				}
// 				else {
// 					$variables['user_picture'] = theme('user_picture', array(
// 							'path' => $filepath,
// 							'alt' => $alt,
// 							'title' => $alt
// 						));
// 				}
// 				if (!empty($account->uid) && user_access('access user profiles')) {
// 					$attributes = array(
// 						'attributes' => array('title' => c_szViewUsrProfile),
// 						'html' => TRUE
// 					);
// 					$variables['user_picture'] = l($variables['user_picture'], "user/$account->uid", $attributes);
// 				}
// 			}
// 		}
// 		else {
// 			dsm('! isset($variables[account])');
// 		}
// 	/*} else {
// 		dsm('variable_get("user_pictures", 0)');
// 	}*/
// }


/**
 * Additional page variables
 */
function emindhub_preprocess_page(&$vars, &$variables) {

	// CUSTOMIZABLE TEXT  ==============================================================
	// banniere
	$vars['banniereText'] = sprintf(c_szTextBanniere, "<p>", "</p>");

	// $vars['firstMenu'] = GetMenu($vars);

	// LOGO SECTION  ==============================================================
	// site logo
	// $vars['imagelogo'] = theme('image', array(
	// 	'path' => imagePath("logo.png"),
	// 	'alt'  => $vars['site_name'],
	// 	'getsize' => FALSE,
	// 	'attributes' => array(
	// 		'id' => 'logo',
	// 		'class' => array(
	// 			'img-responsive'
	// 		),
	// 	),
	// ));
  //
	// $vars['imagelogo'] = l(
	// 	$vars['imagelogo'],
	// 	'<front>',
	// 	array(
	// 		'html' => TRUE,
	// 		'attributes' => array(
	// 			'title' => c_szBackHome,
	// 		)
	// 	)
	// );

	// IMAGES SECTION  ==============================================================
	// mail icon
// 	$vars['mailIcon'] = theme('image', array(
// 		'path' => imagePath('mailIcon.png'),
// 		'alt' => 'email',
// 		'getsize' => FALSE,
// 	));
//
// 	// Vous avez une demande
// 	$vars['demandeImg'] = theme('image', array(
// 		'path' => imagePath("demande.png"),
// //		'alt' => t('Vous avez une demande'),
// 		'getsize' => FALSE,
// 	));
//
// 	// Vous avez une expertise
// 	$vars['expertiseImg'] = theme('image', array(
// 		'path' => imagePath("expertise.png"),
// //		'alt'=> t('Vous avez une expertise'),
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['atomiumImg'] = theme('image', array(
// 		'path' => imagePath("atomium.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['cercleImg'] = theme('image', array(
// 		'path' => imagePath("cercle.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['peopleImg'] = theme('image', array(
// 		'path' => imagePath("people.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['rapiditeImg'] = theme('image', array(
// 		'path' => imagePath("rapidite.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['securiteImg'] = theme('image', array(
// 		'path' => imagePath("securite.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['qualiteImg'] = theme('image', array(
// 		'path' => imagePath("qualite.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['pointImg'] = theme('image', array(
// 		'path' => imagePath("point.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['aerofuturImg'] = theme('image', array(
// 		'path' => imagePath("aerofutur.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['jmLbcImg'] = theme('image', array(
// 		'path' => imagePath("jmLbc.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['bulleImg'] = theme('image', array(
// 		'path' => imagePath("bulle.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['previousImg'] = theme('image', array(
// 		'path' => imagePath("previous.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['menuIconImg'] = theme('image', array(
// 		'path' => imagePath("menuIcon.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['nextImg'] = theme('image', array(
// 		'path' => imagePath("next.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['fluxIconImg'] = theme('image', array(
// 		'path' => imagePath("fluxIcon.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
// 	$vars['actuImg'] = theme('image', array(
// 		'path' => imagePath("actu.png"),
// 		'alt'=> '',
// 		'getsize' => FALSE,
// 	));
//
	$vars['openBurgerImg'] = theme('image', array(
		'path' => imagePath("menuBtn.png"),
		'alt' => '',
		'getsize' => FALSE,
	));
//
// 	$vars['secondMenu'] = FALSE;

}

function emindhub_preprocess_html(&$variables) {
	drupal_add_css('http://fonts.googleapis.com/css?family=Lato:400,700,400italic,700italic' , array('type' => 'external'));
	if (isBusinessUser()) {
		$variables['classes_array'][] = 'business-user';
	}
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


// function emindhub_password_confirm_process($element) {
// 	$element['pass1']['#attributes']['title'] = 'Title';
// 	$element['pass2']['#attributes']['title'] = 'Title2';
// 	return $element;
// }



/*
 * USEFUL FUNCTION
 */
function isBusinessUser($account = null) {
	global $user;
	if (is_null($account)) {
		$account = $user;
	}
	return $account->uid && in_array('business', $account->roles);
}

function isAdminUser () {
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
		/*$arUrl = explode('/', current_path());
		if ($arUrl[count($arUrl)-1] == "homepage") {
			$isHomePage = TRUE;
		}*/
		if (drupal_get_path_alias() == "homepage") {
			$isHomePage = TRUE;
		}
	}
	return $isHomePage;
}

// function isExpertRegister() {
//   if (drupal_get_path_alias() == "expert/register") {
//	 $isExpertRegister = TRUE;
//   }
//   return $isExpertRegister;
// }
//
// function isBusinessRegister() {
//   if (drupal_get_path_alias() == "business/register") {
//	 $isBusinessRegister = TRUE;
//   }
//   return $isBusinessRegister;
// }


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
  return "";
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
  $output .= $firstName . '&nbsp;' . $lastName . '&nbsp;<span class="username badge">@' . $userName . '</span>';
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
