<?php

/**
 * @file
 * Definition of views_handler_field_one_time_login_url.
 */

/**
 * Field handler to provide a user's one-time login URL.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_one_time_login_url extends views_handler_field_url {
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function get_value($values, $field = NULL) {
    if ($field) {
      return parent::get_value($values, $field);
    }
    $account = new stdClass();
    $account->login = $this->get_value($values, 'login');
    $account->pass = $this->get_value($values, 'pass');
    $account->uid = $this->get_value($values, 'uid');
    // Restrict access to users who can edit this account.
    if (user_edit_access($account)) {
      return user_pass_reset_url($account);
    }
  }
}
