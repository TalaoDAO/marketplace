<?php

/**
 * @file
 * Alters the Smart Mobility theme settings form.
 */

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function smartmobility_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL) {

  // Work-around for a core bug affecting admin themes. See issue #943212.
  if (isset($form_id)) {
    return;
  }

  //$settings_theme = $form_state['build_info']['args'][0];

  $form['sm'] = array(
    '#type' => 'fieldset',
    '#title' => t('Smart Mobility settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#weight' => -50,
  );

  // Customers and Experts tutorial videos.
  $form['sm']['video_customers'] = array(
    '#type' => 'textfield',
    '#title' => t('URL of the Customers video'),
    '#default_value' => theme_get_setting('video_customers'),
    '#description' => t('Specify pages by using their paths. Enter one path per line.'),
  );
  $form['sm']['video_experts'] = array(
    '#type' => 'textfield',
    '#title' => t('URL of the Experts video'),
    '#default_value' => theme_get_setting('video_experts'),
    '#description' => t('Specify pages by using their paths. Enter one path per line.'),
  );
}
