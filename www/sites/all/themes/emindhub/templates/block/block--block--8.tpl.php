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
          <a href="<?php print $base_url . '/' . drupal_get_path_alias('node/2520'); ?>"><?php print emh_circles_get_circle_logo(node_load('2520')); ?></a>
        <?php endif; ?>

        <?php if (og_is_member('node', '2564', 'user')) : ?>
          <a href="<?php print $base_url . '/' . drupal_get_path_alias('node/2564'); ?>"><?php print emh_circles_get_circle_logo(node_load('2564')); ?></a>
        <?php endif; ?>
      </div>
    <?php endif; ?>

    <?php if (og_is_member('node', '2520', 'user') || og_is_member('node', '2564', 'user')) : ?>
    <div class="col-md-9">
    <?php else : ?>
    <div class="col-md-12 text-center">
    <?php endif; ?>
      <?php if ($logged_in) : ?>
        <a class="btn btn-flash icon-community" href="<?php print drupal_get_path_alias('circles'); ?>"><?php print t('Join circles'); ?></a>
      <?php endif; ?>

      <?php if (user_access('create request content')) : ?>
        <?php echo sprintf(t('%sCreate a request%s'), '<a class="btn btn-client" href="' . $base_url . '/' . drupal_get_path_alias("node/add/request") . '"><span class="glyphicon glyphicon-plus" aria-hidden="true"></span>&nbsp;&nbsp;', '</a>'); ?>
      <?php endif; ?>

      <?php if (user_access('invite experts')) : ?>
        <a class="btn btn-flash icon-user" href="<?php print $base_url . '/' . drupal_get_path_alias('invitations'); ?>"><?php print t('Invite experts'); ?></a>
      <?php endif; ?>
    </div>

  </span>

</section> <!-- /.block -->
