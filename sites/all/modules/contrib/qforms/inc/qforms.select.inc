<?php

/**
 * @file
 * Qforms select element definition.
 */

module_load_include('inc', 'qforms', 'inc/qforms.options');

/**
 * Returns select Drupal form element.
 */
function qforms_fapi_select($element, array $params = array()) {
  $felement = _qforms_fapi_options_element($element, $params);
  $felement['#type'] = 'select';
  $felement['#multiple'] = $element['multiple'];

  if ($element['other']) {
    $felement['#key'] = $element['key'];
    $felement['#theme_wrappers'] = array('qforms_select', 'form_element');
  }
  return $felement;
}

function qforms_element_select($element_data) {
  $element_data['element_title'] = t('Select list');
  $element = qforms_element_default($element_data);

  $element_data['values'] = (isset($element_data['values']) ? $element_data['values'] : array(''));
  qforms_element_add_options($element, $element_data);
  $element[$element_data['id'] . '_data'] += array(
    $element_data['id'] . '_multiple' => array(
      '#type' => 'checkbox',
      '#title' => t('Allow multiple selection'),
      '#title_display' => 'before',
      '#default_value' => isset($element_data['multiple']) ? $element_data['multiple'] : FALSE,
    )
  );
  $element[$element_data['id'] . '_data'][$element_data['id'] . '_other'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add other'),
    '#title_display' => 'before',
    '#default_value' =>  isset($element_data['other']) ? $element_data['other'] : FALSE,
  );

  return $element;
}

/**
 * Single select options can have only one default checkbox checked.
 *
 * @param $element_id
 *   Form id of this radios group.
 * @param @form_state
 *   Full $form_state array.
 */
function qforms_element_select_validate($element_id, &$form_state) {
  $element_data = & $form_state['complete form']['qforms']['elements'][$element_id][$element_id . '_data'];
  
  // If select is multiple return.
  if ($element_data[$element_id . '_multiple']['#value'] == 1) {
    return;
  }

  $defaults_num = 0;
  $element_options = & $element_data[$element_id . '_options'];
  foreach ($element_options as $key => $value) {
    if (is_array($value) && isset($value[$key . '_default']) && $value[$key . '_default']['#value'] == 1) {
      ++$defaults_num;
      if ($defaults_num > 1) {
        // If we mark actual checkbox error css class will not do anything visualy
        // it will still look the same in web browser. Thats why we will mark
        // for error option_value textfield.
        form_set_error($key . '_option_value', t('Single select list can have only one default option.'));
      }
    }
  }
}

/**
 * For select element if we also have other value in $elements_data we need to
 * join other value with select value/values and unset other value.
 *
 * @param $elements_data
 *  Submission data for all elements in a qforms.
 * @param $key
 *  Key of qform element.
 * @param $value
 *  Submission value of qform element.
 */
function qforms_element_select_prepare_for_csv_export(&$elements_data, $key) {
  $other_key = $key . '_other';
  if (array_key_exists($other_key, $elements_data)) {
    // Select will have array if multiple is true.
    if (is_array($elements_data[$key])) {
      $elements_data[$key][$other_key] = $elements_data[$other_key];
    }
    else {
      $elements_data[$key] = array($key => $elements_data[$key], $other_key => $elements_data[$other_key]);
    }

    unset($elements_data[$other_key]);
  }

  $elements_data[$key] = _qforms_element_join_options($elements_data[$key]);
}
