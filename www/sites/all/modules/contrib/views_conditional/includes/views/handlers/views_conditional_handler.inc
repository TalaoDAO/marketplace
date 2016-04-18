<?php

/**
 * @file
 * Handles conditionals in Views.  IF xxx THEN yyy...
 */

class ViewsConditionalHandler extends views_handler_field {
  // Conditional operators.
  public $conditions = array(
    1 => 'Equal to',
    2 => 'NOT equal to',
    3 => 'Greater than',
    4 => 'Less than',
    5 => 'Empty',
    6 => 'NOT empty',
    7 => 'Contains',
    8 => 'Does NOT contain',
    9 => 'Length Equal to',
    10 => 'Length NOT equal to',
    11 => 'Length Greater than',
    12 => 'Length Less than',
  );

  /**
   * Set default values for form elements.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['label']['default'] = NULL;

    $options['if'] = array('default' => '');
    $options['condition'] = array('default' => '');
    $options['equalto'] = array('default' => '');
    $options['then'] = array('default' => '');
    $options['or'] = array('default' => '');
    $options['strip_tags'] = array('default' => FALSE);

    return $options;
  }

  /**
   * Views form elements.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['relationship']['#access'] = FALSE;

    // Display all labels weighted less than the current label.
    $fields = array(
      0 => '- ' . t('no field selected') . ' -',
    );
    foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
      // We only use fields up to (not including) this one.
      if ($field == $this->options['id']) {
        break;
      }
      $title = $handler->ui_name();
      $fields[$field] = "[$field] == $title";
    }

    $form['if'] = array(
      '#type' => 'select',
      '#title' => t('If this field...'),
      '#options' => $fields,
      '#default_value' => $this->options['if'],
    );

    $form['condition'] = array(
      '#type' => 'select',
      '#title' => t('Is...'),
      '#options' => $this->conditions,
      '#default_value' => $this->options['condition'],
    );

    $form['equalto'] = array(
      '#type' => 'textfield',
      '#title' => t('This value'),
      '#description' => t('Input a value to compare the field against.  Replacement variables may be used'),
      '#default_value' => $this->options['equalto'],
    );

    $form['then'] = array(
      '#type' => 'textarea',
      '#title' => t('Then output this...'),
      '#description' => t('Input what should be output.  Replacement variables may be used.'),
      '#default_value' => $this->options['then'],
    );

    $form['or'] = array(
      '#type' => 'textarea',
      '#title' => t('Otherwise, output this...'),
      '#description' => t('Input what should be output if the above conditions do NOT evaluate to true.'),
      '#default_value' => $this->options['or'],
    );

    $form['strip_tags'] = array(
      '#type' => 'checkbox',
      '#title' => t('Strip html tags from the output'),
      '#default_value' => $this->options['strip_tags'],
    );


    $form['replacements'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#title' => t('Replacement Variables'),
    );

    $form['replacements']['notice'] = array(
      '#markup' => 'You may use any of these replacement variables in the "equals" or the "output" text fields.  If you wish to use brackets ([ or ]), replace them with %5D or %5E.',
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );

    $items = array(
      'DATE_UNIX => Current date / time, in UNIX timestamp format (' . REQUEST_TIME . ')',
      'DATE_STAMP => Current date / time, in standard format (' . format_date(REQUEST_TIME) . ')',
    );
    foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
      // We only use fields up to (not including) this one.
      if ($field == $this->options['id']) {
        break;
      }
      $title = $handler->ui_name();
      $items[] = "[$field] == $title";
    }

    $form['replacements']['variables'] = array(
      '#markup' => theme('item_list', array('items' => $items)),
    );
  }

  /**
   * Check that everything is in order.
   */
  public function options_validate(&$form, &$form_state) {
    $values = &$form_state['values']['options'];
    if (empty($values['if']) || empty($values['condition']) || empty($values['equalto'])) {
      if (empty($values['if'])) {
        form_set_error('if', t("Please specify a valid field to run a condition on."));
      }
      if (empty($values['condition'])) {
        form_set_error('condition', t("Please select a conditional operator."));
      }
      // We using there is_numeric because values '0', '0.0' counting as empty in PHP language.
      if (empty($values['equalto']) && !in_array($values['condition'], array(5, 6)) && !is_numeric($values['equalto'])) {
        form_set_error('condition', t("Please specify something to compare with."));
      }
    }
  }

  /**
   * Defines summary text for Fields category in Views.
   */
  public function admin_summary() {
    // We using there is_numeric because values '0', '0.0' counting as empty in PHP language.
    if (!empty($this->options['if']) && !empty($this->options['condition']) && (!empty($this->options['equalto']) || in_array($this->options['condition'], array(5, 6)) || is_numeric($this->options['equalto'])) && trim($this->options['then']) != '') {
      return t('If !if is !condition !equalto, output !then, else output !or', array(
        '!if' => $this->options['if'],
        '!condition' => $this->conditions[$this->options['condition']],
        '!equalto' => $this->options['equalto'],
        '!then' => strip_tags($this->options['then']),
        '!or' => strip_tags($this->options['or']),
      ));
    }
    else {
      return t('Invalid field selection');
    }
  }

