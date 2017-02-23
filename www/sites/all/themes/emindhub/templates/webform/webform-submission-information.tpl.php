<?php

/**
 * @file
 * Customize the header information shown when editing or viewing submissions.
 *
 * Available variables:
 * - $node: The node object for this webform.
 * - $mode: Either "form" or "display". May be other modes provided by other
 *          modules, such as "print" or "pdf".
 * - $submission: The contents of the webform submission.
 * - $account: The user that submitted the form.
 */
?>

<span class="date"><?php print t('Submitted: !date', array('!date' => check_plain(format_date($submission->submitted, webform_variable_get('webform_date_type'))))); ?></span>
<p class="text-center"><?php print flag_create_link('interesting_answer', $submission->sid); ?><?php print flag_create_link('comment_answer', $submission->sid); ?></p>
<h3>Your feedback comment</h3>
<blockquote>
  <?php print _emh_request_submission_get_comment($submission->sid); ?>
</blockquote>

<?php

/**
 * Helper function to get a submission comment.
 */
function _emh_request_submission_get_comment($sid) {
  $query = db_select('flagging', 'f');
  $query->join('field_data_field_comment_answer', 'c', 'f.flagging_id = c.entity_id');
  $query
    ->condition('f.entity_type', 'webform_submission')
    ->condition('f.fid', 16)
    ->condition('f.entity_id', $sid)
    ->fields('c', array('field_comment_answer_value'));
  $result = $query->execute();
  $row = $result->fetch();

  return ($row->field_comment_answer_value);
}
?>
