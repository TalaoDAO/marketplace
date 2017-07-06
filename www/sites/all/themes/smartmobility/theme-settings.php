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

  $settings_theme = $form_state['build_info']['args'][0];

  // Customers and Experts tutorial videos.
  $form['videos']['customers'] = array(
    '#type'          => 'text',
    '#title'         => t('URL of the Customers video'),
    '#default_value' => theme_get_setting('smartmobility_videos_customers'),
  );
  $form['videos']['experts'] = array(
    '#type'          => 'text',
    '#title'         => t('URL of the Experts video'),
    '#default_value' => theme_get_setting('smartmobility_videos_experts'),
  );

}
