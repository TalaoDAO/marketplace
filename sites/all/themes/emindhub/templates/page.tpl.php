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

<div><?php print render($page['breadcrumbs']); ?></div>

<div id="page-wrapper">
    <div id="page">
    <div id="header">
        <div class="section clearfix paddingU">
            <?php require_once __DIR__ . '/includes/_header.tpl.php' ?>
            <?php if (!user_is_logged_in()): ?>
                <div class="banniere">
                    <div class="container container-fluid">
                        <div class="row">
                            <div class="col-md-4">
                                <div class="text-banniere">
                                    <?php print $banniereText; ?>
                                </div>
                            </div>
                            <div class="col-md-4 col-md-offset-4">
                                <div class="row inscription-image-wrapper">
                                    <div class="col-md-12">
                                        <a href="<?php print url("business/register"); ?>"><?php print $demandeImg; ?></a>
                                    </div>
                                </div>
                                <div class="row inscription-image-wrapper">
                                    <div class="col-md-12">
                                        <a href="<?php print url("expert/register"); ?>"><?php print $expertiseImg; ?></a>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            <?php endif; ?>
            <?php if (user_is_logged_in()): ?>
                <div class="ligh-blue-line header-separator">&nbsp;</div>
                <div class="dark-blue-line-large">&nbsp;</div>
            <?php endif; ?>
            <?php
            if (isAdminUser()) {
                print $messages;
            }
            ?>
            <div class="container container-fluid">
                <?php print render($page['header']); ?>
            </div>
        </div>
    </div> <!-- /.section, /#header -->
<?php if (!user_is_logged_in()): ?>
    <div class="container container-fluid">
        <?php if (isHomePage()): ?>
            <div class="title-wrapper">
                <div class="row">
                    <div class="col-md-4">
                        <hr class="hr-dark"/>
                    </div>
                    <div class="col-md-4 title"><?php print t("QUI SONT LES EXPERTS ?"); ?></div>
                    <div class="col-md-4">
                        <hr class="hr-dark"/>
                    </div>
                </div>
            </div>
            <div class="row">
                <div class="col-md-4">
                    <div class="row">
                        <div class="col-md-2">
                            <?php print $atomiumImg; ?>
                        </div>
                        <div class="col-md-10">
                            <span class="light-blue-text"><?php print t("Professionnels expérimentés, retraités actifs, chercheurs, étudiants..."); ?></span>

                            <p><?php print t("Ils sont dans votre réseau ou dans le réseau emindhub."); ?></p>
                        </div>
                    </div>
                </div>
                <div class="col-md-8">
                    <div class="row">
                        <div class="col-md-offset-2 col-md-4 noPadding">
                            <div class="row">
                                <div class="col-md-3 noPadding">
                                    <?php print $cercleImg; ?>
                                    <map name="test">
                                        <area shape="circle" coords="55,12,11" alt="Mercury" href="#">
                                    </map>
                                </div>
                                <div class="col-md-9 paddingUD">
                                    <?php print t("TOUS"); ?> <br><span class="bold"><?php print t("LES EXPERTS"); ?></span>
                                </div>
                            </div>
                        </div>
                        <div class="col-md-6">
                            <div class="row">
                                <div class="col-md-3">
                                    <?php print $cercleImg; ?>
                                </div>
                                <div class="col-md-9 paddingUD">
                                    <?php print t("LES EXPERTS"); ?> <br><span class="bold"><?php print t("PARRAINÉS"); ?></span>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <div class="row">
                <div class="col-md-4">
                    <div class="little-wrapper">
                        <div class="row">
                            <div class="col-md-2">
                                <?php print $peopleImg; ?>
                            </div>
                            <div class="col-md-10">
                                <span class="light-blue-text"><?php print t("Avec emindhub,"); ?></span>

                                <p><?php print t("Vous les organisez et les sollicitez selon vos besoins."); ?></p>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="col-md-8 ondes-background">
                    <div class="row">
                        <div class="col-md-4">
                            <div class="row">
                                <div class="col-md-3">
                                    <?php print $cercleImg; ?>
                                </div>
                                <div class="col-md-9 paddingUD">
                                    <?php print t("VOTRE RÉSEAU"); ?> <br><span class="bold"><?php print t("ACTIF"); ?></span>
                                </div>
                            </div>
                        </div>
                        <div class="col-md-4">
                            <div class="row">
                                <div class="col-md-3">
                                    <?php print $cercleImg; ?>
                                </div>
                                <div class="col-md-9 paddingUD">
                                    <?php print t("VOS"); ?> <br><span class="bold"><?php print t("ALUMNIS"); ?></span>
                                </div>
                            </div>
                        </div>
                        <div class="col-md-4">
                            <div class="row">
                                <div class="col-md-3">
                                    <?php print $cercleImg; ?>
                                </div>
                                <div class="col-md-9 paddingUD">
                                    <?php print t("VOS CERCLES"); ?> <br><span class="bold"><?php print t("PRIVÉS"); ?></span>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        <?php endif; ?>
        <?php if (!isHomePage()): ?>
            <div class="row">
                <div class="col-md-12">
                    <?php print render($page['content']); ?>
                </div>
            </div>
        <?php endif; ?>
        <div class="row">
            <div class="col-md-8">
                <div class="title-wrapper">
                    <div class="row">
                        <div class="col-md-4">
                            <hr class="hr-dark"/>
                        </div>
                        <div class="col-md-4 title">
                            <?php print t("NOS ENGAGEMENTS"); ?>
                        </div>
                        <div class="col-md-4">
                            <hr class="hr-dark"/>
                        </div>
                    </div>
                </div>
                <div class="row">
                    <div class="col-md-4">
                        <?php print $rapiditeImg; ?>
                    </div>
                    <div class="col-md-4">
                        <?php print $securiteImg; ?>
                    </div>
                    <div class="col-md-4">
                        <?php print $qualiteImg; ?>
                    </div>
                </div>
                <div class="row">
                    <div class="col-md-6">
                              <?php print render($page['theyuseus']); ?>
                    </div>
                    <div class="col-md-6">
                          <?php print render($page['theyareexpert']); ?>

                    </div>
                </div>
            </div>
            <div class="col-md-4">
                <div class="title-wrapper">
                    <div class="row">
                        <div class="col-md-3">
                            <hr class="hr-dark"/>
                        </div>
                        <div class="col-md-6 title">
                            <?php print t('EN SAVOIR + ?'); ?>
                        </div>
                        <div class="col-md-3">
                            <hr class="hr-dark"/>
                        </div>
                    </div>
                </div>
                <?php print render($page['contactform']); ?>
            </div>
        </div>
    </div>
