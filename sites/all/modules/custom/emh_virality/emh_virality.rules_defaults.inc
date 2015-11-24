<?php
/**
 * @file
 * Declares the default rules associated to virality.
 */


/**
 * Implements hook_default_rules_configuration().
 * @ingroup rules
 */
function emh_virality_default_rules_configuration() {
  $rules = array();

  $rules['rules_emh_virality_invitation_email'] = entity_import('rules_config', '{ "rules_emh_virality_invitation_email" : {
      "LABEL" : "Invitation email",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "mimemail", "entity" ],
      "ON" : { "emh_invitation_insert" : [] },
      "DO" : [
        { "mimemail" : {
            "key" : "invitation-email",
            "to" : "[emh-invitation:referral-mail]",
            "subject" : "[emh-invitation:referrer-firstname] [emh-invitation:referrer-lastname] invites you to join eMindHub",
            "body" : "Hello,\u003Cbr\/\u003E\r\n\u003Cbr\/\u003E\r\n[emh-invitation:referrer-firstname] [emh-invitation:referrer-lastname] invites you to join eMindHub.\u003Cbr\/\u003E\r\n\u003Cbr\/\u003E\r\neMindHub allows you to access and to respond online to different kinds of requests from the aerospace industry : questions, bids, advertising of mission.\u003Cbr\/\u003E\r\n\u003Cbr\/\u003E\r\nJoin for free the community of experts and promote your skills, find news customers and make money online !\u003Cbr\/\u003E\r\n\u003Cbr\/\u003E\r\n\u003Ca href=\u0022[site:url]expert\/register\u0022\u003EJOIN EMINDHUB\u003C\/a\u003E\u003Cbr\/\u003E\r\n\u003Cbr\/\u003E\r\nThank you !\u003Cbr\/\u003E\r\n\u003Cbr\/\u003E\r\neMindHub team",
            "plaintext" : "Hello,\r\n\r\n[emh-invitation:referrer-firstname] [emh-invitation:referrer-lastname] invites you to join eMindHub.\r\n\r\neMindHub allows you to access and to respond online to different kinds of requests from the aerospace industry : questions, bids, advertising of mission.\r\n\r\nJoin for free the community of experts and promote your skills, find news customers and make money online !\r\n\r\nJOIN EMINDHUB: [site:url]expert\/register\r\n\r\nThank you !\r\n\r\neMindHub team",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');

  return $rules;
}
