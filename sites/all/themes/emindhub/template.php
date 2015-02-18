<?php
/*
function emindhub_views_pre_render(&$view) {
    if ($view->name== 'query-list-block' ) {
        foreach($view->result as $r => $result) {
            var_dump($view);
            die;
            // do whatever you want with each "row"
        }
    }
}*/
/*
function emindhub_preprocess_views_view_fields(&$vars) {
    $view = $vars['view'];
    //var_dump($view);
    //$vars['fields'] = array();
//    print "=====================";
//    var_dump(get_object_vars($view));
//    print "=====================";
    //die;
}

function emindhub_preprocess_views_view_table(&$vars) {
    /*$view = $vars['view'];
    $options = $view->style_plugin->options;
    var_dump($options);
    die;*//*
}
*/
/*
function emindhub_preprocess_field(&$variables) {
    print $variables['element']['#field_name'];
    if($variables['element']['#field_name'] == 'Picto') {
        if($variables['items']['0']['#markup'] == 'thedefaultvalue') {
            $variables['items']['0']['#markup'] = '';
        }
    }
}
*/
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

//============================================================================
// CONTACT FORM CUSTOMIZATION SECTION

function emindhub_theme() {
    return array(
        'contact_site_form' => array(
            'render element' => 'form',
            'path' => drupal_get_path('theme', 'emindhub').'/templates',
            'template' => 'contact-site-form',
        ),/*
        'user_login' => array(
            'path' => drupal_get_path('theme', 'emindhub').'/templates',
            'template' => 'user_login',
            'render element' => 'form',
        ),*/
    );
}

function emindhub_form_alter(&$form, &$form_state, $form_id) {
    if ($form_id == 'search_block_form') {
        $form['search_block_form']['#title'] = t('Search'); // Change the text on the label element
        $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibilty
        $form['search_block_form']['#size'] = 40;  // define size of the textfield
        //$form['search_block_form']['#default_value'] = t('Search'); // Set a default value for the textfield
        $form['actions']['submit']['#value'] = t('GO!'); // Change the text on the submit button
        $form['actions']['submit']['#attributes']['class'] = array('element-invisible');

//        $form['actions']['submit'] = array('#type' => 'imput');

        // Add extra attributes to the text box
        $form['search_block_form']['#attributes']['class'] = array('search-input', 'form-control');
        $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') {this.value = 'Search';}";
        $form['search_block_form']['#attributes']['onfocus'] = "if (this.value == 'Search') {this.value = '';}";
        // Prevent user from searching the default text
        //$form['#attributes']['onsubmit'] = "if(this.search_block_form.value=='Search'){ alert('Please enter a search'); return false; }";

        // Alternative (HTML5) placeholder attribute instead of using the javascript
        $form['search_block_form']['#attributes']['placeholder'] = t('Votre recherche, mots clefs...');


        $form['#theme_wrappers'] = array();
//            array (size=1)
//      0 => string 'form' (length=4)
//        var_dump($form);
//        die;
    }
}
/*
function emindhub_search_form($form, &$form_state, $action = '', $keys = '', $module = NULL, $prompt = NULL) {
    $module_info = FALSE;
    if (!$module) {
        $module_info = search_get_default_module_info();
    }
    else {
        $info = search_get_info();
        $module_info = isset($info[$module]) ? $info[$module] : FALSE;
    }

    // Sanity check.
    if (!$module_info) {
        form_set_error(NULL, t('Search is currently disabled.'), 'error');
        return $form;
    }

    if (!$action) {
        $action = 'search/' . $module_info['path'];
    }
    if (!isset($prompt)) {
        $prompt = t('Enter your keywords');
    }

    $form['#action'] = url($action);
    // Record the $action for later use in redirecting.
    $form_state['action'] = $action;
    $form['#attributes']['class'][] = 'search-form';
    $form['module'] = array(
        '#type' => 'value',
        '#value' => $module,
    );
    $form['basic'] = array(
        '#type' => 'container',
        '#attributes' => array('class' => array('container-inline', 'form-group')),
    );
    $form['basic']['keys'] = array(
        '#type' => 'textfield',
        '#title' => $prompt,
        '#default_value' => $keys,
        '#size' => $prompt ? 40 : 20,
        '#maxlength' => 255,
        '#attributes' => array(
            'class' => array('search-input', 'form-control'),
            'placeholder' => 'Votre recherche, mots clefs...',
        ),
    );
    // processed_keys is used to coordinate keyword passing between other forms
    // that hook into the basic search form.
    $form['basic']['processed_keys'] = array(
        '#type' => 'value',
        '#value' => '',
    );

//    $form['basic']['submit'] = array(
//        '#type' => 'submit',
//        '#value' => t('Search'),
//    );

    return $form;
}
*/
/*function emindhub_preprocess_search_block_form(&$variables) {
    $variables['search'] = array();
    $hidden = array();
    // Provide variables named after form keys so themers can print each element independently.
    foreach (element_children($variables['form']) as $key) {
        $type = isset($variables['form'][$key]['#type']) ? $variables['form'][$key]['#type'] : '';
        if ($type == 'hidden' || $type == 'token') {
            $hidden[] = drupal_render($variables['form'][$key]);
        }
        else {
            $variables['search'][$key] = drupal_render($variables['form'][$key]);
        }
    }
    // Hidden form elements have no value to themers. No need for separation.
    $variables['search']['hidden'] = implode($hidden);
    // Collect all form elements to make it easier to print the whole form.
    $variables['search_form'] = implode($variables['search']);
}*/
/*
function emindhub_form_contact_site_form_alter(&$form, &$form_state)
{
*/
    /*$form['#theme'] = 'contact_site_form';*/
