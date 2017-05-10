<?php

/**
 * @file
 * View template to show requests fields.
 */
?>

<div class="request-item">

  <?php if (!empty($fields['request_type']->content)) : ?>
  <div class="request-icon">
    <?php print $fields['request_type']->content; ?>
  </div>
  <?php endif; ?>

  <div class="request-infos">
    <span class="request-title"><?php print $fields['title']->content; ?></span>

    <?php if (!empty($fields['field_domaine']->content)) : ?>
    <span class="request-domains"><?php print $fields['field_domaine']->content; ?></span>
    <?php endif; ?>

    <?php if (!empty($fields['request_status']->content)) : ?>
    <span class="request-status"><?php print $fields['request_status']->content; ?></span>
    <?php endif; ?>

    <?php if (!empty($fields['total_answers']->content)) : ?>
    <span class="request-submission-count"><?php print $fields['total_answers']->content; ?></span>
    <?php endif; ?>

    <?php if (!empty($fields['language']->content)) : ?>
    <span class="request-language"><?php print $fields['language']->content; ?></span>
    <?php endif; ?>
  </div>

  <?php if (!empty($fields['og_group_ref']->content)) : ?>
  <span class="request-circles"><?php print $fields['og_group_ref']->content; ?></span>
  <?php endif; ?>

</div>
