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
 *  - cost: a cost by default, 0 (then free) if not provided ;
 *  - weight: a weight for options ordering on the interface, 0 if not provided ;
 *  - setting_form: a form callback to generate a setting form ;
 *  - fields: an array of field names related to the option ;
 *  - behavior: the behavior to add with the given fields, "show" or "hide".
 *
 * @return array
 */
function hook_emh_request_option_info() {
  return array(
    'super_option' => array(
      'label' => t('My super option'),
      'description' => t('This is an option which one I can make lots of super things!'),
      'cost' => 200,        // 0 by default
      'weight' => 100,      // 0 by default
      'setting_form' => 'my_module_super_option_setting_form',
      'fields' => ['field_super_option1', 'field_super_option2'],
      'behavior' => 'show', // "show" by default
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
