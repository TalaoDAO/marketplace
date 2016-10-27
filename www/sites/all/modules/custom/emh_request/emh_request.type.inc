<?php

/**
 * @file
 * Fill form elements with data from GET or POST values.
 *
 * based on prepopulate module
 */

/**
 * An #after_build function to set the values prepopulated in the request.
 */
function emh_request_prepopulate_after_build($form, &$form_state) {
  if (isset($_REQUEST['edit'])) {
    $request = (array) $_REQUEST['edit'];
    _emh_request_prepopulate_request_walk($form, $request, $form_state, $form_state['field']);
  }
  return $form;
}

function _emh_request_multivaluefield_create_empty_slots(&$form, $form_state, $form_id, $field_name, $items_count) {
    $form_theme = $form[$field_name][LANGUAGE_NONE]['#theme'];
    $after_build = $form[$field_name][LANGUAGE_NONE]['#after_build'];
    $items = &$form_state['field'][$field_name][LANGUAGE_NONE];
    // Generate required number of fields collection
    if ($items_count > 1 and $items['items_count'] != $items_count) {
      $items['items_count'] = $items_count;
      $form[$field_name][LANGUAGE_NONE] = field_multiple_value_form($items['field'], $items['instance'], LANGUAGE_NONE, array(), $form, $form_state);
      // Reset theme function, as field_multiple_value_form hijacks it
      $form[$field_name][LANGUAGE_NONE]['#theme'] = $form_theme;
      $form[$field_name][LANGUAGE_NONE]['#after_build'] = $after_build;
      $form[$field_name][LANGUAGE_NONE]['#language'] = 'und';
      $form[$field_name][LANGUAGE_NONE]['#field_parents'] = Array();
    }
}

/**
 * Internal helper to set element values from the $_REQUEST variable.
 *
 * @param array &$form
 *   A form element.
 * @param mixed &$request_slice
 *   String or array. Value(s) to be applied to the element.
 */
function _emh_request_prepopulate_request_walk(&$form, &$request_slice, &$form_state, &$instance) {
  $limited_types = array(
    'actions',
    'button',
    'token',
    'value',
    'hidden',
    'image_button',
    'password',
    'password_confirm',
    'text_format',
    'markup',
    );


  if (is_array($request_slice)) {
    foreach (array_keys($request_slice) as $request_variable) {
      $next_slice =  $request_slice[$request_variable];
      $request_variable = str_replace("'","",$request_variable); //YBA : to bypass a behat bug that strips "[0]" from slice, must be replaced by ['0']
      if (element_child($request_variable) && !empty($form[$request_variable]) &&
       (!isset($form[$request_variable]['#type']) || !in_array($form[$request_variable]['#type'], $limited_types)) ) {
        if (!isset($form[$request_variable]['#access']) || $form[$request_variable]['#access'] != FALSE) {
          _emh_request_prepopulate_request_walk($form[$request_variable], $next_slice, $form_state, $instance[$request_variable]);
        }
      }
    }
    if (!empty($form['#default_value']) && is_array($form['#default_value'])) {
      $form['#default_value'] = array_merge($form['#default_value'], $request_slice);
    }
  }
  else {
    if ($form['#type'] == 'markup' || empty($form['#type'])) {
      $form['#value'] = check_plain($request_slice);
    }
    else {
      if ($form['#type'] == "select") { // try to match taxonomy terms to ease URL expression
        $terms = taxonomy_get_term_by_name($request_slice);
        if (count($terms) == 1) 
          $request_slice = (string)key($terms); 
      }
      $form['#value'] = $request_slice;
      $form['#default_value'] = $request_slice;
    }
    if ($form['#type'] == 'checkboxes' || $form['#type'] == 'checkbox') {
      $form['#checked'] = TRUE;
      $form['#default_value'] = TRUE;
      $form['#value'] = TRUE;
    }
  }
}
