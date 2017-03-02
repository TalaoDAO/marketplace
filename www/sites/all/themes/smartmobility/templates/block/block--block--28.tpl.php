<?php global $base_url, $language; ?>

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
              <span class="block">
                <?php if ($language->language == 'en') : ?>
                  <?php print l(t('Looking for talent'), $base_url . '/' . EMH_SMARTMOBILITY_REGISTER_CLIENT, array('language' => $language, 'attributes' => array('class' => array('signin-client')))); ?>
                <?php else : ?>
                  <?php print l(t('Looking for talent'), $base_url . '/' . $language->language . '/' . EMH_SMARTMOBILITY_REGISTER_CLIENT, array('language' => $language, 'attributes' => array('class' => array('signin-client')))); ?>
                <?php endif; ?>
              </span>
              <span class="separator"></span>
              <span class="block">
                <?php if ($language->language == 'en') : ?>
                  <?php print l(t('I am an employee of Airbus'), $base_url . '/' . EMH_SMARTMOBILITY_REGISTER_EXPERT, array('language' => $language, 'attributes' => array('class' => array('signin-expert')))); ?>
                <?php else : ?>
                  <?php print l(t('I am an employee of Airbus'), $base_url . '/' . $language->language . '/' . EMH_SMARTMOBILITY_REGISTER_EXPERT, array('language' => $language, 'attributes' => array('class' => array('signin-expert')))); ?>
                <?php endif; ?>
              </span>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

</section> <!-- /.block -->
