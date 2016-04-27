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
    "WEIGHT" : "1",
    "OWNER" : "rules",
    "TAGS" : [ "Circles", "client", "EMH" ],
    "REQUIRES" : [ "rules", "og" ],
    "ON" : { "user_login" : [] },
    "IF" : [
      { "user_has_role" : {
          "account" : [ "account" ],
          "roles" : { "value" : { "5" : "5", "10" : "10" } }
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

  $rules['rules_emh_circles_send_email_member_subscribe_pending'] = entity_import('rules_config', '
    { "rules_emh_circles_send_email_member_subscribe_pending" : {
    "LABEL" : "Circles - Send email - Member subscribe (Pending)",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "Circles", "EMH" ],
    "REQUIRES" : [ "rules", "og" ],
    "ON" : { "og_user_insert" : [] },
    "IF" : [
      { "data_is" : { "data" : [ "og-membership:state" ], "value" : "2" } },
      { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } }
    ],
    "DO" : [
      { "variable_add" : {
          "USING" : { "type" : "node", "value" : [ "og-membership:group" ] },
          "PROVIDE" : { "variable_added" : { "group" : "Added variable" } }
        }
      },
      { "mail" : {
          "to" : [ "account:mail" ],
          "subject" : "Your membership request for \u0027[group:title]\u0027",
          "message" : "Dear [account:field-first-name] [account:field-last-name],\r\n\r\nYour membership to group \u0027[group:title]\u0027 located at [group:url] is pending approval."
        }
      },
      { "mail" : {
          "to" : [ "group:author:mail" ],
          "subject" : "[account:field-first-name] [account:field-last-name] membership request for [group:title]",
          "message" : "Dear [group:author:field-first-name] [group:author:field-last-name],\r\n\r\n\u003Cstrong\u003E[account:field-first-name] [account:field-last-name]\u003C\/strong\u003E requests membership for circle \u003Cstrong\u003E[group:title]\u003C\/strong\u003E in [group:url]:\r\n\r\n\u003Cem\u003E[og_membership:og-membership-request]\u003C\/em\u003E",
          "language" : [ "" ]
        }
      }
    ]
  }
  }
  ');

  $rules['rules_emh_circles_send_email_member_subscribe_active'] = entity_import('rules_config', '
    { "rules_emh_circles_send_email_member_subscribe_active" : {
    "LABEL" : "Circles - Send email - Member subscribe (Active)",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "Circles", "EMH" ],
    "REQUIRES" : [ "rules", "og" ],
    "ON" : { "og_user_insert" : [] },
    "IF" : [
      { "data_is" : { "data" : [ "og-membership:state" ], "value" : "1" } },
      { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } }
    ],
    "DO" : [
      { "variable_add" : {
          "USING" : { "type" : "node", "value" : [ "og-membership:group" ] },
          "PROVIDE" : { "variable_added" : { "group" : "Added variable" } }
        }
      },
      { "mail" : {
          "to" : [ "account:mail" ],
          "subject" : "Your membership request was approved for \u0027[group:title]\u0027\r\n",
          "message" : "Dear [account:field-first-name] [account:field-last-name],\r\n\r\nYou are now a member in the circle \u0027[group:title]\u0027 located at [group:url]"
        }
      },
      { "mail" : {
          "to" : [ "group:author:mail" ],
          "subject" : "[account:name] joined [group:title]",
          "message" : "Dear [group:author:field-first-name] [group:author:field-last-name],\r\n\r\n\u003Cstrong\u003E[account:field-first-name] [account:field-last-name]\u003C\/strong\u003E joined \u003Cstrong\u003E[group:title]\u003C\/strong\u003E in [group:url]",
          "language" : [ "" ]
        }
      }
    ]
  }
  }
  ');

  return $rules;
}
