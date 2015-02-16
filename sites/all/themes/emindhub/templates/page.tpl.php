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
  <div id="page-wrapper"><div id="page">
    <div id="header">
        <div class="section clearfix paddingU">
            <?php require_once __DIR__.'/includes/_header.tpl.php' ?>

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
                                    <?php print $demandeImg; ?>
                                </div>
                            </div>
                            <div class="row inscription-image-wrapper">
                                <div class="col-md-12">
                                    <?php print $expertiseImg; ?>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>

            <div class="container container-fluid">
                <?php print render($page['header']); ?>
            </div>
        </div>
    </div> <!-- /.section, /#header -->
    <?php if (!drupal_is_front_page()): ?>
        <div class="container container-fluid">
            <div class="title-wrapper">
                <div class="row">
                    <div class="col-md-4">
                        <hr class="hr-dark" />
                    </div>
                    <div class="col-md-4 title">QUI SONT LES EXPERTS ?</div>
                    <div class="col-md-4">
                        <hr class="hr-dark" />
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
                            <span class="light-blue-text">Professionnels expérimentés, retraités actifs, chercheurs, étudiants...</span>
                            <p>Ils sont dans votre réseau ou dans le réseau emindhub.</p>
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
                                    TOUS <br><span class="bold">LES EXPERTS</span>
                                </div>
                            </div>
                        </div>
                        <div class="col-md-6">
                            <div class="row">
                                <div class="col-md-3">
                                    <?php print $cercleImg; ?>
                                </div>
                                <div class="col-md-9 paddingUD">
                                    LES EXPERTS <br><span class="bold">PARRAINÉS</span>
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
                                <span class="light-blue-text">Avec emindhub,</span>
                                <p>Vous les organisez et les sollicitez selon vos besoins.</p>
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
                                    VOTRE RÉSEAU <br><span class="bold">ACTIF</span>
                                </div>
                            </div>
                        </div>
                        <div class="col-md-4">
                            <div class="row">
                                <div class="col-md-3">
                                    <?php print $cercleImg; ?>
                                </div>
                                <div class="col-md-9 paddingUD">
                                    VOS <br><span class="bold">ALUMNIS</span>
                                </div>
                            </div>
                        </div>
                        <div class="col-md-4">
                            <div class="row">
                                <div class="col-md-3">
                                    <?php print $cercleImg; ?>
                                </div>
                                <div class="col-md-9 paddingUD">
                                    VOS CERCLES <br><span class="bold">PRIVÉS</span>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
            <div class="row">
                <div class="col-md-8">
                    <div class="title-wrapper">
                        <div class="row">
                            <div class="col-md-4">
                                <hr class="hr-dark" />
                            </div>
                            <div class="col-md-4 title">
                                NOS ENGAGEMENTS
                            </div>
                            <div class="col-md-4">
                                <hr class="hr-dark" />
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
                            <div class="subtitle-wrapper">
                                <div class="row">
                                    <div class="col-md-6 light-blue-text noPadding">
                                        ILS UTILISENT EMINDHUB
                                    </div>
                                    <div class="col-md-5">
                                        <hr class="hr-light" />
                                    </div>
                                    <div class="col-md-1">
                                        <?php print $pointImg; ?>
                                    </div>
                                </div>
                            </div>
                            <div class="row">
                                <div class="col-md-12">
                                    <?php print $aerofuturImg; ?>
                                </div>
                            </div>
                        </div>
                        <div class="col-md-6">
                            <div class="subtitle-wrapper">
                                <div class="row">
                                    <div class="col-md-11 light-blue-text">
                                        ILS SONT EXPERTS SUR EMINDHUB
                                    </div>
                                    <div class="col-md-1">
                                        <?php print $pointImg; ?>
                                    </div>
                                </div>
                            </div>
                            <div class="row">
                                <div class="col-md-12">
                                    <?php print $jmLbcImg; ?>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="col-md-4">
                    <div class="title-wrapper">
                        <div class="row">
                            <div class="col-md-3">
                                <hr class="hr-dark" />
                            </div>
                            <div class="col-md-6 title">
                                EN SAVOIR + ?
                            </div>
                            <div class="col-md-3">
                                <hr class="hr-dark" />
                            </div>
                        </div>
                    </div>
                    <!--<div class="row border-light">
                        <div class="col-md-12">
                            <div class="row paddingU">
                                <div class="col-md-1">
                                    <?php /*print $bulleImg; */?>
                                </div>
                                <div class="col-md-10 bold">
                                    Vous avez une question ?
                                </div>
                            </div>
                            <div class="row paddingU">
                                <div class="col-md-1">
                                    <?php /*print $bulleImg; */?>
                                </div>
                                <div class="col-md-10 bold">
                                    Vous voulez en savoir plus ?
                                </div>
                            </div>
                            <div class="text-wrapper">
                                Laissez nous un message, nous vous rappelons  dans les 24h !
                            </div>
                            <form>
                                <div class="form-wrapper">
                                    Civilité :
                                    <select id="selectCivilite" name="civilite" class="form-control-custom select-form">
                                        <option value="M">M.</option>
                                        <option value="Mme">Mme</option>
                                        <option value="Mlle">Mlle</option>
                                    </select>
                                    <div class="required">*</div>
                                </div>
                                <div class="form-wrapper">
                                    <input type="text" class="form-control-custom" id="nom" placeholder="Votre nom" />
                                    <div class="required">*</div>
                                </div>
                                <div class="form-wrapper">
                                    <input type="text" class="form-control-custom" id="prenom" placeholder="Votre prénom" />
                                    <div class="required">*</div>
                                </div>
                                <div class="form-wrapper">
                                    <input type="text" class="form-control-custom" id="societe" placeholder="Votre société" />
                                    <div class="required">*</div>
                                </div>
                                <div class="form-wrapper">
                                    <input type="text" class="form-control-custom" id="telephone" placeholder="Votre téléphone" />
                                    <div class="required">*</div>
                                </div>
                                <div class="form-wrapper">
                                    <input type="email" class="form-control-custom" id="mail" placeholder="Votre email" />
                                    <div class="required">*</div>
                                </div>
                                <div class="form-wrapper">
                                    <input type="text" class="form-control-custom" id="message" placeholder="Votre message..." />
                                    <div class="required">*</div>
                                </div>
                            </form>
                            <div class="row">
                                <div class="col-md-4">
                                    <input type="submit" class="btn btn-primary" value="Envoyer" />
                                </div>
                                <div class="col-md-8">
                                    <span>* Champs requis</span>
                                </div>
                            </div>
                        </div>
                    </div>-->
                    <?php print render($page['contactform']); ?>
                </div>
            </div>
        </div>
    <?php endif; ?>
    <?php if (drupal_is_front_page()): ?>
        <div class="container container-fluid">
        <?php if ($main_menu || $secondary_menu): ?>
            <div id="navigation"><div class="section">
                    <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix')), 'heading' => t('Main menu'))); ?>
                    <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary-menu', 'class' => array('links', 'inline', 'clearfix')), 'heading' => t('Secondary menu'))); ?>
                </div></div> <!-- /.section, /#navigation -->
        <?php endif; ?>

        <?php if ($breadcrumb): ?>
            <div id="breadcrumb"><?php print $breadcrumb; ?></div>
        <?php endif; ?>

        <?php print $messages; ?>

            <div id="main-wrapper"><div id="main" class="clearfix">

                <div id="content" class="column"><div class="section">
                    <?php if ($page['highlighted']): ?><div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
                    <a id="main-content"></a>
                    <?php print render($title_prefix); ?>
                    <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
                    <?php print render($title_suffix); ?>
                    <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
                    <?php print render($page['help']); ?>
                    <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
                    <?php print render($page['content']); ?>
                    <?php print $feed_icons; ?>
                </div></div> <!-- /.section, /#content -->

            <?php if ($page['sidebar_first']): ?>
                <div id="sidebar-first" class="column sidebar"><div class="section">
                        <?php print render($page['sidebar_first']); ?>
                    </div></div> <!-- /.section, /#sidebar-first -->
            <?php endif; ?>

            <?php if ($page['sidebar_second']): ?>
                <div id="sidebar-second" class="column sidebar"><div class="section">
                        <?php print render($page['sidebar_second']); ?>
                    </div></div> <!-- /.section, /#sidebar-second -->
            <?php endif; ?>

            </div></div> <!-- /#main, /#main-wrapper -->
        <div id="footer"><div class="section">
                <?php print render($page['footer']); ?>
            </div></div> <!-- /.section, /#footer -->
        </div></div> <!-- /#page, /#page-wrapper -->

        </div>
    <?php endif; ?>
