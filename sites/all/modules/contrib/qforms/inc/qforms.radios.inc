<?php

/**
 * @file
 * Qforms radios group element definition.
 */

module_load_include('inc', 'qforms', 'inc/qforms.options');

/**
 * Returns Drupal radios form element.
 */
function qforms_fapi_radios($element, array $params = array()) {
  $felement = _qforms_fapi_options_element($element, $params, TRUE);
  $felement['#type'] = 'radios';

  return $felement;
}

function qforms_element_radios($element_data) {
  $element_data['element_title'] = t('Radio group');
  $element = qforms_element_default($element_data);

  $element_data['values'] = (isset($element_data['values']) ? $element_data['values'] : array(''));
  qforms_element_add_options($element, $element_data);

  $element[$element_data['id'] . '_data'][$element_data['id'] . '_other'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add other'),
    '#title_display' => 'before',
    '#default_value' => isset($element_data['other']) ? $element_data['other'] : FALSE,
  );

  return $element;
}

/**
 * Radios options can have only one default checkbox checked
 *
 * @param $element_id
 *   Form id of this radios group.
 * @param @form_state
 *   Full $form_state array.
 */
function qforms_element_radios_validate($element_id, &$form_state) {
  $defaults_num = 0;
  $element_options = $form_state['complete form']['qforms']['elements'][$element_id][$element_id . '_data'][$element_id . '_options'];
  foreach ($element_options as $key => $value) {
    if (is_array($value) && isset($value[$key . '_default']) && $value[$key . '_default']['#value'] == 1) {
      ++$defaults_num;
      if ($defaults_num > 1) {
        // If we mark actual checkbox error css class will not do anything
        // visualy it will still look the same in web browser. Thats why we
        // will mark for error option_value textfield.
        form_set_error($key . '_option_value', t('Radios group can have only one default option.'));
      }
    }
  }
}

/**
 * For radios if we also have other value in $elements_data we need to join
 * other value with radios value and unset other value.
 *
 * @param $elements_data
 *  Submission data for all elements in a qforms.
 * @param $key
 *  Key of qform element.
 */
function qforms_element_radios_prepare_for_csv_export(&$elements_data, $key) {
  $other_key = $key . '_other';
  if (array_key_exists($other_key, $elements_data)) {
    $elements_data[$key] = array($key => $elements_data[$key], $other_key => $elements_data[$other_key]);
    unset($elements_data[$other_key]);
  }

  $elements_data[$key] = _qforms_element_join_options($elements_data[$key]);
}
