<div class="row">
    <div class="col-md-4 challenge-title"><?php echo t("Answer to a question"); ?></div>
    <div class="col-md-8"><hr class="hr-light"></div>
</div>
<div class="row paddingLR challenge-container">
    <div class="col-md-12">
        <h2><?php print $title; ?></h2>
        <br />
    </div>
    <div class="row">
        <div class="col-md-4">
            <?php print t("Submitted by:"); ?>
            <div class="row">
                <div class="col-md-3 profile-picture"><?php print $variables['user_picture']; ?></div>
                <div class="col-md-9">
                    <div class="bold"><?php print $variables['user_name']; ?></div>
                    <div class="bold"><?php print $variables['name']; ?></div>
                    <div class="bold light-blue-text">Nom Entreprise</div>
                </div>
            </div>
        </div>
        <div class="col-md-4">
            <?php print t("Domain(s):"); ?>
            <div class="challenge-domain softPaddingUD paddingL">
                <?php if (isset($field_domaine[0]['taxonomy_term']->name)): ?>
                <?php print  $field_domaine[0]['taxonomy_term']->name; ?>
                <?php endif; ?>
            </div>
        </div>
        <div class="col-md-4">
            <div class="row">
                <div class="col-md-6"><?php print t("Publication date:"); ?></div>
                <div class="bold"><?php print $elements['#node']->created; ?></div>
            </div>
            <div class="row">
                <div class="col-md-6"><?php print t("Deadline:"); ?></div>
                <div class="bold">
                    <?php if (isset($field_expiration_date[0]['value'])): ?>
                        <?php print $field_expiration_date[0]['value']; ?>
                    <?php endif; ?>
                </div>
            </div>
            <div class="row">
                <div class="col-md-6"><?php print t("Number of responses:"); ?></div>
                <div class="bold"></div>
            </div>
            <div class="row">
                <div class="col-md-6"><?php print t("Award:"); ?></div>
                <div class="bold">
                    <?php if (isset($field_reward[0]['safe_value'])): ?>
                        <?php print $field_reward[0]['safe_value']; ?>
                    <?php endif; ?>
                </div>
            </div>
        </div>
    </div>
    <div class="bold paddingU"><?php print t("Description:"); ?></div>
    <div>
        <?php if (isset($body[0]['safe_value'])): ?>
            <?php print $body[0]['safe_value']; ?>
        <?php endif; ?>
    </div>
    <div class="paddingUD"><button class="btn btn-star"><?php print t("Save in my selection"); ?></button></div>
    <div class="bold"><?php print t("Answer:"); ?></div>
    <div class="row">
        <div class="col-md-12">
            <textarea class="question-answer"></textarea>
        </div>
    </div>
    <div class="row paddingU">
        <div class="col-md-2"><?php print t("Add a picture"); ?></div>
        <div class="col-md-3"><button class="btn btn-expert"><?php print t("Choose your file"); ?></button></div>
        <div class="col-md-6 italic">(Taille fichier < 2.5 Mo)</div>
    </div>
    <div class="row paddingU">
        <div class="col-md-2"><?php print t("Add a video"); ?></div>
        <div class="col-md-3"><button class="btn btn-expert"><?php print t("Choose your file"); ?></button></div>
        <div class="col-md-4"><input class="input-text" type="text" /></div>
        <div class="col-md-3">
            <div class="social-viemo"></div>
            <div class="social-youtube"></div>
            <div class="social-dailymotion"></div>
        </div>
    </div>
    <div class="row paddingU">
        <div class="col-md-6">
            <input type="checkbox" id="displayOnlyCaller" >
            <label for="displayOnlyCaller"><?php print t("I want my answer to be visible only by caller"); ?></label>
        </div>
    </div>
</div>
<div class="paddingUD">
    <div class="inline paddingR"><button class="btn btn-cancel"><?php print t("Cancel"); ?></button></div>
    <div class="inline paddingR"><button class="btn btn-draft"><?php print t("Save draft"); ?></button></div>
    <div class="inline"><button class="btn btn-send"><?php print t("Send"); ?></button></div>
</div>
<!--================================================================================================================================<br />
<?php print render($content); ?>-->