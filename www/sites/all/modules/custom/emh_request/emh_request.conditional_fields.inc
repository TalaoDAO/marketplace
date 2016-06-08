<?php
/**
 * @file
 * Code related to conditional_fields module: makes our emh_option_selector
 * field type compatible with this module.
 */


/**
 * Implements hook_conditional_fields_states_handlers_alter().
 */
function emh_request_conditional_fields_states_handlers_alter(&$handlers) {
  $handlers['emh_request_conditional_fields_states_handler'] = array(
    '#field_name' => 'field_options',
  );
}


/**
 * Conditional field states handler for emh_option_selector field type.
 * @see conditional_fields_states_handler_checkboxes()
 */
function emh_request_conditional_fields_states_handler($field, $field_info, $options, &$state) {
  $selectors = array();

  if (isset($options['value']) && !is_array($options['value'])) {
    $options['value'] = array($options['value']);
  }
  if (isset($options['values']) && !is_array($options['values'])) {
    $options['values'] = array($options['values']);
  }

  switch ($options['values_set']) {
    case CONDITIONAL_FIELDS_DEPENDENCY_VALUES_WIDGET:
      foreach ($options['value'] as $value) {
        $selectors[conditional_fields_field_selector($field[$value]['enabled'])] = array('checked' => TRUE);
      }
      break;
    case CONDITIONAL_FIELDS_DEPENDENCY_VALUES_REGEX:
      // We interpret this as: options whose identifiers match the regular
      // expression should be checked.
      $options = emh_request_get_options();
      foreach (array_keys($options) as $id) {
        if (preg_match('/' . $options['value']['RegExp'] . '/', $id)) {
          $selectors[conditional_fields_field_selector($field[$id]['enabled'])] = array('checked' => TRUE);
        }
      }
      break;
    case CONDITIONAL_FIELDS_DEPENDENCY_VALUES_AND:
      foreach ($options['values'] as $value) {
        $selectors[conditional_fields_field_selector($field[$value]['enabled'])] = array('checked' => TRUE);
      }
      break;
    case CONDITIONAL_FIELDS_DEPENDENCY_VALUES_XOR:
      $selectors[] = 'xor';
    case CONDITIONAL_FIELDS_DEPENDENCY_VALUES_OR:
    case CONDITIONAL_FIELDS_DEPENDENCY_VALUES_NOT:
      foreach ($options['values'] as $value) {
        $selectors[] = array(conditional_fields_field_selector($field[$value]['enabled']) => array('checked' => TRUE));
      }
      break;
  }

  $state = array($options['state'] => $selectors);
}
