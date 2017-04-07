<?php

/**
 * @file
 * Contains pages for creating, editing, and deleting previewable email templates (PETs).
 */

/**
 * Generate the PET editing form.
 */
function pet_form($form, &$form_state, $pet, $op = 'edit') {
  if ($op == 'clone') {
    $pet->name .= '_cloned';
    $pet->title .= ' (cloned)';
  }

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $pet->title,
    '#description' => t('A short, descriptive title for this email template. It will be used in administrative interfaces, and in page titles and menu items.'),
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Name'),
    '#default_value' => $pet->name,
    '#description' => t('The machine-name for this email template. It may only contain lowercase letters, underscores, and numbers. It will be used in URLs and in all API calls.'),
    '#maxlength' => 64,
    '#machine_name' => array(
      'exists' => 'pet_load',
      'source' => array('title'),
    ),
    '#required' => TRUE,
    '#disabled' => isset($pet->name) && $op != 'clone',
  );
  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => $pet->subject,
    '#description' => t('The subject line of the email template. May include tokens of any token type specified below.'),
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => $pet->mail_body,
    '#description' => t('The body of the email template. May include tokens of any token type specified below.'),
  );
  $form['mimemail'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mime Mail options'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  if (pet_has_mimemail()) {
    $form['mimemail']['mail_body_plain'] = array(
      '#type' => 'textarea',
      '#title' => t('Plain text body'),
      '#default_value' => $pet->mail_body_plain,
      '#description' => t('The plain text body of the email template. May include tokens of any token type specified below. If left empty Mime Mail will use <a href="@url">drupal_html_to_text()</a> to create a plain text version of the email.', array('@url' => 'http://api.drupal.org/api/drupal/includes%21mail.inc/function/drupal_html_to_text/7')),
    );
    $form['mimemail']['send_plain'] = array(
      '#type' => 'checkbox',
      '#title' => t('Send only plain text'),
      '#default_value' => $pet->send_plain,
      '#description' => t('Send email as plain text only. If checked, only the plain text here will be sent. If unchecked both will be sent as multipart mime.'),
    );
  }
  else {
    $form['mimemail']['#description'] = t('HTML email support is most easily provided by the <a href="@url">Mime Mail</a> module, which must be installed and enabled.', array('@url' => 'http://drupal.org/project/mimemail'));
  }
  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#access' => user_access('administer previewable email templates'),
  );
  $form['advanced']['from_override'] = array(
    '#type' => 'textfield',
    '#title' => t('From override'),
    '#default_value' => $pet->from_override,
    '#description' => t('By default, the From: address is the site address, which is %site_mail and which is configurable on the core <a href="@site_url">site information page</a>. You may specify a different From: address here, which will override the system default for this PET.', array('%site_mail' => variable_get('site_mail', ini_get('sendmail_from')), '@site_url' => url('admin/config/system/site-information'))),
    '#maxlength' => 255,
    '#required' => FALSE,
  );
  $form['advanced']['cc_default'] = array(
    '#type' => 'textarea',
    '#title' => t('CC default'),
    '#rows' => 3,
    '#default_value' => $pet->cc_default,
    '#description' => t('Emails to be copied by default for each mail sent to recipient. Enter emails separated by lines or commas.'),
    '#required' => FALSE,
  );
  $form['advanced']['bcc_default'] = array(
    '#type' => 'textarea',
    '#title' => t('BCC default'),
    '#rows' => 3,
    '#default_value' => $pet->bcc_default,
    '#description' => t('Emails to be blind copied by default for each mail sent to recipient. Enter emails separated by lines or commas.'),
    '#required' => FALSE,
  );
  $form['advanced']['recipient_callback'] = array(
    '#type' => 'textfield',
    '#title' => t('Recipient callback'),
    '#default_value' => $pet->recipient_callback,
    '#description' => t('The name of a function which will be called to retrieve a list of recipients. This function will be called if the query parameter uid=0 is in the URL. It will be called with one argument, the loaded node (if the PET takes one) or NULL if not. This function should return an array of recipients in the form uid|email, as in 136|bob@example.com. If the recipient has no uid, leave it blank but leave the pipe in. Providing the uid allows token substitution for the user.'),
    '#maxlength' => 255,
  );
  $form['tokens'] = pet_token_help();

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save template'),
  );

  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => 'admin/structure/pets',
  );

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function pet_form_submit(&$form, &$form_state) {
  $pet = entity_ui_form_submit_build_entity($form, $form_state);
  $pet->save();
  $form_state['redirect'] = 'admin/structure/pets';
}

