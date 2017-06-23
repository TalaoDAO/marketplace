<?php

/*
 * @file Pages callbacks and form builder functions for Linkedin Profile module.
 */

/**
 * Callback for admin settings at admin/settings/linkedin
 */
function emh_linkedin_admin($form, &$form_state) {
  // LinkedIn API credentials
  $form['linkedin'] = array(
      '#title' => t('Base settings'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE 
  );
  
  $form['linkedin']['emh_linkedin_liboauth_path'] = array(
      '#default_value' => variable_get('emh_linkedin_liboauth_path', ''),
      '#title' => t('OAuth library full path (including filename)'),
      '#type' => 'textfield',
      '#description' => t('Linkedin module needs the OAuth php library from http://code.google.com/p/oauth/. You can either download OAuth.php from there and specify the full path here or install the OAuth module from http://drupal.org/project/oauth (both 6.x-2 and 6.x-3 versions are supported)') 
  );
  
  $form['linkedin']['emh_linkedin_debug_mode'] = array(
      '#default_value' => variable_get('emh_linkedin_debug_mode', 0),
      '#title' => t('Turn on debug mode'),
      '#type' => 'checkbox' 
  );
  
  // User profile settings when user registration
  $form['emh_linkedin']['user_page']['emh_linkedin_user_page_fields'] = array(
      '#type' => 'fieldset',
      '#title' => t('LinkedIn fields'),
      '#description' => t('Choose what fields to retrieve from a user LinkedIn profile.'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE 
  );
  $form['emh_linkedin']['user_page']['emh_linkedin_user_page_fields']['warning'] = array(
      '#type' => 'markup',
      '#value' => '<ul>' . '<li>' . t('Be sure to observe what you are allowed to do with the data by checking the "Business and Legal" documents at http://developer.linkedin.com/community/apis?view=documents.') . '</li>' . '<li>' . t('A description of each field is available at http://developer.linkedin.com/docs/DOC-1061.') . '</li>' . '<li>' . t('Also, please note that the visibility of each field depends on the relation between the viewing and the viewed user at LinkedIn and his visibilty settings : be careful when theming the output.') . '<li>' . '<li>' . t('And finally, the output might be buggy for some of them and will probably need some theming work.') . '<li>' . '</ul>' 
  );
  module_load_include('inc', 'emh_linkedin');
  $fields = _emh_linkedin_list_fields('auth');
  $options = array();
  foreach ($fields as $field) {
    $options[$field] = $field;
  }
  $form['emh_linkedin']['user_page']['emh_linkedin_user_page_fields']['emh_linkedin_user_page_linkedin_fields'] = array(
      '#type' => 'checkboxes',
      '#default_value' => _emh_linkedin_vget_user_page_linkedin_fields(),
      '#options' => $options 
  );
  
  $form['#submit'][] = 'emh_linkedin_admin_submit';
  
  return system_settings_form($form);
}

/**
 * Additionnal submit for Linkedin admin page.
 * Rebuild menu router to avoid problems when switching display from/to tab.
 */
function emh_linkedin_admin_submit(&$form_state) {
  menu_rebuild();
}

/**
 * Update user data with user settings.
 */
function emh_linkedin_user_update_submit(&$form_state) {
  global $user;
  $user_update = user_load($user->uid);
  module_load_include('inc', 'emh_linkedin', 'emh_linkedin');
  $user_fields = _emh_linkedin_get_user_fields($user_update);
  $fields = array_merge($user_fields, _emh_linkedin_fields_default_user_update());
  $profile = emh_linkedin_get_profile_fields($user->uid, $fields);
  
  foreach ($profile as $key => $value) {
    $item = array(
        'name' => $key,
        'value' => $value 
    );
    $user_update = _emh_linkedin_fields_to_user_fields($item, $user_update);
  }
  user_save($user_update);
  
  if (! isset($profile['error'])) {
    drupal_set_message(t('Successful Update.'));
  }
}

/**
 * Implementation of hook_linkedin_user_settings_page.
 * Add our settings to user/%user/edit/emh_linkedin.
 */
function emh_linkedin_linkedin_user_settings_page($account) {
  $elems = array();
  if (variable_get('emh_linkedin_user_page_enabled', 0) > 0 && user_access('display LinkedIn profile')) {
    $elems['emh_linkedin_user_page_enabled'] = array(
        '#type' => 'checkbox',
        '#default_value' => isset($account->data['emh_linkedin_user_page_enabled']) ? $account->data['emh_linkedin_user_page_enabled'] : 0,
        '#title' => t('Display an abstract of your LinkedIn page on your current profile page') 
    );
    return $elems;
  }
  return;
}

/**
 * Build form for user settings.
 */
function emh_linkedin_user_settings($account) {
  $output = '';
  $check = emh_linkedin_get_profile_fields($account->uid, array(
      'first-name',
      'last-name',
      'public-profile-url' 
  ), TRUE);
  
  if (isset($check['error-code'])) {
    $output .= t('You must first authorize LinkedIn integration to use related features.');
  }
  else {
    $output .= t('Your account is associated with @name !public_profile.', array(
        '@name' => $check['first-name'] . ' ' . $check['last-name'],
        '!public_profile' => l($check['public-profile-url'], $check['public-profile-url']) 
    ));
    $form = drupal_get_form('emh_linkedin_user_settings_form', $account);
    $output .= drupal_render($form);
    
    $form = drupal_get_form('emh_linkedin_user_update_form', $account->uid);
    $output .= drupal_render($form);
  }
  return $output;
}

/**
 * Form to update user linkedin data.
 */
function emh_linkedin_user_update_form($form, $form_state, $uid) {
  $form = array();
  $form['#user'] = $uid;
  
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Update') 
  );
  
  $form['#submit'][] = 'emh_linkedin_user_update_submit';
  
  return $form;
}

/**
 * Take users to linkedin auth page.
 */
function emh_linkedin_user_enable_form($form, $form_state, $uid) {
  $form = array();
  $form['#user'] = $uid;
  $form['#action'] = url('/hybridauth/window/LinkedIn?destination=node/323&destination_error=node/323&width=800&height=500&iframe=TRUE');
  
  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Go to LinkedIn'),
      '#suffix' => '<p class="description">' . t('You will be taken to the LinkedIn website in order to complete the process.') . '</p>' 
  );
  
  return $form;
}

