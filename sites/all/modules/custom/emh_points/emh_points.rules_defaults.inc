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
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_reward" } }
      ],
      "DO" : [
        { "move_points" : {
          "source" : [ "node:author" ],
          "destination" : [ "node" ],
          "points" : [ "node:field-reward" ]                                                                        }
        }
      ]
    }
  }');

  return $items;
}
