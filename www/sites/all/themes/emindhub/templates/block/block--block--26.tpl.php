<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> emh-module select-persona-wrapper clearfix"<?php print $attributes; ?>>

  <div class="select-persona container">

    <?php if ($title): ?>
    <div class="select-persona-title">
      <!-- <h2<?php print $title_attributes; ?>><span><?php print $title; ?></span></h2> -->
      <?php print t('The best experts in aerospace responding to your requests.'); ?>
    </div>
    <?php endif;?>

    <div class="select-persona-subtitle">
      <?php print t('The 1st Smart Professional Network in aerospace.'); ?>
    </div>

    <div class="row select-persona-buttons">

      <div class="persona-customer col-xs-6">
        <a class="button" href="#"><?php print t('You\'re a client'); ?></a>
        <p><?php print t('Get quick access to the best experts'); ?></p>
      </div>

      <div class="persona-expert col-xs-6">
        <a class="button" href="#"><?php print t('You\'re an expert'); ?></a>
        <p><?php print t('Respond to requests matching your expertise'); ?></p>
      </div>

    </div>
  </div>

</section><!-- /.select-persona-wrapper -->
