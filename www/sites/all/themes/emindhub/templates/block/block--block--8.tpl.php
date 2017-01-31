<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <h2<?php print $title_attributes; ?>><span><?php print $title; ?></span></h2>
  <?php endif;?>
  <?php print render($title_suffix); ?>

  <div class="content">
    <?php if (user_access('create request content')) : ?>
      <?php echo sprintf(t('%sCreate a request%s'), '<a class="btn btn-client" href="' . url("node/add/request") . '"><span class="glyphicon glyphicon-plus" aria-hidden="true"></span>&nbsp;&nbsp;', '</a>'); ?>
    <?php endif; ?>

    <?php if (user_access('invite experts')) : ?>
      <a class="btn btn-flash icon-user" href="<?php print url('invitations'); ?>"><?php print t('Invite experts'); ?></a>
    <?php endif; ?>

    <?php if (user_has_role(3) || user_has_role(4) || user_has_role(5) || user_has_role(6)) : ?>
      <a class="btn btn-flash icon-community" href="<?php print url('circles'); ?>"><?php print t('Join circles'); ?></a>
    <?php endif; ?>

  </span>

</section> <!-- /.block -->
