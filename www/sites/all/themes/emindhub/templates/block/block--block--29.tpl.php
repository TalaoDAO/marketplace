<?php global $base_url; ?>
<section id="<?php print $block_html_id; ?>" class="emh-module partners-wrapper container <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <ul class="partners-list">
      <li class="partner">
        <?php print render($title_prefix); ?>
        <?php if ($title): ?>
          <h3><span><?php print $title; ?></span></h3>
        <?php endif;?>
        <?php print render($title_suffix); ?>
      </li>
      <li class="partner"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_partner_Aerospace-Valley.png" alt="Aerospace Valley" /></li>
      <li class="partner"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_partner_BPI.png" alt="BPI" /></li>
      <li class="partner"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_partner_Digital-Place.png" alt="Digital Place" /></li>
      <li class="partner"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_partner_Enac.png" alt="Enac" /></li>
      <li class="partner"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_partner_Region_Occitanie.png" alt="Région Occitanie" /></li>
  </ul>

</section> <!-- /.block -->
