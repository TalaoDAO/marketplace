<?php

/**
 * Helper function to notify people.
 */
function emh_request_try_to_notify($node) {
  // Validate pre-requisites.
  if (empty($node->field_domaine) || empty($node->og_group_ref)) {
    return;
  }
  // Get all user from groups.
  $users = array();
  $domains = array();
  $mails = array();
  foreach($node->og_group_ref[LANGUAGE_NONE] as $delta => $group) {
    $query = new EntityFieldQuery();
    $query
      ->entityCondition('entity_type', 'og_membership')
      ->propertyCondition('group_type', 'node', '=')
      ->propertyCondition('gid', $group['target_id'], '=')
      ->propertyCondition('entity_type', 'user', '=');
    $result = $query->execute();
    if (!empty($result['og_membership'])) {
      $og_memberships = og_membership_load_multiple(array_keys($result['og_membership']));
      foreach ($og_memberships as $og_membership) {
        $users[] = $og_membership->etid;
      }
    }
  }
  // Get all domains from node.
  foreach($node->field_domaine[LANGUAGE_NONE] as $delta => $term) {
    $domains[] = $term['tid'];
  }
  // Load users.
  $users = user_load_multiple($users);
  // For each user of each group, check domain.
  foreach($users as $user) {
    // If user has the right role(s) and wants to be notified.
    if (
        ($node->type == 'request' && user_access('edit own webform submissions', $user))
        && !empty($user->field_notification_frequency[LANGUAGE_NONE]) && $user->field_notification_frequency[LANGUAGE_NONE][0]['tid'] == 48
       )
    {
      $queue = DrupalQueue::get('emh_request_request_email_notification');
      $item = array('nid' => $node->nid, 'uid' => $user->uid);
      // Check multidomains option
      // drush vset --yes emh_request_send_notification_email_all_domains FALSE
      $multidomains_option = variable_get('emh_request_send_notification_email_all_domains', 0);
      if ($multidomains_option == TRUE) {
        // Notify every expert within the Organic Group
        $queue->createItem($item);
        continue;
      } else {
        foreach($user->field_domaine[LANGUAGE_NONE] as $delta => $term) {
          // If right domain && notification authorized.
          if (in_array($term['tid'], $domains)) {
            $queue->createItem($item);
            continue;
          }
        }
      }
    }
  }
  // Webmaster copy
  // rules_invoke_event('emh_request_notify_webmaster_new_request', $node);
}

/**
 * Implements hook_cron_queue_info().
 */
function emh_request_cron_queue_info() {
  $queues['emh_request_request_email_notification'] = array(
    'worker callback' => 'emh_request_queue_process',
    'time' => 30,
  );
  return $queues;
}

/**
 * Worker callback defined in hook_cron_queue_info()
 */
function emh_request_queue_process($item) {
  $node = node_load($item['nid']);
  $user = user_load($item['uid']);
  rules_invoke_event('emh_request_notify_new_request', $node, $user);
}

/**
 * Implements hook_rules_event_info().
 * @ingroup rules
 */
function emh_request_rules_event_info() {
  $events = array();
  $events['emh_request_notify_new_request'] = array(
    'label' => t('A new content should be notified'),
    'module' => 'emh_request',
    'group' => t('EMH'),
    'variables' => array(
      'node' => array('type' => 'node', 'label' => t('The created content')),
      'user' => array('type' => 'user', 'label' => t('The user to notify')),
    ),
  );
  return $events;
}

/**
 * Implements hook_default_rules_configuration().
 * @ingroup rules
 */
