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
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>

<!--
seems to be unused
<div><?php //print render($page['breadcrumbs']); ?></div>-->

<div id="page-wrapper">
    <div id="page">
    <div id="header">
        <div class="section clearfix">
            <div class="fixed">
                <?php require_once __DIR__ . '/includes/_header.tpl.php' ?>
                <?php if (user_is_logged_in()) { ?>
                    <div class="ligh-blue-line header-separator">&nbsp;</div>
                <?php } ?>
            </div>

            <?php if (user_is_logged_in()) { ?>
                <!-- START BREADCRUMB -->
                <?php if ($breadcrumb) {
                    print $breadcrumb;
                }
                else { ?>
                    <div class="dark-blue-line-large">&nbsp;</div>
                <?php }
                // END BREADCRUMB
            } ?>

            <div class="container container-fluid">
                <?php print $messages; ?>
                <?php print render($page['header']); ?>
            </div>
        </div>
    </div> <!-- /.section, /#header -->
<?php if (user_is_logged_in()): ?>
    <div class="container container-fluid">

        <!-- START NAV -->
        <?php if (1 == 0): ?>
            <?php if ($main_menu || $secondary_menu): ?>
                <div id="navigation">
                    <div class="section">
                        <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix')), 'heading' => t('Main menu'))); ?>
                        <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary-menu', 'class' => array('links', 'inline', 'clearfix')), 'heading' => t('Secondary menu'))); ?>
                    </div>
                </div> <!-- /.section, /#navigation -->
            <?php endif; ?>
        <?php endif; ?>
        <!-- END NAV -->

        <div id="main-wrapper">
            <div id="main" class="clearfix">

                <div id="content" class="column">
                    <div class="section">
                        <?php if ($page['highlighted']): ?>
                            <div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
                        <a id="main-content"></a>
                        <?php print render($title_prefix);
                            if ($title) { ?>
                                <h1 class="title" id="page-title"><?php print $title; ?></h1>
                        <?php }
                        print render($title_suffix);
                        //START TABS
                        if ($tabs) { ?>
                            <div class="tabs"><?php print render($tabs); ?></div>
                        <?php }
                        //END TABS
                        print render($page['help']);
                        if ($action_links) { ?>
                            <ul class="action-links"><?php print render($action_links); ?></ul>
                        <?php }

                        ddl(get_defined_vars());
//                        ddl($variables['type']);
                        if ($variables['type'] == "challenge") {
                        ?>
                            <div class="row">
                                <div class="col-md-4 challenge-title"><?php echo c_szAnswerChallenge; ?></div>
                                <div class="col-md-8"><hr class="hr-light"></div>
                            </div>
                        <?php
                        }

                        print render($page['timeline']);
                        print render($page['content']);
                        print $feed_icons; ?>
                    </div>
                </div>
                <!-- /.section, /#content -->
            </div>
        </div>
        <!-- /#main, /#main-wrapper -->
        <?php print render($page['burgermenu']); ?>
    </div>
    <!-- /.section, /#footer -->
    </div> <!-- /#page, /#page-wrapper -->
</div>
<?php endif; ?>
<div id="footer" class="footer-container">
    <div class="section">
        <div class="container container-fluid">
            <?php print render($page['footer']); ?>
        </div>
    </div>
</div>
