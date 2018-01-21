<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <?php print render($item); ?>
    <?php endforeach; ?>
  </div>
</div>
