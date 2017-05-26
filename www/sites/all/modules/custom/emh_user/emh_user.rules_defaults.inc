<?php
/**
 * Implements hook_default_rules_configuration().
 * @ingroup rules
 */
function emh_user_default_rules_configuration() {
  $rules = array();

  $rules['rules_emh_user_show_expert_login_message'] = entity_import('rules_config', '
    { "rules_emh_user_show_expert_login_message" : {
        "LABEL" : "Show login message - Expert",
        "PLUGIN" : "reaction rule",
        "WEIGHT" : "1",
        "OWNER" : "rules",
        "TAGS" : [ "EMH", "user", "expert" ],
        "REQUIRES" : [ "rules", "php", "emh_points" ],
        "ON" : { "user_registrationpassword_activated" : [], "user_login" : [] },
        "IF" : [
          { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
        ],
        "DO" : [
          { "drupal_message" : {
            "message" : "You can earn credits by responding to client requests or sponsoring suitable experts who might be interested in responding to client requests. You can therefore monetize your credits once you have reached a threshold of at least \u003C?php print variable_get(\u0027emh_points_monetization_threshold\u0027, \u00271500\u0027); ?\u003E credits.",
            "type" : "info",
            "repeat" : "0"
          } }
        ]
      }
    }
  ');

  $rules['rules_emh_user_show_profile_completion_message_expert'] = entity_import('rules_config', '
    { "rules_emh_user_show_profile_completion_message_expert" : {
        "LABEL" : "Show profile completion message - Expert",
        "PLUGIN" : "reaction rule",
        "WEIGHT" : "2",
        "OWNER" : "rules",
        "TAGS" : [ "EMH", "user", "expert" ],
        "REQUIRES" : [ "rules", "pcp", "php" ],
        "ON" : { "user_login" : [] },
        "IF" : [
          { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } },
          { "AND" : [] },
          { "NOT pcp_profile_is_completed" : { "account" : [ "account" ] } }
        ],
        "DO" : [
          { "drupal_message" : {
              "message" : "\u003Cstrong\u003EPromote your expertise\u003C\/strong\u003E by \u003Ca href=\u0022\u003C?php global $base_url; print url($base_url . \u0027\/user\/\u0027 . $account-\u003Euid . \u0027\/edit\u0027); ?\u003E\u0022\u003Efilling out your profile\u003C\/a\u003E.",
              "type" : "warning"
            }
          }
        ]
      }
    }
  ');

  $rules['rules_emh_user_show_profile_completion_message_business'] = entity_import('rules_config', '
    { "rules_emh_user_show_profile_completion_message_business" : {
        "LABEL" : "Show profile completion message - Client",
        "PLUGIN" : "reaction rule",
        "WEIGHT" : "2",
        "ACTIVE" : false,
        "OWNER" : "rules",
        "TAGS" : [ "EMH", "user", "client" ],
        "REQUIRES" : [ "rules", "pcp", "php" ],
        "ON" : { "user_login" : [] },
        "IF" : [
          { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "5" : "5" } } } },
          { "AND" : [] },
          { "NOT pcp_profile_is_completed" : { "account" : [ "account" ] } }
        ],
        "DO" : [
          { "drupal_message" : {
              "message" : "To better \u003Cstrong\u003Emeet your expectations\u003C\/strong\u003E, please \u003Ca href=\u0022\u003C?php global $base_url; print url($base_url . \u0027\/user\/\u0027 . $account-\u003Euid . \u0027\/edit\u0027); ?\u003E\u0022\u003Efill out your profile\u003C\/a\u003E.",
              "type" : "warning"
            }
          }
        ]
      }
    }
  ');

  $rules['rules_emh_user_activation_login_hp_redirect'] = entity_import('rules_config', '
    { "rules_emh_user_activation_login_hp_redirect" : {
    "LABEL" : "Activation, Login HP redirect",
    "PLUGIN" : "reaction rule",
    "WEIGHT" : "-10",
    "OWNER" : "rules",
    "TAGS" : [ "EMH", "user" ],
    "REQUIRES" : [ "rules", "user_registrationpassword", "hybridauth" ],
    "ON" : {
      "user_registrationpassword_activated" : [],
      "hybridauth_user_login" : [],
      "hybridauth_user_insert" : []
    },
    "IF" : [
      { "NOT text_matches" : { "text" : [ "site:current-page:path" ], "match" : "user\/reset" } }
    ],
    "DO" : [
      { "redirect" : { "url" : "\u003Cfront\u003E", "force" : "0", "destination" : "1" } }
    ]
  }
  }
  ');

  $rules['rules_emh_user_logout_hp_redirect'] = entity_import('rules_config', '
    { "rules_emh_user_logout_hp_redirect" : {
    "LABEL" : "Logout HP redirect",
    "PLUGIN" : "reaction rule",
    "WEIGHT" : "-10",
    "OWNER" : "rules",
    "TAGS" : [ "EMH", "user" ],
    "REQUIRES" : [ "rules" ],
    "ON" : { "user_logout" : [] },
    "DO" : [ { "redirect" : { "url" : "\u003Cfront\u003E" } } ]
  }
  }
  ');

  return $rules;
}
