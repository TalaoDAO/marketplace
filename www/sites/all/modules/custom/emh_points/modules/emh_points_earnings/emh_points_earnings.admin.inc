<?php

/**
 * @file
 * Administration screens for EMH Earnings management module.
 */

/**
 * Admin form for EMH Earnings management settings.
 */
function emh_points_earnings_admin_form() {
  $form = array();

  $form['emh_points_earnings_commissions'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#title' => t('eMindHub commissions before monetization of Credits to Earnings'),
    '#description' => t('Expressed as float values. Example : 0.7 => When a user gets 100 Credits in a transaction context that has a commission rate applied, then EMH gets 100 * 0.7 = 70 Credits, and the user keeps 100 * (1 - 0.7) = 30 Credits, which are immediatly monetized in 30 Earnings.'),
  );

  // Get the commission rates.
  $commission_rates = unserialize(
    variable_get('emh_points_earnings_commissions')
  );

  // Input field for each context.
  foreach (EMH_POINTS_EARNINGS_CONTEXTS as $context) {

    $form['emh_points_earnings_commission'][$context] = array(
      '#type' => 'textfield',
      '#title' => t('Context: %i', array('%i' => $i)),
      '#default_value' => isset($commission_rates[$context]) ? $commission_rates[$context] : EMH_POINTS_EARNINGS_COMMISSION,
    );
  }

  return system_settings_form($form);
}
