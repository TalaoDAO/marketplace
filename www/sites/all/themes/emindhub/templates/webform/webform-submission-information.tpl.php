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
