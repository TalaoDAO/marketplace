<?php

/**
 * @file
 * Log pages.
 */

/**
 * Log view callback.
 *
 * @param Log $log
 *   The log entity.
 *
 * @return array
 *   Returns the entity render array.
 */
function log_view(Log $log) {

  // Set the title of the page to the log's label.
  drupal_set_title(entity_label('log', $log));

  // Build the log entity render array.
  $output = entity_view('log', array(entity_id('log', $log) => $log), 'full');

  // Add the log's "done" status.
  if ($log->done) {
    $status = 'DONE';
  }
  else {
    $status = 'NOT DONE';
    drupal_set_message(t('This log item is not done.'), 'warning');
  }
  $output['log'][$log->id]['done'] = array(
    '#markup' => '<div style="float: right;">Status: <strong>' . $status . '</strong></div>',
    '#weight' => -100,
  );

  // Add the log's timestamp.
  if (!empty($log->timestamp)) {
    $date = format_date($log->timestamp);
    $output['log'][$log->id]['timestamp'] = array(
      '#markup' => '<p><strong>Date:</strong> ' . $date . '</p>',
      '#weight' => -99,
    );
  }

  return $output;
}

/**
 * Page to select log Type to add new log.
 */
function log_add_types_page() {
  $items = array();
  foreach (log_types() as $log_type_key => $log_type) {
    if (log_access('create', $log_type)) {
      $items[] = l(entity_label('log_type', $log_type), 'log/add/' . $log_type_key);
    }
  }
  return array(
    'list' => array(
      '#theme' => 'item_list',
      '#items' => $items,
      '#title' => t('Select a type of log to create.'),
    ),
  );
}

/**
 * Add new log page callback.
 *
 * @param string $type
 *   The log type.
 *
 * @return array
 *   Returns the log form array.
 */
function log_add($type) {
  $log_type = log_types($type);

  $log = entity_create('log', array('type' => $type));
  drupal_set_title(t('Log @name', array('@name' => entity_label('log_type', $log_type))));

  $output = drupal_get_form('log_form', $log);

  return $output;
}

/**
 * Log Form.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param Log $log
 *   The log entity.
 *
 * @return array
 *   Returns the log form array.
 */
function log_form(array $form, array &$form_state, Log $log) {

  // Store the log entity in the form for use later.
  $form['log'] = array(
    '#type' => 'value',
    '#value' => $log,
  );

  // Load the log type.
  $log_type = log_type_load($log->type);

  // Only display the name field if it's editable.
  if (!empty($log_type->name_edit)) {
    $form['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
      '#description' => t('Leave this blank to automatically generate a name.'),
      '#default_value' => $log->name,
    );
  }

  // Timestamp.
  $timestamp_default = !empty($log->timestamp) ? date('Y-m-d H:i:s', $log->timestamp) : '';
  $form['timestamp'] = array(
    '#type' => 'date_select',
    '#title' => t('Date'),
    '#date_format' => 'M j Y H:i:s',
    '#date_type' => DATE_FORMAT_UNIX,
    '#date_year_range' => '-10:+3',
    '#default_value' => $timestamp_default,
    '#required' => TRUE,
  );

  // Additional settings (vertical tabs at the bottom of the form).
  $form['additional_settings'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => 99,
  );

  // If the log is new, and the log type marks new logs as "done" by default,
  // mark the log as done and add some Javascript to auto-check/uncheck based
  // on the timestamp.
  if (empty($log->id) && !empty($log_type->done)) {
    $log->done = TRUE;
    drupal_add_js(drupal_get_path('module', 'log') . '/log.done.js');
  }
  $form['log_status'] = array(
    '#type' => 'fieldset',
    '#title' => t('Log status'),
    '#description' => t('Mark this log as done.'),
    '#collapsible' => TRUE,
    '#group' => 'additional_settings'
  );
  $form['log_status']['done'] = array(
    '#type' => 'checkbox',
    '#title' => t('Done'),
    '#default_value' => $log->done,
  );

  // Log user id.
  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $log->uid,
  );

  field_attach_form('log', $log, $form, $form_state);

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save log'),
    '#submit' => $submit + array('log_form_submit'),
  );

  // Show Delete button if allowed.
  $log_id = entity_id('log', $log);
  if (!empty($log_id) && log_access('delete', $log)) {

    // Get the destination query parameter. If it is the current path, change to
    // <front> (because the current path won't exist once the log is deleted).
    $destination = drupal_get_destination();
    if ($destination['destination'] == current_path()) {
      $destination['destination'] = '<front>';
    }
    $form['actions']['delete'] = array(
      '#type' => 'markup',
      '#markup' => l(t('Delete'), 'log/' . $log_id . '/delete', array('query' => $destination)),
    );
  }

  return $form;
}

/**
 * Log validate handler.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function log_form_validate(array $form, array &$form_state) {

  // If a new log is marked "done", but the timestamp is in the future, display
  // a warning, but allow the user to continue if they submit the form again.
  if (empty($form_state['values']['log']->id) && empty($form_state['log_done_warning'])) {
    $timestamp = strtotime($form_state['values']['timestamp']);
    if (!empty($form_state['values']['done']) && $timestamp > REQUEST_TIME) {
      form_set_error('done', t('You marked this log item as "done", but it has a date in the future. If you are OK with this fact, click save again.'));
      $form_state['log_done_warning'] = TRUE;
    }
  }
}

/**
 * Log submit handler.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function log_form_submit(array $form, array &$form_state) {

  // Load the log entity from the form values.
  $log = $form_state['values']['log'];

  // Convert the date to a timestamp.
  $form_state['values']['timestamp'] = strtotime($form_state['values']['timestamp']);

  // Build the entity from the form values.
  entity_form_submit_build_entity('log', $log, $form, $form_state);

  // Save the log.
  log_save($log);

  // Redirect to the log.
  $log_uri = entity_uri('log', $log);
  $form_state['redirect'] = $log_uri['path'];

  // Print a message.
  drupal_set_message(t('Log saved: <a href="@uri">%title</a>', array('@uri' => base_path() . $log_uri['path'], '%title' => entity_label('log', $log))));
}

/**
 * Delete confirmation form.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 * @param Log $log
 *   The log entity to delete.
 *
 * @return array
 *   Returns a form array.
 */
function log_delete_form(array $form, array &$form_state, Log $log) {
  $form['log'] = array(
    '#type' => 'value',
    '#value' => $log,
  );
  // Always provide entity id in the same form key as in the entity edit form.
  $form['log_type_id'] = array(
    '#type' => 'value',
    '#value' => entity_id('log', $log));
  $log_uri = entity_uri('log', $log);
  return confirm_form($form,
    t('Are you sure you want to delete %title?', array('%title' => entity_label('log', $log))),
    $log_uri['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Delete form submit handler.
 *
 * @param array $form
 *   The form array.
 * @param array $form_state
 *   The form state array.
 */
function log_delete_form_submit(array $form, array &$form_state) {
  $log = $form_state['values']['log'];
  log_delete($log);

  drupal_set_message(t('%title was deleted.', array('%title' => entity_label('log', $log))));

  $form_state['redirect'] = '<front>';
}
