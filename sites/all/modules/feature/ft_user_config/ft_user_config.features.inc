<?php
/**
 * @file
 * ft_user_config.features.inc
 */

/**
 * Implements hook_default_profile2_type().
 */
function ft_user_config_default_profile2_type() {
  $items = array();
  $items['business'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "business",
    "label" : "Business",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 0 }
  }');
  $items['expert'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "expert",
    "label" : "Expert",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 0 }
  }');
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "main",
    "label" : "Main profile",
    "weight" : "0",
    "data" : { "registration" : true, "use_page" : true }
  }');
  return $items;
}
