<?php
/**
 * @file
 * Generates a report showing files on the server, but not in the database.
 */

/**
 * The following are functions for displaying the list of files on the page.
 */

/**
 * Generates the report.
 *
 * This cannot be sorted, because a result set that is too large will time out.
 *
 * @param array $form
 *   The form definition.
 * @param array $form_state
 *   The current state of the form.
 *
 * @return array
 *   The form definition.
 */
function auditfiles_not_in_database_form(array $form, array &$form_state) {
  // Check to see if the confirmation form needs to be displayed instead of the
  // normal form.
  if (isset($form_state['storage']['confirm'])) {
    return _auditfiles_not_in_database_confirm_operation($form, $form_state);
  }

  // Get the records to display.
  // Check to see if there is saved data, and if so, use that.
  $rows = variable_get('auditfiles_not_in_database_files_to_display', array());
  if (empty($rows)) {
    // The data is not saved and the batch operation has not been run, so get
    // the data using the default options.
    $rows = _auditfiles_not_in_database_get_reports_files();
    // Save the data for persistent use.
    variable_set('auditfiles_not_in_database_files_to_display', $rows);
  }

  if (!empty($rows)) {
    // Set up the pager.
    $items_per_page = variable_get('auditfiles_report_options_items_per_page', 50);
    if (!empty($items_per_page)) {
      $current_page = pager_default_initialize(count($rows), $items_per_page);
      // Break the total data set into page sized chunks.
      $pages = array_chunk($rows, $items_per_page, TRUE);
    }
  }

  // Define the form.
  // Setup the record count and related messages.
  $maximum_records = variable_get('auditfiles_report_options_maximum_records', 250);
  if (!empty($rows)) {
    if ($maximum_records > 0) {
      $file_count_message = 'Found at least @count files on the server that are not in the database.';
    }
    else {
      $file_count_message = 'Found @count files on the server that are not in the database.';
    }
    $form_count = format_plural(
      count($rows),
      'Found 1 file on the server that is not in the database.',
      $file_count_message
    );
  }
  else {
    $form_count = 'Found no files on the server that are not in the database.';
  }

  // Add the button to reset the record selection.
  $form['reset_records'] = array(
    '#type' => 'submit',
    '#value' => t('Reset file list'),
    '#suffix' => '<div>' . t("Use this button to reset this report's variables and load the page anew.") . '</div>',
  );
  // Add the button to batch process the list of results.
  if ($maximum_records > 0) {
    $form['batch_process'] = array(
      '#type' => 'submit',
      '#value' => t('Load all files'),
      '#suffix' => '<div>' . t('Use this button to load the number of records specified with the "Batch size" administrative configuration setting.') . '</div>',
    );
  }

  // Create the form table.
  $form['files'] = array(
    '#type' => 'tableselect',
    '#header' => _auditfiles_not_in_database_get_header(),
    '#empty' => t('No items found.'),
    '#prefix' => '<div><em>' . $form_count . '</em></div>',
  );

  // Add the data.
  if (!empty($rows) && !empty($pages)) {
    $form['files']['#options'] = $pages[$current_page];
  }
  elseif (!empty($rows)) {
    $form['files']['#options'] = $rows;
  }
  else {
    $form['files']['#options'] = array();
  }

  // Add any action buttons.
  if (!empty($rows)) {
    $form['actions'] = array('#type' => 'actions');
    $form['actions']['add'] = array(
      '#type' => 'submit',
      '#value' => t('Add selected items to the database'),
    );
    $form['actions']['markup'] = array(
      '#markup' => '&nbsp;' . t('or') . '&nbsp;',
    );
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete selected items from the server'),
    );

    // Add the pager.
    $form['pager'] = array('#markup' => theme('pager'));
  }

  return $form;
}

/**
 * Submit handler for the auditfiles_not_in_database_form form.
 */
