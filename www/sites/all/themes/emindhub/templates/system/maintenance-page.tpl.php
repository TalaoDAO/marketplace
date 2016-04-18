<?php ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
  "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
<head profile="http://www.w3.org/1999/xhtml/vocab">
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <!-- HTML5 element support for IE6-8 -->
  <!--[if lt IE 9]>
    <script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
  <![endif]-->
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <header id="navbar" role="banner" class="navbar navbar-emh">

    <div class="container">

      <?php if ($logo): ?>
      <a class="logo navbar-btn" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
      </a>
      <?php endif; ?>

    </div> <!-- END .container -->

  </header>

  <div id="trail" class="container-fluid">
    <div class="container">
    </div>
  </div>

  <div class="main-container container-fluid">

    <div class="container">

      <section id="maincol" class="col-sm-12">

        <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
        <?php endif; ?>

        <a id="main-content"></a>

        <?php print render($title_prefix); ?>
        <?php if (!empty($title)): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>

        <?php if (!empty($page['help'])): ?>
          <?php print render($page['help']); ?>
        <?php endif; ?>

        <?php if (!empty($action_links)): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>

        <?php print render($page['content']); ?>

        <div class="region region-content">
          <section id="block-system-main" class="block block-system clearfix">
            <div class="content">
              <div class="node node-page clearfix">
                <div class="content">
                  <?php print $content; ?>
                </div>
              </div>
            </div>
          </section> <!-- /.block -->
        </div>

      </section>

    </div>
  </div>

</body>
</html>