/**
 * Multi-step form for previewing and sending a PET.
 */
function pet_user_form($form, &$form_state, $pet) {
  if (pet_isset_or($form_state['storage']['step']) == 3) {
    drupal_set_message(t('Email(s) sent'));
    unset($form_state['storage']);
  }

  $step = empty($form_state['storage']['step']) ? 1 : $form_state['storage']['step'];
  $form_state['storage']['step'] = $step;
  $form_state['storage']['pet'] = $pet;

  // Get any query args
  $nid = $form_state['storage']['nid'] = pet_is_natural(pet_isset_or($_REQUEST['nid'])) ? $_REQUEST['nid'] : NULL;
  $uid = $form_state['storage']['uid'] = pet_is_natural(pet_isset_or($_REQUEST['uid'])) ? $_REQUEST['uid'] : NULL;
  $recipient_callback = $form_state['storage']['recipient_callback'] = (
      pet_isset_or($_REQUEST['recipient_callback']) === 'true' ||
      pet_isset_or($_REQUEST['uid']) === '0' // backward compatibility
      );

  switch ($step) {
    case 1:
      if ($recipient_callback) {
        $default_mail = t('Recipient list will be generated for preview.');
      }
      elseif (pet_isset_or($form_state['storage']['recipients_raw'])) {
        $default_mail = $form_state['storage']['recipients_raw'];
      }
      else {
        $default_mail = '';
        if ($uid) {
          if ($account = user_load($uid)) {
            $default_mail = $account->mail;
          }
          else {
            drupal_set_message(t('Cannot load a user with uid @uid.', array('@uid' => $uid)), 'error');
          }
        }
      }
      $form['recipients'] = array(
        '#title' => t('To'),
        '#type' => 'textarea',
        '#required' => TRUE,
        '#rows' => 3,
        '#default_value' => $default_mail,
        '#description' => t('Enter the recipient(s) separated by lines or commas. A separate email will be sent to each, with token substitution if the email corresponds to a site user.'),
        '#disabled' => $recipient_callback,
      );
      $form['copies'] = array(
        '#title' => t('Copies'),
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => empty($pet->cc_default) && empty($pet->bcc_default),
      );
      $form['copies']['cc'] = array(
        '#title' => t('Cc'),
        '#type' => 'textarea',
        '#rows' => 3,
        '#default_value' => pet_isset_or($form_state['storage']['cc']) ? $form_state['storage']['cc'] : $pet->cc_default,
        '#description' => t('Enter any copied emails separated by lines or commas.'),
      );
      $form['copies']['bcc'] = array(
        '#title' => t('Bcc'),
        '#type' => 'textarea',
        '#rows' => 3,
        '#default_value' => pet_isset_or($form_state['storage']['bcc']) ? $form_state['storage']['bcc'] : $pet->bcc_default,
        '#description' => t('Enter any blind copied emails separated by lines or commas.'),
      );
      $form['subject'] = array(
        '#type' => 'textfield',
        '#title' => t('Subject'),
        '#maxlength' => 255,
        '#default_value' => pet_isset_or($form_state['storage']['subject']) ?
            $form_state['storage']['subject'] :
            $pet->subject,
        '#required' => TRUE,
      );
      if (!(pet_has_mimemail() && $pet->send_plain)) {
        $form['mail_body'] = array(
          '#type' => 'textarea',
          '#title' => t('Body'),
          '#default_value' => pet_isset_or($form_state['storage']['mail_body']) ? $form_state['storage']['mail_body'] : $pet->mail_body,
          '#rows' => 15,
          '#description' => t('Review and edit standard template before previewing. This will not change the template for future emailings, just for this one. To change the template permanently, go to the <a href="@settings">template page</a>. You may use the tokens below.', array('@settings' => url('admin/structure/pets/manage/' . $pet->name))),
        );
      }
      if (pet_has_mimemail()) {
        $form['mimemail'] = array(
          '#type' => 'fieldset',
          '#title' => t('Plain text body'),
          '#collapsible' => TRUE,
          '#collapsed' => !(pet_has_mimemail() && $pet->send_plain),
        );
        $form['mimemail']['mail_body_plain'] = array(
          '#type' => 'textarea',
          '#title' => t('Plain text body'),
          '#default_value' => isset($form_state['storage']['mail_body_plain']) ?
              $form_state['storage']['mail_body_plain'] :
              $pet->mail_body_plain,
          '#rows' => 15,
          '#description' => t('Review and edit plain text template before previewing. This will not change the template for future emailings, just for this one. To change the template permanently, go to the <a href="@settings">template page</a>. You may use the tokens below.', array('@settings' => url('admin/structure/pets/manage/' . $pet->name))),
        );
      }
      $form['tokens'] = pet_token_help();
      $form['preview'] = array(
        '#type' => 'submit',
        '#value' => t('Preview'),
      );
      break;

    case 2:
      $form['info'] = array(
        '#value' => t('A preview of the email is shown below. If you\'re satisfied, click Send. If not, click Back to edit the email.'),
      );
      $form['recipients'] = array(
        '#type' => 'textarea',
        '#title' => t('To'),
        '#rows' => 4,
        '#value' => pet_recipients_formatted($form_state['storage']['recipients']),
        '#disabled' => TRUE,
      );
      if ($form_state['values']['cc']) {
        $form['cc'] = array(
          '#type' => 'textarea',
          '#title' => t('CC'),
          '#rows' => 4,
          '#value' => $form_state['values']['cc'],
          '#disabled' => TRUE,
        );
      }
      if ($form_state['values']['bcc']) {
        $form['bcc'] = array(
          '#type' => 'textarea',
          '#title' => t('BCC'),
          '#rows' => 4,
          '#value' => $form_state['values']['bcc'],
          '#disabled' => TRUE,
        );
      }
      $form['subject'] = array(
        '#type' => 'textfield',
        '#title' => t('Subject'),
        '#size' => 80,
        '#value' => $form_state['storage']['subject_preview'],
        '#disabled' => TRUE,
      );
      if (!pet_has_mimemail() || !$pet->send_plain) {
        $form['body_label'] = array(
          '#prefix' => '<div class="pet_body_label">',
          '#suffix' => '</div>',
          '#markup' => '<label>' . t('Body as HTML') . '</label>',
        );
        $form['body_preview'] = array(
          '#prefix' => '<div class="pet_body_preview">',
          '#suffix' => '</div>',
          '#markup' => $form_state['storage']['body_preview'],
        );
        $form['mail_body'] = array(
          '#type' => 'textarea',
          '#title' => t('Body'),
          '#rows' => 15,
          '#value' => $form_state['storage']['body_preview'],
          '#disabled' => TRUE,
        );
      }
      $plain_text = trim($form_state['storage']['body_preview_plain']);
      if (pet_has_mimemail() && ($pet->send_plain || !empty($plain_text))) {
        $form['mail_body_plain'] = array(
          '#type' => 'textarea',
          '#title' => t('Plain text body'),
          '#rows' => 15,
          '#value' => $form_state['storage']['body_preview_plain'],
          '#disabled' => TRUE,
        );
      }
      $form['back'] = array(
        '#type' => 'submit',
        '#value' => t('Back'),
        '#submit' => array('pet_user_form_back'),
      );
      $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Send email(s)'),
      );
      break;
  }

  return $form;
}

