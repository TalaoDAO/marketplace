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
<div class="row section">
  <div class="col-sm-12">
    <div><?php print t('Request: !form', array('!form' => l($node->title, 'node/' . $node->nid))); ?></div>
    <div>
    <?php print t('Submitted by !name', array('!name' => theme('username', array('account' => $account)))); ?>
    </div>
    <div><?php print check_plain(format_date($submission->submitted, webform_variable_get('webform_date_type'))); ?></div>
  </div>
</div>
