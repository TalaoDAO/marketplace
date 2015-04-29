<?php
if (!isset($variables['form']['#block']->region)) { ?>
    <div><?php print c_szLoginToEmh; ?></div>
    <div class="row">
        <!--<div class="col-md-5">
            <div class="facebook-login"><?php //print t("Login with Facebook"); ?></div>
            <div class="twitter-login"><?php //print t("Login with Twitter"); ?></div>
            <div class="linkedin-login"><?php //print t("Login with Linkedin"); ?></div>
        </div>
        <div class="col-md-1 separator"><div class="vertical-line"></div><div class="center-text"><?php //print t("OR"); ?></div><div class="vertical-line"></div></div>-->
        <div class="col-md-12">
            <?php
            $form['name']['#description'] = "";
            $form['name']['#attributes']['placeholder'] = $form['name']['#title'];
            //$form['name']['#attributes']['placeholder'] = t("Email");
            $form['name']['#title_display'] = "invisible";

            $form['pass']['#description'] = "";
            //$form['pass']['#attributes']['placeholder'] = t("Password");
            $form['pass']['#attributes']['placeholder'] = $form['pass']['#title'];
            $form['pass']['#title_display'] = "invisible";

            $form['actions']['submit']['#attributes']['class'][] = "btn";
            $form['actions']['submit']['#attributes']['class'][] = "btn-primary";
            ?>
            <div><?php print render($form['name']); ?></div>
            <div><?php print drupal_render($form['pass']); ?></div>
            <div><?php print drupal_render($form['form_build_id']); ?></div>
            <div><?php print drupal_render($form['form_id']); ?></div>
            <div><?php print drupal_render($form['openid_identifier']); ?></div>
            <div><?php print drupal_render($form['openid.return_to']); ?></div>
            <div><?php print drupal_render($form['openid_links']); ?></div>
            <div><?php print drupal_render($form['actions']); ?></div>
            <!--<div><input type="checkbox" /> Se souvenir de moi</div>
            <div><a href="">Mot de passe oublié ?</a></div>-->
        </div>
    </div>
<?php
}
else {
    print drupal_render($form['name']);
    print drupal_render($form['pass']);
    print drupal_render($form['form_build_id']);
    print drupal_render($form['form_id']);
    print drupal_render($form['openid_identifier']);
    print drupal_render($form['openid.return_to']);
    print drupal_render($form['openid_links']);
    print drupal_render($form['actions']);
}
?>