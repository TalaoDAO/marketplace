<?php

/**
 * @file
 * Customize the navigation shown when editing or viewing submissions.
 *
 * Available variables:
 * - $node: The node object for this webform.
 * - $mode: Either "form" or "display". May be other modes provided by other
 *          modules, such as "print" or "pdf".
 * - $submission: The Webform submission array.
 * - $submission_content: The contents of the webform submission.
 * - $submission_navigation: The previous submission ID.
 * - $submission_information: The next submission ID.
 */
$submission_status = emh_request_submission_get_status($submission);
?>
<div class="row section">
  <div class="col-sm-12">
    <h2><?php print t('Request: !form', array('!form' => l($node->title, 'node/' . $node->nid))); ?></h2>
  </div>
</div>

<?php if ($mode == 'display' || $mode == 'form'): ?>
  <?php print $submission_actions; ?>
  <?php print $submission_navigation; ?>
<?php endif; ?>

<div class="row section submission-content">
  <div class="col-sm-3">
    <?php print emh_user_cartouche_view($submission->uid); ?>
    <span class="date"><?php print t('Submitted: !date', array('!date' => check_plain(format_date($submission->submitted, webform_variable_get('webform_date_type'))))); ?></span>
  </div>
  <div class="section col-sm-9 submission-answer<?php if (!empty($submission_status)) print ' submission-' . $submission_status['status']; ?>">
    <div class="row user-submission-title">
      <div class="col-sm-8">
        <h3><span><?php print t('Your answer'); ?></span></h3>
      </div>
      <?php if (!empty($submission_status)): ?>
        <div class="col-sm-4">
          <span class="user-submission-status <?php print $submission_status['status']; ?>">
            <?php print $submission_status['label']; ?>
          </span>
        </div>
      <?php endif; ?>
    </div>
    <?php print render($submission_content); ?>
  </div>
  <?php print $submission_information; ?>
</div>

<?php if ($mode == 'display' || $mode == 'form'): ?>
  <?php print $submission_navigation; ?>
<?php endif; ?>
