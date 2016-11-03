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

<?php
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/persona.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/emhlive.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/how-it-works.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/expertise.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/requests.tpl.php');
  include_once(drupal_get_path('theme','emindhub').'/templates/emh-modules/school-community.tpl.php');
?>

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
