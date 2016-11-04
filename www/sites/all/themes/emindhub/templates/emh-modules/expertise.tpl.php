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
      <div class="background" style="background-image: url('http://i.imgur.com/1SZq5NP.png')"></div>
      <svg class="picture" version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
        viewBox="0 0 113.4 113.4" style="enable-background:new 0 0 113.4 113.4;" xml:space="preserve">
        <g id="produits">
          <path class="st0" d="M103.4,9.9c-3.7-3.7-16.7,3.3-21,7.5L68.8,31.1L24.8,19.9c-4.2-1.4-8.6-0.6-11.4,2.2l-4.5,4.5l43.3,21
            c-0.5,0.5-3.9,3.9-5.1,5.1c-0.8,0.8-1.6,1.8-2.4,2.7L29.7,75.9L16.9,74l-5.1,4.9l6.9,6.9l8.5,8.5l6.9,6.9l4.9-4.9l-1.9-12.7
            l20.3-15.1c0.9-0.7,1.9-1.5,2.7-2.4c1.2-1.2,4.6-4.5,5.1-5.1l21,43.3l4.5-4.5c2.8-2.8,3.7-7.2,2.2-11.4L82,44.7L95.6,31
            C100.1,26.6,107.2,13.6,103.4,9.9z"/>
        </g>
      </svg>
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
      infinite: false,
      arrows: false,
      slidesToShow: 4,
      slidesToScroll: 1,
      dots: true,
      appendDots: '.expertise .emh-dots',
      responsive: [{
        breakpoint: 1200,
        settings: {
          slidesToShow: 3
        }
      }, {
        breakpoint: 992,
        settings: {
          slidesToShow: 2
        }
      }, {
        breakpoint: 767,
        settings: {
          slidesToShow: 2,
        }
      }, {
        breakpoint: 600,
        settings: {
          slidesToShow: 1,
        }
      }]
    });
  </script>

</section>
