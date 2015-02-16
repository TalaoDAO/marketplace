<?php

/**
 * @file
 * Plugin to handle the 'webform_submission' content type which allows individual webform submissions
 * to be embedded into a panel.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Webform Submission'),
  'single' => TRUE,
  'defaults' => array(
    'sid' => '',
    'identifier' => '',
  ),
  'title' => t('Existing webform submission'),
  'description' => t('Add a webform submission from your site as content.'),
  'category' => t('Custom'),
  'top level' => TRUE,
  'js' => array('misc/autocomplete.js'),
);

/**
 * Output function for the 'webform submission' content type.
 *
 * Outputs a webform submission based on the module and delta supplied in the configuration.
 */
function webform_entity_webform_submission_content_type_render($subtype, $conf, $panel_args) {
  $sid = $conf['sid'];
  $block = new stdClass();

  // TODO: Ctools' own node content type has the @ and % switched in these code block
  // but that doesn't work for us.  Figure out what we're doing wrong...
  foreach (explode('/', $_GET['q']) as $id => $arg) {
    $sid = str_replace("@$id", $arg, $sid);
  }
  foreach ($panel_args as $id => $arg) {
    if (is_string($arg)) {
      $sid = str_replace("%$id", $arg, $sid);
    }
  }

  if (!is_numeric($sid)) {
    return;
  }

  $submission = webform_entity_load_webform_submission($sid);

  // Don't store viewed webform submission data on the webform submission, this can mess up other
  // views of the webform submission.
  $submission = clone($submission);

  $block->module = 'webform_entity';
  $block->delta = $submission->sid;

  $block->title = t('Submission @sid', array('@sid' => $submission->sid));;

  $node = node_load($submission->nid);

  $block->content = webform_submission_render($node, $submission, NULL, 'html');

  return $block;
}

/**
 * The form to add or edit a webform submission as content.
 */
function webform_entity_webform_submission_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  if ($form_state['op'] == 'add') {
    $form['sid'] = array(
      '#prefix' => '<div class="no-float">',
      '#title' => t('Enter the title or SID of a webform submission'),
      '#description' => t('To use an SID from the URL, you may use %0, %1, ..., %N to get URL arguments. Or use @0, @1, @2, ..., @N to use arguments passed into the panel.'),
      '#type' => 'textfield',
      '#maxlength' => 512,
      '#weight' => -10,
      '#suffix' => '</div>',
    );
  }
  else {
    $form['nid'] = array(
      '#type' => 'value',
      '#value' => $conf['sid'],
    );
  }

  $form['identifier'] = array(
    '#type' => 'textfield',
    '#default_value' => !empty($conf['identifier']) ? $conf['identifier'] : '',
    '#title' => t('Template identifier'),
    '#description' => t('This identifier will be added as a template suggestion to display this submission: webform-submission--panel--IDENTIFIER.tpl.php. Please see the Drupal theming guide for information about template suggestions.'),
  );
  return $form;
}

/**
 * Validate the webform submission selection.
 */
function  webform_entity_webform_submission_content_type_edit_form_validate(&$form, &$form_state) {
  if ($form_state['op'] != 'add') {
    return;
  }

  $sid = $form_state['values']['sid'];
  $preg_matches = array();
  $match = preg_match('/\[id: (\d+)\]/', $sid, $preg_matches);
  if (!$match) {
    $match = preg_match('/^id: (\d+)/', $sid, $preg_matches);
  }

  if ($match) {
    $sid = $preg_matches[1];
  }
  if (is_numeric($sid)) {
    $submission = db_query('SELECT sid FROM {webform_submissions} WHERE sid = :sid', array(':sid' => $sid))->fetchObject();
  }
  if ($submission) {
    $form_state['values']['sid'] = $submission->sid;
  }
}

/**
 * Validate the webform submission selection.
 */
function webform_entity_webform_submission_content_type_edit_form_submit($form, &$form_state) {
  foreach (array('sid', 'identifier') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Returns the administrative title for a webform submission.
 */
function webform_entity_webform_submission_content_type_admin_title($subtype, $conf) {
  if (!is_numeric($conf['sid'])) {
    return t('Webform submission loaded from @var', array('@var' => $conf['sid']));
  }

  $submission = webform_entity_load_webform_submission($conf['sid']);
  if ($submission) {
    return check_plain(t('submission @sid', array('@sid' => $submission->sid)));
  }
  else {
    return t('Deleted/missing webform submission @sid', array('@sid' => $conf['sid']));
  }
}

/**
 * Display the administrative information for a node pane.
 */
function webform_entity_webform_submission_content_type_admin_info($subtype, $conf) {
  // Just render the node.
  return webform_entity_webform_submission_content_type_render($subtype, $conf, array());
}