//    $form['#title'] = '';
 /*   $form['title']  ="";
    $form['contact_site_form'] = array(
        '#type' => 'checkbox',
        '#title' => t(""),
        '#required' => TRUE,
    );
    $form['#bulleImg'] = theme('image', array(
        'path' => imagePath("bulle.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));*/

    /*$form['name']['#title'] = t('Nom');
    $form['mail']['#title'] = t('Email');
    $form['message']['#title'] = t('Votre question, remarque ou information à partager');
    foreach (array('name', 'mail', 'firstname', 'zip', 'city', 'phone') as $field) {
        $form[$field]['#size'] = 20;
    }
    $form['captcha']['#description'] = t('Merci de recopier le texte ci-dessous pour valider votre demande *');
    $form['subject']['#type'] = 'hidden';
    unset($form['subject']['#required']);*/
/*
}
*/

// TODO : Customizable text settings

/**
 * Generate the user menu
 * @return array
 * @throws Exception
 */
function GetMenu (&$vars) {
    //$base_url = $url = base_path();
    if (!user_is_logged_in()) {
        $signIn = theme("link", array(
            'text' => t('Se connecter'),
            'path' => 'user',
            'options' => array(
                'attributes' => array('class' => array('user-menu')),
                'html' => FALSE,
            ),
        ));
        $register = theme("link", array(
            'text' => t('S\'inscrire'),
            'path' => '',
            'options' => array(
                'attributes' => array('class' => array('user-menu')),
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
            'path' => '',
            'options' => array(
                'attributes' => array('class' => array('user-menu')),
                'html' => TRUE,
            ),
        ));
        $logout = theme("link", array(
            'text' => t('Se déconnecter'),
            'path' => 'user/logout',
            'options' => array(
                'attributes' => array('class' => array('user-menu')),
                'html' => FALSE,
            ),
        ));
        return array($accountMenu, $logout);
    }
}

/**
 * Additional page variables
 */
function emindhub_preprocess_page(&$vars) {
    // CUSTOMIZABLE TEXT  ==============================================================
    // banniere
    $vars['banniereText'] = t("ACCÉDEZ EN LIGNE <p>AU 1ER RÉSEAU MONDIAL D’EXPERTS</p> EN AÉRONAUTIQUE & SPATIAL");

    $vars['firstMenu'] = GetMenu($vars);

    // LOGO SECTION  ==============================================================
    // site logo
    $vars['imagelogo'] = theme('image', array(
        'path' => imagePath("logo.png"),
        'alt'  => $vars['site_name'],
        'getsize' => FALSE,
        'attributes' => array('id' => 'logo'),
    ));

    $vars['imagelogo'] = l(
        $vars['imagelogo'],
        '<front>',
        array(
            'html' => TRUE,
            'attributes' => array(
                'title' => t('Retour à l\'accueil'),
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
        'alt' => t('Vous avez une demande'),
        'getsize' => FALSE,
    ));

    // Vous avez une expertise
    $vars['expertiseImg'] = theme('image', array(
        'path' => imagePath("expertise.png"),
        'alt'=> t('Vous avez une expertise'),
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

function imagePath($fileName) {
    return sprintf("%s/images/%s", path_to_theme(), $fileName);
}

function emindhub_preprocess_html(&$variables) {
    drupal_add_css('http://fonts.googleapis.com/css?family=Lato&subset=latin,latin-ext' , array('type' => 'external'));
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
function emindhub_menu_link(array $variables) {
    $sub_menu = '';
    $element = &$variables['element'];
    $pattern = '/\S+\.(png|gif|jpg)\b/i';
    $classes = "";
    if (preg_match($pattern, $element['#title'], $matches) > 0) {
        $element['#title'] = preg_replace($pattern,
            '',
            $element['#title']);
        $element['#localized_options']['html'] = TRUE;
        $classes = "col-md-4";
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

/*
 * USEFULL FUNCTION
 */
function isAdminUser () {
    global $user;
    return (in_array('administrator', array_values($user->roles)));
}