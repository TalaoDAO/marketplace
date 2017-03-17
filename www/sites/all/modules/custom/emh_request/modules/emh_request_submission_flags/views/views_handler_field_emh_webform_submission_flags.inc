<?php

class views_handler_field_emh_webform_submission_flags extends views_handler_field {

  /**
   * Add additional fields.
   */
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
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
   * Renders our field, displays the answer.
   */
  function render($values) {
    if (isset($values->{$this->aliases['nid']})) {
      $nid = $values->{$this->aliases['nid']};
    }
    else {
      return 0;
    }
    if (isset($values->{$this->aliases['sid']})) {
      $sid = $values->{$this->aliases['sid']};
    }
    else {
      return 0;
    }

    module_load_include('inc', 'webform', 'includes/webform.submissions');
    $submission = webform_get_submission($nid, $sid);
    $node = node_load($nid);

    $flag = ''; $comment = ''; $flags = '';

    $flag = emh_request_submission_flags_get_flag_description('interesting_answer', $submission, $node);
    $comment = emh_request_submission_flags_get_flag_field_value('comment_answer', 'field_comment_answer', $submission, $node);

    if (!empty(flag_create_link('interesting_answer', $sid))) {
      $flags .= flag_create_link('interesting_answer', $sid);
    }

    if (!empty(flag_create_link('comment_answer', $sid))) {
      $flags .= flag_create_link('comment_answer', $sid);
    }

    return (!empty($comment)) ? render($comment) . $flags . $flag : $flags . $flag;
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
