<?php
/**
 * @file
 * ft_virality.features.inc
 */

/**
 * Implements hook_default_pet().
 */
function ft_virality_default_pet() {
  $items = array();
  $items['emh_sponsorship_general'] = entity_import('pet', '{
    "name" : "emh_sponsorship_general",
    "title" : "emh_sponsorship_general",
    "subject" : "[user:field-first-name] [user:field-last-name] invites you to join eMindHub",
    "mail_body" : "Hello [emh_invitation:referral-firstname],\\r\\n\\r\\n[user:field-first-name] [user:field-last-name] invites you to join eMindHub.\\r\\n\\r\\n[emh_invitation:message]\\r\\n\\r\\n\\u003Ca href=\\u0022[site:url]\\u0022\\u003EeMindHub\\u003C\\/a\\u003E allows you to access and to respond online to different kinds of\\r\\nrequests from the aerospace industry: questions, calls, contract missions.\\r\\n\\r\\nJoin for free the community of experts and promote your skills, find news customers and convert\\r\\nyour expertise into cash.\\r\\n\\r\\nLooking forward to hearing from you.\\r\\n\\r\\nKind regards.\\r\\nThe eMindHub team.",
    "mail_body_plain" : "",
    "send_plain" : "0",
    "from_override" : "",
    "cc_default" : "",
    "bcc_default" : "",
    "recipient_callback" : "",
    "language" : "en",
    "emh_earnings" : 0
  }');
  $items['emh_sponsorship_general_without_message'] = entity_import('pet', '{
    "name" : "emh_sponsorship_general_without_message",
    "title" : "emh_sponsorship_general_without_message",
    "subject" : "[user:field-first-name] [user:field-last-name] invites you to join eMindHub",
    "mail_body" : "Hello [emh_invitation:referral-firstname],\\r\\n\\r\\n[user:field-first-name] [user:field-last-name] invites you to join eMindHub.\\r\\n\\r\\n\\u003Ca href=\\u0022[site:url]\\u0022\\u003EeMindHub\\u003C\\/a\\u003E allows you to access and to respond online to different kinds of\\r\\nrequests from the aerospace industry: questions, calls, contract missions.\\r\\n\\r\\nJoin for free the community of experts and promote your skills, find news customers and convert\\r\\nyour expertise into cash.\\r\\n\\r\\nLooking forward to hearing from you.\\r\\n\\r\\nKind regards.\\r\\nThe eMindHub team.",
    "mail_body_plain" : "",
    "send_plain" : "0",
    "from_override" : "",
    "cc_default" : "",
    "bcc_default" : "",
    "recipient_callback" : "",
    "language" : "en",
    "emh_earnings" : 0
  }');
  $items['emh_sponsorship_request'] = entity_import('pet', '{
    "name" : "emh_sponsorship_request",
    "title" : "emh_sponsorship_request",
    "subject" : "[user:field-first-name] [user:field-last-name] recommanded you for : [node:title]",
    "mail_body" : "Hello [emh_invitation:referral-firstname],\\r\\n\\r\\nHope you\\u0027re well.\\r\\n[user:field-first-name] [user:field-last-name] recommanded you on eMindHub for a request he believes you might\\r\\nbe interested in : \\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:title]\\u003C\\/a\\u003E\\r\\n\\r\\n[emh_invitation:message]\\r\\n\\r\\nHave a look at the request by registering on eMindHub (for free) : \\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:title]\\u003C\\/a\\u003E\\r\\nIf you want more information you can contact us by replying to this email or use the livechat on our\\r\\nwebsite.\\r\\n\\r\\nLooking forward to hearing from you.\\r\\n\\r\\nKind regards.\\r\\nThe eMindHub team.",
    "mail_body_plain" : "Hello [emh_invitation:referral-firstname],\\r\\n\\r\\nHope you\\u0027re well.\\r\\n[user:field-first-name] [user:field-last-name] recommanded you on eMindHub for a request he believes you might\\r\\nbe interested in : [node:title]\\r\\n\\r\\n[emh_invitation:message]\\r\\n\\r\\nHave a look at the request by registering on eMindHub (for free) : [node:url]\\r\\nIf you want more information you can contact us by replying to this email or use the livechat on our\\r\\nwebsite.\\r\\n\\r\\nLooking forward to hearing from you.\\r\\n\\r\\nKind regards.\\r\\nThe eMindHub team.",
    "send_plain" : "0",
    "from_override" : "",
    "cc_default" : "",
    "bcc_default" : "",
    "recipient_callback" : "",
    "language" : "en",
    "emh_earnings" : 0
  }');
  $items['emh_sponsorship_request_without_message'] = entity_import('pet', '{
    "name" : "emh_sponsorship_request_without_message",
    "title" : "emh_sponsorship_request_without_message",
    "subject" : "[user:field-first-name] [user:field-last-name] recommanded you for : [node:title]",
    "mail_body" : "Hello [emh_invitation:referral-firstname],\\r\\n\\r\\nHope you\\u0027re well.\\r\\n[user:field-first-name] [user:field-last-name] recommanded you on eMindHub for a request he believes you might\\r\\nbe interested in : \\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:title]\\u003C\\/a\\u003E\\r\\n\\r\\nHave a look at the request by registering on eMindHub (for free) : \\u003Ca href=\\u0022[node:url]\\u0022\\u003E[node:url]\\u003C\\/a\\u003E\\r\\nIf you want more information you can contact us by replying to this email or use the livechat on our\\r\\nwebsite.\\r\\n\\r\\nLooking forward to hearing from you.\\r\\n\\r\\nKind regards.\\r\\nThe eMindHub team.",
    "mail_body_plain" : "Hello [emh_invitation:referral-firstname],\\r\\n\\r\\nHope you\\u0027re well.\\r\\n[user:field-first-name] [user:field-last-name] recommanded you on eMindHub for a request he believes you might\\r\\nbe interested in : [node:title]\\r\\n\\r\\n[emh_invitation:message]\\r\\n\\r\\nHave a look at the request by registering on eMindHub (for free) : [node:url]\\r\\nIf you want more information you can contact us by replying to this email or use the livechat on our\\r\\nwebsite.\\r\\n\\r\\nLooking forward to hearing from you.\\r\\n\\r\\nKind regards.\\r\\nThe eMindHub team.",
    "send_plain" : "0",
    "from_override" : "",
    "cc_default" : "",
    "bcc_default" : "",
    "recipient_callback" : "",
    "language" : "en",
    "emh_earnings" : 0
  }');
  return $items;
}
