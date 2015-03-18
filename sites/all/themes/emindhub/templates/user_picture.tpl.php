<?php if (isset($account->picture)) {
    if ($account->picture) {
        $img_url = $account->picture->uri;  // the orig image uri
        $style = 'profile_picture';  // or any other custom image style you've created via /admin/config/media/image-styles
        ?>
        <div class="profile-picture">
            <img src="<?php print image_style_url($style, $img_url); ?>"/>
        </div>
    <?php }
}?>