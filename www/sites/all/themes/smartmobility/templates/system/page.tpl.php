<?php global $base_url, $language; ?>
  <nav id="main-nav" class="navbar navbar-emh">
    <div class="container">
      <div class="navbar-header">
        <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
          <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button>

        <?php if ($language->language == 'en' && !$logged_in) : ?>
          <?php print l(t('Smart Mobility'), variable_get('emh_smartmobility_base_url', 'http://smartmob.box.local'), array('language' => $language, 'attributes' => array('title' => t('Smart Mobility'), 'class' => array('navbar-brand')))); ?>
        <?php else : ?>
          <a class="navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
          <?php if ($logged_in): ?>
            <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/logo/circles.svg" alt="<?php print $site_name; ?>" width="30" height="30" />
          <?php else : ?>
            <?php print l(t('Smart Mobility'), EMH_SMARTMOBILITY_HOMEPAGE, array('language' => $language, 'attributes' => array('title' => t('Smart Mobility'), 'class' => array('navbar-brand')))); ?>
          <?php endif; ?>
          </a>
        <?php endif; ?>

      </div>

      <?php if (!empty($page['burgermenu'])): ?>
        <div class="burger-menu-btn-container" onclick="onClickBurgerMenuBtn();">
          <button type="button" class="btn btn-default emh-blue">
            <span class="glyphicon glyphicon-menu-hamburger" aria-hidden="true"></span>
          </button>
        </div>
      <?php endif; ?>

      <?php if (!empty($page['topmenu']) || !empty($page['navigation'])): ?>
        <div id="navbar" class="navbar-collapse collapse">
          <?php print render($page['topmenu']); ?>
          <?php print render($page['navigation']); ?>
        </div>
      <?php endif; ?>

    </div>
  </nav>

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

          <div class="row">

            <div class="title-left">

              <?php print render($title_prefix); ?>
              <?php if (!empty($title)): ?>
                <div class="title">
                  <h1 class="page-header"><?php print $title; ?></h1>
                </div>
              <?php endif; ?>
              <?php print render($title_suffix); ?>

              <?php if (!empty($page['title'])): ?>
                <?php print render($page['title']); ?>
              <?php endif; ?>

              <?php if (!empty($baseline)) : ?>
                <p class="emh-title-baseline"><?php print $baseline; ?></p>
              <?php endif; ?>

            </div>

            <?php if (!empty($page['title_right'])): ?>
              <?php print render($page['title_right']); ?>
            <?php endif; ?>

          </div>

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

      <div class="container">

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
          <?php if ($language->language == 'en') : ?>
            <?php print l('<img src="' . $base_url . '/' . drupal_get_path('theme', 'smartmobility') . '/images/logo/AIRBUS_WHITE.png" alt="' . t('Airbus') . '" />', variable_get('emh_smartmobility_base_url', 'http://smartmob.box.local'), array('language' => $language, 'html' => TRUE, 'attributes' => array('title' => t('Smart Mobility')))); ?>
          <?php else : ?>
            <?php print l('<img src="' . $base_url . '/' . drupal_get_path('theme', 'smartmobility') . '/images/logo/AIRBUS_WHITE.png" alt="' . t('Airbus') . '" />', EMH_SMARTMOBILITY_HOMEPAGE, array('language' => $language, 'html' => TRUE, 'attributes' => array('title' => t('Smart Mobility')))); ?>
          <?php endif; ?>
        </div>
        <div class="footer-contact">
          <h4><?php print t('Contacts'); ?></h4>
          <div class="row">
            <div class="col-md-4">
              <p><strong><?php print t('Public relations'); ?></strong><br />
              Jean-François Pilliard<br />
              <a href="mailto:jean-francois.pilliard@alixio.fr">jean-francois.pilliard@alixio.fr</a><br />
              <i>+33.6.07.18.13.96</i></p>
            </div>
            <div class="col-md-4">
              <p><strong><?php print t('User support'); ?></strong><br />
              Nicolas Muller<br />
              <a href="mailto:nicolas.muller@emindhub.com">nicolas.muller@emindhub.com</a><br />
              <i>+33.6.51.22.55.10</i></p>
            </div>
            <div class="col-md-4">
              <p><strong><?php print t('Mobility manager'); ?></strong><br />
              Magali Ollivier<br />
              <a href="mailto:magali.ollivier@alixiomobilite.fr">magali.ollivier@alixiomobilite.fr</a><br />
              <i>+33.6.03.00.57.37</i></p>
            </div>
          </div>
        </div>
      </div>
      <hr />
      <p class="footer-credits"><?php print date('Y'); ?> <span class="smartmobility-title"><?php print t('Smart Mobility'); ?></span> | <?php print t('All rights reserved'); ?></p>
    </div>
  </footer>

  <?php print render($page['footer_bottom']); ?>
