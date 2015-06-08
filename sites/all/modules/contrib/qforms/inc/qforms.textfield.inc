<?php


/**
 * @file
 * Qforms texfield element definition.
 */

/**
 * Returns textfield Drupal form element.
 */
function qforms_fapi_textfield($element, array $params = array()) {
  return qforms_fapi_text_element($element, $params);
}

function qforms_element_textfield($element_data) {
  $element_data['element_title'] = t('Text field');
  $element = qforms_element_default($element_data);
  qforms_element_add_size($element_data, $element);
  return $element;
}
