<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <div class="field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>>

        <?php $profileURL = emindhub_beautiful_user_profile_link();
        if (!empty($profileURL)) : ?>
        <?php print t('eMindhub profile'); ?>&nbsp;:&nbsp;<?php print emindhub_beautiful_user_profile_link(); ?>&nbsp;|&nbsp;<?php print t('Website'); ?>&nbsp;:&nbsp;<?php print render($item); ?>
        <?php else : ?>
        <?php print t('Website'); ?>&nbsp;:&nbsp;<?php print render($item); ?>
        <?php endif; ?>

    </div>
    <?php endforeach; ?>
  </div>
</div>
