<?php

class views_handler_field_emh_webform_submission_points extends views_handler_field {

  /**
   * Add additional fields.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['sid'] = 'sid';
  }

  /**
   * Define our additional configuration setting.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Renders our field, displays the number of points of the comment.
   */
  function render($values) {
    if (isset($values->{$this->aliases['sid']})) {
      $cid = $values->{$this->aliases['sid']};
    }
    else {
      return 0;
    }

    return emh_points_get_webform_submission_points($sid);
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
