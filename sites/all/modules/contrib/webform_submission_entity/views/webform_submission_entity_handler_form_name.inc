<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying links to entities
 * as fields.
 */

class webform_submission_entity_handler_form_name extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['wsid'] = 'wsid';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $wsid = $values->{$this->aliases['wsid']};
    $webform_entity = webform_submission_entity_load($wsid);
    $node = node_load($webform_entity->nid);
    return $node->title;
  }
}
