<section class="emh-module publications container">
    <div class="emh-title">
      <?php print t('CHANGEME Publications'); ?>
    </div>
    <div class="emh-subtitle">
      <?php print t('CHANGEME Consultez les derniers articles de la base de connaissances'); ?>
    </div>

    <?php
      $fakeItems = 5;
    ?>


    <div class="publications-slider">
        <?php while($fakeItems--): ?>

        <div class="publications-item-wrapper">
            <article class="publications-item">
                <div class="picture">
                    <img src="http://i.imgur.com/FU3GUPC.png" alt="" />
                </div>

                <div class="publications-item-content">
                    <div class="title">
                        Titre de la publication
                        <?php echo $fakeItems%2?'avec un contenu '.($fakeItems%3?'beaucoup':'').' plus long':''; ?>
                    </div>

                    <div class="metas">
                        <span class="meta date">keyword</span> | <span class="meta category"><a href="#">keyword</a></span>
                    </div>

                    <div class="text">
                        Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
                    </div>
                </div>

                <a href="#" class="read-more"><?php print t('Read more'); ?></a>
            </article>
        </div>

        <?php endwhile; ?>
    </div>

    <div class="emh-dots emh-dots-alt"></div>

    <div class="emh-actions">
      <div class="emh-action">
        <a class="emh-button" href="#"><?php print t('CHANGEME Toutes les publications'); ?></a>
      </div>
    </div>


    <script type="text/javascript">
    /**
     * https://github.com/kenwheeler/slick/
     */
    jQuery('.publications-slider:not(.slick-initialized)').slick({
      arrows: false,
      dots: true,
      slidesToShow: 5,
      slidesToScroll: 1,
      infinite: false,
      appendDots: '.publications .emh-dots',
      responsive: [
        {
          breakpoint: 992,
          settings: {
            slidesToShow: 4
          }
      }, {
          breakpoint: 768,
          settings: {
            slidesToShow: 3
          }
      }, {
          breakpoint: 600,
          settings: {
            slidesToShow: 2
          }
      }, {
          breakpoint: 480,
          settings: {
            slidesToShow: 1
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
