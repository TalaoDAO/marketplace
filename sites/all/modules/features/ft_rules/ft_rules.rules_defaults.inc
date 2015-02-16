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
  $items['rules_pre_subscribe_membres'] = entity_import('rules_config', '{ "rules_pre_subscribe_membres" : {
      "LABEL" : "Pre subscribe membres",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Circle" ],
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
      "TAGS" : [ "email" ],
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