function emh_request_default_rules_configuration() {
  $rules = array();

  $rules['rules_emh_request_send_notification_email'] = entity_import('rules_config', '
    { "rules_emh_request_send_notification_email" : {
      "LABEL" : "Requests - Send email to circle Experts",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "EMH, Request, Email" ],
      "REQUIRES" : [ "rules", "mimemail", "emh_request" ],
      "ON" : { "emh_request_notify_new_request" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "request" : "request" } } } }
      ],
      "DO" : [
        { "mimemail" : {
            "key" : "emh_request_notify",
            "to" : "[user:mail]",
            "subject" : "New request: [node:title]",
            "body" : "\u003Ch1 style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:22px;margin-bottom:20px;color:#333;line-height:150%;\u0022\u003EA new request just came up on eMindHub\u003C\/h1\u003E\r\n\u003Cdiv style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:16px;margin-bottom:20px;color:#333;line-height:150%;\u0022\u003E\r\n\u003Cp\u003EDear [user:field-first-name],\u003C\/p\u003E\r\n\u003Cp\u003EA new request for expertise has been published on eMindHub: \u003Cstrong\u003E\u003Ca title=\u0022Log in to eMindHub\u0022 href=\u0022[site:url]user\/login?destination=node\/[node:nid]?pk_campaign=emh_request_notify_new_request_users_[node:nid]\u0026amp;utm_medium=email\u0026amp;utm_source=emh_request_notify_new_request_users\u0026amp;utm_campaign=emh_request_notify_new_request_users_[node:nid]\u0026amp;pk_kwd=link\u0026amp;utm_content=link\u0022 target=\u0022_blank\u0022 style=\u0022font-weight: bold!important;\u0022\u003E[node:title]\u003C\/a\u003E\u003C\/strong\u003E.\u003C\/p\u003E\r\n\u003Cp\u003EShould you like to know more and respond just log into the platform now.\u003C\/p\u003E\r\n\u003Cp\u003EYou may also sponsor suitable experts who might be interested in responding to this request and earn monitezable credits.\u003C\/p\u003E\r\n\u003C\/div\u003E\r\n\u003Ctable style=\u0022min-width:100%;\u0022 width=\u0022100%\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022 class=\u0022emailButton\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022padding-top:0; padding-right:18px; padding-bottom:18px; padding-left:18px;\u0022 valign=\u0022top\u0022 align=\u0022center\u0022\u003E\r\n\u003Ctable style=\u0022border-collapse: separate !important; border-radius: 0px; background-color: rgb(0, 159, 227);\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022font-family: Arial; font-size: 16px; padding: 15px; color: rgb(255, 255, 255);\u0022 valign=\u0022middle\u0022 align=\u0022center\u0022\u003E\r\n\u003Ca title=\u0022Log in to eMindHub\u0022 href=\u0022[site:url]user\/login?destination=node\/[node:nid]?pk_campaign=emh_request_notify_new_request_users_[node:nid]\u0026amp;utm_medium=email\u0026amp;utm_source=emh_request_notify_new_request_users\u0026amp;utm_campaign=emh_request_notify_new_request_users_[node:nid]\u0026amp;pk_kwd=calltoaction\u0026amp;utm_content=cta\u0022 target=\u0022_blank\u0022 style=\u0022font-weight: bold!important; letter-spacing: normal; line-height: 100%; text-align: center; text-decoration: none; color:#FFFFFF!important;\u0022\u003ELog in to eMindHub\u003C\/a\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E",
            "plaintext" : "A new request just came up on eMindHub\r\n\r\nDear [user:field-first-name],\r\n\r\nA new request for expertise has been published on eMindHub: [node:title].\r\n\r\nShould you like to know more and respond just log into the platform now.\r\n\r\nYou may also sponsor suitable experts who might be interested in responding to this request and earn monitezable credits.\r\n\r\nLogin to eMindHub: [site:url]user\/login?destination=node\/[node:nid]?pk_campaign=emh_request_notify_new_request_users_[node:nid]\u0026amp;utm_medium=email\u0026amp;utm_source=emh_request_notify_new_request_users\u0026amp;utm_campaign=emh_request_notify_new_request_users_[node:nid]\u0026amp;pk_kwd=plain_link\u0026amp;utm_content=plain_link",
            "language" : [ "" ]
          }
        }
      ]
    }
  }
  ');

  $rules['rules_emh_request_send_webmaster_notification_email'] = entity_import('rules_config', '
    { "rules_emh_request_send_webmaster_notification_email" : {
    "LABEL" : "Requests - Send email to Webmaster",
    "PLUGIN" : "reaction rule",
    "ACTIVE" : false,
    "OWNER" : "rules",
    "TAGS" : [ "EMH, Request, Email" ],
    "REQUIRES" : [ "rules", "mimemail", "emh_request" ],
    "ON" : { "emh_request_notify_new_request" : [] },
    "IF" : [
      { "node_is_of_type" : {
          "node" : [ "node" ],
          "type" : { "value" : {
              "challenge" : "challenge",
              "question1" : "question1",
              "webform" : "webform",
              "request" : "request"
            }
          }
        }
      }
    ],
    "DO" : [
      { "mimemail" : {
          "key" : "emh_request_notify",
          "to" : "[site:mail]",
          "subject" : "New request: [node:title]",
          "body" : "\u003Ch1 style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:22px;margin-bottom:20px;color:#333;line-height:150%;\u0022\u003EA new request just came up on eMindHub\u003C\/h1\u003E\r\n\u003Cdiv style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:16px;margin-bottom:20px;color:#333;line-height:150%;\u0022\u003E\r\n\u003Cp\u003EDear Webmaster,\u003C\/p\u003E\r\n\u003Cp\u003EA new request for expertise has been published on eMindHub: \u003Cstrong\u003E\u003Ca title=\u0022Login to eMindHub\u0022 href=\u0022[site:url]user\/login?destination=node\/[node:nid]\u0022 target=\u0022_blank\u0022 style=\u0022font-weight: bold!important;\u0022\u003E[node:title]\u003C\/a\u003E\u003C\/strong\u003E.\u003C\/p\u003E\r\n\u003Cp\u003EShould you like to know more and respond just log into the platform now.\u003C\/p\u003E\r\n\u003Cp\u003EYou may also sponsor suitable experts who might be interested in responding to this request and earn monitezable credits.\u003C\/p\u003E\r\n\u003C\/div\u003E\r\n\u003Ctable style=\u0022min-width:100%;\u0022 width=\u0022100%\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022 class=\u0022emailButton\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022padding-top:0; padding-right:18px; padding-bottom:18px; padding-left:18px;\u0022 valign=\u0022top\u0022 align=\u0022center\u0022\u003E\r\n\u003Ctable style=\u0022border-collapse: separate !important; border-radius: 0px; background-color: rgb(0, 159, 227);\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022font-family: Arial; font-size: 16px; padding: 15px; color: rgb(255, 255, 255);\u0022 valign=\u0022middle\u0022 align=\u0022center\u0022\u003E\r\n\u003Ca title=\u0022Login to eMindHub\u0022 href=\u0022[site:url]user\/login?destination=node\/[node:nid]\u0022 target=\u0022_blank\u0022 style=\u0022font-weight: bold!important; letter-spacing: normal; line-height: 100%; text-align: center; text-decoration: none; color: rgb(255, 255, 255);\u0022\u003ELogin to eMindHub\u003C\/a\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E",
          "plaintext" : "A new request just came up on eMindHub\r\n\r\nDear Webmaster,\r\n\r\nA new request for expertise has been published on eMindHub: [node:title].\r\n\r\nShould you like to know more and respond just log into the platform now.\r\n\r\nYou may also sponsor suitable experts who might be interested in responding to this request and earn monitezable credits.\r\n\r\nLogin to eMindHub: [site:url]user\/login?destination=node\/[node:nid]",
          "language" : [ "" ]
        }
      }
    ]
  }
  }
  ');

  return $rules;
}
