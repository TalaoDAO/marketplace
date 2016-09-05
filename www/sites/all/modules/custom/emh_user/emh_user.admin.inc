<?php
/**
 * @file
 * Elements related to the administration of the module.
 */


/**
 * Implements hook_form_FORM_ID_alter().
 * Adds field for the cost of profile purchase in the credits administration form.
 */
function emh_user_form_emh_points_admin_form_alter(&$form, &$form_state, $form_id) {
  $form['emh_user_profile_purchase_amount'] = array(
    '#type' => 'textfield',
    '#title' => t("Cost of profile purchase"),
    '#default_value' => variable_get('emh_user_profile_purchase_amount', 50),
    '#element_validate' => array('element_validate_integer_positive'),
    '#weight' => 100,
  );
}
