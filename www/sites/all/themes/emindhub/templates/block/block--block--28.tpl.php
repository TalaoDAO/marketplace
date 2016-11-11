<?php global $base_url; ?>

<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div id="login-connexion" class="modal fade" tabindex="-1" role="dialog">
    <div class="modal-dialog" role="document">
      <div class="modal-content">
        <div class="modal-header">
          <button type="button" class="close" data-dismiss="modal" aria-label="<?php print t('Close'); ?>"><span aria-hidden="true">&times;</span></button>
          <img class="horizontal" src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/logo/logo-h.svg" alt="eMindHub" />
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
              <span><a class="signin-client" href="<?php print url('client/register'); ?>"><?php print t('You\'re a client'); ?></a></span>
              <span class="separator"><?php print t('or'); ?></span>
              <span><a class="signin-expert" href="<?php print url('expert/register'); ?>"><?php print t('You\'re an expert'); ?></a></span>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

</section> <!-- /.block -->
