<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
?>
<?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <div class="panel-group" id="accordion" role="tablist" aria-multiselectable="true">
    <?php foreach ($rows as $id => $row): ?>
      <div class="<?php print $classes_array[$id]; ?> panel panel-default">
        <?php print $row; ?>
      </div>
    <?php endforeach; ?>
  </div>
<?php print $wrapper_suffix; ?>
