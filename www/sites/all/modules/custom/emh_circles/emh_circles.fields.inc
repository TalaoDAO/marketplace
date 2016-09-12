<?php
/**
 * @file
 * Defines a field type for the overwriting of requests options costs.
 */


/**
 * Implements hook_field_info().
 */
function emh_circles_field_info() {
  return array(
    'emh_option_cost_modifier' => array(
      'label' => t("Options costs modifier"),
      'description' => t("This field stores the options costs overwriting ones by default."),
      //'settings' => array(),
      //'instance_settings' => array(),
      'default_widget' => 'emh_option_cost_modifier_default',
      'default_formatter' => 'emh_option_cost_modifier_default',
      'no_ui' => true,
    ),
  );
}


//----------------------------------------------------------------------
//-- WIDGETS
//----------------------------------------------------------------------


/**
 * Implements hook_field_widget_info().
 */
function emh_circles_field_widget_info() {
  return array(
    'emh_option_cost_modifier_default' => array(
      'label' => t('Default'),
      'field types' => array('emh_option_cost_modifier'),
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
function emh_circles_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  if (!module_exists('emh_request')) {
    return array();
  }

  $options = emh_request_get_options();
  $items = emh_circles_restructure_option_cost_modifier_items($items);

  $element += array(
    '#type' => 'fieldset',
    '#collapsible' => false,
    '#collapsed' => false,
    '#element_validate' => array('emh_circles_field_widget_option_cost_modifier_validate'),
  );

  foreach ($options as $id => $option) {
    $default_cost = ($option['cost'] === 0)
      ? t("Cost by default: free")
      : t("Cost by default: !amount credits", array('!amount' => $option['cost']));

    $element[$id] = array(
      '#type' => 'textfield',
      '#title' => filter_xss($option['label']),
      '#description' => $default_cost, // filter_xss($option['description']),
      '#default_value' => isset($items[$id]) ? $items[$id] : '',
    );
  }

  return $element;
}


/**
 * Validation callback for the emh_option_cost_modifier_default widget.
 */
function emh_circles_field_widget_option_cost_modifier_validate($element, &$form_state, $form) {
  $items = array();

  foreach (element_children($element, true) as $index => $id) {
    $cost = trim($element[$id]['#value']);

    if (strlen($cost) > 0) {
      if (ctype_digit($cost)) {
        $items[$index] = array('option' => $id, 'cost' => (int) $cost);
      } else {
        form_error($element[$id], t("Costs of options must be integers."));
      }
    }
  }

  form_set_value($element, $items, $form_state);
}


/**
 * Implements hook_field_is_empty().
 *
 * At this point, items have already been processed
 * by emh_circles_field_widget_option_cost_modifier_validate().
 * There is no longer empty items.
 * Then we just have to return false.
 */
function emh_circles_field_is_empty($item, $field) {
  return false;
}


/**
 * Restructures emh_option_cost_modifier field items to make them more usable.
 */
function emh_circles_restructure_option_cost_modifier_items($items) {
  $restructured = array();

  foreach ($items as $delta => $columns) {
    $restructured[$columns['option']] = $columns['cost'];
  }

  return $restructured;
}
