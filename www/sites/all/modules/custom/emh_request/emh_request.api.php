<?php
/**
 * @file
 * Documents hooks invoked by the module.
 * Do not invoke them directly!
 */


/**
 * Informs EMH request system about available options.
 *
 * Must return an array with options identifiers as keys and arrays of
 * option properties as values.
 * Available option properties:
 *  - label (required): a user-friendly label ;
 *  - description: a short explanation about the option ;
 *  - cost: an initial and default cost, 0 (then free) if not provided.
 *    Notice: if another amount is defined in the emh_options_costs variable for
 *    the current option, il will overwrite the initial cost ;
 *  - weight: a weight for options ordering, 0 if not provided ;
 *  - setting_form: a form callback to generate a setting form ;
 *  - fields: an array of field names related to the option (on which the
 *    behavior is applied) ;
 *  - behavior: an array of properties defining the behavior to have with the
 *    specified fields in function of the option state (checked or not).
 *    The behavior by default is to hide the fields and show them only when the
 *    option is checked (with a slide effect).
 *
 * @see conditional_fields_attach_dependency()
 *  Read the documentation of the $options argument to know the available
 *  properties for the options behaviors.
 *
 * @return array
 */
function hook_emh_request_option_info() {
  return array(
    'super_option' => array(
      'label' => t('My super option'),
      'description' => t('This is an option which one I can make lots of super things!'),
      'cost' => 200,    // 0 by default
      'weight' => 100,  // 0 by default
      'setting_form' => 'my_module_super_option_setting_form',
      'fields' => ['field_super_option1', 'field_super_option2'],
      'behavior' => array(
        'state' => '!visible',
        'effect' => 'fade',
      ),
    ),
  );
}


/**
 * Allows third-party modules to alter options data retrieved by
 * hook_emh_request_option_info().
 *
 * @param array $options
 */
function hook_emh_request_option_info_alter(array &$options) {
  $options['super_option']['weight'] = 300;
}


/**
 * Allows to declare form elements for the configuration of the given option.
 * They will be merged to the field widget form.
 *
 * @param string $id Option ID (machine name)
 * @param array $properties Option properties
 * @param array $settings Current settings
 * @return array
 */
function hook_emh_request_option_setting_form($id, $properties, array $settings = array()) {
  if ($id == 'super_option') {
    return array(
      'super_setting' => array(
        '#type' => 'textfield',
        '#title' => t('A super setting'),
        '#default_value' => isset($settings['super_setting']) ? $settings['super_setting'] : '',
      ),
    );
  }
}


/**
 * Allows to alter costs of options for the context of a specific request.
 *
 * @param array $costs
 *  Costs of the selected options keyed by option identifier
 * @param stdClass $request
 *  The request node being saved
 */
function hook_emh_request_options_costs_alter(&$costs, $request) {
  if (variable_get('discount_period', false)) {
    $costs['super_option'] -= 200;
  }
}