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
 // echo '<pre>' . print_r($fields['field_domain_lead_experts'], TRUE) . '</pre>'; die;
 // Show $node field, with display parameters
 // print render($content['field_duration_of_the_mission']);
 // Show $node field, with custom display parameters
 // print render(field_view_field('node', $node, 'field_duration_of_the_mission'));
?>

<div class="panel-heading" role="tab" id="domain-<?php print $fields['tid']->content; ?>-title">

  <h4 class="panel-title">
    <span class="statut state-<?php print $fields['field_domain_state']->content; ?>"><?php print $fields['field_domain_state']->content; ?></span>
    <span class="title"><?php print t($fields['name_field_et']->content); ?></span>
  </h4>

  <?php if (isset($fields['field_domain_lead_experts']->content)) : ?>
  <div class="domain-lead-experts">
    <span><?php print t('Lead experts:'); ?>&nbsp;</span><?php print views_embed_view('circle_members','block_1', $fields['field_domain_lead_experts']->content); ?>
  </div>
  <?php endif; ?>

</div>
