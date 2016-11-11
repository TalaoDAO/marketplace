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
    <section class="emh-module who-we-are container">
      <div class="who-we-are-text">
        <?php
          // We hide the comments and links now so that we can render them later.
          hide($content['comments']);
          hide($content['links']);
          print render($content);
        ?>
      </div>
    </section>
    <section id="who-we-are-sponsors" class="emh-module person-list-wrapper container">
        <h3><?php print t('CHANGEME L\'équipe'); ?></h3>
        <ul class="person-list row">
          <li class="person-wrapper">
              <div class="person ">
                  <div class="picture">
                      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/content/node/267/emindhub_Nicolas-Muller.jpg" alt="<?php print t('Nicolas Muller'); ?>" />
                  </div>
                  <div class="content">
                      <div class="name">
                          <?php print t('Nicolas Muller'); ?>
                      </div>
                      <div class="position">
                          <?php print t('CEO'); ?>
                      </div>
                  </div>
              </div>
          </li>
          <li class="person-wrapper">
              <div class="person">
                  <div class="picture">
                      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/content/node/267/emindhub_Yoann-Babel.jpg" alt="<?php print t('Yoann Babel'); ?>" />
                  </div>
                  <div class="content">
                      <div class="name">
                          <?php print t('Yoann Babel'); ?>
                      </div>
                      <div class="position">
                          <?php print t('CTO'); ?>
                      </div>
                  </div>
              </div>
          </li>
        </ul>
    </section>
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>
