<section id="<?php print $block_html_id; ?>" class="emh-module publications container <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <div class="emh-title">
      <?php print $title; ?>
    </div>
    <!-- <h2<?php print $title_attributes; ?>><span><?php print $title; ?></span></h2> -->
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <div class="emh-subtitle">
    <?php print t('Access the latest articles in the eMindHub knowledge base'); ?>
  </div>

  <?php if ($content): ?>

    <?php print $content; ?>

    <div class="emh-dots emh-dots-alt"></div>

    <div class="emh-actions">
      <div class="emh-action">
        <a class="emh-button" href="<?php print url('publications'); ?>"><?php print t('All publications'); ?></a>
      </div>
    </div>

  <?php endif;?>

</section> <!-- /.block -->
