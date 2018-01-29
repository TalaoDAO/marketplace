<?php
/**
 * @file additional functions.
 */

/**
 * Test if tags already exist into a field node.
 *
 * @param unknown $node
 * @param unknown $val
 *
 * @return boolean
 */
function emh_opencalais_term_is_on_field($tab, $val) {
  foreach ($tab as $key => $value) {
    foreach ($value as $key_tid => $value_tid) {
      if (!strcmp($val, $value_tid)) {
        return TRUE;
      }
    }
  }
  return FALSE;
}