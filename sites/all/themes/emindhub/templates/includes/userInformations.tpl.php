<?php if (isset($field_anonymous[0]['value']) && $field_anonymous[0]['value'] == 0) {
    print t("Submitted by:"); ?>
    <div class="row">
        <div class="col-md-4 col-xs-5 profile-picture">
            <?php
            $account = user_load($uid);
            if ($account) {
                if ($account->field_photo && $account->field_photo[LANGUAGE_NONE][0]) {
                    $path = $account->field_photo[LANGUAGE_NONE][0]['uri'];
                }
            }
            if(isset($path) && $path) {   ?>
                <img src="<?php print image_style_url('profile_picture', $path); ?>"/>
            <?php } ?>

            <?php
            /*print $variables['user_picture'];
            $user = user_load($uid);
            print theme('user_picture', array('account' =>$user));*/
            ?>
        </div>
        <div class="col-md-8 col-xs-7">
            <div class="paddingU bold"><?php print $variables['user_name']; ?></div>
            <div class="bold"><?php print $variables['name']; ?></div>
            <div class="bold light-blue-text">
                <?php print $variables['company_name']; //emindhub_preprocess_node__webform ?>
            </div>
        </div>
    </div>
<?php } ?>