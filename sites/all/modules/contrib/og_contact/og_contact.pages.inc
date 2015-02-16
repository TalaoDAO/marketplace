<?php

/**
 * @file
 * Group contact form page callbacks for the OG contact module.
 */

/**
 * Group contact page
 */
function og_contact_page() {
  $limit = variable_get('og_contact_threshold_limit', 3);
  $window = variable_get('og_contact_threshold_window', 3600);
  if (!flood_is_allowed('og-contact', $limit, $window)) {
    $output = t("You cannot send more than %number0 messages in $number1. Try again later.", array('%number0' => $limit, '%number1' => format_interval($window)));
  }
  else {
    $output = drupal_get_form('og_contact_mail_page');
  }

  return $output;
}

/**
 * Build the contact formn using the form API.
 */
function og_contact_mail_page($form, &$form_state) {
  global $user;
  $nid = arg(1);
  $group = og_get_group('node',$nid);
  $gid = $group->gid;
  $group = og_contact_group_load($gid);

  // use a different theme if the group has one
  //$theme_node = og_set_theme($gid);
  //og_set_group_context($theme_node);

  $name = filter_xss($group['name']);

  drupal_set_title(t('Contact %name', array('%name' => $name)), PASS_THROUGH);
  $groups[$gid] = $name;

  if ($gid && og_contact_group_has_form($gid) == TRUE && arg(2) == 'contact') {
    $form['#token'] = $user->uid ? $user->name . $user->mail : '';
    $form['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Your name'),
      '#maxlength' => 255,
      '#default_value' => $user->uid ? $user->name : '',
      '#required' => TRUE,
    );
    $form['mail'] = array(
      '#type' => 'textfield',
      '#title' => t('Your e-mail address'),
      '#maxlength' => 255,
      '#default_value' => $user->uid ? $user->mail : '',
      '#required' => TRUE,
    );
    $form['subject'] = array(
      '#type' => 'textfield',
      '#title' => t('Subject'),
      '#maxlength' => 255,
      '#required' => TRUE,
    );
    $form['message'] = array(
      '#type' => 'textarea',
      '#title' => t('Message'),
      '#required' => TRUE,
    );
    // We do not allow anonymous users to send themselves a copy
    // because it can be abused to spam people.
    if ($user->uid) {
      $form['copy'] = array(
        '#type' => 'checkbox',
        '#title' => t('Send yourself a copy.'),
      );
    }
    $form['gid'] = array(
      '#type' => 'hidden',
      '#value' => $gid,
    );
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Send e-mail'),
    );
  }
  else {
    drupal_set_message(t('Contact form not configured'), 'status');
  }
  return $form;
}

/**
 * Validate the OG contact page form submission.
 */
function og_contact_mail_page_validate($form, &$form_state) {
  if (!valid_email_address($form_state['values']['mail'])) {
    form_set_error('mail', t('You must enter a valid e-mail address.'));
  }
}

/**
 * Process the contact page form submission.
 */
function og_contact_mail_page_submit($form, &$form_state) {
  global $language;

  $values = $form_state['values'];
  // E-mail address of the sender: as the form field is a text field,
  // all instances of \r and \n have been automatically stripped from it.
  $from = $values['mail'];

  // Load recipients
  $recipients = og_contact_get_recipients($values['gid']);
  // Load group information
  $og_contact_group = og_contact_group_load($values['gid']);
  //Load group object
  $group = og_get_group('group',$values['gid']);

  // drupal_mail('og-contact-page-mail', $recipients, $subject,
  drupal_mail('og_contact', 'page_mail', $recipients, language_default(), $values, $from);

  // If the user requests it, send a copy.
  if ($values['copy']) {
//    drupal_mail('og-contact-page-copy', $from, $subject, $body, $from);
    drupal_mail('og_contact', 'page_copy', $from, $language, $values, $from);
  }

  // Send an auto-reply if necessary:
  if ($og_contact_group['reply']) {
//   drupal_mail('og-contact-page-autoreply', $from, $subject, wordwrap(check_plain($contact->reply)), $contact->recipients);
    drupal_mail('og_contact', 'page_autoreply', $from, $language, $values);
  }

  // Log the operation:
  flood_register_event('og_contact');
  watchdog('mail', '%name-from sent an e-mail regarding %category.', array('%name-from' => $values['name'] . " [$from]", '%category' => $og_contact_group['name']));

  // Update user:
  drupal_set_message(t('Your message has been sent.'));

  // Jump to group page rather than back to contact page to avoid contradictory messages if flood control has been activated.
  $form_state['redirect'] = ('node/' . $group->etid);
}