function auditfiles_not_in_database_form_submit($form, &$form_state) {
  // Check if an operation was performed.
  if (!empty($form_state['values']['op'])) {
    // Check which operation was performed and start the batch process.
    if ($form_state['values']['op'] == t('Load all files')) {
      // Clear the variable, so subsequent pages will load the correct data.
      variable_del('auditfiles_not_in_database_files_to_display');
      // Prepare and set the batch.
      batch_set(_auditfiles_not_in_database_batch_display_create_batch());
    }
    elseif ($form_state['values']['op'] == t('Reset file list')) {
      // Reset all the variables for this report, so subsequent pages loads will
      // load and use the correct data.
      db_delete('variable')
        ->condition('name', 'auditfiles_not_in_database_%', 'LIKE')
        ->execute();
      cache_clear_all('variables', 'cache_bootstrap');
    }
    elseif (($form_state['values']['op'] == t('Add selected items to the database')
      || $form_state['values']['op'] == t('Delete selected items from the server'))
      && !empty($form_state['values']['files'])) {
      foreach ($form_state['values']['files'] as $file_id) {
        if (!empty($file_id)) {
          // At least one file was selected, and the operation has not been
          // confirmed, so modify the data to display the confirmation form.
          $form_state['storage']['files'] = $form_state['values']['files'];
          $form_state['storage']['op'] = $form_state['values']['op'];
          $form_state['storage']['confirm'] = TRUE;
          $form_state['rebuild'] = TRUE;
          return TRUE;
        }
      }

      drupal_set_message(t('No items were selected to operate on.'));
    }
    elseif ($form_state['values']['op'] == t('Yes')) {
      if ($form_state['values']['operation'] == 'add') {
        // Prepare and set the batch.
        batch_set(_auditfiles_not_in_database_batch_add_create_batch($form_state['values']['changelist']));
      }
      elseif ($form_state['values']['operation'] == 'delete') {
        // Prepare and set the batch.
        batch_set(_auditfiles_not_in_database_batch_delete_create_batch($form_state['values']['changelist']));
      }
    }
  }
}

/**
 * The following are functions that are common for all batches in this file.
 */

/**
 * Adds vaules to a batch definition that are common to all batches in the file.
 *
 * @return array
 *   The beginning of the batch definition.
 */
function _auditfiles_not_in_database_batch_set_common_values() {
  return array(
    'error_message' => t('One or more errors were encountered processing the files.'),
    'file' => drupal_get_path('module', 'auditfiles') . '/auditfiles.notindatabase.inc',
    'finished' => '_auditfiles_not_in_database_batch_finish_batch',
    'progress_message' => t('Completed @current of @total operations.'),
  );
}

/**
 * The function that is called when the batch is completed.
 */
function _auditfiles_not_in_database_batch_finish_batch($success, $results, $operations) {
  if ($success) {
    if (!empty($results['files_to_display'])) {
      // Save the gathered data for display.
      variable_set('auditfiles_not_in_database_files_to_display', $results['files_to_display']);
    }
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    drupal_set_message(
      t('An error occurred while processing @operation with arguments : @args',
        array(
          '@operation' => $error_operation[0],
          '@args' => print_r($error_operation[0], TRUE),
        )
      )
    );
  }
}

/**
 * The following are functions for preparing the batch for displaying the files.
 */

/**
 * Prepares the definition for the page display batch.
 *
 * @return array
 *   The batch definition.
 */
function _auditfiles_not_in_database_batch_display_create_batch() {
  $batch = _auditfiles_not_in_database_batch_set_common_values();
  $batch['title'] = t('Loading file audit data');
  $batch['operations'] = _auditfiles_not_in_database_batch_display_get_operations();
  return $batch;
}

/**
 * Configures the operations for the batch process.
 *
 * @return array
 *   The operations to execute.
 */
function _auditfiles_not_in_database_batch_display_get_operations() {
  $operations = array();
  $operations[] = array(
    '_auditfiles_not_in_database_batch_display_get_files',
    array(),
  );
  $operations[] = array(
    '_auditfiles_not_in_database_batch_display_process_files',
    array(),
  );
  return $operations;
}

/**
 * Recurse directories and add files to an array.
 *
 * @param array $context
 *   Used by the Batch API to keep track of data and pass it from one operation
 *   to the next.
 */
