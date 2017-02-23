<section id="<?php print $block_html_id; ?>" class="emh-module <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content">
    <ul class="nav navbar-nav">
      <li>
        <a tabindex="0" id="signUp" class="user-menu sign-up" data-placement="bottom" data-html="true" title="<?php print t('Inscription'); ?>" data-template='<div class="popover signUp" role="tooltip"><div class="arrow"></div><h3 class="popover-title"></h3><div class="popover-content signUpContent"></div></div>'><?php print t('Inscription'); ?></a>
        <div id="signUpContent" class="signUpContent" style="display: none;">
          <h4><?php print sprintf(t('%sSign-in in 1 minute%s and start%s'), '<span>', '</span><span>', '</span>'); ?></h4>
          <span class="block"><a class="signin-client" href="<?php print url('client/register'); ?>"><?php print t('Vous recherchez des talents'); ?></a></span>
          <span class="separator"></span>
          <span class="block"><a class="signin-expert" href="<?php print url('expert/register'); ?>"><?php print t('Vous êtes un employé'); ?></a></span>
          <?php
          if (module_exists('hybridauth')) {
            $element['#type'] = 'hybridauth_widget';
            print drupal_render($element);
          }
          ?>
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
  </div>

</section>