/**
 * Implements hook_mail().
 */
function og_contact_mail($key, &$message, $params) {
  $language = $message['language'];
  $group = og_contact_group_load($params['gid']);

  switch ($key) {
    case 'page_mail':
    case 'page_copy':
      $contact = $params['contact'];

      if (variable_get('og_contact_group_name_in_subject', 0)) {
        $message['subject'] = t('[!groupname] !subject', array('!groupname' => $group->name, '!subject' => $params['subject']), array('langcode' => $language->language));
      }
      else {
        $message['subject'] = t('!subject', array('!subject' => $params['subject']), array('langcode' => $language->language));
      }
      $message['body'][] = t("!name sent a message using the contact form at !form.", array('!name' => $params['name'], '!form' => url($_GET['q'], array('absolute' => TRUE, 'language' => $language))), array('langcode' => $language->language));
      $message['body'][] = $params['message'];
      break;
    case 'page_autoreply':
      $contact = $params['contact'];
      if (variable_get('og_contact_group_name_in_subject', 0)) {
        $message['subject'] = t('[!groupname] !subject', array('!groupname' => $group->name, '!subject' => $params['subject']), array('langcode' => $language->language));
      }
      else {
        $message['subject'] = t('!subject', array('!subject' => $params['subject']), array('langcode' => $language->language));
      }
      $message['body'][] = $group->reply;
      break;
  }
}



/**
 * Format contact form recipient addresses
 */
function og_contact_get_recipients($gid) {
  // pull in recipients and recipient settings for the groups
  $group_rules = db_query('SELECT noadmin,recipients,grouprecipients FROM {og_contact} WHERE gid = :gid', array(':gid' => $gid))->fetchAssoc();
  // get group admins when enabled
  if ($group_rules->noadmin == 0) {
    //$admin_query = db_query('SELECT uid FROM {og_uid} WHERE nid = :nid AND is_admin = :is_admin AND is_active = :is_active', array(':nid' => $gid, ':is_admin' => 1, ':is_active' => 1));
    $admin_query = og_get_users_by_roles($gid, array(3));
    $admin_uids = array();
    foreach ($admin as $admin_query) {
      $admin_uids[$admin] = $admin;
    }
  }
  // get group recipients when enabled
  if ($group_rules->grouprecipients == 1) {
    $group_uids = array();
    $group_uids = og_contact_return_group_recipients($gid);
  }

  // build and array of user recipient uids
  if (count($admin_uids) && count($group_uids)) {
    $uids = array_merge($admin_uids, $group_uids);
  }
  elseif (count($admin_uids)) {
    $uids = $admin_uids;
  }
  elseif (count($group_uids)) {
    $uids = $group_uids;
  }

  // get each user recipients mail address
  if (count($uids)) {
    $i = 0;
    foreach ($uids as $key => $uid) {
      $mail = db_query('SELECT mail FROM {users} WHERE uid = :uid', array(':uid' => $uid))->fetchField();
      // don't append a comma to the first address
      // and don't append the address if its already in the recipients list
      if ($i == 0 && !strstr($group_rules->recipients, $mail)) {
        $mails = $mail;
        $i++;
      }
      elseif (!strstr($group_rules->recipients, $mail)) {
        $mails .= ', ' . $mail;
      }
    }
    // append group recipients when sent with other user recipients
    if ($group_rules->recipients) {
      $mails .= ',' . $group_rules->recipients;
    }
  }
  elseif ($group_rules->recipients) {
    $mails = $group_rules->recipients;
  }
  return $mails;
}


/**
 * Rerturn an array of group recipients
 */
function og_contact_return_group_recipients($gid) {
  $query = db_query('SELECT uid FROM {og_uid} WHERE nid = :nid AND is_active = :is_active AND is_admin = :is_admin', array(':nid' => $gid, ':is_active' => 1, ':is_admin' => 0));
  $users = array();
  foreach ($query as $uid) {
    // TODO Convert "user_load" to "user_load_multiple" if "$uid->uid" is other than a uid.
    // To return a single user object, wrap "user_load_multiple" with "array_shift" or equivalent.
    // Example: array_shift(user_load_multiple(array(), $uid->uid))
    if (user_access('receive og contact submissions', user_load($uid->uid))) {
      $users[$uid->uid] = $uid->uid;
    }
  }
  return $users;
}
