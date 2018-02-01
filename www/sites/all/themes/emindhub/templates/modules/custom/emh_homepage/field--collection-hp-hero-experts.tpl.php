<?php foreach ($items as $delta => $item): ?>
  <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?> hero-expert hero-expert-<?php print $delta; ?>"<?php print $item_attributes[$delta]; ?>>
    <?php print render($item); ?>
  </div>
<?php endforeach; ?>
