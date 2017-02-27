<?php global $base_url; ?>

<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div id="login-connexion" class="modal fade" tabindex="-1" role="dialog">
    <div class="modal-dialog" role="document">
      <div class="modal-content">
        <div class="modal-header">
          <button type="button" class="close" data-dismiss="modal" aria-label="<?php print t('Close'); ?>"><span aria-hidden="true">&times;</span></button>
          <span class="smartmobility-title"><?php print t('Smart Mobility'); ?></span>
        </div>
        <div class="modal-body">
          <div class="row">
            <div class="signInContent">
              <h3><?php print t('Connexion'); ?></h3>
              <?php $login_block = drupal_get_form('user_login_block'); print drupal_render($login_block); ?>
            </div>
            <div class="signUpContent">
              <h3><?php print t('Registration'); ?></h3>
              <h4><?php print sprintf(t('%sSign-in in 1 minute%s and start%s'), '<span>', '</span><span>', '</span>'); ?></h4>
              <span class="block"><a class="signin-client" href="<?php print url($base_url . '/' . EMH_SMARTMOBILITY_REGISTER_CLIENT); ?>"><?php print t('Vous recherchez des talents'); ?></a></span>
              <span class="separator"></span>
              <span class="block"><a class="signin-expert" href="<?php print url($base_url . '/' . EMH_SMARTMOBILITY_REGISTER_EXPERT); ?>"><?php print t('Vous êtes salarié Airbus'); ?></a></span>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

</section> <!-- /.block -->
