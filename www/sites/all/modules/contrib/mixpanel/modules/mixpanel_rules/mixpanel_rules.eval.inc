<?php

/**
 * @file
 * Contains all the Rules callback functions.
 */

/**
 * Callback for executing the 'mixpanel_rules_track' action.
 *
 * This takes a variable number of $prop_name_N and $prop_value_N arguments.
 *
 * @param string $event
 *   The name of the Mixpanel event to send.
 * @param object $account
 *   The user object that will be tracked as triggering the event.
 * @param string $prop_name_N
 *   The name of the Nth property.
 * @param string $prop_value_N
 *   The value of the Nth property.
 * @param array $settings
 *   The actions configuration settings.
 * @param RulesState $state
 *   The current state.
 * @param RulesPlugin $plugin
 *   The current plugin.
 */
function mixpanel_rules_track() {
  $args = func_get_args();

  // Pull off all the static arguments.
  $event = array_shift($args);
  $account = array_shift($args);

  // Use what remains to build the actual properties list.
  $properties = array();
  for ($i = 1; $i <= MIXPANEL_RULES_PROPERTIES_MAX; $i++) {
    $name = trim(array_shift($args));
    $value = array_shift($args);
    if (!empty($name)) {
      $properties[$name] = trim($value);
    }
  }

  mixpanel_track($event, $properties, $account);
}
