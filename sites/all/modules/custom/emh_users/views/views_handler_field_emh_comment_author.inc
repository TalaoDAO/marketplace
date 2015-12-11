<?php

class views_handler_field_emh_comment_author extends views_handler_field {

  /**
   * Add additional fields.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['cid'] = 'cid';
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
    if (isset($values->{$this->aliases['cid']})) {
      $cid = $values->{$this->aliases['cid']};
    }
    else {
      return 0;
    }

    $entity = comment_load($cid);
    return emh_users_get_beautiful_profile_link($entity->uid);
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
