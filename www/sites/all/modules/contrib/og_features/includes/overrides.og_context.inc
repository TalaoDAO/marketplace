<?php

/**
 * @file
 *   Overrides of functions found in og_context.module
 * 
 * @see http://drupal.org/node/1781218
 */
 
module_load_include('inc', 'og_features', 'includes/overrides.menu');
 
/**
 * Override of og_context()
 */
function og_features_og_context($group_type = 'node', $group = NULL) {
  global $user;
  $context = &drupal_static(__FUNCTION__, FALSE);

  if (empty($group) && !empty($context) && $context['group_type'] == $group_type) {
    return $context;
  }

  if (!empty($group)) {
    // Set the group.
    list($id) = entity_extract_ids($group_type, $group);
    $context = array('group_type' => $group_type, 'gid' => $id);
  }
  // Get context from context handlers.
  elseif ($gid = _og_features_og_context_determine_context($group_type)) {
    $context = array('group_type' => $group_type, 'gid' => $gid);
    if ($user->uid) {
      // Save the group ID in the authenticated user's session.
      $_SESSION['og_context'] = array('group_type' => $group_type, 'gid' => $gid);
    }
  }

  return $context;
}

/**
 * Override of og_context_determine_context()
 */
function _og_features_og_context_determine_context($group_type, $item = NULL) {
  // Enable url and node context handlers by default.
  $defaults = array('url' => -5, 'node' => -4);
  if (!$enabled_providers = array_keys(variable_get("og_context_negotiation_group_context", $defaults))) {
    return;
  }

  if (empty($item)) {
    $item = _og_features_menu_get_item();
  }

  $providers = og_context_negotiation_info();
  foreach ($enabled_providers as $name) {
    if (!in_array($name, array_keys($providers))) {
      continue;
    }
    $provider = $providers[$name];
    $invoke = FALSE;
    if (!empty($provider['menu path'])) {
      foreach ($provider['menu path'] as $path) {
        if (strpos($item['path'], $path) === 0) {
          $invoke = TRUE;
          // Path matches, so we can break.
          break;
        }
      }
    }
    else {
      // Context isn't determined by the menu item.
      $invoke = TRUE;
    }

    $gids = array();
    
    // Change the callback, if needed
    if ($provider['callback'] == 'og_context_handler_node') {
      $provider['callback'] = '_og_features_og_context_handler_node';
    }
    if ($provider['callback'] == 'og_context_handler_url') {
      $provider['callback'] = '_og_features_og_context_handler_url';
    }

    if ($invoke && ($contexts = call_user_func($provider['callback'])) && !empty($contexts[$group_type])) {
      // Check if one of the group IDs already exists in the session, and if
      // so use it.
      $gids = $contexts[$group_type];
      if (!empty($_SESSION['og_context']['group_type']) && $_SESSION['og_context']['group_type'] == $group_type && in_array($_SESSION['og_context']['gid'], $gids)) {
        $gid = $_SESSION['og_context']['gid'];
      }
      else {
        // Grab the first group ID.
        $gid = reset($gids);
      }
      // We found the first context, so we can break.
      break;
    }
  }

  return !empty($gid) ? $gid : FALSE;
}

/**
 * Override of og_context_handler_node()
 */
function _og_features_og_context_handler_node() {
  $node = menu_get_object('node');
  if ($node) {
    return _og_features_group_context_handler_entity('node', $node);
  }

  // The path may not be %node, but in fact is a ctools-context, so extract the
  // node from it. We check only the 1st position (e.g. node/%/foo).
  $item = _og_features_menu_get_item();
  if (empty($item['map'][1]) || !is_object($item['map'][1]) || !($item['map'][1] instanceof ctools_context)) {
    return;
  }

  // Check the context is a node type. We check only path similar to node/%/foo
  // and don't traverse over the whole arguments, as it might be a page manager
  // page passing multiple nodes (e.g. some/path/with/%node/%node). Implementing
  // modules wanting to handle the above example, should implement their own
  // context handler.
  $context = clone $item['map'][1];
  if (empty($context->type[0]) || $context->type[0] != 'entity:node') {
    return;
  }
  return _og_features_group_context_handler_entity('node', $context->data);

}

/**
 * Override of og_context_handler_url()
 */
function _og_features_og_context_handler_url() {
  if (!module_exists('entityreference_prepopulate')) {
    return;
  }
  $item = _og_features_menu_get_item();
  if (strpos($item['path'], 'node/add/') !== 0) {
    return;
  }
  if (empty($item['map'][2])) {
    // If we don't have this key in the array, it means the user doesn't have
    // access to create this node.
    return;
  }
  $node_type = str_replace('-', '_', $item['map'][2]);

  if (!$fields = og_get_group_audience_fields('node', $node_type)) {
    return;
  }
  $gids = array();
  foreach ($fields as $field_name => $label) {
    $field = field_info_field($field_name);
    $instance = field_info_instance('node', $field_name, $node_type);
    if ($ids = entityreference_prepopulate_get_values_from_url($field, $instance, TRUE)) {
      $target_type = $field['settings']['target_type'];
      $gids += array($target_type => array());
      $gids[$target_type] = array_merge($gids[$target_type], $ids);
    }
  }
  return $gids;
}

/**
 * Override of _group_context_handler_entity()
 */
function _og_features_group_context_handler_entity($entity_type = 'node', $entity = NULL, $position = 1) {
  $contexts = array();

  if (empty($entity)) {
    $entity = _og_features_menu_get_object($entity_type, $position);
  }

  if (!$entity) {
    return;
  }

  list($id) = entity_extract_ids($entity_type, $entity);
  if (!$id) {
    return;
  }

  // Check if the entity is itself a group.
  if ($group = og_is_group($entity_type, $id)) {
    $contexts[$entity_type][] = $id;
  }
  elseif ($gids = og_get_entity_groups($entity_type, $entity)) {
    $contexts = $gids;
  }

  return $contexts;
}
