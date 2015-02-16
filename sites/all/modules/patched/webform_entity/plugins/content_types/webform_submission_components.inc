<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Webform Components'),
  'description' => t('The rendered webform components.'),
  'required context' => new ctools_context_required(t('Webform Submission'), 'entity:webform_submission_entity'),
  'category' => t('Webform Context'),
  'defaults' => array(
    'fields' => TRUE,
  ),
);

/**
 * Render the custom content type.
 */
function webform_entity_webform_submission_components_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  // Get a shortcut to the webform_submission.
  $submission = $context->data;
  $node = node_load($submission->nid);

  // Build the content type block.
  $block = new stdClass();
  $block->module  = 'webform_submission_components';
  $block->title   = 'Components';
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  if (isset($conf['fields']) && !$conf['fields']) {
    $submission->skip_fields = TRUE;
  }
  $block->content = webform_submission_render($node, $submission, NULL, 'html');
  $block->delta   = $submission->sid;

  return $block;
}

/**
 * Returns an edit form for custom type settings.
 */
function webform_entity_webform_submission_components_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['fields'] = array(
    '#title' => t('Display the webform entity fields.'),
    '#type' => 'checkbox',
    '#default_value' => $conf['fields'],
    '#description' => t('Fields supplised by '),
  );
  return $form;
}

/**
 * Submit handler for the custom type settings form.
 */
function webform_entity_webform_submission_components_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Returns the administrative title for a type.
 */
function webform_entity_webform_submission_components_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" components', array('@s' => $context->identifier));
}
