<?php

/**
 * Helper to get flag description.
 */
function emh_request_submission_flags_get_flag_description($flag_name, $submission, $node) {
  global $user;
  $description = array();

  $flaggings = flag_get_user_flags('webform_submission', $submission->sid, $node->uid);
  if (isset($flaggings[$flag_name]) && ($submission->uid == $user->uid)) {
    $flagging = flagging_load($flaggings[$flag_name]->flagging_id);
    $flag = flag_get_flag($flag_name, $flaggings[$flag_name]->fid);
    $description = array(
      'short' => $flag->flag_short,
      'long' => $flag->flag_long,
    );
  }

  return theme('flag_description', $description);
}

/**
 * Helper to get flag field value.
 */
function emh_request_submission_flags_get_flag_field_value($flag_name, $field, $submission, $node) {
  global $user;
  $value = '';

  $flaggings = flag_get_user_flags('webform_submission', $submission->sid, $node->uid);
  if (isset($flaggings[$flag_name]) && ($node->uid == $user->uid || $submission->uid == $user->uid)) {
    $flagging = flagging_load($flaggings[$flag_name]->flagging_id);
    $value = field_view_field('flagging', $flagging, $field, array('label' => 'inline'));
  }

  return $value;
}
