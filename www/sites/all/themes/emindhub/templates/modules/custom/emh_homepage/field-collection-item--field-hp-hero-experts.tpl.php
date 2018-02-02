<?php

/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */

$popup_status = $content['field_hp_experts_popup'][0]['#markup'];
$popup_direction = $content['field_hp_experts_popup_direction'][0]['#markup'];
$popup_classes = 'hp-expert-popup ' . $popup_status . ' ' . $popup_direction;
?>

<div class="hp-expert-image">
  <?php print render($content['field_photo']); ?>
</div>
<div class="<?php print $popup_classes; ?>">
  <?php
    print render($content['field_hp_experts_name']);
    print render($content['field_hp_experts_position']);
    print render($content['field_hp_experts_domains']);
  ?>
</div>