  /**
   * Remove advanced rendering options from form.
   */
  public function allow_advanced_render() {
    return FALSE;
  }

  /**
   * Defines field alias.  No query manipulation necessary.
   */
  public function query() {
    $this->field_alias = 'views_conditional_' . $this->position;
  }

  /**
   * Cleans a variable for handling later.
   */
  public function clean_var($var) {
    $unparsed = isset($var->last_render) ? $var->last_render : '';
    return $this->options['strip_tags'] ? trim(strip_tags($unparsed)) : trim($unparsed);
  }

  /**
   * Renders the final output based on conditional input.
   */
  public function render($values) {
    $if = $this->options['if'];
    $condition = $this->options['condition'];
    $equalto = $this->options['equalto'];
    $then = $this->options['then'];
    $or = ($this->options['or'] ? $this->options['or'] : '');

    // Gather field information.
    $fields = $this->view->display_handler->get_handlers('field');

    // Search through field information for possible replacement variables.
    foreach ($this->view->display_handler->get_field_labels() as $key => $var) {
      // If we find a replacement variable, replace it.
      if (strpos($equalto, "[$key]") !== FALSE) {
        $field = $this->clean_var($fields[$key]);
        $equalto = str_replace("[$key]", $field, $equalto);
      }
      if (strpos($then, "[$key]") !== FALSE) {
        $field = $this->clean_var($fields[$key]);
        $then = str_replace("[$key]", $field, $then);
      }
      if (strpos($or, "[$key]") !== FALSE) {
        $field = $this->clean_var($fields[$key]);
        $or = str_replace("[$key]", $field, $or);
      }
    }

    // If we find a date stamp replacement, replace that.
    if (strpos($equalto, 'DATE_STAMP') !== FALSE) {
      $equalto = str_replace('DATE_STAMP', format_date(REQUEST_TIME), $equalto);
    }
    if (strpos($then, 'DATE_STAMP') !== FALSE) {
      $then = str_replace('DATE_STAMP', format_date(REQUEST_TIME), $then);
    }
    if (strpos($or, 'DATE_STAMP') !== FALSE) {
      $or = str_replace('DATE_STAMP', format_date(REQUEST_TIME), $or);
    }

    // If we find a unix date stamp replacement, replace that.
    if (strpos($equalto, 'DATE_UNIX') !== FALSE) {
      $equalto = str_replace('DATE_UNIX', REQUEST_TIME, $equalto);
    }
    if (strpos($then, 'DATE_UNIX') !== FALSE) {
      $then = str_replace('DATE_UNIX', REQUEST_TIME, $then);
    }
    if (strpos($or, 'DATE_UNIX') !== FALSE) {
      $or = str_replace('DATE_UNIX', REQUEST_TIME, $or);
    }

    // Strip tags on the "if" field.  Otherwise it appears to
    // output as <div class="xxx">Field data</div>...
    // ...which of course makes it difficult to compare.
    $r = isset($fields["$if"]->last_render) ? trim(strip_tags($fields["$if"]->last_render, '<img>')) : NULL;

    // Run conditions.
    switch ($condition) {
      // Equal to.
      case 1:
        if ($r == $equalto) {
          return $then;
        }
        else {
          return $or;
        }
        break;

      // Not equal to.
      case 2:
        if ($r !== $equalto) {
          return $then;
        }
        else {
          return $or;
        }
        break;

      // Greater than.
      case 3:
        if ($r > $equalto) {
          return $then;
        }
        else {
          return $or;
        }
        break;

      // Less than.
      case 4:
        if ($r < $equalto) {
          return $then;
        }
        else {
          return $or;
        }
        break;

      // Empty.
      case 5:
        if (empty($r)) {
          return $then;
        }
        else {
          return $or;
        }
        break;

      // Not empty.
      case 6:
        if (!empty($r)) {
          return $then;
        }
        else {
          return $or;
        }
        break;

      // Contains
      case 7:
        if (mb_stripos($r, $equalto) !== FALSE) {
          return $then;
        }
        else {
          return $or;
        }
        break;

      // Does NOT contain
      case 8:
        if (mb_stripos($r, $equalto) === FALSE) {
          return $then;
        }
        else {
          return $or;
        }
        break;
        
      // Length Equal to.
      case 9:
        if (mb_strlen($r) == $equalto) {
          return $then;
        }
        else {
          return $or;
        }
        break;

      // Length Not equal to.
      case 10:
        if (mb_strlen($r) !== $equalto) {
          return $then;
        }
        else {
          return $or;
        }
        break;

      // Length Greater than.
      case 11:
        if (mb_strlen($r) > $equalto) {
          return $then;
        }
        else {
          return $or;
        }
        break;

      // Length Less than.
      case 12:
        if (mb_strlen($r) < $equalto) {
          return $then;
        }
        else {
          return $or;
        }
        break;
    }
  }
}