/**
 * Validate PET form.
 */
function pet_user_form_validate($form, &$form_state) {
  $step = empty($form_state['storage']['step']) ? 1 : $form_state['storage']['step'];

  if ($step == 1) {
    $errors = pet_validate_recipients($form_state, $recipients);
    if (!empty($errors)) {
      form_set_error('recipients', '<ul><li>' . implode('</li><li>', $errors) . '</li></ul>');
    }
    else {
      // Save recipients to avoid redundant processing on form submit
      $form_state['storage']['recipients'] = $recipients;
    }

    $errors = pet_validate_emails($form_state['values']['cc']);
    if (!empty($errors)) {
      form_set_error('cc', '<ul><li>' . implode('</li><li>', $errors) . '</li></ul>');
    }

    $errors = pet_validate_emails($form_state['values']['bcc']);
    if (!empty($errors)) {
      form_set_error('bcc', '<ul><li>' . implode('</li><li>', $errors) . '</li></ul>');
    }
  }
}

/**
 * Form submission.  Take action on step 2 (confirmation of the populated templates).
 */
function pet_user_form_submit($form, &$form_state) {
  $step = empty($form_state['storage']['step']) ? 1 : $form_state['storage']['step'];
  $form_state['storage']['step'] = $step;

  switch ($step) {
    case 1:
      $form_state['rebuild'] = TRUE;
      $form_state['storage']['recipients_raw'] = $form_state['values']['recipients'];
      $form_state['storage']['subject'] = $form_state['values']['subject'];
      $form_state['storage']['mail_body'] = pet_isset_or($form_state['values']['mail_body']);
      $form_state['storage']['mail_body_plain'] = pet_isset_or($form_state['values']['mail_body_plain']);
      $form_state['storage']['cc'] = $form_state['values']['cc'];
      $form_state['storage']['bcc'] = $form_state['values']['bcc'];
      pet_make_preview($form_state);
      break;

    case 2:
      $form_state['rebuild'] = TRUE;
      $name = $form_state['storage']['pet']->name;
      $recipients = $form_state['storage']['recipients'];
      $options = array(
        'nid' => $form_state['storage']['nid'],
        'subject' => $form_state['storage']['subject'],
        'body' => $form_state['storage']['mail_body'],
        'body_plain' => $form_state['storage']['mail_body_plain'],
        'from' => NULL,
        'cc' => $form_state['storage']['cc'],
        'bcc' => $form_state['storage']['bcc'],
      );
      pet_send_mail($name, $recipients, $options);
      break;
  }

  $form_state['storage']['step'] ++;
}

