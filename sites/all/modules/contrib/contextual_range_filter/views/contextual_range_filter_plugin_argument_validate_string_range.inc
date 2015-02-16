<?php

/**
 * @file
 * Contains the alphabetic argument range validator plugin.
 */

/**
 * Validate whether an argument is a string or string range.
 *
 * A valid range is either a valid single string or a range of the form:
 *  from--to, from-- or --to
 *
 * As a signle string is also a valid range, there are few specific checks we
 * can do.
 *
 * @ingroup views_argument_validate_plugins
 */
class contextual_range_filter_plugin_argument_validate_string_range extends views_plugin_argument_validate {

  /**
   * Validate the argument.
   */
  public function validate_argument($argument) {
    return check_plain($argument);
  }
}
