<?php global $base_url; ?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $user_picture; ?>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php print $submitted; ?>
    </div>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      // print render($content);
    ?>

    <div class="emh-module customer-emh-expert container">

        <div class="cee-customer cee-block">
            <div class="title">
                <?php print t('Clients') ?>
            </div>
            <ul class="cee-items">
                <li><?php print t('Managers'); ?></li>
                <li><?php print t('Project leaders'); ?></li>
                <li><?php print t('Engineers'); ?></li>
                <li><?php print t('Consultants'); ?></li>
            </ul>
        </div>

        <div class="cee-emh cee-block">
            <div class="title">
                <img class="horizontal" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/logo/logo-h.svg" alt="eMindHub" />
                <img class="vertical"   src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/logo/logo-v.svg" alt="eMindHub" />
            </div>
            <ul class="cee-items">
                <li><?php print t('Content'); ?></li>
                <li><?php print t('Advice'); ?></li>
                <li><?php print t('Projects'); ?></li>
            </ul>
        </div>

        <div class="cee-expert cee-block">
            <div class="title">
                <?php print t('Experts') ?>
            </div>
            <ul class="cee-items">
                <li><?php print t('Employed'); ?></li>
                <li><?php print t('Freelancers'); ?></li>
                <li><?php print t('Retirees'); ?></li>
            </ul>
        </div>

    </div>

    <?php include_once(drupal_get_path('theme','emindhub').'/templates/how-it-works/how-it-works.tpl.php'); ?>
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>
