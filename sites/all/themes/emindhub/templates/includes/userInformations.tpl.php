<?php
$author = user_load( $node->uid );
// echo '<pre>' . print_r($author, TRUE) . '</pre>';
$first_name = field_get_items('user', $author, 'field_first_name');
$last_name = field_get_items('user', $author, 'field_last_name');
$company = field_get_items('user', $author, 'field_entreprise');
$company = node_load($company[0]['target_id']);
?>
<div class="row submitted">
  <div class="col-sm-12">
    <h3 class="h4"><span><?php print t('Submitted by:'); ?></span></h3>
  </div>
  <div class="col-sm-12">
    <div class="row">

      <?php if ( emh_access_user_name( $node ) == TRUE ) : ?>
      <div class="col-md-5 profile-picture">
        <?php print emindhub_beautiful_author_picture( $node, 'img-circle center-block' ); ?>
      </div>
      <?php endif ?>

      <div class="col-md-7">

        <?php if ( emh_access_user_name( $node ) == TRUE && ( $first_name || $last_name ) ) : ?>
        <p class="user"><strong><span class="author-firstname"><?php print render($first_name[0]['value']); ?></span>&nbsp;<span class="author-lastname"><?php print render($last_name[0]['value']); ?></span></strong></p>
        <?php endif ?>

        <?php if ( emh_access_user_company( $node ) == TRUE && ( $company ) ) : ?>
        <p class="company"><strong><?php print $company->title; ?></strong></p>
        <?php endif ?>

      </div>

    </div>
  </div>
</div>