function _auditfiles_not_in_database_batch_display_get_files(array &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox'] = array();
    $context['sandbox']['progress'] = 0;

    // Get the starter list of files from the root directory.
    $file_system_stream = variable_get('auditfiles_file_system_path', 'public');
    $context['sandbox']['drupal_path'] = variable_get('file_' . $file_system_stream . '_path', conf_path() . '/files');
    $context['sandbox']['real_path'] = drupal_realpath($file_system_stream . '://');

    $files = _auditfiles_not_in_database_get_files($context['sandbox']['real_path']);
    if (!empty($files)) {
      $context['sandbox']['exclusions'] = _auditfiles_get_exclusions();
      $context['sandbox']['files']
        = _auditfiles_not_in_database_report_processing_merge_file_lists(
          array(),
          $files,
          $context['sandbox']['real_path'],
          '',
          $context['sandbox']['exclusions']
        );
    }

    $context['sandbox']['batch_size'] = variable_get('auditfiles_report_options_batch_size', 1000);
    if ($context['sandbox']['batch_size'] > 0) {
      $context['sandbox']['max'] = $context['sandbox']['batch_size'];
    }
    else {
      $context['sandbox']['max'] = count($context['sandbox']['files']);
    }
  }
  if (empty($context['results'])) {
    $context['results'] = array();
  }
  if (empty($context['results']['file_list'])) {
    $context['results']['file_list'] = array();
  }

  if (!empty($context['sandbox']['files'])) {
    // Process 20 files at a time, so the batch process has an opportunity to
    // reset itself.
    $file_list = array_slice($context['sandbox']['files'], 0, 20, TRUE);
    foreach ($file_list as $key => $context['sandbox']['file']) {
      if (is_dir($context['sandbox']['real_path'] . DIRECTORY_SEPARATOR . $context['sandbox']['file'])) {
        // Scan the directory and append the files to the files array.
        $found_files = _auditfiles_not_in_database_get_files(
          $context['sandbox']['real_path'] . DIRECTORY_SEPARATOR . $context['sandbox']['file']
        );
        if (!empty($found_files)) {
          // Add the newly found files to the end of the files array.
          $context['sandbox']['files']
            = _auditfiles_not_in_database_report_processing_merge_file_lists(
              $context['sandbox']['files'],
              $found_files,
              $context['sandbox']['real_path'],
              $context['sandbox']['file'],
              $context['sandbox']['exclusions']
            );
          // Update the max file count.
          if (empty($context['sandbox']['batch_size'])) {
            $context['sandbox']['max'] = count($context['sandbox']['files']);
          }
        }
      }
      else {
        // Add the file to the list.
        $context['results']['file_list'][]
          = _auditfiles_not_in_database_fix_path_separators(
            $context['sandbox']['file']
          );

        // Check to see if the array has reached its limit.
        if (count($context['results']['file_list']) >= $context['sandbox']['max']) {
          $context['sandbox']['progress'] = $context['sandbox']['max'];
        }
        else {
          $context['sandbox']['progress']++;
        }
      }

      unset($context['sandbox']['files'][$key]);

      // Update the progress information.
      $context['message'] = t(
        'Getting the list of files. Processed file @num1 of @num2. Last file processed: !file_name.',
        array(
          '@num1' => $context['sandbox']['progress'],
          '@num2' => $context['sandbox']['max'],
          '!file_name' => $context['sandbox']['file'],
        )
      );
    }
  }
  else {
    $context['sandbox']['progress'] = $context['sandbox']['max'];
  }

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = ($context['sandbox']['progress'] >= $context['sandbox']['max']);
  }
}

/**
 * Retrieves file data from the database and checks if it is on the server.
 *
 * @param array $context
 *   Used by the Batch API to keep track of data and pass it from one operation
 *   to the next.
 */
function _auditfiles_not_in_database_batch_display_process_files(array &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox'] = array();
    if (empty($context['results']['file_list'])) {
      $context['sandbox']['progress'] = 1;
      $context['sandbox']['max'] = 1;
    }
    else {
      $context['sandbox']['progress'] = 0;
      $context['sandbox']['max'] = count($context['results']['file_list']);

      $context['sandbox']['date_format'] = variable_get('auditfiles_report_options_date_format', 'long');
      // Get the path of the currently used file scheme.
      $file_system_stream = variable_get('auditfiles_file_system_path', 'public');
      $context['sandbox']['real_path'] = drupal_realpath($file_system_stream . '://');
    }
  }
  if (empty($context['results']['files_to_display'])) {
    $context['results']['files_to_display'] = array();
  }

  if (!empty($context['results']['file_list'])) {
    $file_list = array_slice($context['results']['file_list'], 0, 20, TRUE);
    foreach ($file_list as $file_id => $filepathname) {
      // See if the file is in the database.
      if (!_auditfiles_not_in_database_is_file_in_database($filepathname)) {
        // The file is not in the database, so save the file information for the
        // report.
        $context['results']['files_to_display'][$filepathname]
          = _auditfiles_not_in_database_format_row_data(
            $filepathname,
            $context['sandbox']['real_path'],
            $context['sandbox']['date_format']
          );
      }

      unset($context['results']['file_list'][$file_id]);

      // Update the progress information.
      $context['sandbox']['progress']++;
      $context['message'] = t(
        'Processing the file list. Processed file @num1 of @num2. Last file processed: !file_name.',
        array(
          '@num1' => $context['sandbox']['progress'],
          '@num2' => $context['sandbox']['max'],
          '!file_name' => $file_id,
        )
      );
    }
  }

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = ($context['sandbox']['progress'] >= $context['sandbox']['max']);
  }
}

