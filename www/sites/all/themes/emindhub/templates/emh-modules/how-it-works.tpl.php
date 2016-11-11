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

  <!-- CUSTOMER-->
  <div class="hiw-tab-content hiw-customer">

    <div class="hiw-step hiw-step-1">

      <div class="hiw-step-title">
        <strong>1</strong> - <?php print t('I choose a type of service and I post my request'); ?>
      </div>

      <ul class="hiw-services">
        <li class="hiw-service">
          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-faq.svg" alt="<?php print t('FAQ'); ?>" />
          <div class="label"><?php print t('FAQ'); ?></div>
          <div class="legend"><?php print t('Consult a list of questions and answers to recurring and common themes'); ?></div>
        </li>
        <li class="hiw-service">
          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-doc.svg" alt="<?php print t('Doc'); ?>" />
          <div class="label"><?php print t('Doc'); ?></div>
          <div class="legend"><?php print t('Request a community of experts to find a specific document'); ?></div>
        </li>
        <li class="hiw-service">
          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-qa.svg" alt="<?php print t('Q/A'); ?>" />
          <div class="label"><?php print t('Q/A'); ?></div>
          <div class="legend"><?php print t('Ask a question to a community of experts'); ?></div>
        </li>
        <li class="hiw-service">
          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-call.svg" alt="<?php print t('Call'); ?>" />
          <div class="label"><?php print t('Call'); ?></div>
          <div class="legend"><?php print t('Request a telephone appointment with an expert'); ?></div>
        </li>
        <li class="hiw-service">
          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-survey.svg" alt="<?php print t('Survey'); ?>" />
          <div class="label"><?php print t('Survey'); ?></div>
          <div class="legend"><?php print t('Put out a survey to a community of experts'); ?></div>
        </li>
        <li class="hiw-service">
          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-missions.svg" alt="<?php print('Mission'); ?>" />
          <div class="label"><?php print('Mission'); ?></div>
          <div class="legend"><?php print t('Search for an expert for a mission or project'); ?></div>
        </li>
        <li class="hiw-service">
          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-cv.svg" alt="<?php print t('CV'); ?>" />
          <div class="label"><?php print t('CV'); ?></div>
          <div class="legend"><?php print t('Call on a community of experts to find qualified candidates for recruitment'); ?></div>
        </li>
      </ul>
    </div>

    <div class="hiw-steps-group">

      <div class="hiw-step hiw-step-2">
        <div class="hiw-step-title">
          <strong>2</strong> - <?php print t('I review the responses'); ?>
        </div>

        <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/responses.svg" alt="" />
      </div>

      <div class="hiw-step hiw-step-3">
        <div class="hiw-step-title">
          <strong>3</strong> - <?php print t('I access the expert full profiles and purchase their content'); ?>
        </div>

        <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/community.svg" alt="" />
      </div>

    </div>

    <div class="emh-actions">

      <div class="emh-action">
        <a class="emh-button solid" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Post a request'); ?></a>
      </div>

    </div>


  </div>


  <!-- EXPERT-->
  <div class="hiw-tab-content hiw-expert">
    <div class="hiw-steps">
      <div class="hiw-step hiw-step-1">
        <div class="hiw-step-title">
          <?php print t('I review the public requests and those related to my community'); ?>
        </div>

        <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/requests.svg" alt="" />
      </div>

      <div class="hiw-steps-group">

        <div class="hiw-step hiw-step-2 arrowed">
          <div class="hiw-step-title">
            <?php print t('I respond to a request'); ?>
          </div>

          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/responses-exp.svg" alt="" />
        </div>

        <div class="hiw-step hiw-step-3 arrowed">
          <div class="hiw-step-title">
            <?php print t('I sponsor an expert'); ?>
          </div>

          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/sponsorship.svg" alt="" />
        </div>

      </div>

      <div class="hiw-step hiw-step-4 arrowed">
        <dl class="hiw-step-title">
          <dt><strong>1</strong> - <?php print t('I develop my reputation'); ?></dt>
          <dt><strong>2</strong> - <?php print t('I pick up new missions'); ?></dt>
          <dt><strong>2</strong> - <?php print t('I earn credit when :'); ?></dt>
          <dd><?php print t('my profile is accessed'); ?></dd>
          <dd><?php print t('my referrals are accepted'); ?></dd>
        </dl>

      </div>
    </div>

    <div class="emh-actions">

      <div class="emh-action">
        <a class="emh-button solid-alt" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Post a request'); ?></a>
      </div>

    </div>

    <?php if (!$block_html_id) : ?>
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
      <div class="emh-module hiw-video container">
        <h3><?php print t('Learn about eMindHub on video'); ?></h3>
        <div class="embed-responsive embed-responsive-16by9">
         <iframe class="embed-responsive-item" src="<?php print $video_url; ?>"></iframe>
      </div>
      </div>
    <?php endif; ?>

  </div>

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

</section>
