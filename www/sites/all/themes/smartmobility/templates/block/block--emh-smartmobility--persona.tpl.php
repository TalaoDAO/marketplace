<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> emh-module select-persona-wrapper clearfix"<?php print $attributes; ?>>
  <div class="background-div background-div-left"></div>
  <div class="background-div background-div-right"></div>

  <div class="select-persona container">

    <?php if ($title): ?>
    <div class="select-persona-title">
      <span class="smartmobility-title"><?php print $title; ?></span>
    </div>
    <?php endif;?>

    <div class="select-persona-subtitle">
      <?php print t('Une initiative dédiée au redéploiement des salariés d’Airbus dans le secteur de l’aéronautique'); ?>
    </div>

    <div class="row select-persona-buttons">

      <div class="persona-customer col-xs-6">
        <a class="button" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('vous recherchez des talents'); ?></a>
      </div>

      <div class="persona-expert col-xs-6">
        <a class="button" href="#login-connexion" data-toggle="modal" data-target="#login-connexion"><?php print t('Vous êtes salarié Airbus'); ?></a>
      </div>

    </div>
  </div>

</section><!-- /.select-persona-wrapper -->
