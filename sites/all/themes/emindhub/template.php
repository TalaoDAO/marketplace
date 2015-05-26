<?php

//require_once("templates/PHPDebug.php");
require_once("templates/includes/string_list.php");

//============================================================================
// CONTACT FORM CUSTOMIZATION SECTION


function emindhub_date_combo($variables) {
  return theme('form_element', $variables);
}

function emindhub_status_messages($variables) {
  $display = $variables ['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= "<div class=\"messages $type\">\n";
    if (!empty($status_heading [$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading [$type] . "</h2>\n";
    }
    $output .= "<span class=\"drupal-message\">".$status_heading[$type].":</span>";
    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= reset($messages);
    }
    $output .= "</div>\n";
  }
  return $output;
}

function emindhub_theme() {
    return array(
      'contact_site_form' => array(
        'render element' => 'form',
        'path' => drupal_get_path('theme', 'emindhub').'/templates',
        'template' => 'contact-site-form',
      ),
      'user_picture' => array(
        'path' => drupal_get_path('theme', 'emindhub').'/templates',
        'template' => 'user_picture',
        'render element' => 'image',
      ),
      /*'user_register_form' => array(
        'path' => drupal_get_path('theme', 'emindhub').'/templates',
        'template' => 'user-register-form',
        'render element' => 'form'
      ),*/
      /*
      'password' => array (
        'path' => drupal_get_path('theme', 'emindhub').'/templates',
        'template' => 'password-confirm',
        'render element' => 'form',
      ),*/
      'user_login' => array(
        'path' => drupal_get_path('theme', 'emindhub').'/templates',
        'template' => 'user-login',
        'render element' => 'form',
      ),
    );
}

function emindhub_file($variables) {
    $element = $variables['element'];
    $element['#attributes']['type'] = 'file';
    element_set_attributes($element, array('id', 'name', 'size'));
    _form_set_class($element, array('form-file'));

    return sprintf('<input type="text" disabled data-fileinputtext="%s" class="file-return"><div class="file-upload"><span>%s</span><input' . drupal_attributes($element['#attributes']) . ' /></div>', $element["#id"], c_szChooseFile);
}

function emindhub_preprocess_user_picture(&$variables) {
    $variables['user_picture'] = '';
    //dpm('toto');
    //if (variable_get('user_pictures', true)) {
        if (isset($variables['account'])) {
            $account = $variables['account'];
            if (!empty($account->picture)) {
                // @TODO: Ideally this function would only be passed file objects, but
                // since there's a lot of legacy code that JOINs the {users} table to
                // {node} or {comments} and passes the results into this function if we
                // a numeric value in the picture field we'll assume it's a file id
                // and load it for them. Once we've got user_load_multiple() and
                // comment_load_multiple() functions the user module will be able to load
                // the picture files in mass during the object's load process.
                if (is_numeric($account->picture)) {
                    $account->picture = file_load($account->picture);
                    //dsm($account->picture);
                    //dsm('on as trouvé une image !!');
                }
                if (!empty($account->picture->uri)) {
                    $filepath = $account->picture->uri;
                    //dsm('on as trouvé une image !! bis');
                    //dsm($account->picture);
                }
            }
            elseif (variable_get('user_picture_default', '')) {
                $filepath = variable_get('user_picture_default', '');
                //dsm('on as trouvé une image default !!');
            }
            if (isset($filepath)) {
                $alt = t("@user's picture", array('@user' => format_username($account)));
                // If the image does not have a valid Drupal scheme (for eg. HTTP),
                // don't load image styles.
                if (module_exists('image') && file_valid_uri($filepath) && $style = variable_get('user_picture_style', '')) {
                    $variables['user_picture'] = theme('user_picture', array(
                            'style_name' => $style,
                            'path' => $filepath,
                            'alt' => $alt,
                            'title' => $alt
                        ));
                }
                else {
                    $variables['user_picture'] = theme('user_picture', array(
                            'path' => $filepath,
                            'alt' => $alt,
                            'title' => $alt
                        ));
                }
                if (!empty($account->uid) && user_access('access user profiles')) {
                    $attributes = array(
                        'attributes' => array('title' => c_szViewUsrProfile),
                        'html' => TRUE
                    );
                    $variables['user_picture'] = l($variables['user_picture'], "user/$account->uid", $attributes);
                }
            }
        }
        else {
            dsm('! isset($variables[account])');
        }
    /*} else {
        dsm('variable_get("user_pictures", 0)');
    }*/
}

function emindhub_form_alter(&$form, &$form_state, $form_id) {
    if ($form_id == 'search_block_form') {
        $form['search_block_form']['#title'] = c_szSearch; // Change the text on the label element
        $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibilty
        $form['search_block_form']['#size'] = 40;  // define size of the textfield
        //$form['search_block_form']['#default_value'] = t('Search'); // Set a default value for the textfield
        $form['actions']['submit']['#value'] = c_szGo; // Change the text on the submit button
        $form['actions']['submit']['#attributes']['class'] = array('element-invisible');

//        $form['actions']['submit'] = array('#type' => 'imput');

        // Add extra attributes to the text box
        $form['search_block_form']['#attributes']['class'] = array('search-input', 'form-control');
        $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') {this.value = 'Search';}";
        $form['search_block_form']['#attributes']['onfocus'] = "if (this.value == 'Search') {this.value = '';}";
        // Prevent user from searching the default text
        //$form['#attributes']['onsubmit'] = "if(this.search_block_form.value=='Search'){ alert('Please enter a search'); return false; }";

        // Alternative (HTML5) placeholder attribute instead of using the javascript
        $form['search_block_form']['#attributes']['placeholder'] = c_szYourSearch;


        $form['#theme_wrappers'] = array();
//            array (size=1)
//      0 => string 'form' (length=4)
//        var_dump($form);
//        die;
    }
}


/**
 * Additional page variables
 */
function emindhub_preprocess_page(&$vars) {

    //dsm("test message à mettre en forme");

    // CUSTOMIZABLE TEXT  ==============================================================
    // banniere
    $vars['banniereText'] = sprintf(c_szTextBanniere, "<p>", "</p>");

    $vars['firstMenu'] = GetMenu($vars);

    // LOGO SECTION  ==============================================================
    // site logo
    $vars['imagelogo'] = theme('image', array(
        'path' => imagePath("logo.png"),
        'alt'  => $vars['site_name'],
        'getsize' => FALSE,
        'attributes' => array(
            'id' => 'logo',
            'class' => array(
                'img-responsive'
            ),
        ),
    ));

    $vars['imagelogo'] = l(
        $vars['imagelogo'],
        '<front>',
        array(
            'html' => TRUE,
            'attributes' => array(
                'title' => c_szBackHome,
            )
        )
    );

    // IMAGES SECTION  ==============================================================
    // mail icon
    $vars['mailIcon'] = theme('image', array(
        'path' => imagePath('mailIcon.png'),
        'alt' => 'email',
        'getsize' => FALSE,
    ));

    // Vous avez une demande
    $vars['demandeImg'] = theme('image', array(
        'path' => imagePath("demande.png"),
//        'alt' => t('Vous avez une demande'),
        'getsize' => FALSE,
    ));

    // Vous avez une expertise
    $vars['expertiseImg'] = theme('image', array(
        'path' => imagePath("expertise.png"),
//        'alt'=> t('Vous avez une expertise'),
        'getsize' => FALSE,
    ));

    $vars['atomiumImg'] = theme('image', array(
        'path' => imagePath("atomium.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['cercleImg'] = theme('image', array(
        'path' => imagePath("cercle.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['peopleImg'] = theme('image', array(
        'path' => imagePath("people.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['rapiditeImg'] = theme('image', array(
        'path' => imagePath("rapidite.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['securiteImg'] = theme('image', array(
        'path' => imagePath("securite.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['qualiteImg'] = theme('image', array(
        'path' => imagePath("qualite.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['pointImg'] = theme('image', array(
        'path' => imagePath("point.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['aerofuturImg'] = theme('image', array(
        'path' => imagePath("aerofutur.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['jmLbcImg'] = theme('image', array(
        'path' => imagePath("jmLbc.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['bulleImg'] = theme('image', array(
        'path' => imagePath("bulle.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['previousImg'] = theme('image', array(
        'path' => imagePath("previous.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['menuIconImg'] = theme('image', array(
        'path' => imagePath("menuIcon.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['nextImg'] = theme('image', array(
        'path' => imagePath("next.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['fluxIconImg'] = theme('image', array(
        'path' => imagePath("fluxIcon.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['actuImg'] = theme('image', array(
        'path' => imagePath("actu.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    $vars['openBurgerImg'] = theme('image', array(
        'path' => imagePath("menuBtn.png"),
        'alt' => '',
        'getsize' => FALSE,
    ));


    $vars['secondMenu'] = FALSE;
}

function emindhub_preprocess_html(&$variables) {
//    drupal_add_css('http://fonts.googleapis.com/css?family=Lato&subset=latin,latin-ext' , array('type' => 'external'));
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
                if ($entity) { 
                    $variables['company_name'] = $entity->title;
                    if ($entity->body)
                        $variables['company_description'] = $entity->body[LANGUAGE_NONE][0]["value"];
                }
            }
        }
    }
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
function emindhub_nice_menus_build($variables) {
    // Menu array from which to build the nested lists.
    $menu = $variables['menu'];

    // The number of children levels to display. Use -1 to display all children
    // and use 0 to display no children.
    $depth = $variables['depth'];

    // An array of parent menu items.
    $trail = $variables['trail'];
    // "Show as expanded" option.
    $respect_expanded = $variables['respect_expanded'];

    $output = '';
    // Prepare to count the links so we can mark first, last, odd and even.
    $index = 0;
    $count = 0;
    foreach ($menu as $menu_count) {
        if ($menu_count['link']['hidden'] == 0) {
            $count++;
        }
    }
    // Get to building the menu.
    foreach ($menu as $menu_item) {
        $mlid = $menu_item['link']['mlid'];
        // Check to see if it is a visible menu item.
        if (!isset($menu_item['link']['hidden']) || $menu_item['link']['hidden'] == 0) {
            // Check our count and build first, last, odd/even classes.
            $index++;
            $first_class = ($index == 1) ? 'first' : '';
            $oddeven_class = ($index % 2 == 0) ? 'even' : 'odd';
            $last_class = ($index == $count) ? 'last' : '';
            // Build class name based on menu path
            // e.g. to give each menu item individual style.
            $class = str_replace(array('http', 'https', '://', 'www'), '', $menu_item['link']['href']);
            // Strip funny symbols.
            $class = drupal_html_class('menu-path-' . $class);
            if ($trail && in_array($mlid, $trail)) {
                $class .= ' active-trail';
            }
            // If it has children build a nice little tree under it.
            // Build a nice little tree under it if it has children, and has been set
            // to expand (when that option is being respected).
            if ((!empty($menu_item['link']['has_children'])) &&
                (!empty($menu_item['below'])) && $depth != 0 &&
                ($respect_expanded == 0 || $menu_item['link']['expanded'])) {
                // Keep passing children into the function 'til we get them all.
                if ($menu_item['link']['depth'] <= $depth || $depth == -1) {
                    $children = array(
                        '#theme' => 'nice_menus_build',
                        '#prefix' => '<ul>',
                        '#suffix' => '</ul>',
                        '#menu' => $menu_item['below'],
                        '#depth' => $depth,
                        '#trail' => $trail,
                        '#respect_expanded' => $respect_expanded,
                    );
                }
                else {
                    $children = '';
                }
                // Set the class to parent only of children are displayed.
                $parent_class = ($children && ($menu_item['link']['depth'] <= $depth || $depth == -1)) ? 'menuparent ' : '';
                $element = array(
                    '#below' => $children,
                    '#title' => $menu_item['link']['title'],
                    '#href' => $menu_item['link']['href'],
//                    '#localized_options' => $menu_item['link']['localized_options'],
                    '#localized_options' => array_merge($menu_item['link']['localized_options'], array('html' => TRUE)),
                    '#attributes' => array(
                        'class' => array(
                            'menu-' . $mlid,
                            $parent_class,
                            $class,
                            $first_class,
                            $oddeven_class,
                            $last_class,
                        ),
                    ),
                    '#original_link' => $menu_item['link'],
                );
                $variables['element'] = $element;

                // Check for context reactions menu.
                if (module_exists('context')) {
                    context_preprocess_menu_link($variables);
                    if (isset($variables['element']['#localized_options']['attributes']['class']) &&
                        in_array('active', $variables['element']['#localized_options']['attributes']['class']) &&
                        !in_array('active-trail', $variables['element']['#attributes']['class'])) {
                        $variables['element']['#attributes']['class'][] = ' active-trail';
                    }
                }

                $output .= theme('menu_link', $variables);
            }
            else {
                $element = array(
                    '#below' => '',
                    '#title' => $menu_item['link']['title'],
                    '#href' => $menu_item['link']['href'],
//                    '#localized_options' => $menu_item['link']['localized_options'],
                    '#localized_options' => array_merge($menu_item['link']['localized_options'], array('html' => TRUE)),
                    '#attributes' => array(
                        'class' => array(
                            'menu-' . $mlid,
                            $class,
                            $first_class,
                            $oddeven_class,
                            $last_class,
                        ),
                    ),
                    '#original_link' => $menu_item['link'],
                );
                $variables['element'] = $element;

                // Check for context reactions menu.
                if (module_exists('context')) {
                    context_preprocess_menu_link($variables);
                    if (isset($variables['element']['#localized_options']['attributes']['class']) &&
                        in_array('active', $variables['element']['#localized_options']['attributes']['class']) &&
                        !in_array('active-trail', $variables['element']['#attributes']['class'])) {
                        $variables['element']['#attributes']['class'][] = ' active-trail';
                    }
                }

                $output .= theme('menu_link', $variables);
            }
        }
    }
    return $output;
}


/**
 * Customization => Replacing ul by div elements to use bootstrap grid system
 *
 * @param array $variables
 * @return string
 */
function emindhub_menu_link(array &$variables) {
    $classes = "";

    if ($variables['theme_hook_original'] == "menu_link__menu_top_anonymous"){
        $classes = "col-xs-4 upper";

        //Classe particulière pour le contactez nous/contact us
        if (strpos(strtolower($variables['element']['#title']), "contact") !== false) {
            $classes = $classes .' contact-us';
        }
    }

    if ($variables['theme_hook_original'] == "menu_link__menu_top"){
        $classes = "col-md-4 col-xs-4 upper";
        if (isset($variables['element']['#emhInformation'])) {
            $classes = "";

        }

        if (count($variables['element']['#below']) != 0) {
            foreach ($variables['element']['#below'] as $key => $subMenu) {
                if (strpos(strtolower($key), "#") === false) {
                    $variables['element']['#below'][$key]["#emhInformation"] = "submenu";
                }
            }
        }
    }

    $sub_menu = '';
    $element = &$variables['element'];
    $pattern = '/\S+\.(png|gif|jpg)\b/i';
    if (preg_match($pattern, $element['#title'], $matches) > 0) {
        $element['#title'] = preg_replace($pattern,
            '',
            $element['#title']);
        $element['#localized_options']['html'] = TRUE;
        $classes = "col-sm-4";
    }
    if ($element['#below']) {
        $sub_menu = drupal_render($element['#below']);
    }
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
//    return '<div class=""><div' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</div></div>\n";
    return '<div class="'.$classes.'"><div' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</div></div>\n";
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
function emindhub_nice_menus($variables) {
    $output = array(
        'content' => '',
        'subject' => '',
    );

    // The Nice menu ID.
    $id = $variables['id'];
    // The top parent menu name from which to build the full menu.
    $menu_name = $variables['menu_name'];
    // The menu ID from which to build the displayed menu.
    $mlid = $variables['mlid'];
    // Optional. The direction the menu expands. Default is 'right'.
    $direction = $variables['direction'];
    // The number of children levels to display. Use -1 to display all children
    // and use 0 to display no children.
    $depth = $variables['depth'];
    /*
     * Optional. A custom menu array to use for theming --
     * it should have the same structure as that returned
     * by menu_tree_all_data(). Default is the standard menu tree.
     */
    $menu = $variables['menu'];
    // "Show as expanded" option.
    $respect_expanded = $variables['respect_expanded'];
    if ($menu_tree = theme('nice_menus_tree', array(
        'menu_name' => $menu_name,
        'mlid' => $mlid,
        'depth' => $depth,
        'menu' => $menu,
        'respect_expanded' => $respect_expanded))) {
        if ($menu_tree['content']) {
            $output['content'] = '<div class="row nice-menu nice-menu-' . $direction . ' nice-menu-' . $menu_name . '" id="nice-menu-' . $id . '">' . $menu_tree['content'] . '</div>' . "\n";
            $output['subject'] = $menu_tree['subject'];
        }
    }
    return $output;
}

//============================================================================
// LANGUAGE CUSTOMIZATION SECTION

/**
 * Customization => The block ul/li is now a select
 * @param $vars
 * @return string
 * @throws Exception
 */
function emindhub_links__locale_block(&$vars) {
    foreach($vars['links'] as $language => $langInfo) {
        $vars['links'][$language]['href'] = '';
    }
    $links = $vars['links'];
    $options = array();
    foreach ($links as  $key =>  $link) {
        $value = $link['language']->native;
        $options[] = $key;
    }
    $content = theme('select', array(
            "element" => array(
                '#attributes' => array(
                    'id' => 'language_select',
                    'name' => 'language',
                ),
                '#options' => $options,
            ))
    );
    return $content;
}

function emindhub_form_user_register_form_alter(&$vars) {
    //echo 'toto';
    //$vars['profile_expert']['field_domaine']
    $vars['field_first_name']['#access'] = true;
    $vars['field_last_name']['#access'] = true;
}

function emindhub_password_confirm_process($element) {
    $element['pass1']['#attributes']['title'] = 'Title';
    $element['pass2']['#attributes']['title'] = 'Title2';
    return $element;
}

function emindhub_menu_tree__menu_footer_menu(&$variables) {
    return '<div class="footer-menu">' . $variables['tree'] . '</div>';
}

function emindhub_menu_link__menu_footer_menu(array $variables) {
    $element = $variables['element'];
    $sub_menu = '';

    $separator = "";
    if (!in_array ("last", $element['#attributes']['class'], TRUE)) {
        $separator = "&nbsp;|&nbsp";
    }
    array_push($element['#attributes']['class'], "inline", "upper", "bold");
    if ($element['#below']) {
        $sub_menu = drupal_render($element['#below']);
    }
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);

    return '<div' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</div>".$separator;
}

/*
 * USEFULL FUNCTION
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
            $isHomePage = true;
        }*/
        if (drupal_get_path_alias() == "homepage") {
            $isHomePage = true;
        }
    }
    return $isHomePage;
}

/**
 * Generate the user menu
 * @return array
 * @throws Exception
 */
function GetMenu (&$vars) {
    //$base_url = $url = base_path();
    if (!user_is_logged_in()) {
        $signIn = theme("link", array(
          'text' => c_szLogin,
          'path' => 'user',
          'options' => array(
            'attributes' => array('class' => array('user-menu', 'sign-in')),
            'html' => FALSE,
          ),
        ));
        $register = theme("link", array(
          'text' => c_szRegister,
          'path' => 'user/register',
          'options' => array(
            'attributes' => array('class' => array('user-menu', 'sign-up')),
            'html' => FALSE,
          ),
        ));
        return array($signIn, $register);
    }
    else {
        global $user;
        /**
         * User Account
         */
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
            $name = '<span class="light-blue-text bold">'.$lastName.'</span> '.$firstName;
        }
        $accountMenu = theme("link", array(
          'text' => $name,
          'path' => 'user',
          'options' => array(
            'attributes' => array('class' => array('user-menu')),
            'html' => TRUE,
          ),
        ));
        $logout = theme("link", array(
          'text' => c_szLogout,
          'path' => 'user/logout',
          'options' => array(
            'attributes' => array('class' => array('user-menu')),
            'html' => FALSE,
          ),
        ));
        return array($accountMenu, $logout);
    }
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
