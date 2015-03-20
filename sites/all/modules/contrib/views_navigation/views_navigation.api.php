<?php

/**
 * @file
 * Describe hooks provided by the Views navigation module.
 */

/**
 * Alter Views navigation links.
 */
function hook_views_navigation_navigation_links_alter(&$links, $cid, $pos) {
  $links['back']['title'] = 'Random text';
}

/**
 * Alter the Views navigation query string (GET parameters).
 */
function hook_views_navigation_query_string_alter(&$query, $index, $view) {
  $query['my_parameter'] = 'my value';
}

/**
 * Alter the query and the related view stored by Views navigation.
 */
function hook_views_navigation_stored_query_alter(&$query_to_store, $view) {
  $query_to_store->view->some_property = 'some value';
}
