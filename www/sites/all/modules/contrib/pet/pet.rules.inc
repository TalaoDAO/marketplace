<?php

/**
 * @file
 * Rules integration for the PET module.
 */

/**
 * Implements hook_rules_action_info().
 */
function pet_rules_action_info() {
  $actions = array(
    'pet_action_send_pet' => array(
      'label' => t('Send PET mail'),
      'group' => t('Previewable email templates'),
      'parameter' => array(
        'pet_name' => array(
          'type' => 'text',
          'label' => t('The previewable email template to use'),
          'options list' => 'pet_pet_list',
          'description' => t('The template that will be sent for this action. You can see the full list or add a new one from <a href="@url">this page</a>.', array('@url' => url('admin/structure/pets'))),
        ),
        'to_text' => array(
          'type' => 'text',
          'label' => t('Recipient(s) (for sending to a fixed set of email address(es))'),
          'description' => t('The e-mail address or addresses where the message will be sent to. The formatting of this string must comply with RFC 2822. Either this or the variable recipient below must be provided.'),
          'optional' => TRUE,
          'default value' => NULL,
        ),
        'to_account' => array(
          'type' => 'user',
          'label' => t('Recipient (for sending to a user provided by a Rules event)'),
          'description' => t('Send mail to address on this account. Either this or the fixed recipient(s) above must be provided. If both are provided, this overrides the fixed list.'),
          'optional' => TRUE,
          'default value' => NULL,
        ),
        'account_subs' => array(
          'type' => 'user',
          'label' => t('User for token substitutions (if any)'),
          'description' => t('If your template includes user tokens, this user will be used for them.'),
          'optional' => TRUE,
          'default value' => NULL,
        ),
        'node_subs' => array(
          'type' => 'node',
          'label' => t('Node for token substitutions (if any)'),
          'description' => t('If your template includes node tokens, this node will be used for them.'),
          'optional' => TRUE,
          'default value' => NULL,
        ),
      ),
    ),
  );

  return $actions;
}

/**
 * Callback for eponymous rules action.
 */
function pet_action_send_pet($pet_name, $to_text, $to_account, $account_subs, $node_subs, $settings) {
  $pet = pet_load($pet_name);
  
  // Resolve the recipient
  if (isset($to_account)) {
    $pet_to = $to_account->mail;
  }
  elseif (isset($to_text)) {
    $pet_to = $to_text;
  }
  else {
    watchdog('pet', 'Mail send using %name PET failed. No recipient provided.', array('%name' => $pet_name), WATCHDOG_ERROR);
    return;
  }
  
  $params = array(
    'pet_from' => variable_get('site_mail', ini_get('sendmail_from')),
    'pet_to' => $pet_to,
    'pet_uid' => isset($account_subs) ? $account_subs->uid : NULL,
    'pet_nid' => isset($node_subs) ? $node_subs->nid : NULL,
  );
  pet_send_one_mail($pet, $params);
}

/**
 * Return list of all PETs for rules configuration.
 */
function pet_pet_list() {
  $list = array();
  foreach (pet_load_multiple(FALSE) as $pet) {
    $list[$pet->name] = $pet->title;
  }
  return $list;
}