/**
 * The following are functions for the batch add & delete operations.
 */

/**
 * Presents a confimation form to verify the user wants to complete the action.
 *
 * @param array $form
 *   The form definition.
 * @param array $form_state
 *   The current state of the form.
 *
 * @return array
 *   A form array for a confirmation form.
 */
function _auditfiles_not_in_database_confirm_operation(array $form, array &$form_state) {
  $values = $form_state['values'];

  $form['changelist'] = array(
    '#prefix' => '<ul>',
    '#suffix' => '</ul>',
    '#tree' => TRUE,
  );

  // Prepare the list of items to present to the user.
  if (!empty($values['files'])) {
    foreach ($values['files'] as $filename) {
      if (!empty($filename)) {
        if ($values['op'] == t('Add selected items to the database')) {
          $message = t('will be added to the database.');
        }
        elseif ($values['op'] == t('Delete selected items from the server')) {
          $message = t('will be deleted from the server.');
        }
        $form['changelist'][$filename] = array(
          '#type' => 'hidden',
          '#value' => $filename,
          '#prefix' => '<li><strong>' . $filename . '</strong> ' . $message,
          '#suffix' => "</li>\n",
        );
      }
      else {
        // Unsetting the unprocessed files prevents confirm_submit from dealing
        // with them.
        unset($form_state['values']['files'][$filename]);
      }
    }
  }

  $form['operation'] = array(
    '#type' => 'hidden',
  );
  if ($values['op'] == t('Add selected items to the database')) {
    $form['operation']['#value'] = 'add';
    $confirm_question = t('Add these files to the database?');
    $confirm_description = '';
  }
  elseif ($values['op'] == t('Delete selected items from the server')) {
    $form['operation']['#value'] = 'delete';
    $confirm_question = t('Delete these files from the server?');
    $confirm_description = '<strong>' . t('This action cannot be undone.') . '</strong>';
  }

  // Tell the submit handler to process the confirmation.
  $form['process'] = array(
    '#type' => 'hidden',
    '#value' => 'TRUE',
  );
  // Go back to the main form, when done with this one.
  $form['destination'] = array(
    '#type' => 'hidden',
    '#value' => 'admin/reports/auditfiles/notindatabase',
  );

  return confirm_form(
    $form,
    $confirm_question,
    'admin/reports/auditfiles/notindatabase',
    $confirm_description,
    t('Yes'),
    t('No')
  );
}

/**
 * Creates the batch for adding files to the database.
 *
 * @param array $fileids
 *   The list of file IDs to be processed.
 *
 * @return array
 *   The definition of the batch.
 */
function _auditfiles_not_in_database_batch_add_create_batch(array $fileids) {
  $batch = _auditfiles_not_in_database_batch_set_common_values();
  $batch['title'] = t('Adding files to Drupal file management');
  $operations = array();
  // Remove all the empty values from the array.
  $file_ids = array();
  foreach ($fileids as $file_id) {
    if (!empty($file_id)) {
      $file_ids[] = $file_id;
    }
  }
  // Fill in the $operations variable.
  foreach ($file_ids as $file_id) {
    $operations[] = array(
      '_auditfiles_not_in_database_batch_add_process_batch',
      array($file_id),
    );
  }
  $batch['operations'] = $operations;
  return $batch;
}

/**
 * The batch process for adding the file.
 *
 * @param string $filename
 *   The full pathname to the file to add to the database.
 * @param array $context
 *   Used by the Batch API to keep track of data and pass it from one operation
 *   to the next.
 */
function _auditfiles_not_in_database_batch_add_process_batch($filename, array &$context) {
  // Process the current file.
  _auditfiles_not_in_database_batch_add_process_file($filename);
  // The contents of 'results' are available as $results in the 'finished'
  // function.
  $context['results'][] = $filename;
  // Set a progress message.
  $context['message'] = t('Processed %filename.', array('%filename' => $filename));
}

/**
 * Adds the specified file to the database.
 *
 * @param string $filepathname
 *   The full pathname to the file to add to the database.
 */
