<?php if ($variables['elements']['field_tags']['#items']) { ?>
    <div class="bold"><?php print $variables['elements']['field_tags']['#title']; ?></div>
    <div class="challenge-tag-container">
        <?php
        foreach ($variables['elements']['field_tags']['#items'] as $tag) {
            print sprintf('<span class="challenge-tag">%s</span>', $tag['taxonomy_term']->name);
        } ?>
    </div>
<?php } ?>