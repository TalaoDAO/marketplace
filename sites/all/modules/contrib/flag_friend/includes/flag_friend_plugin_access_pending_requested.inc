<?php

/**
 * @file
 * Definition of flag_friend_views_plugin_access_pending_requested.
 */

/**
 * @see hook_views_plugins()
 */

class flag_friend_plugin_access_pending_requested extends views_plugin_access {
  function access($account) {
    return flag_friend_views_access();
  }

  function get_access_callback() {
    return array('flag_friend_views_access');
  }
}