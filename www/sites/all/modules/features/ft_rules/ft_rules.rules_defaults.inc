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
  $items['rules_on_hybridauth_register'] = entity_import('rules_config', '{ "rules_on_hybridauth_register" : {
      "LABEL" : "On hybridauth register",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "hybridauth" ],
      "ON" : { "hybridauth_user_insert" : [] },
      "DO" : [
        { "data_set" : {
            "data" : [ "hybridauth-user:field-first-name" ],
            "value" : [ "hybridauth:firstName" ]
          }
        },
        { "data_set" : {
            "data" : [ "hybridauth-user:field-last-name" ],
            "value" : [ "hybridauth:lastName" ]
          }
        },
        { "data_set" : { "data" : [ "hybridauth-user:mail" ], "value" : [ "hybridauth:email" ] } },
        { "user_add_role" : {
            "account" : [ "hybridauth-user" ],
            "roles" : { "value" : { "4" : "4" } }
          }
        }
      ]
    }
  }');
  return $items;
}
