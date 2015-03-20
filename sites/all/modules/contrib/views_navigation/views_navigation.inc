<?php

// TODO Set our own cache bin.
define('VIEWS_NAVIGATION_CACHE_BIN', 'cache');
define('VIEWS_NAVIGATION_POSITION_PARAMETER', 'position');
define('VIEWS_NAVIGATION_CACHE_ID_PARAMETER', 'list');

/**
 * Get a view query from cache.
 */
function views_navigation_get_cached_query($cid) {
  $cache = cache_get('query-' . $cid, VIEWS_NAVIGATION_CACHE_BIN);
  if ($cache && (_views_navigation_query_is_supported($cache->data))) {
    return $cache->data;
  }
}

/**
 * Get a view result from cache.
 */
function views_navigation_get_cached_result($cid) {
  $cache = cache_get('result-' . $cid, VIEWS_NAVIGATION_CACHE_BIN);
  return $cache ? $cache->data : FALSE;
}

/**
 * Store a view query in cache.
 * Return the cid or FALSE if the query is not stored.
 */
function views_navigation_store_query($view) {

  if (_views_navigation_query_is_supported($view->query)) {

    $query_to_store = clone($view->query);
    $view_to_store = clone($query_to_store->view);

    // Handle the case when there is no pager.
    if (!isset($view_to_store->total_rows)) {
      $view_to_store->total_rows = count($view_to_store->result);
    }

    // If there is zero or one result, we do nothing.
    if ($view_to_store->total_rows < 2) {
      return FALSE;
    }

    // Store the views navigation option value.
    $view_to_store->views_navigation = $view->display_handler->get_option('views_navigation');

    // Store the cycling option value.
    $view_to_store->cycle = $view->display_handler->get_option('views_navigation_cycle');

    // Store the SEO first option value.
    $view_to_store->seo_first = $view->display_handler->get_option('views_navigation_seo_first');

    // Store the back destination if needed.
    if ($view->display_handler->get_option('views_navigation_back')) {
      $destination = drupal_get_destination();
      $view_to_store->back_destination = urldecode(reset($destination));
      // Store the view's title if needed.
      if ($view->display_handler->get_option('views_navigation_title')) {
        $view_to_store->back_title = $view_to_store->get_title();
      }
    }

    // Remove useless properties and query limit. This is the not easy part.
    unset($query_to_store->display);
    unset($query_to_store->header);
    unset($query_to_store->pager);
    $plugin = _views_navigation_get_query_plugin($query_to_store);
    switch ($plugin) {
      case 'default' :
        unset($query_to_store->limit);
        break;
      case 'search_api' :
        unset($query_to_store->view);
        $query_to_store->set_limit(NULL);
        $query_to_store->set_offset(0);
        break;
    }
    foreach ($view_to_store as $key => $value) {
      if (!in_array($key, array(
        'base_database',
        'name',
        'total_rows',
        'views_navigation',
        'cycle',
        'seo_first',
        'back_destination',
        'back_title',
        'display_handler',
      ))) {
        unset($view_to_store->$key);
      }
    }

    $query_to_store->view = $view_to_store;

    // Allow modules to alter the stored info.
    drupal_alter('views_navigation_stored_query', $query_to_store, $view);

    $cid = views_navigation_get_query_cid($query_to_store);
    // The query may be stored already.
    if (!views_navigation_get_cached_query($cid)) {
      // We need to store the query as long as the user navigates across the
      // result set. One day should be far enough.
      // @see views_navigation_get_links()
      cache_set('query-' . $cid, $query_to_store, VIEWS_NAVIGATION_CACHE_BIN, REQUEST_TIME + 86400);
    }
    return $cid;
  }
  return FALSE;
}

/**
 * Get the unique cid corresponding to a view query.
 */
function views_navigation_get_query_cid($query) {
  return drupal_hash_base64(serialize($query));
}

/**
 * Redirect to the next or previous node.
 */
