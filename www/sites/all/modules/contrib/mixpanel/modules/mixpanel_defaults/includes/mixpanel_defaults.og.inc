<?php

/**
 * @file
 * Sends events related to Organic Groups to Mixpanel.
 */

/**
 * Sends an Organic Groups membership event to Mixpanel.
 *
 * @param string $event
 *   The type of event (ex. 'join', 'leave')
 *
 * @param OgMembership $og_membership
 *   The object representing the Organic Groups membership that this event
 *   concerns.
 */
function _mixpanel_defaults_track_og_event($event, OgMembership $og_membership) {
  if ($og_membership->entity_type != 'user') {
    // For simplicity we operate only on membership with user members.
    return;
  }

  if ($og_membership->group_type != 'node') {
    // For simplicity we operate only on membership with node groups.
    return;
  }

  if (!$og_membership->etid) {
    // Don't capture membership of anonymous user, that might be caused
    // when using Devel generate.
    return;
  }

  $group_node = node_load($og_membership->gid);

  mixpanel_track("group-$event", array("group-id" => $og_membership->gid, "group-name" => $group_node->title), user_load($og_membership->etid));
}

/**
 * Implements hook_og_membership_insert().
 */
function mixpanel_defaults_og_membership_insert(OgMembership $og_membership) {
  _mixpanel_defaults_track_og_event('join', $og_membership);
}

/**
 * Implements hook_og_membership_delete().
 */
function mixpanel_defaults_og_membership_delete(OgMembership $og_membership) {
  _mixpanel_defaults_track_og_event('left', $og_membership);
}
