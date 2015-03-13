<?php
/**
 * @file
 * ft_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ft_rules_default_rules_configuration() {
  $items = array();
  $items['rules_auto_subscribe_to_general_group'] = entity_import('rules_config', '{ "rules_auto_subscribe_to_general_group" : {
      "LABEL" : "Auto subscribe to general group",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og" ],
      "ON" : { "user_insert" : [], "user_update" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
      ],
      "DO" : [
        { "og_group_content_add" : { "entity" : [ "account" ], "group" : "node:205" } }
      ]
    }
  }');
  $items['rules_mandatory_group'] = entity_import('rules_config', '{ "rules_mandatory_group" : {
      "LABEL" : "Mandatory Group",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Circle", "EMH" ],
      "REQUIRES" : [ "rules", "og" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "4" : "4", "8" : "8" } },
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
        { "og_subcribe_user" : { "user" : [ "account" ], "group" : [ "entity-fetched" ] } }
      ]
    }
  }');
  $items['rules_pre_subscribe_membres'] = entity_import('rules_config', '{ "rules_pre_subscribe_membres" : {
      "LABEL" : "Pre subscribe members to new Circles",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Circle", "EMH" ],
      "REQUIRES" : [ "og", "rules" ],
      "ON" : { "node_insert--circle" : { "bundle" : "circle" } },
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-pre-members" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "og_subcribe_user" : { "user" : [ "list-item" ], "group" : [ "node" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_subscription_to_group_email'] = entity_import('rules_config', '{ "rules_subscription_to_group_email" : {
      "LABEL" : "Subscription to group email",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Circle", "EMH", "email" ],
      "REQUIRES" : [ "rules", "og" ],
      "ON" : { "og_user_insert" : [] },
      "DO" : [
        { "mail" : {
            "to" : [ "account:mail" ],
            "subject" : "Welcome to [og-membership:group:title]",
            "message" : "Welcome to the group [og-membership:group:title]",
            "from" : "[site:mail]",
            "language" : [ "account:language" ]
          }
        }
      ]
    }
  }');
  return $items;
}