function views_navigation_router($cid, $pos) {
  if (list($path, $options) = _views_navigation_get_data($cid, $pos)) {
    drupal_goto($path, $options);
  }
  // Something went wrong.
  watchdog('views_navigation', t('Could not find the requested page.'), func_get_args(), WATCHDOG_ERROR);
  return t("Sorry, could not find the requested page.");
}

/**
 * Get the result of a query, as an array of nids keyed by position.
 */
function views_navigation_get_result($cid) {
  if (!$result = views_navigation_get_cached_result($cid)) {
    if ($query = views_navigation_get_cached_query($cid)) {
      $result = array();
      $plugin = _views_navigation_get_query_plugin($query);
      views_module_include('views');
      switch ($plugin) {
        case 'default' :
          $real_query = $query->query();
          $rows = $real_query->execute();
          foreach ($rows as $pos => $row) {
            $result[$pos] = $row->nid;
          }
          break;
        case 'search_api' :
          $real_query = $query->getSearchApiQuery();
          $real_query->range(0, NULL);
          $response = $real_query->execute();
          $rows = $response['results'];
          $pos = 0;
          foreach ($rows as $row) {
            $result[$pos] = $row['id'];
            $pos++;
          }
          break;
      }
      // We currently store the result set during one hour. This is better than
      // never or for ever.
      //TODO Use the view's cache settings.
      cache_set('result-' . $cid, $result, VIEWS_NAVIGATION_CACHE_BIN, REQUEST_TIME + 3600);
    }
  }
  return $result;
}

/**
 * Build and render the previous/next links for the node being viewed.
 */
function views_navigation_get_links($view_mode = 'full') {

  // Ensure we can show links.
  $cid = isset($_GET[VIEWS_NAVIGATION_CACHE_ID_PARAMETER]) ? $_GET[VIEWS_NAVIGATION_CACHE_ID_PARAMETER] : NULL;
  $pos = isset($_GET[VIEWS_NAVIGATION_POSITION_PARAMETER]) ? $_GET[VIEWS_NAVIGATION_POSITION_PARAMETER] : NULL;
  if (!isset($cid) || !isset($pos) || $view_mode != 'full') {
    return FALSE;
  }
  $query = views_navigation_get_cached_query($cid);
  if (!$query) {
    return FALSE;
  }

  $data = array();
  if ($query->view->views_navigation && ($query->view->cycle || $pos > 0)) {
    $data['previous'] = array(
      'default_title' => t('Previous'),
      'pos' => $pos - 1,
    );
  }
  if (isset($query->view->back_destination)) {
    $data['back'] = array(
      'default_title' => isset($query->view->back_title) ? t('Back to %title', array('%title' => $query->view->back_title)) : t('Back'),
      'pos' => 'back',
    );
  }
  if ($query->view->views_navigation && ($query->view->cycle || $pos < $query->view->total_rows - 1)) {
    $data['next'] = array(
      'default_title' => t('Next'),
      'pos' => $pos + 1,
    );
  }
  $links = array();
  foreach ($data as $key => $value) {
    if ($query->view->seo_first) {
      list($path, $options, $text) = _views_navigation_get_data($cid, $value['pos'], TRUE);
      $links[$key] = $options;
      $links[$key]['title'] = isset($text) ? $text : $value['default_title'];
      $links[$key]['href'] = $path;
    }
    else {
      $links[$key]['title'] = $value['default_title'];
      $links[$key]['href'] = 'views_navigation/' . $cid . '/' . $value['pos'];
      $links[$key]['attributes']['rel'] = 'nofollow';
    }
    $links[$key]['html'] = TRUE;
    $links[$key]['attributes']['class'] = array('views-navigation-' . $key);
  }

  // Allow modules to alter the navigation links.
  drupal_alter('views_navigation_navigation_links', $links, $cid, $pos);

  return array(
    '#theme' => 'links',
    '#links' => $links,
  );
}

/**
 * Add the query parameters to append to the node url.
 * The view must have been executed already.
 */
