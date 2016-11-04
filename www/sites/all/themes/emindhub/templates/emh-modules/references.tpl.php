<section class="emh-module references container">
    <div class="emh-title">
      <?php print t('CHANGEME Ils nous ont fait confiance'); ?>
    </div>
    <div class="emh-subtitle">
      <?php print t('CHANGEME Rejoignez les entreprises qui utilisent l\'expertise eMindHub'); ?>
    </div>

    <ul class="references-list">
        <li><a href="#"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/references-baas.png" alt="BAAS" /></a></li>
        <li><a href="#"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/references-planindustries.png" alt="Plan Industries" /></a></li>
        <li><a href="#"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/references-thalesaleniaspace.png" alt="Thales Alenia Space" /></a></li>
        <li><a href="#"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/references-snecma.png" alt="Snecma" /></a></li>
        <li><a href="#"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/references-airbus.png" alt="Airbus Defence & Space" /></a></li>
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
