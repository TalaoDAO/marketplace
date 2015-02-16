<?php

/**
 * @file
 * Views filter handler for the views_system module.
 */

class views_extra_handlers_handler_filter_field_config_instance_data_widget extends views_handler_filter {

  function value_form(&$form, &$form_state) {
    $form['value'] = array(
         '#type' => 'textfield',
         '#title' => t('Widget Type'),
         '#size' => 30,
         '#default_value' => $this->value,
         '#description' => 'example: text_textarea_with_summary or taxonomy_autocomplete',
       );
    if (!isset($form['value'])) {
       // Ensure there is something in the 'value'.
       $form['value'] = array(
         '#type' => 'value',
         '#value' => NULL
       );
    }
  }
  function query() {

    $this->ensure_my_table();

    $field = "$this->table_alias.$this->real_field";
    $operator = 'LIKE';
    $text_value = $this->value;
    $text_len = strlen($text_value);

    $this->query->add_where($this->options['group'], $field, '%' . db_like('s:4:"type";s:'.$text_len.':"'.$text_value.'";') . '%', $operator);
  }
}