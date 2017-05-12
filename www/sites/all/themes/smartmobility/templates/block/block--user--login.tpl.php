<?php global $base_url, $language; ?>

<ul id="menu-user-login" class="nav navbar-nav navbar-right">
  <li>
    <a tabindex="0" id="signUp" class="user-menu sign-up" data-placement="bottom" data-html="true" title="<?php print t('Register'); ?>" data-template='<div class="popover signUp" role="tooltip"><div class="arrow"></div><h3 class="popover-title"></h3><div class="popover-content signUpContent"></div></div>'><?php print t('Registration'); ?></a>
    <div id="signUpContent" class="signUpContent" style="display: none;">
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
  </li>
  <li><span class="navbar-text">|</span></li>
  <li>
    <a tabindex="1" id="signIn" class="user-menu sign-in" data-placement="bottom" data-html="true" title="<?php print t('Connexion'); ?>" data-template='<div class="popover signIn" role="tooltip"><div class="arrow"></div><h3 class="popover-title"></h3><div class="popover-content signInContent"></div></div>'><?php print t('Connexion'); ?></a>
    <div id="signInContent" class="signInContent" style="display: none;">
      <?php $login_block = drupal_get_form('user_login_block'); print drupal_render($login_block); ?>
    </div>
  </li>
</ul>
