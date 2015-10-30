<?php
$author = user_load( $node->uid );
// echo '<pre>' . print_r($author, TRUE) . '</pre>';
$first_name = field_get_items('user', $author, 'field_first_name');
$last_name = field_get_items('user', $author, 'field_last_name');
$company = field_get_items('user', $author, 'field_entreprise');
$company = node_load($company[0]['target_id']);
$activity = field_get_items('user', $author, 'field_entreprise_description');
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
      <?php endif; ?>

      <div class="col-md-7">

        <p class="user"><strong>
          <?php if ( emh_access_user_name( $node ) == TRUE && ( $first_name || $last_name ) ) : ?>
          <span class="author-firstname"><?php print render($first_name[0]['value']); ?></span>&nbsp;<span class="author-lastname"><?php print render($last_name[0]['value']); ?></span>
          <?php else : ?>
          <span class="author-anonymous"><?php print t('Anonymous'); ?></span>
          <?php endif; ?>
        </strong></p>

        <?php if ( emh_access_user_company( $node ) == TRUE && ( $company ) ) : ?>
        <p class="company"><strong><?php print $company->title; ?></strong></p>
        <?php endif; ?>

        <?php if (!empty($field_use_my_entreprise[0]['value'])) : ?>

        <?php if ($field_use_my_entreprise[0]['value'] == 0) : ?>
        <p class="activity"><em><?php print $activity[0]['value']; ?></em></p>
        <?php endif; ?>

        <?php if ($field_use_my_entreprise[0]['value'] == 2) : ?>
        <p class="activity"><em><?php print render($content['field_entreprise_description']); ?></em></p>
        <?php endif; ?>

        <?php endif; ?>

      </div>

    </div>
  </div>
</div>
