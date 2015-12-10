<?php

class views_handler_field_emh_comment_answer extends views_handler_field {

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

    $nid = arg(1);
    $entity = comment_load($cid);
    return '<a href="' . url("node/$nid/comment-$cid") . '">' . emh_request_get_answer($entity, 'comment') . '</a>';
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
