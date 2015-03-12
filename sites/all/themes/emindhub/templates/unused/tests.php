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

/*function getNodeFromTypeAndId_($type, $nid, $next_prev) {
    //select * from node where type = 'challenge' and nid < 315 order by nid desc limit 1
    if ($next_prev == 'next') {
        $query = 'SELECT nid, title, created FROM {node} WHERE type = :type AND nid > :nid ORDER BY nid DESC LIMIT 1';
    }
    else {
        $query = 'SELECT nid, title, created FROM {node} WHERE type = :type AND nid < :nid ORDER BY nid DESC LIMIT 1';
    }

    $result = db_query($query,
        array(
            ':nid' => $nid,
            ':type' => $type
        ));
    if ($result) {
        return $result->currentRow['nid'];
    }
    return false;
}*/


//views-exposed-form--query-list--block.tpl
/**
 * Generic preprocess that is still working on D7
 */
/*function emindhub_preprocess_views_view_fields(&$vars) {
  if (isset($vars['view']->name)) {
    $function = 'emindhub_preprocess_views_view_fields__' . $vars['view']->name . '__' . $vars['view']->current_display;
    var_dump($function);
//    die;
    if (function_exists($function)) {
      $function($vars);
    }
  }
}*/

/**
 * Then the specific preprocess that worked without the above code for D6
 */
/*function emindhub_preprocess_views_view_fields__query_list__block_1(&$vars) {
  // my specific preprocess code
  var_dump($vars);
//  die;
}*/

/*
function emindhub_preprocess_views_view_table(&$vars) {

  if (isset($vars['view']->name)) {
    $function = 'emindhub_preprocess_views_view_table__' . $vars['view']->name . '__' . $vars['view']->current_display;
    //var_dump($function);
//    die;
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

function emindhub_preprocess_views_view_table__query_list__block(&$vars) {
  echo 'toto';
}
*/


function emindhub_preprocess_node__challenge(&$vars) {
    //Get the node id
    /*if (arg(0) == 'node' && is_numeric(arg(1))) {
        $nid = arg(1);
    }

    $prev_nid = $nid - 1;
    $next_nid = $nid + 1;
    $vars['previous_link'] = $prev_nid;
    $vars['next_link'] = $next_nid;*/

//    $nodes = getNodeFromTypeAndId("challenge", $prev_nid);
//    $nodeId = getNodeFromTypeAndId_("challenge", $nid, 'prev');
//    if ($nodeId) {
//        $vars['previous_link'] = $nodes['node'][$prev_nid]->nid;
//        $vars['previous_link'] = $nodeId;
//    }

    //node_load()

//    $nodes = getNodeFromTypeAndId("challenge", $next_nid);
//    $nodeId = getNodeFromTypeAndId_("challenge", $next_nid, 'next');
//    if ($nodeId) {
//        $vars['next_link'] = $nodes['node'][$next_nid]->nid;
//        $vars['next_link'] = $nodeId;
//    }
    $vars['first'] = false;
    if ($vars['teaser']) {
        global $teaserFisrtChallenge;
        if (!isset($teaserFisrtChallenge)) {
            $teaserFisrtChallenge = $vars['id'];
            $vars['first'] = true;
        }
    }
}


function getNodeFromTypeAndId($type, $nid, $next_prev) {
    $query = new EntityFieldQuery();

    $entities = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', $type)
      ->propertyCondition('nid', $nid)
      ->propertyCondition('status', 1)
      ->range(0,1)
      ->execute();

    if (!empty($entities['node'])) {
        return $entities;
    }
    return false;
}