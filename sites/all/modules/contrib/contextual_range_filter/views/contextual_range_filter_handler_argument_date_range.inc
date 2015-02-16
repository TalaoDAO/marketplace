<?php

/**
 * @file
 * Definition of contextual_filter_range_handler_argument_numeric_range.
 */

/**
 * Argument handler for arguments that are date ranges.
 *
 * @ingroup views_argument_handlers
 */
class contextual_range_filter_handler_argument_date_range extends views_handler_argument_date {

  /**
   * Constructor implementation.
   */
  public function construct() {
    parent::construct();
  }

  /**
   * Create the option definition.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['relative_dates'] = array('default' => TRUE);
    $options['break_phrase'] = array('default' => FALSE);
    $options['not'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Create the options form.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['description']['#markup'] = t('Contextual date range filter values are taken from the URL.');

    $form['more']['#collapsed'] = FALSE;

    $form['relative_dates'] = array(
      '#type' => 'checkbox',
      '#title' => t('Allow relative date ranges'),
      '#description' => t('If ticked, offsets from the current date may be specified.<br/>Example: <strong>2 weeks ago--yesterday"</strong>'),
      '#default_value' => $this->options['relative_dates'],
      '#fieldset' => 'more',
    );
    // Allow passing multiple values (ranges).
    $form['break_phrase'] = array(
      '#type' => 'checkbox',
      '#title' => t('Allow multiple date ranges'),
      '#description' => t('If ticked, multiple ranges may be specified by stringing them together with plus signs.<br/>Example: <strong>19990101--20051231+20130701--20140630</strong>'),
      '#default_value' => $this->options['break_phrase'],
      '#fieldset' => 'more',
    );

    $form['not'] = array(
      '#type' => 'checkbox',
      '#title' => t('Exclude'),
      '#description' => t('Negate the range. If selected, output matching the specified date range(s) will be excluded, rather than included.'),
      '#default_value' => !empty($this->options['not']),
      '#fieldset' => 'more',
    );
  }

  /**
   * Title override.
   *
   * Required because of range version of views_break_phrase() in this function.
   */
  public function title() {
    if (!$this->argument) {
      return !empty($this->definition['empty field name']) ? $this->definition['empty field name'] : t('Uncategorized');
    }
    if (!empty($this->options['break_phrase'])) {
      $this->views_break_phrase_range($this->argument);
    }
    else {
      $this->value = array($this->argument);
      $this->operator = 'or';
    }
    if ($this->value === FALSE) {
      return !empty($this->definition['invalid input']) ? $this->definition['invalid input'] : t('Invalid input');
    }
    if (empty($this->value)) {
      return !empty($this->definition['empty field name']) ? $this->definition['empty field name'] : t('Uncategorized');
    }
    return implode($this->operator == 'or' ? ' + ' : ', ', $this->value);
  }

  /**
   * Prepare the range query WHERE-clause.
   */
  public function query($group_by = FALSE) {
    $this->ensure_my_table();

    if (!empty($this->options['break_phrase'])) {
      // From "Allow multple ranges" checkbox.
      $this->views_break_phrase_range($this->argument);
    }
    else {
      $this->value = array($this->argument);
    }
    $this->set_formula(NULL);
    $range_conversion = empty($this->options['relative_dates']) ? NULL : array($this, 'convert_relative_date_range');
    contextual_range_filter_build_range_query($this, $this->get_formula(), $range_conversion);
  }

  /**
   * Converts relative date range, "six months ago--now" to absolute date range.
   *
   * The format used for the absolute date range is the one set on this handler.
   *
   * @param string $from, start date of the range
   * @param string $to, end date of the range
   *
   * @return array of 2 strings
   */
  public function convert_relative_date_range($from, $to) {
    $format = $this->arg_format;
    if (!empty($from)) {
      $abs_from = strtotime($from);
      $from = empty($abs_from) ? date($format) : date($format, $abs_from);
    }
    if (!empty($to)) {
      $abs_to = strtotime($to);
      $to = empty($abs_to) ? date($format) : date($format, $abs_to);
    }
    return array($from, $to);
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

  /**
   * Sets the SQL formula to use for this contextual filter handler.
   *
   * @param string $offset
   *    The name of a field that holds the timezone offset or NULL.
   *
   * @see views/modules/node/views_handler_argument_dates_various.inc
   */
  private function set_formula($offset = NULL) {
    $field_type = 'int';
    if (!empty($this->definition['is date'])) {
      // Date module field comes in three flavours.
      // Date (default) is stored on the database like: Y-m-d H:i:s
      // Date (ISO format) is stored like so: Y-m-dTH:i:s (T replaces space)
      // Date (Unix timestamp) is stored as an int, e.g., 1389789000
      $this->arg_format = 'Y-m-d H:i:s';
      $field_info = field_info_field($this->definition['field_name']);
      $field_type = ($field_info['type'] == 'datestamp') ? 'int' : 'datetime';
    }
    elseif (isset($this->field)) {
      // Suspect node property. Can only tell heuristically via $this->field...
      switch ($this->field) {

        case 'created_year':
        case 'changed_year':
          $this->arg_format = 'Y';
          $extract_type = 'YEAR';
          break;

        case 'created_year_month':
        case 'changed_year_month':
          $this->format = 'F Y';
          $this->arg_format = 'Ym';
          break;

        case 'created_month':
        case 'changed_month':
          $this->format = 'F';
          $this->arg_format = 'm';
          $extract_type = 'MONTH';
          break;

        case 'created_day':
        case 'changed_day':
          $this->format = 'j';
          $this->arg_format = 'd';
          $extract_type = 'DAY';
          break;

        case 'created_week':
        case 'changed_week':
          $this->arg_format = 'w';
          $extract_type = 'WEEK';
          break;

        // created_fulldate
        // changed_fulldate
        default:
          $this->format = 'F j, Y';
          $this->arg_format = 'Ymd'; // or : 'Ymd H:i:s' ?
      }
    }
    $field = isset($this->real_field) ? $this->real_field : $this->name_field;

    return $this->formula = empty($extract_type)
      ? views_date_sql_format($this->arg_format, "***table***.$field", $field_type, $offset)
      : views_date_sql_extract($extract_type, "***table***.$field", $field_type, $offset);
  }
}
