<?php
/**
 * Implements hook_default_rules_configuration().
 * @ingroup rules
 */
function emh_circles_default_rules_configuration() {
  $rules = array();

  $rules['rules_webmaster_notification_all_experts_circle_admin_error'] = entity_import('rules_config', '
    { "rules_webmaster_notification_all_experts_circle_admin_error" : {
    "LABEL" : "Webmaster notification - All experts circle error",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "EMH", "Circles" ],
    "REQUIRES" : [ "views_bulk_operations", "rules" ],
    "ON" : { "cron" : [] },
    "IF" : [
      { "views_bulk_operations_condition_result_count" : { "view" : "circle_users|all_experts", "minimum" : "1" } }
    ],
    "DO" : [
      { "mail" : {
          "to" : "[site:mail]",
          "subject" : "[Error] Experts are admin in \u0022All experts\u0022 circle!",
          "message" : "You can find these errors here: [site:url]user\/login?destination=admin\/people\/circles\/all_experts",
          "language" : [ "" ]
        }
      }
    ]
  }
  }
  ');

  $rules['rules_emh_circles_set_clients_as_creator_in_circles'] = entity_import('rules_config', '
    { "rules_emh_circles_set_clients_as_creator_in_circles" : {
    "LABEL" : "Circles - Set Client as Creator member",
    "PLUGIN" : "reaction rule",
    "ACTIVE" : false,
    "WEIGHT" : "1",
    "OWNER" : "rules",
    "TAGS" : [ "Circles", "client", "EMH" ],
    "REQUIRES" : [ "rules", "og" ],
    "ON" : { "user_login" : [] },
    "IF" : [
      { "user_has_role" : {
          "account" : [ "account" ],
          "roles" : { "value" : { "5" : "5", "10" : "10" } },
          "operation" : "OR"
        }
      }
    ],
    "DO" : [
      { "entity_fetch" : {
          "USING" : { "type" : "node", "id" : "314" },
          "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
        }
      },
      { "og_grant_og_role" : {
          "account" : [ "account" ],
          "group" : [ "entity-fetched" ],
          "roles" : { "value" : { "Creator member" : "Creator member" } }
        }
      }
    ]
  }
  }
  ');

  $rules['rules_emh_circles_add_users_in_all_experts_circle'] = entity_import('rules_config', '
    { "rules_emh_circles_add_users_in_all_experts_circle" : {
    "LABEL" : "Circles - Set all users as Member of All experts",
    "PLUGIN" : "reaction rule",
    "WEIGHT" : "-10",
    "OWNER" : "rules",
    "TAGS" : [ "Circles", "EMH" ],
    "REQUIRES" : [ "rules", "og" ],
    "ON" : { "user_login" : [] },
    "DO" : [
      { "entity_fetch" : {
          "USING" : { "type" : "node", "id" : "314" },
          "PROVIDE" : { "entity_fetched" : { "group_fetched" : "Fetched group" } }
        }
      },
      { "og_subcribe_user" : { "user" : [ "account" ], "group" : [ "group-fetched" ] } }
    ]
  }
  }
  ');

  return $rules;
}
