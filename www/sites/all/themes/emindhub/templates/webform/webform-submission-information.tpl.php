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
 * - $commment_answer: The requester feedback comment on the submission.
 */

$flag = (module_exists('emh_request_submission_flags')) ? emh_request_submission_flags_get_flag_description('interesting_answer', $submission, $node) : '';
$comment = (module_exists('emh_request_submission_flags')) ? emh_request_submission_flags_get_flag_field_value('comment_answer', 'field_comment_answer', $submission, $node) : '';
$interesting_answer = flag_create_link('interesting_answer', $submission->sid);
$comment_answer = flag_create_link('comment_answer', $submission->sid);
?>

<?php if (!empty($flag) || !empty($comment) || !empty($interesting_answer) || !empty($comment_answer)) : ?>
  <div class="section col-sm-9 submission-flags">
    <span>
      <?php print render($comment); ?>
      <?php print $flag; ?>
      <?php print $interesting_answer; ?>
      <?php print $comment_answer; ?>
    </span>
  </div>
<?php endif; ?>