function _views_navigation_build_query($nid, $view, $query = array()) {
  if (isset($view->views_navigation_cid)) {
    //TODO handle the case when the nid is in the result more than one
    // time.
    $nids = array();
    $plugin = _views_navigation_get_query_plugin($view->query);
    foreach ($view->result as $result) {
      switch ($plugin) {
        case 'default' :
          $nids[] .= $result->nid;
          break;
        case 'search_api' :
          $node = is_object($result->entity) ? $result->entity : node_load($result->entity);
          $nids[] .= $node->nid;
          break;
      }

    }
    $index = array_search($nid, $nids);
    //Take care of pagination. Index of first item on second page must be
    // items_per_page, not 0.
    $pager = $view->query->pager;
    if ($pager->use_pager()) {
      $index += ($pager->get_items_per_page() * $pager->get_current_page());
    }

    $query = array_merge($query, array(
      VIEWS_NAVIGATION_POSITION_PARAMETER => $index,
      VIEWS_NAVIGATION_CACHE_ID_PARAMETER => $view->views_navigation_cid,
    ));
  }

  // Allow modules to alter the query string.
  drupal_alter('views_navigation_query_string', $query, $index, $view);

  return $query;
}

/**
 * Used when the view handler needs an already built url. This is the case when
 * it will be passed to parse_url() as in views_handler_field::render_as_link().
 */
function _views_navigation_build_url($nid, $view, $options = array('absolute' => TRUE)) {
  $options['query'] = _views_navigation_build_query($nid, $view, isset($options['query']) ? $options['query'] : array());
  return url("node/$nid", $options);
}

function _views_navigation_query_is_supported($query) {
  $plugin = _views_navigation_get_query_plugin($query);
  return isset($plugin);
}

function _views_navigation_get_query_plugin($query) {
  // ATM we only handle the default and Search API views queries.
  if (is_a($query, 'views_plugin_query_default')) {
    return 'default';
  }
  if (is_a($query, 'SearchApiViewsQuery')) {
    return 'search_api';
  }
}

/**
 * Based on EntityFieldHandlerHelper::render_entity_link().
 */
function _views_navigation_render_entity_link($handler, $value, $values) {
  $render = EntityFieldHandlerHelper::render_single_value($handler, $value, $values);
  if (!$handler->options['link_to_entity']) {
    return $render;
  }
  $entity = $handler->get_value($values, 'entity object');
  if (is_object($entity) && ($url = entity_uri($handler->entity_type, $entity))) {
    if (isset($entity->nid)) {
      $url['options']['query'] = _views_navigation_build_query($entity->nid, $handler->view);
    }
    return l($render, $url['path'], array('html' => TRUE) + $url['options']);
  }
  return $render;
}

/**
 * Return an array containing $path and $options, as needed by url() and
 * drupal_goto() functions.
 * If $get_title is set, the third value will be the node's title, else NULL.
 */
function _views_navigation_get_data($cid, $pos, $get_title = FALSE) {
  if ($pos === 'back') {
    if ($query = views_navigation_get_cached_query($cid)) {
      if (isset($query->view->back_destination)) {
        $options = drupal_parse_url($query->view->back_destination);
        return array(
          $options['path'],
          $options,
          NULL,
        );
      }
    }
  }
  else if ($result = views_navigation_get_result($cid)) {
    // Manage array ends, cycling behavior.
    $max_index = count($result) - 1;
    $pos = ($pos > $max_index) ? 0 : (($pos < 0) ? $max_index : $pos);

    if ($nid = $result[$pos]) {

      $params = array(
        VIEWS_NAVIGATION_POSITION_PARAMETER => $pos,
        VIEWS_NAVIGATION_CACHE_ID_PARAMETER => $cid,
      );
      $return = array(
        'node/' . $nid,
        array('query' => $params),
      );
      if ($get_title && $node = node_load($nid)) {
        $return[] = $node->title;
      }
      else {
        $return[] = NULL;
      }
      return $return;
    }
  }
}
