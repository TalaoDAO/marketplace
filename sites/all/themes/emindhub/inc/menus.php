<?php

function emindhub_menu_alter(&$items) {
  unset($items['user/register']);
}


//============================================================================
// NICE MENU CUSTOMIZATION SECTION

/**
 * Helper function that builds the nested lists of a Nice menu.
 *
 * Customization => support of html tags in menu item name
 *
 * @param array $variables
 *   Menu arguments.
 */
// function emindhub_nice_menus_build($variables) {
// 	// Menu array from which to build the nested lists.
// 	$menu = $variables['menu'];
//
// 	// The number of children levels to display. Use -1 to display all children
// 	// and use 0 to display no children.
// 	$depth = $variables['depth'];
//
// 	// An array of parent menu items.
// 	$trail = $variables['trail'];
// 	// "Show as expanded" option.
// 	$respect_expanded = $variables['respect_expanded'];
//
// 	$output = '';
// 	// Prepare to count the links so we can mark first, last, odd and even.
// 	$index = 0;
// 	$count = 0;
// 	foreach ($menu as $menu_count) {
// 		if ($menu_count['link']['hidden'] == 0) {
// 			$count++;
// 		}
// 	}
// 	// Get to building the menu.
// 	foreach ($menu as $menu_item) {
// 		$mlid = $menu_item['link']['mlid'];
// 		// Check to see if it is a visible menu item.
// 		if (!isset($menu_item['link']['hidden']) || $menu_item['link']['hidden'] == 0) {
// 			// Check our count and build first, last, odd/even classes.
// 			$index++;
// 			$first_class = ($index == 1) ? 'first' : '';
// 			$oddeven_class = ($index % 2 == 0) ? 'even' : 'odd';
// 			$last_class = ($index == $count) ? 'last' : '';
// 			// Build class name based on menu path
// 			// e.g. to give each menu item individual style.
// 			$class = str_replace(array('http', 'https', '://', 'www'), '', $menu_item['link']['href']);
// 			// Strip funny symbols.
// 			$class = drupal_html_class('menu-path-' . $class);
// 			if ($trail && in_array($mlid, $trail)) {
// 				$class .= ' active-trail';
// 			}
// 			// If it has children build a nice little tree under it.
// 			// Build a nice little tree under it if it has children, and has been set
// 			// to expand (when that option is being respected).
// 			if ((!empty($menu_item['link']['has_children'])) &&
// 				(!empty($menu_item['below'])) && $depth != 0 &&
// 				($respect_expanded == 0 || $menu_item['link']['expanded'])) {
// 				// Keep passing children into the function 'til we get them all.
// 				if ($menu_item['link']['depth'] <= $depth || $depth == -1) {
// 					$children = array(
// 						'#theme' => 'nice_menus_build',
// 						'#prefix' => '<ul>',
// 						'#suffix' => '</ul>',
// 						'#menu' => $menu_item['below'],
// 						'#depth' => $depth,
// 						'#trail' => $trail,
// 						'#respect_expanded' => $respect_expanded,
// 					);
// 				}
// 				else {
// 					$children = '';
// 				}
// 				// Set the class to parent only of children are displayed.
// 				$parent_class = ($children && ($menu_item['link']['depth'] <= $depth || $depth == -1)) ? 'menuparent ' : '';
// 				$element = array(
// 					'#below' => $children,
// 					'#title' => $menu_item['link']['title'],
// 					'#href' => $menu_item['link']['href'],
// 					// '#localized_options' => $menu_item['link']['localized_options'],
// 					'#localized_options' => array_merge($menu_item['link']['localized_options'], array('html' => TRUE)),
// 					'#attributes' => array(
// 						'class' => array(
// 							'menu-' . $mlid,
// 							$parent_class,
// 							$class,
// 							$first_class,
// 							$oddeven_class,
// 							$last_class,
// 						),
// 					),
// 					'#original_link' => $menu_item['link'],
// 				);
// 				$variables['element'] = $element;
//
// 				// Check for context reactions menu.
// 				if (module_exists('context')) {
// 					context_preprocess_menu_link($variables);
// 					if (isset($variables['element']['#localized_options']['attributes']['class']) &&
// 						in_array('active', $variables['element']['#localized_options']['attributes']['class']) &&
// 						!in_array('active-trail', $variables['element']['#attributes']['class'])) {
// 						$variables['element']['#attributes']['class'][] = ' active-trail';
// 					}
// 				}
//
// 				$output .= theme('menu_link', $variables);
// 			}
// 			else {
// 				$element = array(
// 					'#below' => '',
// 					'#title' => $menu_item['link']['title'],
// 					'#href' => $menu_item['link']['href'],
// 					// '#localized_options' => $menu_item['link']['localized_options'],
// 					'#localized_options' => array_merge($menu_item['link']['localized_options'], array('html' => TRUE)),
// 					'#attributes' => array(
// 						'class' => array(
// 							'menu-' . $mlid,
// 							$class,
// 							$first_class,
// 							$oddeven_class,
// 							$last_class,
// 						),
// 					),
// 					'#original_link' => $menu_item['link'],
// 				);
// 				$variables['element'] = $element;
//
// 				// Check for context reactions menu.
// 				if (module_exists('context')) {
// 					context_preprocess_menu_link($variables);
// 					if (isset($variables['element']['#localized_options']['attributes']['class']) &&
// 						in_array('active', $variables['element']['#localized_options']['attributes']['class']) &&
// 						!in_array('active-trail', $variables['element']['#attributes']['class'])) {
// 						$variables['element']['#attributes']['class'][] = ' active-trail';
// 					}
// 				}
//
// 				$output .= theme('menu_link', $variables);
// 			}
// 		}
// 	}
// 	return $output;
// }






