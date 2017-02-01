<?php if ($teaser) : ?>
  <div class="row section">
    <div class="circle-logo">
      <?php if (!empty($content['field_circle_logo'])) : ?>
        <?php print render($content['field_circle_logo']); ?>
      <?php endif; ?>
    </div>
    <div class="circle-title">
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <!-- <div class="circle-count"> -->
        <?php //print format_plural(og_extras_subscriber_count($node->nid), '@count member', '@count members'); ?>
      <!-- </div> -->
    </div>
    <?php if (!empty($content['body'])) : ?>
      <div class="circle-body">
        <?php print render($content['body']); ?>
      </div>
    <?php endif; ?>
    <div class="circle-subscribe">
      <?php $state = emh_circles_get_membership_state($node); if (!empty($state)) : ?>
        <em><?php print $state; ?></em>
      <?php endif; ?>
      <?php print og_extras_subscribe('node', $node); ?>
    </div>
  </div>
<?php else: ?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="content"<?php print $content_attributes; ?>>

      <div class="row section">
        <div class="circle-logo">
          <?php if (!empty($content['field_circle_logo'])) : ?>
            <?php print render($content['field_circle_logo']); ?>
          <?php endif; ?>
        </div>
        <div class="circle-count">
          <?php print $subscriber_count; ?>
        </div>
        <div class="circle-subscribe">
          <?php $state = emh_circles_get_membership_state($node); if (!empty($state)) : ?>
            <em><?php print $state; ?></em>
          <?php endif; ?>
          <?php print $subscribe_link; ?>
        </div>
      </div>

      <div class="row">
        <div class="col-sm-8">
          <?php if (!empty($content['field_circle_message'])) : ?>
            <?php print render($content['field_circle_message']); ?>
          <?php endif; ?>

          <?php
          $circle_requests_block = module_invoke('views', 'block_view', 'faq-faq_client_block');
          print render($circle_requests_block['content']);
          ?>
        </div>

        <div class="col-sm-4">
          <?php if (!empty($content['body'])) : ?>
          <div class="circle-body">
            <h3><?php print t('About this circle'); ?></h3>
              <?php print render($content['body']); ?>
          </div>
          <?php endif; ?>

          <?php if (!empty($managers)) : ?>
          <div class="circle-managers">
            <h3><?php print format_plural(count($manager_uids), 'Manager', 'Managers'); ?></h3>
            <div class="row">
              <?php foreach ($managers as $manager): ?>
              <div class="circle-manager">
                <?php print $manager; ?>
              </div>
              <?php endforeach; ?>
            </div>
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
