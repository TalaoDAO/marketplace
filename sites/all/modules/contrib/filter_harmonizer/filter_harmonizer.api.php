<?php
/**
 * @file
 * This file contains no working PHP code; it's here to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * Allow other modules to change the filling-out of the exposed filter form.
 *
 * @param array $data
 *   An array of 5 elements, as follows:
 *
 * array $form
 *   The form.
 * array $form_state
 *   The form state.
 * object $contextual_filter
 *   The contextual filter handler.
 * object $regular_filter
 *   The regular (exposed) filter handler.
 * array $filter_values
 *   The filter value(s) set on the exposed filter.
 */
function hook_filter_harmonizer_set_alter(&$data) {
  // See plugins/filter_harmonizer_geofield.inc for an example.
}

/**
 * Allow modules to alter the meaning of 'empty' for regular filter values.
 *
 * By default, the number 0 and a sequence of one or more spaces are not
 * considered empty for any filter, but other modules may override this by
 * implementing this hook.
 *
 * @param mixed $value
 *   the value that is to be tested on "emptiness"
 * @param bool $is_empty
 *   set this according to whether $value is considered empty or not
 * @param object $filter_handler
 *   the associated Views exposed filter handler, if needed
 */
function hook_filter_harmonizer_filter_is_empty($value, &$is_empty, $filter_handler) {
}
