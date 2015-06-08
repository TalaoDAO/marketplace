<?php

/**
 * @file
 * Common functions for options elements like radios, chechboxes and select.
 */

/**
 * Returns generic options input element.
 */
function _qforms_fapi_options_element($element, $params, $radios = FALSE) {
  $options = array(
    '#title' => check_plain($element['title']),
    '#description' => check_plain($element['description']),
    '#required' => $element['required'] == 'true' ? TRUE : FALSE,
  );

  foreach ($element as $key => $value) {
    if (strpos($key, '_option_value')) {
      $form_value = check_plain($value);
      $options['#options'][$form_value] = $form_value;

      // Lets find default_value key.
      $default_key = str_replace('_option_value', '_default', $key);

      if (isset($params['default_value'])) { // We have stored default values.
        // Find correct value.
        if (is_array($params['default_value'])) { // multiselect and checkboxes
          $default_values = current($params['default_value']);
          next($params['default_value']);
        }
        else { // radios and single select
          $default_values = $params['default_value'];
        }

        if ($radios) {
          $options['#default_value'] = check_plain($default_values);
        }
        else {
          $options['#default_value'][] = check_plain($default_values);
        }
      }
      elseif ($element[$default_key] == TRUE) { // Take default values from form definition.
        if ($radios) {
          $options['#default_value'] = $form_value;
        }
        else {
          $options['#default_value'][] = $form_value;
        }
      }
    }

    if (isset($params['readonly'])) {
      $options['#attributes']['readonly'] = 'readonly';
    }

  }

  if ($element['other']) {
    $options['#after_build'][] = 'qforms_fapi_options_after_build';
    $options[$element['key'] . '_other'] = array(
      '#type' => 'textfield',
      '#title' => t('Other'),
      '#size' => 60,
      '#maxlength' => 128,
      '#weight' => 100,
      '#required' => FALSE,
      '#default_value' => isset($params['default_value_other']) ? $params['default_value_other'] :
        (isset($params['default_value'][($element['key'] . '_other')]) ? $params['default_value'][($element['key'] . '_other')] : ''),
    );
  }

  return $options;
}

/**
 * Value from other textfield must be unset since its value isn't an option in
 * parent element.
 */
function qforms_fapi_options_after_build($form_element, &$form_state) {
  // If we are in form submit we need to tweek submited values for options.
  if (isset($form_state['submitted'])) {
    if (is_array($form_element['#value'])) {
      $other_value = key(array_diff($form_element['#value'], $form_element['#options']));
      if (is_array($form_element['#value']) && isset($form_element['#value'][$other_value])) {
        unset($form_element['#value'][$other_value]);

        // For some reason we are also getting other textfield value in
        // $form_state['values'] like
        // $form_state['values'][element][other_value] = other_value
        // or if other value is not set like empty string. Not
        // exactly sure why (maybe investigate this more later) but this will
        // be serialized for submission results and also can create problem
        // for CSV export, so we need to remove it.
        $other_key = $form_element['#parents'][0];
        if (isset($form_state['values'][$other_key][0]) && empty($form_state['values'][$other_key][0])) {
          // This is a case when other value is empty - user didn't enter data.
          unset($form_state['values'][$other_key][0]);
        }
        elseif (isset($form_state['values'][$other_key][$other_value])) {
          unset($form_state['values'][$other_key][$other_value]);
        }
      }
    }
  }

  return $form_element;
}

/**
 * Prepare element with options for saving. We will remove all buttons values
 * from element.
 */
function qforms_element_options_prepare_for_saving(&$element) {
  // Remove delete option buttons values.
  foreach ($element as $key => $value) {
    if (strpos($key, '_delete_option') !== FALSE) {
      unset($element[$key]);
    }
  }

  // Remove add option button value.
  unset($element['options_add_option']);
}

function qforms_element_add_options(&$element, $element_data) {
  $options = array(
    '#prefix' => '<div class="qforms-element-options form-item"><label>' . t('Select options') . '</label>',
    '#suffix' => '</div>',
    '#qforms_last_option_id' => (isset($element_data['last_option_id'])) ? $element_data['last_option_id'] : 0,
  );

  // If we are creating a new options element then we need to add one empty option.
  if (!isset($element_data['other'])) {
    $element_data['options_0_option_value'] = NULL;
  }

  foreach ($element_data as $key => $value) {
    if (strpos($key, '_option_value')) {

      // Lets check is this option checked to be default.
      $default_key = str_replace('_option_value', '_default', $key);
      $checked = isset($element_data[$default_key])? $element_data[$default_key] : FALSE;

      // Since option is retrieved from DB we need number id of that option.
      // For example from something_2_option_value we need 2.
      $option_id = substr($key, strpos($key, '_') + 1, 1);
      if ($option_id == 0) {
        $option_id = 1;
      }
      qforms_element_add_option($element_data['id'], $options, $option_id, $value, $checked);
    }
  }

  $options[$element_data['id'] . '_options_add_option'] = array(
    '#type' => 'button',
    '#name' => $element_data['id'] . '_add_option', // This needs to be unique so ajax post can work with multiple buttons.
    '#value' => '',
    '#ajax' => array(
      'callback' => 'qforms_add_form_element_option_callback',
      'wrapper' => str_replace('_', '-', 'edit_' . $element_data['id'] . '_options_add_option'),
      'effect' => 'fade',
      'method' => 'before',
      'qforms_callback' => 'qforms_add_form_element_option',
      'qforms_include' => drupal_get_path('module', 'qforms') . '/inc/qforms.options.inc',
      'qforms_parent' => $element_data['id'], // We need this reference to parent qforms element.
    ),
    '#limit_validation_errors' => array(), // Tell form API not to validate form.
    '#weight' => 10000, // Set a heavy weight so during ajax adding new options will always be before add_option button.
    '#attributes' => array('class' => array('qforms-button', 'qforms-action-add-option'), 'title' => t('Add option')),
  );

  $element[$element_data['id'] . '_data'][$element_data['id'] . '_options'] = $options;
}

