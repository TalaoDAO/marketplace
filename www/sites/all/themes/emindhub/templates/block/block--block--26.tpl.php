<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> emh-module select-persona-wrapper clearfix"<?php print $attributes; ?>>
  <div class="background-div background-div-left"></div>
  <div class="background-div background-div-right"></div>

  <div class="select-persona container">

    <?php if ($title): ?>
    <div class="select-persona-title">
      <!-- <h2<?php print $title_attributes; ?>><span><?php print $title; ?></span></h2> -->
      <?php print t('The smart way to access smart people'); ?>
    </div>
    <?php endif;?>

    <div class="select-persona-subtitle">
      <?php print t('in aviation, space and nuclear industry'); ?>
    </div>

    <div class="row select-persona-buttons">

      <div class="persona-customer col-xs-6">
        <a class="button" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('You need expertise'); ?></a>
        <p><?php print t('Get quick access to the best experts'); ?></p>
      </div>

      <div class="persona-expert col-xs-6">
        <a class="button" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('You have expertise'); ?></a>
        <p><?php print t('Respond to requests matching your expertise'); ?></p>
      </div>

    </div>
  </div>

</section><!-- /.select-persona-wrapper -->
