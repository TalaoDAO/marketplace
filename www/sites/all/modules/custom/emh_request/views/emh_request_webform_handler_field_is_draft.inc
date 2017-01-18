<?php

/**
 * @file
 * Views handler to display the draft status of a submission.
 */

/**
 * Field handler to show if submission is draft or not.
 *
 * @ingroup views_field_handlers
 */
class emh_request_webform_handler_field_is_draft extends webform_handler_field_is_draft {
  function render($values) {
    $is_draft = $values->{$this->field_alias};
    return isset($is_draft)
              ? ($is_draft ? t('draft') : t('published'))
              : t('no submission');
  }
}
