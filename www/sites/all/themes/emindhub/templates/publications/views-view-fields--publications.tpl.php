<?php $title = truncate_utf8($fields['title_field_et']->content, '75', FALSE, TRUE); ?>
<?php if (!empty($fields['field_image']->content)) : ?>
<div class="picture">
  <?php print $fields['field_image']->content; ?>
</div>
<?php endif; ?>

<div class="publications-item-content">
  <?php if (!empty($fields['title_field_et']->content)) : ?>
  <div class="title" title="<?php print $fields['title_field_et']->content; ?>">
      <a href="<?php print $fields['path']->content; ?>"><?php print $title; ?></a>
  </div>
  <?php endif; ?>

  <?php if (!empty($fields['created']->content) || !empty($fields['field_blog_tags']->content)) : ?>
  <div class="metas">
      <span class="meta date"><?php print $fields['created']->content; ?></span>
      <?php if (!empty($fields['created']->content) && !empty($fields['field_blog_tags']->content)) : ?>
        |
      <?php endif; ?>
      <?php if (!empty($fields['field_blog_tags']->content)) : ?>
      <span class="meta category"><?php print $fields['field_blog_tags']->content; ?></span>
      <?php endif; ?>
  </div>
  <?php endif; ?>

  <?php if (!empty($fields['body']->content)) : ?>
  <div class="text">
      <?php print $fields['body']->content; ?>
  </div>
  <?php endif; ?>
</div>

<a href="<?php print $fields['path']->content; ?>" class="emh-read-more"><?php print t('Read more'); ?></a>
