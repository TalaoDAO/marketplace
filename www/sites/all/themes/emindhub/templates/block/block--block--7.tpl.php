<?php
global $base_url, $language;
$current_lang = $language->language;
$front_theme = path_to_theme();
$front_theme = $base_url . '/' . $front_theme;

// Video
if (!empty($current_lang) && $current_lang == 'fr') {
  $video_url = 'https://www.youtube.com/embed/Vi2bkPyqyCs?&amp;hl=fr&amp;cc_lang_pref=fr&amp;cc_load_policy=1';
} else {
  $video_url = 'https://www.youtube.com/embed/VAXPojC8KLU';
}
?>

<section class="select-persona-wrapper">

  <div class="select-persona container">
    <div class="select-persona-title">
      <?php print t('The best aviation experts answer your questions.'); ?>
    </div>
    <div class="select-persona-subtitle">
      <?php print t('Your projects deserve the best expertise.'); ?>
    </div>

    <div class="row">

      <div class="persona-customer col-md-6">
        <a class="button" href="#"><?php print t('You are a customer?'); ?></a>
        <p><?php print t('Découvrez comment nullam quis<br>lacinia augue. Curabitur'); ?></p>
      </div>

      <div class="persona-expert col-md-6">
        <a class="button" href="#"><?php print t('You are an expert?'); ?></a>
        <p><?php print t('Découvrez comment nullam quis<br>lacinia augue. Curabitur'); ?></p>
      </div>

    </div>
  </div>

</section><!-- /.select-persona-wrapper -->

<section class="emhlive container">

  <div class="emhlive-arrows"></div>
  <div class="emhlive-dots"></div>

  <div class="emhlive-slider">
    <?php $fakeItems = 4; while($fakeItems--): ?>
      <article class="emhlive-item emhlive-news">

        <div class="emhlive-item-title">
          Titre de la publication
        </div>

        <div>
          <span class="emhlive-item-meta emhlive-item-date">25 oct. 2016</span>
          <span class="emhlive-item-meta emhlive-item-category"><a href="#">category</a></span>
        </div>

        <div class="emhlive-item-picture">
          <img src="https://dummyimage.com/128/000/fff.jpg" alt="" />
        </div>

        <div class="emhlive-item-text">
          Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
          <a href="#" class="emhlive-item-link">Sed do eiusmod tempor</a>
        </div>

      </article>
    <?php endwhile; ?>
  </div>

<script type="text/javascript">
  /**
   * https://github.com/kenwheeler/slick/
   */
  jQuery('.emhlive-slider').slick({
    infinite: true,
    slidesToShow: 3,
    slidesToScroll: 1,
    appendArrows: '.emhlive-arrows',
    dots: true,
    appendDots: '.emhlive-dots'
  });

  /**
   * @TODO
   * Externaliser ce script dans un fichier externe
   */
</script>

</section>

<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content container">
    <div id="highlight">

      <span class="left gradient"></span>
      <span class="right gradient"></span>

      <div class="caption">
        <h2><?php echo sprintf(t('First smart professional network %sconnecting businesses and experts %s in the Aerospace industry'), '<strong>', '</strong>'); ?></h2>
      </div>

      <div class="video">
        <button type="button" id="hp-video" data-toggle="modal" data-target="#videoModal">
          <span class="glyphicon glyphicon-play-circle" aria-hidden="true"></span>
        </button>

        <div class="modal fade" id="videoModal" tabindex="-1" role="dialog" aria-labelledby="videoModalLabel">
          <div class="modal-dialog modal-lg" role="document">
            <div class="modal-content">
              <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-label="<?php print t('Close'); ?>"><span aria-hidden="true">&times;</span></button>
                <h4 class="modal-title" id="videoModalLabel"><?php print $title; ?></h4>
              </div>
              <div class="modal-body">
                <div class="embed-responsive embed-responsive-16by9">
                  <iframe class="embed-responsive-item" src="<?php print $video_url; ?>"></iframe>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>

    </div>
  </div>

</section> <!-- /.block -->
