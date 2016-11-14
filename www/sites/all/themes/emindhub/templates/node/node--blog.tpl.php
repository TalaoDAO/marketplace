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
            <span><?php print format_date($elements['#node']->created, 'custom', 'j F Y'); ?></span>
            <?php if (!empty($elements['#node']->created) && !empty($content['field_blog_tags'])) : ?>
              -
            <?php endif; ?>
            <?php print render($content['field_blog_tags']); ?>
            <?php print render($content['service_links']); ?>
            <?php //print render($content['links']); ?>
        </div>

        <?php if (!empty($content['field_image'])) : ?>
        <div class="publication-picture mobile">
            <?php print render($content['field_image']); ?>
        </div>
        <?php endif; ?>

        <?php if (!empty($content['body'])) : ?>
        <div class="publication-text">
            <?php print render($content['body']); ?>
        </div>
        <?php endif; ?>

    </article>

    <?php if (!empty($content['field_image'])) : ?>
    <aside class="publication-aside">
        <div class="publication-picture desktop">
          <?php print render($content['field_image']); ?>
        </div>
    </aside>
    <?php endif; ?>

</section>
