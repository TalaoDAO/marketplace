<?php
/**
 * @file
 * Elements related to the adminstration of the module.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 * Adds fields for options costs in the points administation form.
 */
function emh_request_form_emh_points_admin_form_alter(&$form, &$form_state, $form_id) {
  $options = emh_request_get_options();

  $form['emh_options_costs'] = array(
    '#type' => 'fieldset',
    '#title' => t('Options costs by default'),
    '#collapsible' => true,
    '#collapsed' => false,
    '#tree' => true,
  );

  foreach ($options as $id => $option) {
    $form['emh_options_costs'][$id] = array(
      '#type' => 'textfield',
      '#title' => $option['label'],
      '#default_value' => $option['cost'],
    );
  }
}
