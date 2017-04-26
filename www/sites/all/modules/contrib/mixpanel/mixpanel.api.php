<?php

/**
 * @file
 * Contains documentation about the Mixpanel module's hooks.
 */

/**
 * @defgroup mixpanel Mixpanel API
 * @{
 * Public API functions and hooks from the Mixpanel module.
 */

/**
 * Alter the default properties that are sent to Mixpanel for a user.
 *
 * This will effect the return value of mixpanel_get_defaults() and will
 * be cached during the length of the current request for the given $account.
 *
 * @param array $properties
 *   The default properties to be sent with every event.
 * @param object $account
 *   The user these defaults are for.
 *
 * @see mixpanel_get_defaults()
 * @see mixpanel_track()
 */
function hook_mixpanel_defaults_alter(&$properties, $account) {
  // Adds a 'user_name' property to all events sent to Mixpanel by default.
  $properties['user_name'] = $account->name;
}

/**
 * Alter the properties to be sent to Mixpanel with this event.
 *
 * @param array $properties
 *   The properties to be sent with every event.
 * @param string $event
 *   The name of the event.
 * @param object $account
 *   The user triggering the event.
 *
 * @see mixpanel_track()
 */
function hook_mixpanel_event_alter(&$properties, $event, $account) {
  // Adds a custom property when ever a specific event is about to be sent
  // to Mixpanel.
  if ($event == 'my-event') {
    $properties['custom'] = 'Value';
  }
}

/**
 * Alter the 'People data' to be sent to Mixpanel for the given user.
 *
 * @param array $data
 *   The values that will be passed to Mixpanel.people.set() on every page.
 * @param object $account
 *   (optional) The user account to generate people data for.
 *
 * @return array
 *   Array of values to pass to Mixpanel.people.set() on every page.
 *
 * @see mixpanel_get_people_defaults()
 */
function hook_mixpanel_people_defaults_alter(&$data, $account) {
  // Adds a 'user_name' property to the 'People data' sent to Mixpanel for a
  // given user.
  $properties['user_name'] = $account->name;
}

/**
 * @}
 */
