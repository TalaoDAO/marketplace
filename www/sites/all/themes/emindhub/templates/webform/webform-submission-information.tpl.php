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

<?php
//TODO: how to get this entity_id ?
$entity_id = 163; // or else for you
$flagging = flagging_load($entity_id);
$comment_answer = $flagging->field_comment_answer[LANGUAGE_NONE][0]['value'];
?>
<h3>Your feedback comment</h3>
<blockquote><?php print $comment_answer; ?></blockquote>
