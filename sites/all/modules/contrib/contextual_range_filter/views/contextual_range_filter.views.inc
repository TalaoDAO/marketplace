<?php
/**
 * @file
 * contextual_range_filter_views.inc
 *
 * Defines the Contextual Range Filters plugins and hooks.
 */

/**
 * Implements hook_views_data_alter().
 *
 * Changes argument handlers to corresponding range argument handlers.
 *
 * This function finds all field and property argument handlers.
 */
function contextual_range_filter_views_data_alter(&$data) {

  $numeric_field_names = array_filter(variable_get('contextual_range_filter_numeric_field_names', array()));
  $string_field_names  = array_filter(variable_get('contextual_range_filter_string_field_names', array()));
  $list_field_names    = array_filter(variable_get('contextual_range_filter_list_field_names', array()));
  $date_field_names    = array_filter(variable_get('contextual_range_filter_date_field_names', array()));

  foreach ($data as $table_name => $table_data) {
    foreach ($table_data as $field_name => $field_data) {
      if (isset($field_data['argument']['handler'])) {
        // If listed on the configuration page, switch this argument handler
        // to its corresponding argument RANGE handler.
        $full_name = "$table_name:$field_name";

        if (in_array($full_name, $numeric_field_names)) {
          $data[$table_name][$field_name]['argument']['handler'] = 'contextual_range_filter_handler_argument_numeric_range';
        }
        elseif (in_array($full_name, $string_field_names)) {
          $data[$table_name][$field_name]['argument']['handler'] = 'contextual_range_filter_handler_argument_string_range';
        }
        elseif (in_array($full_name, $list_field_names)) {
          $data[$table_name][$field_name]['argument']['handler'] = 'contextual_range_filter_handler_argument_list_range';
        }
        elseif (in_array($full_name, $date_field_names)) {
          $data[$table_name][$field_name]['argument']['handler'] = 'contextual_range_filter_handler_argument_date_range';
        }
      }
    }
  }
}

/**
 * Implements hook_views_plugins().
 *
 * Defines the Numeric Range contextual filter validator.
 */
function contextual_range_filter_views_plugins() {
  $plugins = array(
    'argument validator' => array(
      'numeric range' => array(
        'title' => t('Numeric or Numeric Range'),
        'handler' => 'contextual_range_filter_plugin_argument_validate_numeric_range',
      ),
      'string range' => array(
        'title' => t('Safe Text or Safe Text Range'),
        'handler' => 'contextual_range_filter_plugin_argument_validate_string_range',
      ),
    ),
  );
  return $plugins;
}

/**
 * Add to the query a WHERE-clause based on the range(s) passed in.
 *
 * @param object $views_handler_argument
 *   The Views handler that holds one or more contextual filter ranges.
 * @param string $field
 *   Name or expression to be used left of the operator in the WHERE clause
 * @param callback/callable $range_converter
 *   Optional function to convert the from--to range, e.g., for relative date
 *   ranges like "-3 months--last week" to be converted to "20140120--20140413".
 */
function contextual_range_filter_build_range_query($views_handler_argument, $field = NULL, $range_converter = NULL) {

  if (!isset($views_handler_argument) || $views_handler_argument->value === FALSE) {
    return;
  }
  if (!isset($field)) {
    // E.g. field_datafield_price.field_price_value.
    $field = "$views_handler_argument->table_alias.$views_handler_argument->real_field";
  }
  // From "Exclude:" tickbox.
  $is_not = !empty($views_handler_argument->options['not']);
  $null_check = $is_not ? "OR $field IS NULL" : '';

  // All WHERE clauses are OR-ed or AND-ed together in the same group.
  // Note: NOT (a OR b OR c) == (NOT a) AND (NOT b) AND (NOT c).
  $group = $views_handler_argument->query->set_where_group($is_not ? 'AND' : 'OR');

  foreach ($views_handler_argument->value as $range) {

    $placeholder = $views_handler_argument->placeholder();

    list($from, $to) = contextual_range_filter_split($range);

    if (is_callable($range_converter)) {
      list($from, $to) = call_user_func($range_converter, $from, $to);
    }

    if ($to === FALSE) {
      // Single value, not a range.
      $operator = $is_not ? '!=' : '=';
      $views_handler_argument->query->add_where_expression($group, "$field $operator $placeholder $null_check", array($placeholder => $range));
    }
    elseif ($from != '' && $to != '') {
      // Range from--to.
      $operator = $is_not ? 'NOT BETWEEN' : 'BETWEEN';
      $placeholder_from = $placeholder;
      $placeholder_to = $views_handler_argument->placeholder();
      $views_handler_argument->query->add_where_expression($group, "$field $operator $placeholder_from AND $placeholder_to $null_check",
        array($placeholder_from => $from, $placeholder_to => $to));
    }
    elseif ($from != '') {
      // Range from--.
      $operator = $is_not ? '<' : '>=';
      $views_handler_argument->query->add_where_expression($group, "$field $operator $placeholder $null_check", array($placeholder => $from));
    }
    elseif ($to != '') {
      // Range --to.
      $operator = $is_not ? '>' : '<=';
      $views_handler_argument->query->add_where_expression($group, "$field $operator $placeholder $null_check", array($placeholder => $to));
    }
  }
}