/**
 * Customization => Replacing ul by div elements to use bootstrap grid system
 *
 * @param array $variables
 * @return string
 */
// function emindhub_menu_link(array &$variables) {
// 	$classes = "";
//
// 	if ($variables['theme_hook_original'] == "menu_link__menu_top_anonymous"){
// 		$classes = "col-xs-4 upper";
//
// 		// Classe particulière pour le contactez nous/contact us
// 		if (strpos(strtolower($variables['element']['#title']), "contact") !== false) {
// 			$classes = $classes .' contact-us';
// 		}
// 	}
//
// 	if ($variables['theme_hook_original'] == "menu_link__menu_top"){
// 		$classes = "col-md-4 col-xs-4 upper";
// 		if (isset($variables['element']['#emhInformation'])) {
// 			$classes = "";
//
// 		}
//
// 		if (count($variables['element']['#below']) != 0) {
// 			foreach ($variables['element']['#below'] as $key => $subMenu) {
// 				if (strpos(strtolower($key), "#") === false) {
// 					$variables['element']['#below'][$key]["#emhInformation"] = "submenu";
// 				}
// 			}
// 		}
// 	}
//
// 	$sub_menu = '';
// 	$element = &$variables['element'];
// 	$pattern = '/\S+\.(png|gif|jpg)\b/i';
// 	if (preg_match($pattern, $element['#title'], $matches) > 0) {
// 		$element['#title'] = preg_replace($pattern,
// 			'',
// 			$element['#title']);
// 		$element['#localized_options']['html'] = TRUE;
// 		$classes = "col-sm-4";
// 	}
// 	if ($element['#below']) {
// 		$sub_menu = drupal_render($element['#below']);
// 	}
// 	$output = l($element['#title'], $element['#href'], $element['#localized_options']);
// 	return '<div class="'.$classes.'"><div' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</div></div>\n";
// }


function emindhub_preprocess_menu_link(&$vars) {
  // TODO : altérer uniquement le lien spécifique et non pas le lien par URL

  // Reference the menu item
  $element = &$vars['element'];

  switch ($element['#href']) {
    case 'user':
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
      $name = $firstName . '&nbsp;<span class="emh-blue bold text-uppercase">' . $lastName . '</span>';
      $element['#title'] = $name;
      $element['#localized_options']['html'] = 1;
      break;
  }

}


/**
 * Theme function to allow any menu tree to be themed as a Nice menu.
 *
 * Customization => Replacing ul by div elements to use bootstrap grid system
 *
 * @param array $variables
 *   is an array, menu arguments.
 *
 * @return mixed
 *   An HTML string of Nice menu links.
 */
// function emindhub_nice_menus($variables) {
// 	$output = array(
// 		'content' => '',
// 		'subject' => '',
// 	);
//
// 	// The Nice menu ID.
// 	$id = $variables['id'];
// 	// The top parent menu name from which to build the full menu.
// 	$menu_name = $variables['menu_name'];
// 	// The menu ID from which to build the displayed menu.
// 	$mlid = $variables['mlid'];
// 	// Optional. The direction the menu expands. Default is 'right'.
// 	$direction = $variables['direction'];
// 	// The number of children levels to display. Use -1 to display all children
// 	// and use 0 to display no children.
// 	$depth = $variables['depth'];
// 	/*
// 	 * Optional. A custom menu array to use for theming --
// 	 * it should have the same structure as that returned
// 	 * by menu_tree_all_data(). Default is the standard menu tree.
// 	 */
// 	$menu = $variables['menu'];
// 	// "Show as expanded" option.
// 	$respect_expanded = $variables['respect_expanded'];
// 	if ($menu_tree = theme('nice_menus_tree', array(
// 		'menu_name' => $menu_name,
// 		'mlid' => $mlid,
// 		'depth' => $depth,
// 		'menu' => $menu,
// 		'respect_expanded' => $respect_expanded))) {
// 		if ($menu_tree['content']) {
// 			$output['content'] = '<div class="row nice-menu nice-menu-' . $direction . ' nice-menu-' . $menu_name . '" id="nice-menu-' . $id . '">' . $menu_tree['content'] . '</div>' . "\n";
// 			$output['subject'] = $menu_tree['subject'];
// 		}
// 	}
// 	return $output;
// }

