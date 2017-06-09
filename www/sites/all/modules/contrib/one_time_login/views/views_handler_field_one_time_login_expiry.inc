<?php

/**
 * @file
 * Definition of views_handler_field_one_time_login_expiry.
 */

/**
 * Field handler to provide expiration date of the user's one-time login URL.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_one_time_login_expiry extends views_handler_field_date {
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function get_value($values, $field = NULL) {
    if ($field) {
      return parent::get_value($values, $field);
    }
    if ($this->get_value($values, 'login')) {
      return REQUEST_TIME + variable_get('user_password_reset_timeout', 86400);
    }
  }
}
