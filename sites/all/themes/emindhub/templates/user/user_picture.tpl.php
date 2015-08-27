<?php
$account = user_load($variables['account']->uid);
?>

<?php if ($account) {
  if ($account->field_photo && $account->field_photo[LANGUAGE_NONE][0]) {
    $path = $account->field_photo[LANGUAGE_NONE][0]['uri'];
  }
} ?>

<?php if(isset($path) && $path) { ?>
<div class="profile-picture">
  <img src="<?php print image_style_url('profile_picture', $path); ?>" />
</div>
<?php } ?>
