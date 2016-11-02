<section class="emh-module requests container">
  <div class="emh-title">
    <?php print t('CHANGEME Demandes en cours'); ?>
  </div>
  <div class="emh-subtitle">
    <?php print t('CHANGEME Consultez les dernières demandes des clients'); ?>
  </div>

  <div class="requests-slider">

    <?php
      $itemClass = [
        'requests-style-default',
        'requests-style-alpha',
        'requests-style-beta'
      ];
      $fakeItems = 6;
    ?>


    <div class="row">
      <?php while($fakeItems--): ?>
        <div class="requests-item-wrapper col-xs-12 col-sm-6 col-md-4">
          <article class="requests-item <?php print $itemClass[(6 - $fakeItems) % 3]; ?>">

            <div class="title">
              Titre de la publication <?php echo (6 - $fakeItems); ?>
            </div>

            <div>
              <span class="meta date">keyword</span>
              |
              <span class="meta category"><a href="#">keyword</a></span>
            </div>

            <div class="text">
              Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
            </div>
            <a href="#" class="read-more"><?php print t('Read more'); ?></a>

            <div class="social-links">
              <a class="social-network" href="#"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/facebook.svg" alt="" /></a>
              <a class="social-network" href="#"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/twitter.svg" alt="" /></a>
              <a class="social-network" href="#"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/linkedin.svg" alt="" /></a>
              <a class="author-link"    href="#">
                <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/community.svg" class="author-icon" alt="" />
                Lorem ipsum dolor
              </a>
            </div>




          </article>
        </div>
      <?php endwhile; ?>
    </div>
  </div>

  <div class="emh-dots emh-dots-alt"></div>

  <div class="emh-actions">

    <div class="emh-action">
      <a class="emh-button solid" href="#"><?php print t('CHANGEME Poster une demande'); ?></a>
    </div>

    <div class="emh-action">
      <a class="emh-button solid-alt" href="#"><?php print t('CHANGEME Proposer une expertise'); ?></a>
    </div>

  </div>

  <script type="text/javascript">
    /**
     * https://github.com/kenwheeler/slick/
     */
    var requestsSliderOptions = {
      arrows: false,
      dots: true,
      slidesToShow: 2,
      slidesToScroll: 2,
      infinite: true,
      appendDots: '.requests .emh-dots',
      responsive: [
        {
          breakpoint: 600,
          settings: {
            slidesToShow: 1,
            slidesToScroll: 1
          }
        }
      ]
    };

    /**
     * Debounce postpone execution on event trigger stop
     * then enable slider only if width <= 800
     */
    var checkRequestsSlick = debounce(function () {
      if (document.body.clientWidth > 800) {
        jQuery('.requests-slider .row.slick-initialized').slick('unslick');
      } else {
        jQuery('.requests-slider .row:not(.slick-initialized)').slick(requestsSliderOptions);
      }
    }, 300);

    checkRequestsSlick();
    window.addEventListener('resize', checkRequestsSlick);

    /**
     * @TODO
     * Externaliser ce script dans un fichier externe
     */
  </script>

</div>
