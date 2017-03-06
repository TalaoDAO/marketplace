<?php global $base_url; ?>
<section id="<?php print $block_html_id; ?>" class="emh-module partners-wrapper container <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($title): ?>
    <div class="emh-subtitle">
      <?php print $title; ?>
    </div>
  <?php endif;?>

  <ul class="partners-list">
    <li class="partner">
      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'smartmobility'); ?>/images/alixio_logo.png" alt="Alixio" />
    </li>
    <li class="partner">
      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'smartmobility'); ?>/images/emindhub_logo.png" alt="EMindHub" />
    </li>
  </ul>

</section> <!-- /.block -->
