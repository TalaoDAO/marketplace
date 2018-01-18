<?php
/**
 * @file
 * Declares the default rules associated to virality.
 */


/**
 * Implements hook_default_rules_configuration().
 * @ingroup rules
 *//*
function emh_virality_default_rules_configuration() {
  $rules = array();

  $rules['rules_emh_virality_invitation_email'] = entity_import('rules_config', '{ "rules_emh_virality_invitation_email" : {
    "LABEL" : "Invitation email",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "EMH" ],
    "REQUIRES" : [ "rules", "mimemail", "entity" ],
    "ON" : { "emh_invitation_insert" : [] },
    "DO" : [
      { "mimemail" : {
        "key" : "invitation-email",
        "to" : "[emh-invitation:referral-mail]",
        "subject" : "[emh-invitation:referrer-firstname] [emh-invitation:referrer-lastname] invites you to join eMindHub",
        "body" : "\u003Cdiv style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:15px;margin-bottom:20px;color:#333;line-height:135%;\u0022\u003EHello,\u003C\/div\u003E\r\n\u003Cdiv style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:15px;margin-bottom:20px;color:#333;line-height:135%;\u0022\u003E[emh-invitation:referrer-firstname] [emh-invitation:referrer-lastname] invites you to join eMindHub.\u003C\/div\u003E\r\n\u003Cdiv style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:15px;margin-bottom:20px;color:#333;line-height:135%;\u0022\u003EeMindHub allows you to access and to respond online to different kinds of requests from the aerospace industry: questions, bids, advertising of mission.\u003C\/div\u003E\r\n\u003Cdiv style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:15px;margin-bottom:20px;color:#333;line-height:135%;\u0022\u003EJoin for free the community of experts and promote your skills, find news customers and make money online!\u003C\/div\u003E\r\n\u003Ctable border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022 width=\u002250%\u0022 class=\u0022emailButton\u0022 style=\u0022background-color: #3498DB;\u0022\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd align=\u0022center\u0022 valign=\u0022middle\u0022 class=\u0022buttonContent\u0022 style=\u0022padding-top:15px;padding-bottom:15px;padding-right:15px;padding-left:15px;\u0022\u003E\r\n\u003Ca style=\u0022color:#FFFFFF;text-decoration:none;font-family:Helvetica,Arial,sans-serif;font-size:20px;line-height:135%;\u0022 href=\u0022[site:url]expert\/register\u0022 target=\u0022_blank\u0022\u003EJoin eMindHub\u003C\/a\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/table\u003E",
        "plaintext" : "Hello,\r\n\r\n[emh-invitation:referrer-firstname] [emh-invitation:referrer-lastname] invites you to join eMindHub.\r\n\r\neMindHub allows you to access and to respond online to different kinds of requests from the aerospace industry: questions, bids, advertising of mission.\r\n\r\nJoin for free the community of experts and promote your skills, find news customers and make money online!\r\n\r\nJoin eMindHub: [site:url]expert\/register",
        "language" : [ "" ]
      }
     }
    ]
  }
  }');

  return $rules;
}
*/