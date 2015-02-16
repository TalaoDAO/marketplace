<?php

/**
 * @file
 * Admin page callbacks for the OG contact module.
 */

/**
 * Create a table of groups with contact forms.
 *
 * @return
 * A themed table of all groups with a contact form.
 */
function og_contact_admin_groups() {
  $result = db_query('SELECT ogc.gid,og.label FROM {og_contact} ogc INNER JOIN {og} og ON ogc.gid=og.gid WHERE og.state = :state', array(':state' => 1));
  $rows = array();
  foreach ($result as $group) {
    $rows[] = array($group->label, l(t('edit'), 'admin/config/group/contact/edit/' . $group->gid), l(t('delete'), 'admin/config/group/contact/delete/' . $group->gid));
  }
  $header = array(t('Group'), array(
      'data' => t('Operations'),
      'colspan' => 2,
    ));

  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Build the basic form for adding and editing group contact forms
 *
 * Adding and editing the contact forms happens in a few places, both inside
 * and outside the admin area. To keep things simple all of those places use
 * the same basic array produced by this function.
 *
 * @param $op
 * The use case for this form, values are: 'add', 'edit'
 *
 * @param $gid
 * Optional group id of a group, for the edit $op.
 *
 * @return
 * A form array for use in a Drupal form function.
 */
function og_contact_admin_group_form_skel($op, $gid = NULL) {
  switch ($op) {
    case 'add':
      $options = og_contact_group_select_form_options();
      if (count($options) == 0) {
        $form['group'] = array(
          '#markup' => t('All groups already have forms enabled.'),
        );
        return $form;
      }
      $form['group'] = array(
        '#type' => 'select',
        '#title' => t('Group'),
        '#description' => t("Choose the group that you want to add a contact form to."),
        '#required' => TRUE,
        '#options' => $options,
      );
      break;
    case 'edit':
      $edit = db_query('SELECT * FROM {og_contact} WHERE gid = :gid', array(':gid' => $gid))->fetchAssoc();
      $form['group'] = array(
        '#type' => 'hidden',
        '#value' => $gid,
      );
      break;
  }

  // Recipients section
  $form['recipients'] = array(
    '#type' => 'fieldset',
    '#title' => t('Recipients'),
    '#description' => t('By default, contact form submissions go to the administrators of a group. You can change this default behavior, by adding additional recipients below.'),
  );
  $form['recipients']['no_admin'] = array(
    '#type' => 'checkbox',
    '#title' => t('Do not send form submissions to group administrators.'),
    '#default_value' => (!isset($edit)) ? variable_get('no_admin', 0) : $edit['noadmin'],
    '#description' => t("This allows you to send contact form submissions only to the recipients list."),
  );
  if (variable_get('og_contact_group_recipients', 0) == 1) {
    $form['recipients']['group_recipients'] = array(
      '#type' => 'checkbox',
      '#title' => t('Send form submissions to eligible group members.'),
      '#default_value' => (!isset($edit)) ? variable_get('og_contact_group_recipients', 0) : $edit['grouprecipients'],
      '#description' => t('Form submissions will go to group members in a role with "receive og contact submissions" permission.'),
    );
  }
  $form['recipients']['recipients'] = array(
    '#type' => 'textarea',
    '#title' => t('Additional Recipients'),
    '#default_value' => (!isset($edit)) ? NULL : $edit['recipients'],
    '#description' => t("Form submissions will go to these addresses") . ' <br /><br /> ' . t("Example: 'webmaster@example.com' or 'sales@example.com,support@example.com'. To specify multiple recipients, separate each e-mail address with a comma."),
  );
  $form['reply'] = array(
    '#type' => 'textarea',
    '#title' => t('Auto-reply'),
    '#default_value' => (!isset($edit)) ? NULL : $edit['reply'],
    '#description' => t('Optional auto-reply. Leave empty if you do not want to send the user an auto-reply message.'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save form'),
  );

  return $form;
}

/**
 * Group contact add page.
 *
 * This is the page_callback argument that returns a form for
 * drupal_get_form().
 */
function og_contact_admin_add($form, $gid = NULL) {
  $form = og_contact_admin_group_form_skel('add');
  return $form;
}

/**
 * Validate the group contact add form submission.
 */
function og_contact_admin_add_validate($form, &$form_state) {
  // set variables for some optional settings, since we can't assume form
  // values for non-existant form items.
  $group_recipients = FALSE;
  if (variable_get('og_contact_group_recipients', 0) == 1) {
    if ($form_state['values']['group_recipients'] == 1) {
      $group_recipients = TRUE;
    }
  }
  if ($form_state['values']['no_admin'] == 1 && !$form_state['values']['recipients'] && !$group_recipients) {
    form_set_error('recipients', t('You must add recipients, or send form submissions to group administrators.'));
  }
  elseif ($form_state['values']['no_admin'] == 1 && $group_recipients && !$form_state['values']['recipients']) {
    if (!og_contact_check_group_recipients($form_state['values']['group']['#value'])) {
      form_set_error('group_recipients', t('There are currently no members of this group, who are not already administrators, that can recieve form submissions, please add recipients, or send submissions to group administrators.'));
    }
  }
  elseif ($form_state['values']['recipients']) {
    $recipients = explode(',', $form_state['values']['recipients']);
    foreach ($recipients as $recipient) {
      if (!valid_email_address(trim($recipient))) {
        form_set_error('recipients', t('%recipient is an invalid e-mail address.', array('%recipient' => $recipient)));
      }
    }
  }
}

/**
 * Process the group contact add form submission.
 */
function og_contact_admin_add_submit($form, &$form_state) {
  if (arg(4) == 'add') {
    $id = db_insert('og_contact')
  ->fields(array(
      'gid' => $form_state['values']['group'],
      'reply' => $form_state['values']['reply'],
      'recipients' => $form_state['values']['recipients'],
      'noadmin' => $form_state['values']['no_admin'],
    ))
  ->execute();

    $name = og_contact_get_group_name($form_state['values']['group']);
    drupal_set_message(t('Contact form for %group added.', array('%group' => $name)));
    watchdog('mail', 'OG Contact: Form for %group added.', array('%group' => $name), WATCHDOG_NOTICE, l(t('view'), 'admin/config/group/contact'));
  }
  $form_state['redirect'] = 'admin/config/group/contact';
}

/**
 * Group contact edit page.
 */
function og_contact_admin_edit($form, &$form_state) {
  if (arg(0) == 'admin' && is_numeric(arg(5)) && arg(5) > 0) {
    $gid = arg(5);
    $return = 'admin';
  }
  elseif (arg(0) == 'group' && arg(1) == 'node' && is_numeric(arg(2)) && arg(2) > 0) {
    $nid = arg(2);
    $group = og_get_group('node',$nid);
    $entity_type = $group->entity_type;
    $etid = $group->etid;
    $gid = $group->gid;
    $return = 'node';
    og_set_breadcrumb($entity_type, $etid, array(l(t('Group'), "$entity_type/$etid/group")));
  }
  if ($gid) {
    drupal_set_title(t('Edit contact form for ') . og_contact_get_group_name($gid));
    $form = og_contact_admin_group_form_skel('edit', $gid);
    $form['return'] = array(
      '#type' => 'value',
      '#value' => $return,
    );
    if ($nid) {
      $form['nid'] = array(
        '#type' => 'value',
        '#value' => $nid,
      );
    }
    return $form;
  }
  else {
    if ($return == 'admin') {
      drupal_set_message(t('You must choose a group to edit.'), 'error');
    }
    elseif ($return == 'node') {
      drupal_set_title(t('Edit contact form for ') . og_contact_get_group_name($gid));
      drupal_set_message(t('You are not an administrator for this group.'), 'error');
    }
  }
}

/**
 * Validate the group contact edit form submission.
 */
function og_contact_admin_edit_validate($form, &$form_state) {
  if ($form_state['values']['no_admin'] == 1 && !$form_state['values']['recipients'] && $form_state['values']['group_recipients'] == 0) {
    form_set_error('recipients', t('You must add recipients, or send form submissions to list administrators.'));
  }
  elseif ($form_state['values']['recipients']) {
    $recipients = explode(',', $form_state['values']['recipients']);
    foreach ($recipients as $recipient) {
      if (!valid_email_address(trim($recipient))) {
        form_set_error('recipients', t('%recipient is an invalid e-mail address.', array('%recipient' => $recipient)));
      }
    }
  }
}

/**
 * Process the group contact edit page form submission.
 */
function og_contact_admin_edit_submit($form, &$form_state) {
  $name = og_contact_get_group_name($form_state['values']['group']);
  drupal_set_title(t('Edit ') . $name . t('\'s Contact'));
  db_update('og_contact')
  ->fields(array(
    'reply' => $form_state['values']['reply'],
    'noadmin' => $form_state['values']['no_admin'],
    'grouprecipients' => empty($form_state['values']['group_recipients']) ? 0 : $form_state['values']['group_recipients'],
    'recipients' => $form_state['values']['recipients'],
  ))
  ->condition('gid', $form_state['values']['group'])
  ->execute();

  drupal_set_message(t('Contact form for %group has been updated.', array('%group' => $name)));
  watchdog('mail', 'OG Contact: Form for %group updated.', array('%group' => $name), WATCHDOG_NOTICE, l(t('view'), 'admin/config/group/contact'));
  if ($form_state['values']['return'] == 'admin') {
    $form_state['redirect'] = 'admin/config/group/contact';
  }
  elseif ($form_state['values']['return'] == 'node') {
    $form_state['redirect'] = 'node/' . $form_state['values']['nid'] . '/group';
  }
}

/**
 * Group contact form delete page.
 */
function og_contact_admin_delete($form, &$form_state, $group = NULL) {
  $gid = arg(5);
  $name = og_contact_get_group_name($gid);
  if (og_contact_group_has_form($gid)) {
    $form['group'] = array(
      '#type' => 'value',
      '#value' => $gid,
    );

    return confirm_form($form, t('Are you sure you want to delete the contact form for %group?', array('%group' => $name)), 'admin/config/group/contact', t('Any text in the auto reply field will be lost if this form is deleted.'), t('Delete'), t('Cancel'));
  }
  else {
    drupal_set_message(t('Group not found.'), 'error');
    drupal_goto('admin/config/group/contact');
  }
}

/**
 * Process group delete form submission.
 */
function og_contact_admin_delete_submit($form, &$form_state) {
  $name = og_contact_get_group_name($form_state['values']['group']);
  db_delete('og_contact')
  ->condition('gid', arg(5))
  ->execute();
  drupal_set_message(t('The group contact form for %group has been deleted.', array('%group' => $name)));
  watchdog('mail', 'OG Contact: Form for %group was deleted.', array('%group' => $name), WATCHDOG_NOTICE);

  $form_state['redirect'] = 'admin/config/group/contact';
}

/**
 * OG Conact admin settings page
 */
function og_contact_admin_settings($form, &$form_state) {
  $form['og_contact_global_group'] = array(
    '#type' => 'fieldset',
    '#title' => t('Global group contact form settings.'),
  );
  $form['og_contact_global_group']['og_contact_display_tab'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display "Contact" tabs for groups'),
    '#default_value' => variable_get('og_contact_display_tab', 1),
    '#description' => t('Add a "Contact" tab to the tabs of any group with a contact form enabled. If this is turned off, contact forms can still be reached at the URL "node/nid/contact."'),
  );
  $form['og_contact_global_group']['og_contact_group_name_in_subject'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send contact form emails with group name in the subject.'),
    '#default_value' => variable_get('og_contact_group_name_in_subject', 0),
    '#description' => t('When a contact form is submitted, the name of the group that is receiving the submission will be prepended to the user supplied subject. (eg: "[Group Name] User supplied subject")'),
  );

  // new groups defaults
  $form['og_contact_new_groups'] = array(
    '#type' => 'fieldset',
    '#title' => t('New group defaults'),
  );
  $form['og_contact_new_groups']['intro'] = array(
    '#value' => t('NOTE: These changes only effect new OG Contact forms. They do not take effect retroactively. You must change values for each contact form that has already been created, or delete and recreate all of them.'),
  );
  $form['og_contact_new_groups']['og_contact_enable_all'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatically create Contact forms for new groups'),
    '#default_value' => variable_get('og_contact_enable_all', 0),
    '#description' => t('Give all new groups Contact forms when they are created. NOTE: existing groups will still need to have their Contact forms enabled, you can enable them for all groups ' . l(t('here'), 'admin/config/group/contact/addall') . '.'),
  );
  return system_settings_form($form);
}

/**
 * Add all Groups page.
 */
function og_contact_admin_add_all($form, &$form_state) {
  $group_count = og_get_all_group(array(OG_STATE_ACTIVE), array('count' => TRUE));
  $form_count = og_contact_form_count();
  if ($group_count == $form_count && $group_count != 0) {
    $form['all_groups'] = array(
      '#markup' => t('All groups already have forms enabled.'),
    );
    return $form;
  }
  $form['all_groups'] = array(
    '#type' => 'value',
    '#value' => 1,
  );
  return confirm_form($form, t('Are you sure you want to add contact forms for every group?'), 'admin/config/group/contact', t(''), t('Add'), t('Cancel'));
}

/**
 * Process add all Groups form submission.
 */
function og_contact_admin_add_all_submit($form, &$form_state) {
  $groups = og_get_all_group();
  $grpno = 0;
  $alteredno = 0;
  foreach ($groups as $gid) {
    $group = og_load($gid);
    //Check if group doesn't already have a contact form
    if (!og_contact_group_has_form($group->gid)) {
      //It doesn't, so add it to the og_contact table
      $id = db_insert('og_contact')
  ->fields(array(
        'gid' => $group->gid,
        'reply' => "",
      ))
  ->execute();
      $alteredno++;
    }
    $grpno++;
  }
  if ($grpno != $alteredno) {
    drupal_set_message(t('Added Contact forms to the %altered groups (of %groups) groups that did not already have forms.', array('%altered' => $alteredno, '%groups' => $grpno)));
    watchdog('mail', 'OG Contact: Added contact form to the %altered groups (of %groups) that did not already have forms.', array('%altered' => $alteredno, '%groups' => $grpno), WATCHDOG_NOTICE);
  }
  else {
    drupal_set_message(t('Added Contact forms for all groups'));
    watchdog('mail', 'OG Contact: Added Contact forms for all groups', WATCHDOG_NOTICE);
  }
  $form_state['redirect'] = 'admin/config/group/contact';
}

/**
 * Delete all Groups page.
 */
function og_contact_admin_delete_all($form, &$form_state) {
  $form_count = og_contact_form_count();
  if ($form_count == 0) {
    $form['all_groups'] = array(
      '#markup' => t('There are currently no contact forms enabled.'),
    );
    return $form;
  }
  $form['all_groups'] = array(
    '#type' => 'value',
    '#value' => 1,
  );
  return confirm_form($form, t('Are you sure you want to delete the contact forms for every group?'), 'admin/config/group/contact', t('Any group specific settings and information will be lost. This action cannot be undone.'), t('Delete'), t('Cancel'));
}

/**
 * Process delete all Groups form submission.
 */
function og_contact_admin_delete_all_submit($form, &$form_state) {
  db_delete('og_contact')
  ->execute();
  drupal_set_message(t('The group contact form for all groups have been deleted.'));
  watchdog('mail', 'OG Contact: Forms for all groups were deleted.', WATCHDOG_NOTICE);

  $form_state['redirect'] = 'admin/config/group/contact';
}

/**
 * Generate an options array for form selects of groups that don't have
 * contact forms.
 *
 * Helper function for building group select options on admin pages.
 *
 * @return
 * An array to be used as form select options.
 */
function og_contact_group_select_form_options() {
  $groups = og_get_all_group();
  $options = array();
  foreach ($groups as $gid => $name) {
    if (!og_contact_group_has_form($gid)) {
      $group = og_get_group('group', $gid);
      $options[$gid] = $group->label;
    }
  }
  return $options;
}

/**
 * Check if a group has eligible non-admin recipients
 *
 * Helper function to determine whether there are non admin reipients for a
 * group contact form.
 *
 * @param $gid
 * The nid of the Organic Group to be checked
 * @return
 * A boolean. Returns TRUE if there are eligible group members.
 */
function og_contact_check_group_recipients($gid) {
  // TODO: replace this query with a call to the OG API.
  $query = db_query('SELECT uid FROM {og_uid} WHERE nid = :nid AND is_active = :is_active AND is_admin = :is_admin', array(':nid' => $gid, ':is_active' => 1, ':is_admin' => 0));
  $recipient_count = 0;
  foreach ($query as $uid) {
    if (og_user_access($gid, 'receive og contact submissions', user_load($uid->uid))) {
      $recipient_count++;
    }
  }
  if ($recipient_count > 0) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Count the number of contact forms
 *
 * @return a count of OG Contact forms
 */
function og_contact_form_count() {
  $form_count = db_query('SELECT COUNT(*) FROM {og_contact}')->fetchField();
  return $form_count;
}

/**
 * Get group name from gid.
 *
 * Return the name (node title) of a group based on its group id (node id)
 *
 * @param $gid
 * The group id of the group whose name you are checking.
 * @return
 * The text string of the group name
 */
function og_contact_get_group_name($gid) {
  $group = og_get_group('group',$gid);
  $name = $group->label;
  return $name;
}
