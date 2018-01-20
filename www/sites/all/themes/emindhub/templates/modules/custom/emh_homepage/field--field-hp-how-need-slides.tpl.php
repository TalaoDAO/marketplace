<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="slick-how-need field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <?php print render($item); ?>
    <?php endforeach; ?>
  </div>
</div>
