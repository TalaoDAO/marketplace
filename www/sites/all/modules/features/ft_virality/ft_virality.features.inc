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
    "subject" : "[user:field-first-name] [user:field-last-name] vous invites \\u00e0 rejoindre eMindHub",
    "mail_body" : "Hello,\\r\\n[user:field-first-name] [user:field-last-name] invites you to join eMindHub.\\r\\neMindHub allows you to access and to respond online to different kinds of\\r\\nrequests from the aerospace industry: questions, bids, advertising of\\r\\nmission.\\r\\n\\r\\nJoin for free the community of experts and promote your skills, find news\\r\\ncustomers and make money online!\\r\\n\\r\\n[user:field-first-name] [user:field-last-name] have a message for you :\\r\\n[emh_invitation:message]\\r\\n\\r\\nJoin eMindHub [1]\\r\\n\\r\\n[1] http:\\/\\/emh.box.local\\/expert\\/register",
    "mail_body_plain" : "",
    "send_plain" : "0",
    "from_override" : "",
    "cc_default" : "",
    "bcc_default" : "",
    "recipient_callback" : "",
    "language" : "fr",
    "emh_earnings" : 0
  }');
  $items['emh_sponsorship_general_without_message'] = entity_import('pet', '{
    "name" : "emh_sponsorship_general_without_message",
    "title" : "emh_sponsorship_general_without_message",
    "subject" : "[user:field-first-name] [user:field-last-name] vous invites \\u00e0 rejoindre eMindHub",
    "mail_body" : "Hello,\\r\\n[user:field-first-name] [user:field-last-name] invites you to join eMindHub.\\r\\neMindHub allows you to access and to respond online to different kinds of\\r\\nrequests from the aerospace industry: questions, bids, advertising of\\r\\nmission.\\r\\n\\r\\nJoin for free the community of experts and promote your skills, find news\\r\\ncustomers and make money online!\\r\\n\\r\\nJoin eMindHub [1]\\r\\n\\r\\n[1] http:\\/\\/emh.box.local\\/expert\\/register",
    "mail_body_plain" : "",
    "send_plain" : "0",
    "from_override" : "",
    "cc_default" : "",
    "bcc_default" : "",
    "recipient_callback" : "",
    "language" : "fr",
    "emh_earnings" : 0
  }');
  $items['emh_sponsorship_request'] = entity_import('pet', '{
    "name" : "emh_sponsorship_request",
    "title" : "emh_sponsorship_request",
    "subject" : "[user:field-first-name] [user:field-last-name] vous invites \\u00e0 rejoindre eMindHub",
    "mail_body" : "Hello [emh_invitation:referral-lastname] [emh_invitation:referral-firstname],\\r\\n[user:field-first-name] [user:field-last-name] invites you to join eMindHub.\\r\\neMindHub allows you to access and to respond online to different kinds of\\r\\nrequests from the aerospace industry: questions, bids, advertising of\\r\\nmission.\\r\\n\\r\\nA new request for expertise has been published on eMindHub: [node:title].\\r\\n\\r\\nJoin for free the community of experts and promote your skills, find news\\r\\ncustomers and make money online!\\r\\n\\r\\n[user:field-first-name] [user:field-last-name] have a message for you :\\r\\n[emh_invitation:message]\\r\\n\\r\\nJoin eMindHub [1]\\r\\n\\r\\n[1] http:\\/\\/emh.box.local\\/expert\\/register",
    "mail_body_plain" : "",
    "send_plain" : "0",
    "from_override" : "",
    "cc_default" : "",
    "bcc_default" : "",
    "recipient_callback" : "",
    "language" : "fr",
    "emh_earnings" : 0
  }');
  $items['emh_sponsorship_request_without_message'] = entity_import('pet', '{
    "name" : "emh_sponsorship_request_without_message",
    "title" : "emh_sponsorship_request_without_message",
    "subject" : "[user:field-first-name] [user:field-last-name] vous invites \\u00e0 rejoindre eMindHub",
    "mail_body" : "Hello [emh_invitation:referral-lastname] [emh_invitation:referral-firstname],\\r\\n[user:field-first-name] [user:field-last-name] invites you to join eMindHub.\\r\\neMindHub allows you to access and to respond online to different kinds of\\r\\nrequests from the aerospace industry: questions, bids, advertising of\\r\\nmission.\\r\\n\\r\\nA new request for expertise has been published on eMindHub: [node:title].\\r\\n\\r\\nJoin for free the community of experts and promote your skills, find news\\r\\ncustomers and make money online!\\r\\n\\r\\nJoin eMindHub [1]\\r\\n\\r\\n[1] http:\\/\\/emh.box.local\\/expert\\/register",
    "mail_body_plain" : "",
    "send_plain" : "0",
    "from_override" : "",
    "cc_default" : "",
    "bcc_default" : "",
    "recipient_callback" : "",
    "language" : "fr",
    "emh_earnings" : 0
  }');
  return $items;
}
