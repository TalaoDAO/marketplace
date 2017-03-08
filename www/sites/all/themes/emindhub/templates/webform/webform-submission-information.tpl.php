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
?>

<span class="date"><?php print t('Submitted: !date', array('!date' => check_plain(format_date($submission->submitted, webform_variable_get('webform_date_type'))))); ?></span>

<div id="submission-flags">
  <?php print flag_create_link('interesting_answer', $submission->sid); ?>
  <?php print flag_create_link('comment_answer', $submission->sid); ?>
  <?php if (isset($comment_answer)) : ?>
  <p><em><?php print $comment_answer; ?></em></p>
  <?php endif; ?>
</div>
