<?php

class views_handler_field_emh_request_answer_count extends views_handler_field {

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
   * Renders our field, displays the answer count.
   */
  function render($values) {
    if (isset($values->{$this->aliases['nid']})) {
      $nid = $values->{$this->aliases['nid']};
    }
    else {
      return 0;
    }

    $submission_count = emh_request_count_answers($nid);
    return theme('submission_count', array(
      'submission_count' => $submission_count,
    ));
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