function _auditfiles_not_in_database_batch_add_process_file($filepathname) {
  global $user;
  $file = new stdClass();
  $file->uid = $user->uid;
  $file->filename = trim(basename($filepathname));
  $file->uri = file_build_uri($filepathname);
  // Get the full system file path name, so that the following two operations
  // will work.
  $real_filenamepath = drupal_realpath($file->uri);
  $file->filemime = file_get_mimetype($real_filenamepath);
  $file->filesize = filesize($real_filenamepath);
  $file->status = FILE_STATUS_PERMANENT;
  $file->timestamp = REQUEST_TIME;

  // Make sure the file is not already in the database.
  $query = 'SELECT fid FROM file_managed WHERE uri = :uri';
  $existing_file = db_query($query, array(':uri' => $file->uri))->fetchAll();
  if (empty($existing_file)) {
    // The file is not already in the database, so add it.
    $results = drupal_write_record('file_managed', $file);

    if (empty($results)) {
      drupal_set_message(t('Failed to add %file to the database.', array('%file' => $filepathname)));
    }
    else {
      drupal_set_message(t('Sucessfully added %file to the database.', array('%file' => $filepathname)));
      // Remove the file from the list of files to display.
      $rows = variable_get('auditfiles_not_in_database_files_to_display', array());
      unset($rows[$filepathname]);
      variable_set('auditfiles_not_in_database_files_to_display', $rows);
    }
  }
  else {
    drupal_set_message(t('The file %file is already in the database.', array('%file' => $filepathname)), 'error');
  }
}

/**
 * Creates the batch for deleting files from the server.
 *
 * @param array $file_names
 *   The list of file names to be processed.
 *
 * @return array
 *   The definition of the batch.
 */
function _auditfiles_not_in_database_batch_delete_create_batch(array $file_names) {
  $batch = _auditfiles_not_in_database_batch_set_common_values();
  $batch['title'] = t('Deleting files from the server');
  $operations = array();
  // Remove all the empty values from the array.
  $filenames = array();
  foreach ($file_names as $file_name) {
    if (!empty($file_name)) {
      $filenames[] = $file_name;
    }
  }
  // Fill in the $operations variable.
  foreach ($filenames as $filename) {
    $operations[] = array(
      '_auditfiles_not_in_database_batch_delete_process_batch',
      array($filename),
    );
  }
  $batch['operations'] = $operations;
  return $batch;
}

/**
 * The batch process for deleting the file.
 *
 * @param string $filename
 *   The filename to delete.
 * @param array $context
 *   Used by the Batch API to keep track of data and pass it from one operation
 *   to the next.
 */
function _auditfiles_not_in_database_batch_delete_process_batch($filename, array &$context) {
  // Process the current file.
  _auditfiles_not_in_database_batch_delete_process_file($filename);
  // The contents of 'results' are available as $results in the 'finished'
  // function.
  $context['results'][] = check_plain($filename);
  // Set a progress message.
  $context['message'] = t('Processed %filename.', array('%filename' => $filename));
}

/**
 * Deletes the specified file from the server.
 *
 * @param string $filename
 *   The full pathname of the file to delete from the server.
 */
function _auditfiles_not_in_database_batch_delete_process_file($filename) {
  // Get the static paths necessary for processing the files.
  $file_system_stream = variable_get('auditfiles_file_system_path', 'public');
  // The full file system path to the Drupal root directory.
  $real_files_path = drupal_realpath($file_system_stream . '://');
  // Delete the file without invoking any hooks.
  if (file_unmanaged_delete($real_files_path . DIRECTORY_SEPARATOR . $filename)) {
    drupal_set_message(t('Sucessfully deleted %file from the server.', array('%file' => $filename)));
    // Remove the deleted files from the list of files to display.
    $rows = variable_get('auditfiles_not_in_database_files_to_display', array());
    unset($rows[$filename]);
    variable_set('auditfiles_not_in_database_files_to_display', $rows);
  }
  else {
    drupal_set_message(t('Failed to delete %file from the server.', array('%file' => $filename)));
  }
}

/**
 * The following are functions for retrieving and processing the file data.
 */

/**
 * Recurse directories and add files to an array.
 *
 * @param string $directory
 *   The directory in which to look for files.
 * @param bool $recursive
 *   Whether or not to recurse into subdirectories.
 *
 * @return array
 *   The list of file names to display.
 */
