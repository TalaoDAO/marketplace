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
  $items['rules_add_expert_role_on_hybridauth'] = entity_import('rules_config', '{ "rules_add_expert_role_on_hybridauth" : {
      "LABEL" : "Add \\u0022Expert\\u0022 role on hybridauth",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "emh" ],
      "REQUIRES" : [ "rules", "hybridauth" ],
      "ON" : { "hybridauth_user_insert" : [] },
      "DO" : [
        { "user_add_role" : {
            "account" : [ "hybridauth-user" ],
            "roles" : { "value" : { "8" : "8" } }
          }
        }
      ]
    }
  }');
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
      "REQUIRES" : [ "rules", "og", "views_rules" ],
      "ON" : { "user_update" : [] },
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : "314" },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "og_subcribe_user" : { "user" : [ "account" ], "group" : [ "entity-fetched" ] } },
        { "VIEW LOOP" : {
            "VIEW" : "user_circle_list",
            "DISPLAY" : "views_rules_1",
            "ROW VARIABLES" : { "node" : { "node" : "Node" } },
            "DO" : []
          }
        }
      ]
    }
  }');
  $items['rules_pre_subscribe_membres'] = entity_import('rules_config', '{ "rules_pre_subscribe_membres" : {
      "LABEL" : "Pre subscribe members to new Circles",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
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
  $items['rules_set_clients_as_admin_in_mandatory_group'] = entity_import('rules_config', '{ "rules_set_clients_as_admin_in_mandatory_group" : {
      "LABEL" : "Set clients as admin in circles",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og" ],
      "ON" : { "og_user_insert" : [] },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "4" : "4", "8" : "8" } },
            "operation" : "OR"
          }
        },
        { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "og-membership:group:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "og_grant_og_role" : {
            "account" : [ "account" ],
            "group" : [ "entity-fetched" ],
            "roles" : { "value" : { "administrator member" : "administrator member" } }
          }
        }
      ]
    }
  }');
  $items['rules_subscription_to_group_email'] = entity_import('rules_config', '{ "rules_subscription_to_group_email" : {
      "LABEL" : "Subscription to group email",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
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
  $items['rules_welcome_message'] = entity_import('rules_config', '{ "rules_welcome_message" : {
      "LABEL" : "Welcome message",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "emh" ],
      "REQUIRES" : [ "rules", "user_registrationpassword" ],
      "ON" : { "user_registrationpassword_activated" : [] },
      "DO" : [
        { "drupal_message" : {
            "message" : "Welcome to [site:name] !\\r\\nPlease fill your profile information in \\u003Ca href=\\u0022[account:edit-url]\\u0022\\u003Emy account\\u003C\\/a\\u003E.",
            "type" : "warning"
          }
        }
      ]
    }
  }');
  return $items;
}
