<?php
/**
 * @file
 * ft_config_pages.features.inc
 */

/**
 * Implements hook_default_config_pages_type().
 */
function ft_config_pages_default_config_pages_type() {
  $items = array();
  $items['emindhub'] = entity_import('config_pages_type', '{
    "type" : "emindhub",
    "label" : "eMindHub",
    "weight" : "0",
    "data" : {
      "menu" : { "path" : "admin\\/config\\/emindhub", "type" : 6 },
      "context" : { "group" : {
          "config_pages:language" : "config_pages:language",
          "config_pages:host" : 0,
          "config_pages:domain" : 0
        }
      }
    },
    "emh_earnings" : 0
  }');
  $items['footer'] = entity_import('config_pages_type', '{
    "type" : "footer",
    "label" : "Footer",
    "weight" : "0",
    "data" : {
      "menu" : { "path" : "admin\\/config\\/emindhub\\/footer", "type" : "132" },
      "context" : { "group" : {
          "config_pages:language" : "config_pages:language",
          "config_pages:host" : 0,
          "config_pages:domain" : 0
        }
      }
    },
    "emh_earnings" : 0
  }');
  $items['homepage'] = entity_import('config_pages_type', '{
    "type" : "homepage",
    "label" : "Homepage",
    "weight" : "0",
    "data" : {
      "menu" : { "path" : "admin\\/config\\/emindhub\\/homepage", "type" : "132" },
      "context" : { "group" : {
          "config_pages:language" : "config_pages:language",
          "config_pages:host" : 0,
          "config_pages:domain" : 0
        }
      }
    },
    "emh_earnings" : 0
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function ft_config_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
