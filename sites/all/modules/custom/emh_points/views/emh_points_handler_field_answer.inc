<?php

/**
 * @file
 * Definition of emh_points_handler_field_answer.
 */

/**
 * Provide the trimmed answer field.
 *
 * @ingroup views_filter_handlers
 */
class emh_points_handler_field_answer extends views_handler_field {
  /**
  * Render the answer field.
  */
  public function render($values) {
    dpm($values);
    // $value = $this->get_value($values);
    // $answer = emh_request_get_answer($entity, $type);
    // return $answer[$value];
    $output = t("Hello World!");
    return $output;  
  }
}