//============================================================================
// LANGUAGE CUSTOMIZATION SECTION

/**
 * Customization => The block ul/li is now a select
 * @param $vars
 * @return string
 * @throws Exception
 */
// function emindhub_links__locale_block(&$vars) {
// 	foreach($vars['links'] as $language => $langInfo) {
// 		$vars['links'][$language]['href'] = '';
// 	}
// 	$links = $vars['links'];
// 	$options = array();
// 	foreach ($links as  $key =>  $link) {
// 		$value = $link['language']->native;
// 		$options[] = $key;
// 	}
// 	$content = theme('select', array(
// 			"element" => array(
// 				'#attributes' => array(
// 					'id' => 'language_select',
// 					'name' => 'language',
// 				),
// 				'#options' => $options,
// 			))
// 	);
// 	return $content;
// }


// function emindhub_menu_tree__menu_footer_menu(&$variables) {
// 	return '<div class="footer-menu">' . $variables['tree'] . '</div>';
// }

// function emindhub_menu_link__menu_footer_menu(array $variables) {
// 	$element = $variables['element'];
// 	$sub_menu = '';
//
// 	$separator = "";
// 	if (!in_array ("last", $element['#attributes']['class'], TRUE)) {
// 		$separator = "&nbsp;|&nbsp";
// 	}
// 	array_push($element['#attributes']['class'], "inline", "upper", "bold");
// 	if ($element['#below']) {
// 		$sub_menu = drupal_render($element['#below']);
// 	}
// 	$output = l($element['#title'], $element['#href'], $element['#localized_options']);
//
// 	return '<div' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</div>".$separator;
// }



/**
 * Generate the user menu
 * @return array
 * @throws Exception
 */
// function GetMenu (&$vars) {
// 	//$base_url = $url = base_path();
// 	if (!user_is_logged_in()) {
// 		$signIn = theme('html_tag', array(
// 		  'element' => array(
//   			'#tag' => 'span',
//   			'#attributes' => array(
//   			  'class' => array('sign-in'),
//   			  // 'onclick' => 'signInClick()'
//   			),
//   			'#value' => c_szLogin,
// 		  ),
// 		));
// 		$register = theme('html_tag', array(
// 		  'element' => array(
//   			'#tag' => 'span',
//   			'#attributes' => array(
//   			  'class' => array('sign-up'),
//   			  // 'onclick' => 'signUpClick()'
//   			),
//   			'#value' => c_szRegister,
// 		  ),
// 		));
// 		return array($signIn, $register);
// 	}
// 	else {
// 		global $user;
// 		/**
// 		 * User Account
// 		 */
// 		$account = user_load($user->uid);
// 		if ($account) {
// 			$firstName = "";
// 			if (isset($account->field_first_name[LANGUAGE_NONE]) && $account->field_first_name[LANGUAGE_NONE]) {
// 				$firstName = $account->field_first_name[LANGUAGE_NONE][0]['value'];
// 			}
// 			$lastName = "";
// 			if (isset($account->field_last_name[LANGUAGE_NONE]) && $account->field_last_name[LANGUAGE_NONE]) {
// 				$lastName = $account->field_last_name[LANGUAGE_NONE][0]['value'];
// 			}
// 			$name = '<span class="light-blue-text bold">'.$lastName.'</span> '.$firstName;
// 		}
// 		$accountMenu = theme("link", array(
// 		  'text' => $name,
// 		  'path' => 'user',
// 		  'options' => array(
// 			'attributes' => array('class' => array('user-menu')),
// 			'html' => TRUE,
// 		  ),
// 		));
// 		$logout = theme("link", array(
// 		  'text' => c_szLogout,
// 		  'path' => 'user/logout',
// 		  'options' => array(
// 			'attributes' => array('class' => array('user-menu')),
// 			'html' => FALSE,
// 		  ),
// 		));
// 		return array($accountMenu, $logout);
// 	}
// }



/**
 * Overrides theme_menu_tree().
 */
function bootstrap_menu_tree__user_menu(&$variables) {
  return '<ul class="menu nav navbar-nav navbar-emh-separator">' . $variables['tree'] . '</ul>';
}
function bootstrap_menu_tree__menu_top(&$variables) {
  return '<ul class="menu nav nav-justified">' . $variables['tree'] . '</ul>';
}
function bootstrap_menu_tree__menu_top_anonymous(&$variables) {
  return '<ul class="menu nav nav-justified">' . $variables['tree'] . '</ul>';
}
function bootstrap_menu_tree__menu_burger_menu(&$variables) {
  return '<ul class="menu nav navbar-emh-burger">' . $variables['tree'] . '</ul>';
}
function bootstrap_menu_tree__menu_footer_menu(&$variables) {
  return '<ul class="menu nav navbar-nav navbar-emh-separator">' . $variables['tree'] . '</ul>';
}