<?php endif; ?>
<?php if (user_is_logged_in()): ?>
    <div class="container container-fluid">

        <!-- START BREADCRUMB AND NAV -->
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

        <?php if ($breadcrumb): ?>
            <div id="breadcrumb"><?php print $breadcrumb; ?></div>
        <?php endif; ?>

        <!-- END BREADCRUMB AND NAV -->


        <div id="main-wrapper">
            <div id="main" class="clearfix">

                <div id="content" class="column">
                    <div class="section">
                        <?php if ($page['highlighted']): ?>
                            <div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
                        <a id="main-content"></a>
                        <?php print render($title_prefix); ?>
                        <?php if ($title): ?><h1 class="title"
                                                 id="page-title"><?php print $title; ?></h1><?php endif; ?>
                        <?php print render($title_suffix); ?>
                        <!-- START TABS -->
                        <?php if ($tabs && isAdminUser()): ?>
                            <div class="tabs"><?php print render($tabs); ?></div>
                        <?php endif; ?>
                        <!-- END TABS -->

                        <?php print render($page['help']); ?>
                        <?php if ($action_links): ?>
                            <ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
                        <?php print render($page['content']); ?>
                        <?php print $feed_icons; ?>
                    </div>
                </div>
                <!-- /.section, /#content -->


                <?php if (FALSE): ?>
                    <?php if ($page['sidebar_first']): ?>
                        <div id="sidebar-first" class="column sidebar">
                            <div class="section">
                                <?php print render($page['sidebar_first']); ?>
                            </div>
                        </div> <!-- /.section, /#sidebar-first -->
                    <?php endif; ?>

                    <?php if ($page['sidebar_second']): ?>
                        <div id="sidebar-second" class="column sidebar">
                            <div class="section">
                                <?php print render($page['sidebar_second']); ?>
                            </div>
                        </div> <!-- /.section, /#sidebar-second -->
                    <?php endif; ?>
                <?php endif; ?>
                <?php if (isHomePage()): ?>
                    <div class="row">
                        <div class="col-md-8">
                            <div class="row subtitle-wrapper">
                              <div class="col-md-6">
                                <?php print render($page['theyuseus']); ?>
                              </div>
                              <div class="col-md-6">
                                <?php print render($page['theyareexpert']); ?>
                              </div>
                            </div>
                        </div>
                        <div class="col-md-4">
                            <div class="row subtitle-wrapper">
                                <?php print render($page['news']); ?>
                            </div>
                        </div>
                    </div>
                <?php endif; ?>
            </div>
        </div>
        <!-- /#main, /#main-wrapper -->
        <div id="footer">
            <div class="section">
                <?php print render($page['footer']); ?>
            </div>
        </div>
        <!-- /.section, /#footer -->
        <?php print render($page['burgermenu']); ?>
    </div></div> <!-- /#page, /#page-wrapper -->

    </div>
<?php endif; ?>
