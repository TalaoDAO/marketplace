<?php

/**
 * @file
 * Theme file for suggestions on the node edit page.
 */

$score_value = array(0 => t('Low'), 1 => t('Low'), 2 => t('Moderate'), 3 => t('High'));
$id = $field_name . '_suggestions';
$for = 'edit-' . strtr(drupal_strtolower($field_name . '-' . $language), array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
?>
<div id='<?php print $id; ?>' class='suggestions'>
  <?php print t('Tag Suggestions: '); ?>
<?php
  if (!empty($suggestions)):
    foreach ($suggestions as $term => $data):
      $relevance = $data['relevance'];
      $size = ceil(3 * $relevance);
      $hover = t('Relevance: ') . $score_value[$size];
      $class = "score-{$size}";
      $term_name = check_plain($term);
?>
    <label class='suggestion <?php print $class; ?>' for='<?php print $for; ?>' title='<?php print $hover; ?>'><?php print $term_name; ?></label>
  <?php endforeach; ?>
<?php endif; ?>
</div>