/**
 * Form to save user settings about LinkedIn fields.
 */
function emh_linkedin_user_settings_form($form, &$form_state, $account) {
  $form = array();
  $form['emh_linkedin']['user_page']['emh_linkedin_user_page_fields'] = array(
      '#type' => 'fieldset',
      '#title' => t('LinkedIn fields'),
      '#description' => t('Choose what fields to retrieve from a user LinkedIn profile.'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE 
  );
  $form['emh_linkedin']['user_page']['emh_linkedin_user_page_fields']['warning'] = array(
      '#type' => 'markup',
      '#value' => '<ul>' . '<li>' . t('Be sure to observe what you are allowed to do with the data by checking the "Business and Legal" documents at http://developer.linkedin.com/community/apis?view=documents.') . '</li>' . '<li>' . t('A description of each field is available at http://developer.linkedin.com/docs/DOC-1061.') . '</li>' . '<li>' . t('Also, please note that the visibility of each field depends on the relation between the viewing and the viewed user at LinkedIn and his visibilty settings : be careful when theming the output.') . '<li>' . '<li>' . t('And finally, the output might be buggy for some of them and will probably need some theming work.') . '<li>' . '</ul>' 
  );
  module_load_include('inc', 'emh_linkedin');
  $fields = _emh_linkedin_fields_user_update();
  $options = array();
  foreach ($fields as $field) {
    $options[$field] = $field;
  }
  $form['emh_linkedin']['user_page']['emh_linkedin_user_page_fields']['emh_linkedin_user_page_linkedin_fields'] = array(
      '#type' => 'checkboxes',
      '#default_value' => _emh_linkedin_fields_user($account->uid),
      '#options' => $options 
  );
  
  $form = system_settings_form($form);
  
  
  $form['#submit'][] = 'emh_linkedin_user_submit';
  
  return $form;
}

function emh_linkedin_user_submit($form, &$form_state) {
  global $user;
  $user_settings = user_load($user->uid);
  $user_fields = $form_state['values']['emh_linkedin_user_page_linkedin_fields'];
  foreach ($user_fields as $key => $field) {
    if ($field !== 0) {
      if (isset($user_settings->data['emh_linkedin_fields'])) {
        $user_settings->data['emh_linkedin_fields'][$key] = TRUE;
      }
    }
    else {
      $user_settings->data['emh_linkedin_fields'][$key] = FALSE;
    }
  }
  
  user_save($user_settings);
}

