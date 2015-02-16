<?php

/**
 * Implements hook_admin_settings() for configuring the module.
 */
function piwik_rules_admin_settings_form($form_state) {
  $form['piwik_rules_piwiktracker'] = array(
    '#type' => 'textfield',
    '#title' => t('PiwikTracker.php location'),
    '#description' => t('The path to the PiwikTracker.php file. PiwikTracker.php is available in the /libs/PiwikTracker directory of the Piwik package, or can be downloaded direcly from !here.', array('!here' => l(t('here'), 'http://demo.piwik.org/index.php?module=SitesManager&action=downloadPiwikTracker'))),
    '#required' => TRUE,
    '#default_value' => variable_get('piwik_rules_piwiktracker','')
  );
  $form['piwik_rules_token_auth'] = array(
    '#type' => 'textfield',
    '#title' => t('Token Auth'),
    '#description' => t('Ask your piwik administrator for a token auth with administration priviledge for this site.'),
    '#required' => TRUE,
    '#default_value' => variable_get('piwik_rules_token_auth','')
  );
  return system_settings_form($form);
}
/**
 * Valdidate admin_settings_form.
 */
function piwik_rules_admin_settings_form_validate($form, &$form_state) {
  // Check if path to PiwikTracker.php exists
  if (!file_exists($form_state['values']['piwik_rules_piwiktracker'])) {
    form_set_error('piwik_rules_piwiktracker', t('PiwikTracker.php location is wrong'));
  }
}
