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

$comment = emh_request_get_comment_answer_flag($submission, $node);
?>

<?php print render($comment); ?>
<?php print flag_create_link('interesting_answer', $submission->sid); ?>
<?php print flag_create_link('comment_answer', $submission->sid); ?>
