<?php
/**
 * @file
 * Declares the default rules associated to notifications.
 */


/**
 * Implements hook_default_rules_configuration().
 * @ingroup rules
 */
function emh_request_notification_default_rules_configuration() {
  $rules = array();

  // Step 2.3) : We send an individual moderation email
  $rules['_emh_request_notification_moderate_mail'] = entity_import('rules_config', '
    { "_emh_request_notification_moderate_mail" : {
    "LABEL" : "Requests - Send moderation email to Webmasters and Administrators.",
    "PLUGIN" : "reaction rule",
    "ACTIVE" : true,
    "OWNER" : "rules",
    "TAGS" : [ "Request" ],
    "REQUIRES" : [ "rules", "mimemail", "emh_request" ],
    "ON" : { "_emh_request_notification_moderate" : [] },
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
          "key" : "emh_request_notification",
          "to" : "[user:mail]",
          "subject" : "[EMH] Moderate this new request: [node:title]",
          "body" : "\u003Ch1 style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:22px;margin-bottom:20px;color:#333;line-height:150%;\u0022\u003EA new request just came up on eMindHub\u003C\/h1\u003E\r\n\u003Cdiv style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:16px;margin-bottom:20px;color:#333;line-height:150%;\u0022\u003E\r\n\u003Cp\u003EDear Webmaster \/ Administrator,\u003C\/p\u003E\r\n\u003Cp\u003EA new request for expertise has been published on eMindHub: \u003Cstrong\u003E\u003Ca title=\u0022Login to eMindHub\u0022 href=\u0022[site:url]user\/login?destination=node\/[node:nid]\u0022 target=\u0022_blank\u0022 style=\u0022font-weight: bold!important;\u0022\u003E[node:title]\u003C\/a\u003E\u003C\/strong\u003E.\u003C\/p\u003E\r\n\u003Cp\u003EYou have 30 minutes to moderate the request if necessary. After, the notification will be sent to all the concerned users. In case of this request is non-appropriate for notification, don\u0027t forget to cancel the scheduled rule that will trigger the notification emails.\u003C\/p\u003E\r\n\u003C\/div\u003E\r\n\u003Ctable style=\u0022min-width:100%;\u0022 width=\u0022100%\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022 class=\u0022emailButton\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022padding-top:0; padding-right:18px; padding-bottom:18px; padding-left:18px;\u0022 valign=\u0022top\u0022 align=\u0022center\u0022\u003E\r\n\u003Ctable style=\u0022border-collapse: separate !important; border-radius: 0px; background-color: rgb(0, 159, 227);\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022font-family: Arial; font-size: 16px; padding: 15px; color: rgb(255, 255, 255);\u0022 valign=\u0022middle\u0022 align=\u0022center\u0022\u003E\r\n\u003Ca title=\u0022Login to eMindHub\u0022 href=\u0022[site:url]user\/login?destination=node\/[node:nid]\u0022 target=\u0022_blank\u0022 style=\u0022font-weight: bold!important; letter-spacing: normal; line-height: 100%; text-align: center; text-decoration: none; color: rgb(255, 255, 255);\u0022\u003ELogin to eMindHub\u003C\/a\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022font-family: Arial; font-size: 16px; padding: 15px; color: rgb(255, 255, 255);\u0022 valign=\u0022middle\u0022 align=\u0022center\u0022\u003E\r\n\u003Ca title=\u0022View the scheduled rule\u0022 href=\u0022[site:url]admin\/config\/workflow\/rules\/schedule\u0022 target=\u0022_blank\u0022 style=\u0022font-weight: bold!important; letter-spacing: normal; line-height: 100%; text-align: center; text-decoration: none; color: rgb(255, 255, 255);\u0022\u003EView the scheduled rule\u003C\/a\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E",
          "plaintext" : "A new request just came up on eMindHub\r\n\r\nDear Webmaster \/ Administrator,\r\n\r\nA new request for expertise has been published on eMindHub: [node:title].\r\n\r\nYou have 30 minutes to moderate the request if necessary. After, the notification will be sent to all the concerned users. In case of this request is non-appropriate for notification, don\u0027t forget to delete the scheduled rule that will trigger the notification emails.\r\n\r\nLogin to eMindHub: [site:url]user\/login?destination=node\/[node:nid]\r\nView the scheduled rule : [site:url]admin\/config\/workflow\/rules\/schedule\r\n",
          "language" : [ "" ]
        }
      }
    ]
  }
  }
  ');

  // Step 3.2) : After the delay, we trigger the building of the notification queue.
  $rules['_emh_request_notification_schedule'] = entity_import('rules_config', '
    { "_emh_request_notification_schedule" : {
        "LABEL" : "Requests - Component to be scheduled for execution : triggers the building of the notification queue.",
        "PLUGIN" : "action set",
        "OWNER" : "rules",
        "REQUIRES" : [ "emh_request" ],
        "USES VARIABLES" : { "node" : { "label" : "Node", "type" : "node" } },
        "ACTION SET" : [ { "_emh_request_notification_build_queue" : { "node" : [ "node" ] } } ]
      }
    }');

  // Step 3.5) : Finally, we send an actual email notification.
  $rules['_emh_request_notification_notify_mail'] = entity_import('rules_config', '
    { "rules_emh_request_notification_notify_mail" : {
      "LABEL" : "Requests - Send a mail now to inform a user of the new request.",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "EMH, Request, Email" ],
      "REQUIRES" : [ "rules", "mimemail", "emh_request" ],
      "ON" : { "_emh_request_notification_notify" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "request" : "request" } } } }
      ],
      "DO" : [
        { "mimemail" : {
            "key" : "emh_request_notification",
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

  return $rules;
}
