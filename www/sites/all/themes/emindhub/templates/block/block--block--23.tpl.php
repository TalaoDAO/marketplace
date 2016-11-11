<?php global $base_url; ?>

<section id="<?php print $block_html_id; ?>" class="emh-module school-community container <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <div class="title">
      <?php print t('Take advantage of private communities of experts'); ?>
    </div>
    <!-- <h2<?php print $title_attributes; ?>><span><?php print $title; ?></span></h2> -->
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <div class="subtitle">
    <?php print t('If you are part of an industry association or in the alumni of your former college, university or company, take a look at the list of private communities and request to be part of the group.'); ?>
  </div>

  <div class="emh-actions">
    <div class="emh-action">
      <a class="emh-button solid-alt" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Join a private community'); ?></a>
    </div>
  </div>

  <ul class="sponsors">
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/enac.png" alt="ENAC" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/thalesaleniaspace.png" alt="Thales Alenia Space" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/snecma.png" alt="Snecma" /></li>
  </ul>

</section> <!-- /.block -->
