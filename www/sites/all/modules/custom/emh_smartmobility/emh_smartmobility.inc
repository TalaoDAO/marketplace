<?php

/**
 * @file
 * Code for EMH Smart Mobility custom functions.
 */

/**
 * Get Smart Mobility context.
 *
 * @return bool
 *   Returns TRUE if user is in Smart Mobility mini-website.
 */
function emh_smartmobility_context() {
  global $base_url;

  return ($base_url == variable_get('emh_smartmobility_base_url', 'http://smartmob.box.local') || arg(0) == EMH_SMARTMOBILITY_HOMEPAGE_ALIAS);
}
