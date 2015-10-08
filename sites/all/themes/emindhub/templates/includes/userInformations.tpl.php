<div class="row submitted">
  <div class="col-sm-12">
    <h3 class="h4"><span><?php print t('Submitted by:'); ?></span></h3>
  </div>
  <div class="col-sm-12">
    <div class="row">

      <?php if ( emindhub_show_user_name( $node ) == TRUE ) : ?>
      <div class="col-md-5 profile-picture">
        <?php print emindhub_beautiful_author_picture( $node, 'img-circle center-block' ); ?>
      </div>
      <?php endif ?>

      <div class="col-md-7">

        <?php if ( emindhub_show_user_name( $node ) == TRUE ) : ?>
        <p><strong><?php print emindhub_beautiful_user_name( 'node', FALSE ); ?></strong></p>
        <?php endif ?>

        <?php if ( emindhub_show_user_company( $node ) == TRUE ) : ?>
        <p><strong><?php print $variables['company_name']; //emindhub_preprocess_node__webform ?></strong></p>
        <?php endif ?>

      </div>

    </div>
  </div>
</div>
