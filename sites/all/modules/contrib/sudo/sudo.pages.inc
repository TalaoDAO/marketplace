<?php

/**
 * @file
 */

/**
 * Form builder: Sudoers page
 *
 * @ingroup forms
 *
 * @see sudo_settings_validate().
 * @see sudo_settings_submit().
 */
function sudo_settings($form, $form_state) {
  if (!empty($form_state['values']) && (!empty($form_state['values']['sudo_remove']) || !empty($form_state['values']['sudo_role_remove']))) {
    return @sudo_multiple_delete_confirm($form_state, $form_state['values']['sudo_remove'], $form_state['values']['sudo_role_remove']);
  }
  $form['help'] = array(
    '#value' => '<h2>' . t('Instructions') . '</h2><p>' .
                  t('Sudo module allows administrative users
                  to use the site in the same way that a normal user would, but
                  "sudo" as needed to obtain extra permissions for performing administrative tasks.'
                  . '</p><p>' .
                  'To use this module, you must specify one or more sudoers.  Those
                  users will then have access to a button on every page which will add or remove the site\'s
                  administrative roles on their account.  The roles to be added and removed can be configured on a
                  per-user basis with the form below.')
                  . '</p><p>' .
                  'You may wish to add one or more roles which will cause any
                  users saved with those roles to be automatically added to the
                  sudoers; you can do that under "Automatic Sudo Roles" below.' . '</p>',
  );

  $roles = user_roles(TRUE);
  unset($roles[2]);
  $form['default_roles_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Automatic Sudo Roles'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('When users are saved with one or more of these roles,
      they will automatically be added as a sudo user with the corresponding
      roles as sudo roles.'),
    'sudo_default_roles' => array(
      '#type' => 'checkboxes',
      '#title' => '',
      '#options' => $roles,
      '#default_value' => variable_get('sudo_default_roles', array()),
    ),
  );

  // User list
  $form['sudo_users'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sudo Users'),
    '#description' => t('Add users to this list using the form above.  After users are added,
                        specify a set of roles to be added or removed for each user when sudoing.'),
  );

  if (db_query("SELECT uid FROM {sudo}")->fetchField()) {

    $q = db_query("SELECT s.*, u.name FROM {sudo} s LEFT JOIN {users} u ON s.uid = u.uid");
    while ($u = $q->fetchObject()) {
      $sudo_roles = $u->roles ? unserialize($u->roles) : array();
      $form['sudo_users']['checkboxes'][$u->uid]['roles'] = array(
        '#type' => 'checkboxes',
        '#options' => $roles,
        '#default_value' => $sudo_roles,
      );
      $form['sudo_users']['checkboxes'][$u->uid]['name'] = array('#value' => check_plain($u->name));
      $form['sudo_users']['checkboxes'][$u->uid]['remove'] = array(
        '#type' => 'checkbox',
        '#default_value' => FALSE,
      );
      $form['sudo_users']['checkboxes'][$u->uid]['#tree'] = TRUE;
      $form['sudo_users']['checkboxes']['roles'] = array(
        '#value' => $roles,
        '#tree' => TRUE,
      );
      $form['sudo_users']['checkboxes']['#theme'] = 'sudo_checkboxes';
      $form['sudo_users']['checkboxes']['#tree'] = TRUE;
    }

  }

  // Add user
  $form['new_sudoer'] = array(
    '#type' => 'textfield',
    '#title' => t('Add User'),
    '#description' => t('Type in a uid or part of a username.'),
    '#autocomplete_path' => 'user/autocomplete',
  );

  // Sudo settings
  $form['button'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Button Settings'),
  );
  $form['button']['sudo_title_sudoing'] = array(
    '#type' => 'textfield',
    '#title' => t('Title when sudoing'),
    '#default_value' => variable_get('sudo_title_sudoing', 'sudo'),
  );
  $form['button']['sudo_title_normal'] = array(
    '#type' => 'textfield',
    '#title' => t('Title when normal'),
    '#default_value' => variable_get('sudo_title_normal', 'sudo'),
  );
  $form['button']['sudo_button_path'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Theme Path'),
    '#default_value' => variable_get('sudo_button_path', FALSE),
    '#description' => t('If you select this option, you may either copy the sudo_button folder to your theme directory and make changes as you wish, or implement your own css.'),
  );
  $form['button']['sudo_hide_button'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide Sudo Button'),
    '#default_value' => variable_get('sudo_hide_button', FALSE),
    '#description' => t('Check this box to disable display of the standard button.  You will have to implement the button in your own theme or in a php block.'),
  );

  // Submit
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  drupal_add_css(drupal_get_path('module', 'sudo') . '/sudo_settings.css');
  return $form;
}

/**
 * Theme the sudo checkboxes.
 *
 * @ingroup themeable
 */
function theme_sudo_checkboxes($variables) {
  $form = $variables['form'];

  $header[] = t('Users');
  foreach ($form['roles']['#value'] as $rid => $role_name) {
    $header[] = array(
      'data' => $role_name,
      'class' => 'centered',
    );
  }
  $header[] = array(
    'data' => t('Remove'),
    'class' => 'centered remove',
  );
  unset($form['roles']);

  $rows = array();

  foreach (element_children($form) as $uid) {
    // Don't take form control structures
    if (is_numeric($uid)) {
      $row = array();
      $row[] = array('data' => $form[$uid]['name']['#value']);
      // Module name
      foreach (element_children($form[$uid]['roles']) as $rid) {
        if (is_numeric($rid)) {
          $title = $form[$uid]['name']['#value'] . ' : ' . $form[$uid]['roles'][$rid]['#title'];
          $form[$uid]['roles'][$rid]['#title'] = '';
          $row[] = array(
            'data' => drupal_render($form[$uid]['roles'][$rid]),
            'class' => 'checkbox',
            'title' => $title,
          );
        }
      }
      $row[] = array(
        'data' => drupal_render($form[$uid]['remove']),
        'class' => 'checkbox centered remove',
        'title' => $form[$uid]['name']['#value'] . ' : ' . t('Remove'),
      );
      unset($form[$uid]['name']);
      $rows[] = $row;
    }
  }
  $output = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'permissions')));
  $output .= drupal_render_children($form);
  return $output;
}

