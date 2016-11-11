<?php global $base_url; ?>

<?php if ($block_html_id) : ?>
<section id="<?php print $block_html_id; ?>" class="emh-module how-it-works hiw container <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php else : ?>
<section class="emh-module how-it-works hiw container">
<?php endif; ?>

  <?php if ($block_html_id) : ?>
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <div class="emh-title">
      <?php print t('How it works?'); ?>
    </div>
  <?php endif;?>
  <?php print render($title_suffix); ?>
  <div class="emh-subtitle">
    <?php print t('Simple, free, and in 3 easy steps…'); ?>
  </div>
  <?php endif; ?>

  <ul class="hiw-tabs">
    <li><button type="button" name="button" data-tab="hiw-customer" class="hiw-tab emh-button customer"><?php print t('You need expertise'); ?></button></li>
    <li><button type="button" name="button" data-tab="hiw-expert" class="hiw-tab emh-button expert"><?php print t('You have expertise'); ?></button></li>
  </ul>

  <?php include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/how-it-works/how-it-works_client.tpl.php'); ?>

  <?php include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/how-it-works/how-it-works_expert.tpl.php'); ?>

  <script type="text/javascript">
    Drupal.behaviors.offCanvasMenu = {
      attach: function (context, settings) {
        jQuery('.hiw-tabs', context).once().on('click', 'button', function (e) {
          var $this = jQuery(this);
          jQuery('.' + $this.data('tab')).removeClass('hiw-hidden').siblings('.hiw-tab-content').addClass('hiw-hidden');
          jQuery('.hiw-tabs .active').removeClass('active');
          $this.addClass('active');
        });

        jQuery('.hiw-tabs', context).find('button').first().trigger('click');
      }
    };
  </script>

  <script type="text/javascript">
      Drupal.behaviors.faq = {
          attach: function (context, settings) {
              jQuery('.emh-module.faq', context).once(function (e) {
                  var $this = jQuery(this);

                  /**
                   * Initialy close all answers
                   */
                  $this.find('.answer').hide();

                  /**
                   * Add click event to questions
                   */
                  $this.find('.question').on('click', function () {
                      jQuery(this).next().slideToggle().siblings('.answer').slideUp();
                      jQuery(this).toggleClass('active').siblings('.question').removeClass('active');
                  });
              });
          }
      };
  </script>

  <script type="text/javascript">
    /**
     * https://github.com/kenwheeler/slick/
     */
    jQuery('.testimonial-slider').slick({
      infinite: false,
      slidesToShow: 1,
      slidesToScroll: 1,
      arrows: false,
      dots: false,
      vertical: true
    });

    window.addEventListener('resize', debounce(function () {
        jQuery('.testimonial-slider.slick-initialized').slick('refresh');
    }, 300));

    jQuery('.testimonial-tabs').on('click', 'li', function (e) {
        var $this = jQuery(this);
        jQuery('.testimonial-slider').slick('slickGoTo', $this.index());
        $this.addClass('active').siblings().removeClass('active');
    });

  </script>

</section>
