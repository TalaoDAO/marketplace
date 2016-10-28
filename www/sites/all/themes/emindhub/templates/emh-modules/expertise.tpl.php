<section class="emh-module expertise">
  <div class="emh-title">
    <?php print t('CHANGEME Domaine d\'expertise'); ?>
  </div>
  <div class="emh-subtitle">
    <?php print t('CHANGEME Consultez les domaines où client et experts se retrouvent'); ?>
  </div>

  <div class="expertise-slider">

    <?php $expertiseLoop = 4; while ($expertiseLoop--): ?>
    <div class="expertise-slider-item">
      <div class="background" style="background-image: url('http://i.imgur.com/xn9iQ9G.png')"></div>
      <img class="picture" src="" alt="" />
      <div class="domain">
        <?php print t('Produits'); ?>
      </div>
      <ul class="subdomains">
        <li><?php print t('Air traffic Management'); ?></li>
        <li><?php print t('Big Data'); ?></li>
        <li><?php print t('Connectivité'); ?></li>
        <li><?php print t('Cybersécurité'); ?></li>
        <li><?php print t('Fabrication additive'); ?></li>
        <li><?php print t('Usine du futur'); ?></li>
      </ul>
      <a class="emh-button" href="#"><?php print t('Expertises technologie'); ?></a>
    </div>
  <?php endwhile; ?>

  </div>

  <div class="emh-dots emh-dots-alt"></div>

  <script type="text/javascript">
    /**
     * https://github.com/kenwheeler/slick/
     */
    jQuery('.expertise-slider').slick({
      infinite: true,
      arrows: false,
      slidesToShow: 4,
      slidesToScroll: 1,
      dots: true,
      appendDots: '.expertise .emh-dots'
    });
  </script>

</section>
