<?php

/**
 * @file
 * Sends events related to nodes to Mixpanel.
 */

/**
 * Track a node event.
 */
function _mixpanel_defaults_track_node_event($event, $node) {
  $values = array(
    'node-title' => $node->title,
    'node-id' => $node->nid,
    'node-type' => $node->type,
  );

  if (!empty($node->og_groups)) {
    $values['group-id'] = array_pop(array_values($node->og_groups));
  }

  mixpanel_track("node-$event", $values);
}

/**
 * Implements hook_node_delete().
 */
function mixpanel_defaults_node_delete($node) {
  _mixpanel_defaults_track_node_event('deleted', $node);
}

/**
 * Implements hook_node_insert().
 */
function mixpanel_defaults_node_insert($node) {
  _mixpanel_defaults_track_node_event('created', $node);
}

/**
 * Implements hook_node_update().
 */
function mixpanel_defaults_node_update($node) {
  _mixpanel_defaults_track_node_event('updated', $node);
}

/**
 * Submit function for the search form to let us track searches.
 */
function mixpanel_defaults_search_form_submit($form, $form_state) {
  $keys = isset($form_state['values']['search_block_form']) ? $form_state['values']['search_block_form'] : $form_state['values']['keys'];
  mixpanel_track("search", array('search-string' => $keys));
}
