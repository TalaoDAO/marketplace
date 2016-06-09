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
<<<<<<< HEAD
    'emh_option_selector' => array(
=======
    'option_selector' => array(
>>>>>>> ADD: beginning of the development for the options selector field (draft)
      'label' => t("Options selector"),
      'description' => t("This field stores the selected request options."),
      //'settings' => array(),
      //'instance_settings' => array(),
<<<<<<< HEAD
      'default_widget' => 'emh_option_selector_default',
      'default_formatter' => 'emh_option_selector_default',
      'no_ui' => true,
    ),
//    'emh_option_cost_editor' => array(
=======
      'default_widget' => 'option_selector_default',
      'default_formatter' => 'option_selector_default',
    ),
//    'option_cost_editor' => array(
>>>>>>> ADD: beginning of the development for the options selector field (draft)
//      'label' => t("Options costs editor"),
//      'description' => t("This field stores the options costs overwriting ones by default."),
//      //'settings' => array(),
//      //'instance_settings' => array(),
<<<<<<< HEAD
//      'default_widget' => 'emh_option_cost_editor_default',
//      'default_formatter' => 'emh_option_cost_editor_default',
//      'no_ui' => true,
=======
//      'default_widget' => 'option_cost_editor_default',
//      'default_formatter' => 'option_cost_editor_default',
>>>>>>> ADD: beginning of the development for the options selector field (draft)
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
<<<<<<< HEAD
    'emh_option_selector_default' => array(
      'label' => t('Default'),
      'field types' => array('emh_option_selector'),
=======
    'option_selector_default' => array(
      'label' => t('Default'),
      'field types' => array('option_selector'),
>>>>>>> ADD: beginning of the development for the options selector field (draft)
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
<<<<<<< HEAD
  uasort($options, 'drupal_sort_weight');

  $weight = 0;
  $items = emh_request_restructure_option_selector_items($items);

  $element += array(
    '#type' => 'fieldset',
=======
  uasort($options, 'drual_sort_weight');

  $weight = 0;
  $items = emh_request_option_storage_to_form($items);

  $element += array(
    '#type' => 'fieldset',
    '#title' => t('Choice of options'),
    '#title_display' => 'invisible',
>>>>>>> ADD: beginning of the development for the options selector field (draft)
    '#collapsible' => false,
    '#collapsed' => false,
    '#element_validate' => array('emh_request_field_widget_validate'),
  );

  foreach ($options as $id => $option) {
<<<<<<< HEAD
    $item = isset($items[$id]) ? $items[$id] : array('settings' => array());

=======
>>>>>>> ADD: beginning of the development for the options selector field (draft)
    $element[$id] = array(
      '#type' => 'container',
      '#weight' => $weight++,
    );

    $element[$id]['enabled'] = array(
      '#type' => 'checkbox',
      '#title' => filter_xss($option['label']),
      '#description' => filter_xss($option['description']),
<<<<<<< HEAD
      '#default_value' => isset($items[$id]),
    );

    $cost = isset($item['cost']) ? $item['cost'] : $option['cost'];
    if ($cost == 0) {
      $cost = t('Free');
    } else {
      $cost = t('!count points', array('!count' => $cost));
    }

    $element[$id]['cost'] = array(
      '#type' => 'markup',
      '#markup' => '<span class="cost">' . $cost . '</span>',
    );

    $setting_form = module_invoke_all('emh_request_option_setting_form', $id, $option, $item['settings']);
    if ($setting_form) {
      $element[$id]['settings'] = array(
        '#type' => 'container',
//        '#states' => array(
//          'visible' => array(
//            '' => array('checked' => true),
//          )
//        ),
=======
    );

    $setting_form = module_invoke_all('emh_request_option_setting_form', $id, $option, $items[$id]['settings']);
    if ($setting_form) {
      $element[$id]['settings'] = array(
        '#type' => 'container',
        '#states' => array(),
>>>>>>> ADD: beginning of the development for the options selector field (draft)
      ) + $setting_form;
    }
  }

<<<<<<< HEAD
  // Adds an after build callback to the form to set up options behaviors
  $form['#after_build'][] = 'emh_request_setup_options_behaviors';

  return $element;
=======
  return array('value' => $element);
>>>>>>> ADD: beginning of the development for the options selector field (draft)
}


/**
<<<<<<< HEAD
 * Validation callback for the options field.
 */
function emh_request_field_widget_validate($element, &$form_state, $form) {
  $items = array();

  foreach (element_children($element, true) as $index => $id) {
    if ($element[$id]['enabled']['#value']) {
      $items[$index] = array(
        'option'    => $id,
        'cost'      => 0,
        'settings'  => null,
      );

      if (isset($element[$id]['settings'])) {
        $settings = drupal_array_get_nested_value($form_state['values'], $element[$id]['settings']['#parents']);
        if (!empty($settings)) {
          $items[$index]['settings'] = serialize($settings);
        }
      }
    }
  }

  form_set_value($element, $items, $form_state);
}


/**
 * Implements hook_field_is_empty().
 *
 * At this point, items have already been processed
 * by emh_request_field_widget_validate().
 * There is no longer empty items.
 * Then we just have to return false.
 */
function emh_request_field_is_empty($item, $field) {
  return false;
=======
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
>>>>>>> ADD: beginning of the development for the options selector field (draft)
}


/**
<<<<<<< HEAD
 * Restructures option_selector field items to make them more usable.
 */
function emh_request_restructure_option_selector_items($items) {
  $restructured = array();

  foreach ($items as $delta => $columns) {
    if (!empty($columns['settings'])) {
      $columns['settings'] = unserialize($columns['settings']);
    } else {
      $columns['settings'] = array();
}
    $restructured[$columns['option']] = $columns;
  }

  return $restructured;
=======
 * Form to storage.
 */
function emh_request_option_form_to_storage($values) {

>>>>>>> ADD: beginning of the development for the options selector field (draft)
}


//----------------------------------------------------------------------
//-- FORMATTERS
<<<<<<< HEAD
//----------------------------------------------------------------------
=======
//----------------------------------------------------------------------
>>>>>>> ADD: beginning of the development for the options selector field (draft)
