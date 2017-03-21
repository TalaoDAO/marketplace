<?php

/**
 * @file
 * Declares the default rules associated to notifications.
 */

/**
 * Implements hook_default_rules_configuration().
 *
 * @ingroup rules
 */
function emh_circles_notification_default_rules_configuration() {
  $rules = array();

  $rules['rules_circles_send_email_member_subscribe_pending_manager_admins'] = entity_import('rules_config', '
    { "rules_circles_send_email_member_subscribe_pending_manager_admins" : {
      "LABEL" : "Circles - Send email - Member subscribe (Pending) [Manager \/ Admins]",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Circles", "email", "EMH" ],
      "REQUIRES" : [ "rules", "mimemail", "emh_request_notification" ],
      "ON" : { "_emh_circles_notification_membership_requested" : [] },
      "DO" : [
        { "mimemail" : {
            "key" : "emh_circles_notification_membership_requested_email",
            "to" : "[author:mail]",
            "subject" : "[user:field-first-name] [user:field-last-name] membership request for \u0027[node:title]\u0027",
            "body" : "\u003Cdiv style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:16px;margin-bottom:20px;color:#333;line-height:150%;\u0022\u003E\r\n\u003Cp\u003EDear [account:field-first-name] [account:field-last-name],\u003C\/p\u003E\r\n\u003Cp\u003E\u003Cstrong\u003E[user:field-first-name] [user:field-last-name]\u003C\/strong\u003E requests membership for circle \u003Cstrong\u003E[node:title]\u003C\/strong\u003E in [site:url]user\/login?destination=group\/node\/[node:nid]\/admin\/people?pk_campaign=emh_circle_membership_pending_manager_[node:nid]\u0026amp;utm_medium=email\u0026amp;utm_source=emh_circle_membership_pending_manager\u0026amp;utm_campaign=emh_circle_membership_pending_manager_[node:nid]\u0026amp;pk_kwd=link\u0026amp;utm_content=link.\u003C\/p\u003E\r\n\u003Cp\u003E\u003Cspan style=\u0022font-style:italic;\u0022\u003E[og_membership:og-membership-request]\u003C\/span\u003E\u003C\/p\u003E\r\n\u003C\/div\u003E\r\n\u003Ctable style=\u0022min-width:100%;\u0022 width=\u0022100%\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022 class=\u0022emailButton\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022padding-top:0; padding-right:18px; padding-bottom:18px; padding-left:18px;\u0022 valign=\u0022top\u0022 align=\u0022center\u0022\u003E\r\n\u003Ctable style=\u0022border-collapse: separate !important; border-radius: 0px; background-color: rgb(0, 159, 227);\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022font-family: Arial; font-size: 16px; padding: 15px; color: rgb(255, 255, 255);\u0022 valign=\u0022middle\u0022 align=\u0022center\u0022\u003E\r\n\u003Ca title=\u0022Log in to eMindHub\u0022 href=\u0022[site:url]user\/login?destination=group\/node\/[node:nid]\/admin\/people?pk_campaign=emh_circle_membership_pending_manager_[node:nid]\u0026amp;utm_medium=email\u0026amp;utm_source=emh_circle_membership_pending_manager\u0026amp;utm_campaign=emh_circle_membership_pending_manager_[node:nid]\u0026amp;pk_kwd=calltoaction\u0026amp;utm_content=cta\u0022 target=\u0022_blank\u0022 style=\u0022font-weight: bold!important; letter-spacing: normal; line-height: 100%; text-align: center; text-decoration: none; color:#FFFFFF!important;\u0022\u003ELog in to eMindHub\u003C\/a\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E",
            "plaintext" : "Dear [account:field-first-name] [account:field-last-name],\r\n\r\n[user:field-first-name] [user:field-last-name] requests membership for circle [node:title] in [site:url]user\/login?destination=group\/node\/[node:nid]\/admin\/people?pk_campaign=emh_circle_membership_pending_manager_[node:nid]\u0026amp;utm_medium=email\u0026amp;utm_source=emh_circle_membership_pending_manager\u0026amp;utm_campaign=emh_circle_membership_pending_manager_[node:nid]\u0026amp;pk_kwd=link\u0026amp;utm_content=link.\r\n\r\nLog in to eMindHub: [site:url]user\/login?destination=group\/node\/[node:nid]?pk_campaign=emh_circle_membership_pending_manager_[node:nid]\u0026amp;utm_medium=email\u0026amp;utm_source=emh_circle_membership_pending_manager\u0026amp;utm_campaign=emh_circle_membership_pending_manager_[node:nid]\u0026amp;pk_kwd=calltoaction\u0026amp;utm_content=cta",
            "language" : [ "" ]
          }
        }
      ]
    }
  }
  ');

  return $rules;
}
