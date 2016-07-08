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
$first_name = field_get_items('user', $account, 'field_first_name');
$last_name = field_get_items('user', $account, 'field_last_name');
// echo '<pre>' . print_r($account, TRUE) . '</pre>';
?>
<div class="row section">
  <div class="col-sm-12">
    <div><?php print t('Request: !form', array('!form' => l($node->title, 'node/' . $node->nid))); ?></div>
    <div>
    <?php if ( $first_name || $last_name ) : ?>
    <?php print t('Submitted by'); ?> <span class="author-firstname"><?php print render($first_name[0]['value']); ?></span>&nbsp;<span class="author-lastname"><?php print render($last_name[0]['value']); ?></span>
    <?php else : ?>
    <?php print t('Submitted by !name', array('!name' => theme('username', array('account' => $account)))); ?>
    <?php endif; ?>
    </div>
    <div><?php print check_plain(format_date($submission->submitted, webform_variable_get('webform_date_type'))); ?></div>
  </div>
</div>