/**
 * Validate the sudo settings form.
 *
 * @see sudo_settings_submit().
 */
function sudo_settings_validate($form, &$form_state) {
  if (!empty($form_state['values']['new_sudoer']) && !db_query("SELECT uid FROM {users} WHERE name = :name", array(':name' => $form_state['values']['new_sudoer']))->fetchField()) {
    form_set_error('new_sudoer', t('Not a valid username'));
  }
}

/**
 * Submit handler for the sudo settings form.
 *
 * @see sudo_settings_validate().
 */
function sudo_settings_submit($form, &$form_state) {
  if ($uid = db_query("SELECT uid FROM {users} WHERE name = :name", array(':name' => $form_state['values']['new_sudoer']))->fetchField()) { // intentional assignment of $uid
    if (!db_query("SELECT uid FROM {sudo} WHERE uid = :uid", array(':uid' => $uid))->fetchField()) {
      $id = db_insert('sudo')
        ->fields(array(
              'uid' => $uid,
            ))
        ->execute();
    }
  }
  if (!empty($form_state['values']['checkboxes']) && is_array($form_state['values']['checkboxes'])) {
    foreach ($form_state['values']['checkboxes'] as $uid => $values) {
      if ( is_array($form_state['values']['checkboxes'][$uid]) && is_numeric($uid) ) {
        $save_roles = array_values(array_filter($values['roles']));
        $current_roles = sudo_roles($uid);

        // add all users scheduled for removal to the sudo_remove value, with checkboxes for all sudo roles
        if ($values['remove']) {
          $form_state['rebuild'] = TRUE;
          $form_state['values']['sudo_remove'][$uid] = $current_roles;
        }
        elseif ($diff = array_diff($current_roles, $save_roles)) { // intentional assignment of $diff
          $form_state['rebuild'] = TRUE;
          $form_state['values']['sudo_role_remove'][$uid] = $diff;
          db_update('sudo')
            ->fields(array(
              'roles' => serialize(array_merge($save_roles, $current_roles)),
            ))
            ->condition('uid', $uid)
            ->execute();
        }
        else {
          db_update('sudo')
            ->fields(array(
                'roles' => serialize($save_roles),
              ))
            ->condition('uid', $uid)
            ->execute();
        }
      }
    }
  }
  foreach (array('sudo_hide_button', 'sudo_title_sudoing', 'sudo_title_normal', 'sudo_button_path') as $field) {
    variable_set($field, $form_state['values'][$field]);
  }
  variable_set('sudo_default_roles', array_keys(array_filter($form_state['values']['sudo_default_roles'])));
}

/**
 * Form builder: sudo multiple delete confirmation form.
 *
 * @see sudo_multiple_delete_confirm_submit().
 */