function _auditfiles_not_in_database_get_reports_files() {
  // Set up the variables for holding the file data.
  $report_files = array();
  $reported_files = array();

  _auditfiles_not_in_database_get_files_for_report('', $report_files);

  if (!empty($report_files)) {
    // Get the static paths necessary for processing the files.
    $file_system_stream = variable_get('auditfiles_file_system_path', 'public');
    // The full file system path to the Drupal root directory.
    $real_files_path = drupal_realpath($file_system_stream . '://');
    // Get the chosen date format for displaying the file dates with.
    $date_format = variable_get('auditfiles_report_options_date_format', 'long');

    foreach ($report_files as $report_file) {
      // Check to see if the file is in the database.
      if (empty($report_file['path_from_files_root'])) {
        $file_to_check = $report_file['file_name'];
      }
      else {
        $file_to_check = $report_file['path_from_files_root'] . DIRECTORY_SEPARATOR . $report_file['file_name'];
      }
      $file_in_database = _auditfiles_not_in_database_is_file_in_database($file_to_check);

      // If the file is not in the database, add it to the list for displaying.
      if (!$file_in_database) {
        // Gets the file's information (size, date, etc.) and assempbles the
        // array for the table.
        $reported_files += _auditfiles_not_in_database_format_row_data(
          $report_file,
          $real_files_path,
          $date_format
        );
      }
    }
  }

  return $reported_files;
}

function _auditfiles_not_in_database_get_files_for_report($path, array &$report_files) {
  // Get the static paths necessary for processing the files.
  $file_system_stream = variable_get('auditfiles_file_system_path', 'public');
  // The full file system path to the Drupal root directory.
  $real_files_path = drupal_realpath($file_system_stream . '://');
  // If record limition has been configured, only use those records within that
  // specification.
  $maximum_records = variable_get('auditfiles_report_options_maximum_records', 250);

  if ($maximum_records > 0 && count($report_files) < $maximum_records) {
    $new_files = _auditfiles_not_in_database_get_files($path);
    if (!empty($new_files)) {
      foreach ($new_files as $file) {
        // Check if the current item is a directory or a file.
        if (empty($file['path_from_files_root'])) {
          $item_path_check = $real_files_path . DIRECTORY_SEPARATOR . $file['file_name'];
        }
        else {
          $item_path_check = $real_files_path . DIRECTORY_SEPARATOR . $file['path_from_files_root'] . DIRECTORY_SEPARATOR . $file['file_name'];
        }
        if (is_dir($item_path_check)) {
          // The item is a directory, so go into it and get any files there.
          if (empty($path)) {
            $file_path = $file['file_name'];
          }
          else {
            $file_path = $path . DIRECTORY_SEPARATOR . $file['file_name'];
          }
          _auditfiles_not_in_database_get_files_for_report($file_path, $report_files);
        }
        else {
          // The item is a file, so add it to the list.
          $file['path_from_files_root'] = _auditfiles_not_in_database_fix_path_separators($file['path_from_files_root']);
          $report_files[] = $file;
        }
      }
    }
    else {
    }
  }
}

/**
 * The following are helper functions.
 */

/**
 * Retrieves a list of files in the given path.
 *
 * @param string $path
 *   The path to search for files in.
 *
 * @return array
 *   The list of files and diretories found in the given path.
 */
function _auditfiles_not_in_database_get_files($path) {
  // Get the static paths necessary for processing the files.
  $file_system_stream = variable_get('auditfiles_file_system_path', 'public');
  // The full file system path to the Drupal root directory.
  $real_files_path = drupal_realpath($file_system_stream . '://');
  // Get the list of any excluded files, extensions, and/or directories.
  $exclusions = _auditfiles_get_exclusions();
  // The variable to store the data being returned.
  $file_list = array();

  if (empty($path)) {
    $scan_path = $real_files_path;
  }
  else {
    $scan_path = $real_files_path . DIRECTORY_SEPARATOR . $path;
  }
  // Get the files in the specified directory.
  $files = scandir($scan_path);
  foreach ($files as $file) {
    if ($file != '.' && $file != '..') {
      // Check to see if this file should be included.
      $include_file = _auditfiles_not_in_database_include_file(
        $real_files_path . DIRECTORY_SEPARATOR . $path,
        $file,
        $exclusions
      );
      if ($include_file) {
        // The file is to be included, so add it to the data array.
        $file_list[] = array(
          'file_name' => $file,
          'path_from_files_root' => $path,
        );
      }
    }
  }

  return $file_list;
}

