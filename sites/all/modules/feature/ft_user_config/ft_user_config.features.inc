<?php
/**
 * @file
 * ft_user_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ft_user_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
