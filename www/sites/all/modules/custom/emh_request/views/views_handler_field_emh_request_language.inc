<?php

class views_handler_field_emh_request_language extends views_handler_field {

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

    // $languages = locale_language_list(empty($this->options['native_language']) ? 'name' : 'native');
    // $value = $this->get_value($values);

    // echo '<pre>' . print_r($node, true) . '</pre>';
    // return $node->language;
    // echo $node->language;

    return isset($node->language) ? '<span class="lang-sm" lang="' . $node->language . '">' . $node->language . '</span>' : '';
    // return isset($languages[$value]) ? $languages[$value] : '';

    // return emh_request_get_request_type_image($nid, 25) . emh_request_get_request_type_name($nid);
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
