<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> emh-module select-persona-wrapper clearfix"<?php print $attributes; ?>>

  <div class="select-persona container">

    <?php if ($title): ?>
    <div class="select-persona-title">
      <!-- <h2<?php print $title_attributes; ?>><span><?php print $title; ?></span></h2> -->
      <?php print t('The best experts in aerospace responding to your requests.'); ?>
    </div>
    <?php endif;?>

    <div class="select-persona-subtitle">
      <?php print t('The 1st smart professional network in aerospace.'); ?>
    </div>

    <div class="row select-persona-buttons">

      <div class="persona-customer col-xs-6">
        <a class="button" href="#"><?php print t('CHANGEME Vous êtes client ?'); ?></a>
        <p><?php print t('Get quick access to the best experts'); ?></p>
      </div>

      <div class="persona-expert col-xs-6">
        <a class="button" href="#"><?php print t('CHANGEME Vous êtes expert ?'); ?></a>
        <p><?php print t('Respond to requests matching your expertise'); ?></p>
      </div>

    </div>
  </div>

</section><!-- /.select-persona-wrapper -->

<?php
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/who-we-are.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/persona.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/emhlive.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/person-list.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/how-it-works.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/expertise.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/requests.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/school-community.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/publications.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/references.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/customer-emh-expert.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/publication-detail.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/faq.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/expertise-full.tpl.php');
?>
