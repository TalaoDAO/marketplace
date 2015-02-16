<div class="row border-light">
    <div class="col-md-12">
        <div class="row paddingU">
            <div class="col-md-1">
                <img src="./sites/all/themes/emindhub/images/bulle.png" />
            </div>
            <div class="col-md-10 bold">
                Vous avez une question ?
            </div>
        </div>
        <div class="row paddingU">
            <div class="col-md-1">
                <img src="./sites/all/themes/emindhub/images/bulle.png" />
            </div>
            <div class="col-md-10 bold">
                Vous voulez en savoir plus ?
            </div>
        </div>
        <div class="text-wrapper">
            Laissez nous un message, nous vous rappelons  dans les 24h !
        </div>
        <form>
            <div class="form-wrapper">
                Civilité :
                <select id="selectCivilite" name="civilite" class="form-control-custom select-form">
                    <option value="M">M.</option>
                    <option value="Mme">Mme</option>
                    <option value="Mlle">Mlle</option>
                </select>
                <div class="required">*</div>
            </div>
            <div class="form-wrapper">
                <input type="text" class="form-control-custom" id="nom" placeholder="Votre nom" />
                <div class="required">*</div>
            </div>
            <div class="form-wrapper">
                <input type="text" class="form-control-custom" id="prenom" placeholder="Votre prénom" />
                <div class="required">*</div>
            </div>
            <div class="form-wrapper">
                <input type="text" class="form-control-custom" id="societe" placeholder="Votre société" />
                <div class="required">*</div>
            </div>
            <div class="form-wrapper">
                <input type="text" class="form-control-custom" id="telephone" placeholder="Votre téléphone" />
                <div class="required">*</div>
            </div>
            <div class="form-wrapper">
                <input type="email" class="form-control-custom" id="mail" placeholder="Votre email" />
                <div class="required">*</div>
            </div>
            <div class="form-wrapper">
                <input type="text" class="form-control-custom" id="message" placeholder="Votre message..." />
                <div class="required">*</div>
            </div>
        </form>
        <div class="row">
            <div class="col-md-4">
                <input type="submit" class="btn btn-primary" value="Envoyer" />
            </div>
            <div class="col-md-8">
                <span>* Champs requis</span>
            </div>
        </div>
    </div>
</div>
<?php //echo drupal_render_children($form) ?>
