<div class="highlighted jumbotron">
  <div class="container">
    <div class="region region-highlighted row">
      <section id="block-pcp-pcp-profile-percent-complete" class="block block-pcp col-sm-12 clearfix">
        <h2 class="block-title"><span><?php print t('Complete your profile and get launched!'); ?></span></h2>
        <div class="content">
          <?php if (module_exists('pcp')) : ?>
          <?php $pcp_block = module_invoke('pcp', 'block_view', 'pcp_profile_percent_complete'); ?>
          <?php print render($pcp_block['content']); ?>
          <?php else : ?>
          <?php endif; ?>
        </div>
      </section> <!-- /.block -->
    </div>
  </div>
</div>
