<?php

/**
 * @file
 * Commons qforms functions.
 */

/**
 * Returns generic text input element.
 */
function qforms_fapi_text_element($element, $params) {
  $felement = array(
    '#title' => check_plain($element['title']),
    '#description' => check_plain($element['description']),
    '#required' => $element['required'],
  );

  if (isset($params['readonly'])) {
    $felement['#attributes']['readonly'] = 'readonly';
  }

  if (isset($params['default_value'])) {
    $felement['#default_value'] = $params['default_value']; // No need for check_plain because theme function will do this.
  }

  if (isset($element['size']) && $element['size'] != '0') {
    $felement['#size'] = $element['size'];
  }

  $felement['#type'] = 'textfield';

  return $felement;
}

/**
 * Generates default form element array.
 *
 * @param $data
 *   Array of element definition params.
 * @return
 *   Form array.
 */
function qforms_element_default($data) {
  $element = qforms_element_common($data);

  // Data elements.
  $element[$data['id'] . '_data'] += array(
    $data['id'] . '_title' => array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => isset($data['title'])? $data['title'] : '',
      '#required' => TRUE,
      '#size' => 30,
      '#attributes' => array('class' => array('qforms-element-title')),
    ),
    $data['id'] . '_description' => array(
      '#type' => 'textfield',
      '#title' => t('Description'),
      '#default_value' => isset($data['description'])? $data['description'] : '',
      '#size' => 30,
    ),
    $data['id'] . '_required' => array(
      '#type' => 'checkbox',
      '#title' => t('Required'),
      '#title_display' => 'before',
      '#default_value' => isset($data['required'])? $data['required'] : 0,
      '#weight' => 102,
    ),
  );

  return $element;
}

/**
 * Returns qform element with most common settings from $data.
 *
 * @param <type> $data
 * @return array
 */
function qforms_element_common($data) {
  $element = array(
    '#prefix' => '<div id="' . $data['id'] . '" class="qforms-element qforms-' . $data['type'] . '">',
    '#suffix' => '</div>',
    '#weight' => $data['weight'],
    '#qforms_type' => $data['type'],
  );

  $element[$data['id'] . '_header'] = array(
    '#prefix' => '<div class="qforms-element-header">',
    '#suffix' => '</div>',
  );

  $element[$data['id'] . '_header']['title'] = array(
    '#markup' => '<div class="qforms-element-title">' . $data['element_title'] .
    ': <span class="qforms-element-live-title">' . (isset($data['title'])? check_plain($data['title']) : '') . '</span></div>',
  );

  // Form element actions.
  $element[$data['id'] . '_header']['actions'] = array(
    '#prefix' => '<div class="qforms-element-actions">',
    '#suffix' => '</div>',
    $data['id'] . '_move' => array(
      '#markup' => '<a title="' . t('Move') . '" href="#" class="qforms-action qforms-action-move qforms-button"></a>',
    ),
    $data['id'] . '_close' => array(
      '#markup' => '<a title="' . t('Close') . '" href="#" class="qforms-action qforms-action-collapse qforms-form-close qforms-button"></a>',
    ),
    $data['id'] . '_delete' => array(
      '#type' => 'button',
      '#name' => $data['id'] . '_delete', // This needs to be unique so ajax post can work with multiple buttons.
      '#value' => '',
      '#ajax' => array(
        'callback' => 'qforms_delete_form_element_callback',
        'wrapper' => $data['id'],
        'effect' => 'fade',
        'method' => 'replace',
      ),
      '#limit_validation_errors' => array(), // Tell form API not to validate this form on ajax submit.
      '#attributes' => array('class' => array('qforms-action-delete', 'qforms-button'), 'title' => t('Delete element')),
    ),
  );

  // Data elements.
  $element[$data['id'] . '_data'] = array(
    '#prefix' => '<div class="qforms-element-data">',
    '#suffix' => '</div>',
    $data['id'] . '_separator' => array(
      '#markup' => '<div class="qforms-separator"></div>',
      '#weight' => 101,
    ),
    $data['id'] . '_id' => array(
      '#type' => 'value',
      '#value' => $data['id']
    ),
    $data['id'] . '_weight' => array(
      '#type' => 'textfield',
      '#title' => t('Weight'),
      '#size' => 5,
      '#default_value' => isset($data['weight'])? $data['weight'] : 1,
      '#attributes' => array('class' => array('qforms-element-weight')),
      '#weight' => 104,
    ),
    $data['id'] . '_visible' => array(
      '#type' => 'checkbox',
      '#title' => t('Visible'),
      '#title_display' => 'before',
      '#default_value' => isset($data['visible'])? $data['visible'] : 1,
      '#weight' => 103,
    ),
  );
  return $element;
}
/**
 * Appends size field to $element.
 */
function qforms_element_add_size(&$element_data, &$element) {
  $element[$element_data['id'] . '_data'][$element_data['id'] . '_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Size'),
    '#default_value' => isset($element_data['size'])? $element_data['size'] : '',
    '#size' => 5,
  );
}
