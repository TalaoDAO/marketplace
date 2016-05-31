<?php
/**
 * @file
 * Declares new field types to manage request options.
 */


/**
 * Implements hook_field_info().
 */
function emh_request_field_info() {
  return array(
    'option_selector' => array(
      'label' => t("Options selector"),
      'description' => t("This field stores the selected request options."),
      //'settings' => array(),
      //'instance_settings' => array(),
      'default_widget' => 'option_selector_default',
      'default_formatter' => 'option_selector_default',
    ),
//    'option_cost_editor' => array(
//      'label' => t("Options costs editor"),
//      'description' => t("This field stores the options costs overwriting ones by default."),
//      //'settings' => array(),
//      //'instance_settings' => array(),
//      'default_widget' => 'option_cost_editor_default',
//      'default_formatter' => 'option_cost_editor_default',
//    ),
  );
}


//----------------------------------------------------------------------
//-- WIDGETS
//----------------------------------------------------------------------


/**
 * Implements hook_field_widget_info().
 */
function emh_request_field_widget_info() {
  return array(
    'option_selector_default' => array(
      'label' => t('Default'),
      'field types' => array('option_selector'),
      //'settings' => array(),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM,
        'default value' => FIELD_BEHAVIOR_DEFAULT,
      ),
    ),
  );
}


/**
 * Implements hook_field_widget_form().
 */
function emh_request_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $options = emh_request_get_options();
  uasort($options, 'drual_sort_weight');

  $weight = 0;
  $items = emh_request_option_storage_to_form($items);

  $element += array(
    '#type' => 'fieldset',
    '#title' => t('Choice of options'),
    '#title_display' => 'invisible',
    '#collapsible' => false,
    '#collapsed' => false,
    '#element_validate' => array('emh_request_field_widget_validate'),
  );

  foreach ($options as $id => $option) {
    $element[$id] = array(
      '#type' => 'container',
      '#weight' => $weight++,
    );

    $element[$id]['enabled'] = array(
      '#type' => 'checkbox',
      '#title' => filter_xss($option['label']),
      '#description' => filter_xss($option['description']),
    );

    $setting_form = module_invoke_all('emh_request_option_setting_form', $id, $option, $items[$id]['settings']);
    if ($setting_form) {
      $element[$id]['settings'] = array(
        '#type' => 'container',
        '#states' => array(),
      ) + $setting_form;
    }
  }

  return array('value' => $element);
}


/**
 * Storage to form.
 */
function emh_request_option_storage_to_form($items) {
  $options = array();

  foreach ($items as $delta => $columns) {
    if (!empty($columns['settings'])) {
      $columns['settings'] = unserialize($columns['settings']);
    }
    $options[$columns['option']] = $columns;
  }

  return $options;
}


/**
 * Form to storage.
 */
function emh_request_option_form_to_storage($values) {

}


//----------------------------------------------------------------------
//-- FORMATTERS
//----------------------------------------------------------------------