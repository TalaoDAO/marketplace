<?php

/*
 * @file : Pages callbacks and form builder functions for linkedin module
 */

/*
 * Callback for admin settings at admin/settings/linkedin
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function linkedin_admin($form, &$form_state) {
  //LinkedIn API credentials
  global $base_url;
  $form['linkedin'] = array(
    '#title' => t('Base settings'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['linkedin']['linkedin_liboauth_path'] = array(
    '#default_value' => variable_get('linkedin_liboauth_path', ''),
    '#title' => t('OAuth library full path (including filename)'),
    '#type' => 'textfield',
    '#description' => t('Linkedin module needs the OAuth php library from http://code.google.com/p/oauth/. You can either download OAuth.php from there and specify the full path here or install the OAuth module from http://drupal.org/project/oauth (both 6.x-2 and 6.x-3 versions are supported)'),
  );

  $form['linkedin']['consumer'] = array(
    '#description' => t('You will get theses values by requesting an API key at https://www.linkedin.com/secure/developer. <br /><em>Notice that the "integration url" you specify at Linkedin must match the base url (@url)</em>', array('@url' => $base_url)),
    '#title' => t('Consumer information'),
    '#type' => 'fieldset',
  );
  $form['linkedin']['consumer']['linkedin_consumer_key'] = array(
    '#default_value' => variable_get('linkedin_consumer_key', ''),
    '#title' => t('API key'),
    '#type' => 'textfield',
  );
  $form['linkedin']['consumer']['linkedin_consumer_secret'] = array(
    '#default_value' => variable_get('linkedin_consumer_secret', ''),
    '#title' => t('API Secret key'),
    '#type' => 'textfield',
  );
  $form['linkedin']['linkedin_debug_mode'] = array(
    '#default_value' => variable_get('linkedin_debug_mode', 0),
    '#title' => t('Turn on debug mode'),
    '#type' => 'checkbox',
  );

  //Fetch forms from submodules.
  $forms = array();
  $forms = module_invoke_all('linkedin_admin_page');
  //Tabs on user page don't always get rebuild, so manually trigger it.
  $form['#submit'][] = 'menu_rebuild';
  $form = array_merge($form, $forms);
  return system_settings_form($form);
}

/*
 * Callback for linkedin related user settings at user/%/edit/linkedin
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function linkedin_user_settings($account) {
  $output = '';
  $check = linkedin_get_profile_fields($account->uid, array('first-name', 'last-name', 'public-profile-url'), TRUE);
  if (isset($check['error-code'])) {
    $output .= t('You must first authorize LinkedIn integration to use related features.');
    $form = drupal_get_form('linkedin_user_enable_form', $account->uid);
    $output .= drupal_render($form);
  }
  else {
    $output .= t('Your account is associated with @name !public_profile.', array('@name' => $check['first-name'] . ' ' . $check['last-name'], '!public_profile' => l($check['public-profile-url'], $check['public-profile-url'])));
    $form = drupal_get_form('linkedin_user_settings_form', $account);
    $output .= drupal_render($form);
  }
  return $output;
}

/*
 * Take users to linkedin auth page
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function linkedin_user_enable_form($form, $form_state, $uid) {
  $form = array();
  $form['#user'] = $uid;
  $form['#action'] = url('linkedin/token/' . $uid);
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Go to LinkedIn'),
    '#suffix' => '<p class="description">' . t('You will be taken to the LinkedIn website in order to complete the process.') . '</p>',
  );
  return $form;
}

/*
 * form for individual user settings
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function linkedin_user_settings_form($form, &$form_state, $account) {
  // Just fetch forms from submodules.
  $form['linkedin']['elements'] = module_invoke_all('linkedin_user_settings_page', $account);
  // We will need the account at submit
  $form['#account'] = $account;

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );
  $form['linkedin']['reset'] = array(
    '#type' => 'submit',
    '#description' => t('Click here to unlink your LinkedIn account.'),
    '#value' => t('Unlink'),
  );

  return $form;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function linkedin_user_settings_form_submit($form, &$form_state) {
  $op = $form_state['values']['op'];

  if ($op == $form['linkedin']['reset']['#value']) {
    $data = array();
    foreach ($form_state['values'] as $key => $val) {
      if (substr($key, 0, 8) == 'linkedin') {
        $data[$key] = NULL;
      }
    }
    user_save($form['#account'], array('data' => $data), 'linkedin');
    db_delete('linkedin_token')
      ->condition('uid', $form['#account']->uid)
      ->execute();
    drupal_set_message(t('LinkedIn preferences have been reset'));
  }
  else {
    $data = array();
    foreach ($form_state['values'] as $key => $val) {
      if (substr($key, 0, 8) == 'linkedin') {
        $data[$key] = $val;
      }
    }
    user_save($form['#account'], array('data' => $data), 'linkedin');
    drupal_set_message(t('LinkedIn preferences have been saved'));
  }
}
