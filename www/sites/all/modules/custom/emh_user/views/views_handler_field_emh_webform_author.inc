<?php

class views_handler_field_emh_webform_author extends views_handler_field {

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
   * Renders our field, displays the author of the submission.
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
    $entity = webform_get_submission($nid, $sid);
    return emh_user_cartouche_view($entity->uid);
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
