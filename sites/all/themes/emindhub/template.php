<?php

//============================================================================
// CONTACT FORM CUSTOMIZATION SECTION

function emindhub_theme() {
    return array(
        'contact_site_form' => array(
            'render element' => 'form',
            'path' => drupal_get_path('theme', 'emindhub').'/templates',
            'template' => 'contact-site-form',
        ),
    );
}


function emindhub_form_contact_site_form_alter(&$form, &$form_state)
{
    $form['#theme'] = 'contact_site_form';
    $form['#bulleImg'] = theme('image', array(
        'path' => imagePath("bulle.png"),
        'alt'=> '',
        'getsize' => FALSE,
    ));

    /*$form['name']['#title'] = t('Nom');
    $form['mail']['#title'] = t('Email');
    $form['message']['#title'] = t('Votre question, remarque ou information à partager');
    foreach (array('name', 'mail', 'firstname', 'zip', 'city', 'phone') as $field) {
        $form[$field]['#size'] = 20;
    }
    $form['captcha']['#description'] = t('Merci de recopier le texte ci-dessous pour valider votre demande *');
    $form['subject']['#type'] = 'hidden';
    unset($form['subject']['#required']);*/
}

// TODO : Customizable text settings

/**
 * Generate the user menu
 * @return array
 * @throws Exception
 */
function GetMenu (&$vars) {
    if (!user_is_logged_in()) {

        $signIn = theme("link", array(
            'text' => 'Se connecter',
            'path' => '',
            'options' => array(
                'attributes' => array('class' => array('user-menu')),
                'html' => FALSE,
            ),
        ));
        $register = theme("link", array(
            'text' => 'S\'inscrire',
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
            $name = '<span class="light-blue-text bold">'.$account->field_last_name[LANGUAGE_NONE][0]['value'].'</span> '.$account->field_first_name[LANGUAGE_NONE][0]['value'];
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
            'text' => 'Se déconnecter',
            'path' => './user/logout',
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
        'alt' => 'Vous avez une demande',
        'getsize' => FALSE,
    ));

    // Vous avez une expertise
    $vars['expertiseImg'] = theme('image', array(
        'path' => imagePath("expertise.png"),
        'alt'=> 'Vous avez une expertise',
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
    $element = $variables['element'];
    $sub_menu = '';

    if ($element['#below']) {
        $sub_menu = drupal_render($element['#below']);
    }
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
    return '<div class="col-md-4"><div' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</div></div>\n";
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