/**
 * Checks to see if the file is being included.
 *
 * @param string $path
 *   The complete file system path to the file.
 * @param string $file
 *   The name of the file being checked.
 * @param string $exclusions
 *   The list of files and directories that are not to be included in the list
 *   of files to check.
 *
 * @return boolean
 *   Returns TRUE, if the path or file is being included, or FALSE, if the path
 *   or file has been excluded.
 *
 * @todo Possibly add other file streams that are on the system but not the one
 *   being checked to the exclusions check.
 */
function _auditfiles_not_in_database_include_file($path, $file, $exclusions) {
  // No exclusions have been specified, so all paths and files are included.
  if (empty($exclusions)) {
    return TRUE;
  }
  // Neither the path, nor the file are in the exclusions configuration.
  elseif (!preg_match('@' . $exclusions . '@', $file)
    && !preg_match('@' . $exclusions . '@', $path . DIRECTORY_SEPARATOR . $file)) {
    return TRUE;
  }
  // This path and/or file are being excluded.
  return FALSE;
}

/**
 * Merges one array of files into another.
 *
 * @param array $dest_files
 *   The existing set of files to merge the new set into.
 * @param array $source_files
 *   The new set of files to merge into the other set.
 * @param string $real_path
 *   The complete file system path to the file.
 * @param string $exclusions
 *   The list of files and directories that are not to be included in the list
 *   of files to check.
 *
 * @return array
 *   The merged file arrays.
 */
function _auditfiles_not_in_database_report_processing_merge_file_lists($dest_files, $source_files, $real_path, $new_files_path, $exclusions) {
  foreach ($source_files as $source_file) {
    $include = _auditfiles_not_in_database_include_file(
      $real_path,
      $source_file,
      $exclusions
    );
    if ($include) {
      if (empty($new_files_path)) {
        $dest_files[] = $source_file;
      }
      else {
        $dest_files[] = $new_files_path . DIRECTORY_SEPARATOR . $source_file;
      }
    }
  }
  return $dest_files;
}

/**
 * Corrects the separators of a file system's file path.
 *
 * Changes the separators of a file path, so they are match the ones being used
 * on the operating system the site is running on.
 *
 * @param string $path
 *   The path to correct.
 *
 * @return string
 *   The corrected path.
 */
function _auditfiles_not_in_database_fix_path_separators($path) {
  $path = preg_replace('@\/\/@', DIRECTORY_SEPARATOR, $path);
  $path = preg_replace('@\\\\@', DIRECTORY_SEPARATOR, $path);
  return $path;
}

/**
 * Checks if the specified file is in the database.
 *
 * @param string $filepathname
 *   The path and filename, from the "files" directory, of the file to check.
 *
 * @return bool
 *   Returns TRUE if the file was found in the database, or FALSE, if not.
 */
function _auditfiles_not_in_database_is_file_in_database($filepathname) {
  $file_uri = file_build_uri($filepathname);
  $query = "SELECT fid FROM {file_managed} WHERE uri = :file_uri";
  $fid = db_query($query, array(':file_uri' => $file_uri))->fetchField();
  return empty($fid) ? FALSE : TRUE;
}

/**
 * Formats data about a file for adding to a table row.
 *
 * @param array $file
 *   The name and path of the file, in an associative array.
 * @param string $real_path
 *   The full system path to Drupal's "files" directory.
 * @param string $date_format
 *   The specified system format to use when preparing a date.
 *
 * @return array
 *   The file data, formatted for adding to a table row.
 */
function _auditfiles_not_in_database_format_row_data($file, $real_path, $date_format) {
  $filename = $file['file_name'];
  $filepath = $file['path_from_files_root'];
  if (empty($filepath)) {
    $filepathname = $filename;
  }
  else {
    $filepathname = $filepath . DIRECTORY_SEPARATOR . $filename;
  }
  $real_filepathname = $real_path . DIRECTORY_SEPARATOR . $filepathname;

  $filemime = file_get_mimetype($real_filepathname);
  $filesize = number_format(filesize($real_filepathname));
  if (!empty($date_format)) {
    $filemodtime = format_date(filemtime($real_filepathname), $date_format);
  }

  // Format the data for the table row.
  $row_data[$filepathname] = array(
    'filepathname' => empty($filepathname) ? '' : $filepathname,
    'filemime' => empty($filemime) ? '' : $filemime,
    'filesize' => !isset($filesize) ? '' : $filesize,
    'filemodtime' => empty($filemodtime) ? '' : $filemodtime,
    'filename' => empty($filename) ? '' : $filename,
  );

  return $row_data;
}

