<?php
$fieldFirstName = $elements['field_first_name'];
$fieldLastName = $elements['field_last_name'];
$fieldPicture = $elements['user_picture'];
$fieldProfileTitle = $elements['profile_expert']['view']['profile2'][2]['field_titre_metier'];
$fieldDomain = $elements['profile_expert']['view']['profile2'][2]['field_domaine'];
$fieldReferent = $elements['profile_expert']['view']['profile2'][2]['field_referent'];

$fieldFirstName['#label_display'] = "hidden";
$fieldLastName['#label_display'] = "hidden";
$fieldProfileTitle['#label_display'] = "hidden";
$fieldReferent['#label_display'] = "hidden";
?>
<div class="user-profile paddingUD">
    <fieldset>
        <legend>1 - Mes informations personnelles</legend>
    </fieldset>
    <div class="row">
        <div class="col-md-2">
            <label><?php print $fieldFirstName['#title']; ?></label>
        </div>
        <div class="col-md-4 input-style">
            <?php print render($fieldFirstName); ?>
        </div>
        <div class="col-md-2">
            <label><?php print $fieldLastName['#title']; ?></label>
        </div>
        <div class="col-md-4 input-style">
            <?php print render($fieldLastName); ?>
        </div>
    </div>

    <div class="challenge-tag-container">
        <?php
            foreach ($fieldDomain as $key => $value){
                if (strpos(strtolower($key), "#") === false) {
                    print sprintf('<span class="challenge-tag">%s</span>', render($fieldDomain[$key]));
                }
            }
        ?>
    </div>
    <div class="row">
        <div class="col-md-2">
            <label><?php print $fieldProfileTitle ['#title']; ?></label>
        </div>
        <div class="col-md-4 input-style">
            <?php print render($fieldProfileTitle ); ?>
        </div>
        <div class="col-md-2">
            <label><?php print $fieldReferent['#title']; ?></label>
        </div>
        <div class="col-md-4 input-style">
            <?php print render($fieldReferent); ?>
        </div>
    </div>
</div>

<div class="user-profile paddingUD marginU">
    <div class="row">
        <div class="col-md-5">
            <input type="text" placeholder="<?php print t("I want to give a name to my profile"); ?>">
        </div>
        <div class="col-md-1">
            <button class="btn btn-primary expert"><?php print t("Valider"); ?></button>
        </div>
        <div class="col-md-5">
            <input type="text" placeholder="<?php print t("Link to my website/blog"); ?>">
        </div>
        <div class="col-md-1">
            <button class="btn btn-primary expert"><?php print t("Valider"); ?></button>
        </div>
    </div>
    <div class="row">
        <div class="col-md-3 user-picture"><?php print render($fieldPicture); ?></div>
        <div class="col-md-3">
            <div class="row">
                <div class="col-md-12 paddingD">
                    <button class="btn btn-primary expert"><?php print t("Download a picture"); ?></button>
                </div>
            </div>
            <div class="row">
                <div class="col-md-12 paddingD">
                    <button class="btn btn-primary expert"><?php print t("Add"); ?></button>
                </div>
            </div>
            <div class="row">
                <div class="col-md-12 paddingD">
                    <button class="btn btn-secondary"><?php print t("Cancel"); ?></button>
                </div>
            </div>
        </div>
        <div class="col-md-3">
            <div class="row">
                <div class="col-md-12"><?php print t("Adjust picture"); ?></div>
            </div>
            <div class="row">
                <div class="col-md-12"><?php print render($fieldPicture); ?></div>
            </div>
        </div>
        <div class="col-md-3">
            <div class="row">
                <div class="col-md-12"><?php print t("Preview"); ?></div>
            </div>
            <div class="row">
                <div class="col-md-12"><?php print render($fieldPicture); ?></div>
            </div>
        </div>
    </div>
</div>

<div class="user-profile paddingUD marginU">
    <?php print render($elements['profile_expert']['view']['profile2'][2]['field_skills_set']); ?>
</div>

<hr class="hr-light">
<?php
print render($elements['userpoints']);
?>
<hr class="hr-light">
<?php
print render($elements['og_user_node'][0])."<br>";
print render($elements['og_user_node'][1])."<br>";
print render($elements['og_user_node'][2])."<br>";
print render($elements['og_user_node'][3])."<br>";
print render($elements['og_user_node'][4])."<br>";
print render($elements['og_user_node'][5])."<br>";
print render($elements['og_user_node'][6])."<br>";
print render($elements['og_user_node'][7])."<br>";
print render($elements['og_user_node'][8]);

/*picture
member for
history
send this user a private message*/