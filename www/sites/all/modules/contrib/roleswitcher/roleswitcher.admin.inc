<?php

/**
 * @file
 * Contains administrative pages for Role Switcher.
 */

/**
 * Role Switcher administration page.
 */
function roleswitcher_admin_form($form, $form_state) {

  // Store mode settings.
  $form['roleswitcher_store_mode'] = array(
    '#type' => 'radios',
    '#options' => array(
      'database' => t('Database'),
      'session' => t('Session'),
    ),
    '#title' => t("Store mode"),
    '#description' => t("<p>Select where do you want to save the role selected by Role Switcher.</p><p>Storing in the database overrides a user's actual roles in users_roles table while storing in a session leaves them untouched. A session storage also makes possible to switch to anonymous role which is not possible by using database storage.</p><p>However using a session may cause problems in which case a module does not use global user object for checking permissions but loads user object again from the database. A session will also remain active until a user actually closes the browser regardless of turning off the Role Switcher module.</p>"),
    '#default_value' => variable_get('roleswitcher_store_mode', 'database'),
  );

  return system_settings_form($form);

}