/**
 * Helper function to provide token help to template construction form and template use form.
 */
function pet_token_help() {
  if (module_exists('token')) {
    $tokens = array(
      '#title' => t('Replacement patterns'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#description' => t('Make sure that the tokens you choose are available to your template when previewed. The list below includes the standard Nodes and Users groups, as well as global tokens. See also hook_pet_substitutions_alter().'),
    );
    $tokens['token_tree'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('node', 'user'),
    );
  }
  else {
    $tokens = array(
      '#markup' => '<p>' . t('Enable the <a href="@drupal-token">Token module</a> to view the available token browser.', array('@drupal-token' => 'http://drupal.org/project/token')) . '</p>',
    );
  }
  return $tokens;
}

/**
 * Return user to starting point on template multi-form.
 */
function pet_user_form_back($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $form_state['storage']['step'] = 1;
}

/**
 * Generate a preview of the tokenized email for the first in the list.
 */
function pet_make_preview(&$form_state) {
  $params = array(
    'pet_uid' => $form_state['storage']['recipients'][0]['uid'],
    'pet_nid' => $form_state['storage']['nid'],
  );
  $subs = pet_substitutions($form_state['storage']['pet'], $params);

  $form_state['storage']['subject_preview'] = token_replace($form_state['values']['subject'], $subs);
  $form_state['storage']['body_preview'] = token_replace(pet_isset_or($form_state['values']['mail_body']), $subs);
  $form_state['storage']['body_preview_plain'] = token_replace(pet_isset_or($form_state['values']['mail_body_plain']), $subs);
}

/**
 * Validate existence of a non-empty recipient list free of email errors.
 */
function pet_validate_recipients($form_state, &$recipients) {
  $errors = array();
  $recipients = array();

  if ($form_state['storage']['recipient_callback']) {
    // Get recipients from callback
    $mails = pet_callback_recipients($form_state);
    if (!is_array($mails)) {
      $errors[] = t('There is no recipient callback defined for this template or it is not returning an array.');
      return $errors;
    }
  }
  else {
    // Get recipients from form field
    $mails = pet_parse_mails($form_state['values']['recipients']);
  }

  // Validate and build recipient array with uid on the fly
  foreach ($mails as $mail) {
    if (!valid_email_address($mail)) {
      $errors[] = t('Invalid email address found: %mail.', array('%mail' => $mail));
    }
    else {
      $recipients[] = array('mail' => $mail, 'uid' => pet_lookup_uid($mail));
    }
  }

  // Check for no recipients
  if (empty($errors) && count($recipients) < 1) {
    $errors[] = t('There are no recipients for this email.');
  }

  return $errors;
}

/**
 * Return an array of email recipients provided by a callback function.
 */
function pet_callback_recipients($form_state) {
  $nid = $form_state['storage']['nid'];
  $pet = $form_state['storage']['pet'];
  $callback = $pet->recipient_callback;
  $node = empty($nid) ? NULL : node_load($nid);

  if (!empty($callback)) {
    if (function_exists($callback)) {
      $recipients = $callback($node);

      // Remove uid for backward compatibility
      if (isset($recipients) && is_array($recipients)) {
        $new_recipients = array();
        foreach ($recipients as $recipient) {
          $recipient = preg_replace('/^[0-9]*\|/', '', $recipient);
          $new_recipients[] = $recipient;
        }
        return $new_recipients;
      }
    }
  }

  return NULL;
}

/**
 * Return formatted list of PET recipients for preview display.
 */
function pet_recipients_formatted($recipients) {
  $output = '';
  if (is_array($recipients)) {
    foreach ($recipients as $recipient) {
      $output .= $recipient['mail'] . ' ';
      $output .= $recipient['uid'] ? t('(user @uid)', array('@uid' => $recipient['uid'])) : t('(no user id)');
      $output .= "\n";
    }
    return $output;
  }
}

/**
 * Return TRUE if a $val is a natural number (integer 1, 2, 3, ...).  Base can
 * be changed to zero if desired.
 */
function pet_is_natural($val, $base = 1) {
  if (!isset($val)) {
    return FALSE;
  }
  $return = ((string) $val === (string) (int) $val);
  if ($return && intval($val) < $base) {
    $return = FALSE;
  }
  return $return;
}

/**
 * Parse a list of emails and return errors if any.
 */
function pet_validate_emails($mail_text) {
  $errors = array();

  foreach (pet_parse_mails($mail_text) as $mail) {
    if (!valid_email_address($mail)) {
      $errors[] = t('Invalid email address found: %mail.', array('%mail' => $mail));
    }
  }

  return $errors;
}

/**
 * PET setting form
 */
function pet_settings($form, $form_state) {
  $form['logging'] = array(
    '#type' => 'fieldset',
    '#title' => t('PET log settings'),
    '#collapsible' => FALSE,
  );

  $options = array(
    0 => t('Log everything.'),
    1 => t('Log errors only.'),
    2 => t('No logging, display error on screen, useful for debugging.'),
  );
  $form['logging']['pet_logging'] = array(
    '#type' => 'radios',
    '#title' => t('Log setting'),
    '#options' => $options,
    '#default_value' => variable_get('pet_logging', 0),
  );
  return system_settings_form($form);
}
