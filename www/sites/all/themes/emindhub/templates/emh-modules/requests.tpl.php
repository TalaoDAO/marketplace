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

          </article>
        </div>
      <?php endwhile; ?>
    </div>
  </div>

  <div class="emh-dots emh-dots-alt"></div>

  <script type="text/javascript">
    /**
     * https://github.com/kenwheeler/slick/
     */
    jQuery('.requests-slider').slick({
      arrows: false,
      dots: true,
      infinite: true,
      rows: 1,
      appendDots: '.requests .emh-dots',

      responsive: [{
        breakpoint: 1800,
        settings: 'unslick'
      }, {
        breakpoint: 600,
        settings: {

          slidesToShow: 1,
          slidesToScroll: 1,
        }
      }]
    });

    /**
     * @TODO
     * Externaliser ce script dans un fichier externe
     */
  </script>

</div>
