<?php
/**
 * @file
 * Elements related to the administration of the module.
 */


/**
 * Implements hook_form_FORM_ID_alter().
 * Adds fields for options costs in the points administration form.
 */
function emh_request_form_emh_points_admin_form_alter(&$form, &$form_state, $form_id) {
  $options = emh_request_get_options();

  $form['emh_options_costs'] = array(
    '#type' => 'fieldset',
    '#title' => t('Options costs by default'),
    '#description' => t('Leave a field empty to restablish the initial cost.'),
    '#collapsible' => true,
    '#collapsed' => false,
    '#weight' => 500,
    '#tree' => true,
  );

  foreach ($options as $id => $option) {
    $form['emh_options_costs'][$id] = array(
      '#type' => 'textfield',
      '#title' => $option['label'],
      '#default_value' => $option['cost'],
    );
  }

  $form['#validate'][] = 'emh_request_form_emh_points_admin_form_validate';
}


/**
 * Validation callback for the points administration form.
 */
function emh_request_form_emh_points_admin_form_validate($form, &$form_state) {
  foreach ($form_state['values']['emh_options_costs'] as $id => $cost) {
    $cost = trim($cost);

    if (strlen($cost) > 0) {
      if (!ctype_digit($cost)) {
        form_error($form['emh_options_costs'][$id], t("The option's cost must be a positive integer."));
      }
    }
    else {
      unset($form_state['values']['emh_options_costs'][$id]);
    }
  }
}
