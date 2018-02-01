<div class="field-items hp-testimonies"<?php print $content_attributes; ?>>
  <?php foreach ($items as $delta => $item): ?>
    <?php print render($item); ?>
  <?php endforeach; ?>
</div>
