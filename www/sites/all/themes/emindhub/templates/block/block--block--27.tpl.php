<?php global $base_url; ?>

<section id="<?php print $block_html_id; ?>" class="emh-module references container <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

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

  <div class="emh-dots emh-dots-alt"></div>

</section>

<?php
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/who-we-are.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/persona.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/emhlive.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/person-list.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/how-it-works.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/expertise.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/requests.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/school-community.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/publications.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/references.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/customer-emh-expert.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/publication-detail.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/faq.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/expertise-full.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/testimonial.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/press-page.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/partners.tpl.php');
?>
