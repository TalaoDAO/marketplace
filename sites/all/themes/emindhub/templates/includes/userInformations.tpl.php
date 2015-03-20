<?php if (isset($field_anonymous[0]['value']) && $field_anonymous[0]['value'] == 1) {
    print t("Submitted by:"); ?>
    <div class="row">
        <div class="col-md-4 profile-picture"><?php print $variables['user_picture']; ?></div>
        <div class="col-md-8">
            <div class="paddingU bold"><?php print $variables['user_name']; ?></div>
            <div class="bold"><?php print $variables['name']; ?></div>
            <div class="bold light-blue-text">
                <?php print $variables['company_name']; //emindhub_preprocess_node__webform ?>
            </div>
        </div>
    </div>
<?php } ?>