/**
 * Returns any report limiting settings.
 *
 * Returns the information that is needed to modify the report and display based
 * on any report limiting options that may have been set on the administrative
 * configuration settings page.
 *
 * @return array
 *   An associative array with these two values:
 *   - record_selection: A string representing record selection type, on which
 *     maximum_records is based.
 *   - maximum_records: An integer representing the total number of records to
 *     display on a report. (A value of 0 means there is no limit.)
 */
function _auditfiles_not_in_database_get_record_limiters() {
  $record_selection = variable_get('auditfiles_not_in_database_record_selection', 'normal');
  $maximum_records = 0;
  if ($record_selection == 'batch_sets') {
    $maximum_records = variable_get('auditfiles_report_options_batch_size', 1000);
  }
  elseif ($record_selection != 'batched') {
    $maximum_records = variable_get('auditfiles_report_options_maximum_records', 250);
    if ($maximum_records > 0) {
      $record_selection = 'limited';
      variable_set('auditfiles_not_in_database_record_selection', 'limited');
    }
  }
  return array(
    'record_selection' => $record_selection,
    'maximum_records' => $maximum_records,
  );
}

/**
 * Returns the header to use for the display table.
 *
 * @return array
 *   The header to use.
 */
function _auditfiles_not_in_database_get_header() {
  return array(
    'filepathname' => array(
      'data' => t('File pathname'),
    ),
    'filemime' => array(
      'data' => t('MIME'),
    ),
    'filesize' => array(
      'data' => t('Size (in bytes)'),
    ),
    'filemodtime' => array(
      'data' => t('Last modified'),
    ),
  );
}

/**
 * Creates an exclusion string.
 *
 * This function creates a list of file and/or directory exclusions to be used
 * with a preg_* function.
 *
 * @return string
 *   The excluions.
 */
function _auditfiles_get_exclusions() {
  $exclusions_array = array();

  // Create the list of requested file exclusions.
  $files = trim(variable_get('auditfiles_exclude_files', '.htaccess'));
  if ($files) {
    $exclude_files = explode(';', $files);
    array_walk($exclude_files, '_auditfiles_make_preg', FALSE);
    $exclusions_array = array_merge($exclusions_array, $exclude_files);
  }

  // Create the list of requested path exclusions.
  $paths = trim(variable_get('auditfiles_exclude_paths', 'color;css;ctools;js'));
  if ($paths) {
    $exclude_paths = explode(';', $paths);
    array_walk($exclude_paths, '_auditfiles_make_preg', TRUE);
    $exclusions_array = array_merge($exclusions_array, $exclude_paths);
  }

  // Exclude other file streams that may be deinfed and in use.
  $exclude_streams = array();
  $auditfiles_file_system_path = variable_get('auditfiles_file_system_path', 'public');
  $file_system_paths = file_get_stream_wrappers();
  foreach ($file_system_paths as $file_system_path_id => $file_system_path) {
    if ($file_system_path_id != $auditfiles_file_system_path) {
      $uri = $file_system_path_id . '://';
      if ($wrapper = file_stream_wrapper_get_instance_by_uri($uri)) {
        $exclude_streams[] = $wrapper->realpath();
      }
    }
  }
  array_walk($exclude_streams, '_auditfiles_make_preg', FALSE);
  $exclusions_array = array_merge($exclusions_array, $exclude_streams);

  // Create the list of requested extension exclusions. (This is a little more
  // complicated.)
  $extensions = trim(variable_get('auditfiles_exclude_extensions', ''));
  if ($extensions) {
    $exclude_extensions = explode(';', $extensions);
    array_walk($exclude_extensions, '_auditfiles_make_preg', FALSE);

    $extensions = implode('|', $exclude_extensions);
    // Add grouping around string & end marker and append to exlusions_array.
    $extensions = '(' . $extensions . ')$';
    $exclusions_array[] = $extensions;
  }

  // Implode exclusions array to a string.
  $exclusions = implode('|', $exclusions_array);

  // Return prepared exclusion string.
  return $exclusions;
}

/**
 * Escapes any possible regular expression characters in the specified string.
 *
 * @param string $element
 *   The string to escape.
 * @param mixed $key
 *   The key or index for the array item passed into $element.
 * @param bool $makefilepath
 *   Set to TRUE to change elements to file paths at the same time.
 */
function _auditfiles_make_preg(&$element, $key, $makefilepath = FALSE) {
  if ($makefilepath) {
    $realpath = drupal_realpath(file_build_uri($element));
    if ($realpath) {
      $element = $realpath;
    }
  }
  $element = preg_quote($element);
}
