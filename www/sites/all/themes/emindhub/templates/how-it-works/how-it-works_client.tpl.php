<!-- CUSTOMER-->
<div class="hiw-tab-content hiw-customer">

  <div class="hiw-step hiw-step-1">

    <div class="hiw-step-title">
      <strong>1</strong> - <?php print t('I choose a type of service and I post my request'); ?>
    </div>

    <ul class="hiw-services">
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
        <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-mission.svg" alt="<?php print('Mission'); ?>" />
        <div class="label"><?php print('Mission'); ?></div>
        <div class="legend"><?php print t('Search for an expert for a mission or project'); ?></div>
      </li>
      <li class="hiw-service">
        <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-co-option.svg" alt="<?php print t('Co-option'); ?>" />
        <div class="label"><?php print t('Co-option'); ?></div>
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

  <?php if (!isset($block_html_id)) : ?>
  <?php include_once(drupal_get_path('theme','emindhub').'/templates/how-it-works/how-it-works_client_testimonials.tpl.php'); ?>
  <?php endif; ?>

  <?php if (!isset($block_html_id)) : ?>
  <section class="emh-module faq hiw-faq">

      <div class="emh-subtitle"><?php echo t('Frequently Asked Questions') ?></div>
      <?php
      $FAQ_client_block = module_invoke('views', 'block_view', 'faq-faq_client_block');
      print render($FAQ_client_block['content']);
      ?>

      <div class="emh-actions">

        <div class="emh-action">
          <span class="emh-action-text"><?php print t('Do you need expertise? Register now and post a request'); ?></span> <a class="emh-button solid" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Post a request'); ?></a>
        </div>

      </div>

  </section>
  <?php endif; ?>

</div>
