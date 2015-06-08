<?php


/**
 * @file
 * Qforms texarea element definition.
 */

/**
 * Returns textarea Drupal form element.
 */
function qforms_fapi_textarea($element, array $params = array()) {
  $felement = qforms_fapi_text_element($element, $params);
  $felement['#type'] = 'textarea';

  // Text area is not using #size but #cols.
  unset($felement['size']);
  if (isset($element['size']) && $element['size'] != '0') {
    $felement['#cols'] = $element['size'];
  }

  return $felement;
}

function qforms_element_textarea($element_data) {
  $element_data['element_title'] = t('Paragraph field');
  $element = qforms_element_default($element_data);
  qforms_element_add_size($element_data, $element);
  return $element;
}
