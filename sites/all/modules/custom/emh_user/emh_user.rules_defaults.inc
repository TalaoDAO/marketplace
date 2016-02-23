<?php
/**
 * Implements hook_default_rules_configuration().
 * @ingroup rules
 */
function emh_user_default_rules_configuration() {
  $rules = array();

  $rules['rules_emh_user_show_beta_login_message'] = entity_import('rules_config', '
    { "rules_emh_user_show_beta_login_message" : {
        "LABEL" : "Show login message - Beta version",
        "PLUGIN" : "reaction rule",
        "OWNER" : "rules",
        "TAGS" : [ "EMH" ],
        "REQUIRES" : [ "rules", "php" ],
        "ON" : { "user_registrationpassword_activated" : [], "user_login" : [] },
        "DO" : [
          { "drupal_message" : {
            "message" : "\u003Cstrong\u003EWelcome to eMindHub!\u003C\/strong\u003E Thank you for being among the first users of our platform! This is a beta version, for any suggestion or comment please leave a message through the \u003Ca href=\u0022\u003C?php global $base_url; print $base_url; ?\u003E\/contact\u0022\u003Econtact form\u003C\/a\u003E.",
            "type" : "info",
            "repeat" : "0"
          } }
        ]
      }
    }
  ');

  $rules['rules_emh_user_show_expert_login_message'] = entity_import('rules_config', '
    { "rules_emh_user_show_expert_login_message" : {
        "LABEL" : "Show login message - Expert",
        "PLUGIN" : "reaction rule",
        "WEIGHT" : "1",
        "OWNER" : "rules",
        "TAGS" : [ "EMH" ],
        "REQUIRES" : [ "rules", "php", "emh_points" ],
        "ON" : { "user_registrationpassword_activated" : [], "user_login" : [] },
        "IF" : [
          { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
        ],
        "DO" : [
          { "drupal_message" : {
            "message" : "You can earn points by responding to a request and when the client recognize the value of your contribution. You can therefore monetize your points once you have reached a threshold of at least \u003C?php print variable_get(\u0027emh_points_monetization_threshold\u0027, \u00271500\u0027); ?\u003E points.",
            "type" : "info",
            "repeat" : "0"
          } }
        ]
      }
    }
  ');

  $rules['rules_emh_user_show_profile_completion_message_expert'] = entity_import('rules_config', '
    { "rules_show_profile_completion_message_expert" : {
        "LABEL" : "Show profile completion message - Expert",
        "PLUGIN" : "reaction rule",
        "WEIGHT" : "2",
        "OWNER" : "rules",
        "TAGS" : [ "EMH" ],
        "REQUIRES" : [ "pcp", "rules" ],
        "ON" : { "user_login" : [] },
        "IF" : [
          { "NOT pcp_profile_is_completed" : { "account" : [ "account" ] } },
          { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
        ],
        "DO" : [
          { "drupal_message" : {
              "message" : "\u003Cstrong\u003EPromote your expertise\u003C\/strong\u003E by \u003Ca href=\u0022[account:edit-url]\u0022\u003Efilling out your profile\u003C\/a\u003E.",
              "type" : "warning"
            }
          }
        ]
      }
    }
  ');

  $rules['rules_emh_user_show_profile_completion_message_business'] = entity_import('rules_config', '
    { "rules_show_profile_completion_message_business" : {
        "LABEL" : "Show profile completion message - Business",
        "PLUGIN" : "reaction rule",
        "WEIGHT" : "2",
        "OWNER" : "rules",
        "TAGS" : [ "EMH" ],
        "REQUIRES" : [ "pcp", "rules" ],
        "ON" : { "user_login" : [] },
        "IF" : [
          { "NOT pcp_profile_is_completed" : { "account" : [ "account" ] } },
          { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "5" : "5" } } } }
        ],
        "DO" : [
          { "drupal_message" : {
              "message" : "To better \u003Cstrong\u003Emeet your expectations\u003C\/strong\u003E, please \u003Ca href=\u0022[account:edit-url]\u0022\u003Efill out your profile\u003C\/a\u003E.",
              "type" : "warning"
            }
          }
        ]
      }
    }
  ');

  return $rules;
}
