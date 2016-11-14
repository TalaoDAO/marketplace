<?php global $base_url; ?>
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php /*if ($rows): ?>
    <div class="view-content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif;*/ ?>

  <section class="emh-module container expertise-full">

    <div class="expertise-list">

      <div class="expertise-list-item expertise-produits">
        <div class="domain">
          <div class="domain-name">
            <?php print t('Products'); ?>
          </div>
        </div>
        <ul class="subdomains">
          <li><?php print t('Airports'); ?></li>
          <li><?php print t('Aircraft'); ?></li>
          <li><?php print t('Drones'); ?></li>
          <li><?php print t('Equipments'); ?></li>
          <li><?php print t('Helicopters'); ?></li>
          <li><?php print t('Launchers'); ?></li>
          <li><?php print t('Satellites'); ?></li>
        </ul>
        <div class="description">
          <?php print t('EMindHub offers expertise across a range of products in the aerospace industry.'); ?>

          <div class="links">
            <a class="request" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Post a request'); ?></a>
            <a class="expertise" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Propose your expertise'); ?></a>
          </div>
        </div>

      </div>

      <div class="expertise-list-item expertise-disciplines">
        <div class="domain">
          <div class="domain-name">
            <?php print t('Discipline'); ?>
          </div>
        </div>
        <ul class="subdomains">
          <li><?php print t('Certification & Regulation'); ?></li>
          <li><?php print t('Energy'); ?></li>
          <li><?php print t('Human factors'); ?></li>
          <li><?php print t('Maintenance'); ?></li>
          <li><?php print t('Engines & propulsion'); ?></li>
          <li><?php print t('Navigation, Telecom & Observation'); ?></li>
          <li><?php print t('Airline operations'); ?></li>
          <li><?php print t('Structures & Materials'); ?></li>
          <li><?php print t('Supply chain'); ?></li>
          <li><?php print t('Safety & Security'); ?></li>
          <li><?php print t('Embedded Systems'); ?></li>
        </ul>
        <div class="description">
          <?php print t('EMindHub experts cover the entire lifecycle of products: R & D, design, production and operation.'); ?>

          <div class="links">
            <a class="request" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Post a request'); ?></a>
            <a class="expertise" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Propose your expertise'); ?></a>
          </div>
        </div>

      </div>

      <div class="expertise-list-item expertise-technologies">
        <div class="domain">
          <div class="domain-name">
            <?php print t('Technology'); ?>
          </div>
        </div>
        <ul class="subdomains">
          <li><?php print t('Air Traffic Management'); ?></li>
          <li><?php print t('Big Data'); ?></li>
          <li><?php print t('Connectivity'); ?></li>
          <li><?php print t('Cybersecurity'); ?></li>
          <li><?php print t('Additive layer manufacturing'); ?></li>
          <li><?php print t('A/C modifications'); ?></li>
          <li><?php print t('Factory of the Future'); ?></li>
        </ul>
        <div class="description">
          <?php print t('At the forefront of technology and innovation, EMindHub experts are addressing key challenges in the aerospace industry.'); ?>

          <div class="links">
            <a class="request" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Post a request'); ?></a>
            <a class="expertise" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Propose your expertise'); ?></a>
          </div>
        </div>

      </div>

      <div class="expertise-list-item expertise-transverse">
        <div class="domain">
          <div class="domain-name">
            <?php print t('Cross discipline'); ?>
          </div>
        </div>
        <ul class="subdomains">
          <li><?php print t('Finance & Legal'); ?></li>
          <li><?php print t('Knowledge transfer & Training'); ?></li>
          <li><?php print t('Configuration management'); ?></li>
          <li><?php print t('PLM'); ?></li>
          <li><?php print t('Project management'); ?></li>
          <li><?php print t('Quality & Methods'); ?></li>
          <li><?php print t('Strategy & Development'); ?></li>
          <li><?php print t('IT systems'); ?></li>
        </ul>
        <div class="description">
          <?php print t('Beyond the technical domains, eMindHub\'s community of experts can also meet the demands of functional areas and support.'); ?>

          <div class="links">
            <a class="request" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Post a request'); ?></a>
            <a class="expertise" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Propose your expertise'); ?></a>
          </div>
        </div>

      </div>

  </section>

  <section class="emh-module person-list-wrapper container">

      <h3 class="emh-subtitle"><?php print t('They got rapid and relevant answers'); ?></h3>

      <ul class="person-list row">

          <li class="person-wrapper">
            <div class="person">
                <div class="picture"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_testimonial_Jerome-Aillet.jpg" alt="Jérôme AILLET" /></div>
                <div class="content">
                    <div class="name">Jérôme AILLET</div>
                    <div class="position"><?php print t('Sales engineer AKKA TECHNOLOGIES'); ?></div>
                </div>
            </div>
          </li>

          <li class="person-wrapper">
              <div class="person">
                  <div class="picture"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_testimonial_Herve-Pierret.jpg" alt="Hervé PIERRET" /></div>
                  <div class="content">
                      <div class="name">Hervé PIERRET</div>
                      <div class="position"><?php print t('CEO AIR CORSICA'); ?></div>
                  </div>
              </div>
          </li>

          <li class="person-wrapper">
              <div class="person person-alt">
                <div class="picture"><img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/emindhub_testimonial_Thierry-Porro.jpg" alt="Thierry PORRO" /></div>
                <div class="content">
                    <div class="name">Thierry PORRO</div>
                    <div class="position"><?php print t(' Freelancer in asset management'); ?></div>
                </div>
              </div>
          </li>

      </ul>

  </section>

  <div class="emh-actions">

    <div class="emh-action">
      <?php print t('Do you need expertise? Register now and post a request'); ?> <a class="emh-button solid" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Post a request'); ?></a>
    </div>

  </div>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>
