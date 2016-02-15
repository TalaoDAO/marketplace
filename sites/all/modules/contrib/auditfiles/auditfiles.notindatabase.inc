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
    $file_system_stream = variable_get('auditfiles_file_system_path', 'public');
    $file_system_path = drupal_realpath($file_system_stream . '://');
    $file_ids = _auditfiles_not_in_database_get_file_list($file_system_path, TRUE);
    if (!empty($file_ids)) {
      $date_format = variable_get('auditfiles_report_options_date_format', 'long');
      foreach ($file_ids as $file_id) {
        $row = _auditfiles_not_in_database_get_file_data($file_id, $date_format);
        if (isset($row)) {
          $rows[$file_id] = $row;
        }
      }
    }

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
  $maximum_records = variable_get('auditfiles_report_options_maximum_records', 0);
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
    array(variable_get('auditfiles_report_options_date_format', 'long')),
  );
  return $operations;
}

/**
 * Recurse directories and add files to an array.
 *
 * @param array $context
 *   Used by the Batch API to keep track of and pass data from one operation to
 *   the next.
 */
function _auditfiles_not_in_database_batch_display_get_files(array &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox'] = array();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_file'] = 0;

    $context['sandbox']['exclusions'] = _auditfiles_get_exclusions();

    // Get the starter list of files from the root directory.
    $file_system_stream = variable_get('auditfiles_file_system_path', 'public');
    $context['sandbox']['path'] = drupal_realpath($file_system_stream . '://');
    $files = array_diff(scandir($context['sandbox']['path']), array('.', '..'));
    if (!empty($files)) {
      foreach ($files as $file) {
        $context['sandbox']['files'][$context['sandbox']['path'] . DIRECTORY_SEPARATOR . $file] = $context['sandbox']['path'] . DIRECTORY_SEPARATOR . $file;
      }
    }

    $context['sandbox']['batch_size'] = variable_get('auditfiles_report_options_batch_size', 0);
    if ($context['sandbox']['batch_size'] > 0) {
      $context['sandbox']['max'] = $context['sandbox']['batch_size'];
    }
    else {
      $context['sandbox']['max'] = count($context['sandbox']['files']);
    }
  }
  if (empty($context['results']['file_list'])) {
    $context['results']['file_list'] = array();
  }

  if (!empty($context['sandbox']['files'])) {
    // Process 20 files at a time, so the batch process has an opportunity to
    // reset itself.
    $file_list = array_slice($context['sandbox']['files'], 0, 20, TRUE);
    foreach ($file_list as $file) {
      // Check to see if it excluded.
      if (empty($context['sandbox']['exclusions']) || !preg_match('@' . $context['sandbox']['exclusions'] . '@', $file)) {
        if (is_dir($file)) {
          // Scan the directory and append the files to the files array.
          $found_files = array_diff(scandir($file), array('.', '..'));
          if (!empty($found_files)) {
            // Add the newly found files to the end of the files array.
            foreach ($found_files as $found_file) {
              $context['sandbox']['files'][$file . DIRECTORY_SEPARATOR . $found_file] = $file . DIRECTORY_SEPARATOR . $found_file;
            }

            // Update the max file count.
            if ($context['sandbox']['batch_size'] > 0) {
              $context['sandbox']['max'] = $context['sandbox']['batch_size'];
            }
            else {
              $context['sandbox']['max'] = $context['sandbox']['max'] + count($found_files);
            }
          }
        }
        else {
          // Add the file to the list.
          $file = preg_replace('/\/\//', DIRECTORY_SEPARATOR, $file);
          $array_item = preg_replace('/\\\\/', DIRECTORY_SEPARATOR, $file);
          $context['results']['file_list'][$array_item] = $array_item;

          // Check to see if the array has reached its limit.
          if (count($context['results']['file_list']) == $context['sandbox']['max']) {
            $context['sandbox']['progress'] = $context['sandbox']['max'];
          }
        }
      }

      unset($context['sandbox']['files'][$file]);

      // Update the progress information.
      $context['sandbox']['progress']++;
      $context['sandbox']['current_file'] = $file;
      $context['message'] = t(
        'Getting the list of files. Processed file @num1 of @num2. Last file processed: !file_name.',
        array(
          '@num1' => $context['sandbox']['progress'],
          '@num2' => $context['sandbox']['max'],
          '!file_name' => $file,
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
 * @param string $date_format
 *   The format to display time/date values in.
 * @param array $context
 *   Used by the Batch API to keep track of and pass data from one operation to
 *   the next.
 */
function _auditfiles_not_in_database_batch_display_process_files($date_format, array &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox'] = array();
    if (empty($context['results']['file_list'])) {
      $context['sandbox']['progress'] = 1;
      $context['sandbox']['max'] = 1;
    }
    else {
      $context['sandbox']['progress'] = 0;
      $context['sandbox']['max'] = count($context['results']['file_list']);
    }

    // Get the path of the currently used file scheme.
    $file_system_stream = variable_get('auditfiles_file_system_path', 'public');
    $context['sandbox']['files_path'] = variable_get('file_' . $file_system_stream . '_path', conf_path() . '/files');
  }
  if (empty($context['results']['files_to_display'])) {
    $context['results']['files_to_display'] = array();
  }

  if (!empty($context['results']['file_list'])) {
    $file_list = array_slice($context['results']['file_list'], 0, 20, TRUE);

    foreach ($file_list as $file_id => $filepathname) {
      // Remove the path to the files directory.
      $matches = array();
      preg_match_all('~(.*)(' . $context['sandbox']['files_path'] . ')(.*)~', $filepathname, $matches);
      $match = end($matches);
      $match = reset($match);
      $file_uri = file_build_uri($match);

      // See if the file is in the database.
      $query = "SELECT fid FROM {file_managed} WHERE uri = :file_uri";
      $stored_file = db_query($query, array(':file_uri' => $file_uri))->fetchField();

      if (empty($stored_file)) {
        // This file is not in the database.
        // Get the filename from the filepathname.
        $filename = substr($filepathname, strrpos($filepathname, '/') + 1);
        // Save the file information.
        $context['results']['files_to_display'][$filepathname] = array(
          'filepathname' => $filepathname,
          'filemime' => file_get_mimetype($filepathname),
          'filesize' => number_format(filesize($filepathname)),
          'filemodtime' => format_date(filemtime($filepathname), $date_format),
          'filename' => $filename,
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
 *   Used by the Batch API to keep track of and pass data from one operation to
 *   the next.
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
  // Get the path to the file relative to it's file storage location.
  $filename = preg_replace('@' . preg_quote(drupal_realpath('./')) . '.@', '', $filepathname);
  // Get the scheme's path.
  $file_system_stream = variable_get('auditfiles_file_system_path', 'public');
  $scheme_path = variable_get('file_' . $file_system_stream . '_path', conf_path() . '/files');
  $filename = preg_replace('@' . preg_quote($scheme_path) . '.@', '', $filename);
  $file->filename = trim(basename($filename));
  $file->uri = file_build_uri($filename);
  $file->filemime = file_get_mimetype($file->uri);
  $file->filesize = filesize(drupal_realpath($file->uri));
  $file->status = FILE_STATUS_PERMANENT;
  $file->timestamp = REQUEST_TIME;

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
 *   Used by the Batch API to keep track of and pass data from one operation to
 *   the next.
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
  // Delete the file without invoking any hooks.
  if (file_unmanaged_delete($filename)) {
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
function _auditfiles_not_in_database_get_file_list($directory, $recursive) {
  $array_items = array();
  $exclusions = _auditfiles_get_exclusions();
  // If record limition has been configured, only use those records within that
  // specification.
  $maximum_records = variable_get('auditfiles_report_options_maximum_records', 0);

  if ($maximum_records == 0 || ($maximum_records > 0 && count($array_items) < $maximum_records)) {
    // Get the list of files in the specified directory.
    if ($handle = opendir($directory)) {
      while (($file = readdir($handle)) !== FALSE) {
        // Exclude files, paths and extensions according to the admin specified
        // exclusions list.
        if ($file != "." && $file != ".."
          && (empty($exclusions) || (!preg_match('@' . $exclusions . '@', $file)
          && !preg_match('@' . $exclusions . '@', $directory . DIRECTORY_SEPARATOR . $file)))) {
          if (is_dir($directory . '/' . $file)) {
            if ($recursive && ($maximum_records == 0 || count($array_items) < $maximum_records)) {
              $array_items = array_merge($array_items, _auditfiles_not_in_database_get_file_list($directory . DIRECTORY_SEPARATOR . $file, $recursive));
            }
          }
          else {
            // Add the file to the list.
            $file = $directory . DIRECTORY_SEPARATOR . $file;
            $file = preg_replace('/\/\//', DIRECTORY_SEPARATOR, $file);
            $array_item = preg_replace('/\\\\/', DIRECTORY_SEPARATOR, $file);
            $array_items[$array_item] = $array_item;
          }
        }
      }
    }

    closedir($handle);
  }

  if ($maximum_records > 0 && count($array_items) >= $maximum_records) {
    $array_items = array_slice($array_items, 0, $maximum_records);
  }
  return $array_items;
}

/**
 * Retrieves file data from the database and checks if it is on the server.
 *
 * @param string $filepathname
 *   The path and name of the file to prepare for display.
 * @param string $date_format
 *   The format to display time/date values in.
 *
 * @return array
 *   The row for the table on the report, with the file's information formatted
 *   for display.
 */
function _auditfiles_not_in_database_get_file_data($filepathname, $date_format) {
  // Convert the path name to a Drupal URI scheme for comparison in the
  // database.
  // Get the path of the currently used file scheme.
  $file_system_stream = variable_get('auditfiles_file_system_path', 'public');
  $files_path = variable_get('file_' . $file_system_stream . '_path', conf_path() . '/files');

  // Remove the path to the files directory.
  if ($files_path != '') {
    $matches = array();
    preg_match_all('~(.*)(' . $files_path . ')(.*)~', $filepathname, $matches);
    $match = end($matches);
    $match = reset($match);
    $file_uri = file_build_uri($match);
  }

  // See if the file is in the database.
  $query = "SELECT fid FROM {file_managed} WHERE uri = :file_uri";
  $stored_file = db_query($query, array(':file_uri' => $file_uri))->fetchField();
  if (empty($stored_file)) {
    // This file is not in the database.
    // Get the filename from the filepathname.
    $filename = substr($filepathname, strrpos($filepathname, '/') + 1);
    // Return the file.
    return array(
      'filepathname' => $filepathname,
      'filemime' => file_get_mimetype($filepathname),
      'filesize' => number_format(filesize($filepathname)),
      'filemodtime' => format_date(filemtime($filepathname), $date_format),
      'filename' => $filename,
    );
  }
}

/**
 * The following are helper functions.
 */

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
    $maximum_records = variable_get('auditfiles_report_options_batch_size', 0);
  }
  elseif ($record_selection != 'batched') {
    $maximum_records = variable_get('auditfiles_report_options_maximum_records', 0);
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
  $paths = trim(variable_get('auditfiles_exclude_paths', 'color css ctools js'));
  if ($paths) {
    $exclude_paths = explode(';', $paths);
    array_walk($exclude_paths, '_auditfiles_make_preg', TRUE);
    $exclusions_array = array_merge($exclusions_array, $exclude_paths);
  }

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
