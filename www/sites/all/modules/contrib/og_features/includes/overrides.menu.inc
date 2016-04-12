<?php

/**
 * @file
 *   Overrides of functions found in Drupal's menu.inc
 * 
 * @see http://drupal.org/node/1781218
 */
 
/**
 * Override of menu_get_item()
 */
function _og_features_menu_get_item($path = NULL, $router_item = NULL) {
  $router_items = &drupal_static(__FUNCTION__);
  if (!isset($path)) {
    $path = $_GET['q'];
  }
  if (isset($router_item)) {
    $router_items[$path] = $router_item;
  }
  if (!isset($router_items[$path])) {
    // Rebuild if we know it's needed, or if the menu masks are missing which
    // occurs rarely, likely due to a race condition of multiple rebuilds.
    if (variable_get('menu_rebuild_needed', FALSE) || !variable_get('menu_masks', array())) {
      menu_rebuild();
    }
    $original_map = arg(NULL, $path);

    $parts = array_slice($original_map, 0, MENU_MAX_PARTS);
    $ancestors = menu_get_ancestors($parts);
    $router_item = db_query_range('SELECT * FROM {menu_router} WHERE path IN (:ancestors) ORDER BY fit DESC', 0, 1, array(':ancestors' => $ancestors))->fetchAssoc();

    if ($router_item) {
      // Allow modules to alter the router item before it is translated and
      // checked for access.
      drupal_alter('menu_get_item', $router_item, $path, $original_map);

      $map = _og_features_menu_translate($router_item, $original_map);
      $router_item['original_map'] = $original_map;
      if ($map === FALSE) {
        $router_items[$path] = FALSE;
        return FALSE;
      }
      $router_item['map'] = $map;
      $router_item['page_arguments'] = array_merge(menu_unserialize($router_item['page_arguments'], $map), array_slice($map, $router_item['number_parts']));
      $router_item['theme_arguments'] = array_merge(menu_unserialize($router_item['theme_arguments'], $map), array_slice($map, $router_item['number_parts']));
    }
    $router_items[$path] = $router_item;
  }
  return $router_items[$path];
}

/**
 * Override of _menu_translate()
 */
function _og_features_menu_translate(&$router_item, $map, $to_arg = FALSE) {
  if ($to_arg && !empty($router_item['to_arg_functions'])) {
    // Fill in missing path elements, such as the current uid.
    _menu_link_map_translate($map, $router_item['to_arg_functions']);
  }
  // The $path_map saves the pieces of the path as strings, while elements in
  // $map may be replaced with loaded objects.
  $path_map = $map;
  if (!empty($router_item['load_functions']) && !_menu_load_objects($router_item, $map)) {
    // An error occurred loading an object.
    $router_item['access'] = FALSE;
    return FALSE;
  }

  // Generate the link path for the page request or local tasks.
  $link_map = explode('/', $router_item['path']);
  if (isset($router_item['tab_root'])) {
    $tab_root_map = explode('/', $router_item['tab_root']);
  }
  if (isset($router_item['tab_parent'])) {
    $tab_parent_map = explode('/', $router_item['tab_parent']);
  }
  for ($i = 0; $i < $router_item['number_parts']; $i++) {
    if ($link_map[$i] == '%') {
      $link_map[$i] = $path_map[$i];
    }
    if (isset($tab_root_map[$i]) && $tab_root_map[$i] == '%') {
      $tab_root_map[$i] = $path_map[$i];
    }
    if (isset($tab_parent_map[$i]) && $tab_parent_map[$i] == '%') {
      $tab_parent_map[$i] = $path_map[$i];
    }
  }

  return $map;
}

/**
 * Override of menu_get_object()
 */
function _og_features_menu_get_object($type = 'node', $position = 1, $path = NULL) {
  $router_item = _og_features_menu_get_item($path);
  if (isset($router_item['load_functions'][$position]) && !empty($router_item['map'][$position]) && $router_item['load_functions'][$position] == $type . '_load') {
    return $router_item['map'][$position];
  }
}
