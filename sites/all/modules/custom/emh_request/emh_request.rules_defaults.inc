<?php
/**
 * @file
 * Declares the default rules associated to virality.
 */


/**
 * Implements hook_default_rules_configuration().
 * @ingroup rules
 */
function emh_request_default_rules_configuration() {
  $rules = array();

  $rules['rules_emh_request_send_notification_email'] = entity_import('rules_config', '{ "rules_emh_request_send_notification_email" : {
    "LABEL" : "Send notification email",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "REQUIRES" : [ "rules", "mimemail", "emh_request" ],
    "ON" : { "emh_request_notify_new_request" : [] },
    "IF" : [
      { "node_is_of_type" : {
        "node" : [ "node" ],
        "type" : { "value" : {
          "challenge" : "challenge",
          "question1" : "question1",
          "webform" : "webform"
        }}
      }}
    ],
    "DO" : [
      { "mimemail" : {
        "key" : "emh_request_notify",
        "to" : [ "user:mail" ],
        "subject" : "A new request has been created",
        "body" : "\u003Cdiv style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:15px;margin-bottom:20px;color:#333;line-height:135%;\u0022\u003EHello,\u003C\/div\u003E\r\n\u003Cdiv style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:15px;margin-bottom:20px;color:#333;line-height:135%;\u0022\u003EA new request has been created.\u003C\/div\u003E\r\n\u003Ctable border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022 width=\u002250%\u0022 class=\u0022emailButton\u0022 style=\u0022background-color: #3498DB;\u0022\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd align=\u0022center\u0022 valign=\u0022middle\u0022 class=\u0022buttonContent\u0022 style=\u0022padding-top:15px;padding-bottom:15px;padding-right:15px;padding-left:15px;\u0022\u003E\r\n\u003Ca style=\u0022color:#FFFFFF;text-decoration:none;font-family:Helvetica,Arial,sans-serif;font-size:20px;line-height:135%;\u0022 href=\u0022[node:url]\u0022 target=\u0022_blank\u0022\u003EView request\u003C\/a\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/table\u003E",
        "plaintext" : "Hello,\\r\\n\\r\\nA new request has been created.\\r\\n\\r\\nView request on [node:url].\r\n",
        "language" : [ "" ]
      }}
    ]
  }}');
  return $rules;
}
