<?php

/**
 * @file
 * Definition of contextual_range_filter_handler_argument_string_range.
 */

/**
 * Argument handler to implement string range arguments.
 *
 * @ingroup views_argument_handlers
 */
class contextual_range_filter_handler_argument_string_range extends views_handler_argument_string {

  /**
   * Define the option.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['not'] = array('default' => FALSE, 'bool' => TRUE);
    return $options;
  }

  /**
   * Create the options form.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['description']['#markup'] = t('Contextual string range filter values are taken from the URL.');

    $form['more']['#collapsed'] = FALSE;

    $form['break_phrase']['#title'] = t('Allow multiple alphabetic ranges');
    $form['break_phrase']['#description'] = t('If selected, multiple ranges may be specified by stringing them together with plus signs. Example: <strong>a--f+q--y</strong>');

    $form['not'] = array(
      '#type' => 'checkbox',
      '#title' => t('Exclude'),
      '#description' => t('Negate the range. If selected, output matching the specified range(s) will be excluded, rather than included.'),
      '#default_value' => !empty($this->options['not']),
      '#fieldset' => 'more',
    );
  }

  /**
   * Build the query.
   */
  public function query($group_by = FALSE) {
    $argument = $this->argument;
    if (!empty($this->options['transform_dash'])) {
      $argument = strtr($argument, '-', ' ');
    }
    if (!empty($this->options['break_phrase'])) {
      views_break_phrase_string($argument, $this);
    }
    else {
      $this->value = array($argument);
    }
    $this->ensure_my_table();

    if (!empty($this->definition['many to one'])) {
      if (!empty($this->options['glossary'])) {
        $this->helper->formula = TRUE;
      }
      $this->helper->ensure_my_table();
      $this->helper->add_filter();
      return;
    }

    if (empty($this->options['glossary'])) {
      $field = "$this->table_alias.$this->real_field";
    }
    else {
      $field = $this->get_formula();
    }
    contextual_range_filter_build_range_query($this, $field);
  }
}
