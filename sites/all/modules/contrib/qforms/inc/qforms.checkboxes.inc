<?php

/**
 * @file
 * Qforms radios group element definition.
 */

module_load_include('inc', 'qforms', 'inc/qforms.options');

/**
 * Returns checkboxes Drupal form element.
 */
function qforms_fapi_checkboxes($element, array $params = array()) {
  $felement = _qforms_fapi_options_element($element, $params);
  $felement['#type'] = 'checkboxes';

  return $felement;
}

function qforms_element_checkboxes($element_data) {
  $element_data['element_title'] = t('Checkbox group');
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

function qforms_element_checkboxes_prepare_for_csv_export(&$elements_data, $key) {
  $elements_data[$key] = _qforms_element_join_options($elements_data[$key]);
}
