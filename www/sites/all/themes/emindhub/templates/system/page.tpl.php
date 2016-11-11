<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
global $base_url;
?>
<header id="navbar" role="banner" class="navbar navbar-emh">

  <div class="container">

    <div class="row">

      <?php if ( $logged_in ): ?>
      <div class="col-md-1">
      <?php else : ?>
      <div class="col-md-3">
      <?php endif; ?>

        <?php if (!empty($page['burgermenu'])): ?>
        <div class="burger-menu-btn-container" onclick="onClickBurgerMenuBtn();">
          <button type="button" class="btn btn-default emh-blue">
            <span class="glyphicon glyphicon-menu-hamburger" aria-hidden="true"></span>
          </button>
        </div>
        <?php endif; ?>

        <?php if ($logo): ?>
        <a class="logo navbar-btn" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
          <?php if ( $logged_in ): ?>
          <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/logo/eMindHub_picto.png" alt="<?php print $site_name; ?>" />
          <?php else : ?>
          <img src="<?php print $logo; ?>" alt="<?php print $site_name; ?>" />
          <?php endif; ?>
        </a>
        <?php endif; ?>

      </div> <!-- END .col -->

      <?php if ( $logged_in ): ?>
      <div class="col-md-11">
      <?php else : ?>
      <div class="col-md-9">
      <?php endif; ?>

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

      </div> <!-- END .col -->

    </div> <!-- END .row -->

  </div> <!-- END .container -->

</header>

<?php if (!empty($page['header'])): ?>
<header role="banner" id="page-header">
  <div class="container-fluid">

    <div class="row">
      <?php print render($page['header']); ?>
    </div>

  </div>
</header> <!-- /#page-header -->
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
                <?php emindhub_show_request_type(); ?>
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

        <?php if (!empty($page['title_bottom'])): ?>
          <?php print render($page['title_bottom']); ?>
        <?php endif; ?>

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

      <?php if (!empty($page['highlighted'])): ?>
      <div class="highlighted jumbotron">
          <?php print render($page['highlighted']); ?>
      </div>
      <?php endif; ?>

      <div class="row">

        <?php if (!empty($page['sidebar_first'])) : ?>
        <?php if ($is_front) : ?>
        <aside id="sidebar-first" class="col-md-5 col-md-offset-1" role="complementary">
        <?php else : ?>
        <aside id="sidebar-first" class="col-md-2" role="complementary">
        <?php endif; ?>
          <?php print render($page['sidebar_first']); ?>
        </aside>  <!-- /#sidebar-first -->
        <?php endif; ?>

        <section id="maincol"<?php print $content_column_class; ?>>

          <?php if (!empty($action_links)): ?>
            <ul class="action-links"><?php print render($action_links); ?></ul>
          <?php endif; ?>

          <?php print render($page['content']); ?>

        </section>

        <?php if (!empty($page['sidebar_second']) || !empty($page['help'])): ?>
        <?php if ($is_front) : ?>
        <aside id="sidebar-second" class="col-md-5" role="complementary">
        <?php else : ?>
        <aside id="sidebar-second" class="col-md-3" role="complementary">
        <?php endif; ?>
          <?php if (!empty($page['help'])): ?>
            <?php print render($page['help']); ?>
          <?php endif; ?>
          <?php print render($page['sidebar_second']); ?>
        </aside>  <!-- /#sidebar-second -->
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

        <?php if ( (!empty($page['bottom']) && empty($page['bottom_right'])) || (empty($page['bottom']) && !empty($page['bottom_right'])) ): ?>
          <?php print render($page['bottom']); ?>
          <?php print render($page['bottom_right']); ?>
        <?php endif; ?>

      </div>
    </div>
    <?php endif; ?>

</div>

<?php print render($page['burgermenu']); ?>

