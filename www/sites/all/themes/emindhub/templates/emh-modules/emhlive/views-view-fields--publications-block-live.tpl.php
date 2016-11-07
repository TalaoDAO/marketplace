<?php if (!empty($fields['title_field_et']->content)): ?>
  <div class="emhlive-item-title">
    <?php print $fields['title_field_et']->content; ?>
  </div>
<?php endif; ?>

<?php if (!empty($fields['created']->content) || !empty($fields['field_domain']->content)): ?>
  <div>
    <?php if (!empty($fields['created']->content)): ?>
    <span class="emhlive-item-meta emhlive-item-date"><?php print $fields['created']->content; ?></span>
    <?php endif; ?>

    <?php if (!empty($fields['created']->content) && !empty($fields['field_domain']->content)): ?>
      |
    <?php endif; ?>

    <?php if (!empty($fields['field_domaine']->content)): ?>
    <span class="emhlive-item-meta emhlive-item-category"><?php print $fields['field_domaine']->content; ?></span>
    <?php endif; ?>

  </div>
<?php endif; ?>

<?php if (!empty($fields['body']->content)): ?>
  <div class="emhlive-item-text">
    <?php print $fields['body']->content; ?>
  </div>
<?php endif; ?>
