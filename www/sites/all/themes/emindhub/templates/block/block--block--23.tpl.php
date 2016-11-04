<?php global $base_url; ?>

<section id="<?php print $block_html_id; ?>" class="emh-module school-community container <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <div class="title">
      <?php print t('CHANGEME Profitez des avantages des communautés privées'); ?>
    </div>
    <!-- <h2<?php print $title_attributes; ?>><span><?php print $title; ?></span></h2> -->
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <div class="subtitle">
    <?php print t('CHANGEME Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.'); ?>
  </div>

  <div class="emh-actions">
    <div class="emh-action">
      <a class="emh-button solid-alt" href="#"><?php print t('CHANGEME Voir les avantages'); ?></a>
    </div>
  </div>

  <ul class="sponsors">
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/enac.png" alt="ENAC" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/thalesaleniaspace.png" alt="Thales Alenia Space" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/snecma.png" alt="Snecma" /></li>
  </ul>

</section> <!-- /.block -->
