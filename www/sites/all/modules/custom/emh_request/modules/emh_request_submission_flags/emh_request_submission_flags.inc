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
      'message' => $flag->flag_message,
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

/**
 * Helper function to get a submission comment.
 */
function _emh_request_submission_flags_get_comment($sid) {
  $flag = flag_get_flag('comment_answer');
  $fid = $flag->fid;
  if (!is_numeric($sid)) {
    return;
  }
  $query = db_select('flagging', 'f');
  $query->join('field_data_field_comment_answer', 'c', 'f.flagging_id = c.entity_id');
  $query
    ->condition('f.entity_type', 'webform_submission')
    ->condition('f.fid', $fid)
    ->condition('f.entity_id', $sid)
    ->fields('c', array('field_comment_answer_value'));
  $result = $query->execute();
  $row = $result->fetch();

  if (isset($row->field_comment_answer_value)) {
    return ($row->field_comment_answer_value);
  }
  else {
    return NULL;
  }
}
