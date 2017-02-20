  <?php global $base_url; ?>
  <header id="navbar" role="banner" class="navbar navbar-emh">

    <div class="container">

      <div class="row">

        <div class="emh-brand col-md-2">
          <a class="logo navbar-btn" href="<?php print url('smart-mobility'); ?>" title="<?php print t('Smart Mobility'); ?>">
            <?php print t('Smart Mobility'); ?>
          </a>
        </div>

        <div class="col-md-10">

          <nav class="navbar">

            <div class="navbar-header">
              <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
              <span class="sr-only">Toggle navigation</span>
              <span class="icon-bar"></span>
              <span class="icon-bar"></span>
              <span class="icon-bar"></span>
              </button>
            </div>

            <?php if (!empty($page['topmenu']) || !empty($page['navigation'])): ?>
            <div class="collapse navbar-collapse">
              <?php print render($page['topmenu']); ?>
              <?php print render($page['navigation']); ?>
            </div>
            <?php endif; ?>

          </nav>

        </div>

      </div>

    </div>

  </header>

  <?php if (!empty($page['header'])): ?>
  <header role="banner" id="page-header">
    <div class="container-fluid">

      <div class="row">
        <?php print render($page['header']); ?>
      </div>

    </div>
  </header>
  <?php endif; ?>

  <div class="main-container container-fluid">

      <header id="title">

        <div class="container">

          <a id="main-content"></a>

          <?php print $messages; ?>

          <?php $primary_tabs = emh_submenu_menu_tabs_primary($tabs);
          if (!empty($primary_tabs)) : ?>
            <ul class="tabs--primary nav nav-tabs">
              <?php print render($primary_tabs); ?>
            </ul>
          <?php endif; ?>

        </div>

      </header>

      <?php if (!empty($page['top'])): ?>
        <div class="container-fluid">
          <?php print render($page['top']); ?>
        </div>
      <?php endif; ?>

      <div class="container-fluid">

        <div class="row">

          <?php if (!empty($page['sidebar_first'])) : ?>
          <aside id="sidebar-first" class="col-md-2" role="complementary">
            <?php print render($page['sidebar_first']); ?>
          </aside>
          <?php endif; ?>

          <section id="maincol"<?php print $content_column_class; ?>>

            <?php if (!empty($action_links)): ?>
              <ul class="action-links"><?php print render($action_links); ?></ul>
            <?php endif; ?>

            <?php print render($page['content']); ?>

          </section>

          <?php if (!empty($page['sidebar_second']) || !empty($page['help'])): ?>
          <aside id="sidebar-second" class="col-md-3" role="complementary">
            <?php if (!empty($page['help'])): ?>
              <?php print render($page['help']); ?>
            <?php endif; ?>
            <?php print render($page['sidebar_second']); ?>
          </aside>
          <?php endif; ?>

        </div>

      </div>

      <?php if (!empty($page['bottom']) || !empty($page['bottom_right'])): ?>
      <div class="container">
        <div class="bottom row">

          <?php if (!empty($page['bottom']) && !empty($page['bottom_right'])): ?>
          <div class="row">
            <?php print render($page['bottom']); ?>
            <?php print render($page['bottom_right']); ?>
          </div>
          <?php endif; ?>

          <?php if ((!empty($page['bottom']) && empty($page['bottom_right'])) || (empty($page['bottom']) && !empty($page['bottom_right']))): ?>
            <?php print render($page['bottom']); ?>
            <?php print render($page['bottom_right']); ?>
          <?php endif; ?>

        </div>
      </div>
      <?php endif; ?>

  </div>

  <footer class="footer">
    <div class="container">
      <div class="row">
        <div class="footer-logo">
          <a href="<?php print url('smart-mobility'); ?>" title="<?php print t('Smart Mobility'); ?>">
            <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'smartmobility'); ?>/images/logo/AIRBUS_WHITE.png" alt="<?php print t('Airbus'); ?>" />
          </a>
        </div>
        <div class="footer-contact">
          <h4><?php print t('Contacts'); ?></h4>
          <div class="row">
            <div class="col-md-4">
              <p><strong>Relations publiques</strong><br />
              Jean-François Pilliard<br />
              <a href="mailto:jean-francois.pilliard@alixio.fr">jean-francois.pilliard@alixio.fr</a><br />
              <i>+33.6.07.18.13.96</i></p>
            </div>
            <div class="col-md-4">
              <p><strong>Responsable technique de la plateforme</strong><br />
              Nicolas Muller<br />
              <a href="mailto:nicolas.muller@emindhub.com">nicolas.muller@emindhub.com</a><br />
              <i>+33.6.51.22.55.10</i></p>
            </div>
            <div class="col-md-4">
              <p><strong>Responsable de la Mobilité</strong><br />
              Magali Ollivier<br />
              <a href="mailto:magali.ollivier@alixiomobilite.fr">magali.ollivier@alixiomobilite.fr</a><br />
              <i>+33.6.03.00.57.37</i></p>
            </div>
          </div>
        </div>
      </div>
      <hr />
      <p class="footer-credits"><?php print date('Y'); ?> <?php print t('Smart Mobility'); ?> | <?php print t('Tous droits réservés'); ?></p>
    </div>
  </footer>

  <?php print render($page['footer_bottom']); ?>