function qforms_element_add_option($parent_id, &$options, $option_id = NULL, $value = NULL, $checked = FALSE) {
  if (isset($option_id)) {
    // Since option is retrieved from DB lets use its stored id.
    $options['#qforms_last_option_id'] = $option_id;
  }
  else {
    // When user hit "Add option".
    ++$options['#qforms_last_option_id'];
  }

  $okey = $parent_id . '_options' . '_' . $options['#qforms_last_option_id'];
  $option_value = isset($value) ? check_plain($value) : t('Option !num', array('!num' => $options['#qforms_last_option_id']));

  $options[$okey] = array(
    '#prefix' => '<div id="' . $okey . '" class="qforms-element-option ' . $okey . '">',
    '#suffix' => '</div>',
    $okey . '_default' => array(
      '#type' => 'checkbox',
      '#default_value' => $checked? 1 : 0,
    ),
    $okey . '_id' => array(
      '#type' => 'value',
      '#value' => $options['#qforms_last_option_id'],
    ),
    $okey . '_option_value' => array(
      '#title' => $option_value,
      '#title_display' => 'invisible',
      '#type' => 'textfield',
      '#size' => '20',
      '#default_value' => $option_value,
      '#required' => TRUE,
    ),
    $okey . '_delete_option' => array(
      '#type' => 'button',
      '#name' => $okey . '_delete_option', // This needs to be unique so ajax post can work with multiple buttons.
      '#value' => '',
      '#ajax' => array(
        'callback' => 'qforms_delete_form_element_option_callback',
        'qforms_callback' => 'qforms_delete_form_element_option',
        'wrapper' => $okey, // Wrapper needs to point to element html id.
        'effect' => 'fade',
        'method' => 'replace',
        'qforms_include' => drupal_get_path('module', 'qforms') . '/inc/qforms.options.inc',
        'qforms_parent' => $parent_id, // We need this reference to parent qforms element.
      ),
      '#limit_validation_errors' => array(), // Tell form API not to validate form.
      '#attributes' => array('class' => array('qforms-button', 'qforms-action-delete-option'), 'title' => t('Delete option')),
    ),
  );

  return $options[$okey];
}

/********************/
/** Ajax callbacks **/
/********************/

/**
 * Helper for adding a new form element option.
 */
function qforms_add_form_element_option($parent_id, &$element, $form_state) {
  $options = & $element[$parent_id . '_data'][$parent_id . '_options'];
  qforms_element_add_option($parent_id, $options);
}

/**
 * Ajax callback for adding a new form element option.
 * We need to return last added option in options section.
 */
function qforms_add_form_element_option_callback($form, $form_state) {
  $parent = $form_state['triggering_element']['#ajax']['qforms_parent'];
  $count = $form['qforms']['elements'][$parent][$parent . '_data'][$parent . '_options']['#qforms_last_option_id'];
  return $form['qforms']['elements'][$parent][$parent . '_data'][$parent . '_options'][$parent . '_options_' . $count];
}

/**
 * Helper for deleting form element option.
 */
function qforms_delete_form_element_option($parent_id, &$element, &$form_state) {
  $parent = $form_state['triggering_element']['#ajax']['qforms_parent'];
  $target = $form_state['triggering_element']['#ajax']['wrapper'];
  unset($element[$parent . '_data'][$parent . '_options'][$target]);
}

/**
 * Ajax callback for adding a new form element option.
 */
function qforms_delete_form_element_option_callback($form, $form_state) {
  return '';
}

/*************/
/** Helpers **/
/*************/

/**
 * If options is an array then join it to comma separated string.
 */
function _qforms_element_join_options($options) {
  // Convert array of data to comma separated string.
  if (is_array($options)) {
    $option_values = array();
    foreach ($options as $value) {
      if (!empty($value)) {
        // Note that we are not escaping user submission data here, which
        // I guess is OK? @TODO - check this later.
        $option_values[] = $value;
      }
    }
    return implode(', ', $option_values);
  }

  return $options;
}
