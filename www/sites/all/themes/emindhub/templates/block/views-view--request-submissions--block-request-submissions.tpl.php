<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<?php /* if (($node->uid == $user->uid) || !emh_request_has_option($node, 'private')) : ?>
  <div class="section submissions">
    <div class="row submissions-title">
      <div class="col-sm-8">
        <h2><span class="submission-title"><?php print t('Submissions'); ?></span>&nbsp;<span class="submission-count">(<?php print webform_get_submission_count($node->nid); ?>)</span></h2>
      </div>
      <?php if (emh_request_has_option($node, 'private')) : ?>
        <div class="col-sm-4 text-right submissions-private-info">
          <span class="submission-private"><?php print t('Submissions are only visible by you.'); ?></span>
        </div>
      <?php endif; ?>
    </div>
    <div class="submissions-list">
      <?php if (!empty($submissions)) : ?>
        <?php foreach ($submissions as $submission) : ?>
          <?php if (!($node->uid == $user->uid && !empty($submission->is_draft))) : ?>
            <?php
              $render = webform_submission_render($node, $submission, null, 'html');
              print drupal_render($render);
            ?>
            <?php if (webform_submission_access($node, $submission, 'edit')) : ?>
              <a href="<?php print base_path(); ?>node/<?php print $node->nid; ?>/submission/<?php print $submission->sid; ?>/edit"><?php print t('Edit'); ?></a>
            <?php endif; ?>
          <?php endif; ?>
        <?php endforeach; ?>
      <?php else: ?>
        <?php print t("No submission at this moment."); ?>
      <?php endif; ?>
    </div>
  </div>
<?php endif; */ ?>
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <div class="view-content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>
Ok
