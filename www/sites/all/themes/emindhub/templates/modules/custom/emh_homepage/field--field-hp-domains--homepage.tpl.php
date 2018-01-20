<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="container field-items"<?php print $content_attributes; ?>>
    <div class="row">
      <?php foreach ($items as $delta => $item): ?>
        <div class="col-xs-6 col-sm-3 field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>>
          <?php print render($item); ?>
        </div>
      <?php endforeach; ?>
  </div>
</div>
