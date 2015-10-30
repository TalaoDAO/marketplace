<?php

/**
 * @file
 * Customize the navigation shown when editing or viewing submissions.
 *
 * Available variables:
 * - $node: The node object for this webform.
 * - $mode: Either "form" or "display". May be other modes provided by other
 *          modules, such as "print" or "pdf".
 * - $submission: The contents of the webform submission.
 * - $previous: The previous submission ID.
 * - $next: The next submission ID.
 * - $previous_url: The URL of the previous submission.
 * - $next_url: The URL of the next submission.
 */
?>
<div class="row section webform-submission-navigation">

  <div class="col-sm-3 nav-back">
    <?php print l('<span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span> ' . t('Back to <em class="placeholder">Answers</em>'), 'node/' . $node->nid . '/survey_answers', array('html' => TRUE)); ?>
  </div>

  <div class="col-sm-3 col-sm-offset-3 col-xs-6 nav-previous text-right">
  <?php if ($previous): ?>
    <?php print l('<span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span> ' . t('Previous answer'), $previous_url, array('attributes' => array('class' => array('webform-submission-previous')), 'html' => TRUE, 'query' => ($mode == 'form' ? array('destination' => $previous_url) : NULL))); ?>
  <?php else: ?>

  <?php endif; ?>
  </div>

  <div class="col-sm-3 col-xs-6 nav-next pull-right">
  <?php if ($next): ?>
    <?php print l(t('Next answer') . ' <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>', $next_url, array('attributes' => array('class' => array('webform-submission-next')), 'html' => TRUE, 'query' => ($mode == 'form' ? array('destination' => $next_url) : NULL))); ?>
  <?php else: ?>

  <?php endif; ?>
  </div>

</div>
