<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
global $base_url;
?>
<header id="navbar" role="banner" class="navbar navbar-emh">

  <div class="container">

    <div class="row">

      <div class="col-md-3">

      <a class="logo navbar-btn" href="<?php print $base_url; ?>" title="<?php print t('Home'); ?>">
        <img src="<?php print $base_url; ?>/sites/all/themes/emindhub/logo.png" alt="eMindHub" />
      </a>

      </div> <!-- END .col -->

      <div class="col-md-9">

        <nav class="navbar">

          <div class="navbar-header">
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            </button>
          </div>

          <div class="collapse navbar-collapse">
            <div class="region region-navigation row">
              <section id="block-menu-menu-top-anonymous" class="block block-menu col-sm-11 col-md-11 clearfix">

                <div class="content">
                  <ul class="menu nav nav-justified">
                    <?php if (!empty($content['field_landingpage_how_title'])) : ?>
                    <li class="leaf">
                      <a href="#lp-two">
                        <?php print $field_landingpage_how_title['0']['value']; ?>
                      </a>
                    </li>
                    <?php endif; ?>
                    <?php if (!empty($content['field_landingpage_media_title'])) : ?>
                    <li class="leaf">
                      <a href="#lp-three">
                        <?php print $field_landingpage_media_title['0']['value']; ?>
                      </a>
                    </li>
                    <?php endif; ?>
                    <li class="leaf">
                      <a href="#lp-join"><?php print t('Join eMindHub for free'); ?></a>
                    </li>
                  </ul>
                </div>

              </section>

            </div>
          </div>

        </nav>

      </div> <!-- END .col -->

    </div> <!-- END .row -->

  </div> <!-- END .container -->

</header>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      //print render($content);
    ?>

    <?php if (!empty($title) || !empty($body)) : ?>

    <div id="lp-one" class="landing-section landing-one">
      <div class="container">

        <div class="row">

          <?php if (!empty($content['field_landingpage_image'])) : ?>
          <div class="col-md-2">
            <?php print render($content['field_landingpage_image']); ?>
          </div>
          <?php endif; ?>

          <?php print render($title_prefix); ?>
          <?php if (!$page): ?>
            <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
          <?php else : ?>
          <div class="col-md-10">
            <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
          </div>
          <?php endif; ?>
          <?php print render($title_suffix); ?>

        </div>

        <?php if (!empty($body)) : ?>
          <?php print $body['0']['value']; ?>
        <?php endif; ?>

        <a id="lp-join"></a>
        <?php $register_block = drupal_get_form('user_register_form_landing_page'); print drupal_render($register_block); ?>

      </div>
    </div>

    <?php endif; ?>

    <?php if (!empty($content['field_landingpage_how_title']) || !empty($content['field_landingpage_how_text'])) : ?>
    <div id="lp-two" class="landing-section landing-two">
      <div class="container">

        <?php if (!empty($content['field_landingpage_how_title'])) : ?>
          <?php print render($content['field_landingpage_how_title']); ?>
        <?php endif; ?>

        <?php if (!empty($content['field_landingpage_how_text'])) : ?>
          <?php print render($content['field_landingpage_how_text']); ?>
        <?php endif; ?>

      </div>
    </div>
    <?php endif; ?>

    <?php if (!empty($content['field_landingpage_media_title']) || !empty($content['field_landingpage_media_text'])) : ?>
    <div id="lp-three" class="landing-section landing-three">
      <div class="container">

        <?php if (!empty($content['field_landingpage_media_title'])) : ?>
          <?php print render($content['field_landingpage_media_title']); ?>
        <?php endif; ?>

        <?php if (!empty($content['field_landingpage_media_text'])) : ?>
          <?php print render($content['field_landingpage_media_text']); ?>
        <?php endif; ?>

      </div>
    </div>
    <?php endif; ?>

    <div id="lp-four" class="landing-section landing-four">
      <div class="container">
        <a class="btn btn-success btn-lg" href="#lp-join"><?php print t('Register now'); ?></a>
      </div>
    </div>

  </div>

</div>
