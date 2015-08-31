<?php if ($variables['elements']['field_tags']['#items']) { ?>
    <div class="bold"><?php print $variables['elements']['field_tags']['#title']; ?></div>
    <div class="challenge-tag-container">
        <?php
//kpr($variables['elements']['field_tags']['#items']);
        foreach ($variables['elements']['field_tags']['#items'] as $tag) {
            print sprintf('<span class="challenge-tag">%s</span>',
              l($tag['taxonomy_term']->name, drupal_get_path_alias('taxonomy/term/' .$tag['taxonomy_term']->tid )));
        } ?>
    </div>
<?php } ?>
