<?php
/**
 * @file
 * aup.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function aup_default_rules_configuration() {
  $items = array();
  $items['rules_user_retracts_a_vote_down_on_a_question'] = entity_import('rules_config', '{ "rules_user_retracts_a_vote_down_on_a_question" : {
      "LABEL" : "User retracts a vote down on a question",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Answers Userpoints" ],
      "REQUIRES" : [ "rules", "voting_rules", "userpoints_rules" ],
      "ON" : [ "voting_rules_delete_node" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "question" : "question" } }
          }
        },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "operator" : "\\u003C", "value" : "0" } },
        { "NOT data_is" : { "data" : [ "vote:user:uid" ], "value" : [ "node:author:uid" ] } },
        { "NOT data_is" : { "data" : [ "node:author:uid" ], "value" : "0" } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "2",
            "tid" : "1",
            "entity" : [ "node" ],
            "description" : "A user retracted a vote down on your question",
            "operation" : "Retract Vote Down",
            "reference" : "[node:nid]",
            "display" : 1,
            "moderate" : "approved"
          }
        },
        { "userpoints_action_grant_points" : {
            "user" : [ "vote:user" ],
            "points" : "1",
            "tid" : "1",
            "entity" : [ "node" ],
            "description" : "You retracted a vote down on a question",
            "operation" : "Retract Vote Down",
            "reference" : "[node:nid]",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_user_retracts_a_vote_down_on_an_answer'] = entity_import('rules_config', '{ "rules_user_retracts_a_vote_down_on_an_answer" : {
      "LABEL" : "User retracts a vote down on an answer",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Answers Userpoints" ],
      "REQUIRES" : [ "rules", "voting_rules", "userpoints_rules" ],
      "ON" : [ "voting_rules_delete_node" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "answer" : "answer" } } } },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "operator" : "\\u003C", "value" : "0" } },
        { "NOT data_is" : { "data" : [ "vote:user:uid" ], "value" : [ "node:author:uid" ] } },
        { "NOT data_is" : { "data" : [ "node:author:uid" ], "value" : "0" } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "2",
            "tid" : "1",
            "entity" : [ "node:field-answer-question" ],
            "description" : "A user retracted a vote down on your answer",
            "operation" : "Retract Vote Down",
            "reference" : "[node:field-answer-question]",
            "display" : 1,
            "moderate" : "approved"
          }
        },
        { "userpoints_action_grant_points" : {
            "user" : [ "vote:user" ],
            "points" : "1",
            "tid" : "1",
            "entity" : [ "node:field-answer-question" ],
            "description" : "You retracted a vote down on an answer",
            "operation" : "Retract Vote Down",
            "reference" : "[node:field-answer-question]",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_user_retracts_a_vote_up_on_a_question'] = entity_import('rules_config', '{ "rules_user_retracts_a_vote_up_on_a_question" : {
      "LABEL" : "User retracts a vote up on a question",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Answers Userpoints" ],
      "REQUIRES" : [ "rules", "voting_rules", "userpoints_rules" ],
      "ON" : [ "voting_rules_delete_node" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "question" : "question" } }
          }
        },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "operator" : "\\u003E=", "value" : "0" } },
        { "NOT data_is" : { "data" : [ "site:current-user" ], "value" : [ "node:author" ] } },
        { "NOT user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "-5",
            "tid" : "1",
            "entity" : [ "node" ],
            "description" : "A user retracted a vote up on your question",
            "operation" : "Retract Vote Up",
            "reference" : "[node:nid]",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_user_retracts_a_vote_up_on_an_answer'] = entity_import('rules_config', '{ "rules_user_retracts_a_vote_up_on_an_answer" : {
      "LABEL" : "User retracts a vote up on an answer",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Answers Userpoints" ],
      "REQUIRES" : [ "rules", "voting_rules", "userpoints_rules" ],
      "ON" : [ "voting_rules_delete_node" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "answer" : "answer" } } } },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "operator" : "\\u003E", "value" : "0" } },
        { "NOT data_is" : { "data" : [ "vote:user:uid" ], "value" : [ "node:author:uid" ] } },
        { "NOT data_is" : { "data" : [ "node:author:uid" ], "value" : "0" } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "-10",
            "tid" : "1",
            "entity" : [ "node:field-answer-question" ],
            "description" : "A user retracted a vote up on your answer",
            "operation" : "Retract Vote Up",
            "reference" : "[node:field-answer-question]",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_user_selects_a_best_answer'] = entity_import('rules_config', '{ "rules_user_selects_a_best_answer" : {
      "LABEL" : "User selects a best answer",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Answers Userpoints" ],
      "REQUIRES" : [ "rules", "userpoints_rules", "best_answer" ],
      "ON" : [ "best_answer_set" ],
      "IF" : [
        { "NOT user_has_role" : { "account" : [ "answer:author" ], "roles" : { "value" : { "1" : "1" } } } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "answer:author" ],
            "points" : "15",
            "tid" : "1",
            "entity" : [ "question" ],
            "description" : "Your answer has been selected as the best answer",
            "operation" : "Select Best Answer",
            "reference" : "[question:nid]",
            "display" : 1,
            "moderate" : "approved"
          }
        },
        { "userpoints_action_grant_points" : {
            "user" : [ "site:current-user" ],
            "points" : "2",
            "tid" : "1",
            "entity" : [ "question" ],
            "description" : "You selected a best answer",
            "operation" : "Select Best Answer",
            "reference" : "[question:nid]",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_user_unselects_a_prior_best_answer'] = entity_import('rules_config', '{ "rules_user_unselects_a_prior_best_answer" : {
      "LABEL" : "User unselects a prior best answer",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Answers Userpoints" ],
      "REQUIRES" : [ "rules", "userpoints_rules", "best_answer" ],
      "ON" : [ "best_answer_unset" ],
      "IF" : [
        { "NOT user_has_role" : { "account" : [ "answer:author" ], "roles" : { "value" : { "1" : "1" } } } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "answer:author" ],
            "points" : "-15",
            "tid" : "1",
            "entity" : [ "question" ],
            "description" : "Your answer has been unselected as the best answer",
            "operation" : "Retract Best Answer",
            "reference" : "[question:nid]",
            "display" : 1,
            "moderate" : "approved"
          }
        },
        { "userpoints_action_grant_points" : {
            "user" : [ "site:current-user" ],
            "points" : "-2",
            "tid" : "1",
            "entity" : [ "question" ],
            "description" : "You retracted a best answer",
            "operation" : "Retract Best Answer",
            "reference" : "[question:nid]",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_user_votes_down_a_question'] = entity_import('rules_config', '{ "rules_user_votes_down_a_question" : {
      "LABEL" : "User votes down a question",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Answers Userpoints" ],
      "REQUIRES" : [ "rules", "voting_rules", "userpoints_rules" ],
      "ON" : [ "voting_rules_insert_node" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "question" : "question" } }
          }
        },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "operator" : "\\u003C", "value" : "0" } },
        { "NOT data_is" : { "data" : [ "vote:user:uid" ], "value" : [ "node:author:uid" ] } },
        { "NOT data_is" : { "data" : [ "node:author:uid" ], "value" : "0" } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "-2",
            "tid" : "1",
            "entity" : [ "node" ],
            "description" : "A user voted your question down",
            "operation" : "Vote Down",
            "reference" : "[node:nid]",
            "display" : 1,
            "moderate" : "approved"
          }
        },
        { "userpoints_action_grant_points" : {
            "user" : [ "vote:user" ],
            "points" : "-1",
            "tid" : "1",
            "entity" : [ "node" ],
            "description" : "You voted a question down",
            "operation" : "Vote Down",
            "reference" : "[node:nid]",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_user_votes_down_an_answer'] = entity_import('rules_config', '{ "rules_user_votes_down_an_answer" : {
      "LABEL" : "User votes down an answer",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Answers Userpoints" ],
      "REQUIRES" : [ "rules", "voting_rules", "userpoints_rules" ],
      "ON" : [ "voting_rules_insert_node" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "answer" : "answer" } } } },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "operator" : "\\u003C", "value" : "0" } },
        { "NOT data_is" : { "data" : [ "vote:user:uid" ], "value" : [ "node:author:uid" ] } },
        { "NOT data_is" : { "data" : [ "node:author:uid" ], "value" : "0" } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "-2",
            "tid" : "1",
            "entity" : [ "node:field-answer-question" ],
            "description" : "A user voted your answer down",
            "operation" : "Vote Down",
            "reference" : "[node:field-answer-question]",
            "display" : 1,
            "moderate" : "approved"
          }
        },
        { "userpoints_action_grant_points" : {
            "user" : [ "vote:user" ],
            "points" : "-1",
            "tid" : "1",
            "entity" : [ "node:field-answer-question" ],
            "description" : "You voted an answer down",
            "operation" : "Vote Down",
            "reference" : "[node:field-answer-question]",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_user_votes_up_a_question'] = entity_import('rules_config', '{ "rules_user_votes_up_a_question" : {
      "LABEL" : "User votes up a question",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Answers Userpoints" ],
      "REQUIRES" : [ "rules", "voting_rules", "userpoints_rules" ],
      "ON" : [ "voting_rules_insert_node" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "question" : "question" } }
          }
        },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "operator" : "\\u003E=", "value" : "0" } },
        { "NOT data_is" : { "data" : [ "vote:user:uid" ], "value" : [ "node:author:uid" ] } },
        { "NOT data_is" : { "data" : [ "node:author:uid" ], "value" : "0" } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "5",
            "tid" : "1",
            "entity" : [ "node" ],
            "description" : "A user voted your question up",
            "operation" : "Vote Up",
            "reference" : "[node:nid]",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_user_votes_up_an_answer'] = entity_import('rules_config', '{ "rules_user_votes_up_an_answer" : {
      "LABEL" : "User votes up an answer",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "Answers Userpoints" ],
      "REQUIRES" : [ "rules", "voting_rules", "userpoints_rules" ],
      "ON" : [ "voting_rules_insert_node" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "answer" : "answer" } } } },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "operator" : "\\u003E=", "value" : "0" } },
        { "NOT data_is" : { "data" : [ "vote:user:uid" ], "value" : [ "node:author:uid" ] } },
        { "NOT data_is" : { "data" : [ "node:author:uid" ], "value" : "0" } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "10",
            "tid" : "1",
            "entity" : [ "node:field-answer-question" ],
            "description" : "A user voted your answer up",
            "operation" : "Vote Up",
            "reference" : "[node:field-answer-question]",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  return $items;
}
