<?php
/**
 * @file
 * Node content CCT.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Config Pages: Content'),
  'icon' => NULL,
  'description' => t('The content of the referenced node.'),
  'category' => t('Config Pages'),
  'required context' => array(new ctools_context_optional(t('Any'), 'any')),
);

/**
 * Render the Config Page content.
 */
function config_pages_content_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($conf['bundle']) || empty($conf['view_mode'])) {
    return;
  }

  // Use CP from plugin settings if defined.
  if ($conf['bundle'] != '_none') {
    $bundle = $conf['bundle'];
  }
  else {

    // Use CP from context in another case.
    list($config_page) = $context;
    if (empty($config_page->data)) {
      return;
    }
    $bundle = array_shift($config_page->data);
  }
  $content = config_pages_render($bundle, NULL, $conf['view_mode']);

  $block = new stdClass();
  $block->module = 'config_pages';
  $block->delta  = $conf['bundle'];

  $block->title = '';
  $block->content = $content;

  return $block;
}

/**
 * Returns an edit form for the custom type.
 */
function config_pages_content_content_type_edit_form($form, &$form_state) {

  // Config holder.
  $conf = $form_state['conf'];
  $form['conf'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuration'),
    '#tree' => TRUE,
  );

  // Generate bundle list.
  $entity = entity_get_info('config_pages');
  $bundle_options = array();
  $bundle_options['_none'] = t('Use value from context');
  foreach ($entity['bundles'] as $bundle => $option) {
    $bundle_options[$bundle] = $option['label'];
  }
  $form['conf']['bundle'] = array(
    '#title' => t('Config Page'),
    '#type' => 'select',
    '#description' => t('Select config page to render.'),
    '#options' => $bundle_options,
    '#default_value' => $conf['bundle'],
  );

  // Generate view mode list.
  $view_mode_options = array();
  foreach ($entity['view modes'] as $mode => $option) {
    $view_mode_options[$mode] = $option['label'];
  }

  $form['conf']['view_mode'] = array(
    '#title' => t('View mode'),
    '#type' => 'select',
    '#description' => t('Select a view mode for this config page.'),
    '#options' => $view_mode_options,
    '#default_value' => $conf['view_mode'],
  );

  return $form;
}

/**
 * Submit function.
 */
function config_pages_content_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function config_pages_content_content_type_admin_title($subtype, $conf, $context) {

  $entity = entity_get_info('config_pages');
  $bundle = !empty($entity['bundles'][$conf['bundle']]) ?
    $entity['bundles'][$conf['bundle']]['label'] :
    $conf['bundle'];
  $view_mode = !empty($entity['view modes'][$conf['view_mode']]) ?
    $entity['view modes'][$conf['view_mode']]['label'] :
    $conf['view_mode'];

  return t('Config Pages: rendered "@bundle" in "@mode" mode', array(
    '@bundle' => $bundle,
    '@mode' => $view_mode,
  ));
}
