<div class="row">

  <?php if (isset($field_anonymous[0]['value']) && $field_anonymous[0]['value'] == 1) : ?>
  <div class="col-md-2 col-xs-5 profile-picture">
    <?php
    $account = user_load($uid);
    if ($account) {
      if ($account->field_photo && $account->field_photo[LANGUAGE_NONE][0]) {
        $path = $account->field_photo[LANGUAGE_NONE][0]['uri'];
      }
    }
    if(isset($path) && $path) {  ?>
      <img src="<?php print image_style_url('profile_picture', $path); ?>" class="img-circle center-block" />
    <?php } ?>

    <?php
    /*print $variables['user_picture'];
    $user = user_load($uid);
    print theme('user_picture', array('account' =>$user));*/
    ?>
  </div>
  <?php endif ?>

  <div class="col-md-10 col-xs-7">

    <?php if (isset($field_anonymous[0]['value']) && $field_anonymous[0]['value'] == 1) : ?>
    <p><?php print emindhub_beautiful_user_name(TRUE); ?></p>
    <?php endif ?>

    <?php if (isset($field_show_entreprise[0]['value']) && $field_show_entreprise[0]['value'] == 1) : ?>
    <p>
      <b><?php print $variables['company_name']; //emindhub_preprocess_node__webform ?></b><br />
      <?php if (isset($field_use_my_entreprise[0]['value']) && $field_use_my_entreprise[0]['value'] != 0) { ?>
      <?php if (isset($field_use_my_entreprise) && $field_use_my_entreprise[0]['value'] == 2) { ?>
      <?php print $field_entreprise_description[0]['value']; ?>
      <?php } else { ?>
      <?php print $company_description; //emindhub_preprocess_node__webform ?>
      <?php } ?>
      <?php } ?>
    </p>
    <?php endif ?>

  </div>

</div>
