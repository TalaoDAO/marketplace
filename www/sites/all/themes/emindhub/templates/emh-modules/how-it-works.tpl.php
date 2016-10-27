<section class="emh-module how-it-works hiw container">
  <div class="emh-title">
    <?php print t('CHANGEME Comment ça marche ?'); ?>
  </div>
  <div class="emh-subtitle">
    <?php print t('CHANGEME C\'est simple, gratuit et en 3 étapes'); ?>
  </div>

  <ul class="hiw-tabs">
    <li><button type="button" name="button" class="hiw-tab"><?php print t('You are a customer'); ?></button></li>
    <li><button type="button" name="button" class="hiw-tab"><?php print t('You are an expert'); ?></button></li>
  </ul>

  <!-- CUSTOMER-->
  <div class="hiw-customer">

    <div class="hiw-step">

      <div class="hiw-step-title">
        <strong>1</strong> - <?php print t('CHANGEME Je choisis un type de service et une communauté d\'experts'); ?>
      </div>

      <ul class="hiw-services">
        <li class="hiw-service">
          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-faq.svg" alt="" />
          <div class="label">FAQ</div>
          <div class="legend"><?php print t('CHANGEME Poser une question à la commnauté des experts'); ?></div>
        </li>
        <li class="hiw-service">
          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-doc.svg" alt="" />
          <div class="label">Doc</div>
          <div class="legend"><?php print t('CHANGEME Poser une question à la commnauté des experts'); ?></div>
        </li>
        <li class="hiw-service">
          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-qa.svg" alt="" />
          <div class="label">Q/A</div>
          <div class="legend"><?php print t('CHANGEME Poser une question à la commnauté des experts'); ?></div>
        </li>
        <li class="hiw-service">
          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-call.svg" alt="" />
          <div class="label">Call</div>
          <div class="legend"><?php print t('CHANGEME Poser une question à la commnauté des experts'); ?></div>
        </li>
        <li class="hiw-service">
          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-survey.svg" alt="" />
          <div class="label">Survey</div>
          <div class="legend"><?php print t('CHANGEME Poser une question à la commnauté des experts'); ?></div>
        </li>
        <li class="hiw-service">
          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-missions.svg" alt="" />
          <div class="label">Missions</div>
          <div class="legend"><?php print t('CHANGEME Poser une question à la commnauté des experts'); ?></div>
        </li>
        <li class="hiw-service">
          <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/ico-cv.svg" alt="" />
          <div class="label">CV</div>
          <div class="legend"><?php print t('CHANGEME Poser une question à la commnauté des experts'); ?></div>
        </li>
      </ul>
    </div>

    <div class="hiw-step">
      <div class="hiw-step-title">
        <strong>2</strong> - <?php print t('CHANGEME Je consulte les réponses à mon besoin'); ?>
      </div>

      <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/responses.svg" alt="" />
    </div>

    <div class="hiw-step">
      <div class="hiw-step-title">
        <strong>3</strong> - <?php print t('CHANGEME J\'accède au profil des experts et j\'achète leur contenu'); ?>
      </div>

      <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/community.svg" alt="" />
    </div>

    <a href="#"><?php print t('CHANGEME Voir le schéma complet') ?></a>

    <a class="button" href="#"><?php print t('CHANGEME Poster une demande'); ?></a>


  </div>


  <!-- EXPERT-->
  <div class="hiw-expert">
    <div class="hiw-step">
      <div class="hiw-step-title">
        <?php print t('CHANGEME Je consulte les demandes publiques ou liées à ma communauté'); ?>
      </div>

      <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/requests.svg" alt="" />
    </div>


    <div class="hiw-step">
      <div class="hiw-step-title">
        <?php print t('CHANGEME Je réponds à une demande'); ?>
      </div>

      <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/responses-exp.svg" alt="" />
    </div>

    <div class="hiw-step">
      <div class="hiw-step-title">
        <?php print t('CHANGEME Je parraine un expert'); ?>
      </div>

      <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/sponsorship.svg" alt="" />
    </div>

    <div class="hiw-step">
      <dl class="hiw-step-title">
        <dt><strong>1</strong> - <?php print t('CHANGEME Je développe ma notoriété'); ?></dt>
        <dt><strong>2</strong> - <?php print t('CHANGEME J\'optient de nouvelles missions'); ?></dt>
        <dt><strong>2</strong> - <?php print t('CHANGEME Je gagne des crédits lorsque :'); ?></dt>
        <dd><?php print t('CHANGEME mon profil est consulté'); ?></dd>
        <dd><?php print t('CHANGEME mes parrainages sont acceptés'); ?></dd>
      </dl>

      <img class="hiw-step-picture" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/sponsorship.svg" alt="" />
    </div>

    <a href="#"><?php print t('CHANGEME Voir le schéma complet') ?></a>

    <a class="button" href="#"><?php print t('CHANGEME Poster une demande'); ?></a>

  </div>

</section>
