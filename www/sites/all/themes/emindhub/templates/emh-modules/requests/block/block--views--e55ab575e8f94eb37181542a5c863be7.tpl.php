<section id="<?php print $block_html_id; ?>" class="emh-module requests container <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title) : ?>
    <h2<?php print $title_attributes; ?>><span><?php print $title; ?></span></h2>
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <div class="emh-subtitle">
    <?php print t('Access the latest client requests'); ?>
  </div>

  <?php if ($content) : ?>
    <?php print $content; ?>

    <div class="emh-dots emh-dots-alt"></div>

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
  <?php endif;?>

</section> <!-- /.block -->
