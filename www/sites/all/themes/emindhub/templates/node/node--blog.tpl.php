<section id="node-<?php print $node->nid; ?>" class="emh-module publication container <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <article class="publication-main"<?php print $content_attributes; ?>>

        <?php print render($title_prefix); ?>
        <?php if (!$page): ?>
          <div class="emh-title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></div>
          <!-- <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2> -->
        <?php else : ?>
          <div class="emh-title"><?php print $title; ?></div>
          <!-- <h2<?php print $title_attributes; ?>><?php print $title; ?></h2> -->
        <?php endif; ?>
        <?php print render($title_suffix); ?>

        <div class="publication-meta">
            <?php print render($content['field_domaine']); ?>
            <?php if (!empty($elements['#node']->created)) : ?>
  						<span><?php print format_date($elements['#node']->created, 'custom', 'j F Y'); ?></span>
  					<?php endif; ?>
            <?php //print render($content['links']); ?>
        </div>

        <div class="publication-picture mobile">
            <?php print render($content['field_image']); ?>
        </div>

        <div class="publication-text">
            <?php print render($content['body']); ?>
        </div>

        <ul class="publication-navigation">
            <li class="previous"><a href="#"><?php print t('Previous') ?></a></li>
            <li class="back-to-list"><a href="#"><?php print t('Back to list') ?></a></li>
            <li class="next"><a href="#"><?php print t('Next') ?></a></li>
        </ul>

    </article>

    <aside class="publication-aside"><!-- hide full <aside> if empty -->
        <div class="publication-picture desktop">
          <?php print render($content['field_image']); ?>
        </div>
        <!--
            Author bio
        -->
        <?php //print $user_picture; ?>
    </aside>

    <?php //print render($content['comments']); ?>

</section>
