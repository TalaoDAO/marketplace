<?php global $base_url; ?>
<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <h2<?php print $title_attributes; ?>><span><?php print $title; ?></span></h2>
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <div class="content">

    <?php if (og_is_member('node', '2520', 'user') || og_is_member('node', '2564', 'user')) : ?>
      <div class="col-md-3 highlight-circles">
        <?php if (og_is_member('node', '2520', 'user')) : ?>
          <a href="<?php print $base_url . '/ ' . url('node/2520'); ?>"><?php print emh_circles_get_circle_logo(node_load('2520')); ?></a>
        <?php endif; ?>

        <?php if (og_is_member('node', '2564', 'user')) : ?>
          <a href="<?php print $base_url . '/ ' . url('node/2564'); ?>"><?php print emh_circles_get_circle_logo(node_load('2564')); ?></a>
        <?php endif; ?>
      </div>
    <?php endif; ?>

    <div class="col-md-9">
      <?php if ($logged_in) : ?>
        <a class="btn btn-flash icon-community" href="<?php print url('circles'); ?>"><?php print t('Join circles'); ?></a>
      <?php endif; ?>

      <?php if (user_access('create request content')) : ?>
        <?php echo sprintf(t('%sCreate a request%s'), '<a class="btn btn-client" href="' . url("node/add/request") . '"><span class="glyphicon glyphicon-plus" aria-hidden="true"></span>&nbsp;&nbsp;', '</a>'); ?>
      <?php endif; ?>

      <?php if (user_access('invite experts')) : ?>
        <a class="btn btn-flash icon-user" href="<?php print url('invitations'); ?>"><?php print t('Invite experts'); ?></a>
      <?php endif; ?>
    </div>

  </span>

</section> <!-- /.block -->
