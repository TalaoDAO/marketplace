<?php if ($teaser) : ?>
  <div class="row section">

    <div class="circle-logo">
      <?php if (!empty($content['field_circle_logo'])) : ?>
        <?php print render($content['field_circle_logo']); ?>
      <?php endif; ?>
    </div>

    <div class="circle-title">
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <div class="circle-count">
        <?php print format_plural(og_extras_subscriber_count($node->nid), '@count member', '@count members'); ?>
      </div>
    </div>

    <?php if (!empty($content['body'])) : ?>
      <div class="circle-body">
        <?php print render($content['body']); ?>
      </div>
    <?php endif; ?>

    <div class="circle-membership-infos">
      <?php if (!empty(emh_circles_show_membership_state_info(NULL, NULL, $node))) : ?>
      <span class="circle-membership-state">
        <?php print emh_circles_show_membership_state_info(NULL, NULL, $node); ?>
      </span>
      <?php endif; ?>

      <?php if (!empty(og_extras_subscribe('node', $node))) : ?>
      <span class="circle-membership-links">
        <?php print og_extras_subscribe('node', $node); ?>
      </span>
      <?php endif; ?>
    </div>

  </div>
<?php else: ?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="content"<?php print $content_attributes; ?>>

      <div class="row">
        <div class="col-sm-8">
          <?php if (!empty($content['field_circle_message'])) : ?>
            <?php print render($content['field_circle_message']); ?>
          <?php endif; ?>

          <?php
          $circle_requests_block = module_invoke('views', 'block_view', 'views-ebd3d59bc59a77db1ff1c0c9be295d26');
          if (!empty($circle_requests_block)) print render($circle_requests_block['content']);
          ?>
        </div>

        <div class="col-sm-4">
          <?php if (!empty($content['body']) || !empty($content['field_circle_website'])) : ?>
            <h3><?php print t('About this circle'); ?></h3>

            <?php print render($content['body']); ?>

            <?php if (!empty($content['field_circle_website'])) : ?>
              <?php print render($content['field_circle_website']); ?>
            <?php endif; ?>

            <hr />
          <?php endif; ?>

          <?php if (!empty($managers)) : ?>
          <div class="circle-managers">
            <?php print format_plural(count($manager_uids), 'Manager:', 'Managers:'); ?>
            <?php foreach ($managers as $manager): ?>
              <?php print $manager; ?>&nbsp;
            <?php endforeach; ?>
          </div>
          <?php endif; ?>

        </div>
      </div>

      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        // print render($content);
      ?>
    </div>

    <?php //print render($content['links']); ?>
    <?php //print render($content['comments']); ?>

  </div>
<?php endif; ?>
