<?php
/**
 * @file
 * Declares a field type to select options during the request creation.
 */


/**
 * Implements hook_field_info().
 */
function emh_request_field_info() {
  return array(
    'emh_option_selector' => array(
      'label' => t("Options selector"),
      'description' => t("This field stores the selected request options."),
      //'settings' => array(),
      //'instance_settings' => array(),
      'default_widget' => 'emh_option_selector_default',
      'default_formatter' => 'emh_option_selector_default',
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
function emh_request_field_widget_info() {
  return array(
    'emh_option_selector_default' => array(
      'label' => t('Default'),
      'field types' => array('emh_option_selector'),
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
  $options  = emh_request_get_options();
  $items    = emh_request_restructure_option_selector_items($items);
  $weight   = 0;
  // Is the selection of options enabled?
  $enabled  = empty($form['#entity']->nid) || ($form['#entity']->status == NODE_NOT_PUBLISHED);

  if ($enabled) {
    $costs = emh_request_get_options_costs($form['#entity']);
    $total = 0;
  }

  $element += array(
    '#type' => 'fieldset',
    '#collapsible' => false,
    '#collapsed' => false,
    '#element_validate' => array('emh_request_field_widget_option_selector_validate'),
  );

  foreach ($options as $id => $option) {
    if (isset($items[$id])) {
      $item = $items[$id];
      if ($enabled) {
        $total += $costs[$id];
      }
    } else {
      $item = array('settings' => array());
    }

    $element[$id] = array(
      '#type' => 'container',
      '#weight' => $weight++,
      '#attributes' => array(
        'data-emh-option' => $id,
      ),
    );

    $element[$id]['enabled'] = array(
      '#type' => 'checkbox',
      '#title' => filter_xss($option['label']),
      '#description' => filter_xss($option['description']),
      // We can't be satisfied with the only values 0 or 1 because of
      // conditional_fields validation. We have to set the #return_value
      // property with the option identifier to make work this validation.
      '#return_value' => $id,
      '#default_value' => isset($items[$id]) ? $id : 0,
      // We have to be sure that it's the first element because of
      // conditional_fields validation. Then we set its weight to -1.
      '#weight' => -1,
    );

    // Displays the cost only if the field is enabled,
    // otherwise this information is useless.
    if ($enabled) {
      $cost = emh_request_format_cost($costs[$id]);
      $element[$id]['cost_markup'] = array(
        '#type' => 'markup',
        '#markup' => '<span class="cost">' . $cost . '</span>',
      );

      // We include the cost in the form with a hidden field,
      // but it's only for Javascript (total cost calculation).
      // Those values are ignored during the submission process.
      $element[$id]['cost'] = array(
        '#type' => 'hidden',
        '#value' => $costs[$id],
        '#tree' => false,
      );
    }

    $setting_form = module_invoke_all('emh_request_option_setting_form', $id, $option, $item['settings']);
    if ($setting_form) {
      $element[$id]['settings'] = array('#type' => 'container') + $setting_form;
    }
  }

  // Same as upper: displays the total cost only if the field is enabled,
  // otherwise this information is useless.
  if ($enabled) {
    // Includes the script to dynamically calculate and update the total cost.
    $element['#attached'] = array(
      'js' => array(drupal_get_path('module', 'emh_request') . '/js/options-costs.js'),
    );

    $element['total_markup'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="total-wrapper">'
        . '<span class="total-label">' . t("Total:") . '</span> '
        . '<span class="total">' . emh_request_format_cost($total) . '</span>'
        . '</div>',
      '#weight' => $weight++,
    );
  }

  // Adds an after build callback to the form to set up options behaviors
  $form['#after_build'][] = 'emh_request_setup_options_behaviors';

  return $element;
}


/**
 * Validation callback for the emh_option_selector_default widget.
 */
function emh_request_field_widget_option_selector_validate($element, &$form_state, $form) {
  $items = array();

  foreach (array_keys(emh_request_get_options()) as $index => $id) {
    if ($element[$id]['enabled']['#value']) {
      $items[$index] = array(
        'option'    => $id,
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
 * by emh_request_field_widget_option_selector_validate().
 * There is no longer empty items.
 * Then we just have to return false.
 */
function emh_request_field_is_empty($item, $field) {
  return false;
}


/**
 * Restructures emh_option_selector field items to make them more usable.
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
}


//----------------------------------------------------------------------
//-- STORAGE
//----------------------------------------------------------------------


/**
 * Implements hook_field_presave().
 */
function emh_request_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  if ($field['type'] == 'emh_option_selector') {
    // If the request has the skip_costs_calculation property setted to true,
    // we skip this step, assuming that items are already populated with costs
    // and that they must be saved.
    if (!empty($entity->skip_costs_calculation)) {
      return;
    }

    if (empty($entity->nid) || $entity->original->status == NODE_NOT_PUBLISHED) {
      $costs = emh_request_get_options_costs($entity);

      foreach ($items as $delta => $item) {
        if (isset($costs[$item['option']])) {
          $items[$delta]['cost'] = $costs[$item['option']];
        }
      }
    }
    else {
      // Adds a "flag" to the request to avoid options update.
      // See emh_request_field_storage_pre_update().
      $entity->skip_options_update = true;
    }
  }
}


/**
 * Implements hook_field_storage_pre_update().
 *
 * Prevents to update options data if it's specified by the skip_options_update
 * property of the request.
 */
function emh_request_field_storage_pre_update($entity_type, $entity, &$skip_fields) {
  if (
    $entity_type == 'node' &&
    $entity->type == 'request' &&
    !empty($entity->skip_options_update)
  ) {
    $field = field_info_field('field_options');
    $skip_fields[$field['id']] = true;
  }
}
