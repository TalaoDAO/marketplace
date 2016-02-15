<?php

/**
 * @file
 * Implement default Rules associated to Points
 */

/**
 * Implements hook_default_rules_configuration().
 * @ingroup rules
 */
function emh_points_default_rules_configuration() {
  $items = array();

  $items['rules_contact_buy'] = entity_import('rules_config', '{ "rules_contact_buy" : {
      "LABEL" : "Contact buy",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "emh_points", "rules", "flag" ],
      "ON" : { "flag_flagged_my_contacts" : [] },
      "IF" : [
        { "emh_points_user_has_enough_points" : {
            "owner" : [ "flagging-user" ],
            "points" : {
              "select" : "flagging-user:uid",
              "php" : { "code" : "return (int)variable_get(\u0027emh_points_contact_price\u0027, \u0027100\u0027);" }
            }
          }
         }
       ],
       "DO" : [
         { "entity_fetch" : {
             "USING" : { "type" : "user", "id" : "1" },
             "PROVIDE" : { "entity_fetched" : { "emindhub" : "eMindHub" } }
           }
         },
         { "move_points" : {
             "source" : [ "flagging-user" ],
             "destination" : [ "emindhub" ],
             "points" : {
               "select" : "flagging-user:uid",
               "php" : { "code" : "return (int)variable_get(\u0027emh_points_contact_price\u0027, \u0027100\u0027);" }
             }
           }
         }
      ]
    }
  }');

  $items['rules_contact_impossible'] = entity_import('rules_config', '{ "rules_contact_impossible" : {
      "LABEL" : "Contact impossible",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "emh_points", "flag", "rules" ],
      "ON" : { "flag_flagged_my_contacts" : [] },
      "IF" : [
        { "NOT emh_points_user_has_enough_points" : {
            "owner" : [ "flagging-user" ],
            "points" : {
              "select" : "flagging-user:uid",
              "php" : { "code" : "return (int)variable_get(\u0027emh_points_contact_price\u0027, \u0027100\u0027);" }
            }
          }
        }
      ],
      "DO" : [
        { "flag_unflaguser" : {
            "flag" : "my_contacts",
            "user" : [ "flagged-user" ],
            "flagging_user" : [ "flagging_user" ],
            "permission_check" : "1"
          }
        },
        { "drupal_message" : {
            "message" : "You don\u0027t have enough points. You need \u003C?php echo variable_get(\u0027emh_points_contact_price\u0027, \u0027100\u0027) ?\u003E points.",
            "type" : "error"
          }
        }
      ]
    }
  }');

  // Donne les points si tu publies le contenu dès sa création
  $items['rules_transfert_points_for_content'] = entity_import('rules_config', '{ "rules_transfert_points_for_content" : {
      "LABEL" : "Transfert points for content",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "emh_points", "rules" ],
      "ON" : {
        "node_insert--question1" : { "bundle" : "question1" },
        "node_insert--challenge" : { "bundle" : "challenge" },
        "node_insert--webform" : { "bundle" : "webform" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_reward" } },
        { "node_is_published" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "move_points" : {
            "source" : [ "node:author" ],
            "destination" : [ "node" ],
            "points" : [ "node:field-reward" ]
          }
        }
      ]
    }
  }');

  // Donne des points si tu édites un contenu et le publie alors qu'il était brouillon
  $items['emh_points_transfert_points_for_published_content'] = entity_import('rules_config', '{ "emh_points_transfert_points_for_published_content" : {
      "LABEL" : "Transfert points for published content",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "emh_points" ],
      "ON" : {
        "node_update--question1" : { "bundle" : "question1" },
        "node_update--challenge" : { "bundle" : "challenge" },
        "node_update--webform" : { "bundle" : "webform" }
      },
      "IF" : [
        { "NOT node_is_published" : { "node" : [ "node-unchanged" ] } },
        { "node_is_published" : { "node" : [ "node" ] } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_reward" } }
      ],
      "DO" : [
        { "move_points" : {
            "source" : [ "node:author" ],
            "destination" : [ "node" ],
            "points" : [ "node:field-reward" ]
          }
        }
      ]
    }
  }');

  $items['emh_points_transfert_points_for_updated_content'] = entity_import('rules_config', '{ "emh_points_transfert_points_for_updated_content" : {
      "LABEL" : "Transfert points for updated content",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "emh_points" ],
      "ON" : {
        "node_update--question1" : { "bundle" : "question1" },
        "node_update--challenge" : { "bundle" : "challenge" },
        "node_update--webform" : { "bundle" : "webform" }
      },
      "IF" : [
        { "node_is_published" : { "node" : [ "node-unchanged" ] } },
        { "node_is_published" : { "node" : [ "node" ] } },
        { "entity_has_field" : { "entity" : [ "node-unchanged" ], "field" : "field_reward" } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_reward" } },
        { "data_is" : {
          "data" : [ "node-unchanged:field-reward" ],
          "op" : "\u003C",
          "value" : [ "node:field-reward" ]
        }}
      ],
      "DO" : [
        { "data_calc" : {
          "USING" : {
            "input_1" : [ "node:field-reward" ],
            "op" : "-",
            "input_2" : [ "node-unchanged:field-reward" ]
          },
          "PROVIDE" : { "result" : { "amount" : "New amount" } }
        }},
        { "move_points" : {
          "source" : [ "node:author" ],
          "destination" : [ "node" ],
          "points" : [ "amount" ]
        }}
      ]
    }
  }');

  return $items;
}
