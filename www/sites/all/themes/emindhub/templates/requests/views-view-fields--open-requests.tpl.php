<?php global $base_url;
$title = truncate_utf8($fields['title']->content, '50', FALSE, TRUE); ?>
<div class="request-item-head">

  <?php if (!empty($fields['field_request_type']->content)) : ?>
  <div class="request-item-icon">
    <?php print $fields['field_request_type']->content; ?>
  </div>
  <?php endif; ?>

  <div class="title" title="<?php print $fields['title']->content; ?>">
    <span class="request-title"><?php print $title; ?></span>

    <div class="metas">
        <?php if (!empty($fields['field_domaine']->content)) : ?>
        <span class="meta date"><?php print $fields['field_domaine']->content; ?></span>
        <?php endif; ?>
        <?php if (!empty($fields['sticky']->content) && $fields['sticky']->content === 'Urgent' && !empty($fields['field_domaine']->content)) : ?>
          |
        <?php endif; ?>
        <?php if (!empty($fields['sticky']->content) && $fields['sticky']->content === 'Urgent') : ?>
        <span class="meta category"><?php print $fields['sticky']->content; ?></span>
        <?php endif; ?>
    </div>

  </div>

</div>

<div class="text">
  <?php if (!empty($fields['field_prequest_confidential']->content) && $fields['field_prequest_confidential']->content === 'Confidential') : ?>
    <?php print $fields['field_prequest_confidential']->content; ?>
  <?php else : ?>
  <?php print $fields['body']->content; ?>
  <?php endif; ?>
</div>
<a href="#login-connexion" data-toggle="modal" data-target="#login-connexion" class="emh-read-more"><?php print t('Read more'); ?></a>

<div class="service-links">
  <?php print $fields['service_links']->content; ?>
  <?php if (!empty($fields['field_prequest_circles']->content)) : ?>
    <a class="author-link"    href="#login-connexion" data-toggle="modal" data-target="#login-connexion">
      <img src="<?php print $base_url . '/' . drupal_get_path('theme', 'emindhub'); ?>/images/community.svg" class="author-icon" alt="" />
      <?php print $fields['field_prequest_circles']->content; ?>
    </a>
  <?php endif; ?>
</div>
