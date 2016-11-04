<?php if (!empty($fields['field_image']->content)): ?>
<div class="picture">
  <?php print $fields['field_image']->content; ?>
</div>
<?php endif; ?>

<div class="publications-item-content">
  <?php if (!empty($fields['title_field_et']->content)): ?>
  <div class="title">
      <?php print $fields['title_field_et']->content; ?>
  </div>
  <?php endif; ?>

  <?php if (!empty($fields['created']->content) || !empty($fields['field_domain']->content)): ?>
  <div class="metas">
      <span class="meta date"><?php print $fields['created']->content; ?></span>
      <?php if (!empty($fields['created']->content) && !empty($fields['field_domain']->content)): ?>
        |
      <?php endif; ?>
      <?php if (!empty($fields['field_domaine']->content)): ?>
      <span class="meta category"><?php print $fields['field_domaine']->content; ?></span>
      <?php endif; ?>
  </div>
  <?php endif; ?>

  <?php if (!empty($fields['body']->content)): ?>
  <div class="text">
      <?php print $fields['body']->content; ?>
  </div>
  <?php endif; ?>
</div>
