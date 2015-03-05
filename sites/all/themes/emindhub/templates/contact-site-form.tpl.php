<div class="row border-light">
    <div class="col-md-12">
        <div class="row paddingU">
            <div class="col-md-1">
                <img src="<?php print url("sites/all/themes/emindhub/images/bulle.png"); ?>" />
            </div>
            <div class="col-md-10 bold">
                <?php print t("Vous avez une question ?"); ?>
            </div>
        </div>
        <div class="row paddingU">
            <div class="col-md-1">
                <img src="<?php print url("sites/all/themes/emindhub/images/bulle.png"); ?>" />
            </div>
            <div class="col-md-10 bold">
                <?php print t("Vous voulez en savoir plus ?"); ?>
            </div>
        </div>
        <div class="text-wrapper">
            <?php print t("Laissez nous un message, nous vous rappelons  dans les 24h !"); ?>
        </div>
        <form>
            <div class="form-wrapper">
                <?php print t("Civilité :"); ?>
                <select id="selectCivilite" name="civilite" class="form-control-custom select-form">
                    <option value="M">M.</option>
                    <option value="Mme">Mme</option>
                    <option value="Mlle">Mlle</option>
                </select>
                <div class="required">*</div>
            </div>
            <div class="form-wrapper">
                <input type="text" class="form-control-custom" id="nom" placeholder="<?php print t("Votre nom"); ?>" />
                <div class="required">*</div>
            </div>
            <div class="form-wrapper">
                <input type="text" class="form-control-custom" id="prenom" placeholder="<?php print t("Votre prénom"); ?>" />
                <div class="required">*</div>
            </div>
            <div class="form-wrapper">
                <input type="text" class="form-control-custom" id="societe" placeholder="<?php print t("Votre société"); ?>" />
                <div class="required">*</div>
            </div>
            <div class="form-wrapper">
                <input type="text" class="form-control-custom" id="telephone" placeholder="<?php print t("Votre téléphone"); ?>" />
                <div class="required">*</div>
            </div>
            <div class="form-wrapper">
                <input type="email" class="form-control-custom" id="mail" placeholder="<?php print t("Votre email"); ?>" />
                <div class="required">*</div>
            </div>
            <div class="form-wrapper">
                <input type="text" class="form-control-custom" id="message" placeholder="<?php print t("Votre message..."); ?>" />
                <div class="required">*</div>
            </div>
        </form>
        <div class="row">
            <div class="col-md-4">
                <input type="submit" class="btn btn-primary" value="<?php print t("Envoyer"); ?>" />
            </div>
            <div class="col-md-8">
                <span><?php print t("* Champs requis"); ?></span>
            </div>
        </div>
    </div>
</div>
<?php //echo drupal_render_children($form) ?>
