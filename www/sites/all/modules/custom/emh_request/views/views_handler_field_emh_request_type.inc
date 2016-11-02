<?php

class views_handler_field_emh_request_type extends views_handler_field {

  /**
   * Add additional fields.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }

  /**
   * Define our additional configuration setting.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Renders our field, displays the request type.
   */
  function render($values) {
    if (isset($values->{$this->aliases['nid']})) {
      $nid = $values->{$this->aliases['nid']};
    }
    else {
      return 0;
    }

    $node = node_load($nid);
    $type = emh_request_get_type($node);
    $term = taxonomy_term_load($tid);
    $term_wrapper = entity_metadata_wrapper('taxonomy_term', $term);
    $term_name = $term_wrapper->language($language->language)->name_field->value();

    return emindhub_get_request_type_image($term_name);
  }

  /**
   * Only display the column for users with the appropriate permission.
   */
  function access() {
    return TRUE;
  }

  /**
   * Just do some basic checks.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

}
