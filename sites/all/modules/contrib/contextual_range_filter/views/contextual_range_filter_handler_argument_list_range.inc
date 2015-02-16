<?php

/**
 * @file
 * Definition of contextual_filter_range_handler_argument_list_range.
 */

/**
 * Argument handler for arguments that are list ranges.
 *
 * @ingroup views_argument_handlers
 */
class contextual_range_filter_handler_argument_list_range extends views_handler_argument_field_list {

  /**
   * Initialize the view.
   */
  public function init(&$view, &$options) {
    parent::init($view, $options);
  }

  /**
   * Create the options form.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['description']['#markup'] = t('Contextual list range filter values are taken from the URL.');

    $form['break_phrase']['#title'] = t('Allow multiple list ranges');
    $form['break_phrase']['#description'] = t('If selected, multiple list ranges may be specified by stringing them together with plus signs. Use either the human-readable names or the list keys, which are usually integers.<br/>Example: <strong>infant--teenager+middele-aged--retiree</strong>.');
  }

  /**
   * Help build the query.
   */
  public function query($group_by = FALSE) {

    // From "Allow multple ranges" checkbox.
    if (!empty($this->options['break_phrase'])) {
      $this->views_break_phrase_range($this->argument);
    }
    else {
      $this->value = array($this->argument);
    }
    if ($this->value === FALSE) {
      return;
    }
    $this->ensure_my_table();
    // From "Exclude:" tickbox.
    $is_not = !empty($this->options['not']);

    // All WHERE clauses are OR-ed or AND-ed together in the same group.
    // Note: NOT (a OR b OR c) == (NOT a) AND (NOT b) AND (NOT c).
    $group = $this->query->set_where_group($is_not ? 'AND' : 'OR');

    // E.g. field_datafield_price.field_price_value.
    $field = "$this->table_alias.$this->real_field";
    $operator = $is_not ? 'NOT IN' : 'IN';
    $null_check = $is_not ? "OR $field IS NULL" : '';

    foreach ($this->value as $range) {
      $placeholder = $this->placeholder();
      $range_values = contextual_range_filter_explode_list_range($range, $this->allowed_values);
      if ($range_values) {
        $this->query->add_where_expression($group, "$field $operator ($placeholder) $null_check", array($placeholder => $range_values));
      }
    }
  }

  /**
   * Break xfrom--xto+yfrom--yto+zfrom--zto into an array or ranges.
   *
   * @param string $str
   *   The string to parse.
   */
  public function views_break_phrase_range($str) {
    if (empty($str)) {
      return;
    }
    $this->value = preg_split('/[+ ]/', $str);
    $this->operator = 'or';
    // Keep an 'error' value if invalid ranges were given.
    // A single non-empty value is ok, but a plus sign without values is not.
    if (count($this->value) > 1 && (empty($this->value[0]) || empty($this->value[1]))) {
      // Used in $this->title().
      $this->value = FALSE;
    }
  }
}
