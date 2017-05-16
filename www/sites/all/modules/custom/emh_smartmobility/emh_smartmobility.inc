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
  return ((arg(0) == EMH_SMARTMOBILITY_HOMEPAGE) || (arg(1) == variable_get('emh_smartmobility_circle_gid', 1813)));
}
