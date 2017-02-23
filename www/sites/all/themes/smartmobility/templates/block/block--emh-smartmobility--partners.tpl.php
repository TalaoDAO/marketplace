<?php global $base_url; ?>

<section id="<?php print $block_html_id; ?>" class="emh-module references <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($title): ?>
    <div class="emh-subtitle">
      <?php print $title; ?>
    </div>
  <?php endif;?>

  <ul class="references-list">
    <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'smartmobility'); ?>/images/alixio_logo.png" alt="Alixio" /></li>
    <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'smartmobility'); ?>/images/emindhub_logo.svg" alt="EmindHub" /></li>
  </ul>

</section>
