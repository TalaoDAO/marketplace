<?php

/**
 * @file
 * Contains the numeric argument range validator plugin.
 */

/**
 * Validate whether an argument is a number or a numeric range or not.
 *
 * A valid range is either a valid single number or a range of the form:
 *  xfrom--xto, xfrom-- or --xto
 * Instead of the double-hyphen a colon may be used.
 *
 * @ingroup views_argument_validate_plugins
 */
class contextual_range_filter_plugin_argument_validate_numeric_range extends views_plugin_argument_validate {

  /**
   * Validate the argument.
   */
  public function validate_argument($argument) {
    // The character '+' may arrive as space.
    $ranges = preg_split('/[+ ]/', $argument);

    foreach ($ranges as $range) {
      $minmax = explode(CONTEXTUAL_RANGE_FILTER_SEPARATOR1, $range);
      if (count($minmax) < 2) {
        $minmax = explode(CONTEXTUAL_RANGE_FILTER_SEPARATOR2, $range);
      }
      if (count($minmax) < 2) {
        // Not a range but single value. Must be numeric.
        if (is_numeric($range)) {
          continue;
        }
        return FALSE;
      }
      if (!(
        (is_numeric($minmax[0]) && is_numeric($minmax[1]) && $minmax[0] <= $minmax[1]) ||
        (empty($minmax[0]) && is_numeric($minmax[1])) ||
        (empty($minmax[1]) && is_numeric($minmax[0])))) {
        return FALSE;
      }
    }
    return TRUE;
  }
}
