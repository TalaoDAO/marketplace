<div class="row submitted">
  <div class="col-sm-12">
    <h3 class="h4"><span><?php print t('Submitted by:'); ?></span></h3>
  </div>
  <div class="col-sm-12">
    <div class="row">

      <?php if ( emindhub_show_user_name() == TRUE ) : ?>
      <div class="col-md-4 profile-picture">
        <?php print emindhub_show_user_photo( 'img-circle center-block' ); ?>
      </div>
      <?php endif ?>

      <div class="col-md-8">

        <?php if ( emindhub_show_user_name() == TRUE ) : ?>
        <p><strong><?php print emindhub_beautiful_user_name( TRUE ); ?></strong></p>
        <?php endif ?>

        <?php if ( emindhub_show_user_company() == TRUE ) : ?>
        <p><strong><?php print $variables['company_name']; //emindhub_preprocess_node__webform ?></strong></p>
        <?php endif ?>

      </div>

    </div>
  </div>
</div>
