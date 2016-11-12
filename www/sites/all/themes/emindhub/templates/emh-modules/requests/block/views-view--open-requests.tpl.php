<div class="requests-slider <?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title) : ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header) : ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed) : ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before) : ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows) : ?>
    <div class="row view-content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty) : ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager) : ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after) : ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more) : ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer) : ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon) : ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>

<div class="emh-actions">

  <div class="emh-action">
    <a class="emh-button solid" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Post a request'); ?></a>
  </div>

  <div class="emh-action">
    <a class="emh-button solid-alt" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Propose your expertise'); ?></a>
  </div>

</div>
