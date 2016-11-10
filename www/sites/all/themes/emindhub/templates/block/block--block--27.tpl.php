<?php global $base_url; ?>

<section id="<?php print $block_html_id; ?>" class="emh-module references container <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <div class="emh-title">
      <?php print t('CHANGEME Ils nous ont fait confiance'); ?>
    </div>
  <?php endif;?>
  <?php print render($title_suffix); ?>
  <div class="emh-subtitle">
    <?php print t('CHANGEME Rejoignez les entreprises qui utilisent l\'expertise eMindHub'); ?>
  </div>

  <ul class="references-list">
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/references-baas.png" alt="BAAS" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/references-planindustries.png" alt="Plan Industries" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/references-thalesaleniaspace.png" alt="Thales Alenia Space" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/references-snecma.png" alt="Snecma" /></li>
      <li><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/references-airbus.png" alt="Airbus Defence & Space" /></li>
  </ul>

  <div class="emh-dots emh-dots-alt"></div>

  <script type="text/javascript">
  /**
   * https://github.com/kenwheeler/slick/
   */
  jQuery('.references-list:not(.slick-initialized)').slick({
    arrows: false,
    dots: true,
    slidesToShow: 5,
    slidesToScroll: 1,
    infinite: false,
    appendDots: '.references .emh-dots',
    responsive: [
      {
        breakpoint: 768,
        settings: {
          slidesToShow: 2,
          slidesToScroll: 1
        }
    },
      {
        breakpoint: 480,
        settings: {
          infinite: true,
          slidesToShow: 1,
          slidesToScroll: 1
        }
      }
    ]
  });

  /**
   * @TODO
   * Externaliser ce script dans un fichier externe
   */
  </script>
</section>

<?php
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/who-we-are.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/persona.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/emhlive.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/person-list.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/how-it-works.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/expertise.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/requests.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/school-community.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/publications.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/references.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/customer-emh-expert.tpl.php');
  // include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/publication-detail.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/faq.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/expertise-full.tpl.php');
?>
