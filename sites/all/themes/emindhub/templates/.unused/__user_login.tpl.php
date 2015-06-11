<div class="popup">
    <div><?php print t("Se connecter à EmindHub"); ?> :</div>
    <div class="row">
        <div class="col-md-5">
            <div class="row">
                <div class="col-md-12">
                    <div class="facebook-login"><?php print t("Login with Facebook"); ?></div>
                </div>
            </div>
            <div class="row">
                <div class="col-md-12">
                    <div class="twitter-login"><?php print t("Login with Twitter"); ?></div>
                </div>
            </div>
            <div class="row">
                <div class="col-md-12">
                    <div class="linkedin-login"><?php print t("Login with Linkedin"); ?></div>
                </div>
            </div>
        </div>
        <div class="col-md-1">OU</div>
        <div class="col-md-6">
            <div><input type="text" class="form-control-custom" placeholder="Votre email" /></div>
            <div><input type="password" placeholder="<?php print t("Votre mot de passe"); ?>" /></div>
            <div><input type="checkbox" /><?php print t("Se souvenir de moi"); ?></div>
            <div><input type="submit" value="<?php print t("VALIDER"); ?>" /></div>
            <div><a href=""><?php print t("Mot de passe oublié ?"); ?></a></div>
        </div>
    </div>
</div>

<div class="form-item">
    <label for="edit-name">Username: <span class="form-required" title="This field is required.">*</span></label>
    <input type="text" maxlength="60" name="name" id="edit-name"  size="30" value="" tabindex="1" class="form-text required" />
    <div class="description">enter your username</div>
</div>
<div class="form-item">
    <label for="edit-pass">Password: <span class="form-required" title="This field is required.">*</span></label>
    <input type="password" name="pass" id="edit-pass"  size="40"  tabindex="2" class="form-text required" />
    <div class="description">enter your password</div>
</div>
<input type="hidden" name="form_id" id="edit-user-login" value="user_login"  />
<input type="submit" name="op" id="edit-submit" value="Log in"  tabindex="3" class="form-submit" />
<p><a class="textlink" href="?q=user/password">Forgotten your Password?</a></p>