<footer class="footer">
  <div class="container">
    <div class="row">
      <div class="footer-logo col-md-3">
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
          <svg version="1.1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
          	 viewBox="0 0 234.3 34.6" style="enable-background:new 0 0 234.3 34.6;" xml:space="preserve">
            <style type="text/css">
            	.st0{fill:#FFFFFF;}
            	.st1{fill:#FFFFFF;}
            </style>
            <g id="Calque_1">
            	<path class="st0" d="M41.9,10.2c-0.7,0-1.2,0.4-1.5,1l-5.5,12.5l-5.5-12.5c-0.1-0.3-0.4-0.6-0.6-0.8c-0.3-0.2-0.6-0.3-0.9-0.3
            		c-0.8,0-1.3,0.4-1.5,1.3l-4.6,16.7h3.1l3.4-12.5l5,11.5c0.3,0.8,0.9,1.2,1.6,1.2c0.4,0,0.7-0.1,0.9-0.3c0.3-0.2,0.5-0.5,0.6-0.9
            		l5-11.5l3.4,12.5h3.1l-4.5-16.7C43.1,10.7,42.6,10.2,41.9,10.2z M52.9,28.2H56V10.5h-3.1V28.2z M77.4,23.3L64.8,10.9
            		c-0.2-0.2-0.4-0.4-0.7-0.5c-0.2-0.1-0.4-0.1-0.7-0.1c-0.5,0-0.9,0.2-1.2,0.5c-0.3,0.3-0.4,0.8-0.4,1.4v16.1h3v-13l12.5,12.5
            		c0.4,0.4,0.9,0.7,1.4,0.7c0.5,0,0.8-0.2,1.1-0.5c0.3-0.3,0.4-0.8,0.4-1.4V10.3h-3V23.3z M104.4,15.6c-0.4-1.1-1-2-1.8-2.7
            		c-0.8-0.8-1.7-1.4-2.7-1.8c-1.1-0.4-2.2-0.6-3.5-0.6H86.1v17.7h10.3c1.3,0,2.4-0.2,3.5-0.7c1.1-0.5,2-1.1,2.7-1.9
            		c0.8-0.8,1.4-1.8,1.8-2.9c0.4-1.1,0.6-2.3,0.6-3.6C105,17.9,104.8,16.7,104.4,15.6z M101.5,21.6c-0.3,0.7-0.7,1.3-1.2,1.8
            		c-0.5,0.5-1.1,0.9-1.8,1.2c-0.7,0.3-1.4,0.4-2.2,0.4h-7.2V13.5h7.2c0.8,0,1.5,0.1,2.2,0.4c0.7,0.3,1.3,0.7,1.8,1.2
            		c0.5,0.5,0.9,1.1,1.2,1.8c0.3,0.7,0.4,1.5,0.4,2.3C101.9,20.1,101.8,20.9,101.5,21.6z"/>
            	<path class="st1" d="M18.4,19.7c0-2.4-0.7-4.5-2-6.1c-1.8-2.3-4.3-3.5-7.3-3.5c-2.9,0-5.3,1.1-7.1,3.4c-1.4,1.8-2.1,3.8-2.1,6
            		c0,2.4,0.8,4.6,2.5,6.4c1.6,1.9,3.9,2.9,6.8,2.9c1.3,0,2.5-0.2,3.5-0.6c1-0.4,2-1,2.8-1.7c0.8-0.8,1.6-1.8,2.2-3l0.2-0.3h-3.5
            		c-0.4,0.5-0.7,0.9-1.1,1.2c-0.5,0.5-1.2,0.8-1.9,1.1c-0.8,0.3-1.6,0.4-2.4,0.4c-1.7,0-3-0.6-4.2-1.7c-1-1.1-1.6-2.4-1.7-4.1h15.2
            		L18.4,19.7z M3.5,17.3c0.4-1.2,1-2.1,1.7-2.7c1.1-1,2.4-1.5,4-1.5c0.9,0,1.8,0.2,2.7,0.6c0.8,0.4,1.5,0.9,2,1.6
            		c0.4,0.5,0.8,1.2,1,2H3.5z M124.6,17.8h-11.2v-7.3h-3.1v17.8h3.1v-7.7h11.2v7.7h3.1V10.5h-3.1V17.8z M149.4,20.4
            		c0,0.9-0.1,1.7-0.3,2.3c-0.2,0.6-0.6,1.2-1.1,1.6c-0.5,0.4-1.2,0.7-2,0.9c-0.8,0.2-1.9,0.3-3.1,0.3c-1.2,0-2.2-0.1-3.1-0.3
            		c-0.8-0.2-1.5-0.5-2-0.9c-0.5-0.4-0.9-0.9-1.1-1.6c-0.2-0.6-0.3-1.4-0.3-2.3v-9.9h-3.2v9.9c0,1.4,0.2,2.6,0.5,3.6
            		c0.4,1,0.9,1.9,1.7,2.5c0.8,0.7,1.8,1.2,3,1.5c1.2,0.3,2.7,0.5,4.4,0.5c1.7,0,3.2-0.2,4.4-0.5c1.2-0.3,2.2-0.8,3-1.5
            		c0.8-0.7,1.3-1.5,1.7-2.5c0.4-1,0.5-2.2,0.5-3.6v-9.9h-3V20.4z M176.3,20.2c-0.5-0.7-1.2-1.2-2-1.4c0.3-0.1,0.6-0.2,0.9-0.5
            		c0.3-0.2,0.6-0.5,0.8-0.8c0.2-0.3,0.4-0.7,0.5-1.1c0.1-0.4,0.2-0.9,0.2-1.5c0-0.7-0.1-1.4-0.4-2c-0.3-0.6-0.7-1.1-1.2-1.4
            		c-0.5-0.4-1.1-0.7-1.8-0.9c-0.7-0.2-1.5-0.3-2.4-0.3h-13v17.7h13.3c0.9,0,1.6-0.1,2.4-0.4c0.7-0.3,1.3-0.6,1.8-1.1
            		c0.5-0.5,0.9-1,1.1-1.7c0.3-0.7,0.4-1.4,0.4-2.2C177.1,21.8,176.8,20.9,176.3,20.2z M161.1,13.5h8.7c0.6,0,1.1,0,1.6,0.1
            		c0.5,0,0.9,0.2,1.2,0.3c0.3,0.2,0.6,0.4,0.8,0.7c0.2,0.3,0.3,0.7,0.3,1.1c0,0.8-0.2,1.3-0.6,1.7c-0.4,0.3-1.1,0.5-2,0.5h-9.9V13.5z
            		 M173.6,23.9c-0.2,0.3-0.5,0.5-0.8,0.7c-0.3,0.2-0.7,0.3-1.2,0.4c-0.5,0.1-1,0.1-1.5,0.1h-9v-4.6h10.1c0.9,0,1.5,0.2,2,0.6
            		c0.5,0.4,0.7,1,0.7,1.7C173.9,23.2,173.8,23.6,173.6,23.9z"/>
            </g>
            <g id="Calque_2">
            	<path class="st1" d="M212.3,11.4c4.3,0,7.7,3.5,7.7,7.7c0,4.3-3.5,7.7-7.7,7.7c-4.3,0-7.7-3.5-7.7-7.7
            		C204.6,14.9,208.1,11.4,212.3,11.4 M212.3,7.6c-6.4,0-11.6,5.2-11.6,11.6c0,6.4,5.2,11.6,11.6,11.6c6.4,0,11.6-5.2,11.6-11.6
            		C224,12.8,218.8,7.6,212.3,7.6L212.3,7.6z"/>
            	<path class="st0" d="M196.1,5.4c0-3-2.4-5.4-5.4-5.4c-3,0-5.4,2.4-5.4,5.4c0,3,2.4,5.4,5.4,5.4C193.7,10.8,196.1,8.4,196.1,5.4z
            		 M187.6,5.4c0-1.7,1.4-3.1,3.1-3.1c1.7,0,3.1,1.4,3.1,3.1c0,1.7-1.4,3.1-3.1,3.1C189,8.5,187.6,7.1,187.6,5.4z M195.7,23.8
            		c-3,0-5.4,2.4-5.4,5.4c0,3,2.4,5.4,5.4,5.4c3,0,5.4-2.4,5.4-5.4C201.1,26.2,198.7,23.8,195.7,23.8z M195.7,32.3
            		c-1.7,0-3.1-1.4-3.1-3.1c0-1.7,1.4-3.1,3.1-3.1c1.7,0,3.1,1.4,3.1,3.1C198.8,30.9,197.4,32.3,195.7,32.3z M228.9,23.8
            		c-3,0-5.4,2.4-5.4,5.4c0,3,2.4,5.4,5.4,5.4c3,0,5.4-2.4,5.4-5.4C234.3,26.2,231.9,23.8,228.9,23.8z M228.9,32.3
            		c-1.7,0-3.1-1.4-3.1-3.1c0-1.7,1.4-3.1,3.1-3.1c1.7,0,3.1,1.4,3.1,3.1C232,30.9,230.6,32.3,228.9,32.3z M228.3,9
            		c0-3-2.4-5.4-5.4-5.4c-3,0-5.4,2.4-5.4,5.4c0,3,2.4,5.4,5.4,5.4C225.9,14.4,228.3,12,228.3,9z M222.9,12c-1.7,0-3.1-1.4-3.1-3.1
            		c0-1.7,1.4-3.1,3.1-3.1S226,7.3,226,9C226,10.7,224.6,12,222.9,12z"/>
            </g>
          </svg>
          <span><?php print $site_slogan; ?></span>
        </a>
      </div>
      <div class="footer-nav col-md-3">
        <?php print render($page['footer']); ?>
      </div>
      <div class="footer-contact col-md-3">
        <h3><?php print t('Contact us'); ?></h3>
        <p><a href="<?php print url('contact'); ?>">contact@emindhub.com</a></p>
      </div>
      <div class="footer-social col-md-3">
        Social
      </div>
    </div>
    <hr />
    <p class="footer-credits"><?php print date('Y'); ?> <?php print $site_name; ?> | <?php print t('All rights reserved'); ?></p>
  </div>
</footer>
