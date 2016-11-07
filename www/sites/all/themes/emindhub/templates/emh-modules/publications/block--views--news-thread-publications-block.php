<section id="<?php print $block_html_id; ?>" class="emh-module publications container <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <div class="emhlive-title">
      <?php print $title; ?>
    </div>
    <!-- <h2<?php print $title_attributes; ?>><span><?php print $title; ?></span></h2> -->
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <div class="emh-subtitle">
    <?php print t('CHANGEME Consultez les derniers articles de la base de connaissances'); ?>
  </div>

  <?php if ($content): ?>

    <?php print $content; ?>

    <div class="emh-dots emh-dots-alt"></div>

    <!-- <div class="emh-actions">
      <div class="emh-action">
        <a class="emh-button" href="#"><?php print t('CHANGEME Toutes les publications'); ?></a>
      </div>
    </div> -->

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
  <?php endif;?>

</section> <!-- /.block -->
