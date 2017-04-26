<?php

/**
 * @file
 * Admin pages for the Mixpanel module.
 */

/**
 * Form constructor for the admin settings form.
 *
 * @ingroup forms
 */
function mixpanel_admin_settings($form, &$form_state) {
  $form['mixpanel_token'] = array(
    '#title' => t('Mixpanel Token'),
    '#type' => 'textfield',
    '#default_value' => variable_get('mixpanel_token', ''),
    '#description' => t('The token you got from mixpanel.com for this domain.'),
  );

  $form['mixpanel_library_version'] = array(
    '#title' => t('Mixpanel Javascript library version'),
    '#type' => 'radios',
    '#options' => array(
      '1.0' => t("1.0 - <em>Don't use unless you have legacy code which depends on 1.0!</em>"),
      '2.0' => '2.0',
    ),
    '#default_value' => variable_get('mixpanel_library_version', '2.0'),
    '#description' => t('In April 2012, Mixpanel updated their Javascript library to version 2.0. It adds several new features but unfortunately has a completely new API. Unless you have legacy code which depends on 1.0, you should be using 2.0!'),
  );

  $form['mixpanel_queue'] = array(
    '#title' => t('Queue and send events during cron'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('mixpanel_queue', TRUE),
    '#description' => t('Enabling this will increase site performance but delay sending data to Mixpanel until cron is run.'),
  );

  $form['mixpanel_cross_subdomain_cookie'] = array(
    '#title' => t('Set Mixpanel cookie across all subdomains'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('mixpanel_cross_subdomain_cookie', TRUE),
    '#description' => t('Enabling this use the same Mixpanel cookie for <em>site1</em>.example.com and <em>site2</em>.example.com. <strong>Only works with version 2.0 of the Javascript library!</strong>'),
  );

  $form['mixpanel_track_anonymous'] = array(
    '#title' => t('Track anonymous users'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('mixpanel_track_anonymous', TRUE),
  );

  return system_settings_form($form);
}
