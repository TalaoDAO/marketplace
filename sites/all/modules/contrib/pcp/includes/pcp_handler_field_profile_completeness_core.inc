<?php

/**
 * @file pcp_handler_profile_completeness_core.inc
 *
 * Handler for the 'Profile: completeness' field.
 * This is for the core profile.
 */

class pcp_handler_field_profile_completeness_core extends views_handler_field {

  public function construct() {
    parent::construct();
    $this->additional_fields['uid'] = 'uid';
  }

  /**
   * Check access.
   */
  public function access() {
    return user_access('access user profiles');
  }

  /**
   * Help build the query.
   */
  public function query() {
    // Not calling parent::query() as it will treat 'completeness' as a real
    // db field.
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Render data.
   */
  public function render($values) {
    $user = new stdClass();
    $user->uid = $values->{$this->aliases['uid']};
    $data = pcp_get_complete_percentage_data('user', 'user', $user);
    return $data['current_percent'];
  }
}