function sudo_multiple_delete_confirm(&$form_state, $sudo_remove, $sudo_role_remove) {
  $roles = user_roles(TRUE);
  foreach (array('sudo_remove', 'sudo_role_remove') as $key) {
    if (is_array($$key)) {
      $form[$key] = array(
        '#type' => 'fieldset',
        '#title' => $key == 'sudo_remove' ? t('Users to be removed') : t('Roles to be removed'),
        '#description' => $key == 'sudo_remove' ?
          t('The following users will be <b>removed from sudoers.</b><br/>
            Any roles checked below will be permanently added to their accounts.<br/>
            <b>All un-checked roles will be removed from their accounts.</b>') :
          t('The following users will remain as sudoers, but with <b>fewer permissions</b> when sudoing.<br/>
            Any roles checked below will be permanently added to their accounts.<br/>
            <b>All un-checked roles will be removed from their accounts.</b>'),
        '#tree' => TRUE,
      );
      foreach ($$key as $uid => $user_roles) {
        $options = array();
        foreach ($user_roles as $rid) {
          $options[$rid] = check_plain($roles[$rid]);
        }
        $form[$key][$uid] = array(
          '#type' => 'checkboxes',
          '#title' => check_plain(db_query("SELECT name FROM {users} WHERE uid = :uid", array(':uid' => $uid))->fetchField()),
          '#options' => $options,
        );
      }
    }
  }
  $form['#submit'][] = 'sudo_multiple_delete_confirm_submit';
  return confirm_form($form,
          t('Which roles should these users have?'), 'admin/user/sudo',
          t('Your changes include removing sudo roles from some users.<br/>Please check
            any roles that the users should continue to have on a permanent basis.<br/>
            <b>All un-checked roles will be removed from users accounts.</b>'),
          t('Continue'), t('Cancel')
        );
}

/**
 * Submit handler for the sudo multiple delete confirmation form.
 */
function sudo_multiple_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    foreach (array('sudo_remove', 'sudo_role_remove') as $key) {
      if (!empty($form_state['values'][$key])) {
        foreach ($form_state['values'][$key] as $uid => $remove_roles) {
          $keep_roles = array_filter($remove_roles);
          $remove_roles = array_keys($remove_roles);
          $current_roles = sudo_roles($uid);

          // save the new sudo roles
          if ($key == 'sudo_remove') {
            db_delete('sudo')
              ->condition('uid', $uid)
              ->execute();
          }
          else {
            db_update('sudo')
              ->fields(array(
                'roles' => serialize(array_diff($current_roles, $remove_roles)),
              ))
              ->condition('uid', $uid)
              ->execute();
          }

          // save the user account
          if (is_array($remove_roles) && !empty($remove_roles)) { // sanity check
            db_delete('users_roles')
              ->condition(db_and()->condition('uid', $uid)->condition('rid', $remove_roles, 'IN'))
              ->execute();
            foreach ($keep_roles as $rid) {
              $id = db_insert('users_roles')
                ->fields(array(
                  'uid' => $uid,
                  'rid' => $rid,
                ))
                ->execute();
            }
          }

        }
      }
    }
  }
}

/**
 * Form builder: sudo switcher button form.
 *
 * @ingroup forms
 * @see sudo_switch_submit().
 */
function sudo_switch() {
  global $user;
  $form['sudoing_state'] = array(
    '#type' => 'value',
    '#value' => !(count(array_diff(sudo_roles(), array_keys($user->roles)))) ? 'sudoing' : 'normal'
  );
  $title = 'sudo_title_' . $form['sudoing_state']['#value'];
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t(check_plain(variable_get($title, 'sudo'))),
  );
  return $form;
}

/**
 * Submit handler for sudo_switch form.
 */
function sudo_switch_submit($form, &$form_state) {
  if (variable_get('site_offline', FALSE)) {
    drupal_set_message(t("You can't un-sudo when the site is in maintenance mode."), 'error');
    return;
  }
  global $user;
  if ($sudo_roles = sudo_roles()) { // intentional assignment of $sudo_roles
    // first, take all sudo roles away
    db_delete('users_roles')
      ->condition(db_and()->condition('uid', $user->uid)->condition('rid', $sudo_roles, 'IN'))
      ->execute();
    // then, add them back if the user is not already sudoing
    if ($form_state['values']['sudoing_state'] == 'normal') {
      foreach ($sudo_roles as $rid) {
        db_insert('users_roles')
          ->fields(array(
            'uid' => $user->uid,
            'rid' => $rid,
          ))
          ->execute();
      }
    }

  }
}

/**
 * HTML for sudo switcher button form.
 *
 * @ingroup themeable
 *
 * @param array $variables
 *   An array with the single key of 'form', which contains the sudo button
 *   form.  The default implementation simply renders the form inside a div.
 *
 * @return string
 *   HTML output for the sudo button form to appear on each page.
 */
function theme_sudo_switch($variables) {
  $form = $variables['form'];
  unset($form['#theme']);
  $output = "<div id='sudo-button' class='{$form['sudoing_state']['#value']}'>";
  $output .= drupal_render($form);
  $output .= "</div>";
  return $output;
}

/**
 * Submit handler for the maintenance mode submit form.
 *
 * This function ensures that sudoers who are not sudoing when the site is taken
 * offline will not be locked out; instead, all their sudo roles will be added
 * to their account at that time.
 *
 * @param array $form
 * @param array $form_state
 *
 * @see sudo_form_system_site_maintenance_mode_alter
 */
function sudo_site_offline_submit($form, &$form_state) {
  if ($form_state['values']['maintenance_mode']) {
    $q = db_query("SELECT * FROM {sudo}");
    while ($r = $q->fetchObject()) {
      $roles = $r->roles ? unserialize($r->roles) : FALSE;
      if (is_array($roles) && count($roles)) {
        db_delete('users_roles')
          ->condition(db_and()->condition('uid', $r->uid)->condition('rid', $roles, 'IN'))
          ->execute();
        foreach ($roles as $rid) {
          $id = db_insert('users_roles')
            ->fields(array(
              'uid' => $r->uid,
              'rid' => $rid,
            ))
            ->execute();
        }
      }
    }
  }
}
