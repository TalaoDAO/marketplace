<section id="<?php print $block_html_id; ?>" class="emh-module emhlive container <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <div class="emhlive-title">
      <?php print $title; ?>
    </div>
    <!-- <h2<?php print $title_attributes; ?>><span><?php print $title; ?></span></h2> -->
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <?php if ($content): ?>
    <div class="emhlive-arrows"></div>
    <div class="emh-dots above"></div>

    <?php print $content; ?>

    <div class="emh-dots emh-dots-alt below"></div>

    <script type="text/javascript">
      /**
       * https://github.com/kenwheeler/slick/
       */
      jQuery('.emhlive-slider').slick({
        infinite: false,
        slidesToShow: 3,
        slidesToScroll: 1,
        appendArrows: '.emhlive-arrows',
        dots: true,
        appendDots: '.emhlive .emh-dots.above',
        responsive: [{
          breakpoint: 992,
          settings: {
            slidesToShow: 2
            // appendDots: '.emhlive-dots.below',
          }
        }, {
          breakpoint: 600,
          settings: {
            slidesToShow: 1,
            appendDots: '.emhlive .emh-dots.below'
          }
        }]
      });

      /**
       * @TODO
       * Externaliser ce script dans un fichier externe
       */
    </script>
  <?php endif;?>

</section> <!-- /.block -->
