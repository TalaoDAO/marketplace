<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
// echo '<pre>' . print_r($fields['field_photo'], TRUE) . '</pre>'; die;
// Show $node field, with display parameters
// print render($content['field_duration_of_the_mission']);
// Show $node field, with custom display parameters
// print render(field_view_field('node', $node, 'field_duration_of_the_mission'));
?>
<div class="partner-user row">

  <?php if (isset($fields['field_photo'])) : ?>
  <div class="col-sm-2">
    <?php print $fields['field_photo']->content; ?>
  </div>
  <?php endif; ?>

  <div class="col-sm-10">
  <?php if (isset($fields['field_first_name']) || isset($fields['field_last_name'])) : ?>
  <h3>
    <?php if (isset($fields['field_first_name'])) : ?>
    <?php print $fields['field_first_name']->content; ?>
    <?php endif; ?>
    <?php if (isset($fields['field_last_name'])) : ?>
    <?php print $fields['field_last_name']->content; ?>
    <?php endif; ?>
  </h3>
  <?php endif; ?>

  <?php if (isset($fields['field_titre_metier'])) : ?>
  <h4><?php print $fields['field_titre_metier']->content; ?></h4>
  <?php endif; ?>

  <?php if (isset($fields['field_employment_history'])) : ?>
  <p><?php print $fields['field_employment_history']->content; ?></p>
  <?php endif; ?>

</div>
