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
?>

<?php global $base_url; ?>

<div class="request-item">

  <?php if (!empty($fields['request_type']->content)) : ?>
  <div class="request-icon">
    <?php print $fields['request_type']->content; ?>
  </div>
  <?php endif; ?>

  <div class="request-infos">
    <span class="request-title"><?php print $fields['title']->content; ?></span>

    <?php if (!empty($fields['field_domaine']->content)) : ?>
    <span class="request-domains"><?php print $fields['field_domaine']->content; ?></span>
    <?php endif; ?>

    <?php if (!empty($fields['request_status']->content)) : ?>
    <span class="request-status"><?php print $fields['request_status']->content; ?></span>
    <?php endif; ?>

    <?php if (!empty($fields['total_answers']->content)) : ?>
    <span class="request-submission-count"><?php print $fields['total_answers']->content; ?></span>
    <?php endif; ?>

    <?php if (!empty($fields['language']->content)) : ?>
    <span class="request-language"><?php print $fields['language']->content; ?></span>
    <?php endif; ?>
  </div>

  <?php if (!empty($fields['og_group_ref']->content)) : ?>
  <span class="request-circles"><?php print $fields['og_group_ref']->content; ?></span>
  <?php endif; ?>

</div>
