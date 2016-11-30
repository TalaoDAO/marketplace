<?php global $base_url; ?>

<section id="<?php print $block_html_id; ?>" class="emh-module references <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <div class="emh-title">
      <?php print t('Trust in our expertise'); ?>
    </div>
  <?php endif;?>
  <?php print render($title_suffix); ?>
  <div class="emh-subtitle">
    <?php print t('Join the companies benefiting from the expertise of eMindHub'); ?>
  </div>

  <ul class="references-list">
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_reference_Air-Corsica.png" alt="Air Corsica" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_reference_Akka-Technologies.png" alt="Akka Technologies" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_reference_Apave_Aeroservices.png" alt="Apave Aeroservices" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_reference_Assystem.png" alt="Assystem" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_reference_Dassault-Falcon.png" alt="Dassault Falcon" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_reference_Ingeliance.png" alt="Ingéliance" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_reference_Thales.png" alt="Thales" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_reference_Theano-Advisor.png" alt="Théano Advisor" /></li>
  </ul>

</section>
