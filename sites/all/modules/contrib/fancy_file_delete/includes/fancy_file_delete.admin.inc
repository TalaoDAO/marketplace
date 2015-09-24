<?php
/**
 * @file
 * Fancy File Delete administration and module settings UI.
 */

/**
 * Info Page Callback.
 */
function fancy_file_delete_info() {
  $html  = '<h2>' . t('Fancy File Delete Options') . '</h2>';
  $html .= '<ol>';
  $html .= '<li>' . t('<b>LIST:</b> View of all managed files with an <em>option to force</em> delete them via VBO custom actions') . '</li>';
  $html .= '<li>' . t('<b>MANUAL:</b> Manually deleting managed files by FID (and an  <em>option to force</em> the delete if you really want to).') . '</li>';
  $html .= '<li>' . t('<b>ORPHANED:</b> Deleting unused files from the whole install that are no longer attached to nodes & the file usage table. AKA deleting all the orphaned files.') . '</li>';
  $html .= '<li>' . t('<b>UNMANAGED:</b> Deleting unused files from the default files directory that are not in the file managed table. AKA deleting all the unmanaged files.') . '</li>';
  $html .= '</ol>';

  return array('#markup' => $html);
}

/**
 * Manual Deletion Page Callback.
 */
function fancy_file_delete_manual() {

  $form['force'] = array(
    '#type' => 'checkbox',
    '#title' => t('FORCE file deletion?'),
  );

  $form['delete_textarea'] = array(
    '#type' => 'textarea',
    '#title' => t('FID Numbers'),
    '#default_value' => '',
    '#description' => t('Provide the fid numbers, one per line.'),
    '#attributes' => array(
      'style' => 'font-family:"Courier New", Courier, monospace;',
    ),
    '#rows' => 10,
  );

  $form['#validate'][] = 'fancy_file_delete_manual_validate';
  $form['#submit'][] = 'fancy_file_delete_manual_submit';

  return system_settings_form($form);
}

/**
 * Validate handler for manual form.
 */
function fancy_file_delete_manual_validate($form, &$form_state) {
  // Required doesn't work well with states it seemz.
  if (empty($form_state['values']['delete_textarea'])) {
    form_set_error('delete_textarea', t('You can\'t leave this blank, what\'cha thinking?'));
  }
}

/**
 * Submit handler for manual form.
 */
function fancy_file_delete_manual_submit($form, &$form_state) {
  $operations = array();

  $force = ($form_state['values']['force']) ? TRUE : FALSE;
  $fids = explode("\n", $form_state['values']['delete_textarea']);
  foreach ($fids as $fid) {
    $operations[] = array('fancy_file_delete_batch', array($fid, $force));
  }
  // Send to batch.
  _fancy_file_delete_batch_run($operations);
}

/**
 * Unmanaged Deletion Page Callback.
 */
function fancy_file_delete_unmanaged() {
  $form['close'] = array(
    '#type' => 'item',
    '#markup' => '<h2>' . t('Warning, this will delete all files that are orphaned (ones that are in the files directory with no record on the file_usage table)') . '</h2>' .
     '<h5>' . t('There is no turning back once you hit submit!') . '</h5>',
  );

  $form['#submit'][] = 'fancy_file_delete_unmanaged_submit';

  return system_settings_form($form);
}

/**
 * Submit callback for auto form.
 */
function fancy_file_delete_unmanaged_submit($form, &$form_state) {
  $operations = array();
  // Get all files from default standard file dir.
  $dir = variable_get('file_public_path', 'sites/default/files');
  $files = file_scan_directory($dir, '(.*?)');

  // Go through each one and replace this with a proper uri.
  foreach ($files as $file) {
    $file_check[] = str_replace($dir . '/', 'public://', $file->uri);
  }

  // All the files in the file_managed table
  $query = db_select('file_managed', 'fm')
    ->fields('fm', array('uri'))
    ->execute();

  // Set this to a numeric keyed array so we can check this easier.
  foreach ($query->fetchAll() as $result) {
    $db_check[] = $result->uri;
  }
  // Get the files not in the file_managed table.
  $results = array_diff($file_check, $db_check);

  // Go through and add this to the batch.
  if(count($results) > 0) {
    foreach ($results as $result) {
      $operations[] = array('fancy_file_delete_batch', array($result, FALSE));
    }
    // Send to batch.
    _fancy_file_delete_batch_run($operations);
  }
  else {
    drupal_set_message(t('No Unmanaged Files Were Found.'));
    drupal_goto('admin/config/content/fancy_file_delete/unmanaged');
  }
}

/**
 * The batch operations to run for either function.
 *
 * @param  object $operations
 *   The operations array from each submit handler.
 */
function _fancy_file_delete_batch_run($operations) {
  $batch = array(
    'title' => t('Fun Stuff is Happening...'),
    'operations' => $operations,
    'finished' => 'fancy_file_delete_batch_finished',
    'file' => drupal_get_path('module', 'fancy_file_delete') . '/includes/fancy_file_delete.batch.inc',
  );

  batch_set($batch);
}
