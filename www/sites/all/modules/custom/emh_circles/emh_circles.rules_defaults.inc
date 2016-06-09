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

  $rules['rules_emh_circles_send_email_member_subscribe_pending'] = entity_import('rules_config', '
    { "rules_emh_circles_send_email_member_subscribe_pending" : {
    "LABEL" : "Circles - Send email - Member subscribe (Pending)",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "Circles", "email", "EMH" ],
    "REQUIRES" : [ "rules", "mimemail", "og" ],
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
      { "variable_add" : {
          "USING" : { "type" : "user", "value" : [ "group:author" ] },
          "PROVIDE" : { "variable_added" : { "author" : "Added variable" } }
        }
      },
      { "mimemail" : {
          "key" : "emh_circle_membership_pending",
          "to" : "[account:mail]",
          "subject" : "Your membership request for \u0027[group:title]\u0027",
          "body" : "\u003Cdiv style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:16px;margin-bottom:20px;color:#333;line-height:150%;\u0022\u003E\r\n\u003Cp\u003EDear [account:field-first-name] [account:field-last-name],\u003C\/p\u003E\r\n\u003Cp\u003EYour application for membership in the circle of experts \u003Cstrong\u003E[group:title]\u003C\/strong\u003E is pending approval.\u003C\/p\u003E\r\n\u003C\/div\u003E\r\n\u003Ctable style=\u0022min-width:100%;\u0022 width=\u0022100%\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022 class=\u0022emailButton\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022padding-top:0; padding-right:18px; padding-bottom:18px; padding-left:18px;\u0022 valign=\u0022top\u0022 align=\u0022center\u0022\u003E\r\n\u003Ctable style=\u0022border-collapse: separate !important; border-radius: 0px; background-color: rgb(0, 159, 227);\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022font-family: Arial; font-size: 16px; padding: 15px; color: rgb(255, 255, 255);\u0022 valign=\u0022middle\u0022 align=\u0022center\u0022\u003E\r\n\u003Ca title=\u0022Log in to eMindHub\u0022 href=\u0022[site:url]user\/login?destination=group\/node\/[group:nid]?pk_campaign=circle_[group:nid]_membership_pending\u0026amp;pk_kwd=calltoaction\u0022 target=\u0022_blank\u0022 style=\u0022font-weight: bold!important; letter-spacing: normal; line-height: 100%; text-align: center; text-decoration: none; color:#FFFFFF!important;\u0022\u003ELog in to eMindHub\u003C\/a\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E",
          "plaintext" : "Dear [account:field-first-name] [account:field-last-name],\r\n\r\nYour application for membership in the circle of experts [group:title] is pending approval.\r\n\r\nLog in to eMindHub: [site:url]user\/login?destination=group\/node\/[group:nid]?pk_campaign=circle_[group:nid]_membership_pending\u0026amp;pk_kwd=calltoaction",
          "language" : [ "" ]
        }
      },
      { "mimemail" : {
          "key" : "emh_circle_membership_pending_manager",
          "to" : "[author:mail]",
          "subject" : "[account:field-first-name] [account:field-last-name] membership request for \u0027[group:title]\u0027",
          "body" : "\u003Cdiv style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:16px;margin-bottom:20px;color:#333;line-height:150%;\u0022\u003E\r\n\u003Cp\u003EDear [group:author:field-first-name] [group:author:field-last-name],\u003C\/p\u003E\r\n\u003Cp\u003E\u003Cstrong\u003E[account:field-first-name] [account:field-last-name]\u003C\/strong\u003E requests membership for circle \u003Cstrong\u003E[group:title]\u003C\/strong\u003E in [site:url]user\/login?destination=group\/node\/[group:nid]\/admin\/people?pk_campaign=circle_[group:nid]_membership_pending_manager\u0026amp;pk_kwd=link.\u003C\/p\u003E\r\n\u003Cp\u003E\u003Cspan style=\u0022font-style:italic;\u0022\u003E[og_membership:og-membership-request]\u003C\/span\u003E\u003C\/p\u003E\r\n\u003C\/div\u003E\r\n\u003Ctable style=\u0022min-width:100%;\u0022 width=\u0022100%\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022 class=\u0022emailButton\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022padding-top:0; padding-right:18px; padding-bottom:18px; padding-left:18px;\u0022 valign=\u0022top\u0022 align=\u0022center\u0022\u003E\r\n\u003Ctable style=\u0022border-collapse: separate !important; border-radius: 0px; background-color: rgb(0, 159, 227);\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022font-family: Arial; font-size: 16px; padding: 15px; color: rgb(255, 255, 255);\u0022 valign=\u0022middle\u0022 align=\u0022center\u0022\u003E\r\n\u003Ca title=\u0022Log in to eMindHub\u0022 href=\u0022[site:url]user\/login?destination=group\/node\/[group:nid]\/admin\/people?pk_campaign=circle_[group:nid]_membership_pending_manager\u0026amp;pk_kwd=calltoaction\u0022 target=\u0022_blank\u0022 style=\u0022font-weight: bold!important; letter-spacing: normal; line-height: 100%; text-align: center; text-decoration: none; color:#FFFFFF!important;\u0022\u003ELog in to eMindHub\u003C\/a\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E",
          "plaintext" : "Dear [group:author:field-first-name] [group:author:field-last-name],\r\n\r\n[account:field-first-name] [account:field-last-name] requests membership for circle [group:title] in [site:url]user\/login?destination=group\/node\/[group:nid]\/admin\/people?pk_campaign=circle_[group:nid]_membership_pending_manager\u0026amp;pk_kwd=link.\r\n\r\nLog in to eMindHub: [site:url]user\/login?destination=group\/node\/[group:nid]?pk_campaign=circle_[group:nid]_membership_pending_manager\u0026amp;pk_kwd=calltoaction",
          "language" : [ "" ]
        }
      }
    ]
  }
  }
  ');

  $rules['rules_emh_circles_send_email_membership_accepted'] = entity_import('rules_config', '
    { "rules_emh_circles_send_email_membership_accepted" : {
    "LABEL" : "Circles - Send email - Member subscribe (Active)",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "Circles", "email", "EMH" ],
    "REQUIRES" : [ "rules", "mimemail", "og" ],
    "ON" : { "og_user_approved" : [] },
    "IF" : [
      { "data_is" : { "data" : [ "og-membership:state" ], "value" : "1" } },
      { "entity_is_of_type" : { "entity" : [ "og-membership:group" ], "type" : "node" } },
      { "NOT data_is" : { "data" : [ "og-membership:group:nid" ], "value" : "314" } }
    ],
    "DO" : [
      { "variable_add" : {
          "USING" : { "type" : "node", "value" : [ "og-membership:group" ] },
          "PROVIDE" : { "variable_added" : { "group" : "Added variable" } }
        }
      },
      { "mimemail" : {
          "key" : "emh_circle_membership_accepted",
          "to" : "[account:mail]",
          "subject" : "Your membership request was approved for \u0027[group:title]\u0027",
          "body" : "\u003Cdiv style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:16px;margin-bottom:20px;color:#333;line-height:150%;\u0022\u003E\r\n\u003Cp\u003EDear [account:field-first-name] [account:field-last-name],\u003C\/p\u003E\r\n\u003Cp\u003EYou are now a member in the circle of experts \u003Cstrong\u003E[group:title]\u003C\/strong\u003E.\u003C\/p\u003E\r\n\u003C\/div\u003E\r\n\u003Ctable style=\u0022min-width:100%;\u0022 width=\u0022100%\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022 class=\u0022emailButton\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022padding-top:0; padding-right:18px; padding-bottom:18px; padding-left:18px;\u0022 valign=\u0022top\u0022 align=\u0022center\u0022\u003E\r\n\u003Ctable style=\u0022border-collapse: separate !important; border-radius: 0px; background-color: rgb(0, 159, 227);\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022font-family: Arial; font-size: 16px; padding: 15px; color: rgb(255, 255, 255);\u0022 valign=\u0022middle\u0022 align=\u0022center\u0022\u003E\r\n\u003Ca title=\u0022Log in to eMindHub\u0022 href=\u0022[site:url]user\/login?destination=group\/node\/[group:nid]?pk_campaign=circle_[group:nid]_membership_accepted\u0026amp;pk_kwd=calltoaction\u0022 target=\u0022_blank\u0022 style=\u0022font-weight: bold!important; letter-spacing: normal; line-height: 100%; text-align: center; text-decoration: none; color:#FFFFFF!important;\u0022\u003ELog in to eMindHub\u003C\/a\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E",
          "plaintext" : "Dear [account:field-first-name] [account:field-last-name],\r\n\r\nYou are now a member in the circle of experts [group:title].\r\n\r\nLogin to eMindHub: [site:url]user\/login?destination=group\/node\/[group:nid]?pk_campaign=circle_[group:nid]_membership_accepted\u0026amp;pk_kwd=calltoaction",
          "language" : [ "" ]
        }
      }
    ]
  }
  }
  ');

  $rules['rules_emh_circles_circles_send_email_membership_refused'] = entity_import('rules_config', '
    { "rules_emh_circles_circles_send_email_membership_refused" : {
    "LABEL" : "Circles - Send email - Membership refused",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "Circles", "email", "EMH" ],
    "REQUIRES" : [ "rules", "mimemail", "og" ],
    "ON" : { "og_user_delete" : [] },
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
      { "mimemail" : {
          "key" : "emh_circle_membership_refused",
          "to" : "[account:mail]",
          "subject" : "Your membership request has not been approved for \u0027[group:title]\u0027",
          "body" : "\u003Cdiv style=\u0022text-align:left;font-family:Helvetica,Arial,sans-serif;font-size:16px;margin-bottom:20px;color:#333;line-height:150%;\u0022\u003E\r\n\u003Cp\u003EDear [account:field-first-name] [account:field-last-name],\u003C\/p\u003E\r\n\u003Cp\u003EYour application to membership in the circle of experts \u003Cstrong\u003E[group:title]\u003C\/strong\u003E was refused.\u003C\/p\u003E\r\n\u003C\/div\u003E\r\n\u003Ctable style=\u0022min-width:100%;\u0022 width=\u0022100%\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022 class=\u0022emailButton\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022padding-top:0; padding-right:18px; padding-bottom:18px; padding-left:18px;\u0022 valign=\u0022top\u0022 align=\u0022center\u0022\u003E\r\n\u003Ctable style=\u0022border-collapse: separate !important; border-radius: 0px; background-color: rgb(0, 159, 227);\u0022 border=\u00220\u0022 cellpadding=\u00220\u0022 cellspacing=\u00220\u0022\u003E\r\n\u003Ctbody\u003E\r\n\u003Ctr\u003E\r\n\u003Ctd style=\u0022font-family: Arial; font-size: 16px; padding: 15px; color: rgb(255, 255, 255);\u0022 valign=\u0022middle\u0022 align=\u0022center\u0022\u003E\r\n\u003Ca title=\u0022Log in to eMindHub\u0022 href=\u0022[site:url]user\/login?destination=group\/node\/[group:nid]?pk_campaign=circle_[group:nid]_membership_refused\u0026amp;pk_kwd=calltoaction\u0022 target=\u0022_blank\u0022 style=\u0022font-weight: bold!important; letter-spacing: normal; line-height: 100%; text-align: center; text-decoration: none; color:#FFFFFF!important;\u0022\u003ELog in to eMindHub\u003C\/a\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E\r\n\u003C\/td\u003E\r\n\u003C\/tr\u003E\r\n\u003C\/tbody\u003E\r\n\u003C\/table\u003E",
          "plaintext" : "Dear [account:field-first-name] [account:field-last-name],\r\n\r\nYour application to membership in the circle of experts [group:title] was refused.\r\n\r\nLog in to eMindHub: [site:url]user\/login?destination=group\/node\/[group:nid]?pk_campaign=circle_[group:nid]_membership_refused\u0026amp;pk_kwd=calltoaction",
          "language" : [ "" ]
        }
      }
    ]
  }
  }
  ');

  return $rules;
}
