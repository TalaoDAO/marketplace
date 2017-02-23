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
<?php if (!empty(flag_create_link('interesting_answer', $submission->sid))) : ?>
<p id="submission-flags">
  <?php print flag_create_link('interesting_answer', $submission->sid); ?>
</p>
<?php endif; ?>
<?php print flag_create_link('comment_answer', $submission->sid); ?></p>
