<?php
$author = user_load( $node->uid );
// echo '<pre>' . print_r($author, TRUE) . '</pre>';
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

      <div class="col-md-5 profile-picture">
      <?php if (module_exists('emh_access')) : ?>
      <?php if ( emh_access_author_name( $node ) ) : ?>
      <?php print emindhub_beautiful_author_picture( $node, 'img-circle center-block' ); ?>
      <?php endif; ?>
      <?php else : ?>
      <?php print $user_picture; ?>
      <?php endif; ?>
      </div>

      <div class="col-md-7">

        <p class="user"><strong>
          <?php if (module_exists('emh_user')) : ?>
          <?php print emh_user_get_beautiful_author($node); ?>
          <?php else : ?>
          <?php print $name; ?>
          <?php endif; ?>
        </strong></p>

        <?php if (module_exists('emh_access')) : ?>
        <?php if ( emh_access_author_company( $node ) && ( $company ) ) : ?>
        <?php //note to themer, if you do not like check_plain, use render and theme hooks to ensure check_plain is already applied, and never use direct attribute access ?>
        <p class="company"><strong><?php print check_plain($company->title); ?></strong></p>
        <?php endif; ?>
        <?php endif; ?>

        <?php if (!empty($field_use_my_entreprise[0]['value'])) : ?>

        <?php if ($field_use_my_entreprise[0]['value'] == 0) : ?>
        <?php // TODO: security: no filtering here? ?>
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
