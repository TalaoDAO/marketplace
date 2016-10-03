<?php
/**
 * @file
 * Generates a report showing & allowing for merging potential duplicate files.
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
function auditfiles_merge_file_references_form(array $form, array &$form_state) {
  // Check to see if the confirmation form needs to be displayed instead of the
  // normal form.
  if (isset($form_state['storage']['stage'])) {
    if ($form_state['storage']['stage'] == 'confirm') {
      return _auditfiles_merge_file_references_confirm_operation($form, $form_state);
    }
    elseif ($form_state['storage']['stage'] == 'preconfirm') {
      return _auditfiles_merge_file_references_pre_confirm_operation($form, $form_state);
    }
  }

  // Get the records to display.
  // Check to see if there is saved data, and if so, use that.
  $rows = variable_get('auditfiles_merge_file_references_files_to_display', array());
  if (empty($rows)) {
    // The data is not saved and the batch operation has not been run, so get
    // the data using the default options.
    $file_names = _auditfiles_merge_file_references_get_file_list();
    if (!empty($file_names)) {
      $date_format = variable_get('auditfiles_report_options_date_format', 'long');
      foreach ($file_names as $file_name) {
        $rows[$file_name] = _auditfiles_merge_file_references_get_file_data($file_name, $date_format);
      }
    }

    // Save the data for persistent use.
    variable_set('auditfiles_merge_file_references_files_to_display', $rows);
  }

  // Set up the pager.
  if (!empty($rows)) {
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
      $file_count_message = 'Found at least @count files in the file_managed table with duplicate file names.';
    }
    else {
      $file_count_message = 'Found @count files in the file_managed table with duplicate file names.';
    }
    $form_count = format_plural(
      count($rows),
      'Found 1 file in the file_managed table with a duplicate file name.',
      $file_count_message
    );
  }
  else {
    $form_count = t('Found no files in the file_managed table with duplicate file names.');
  }

  // Add filtering options.
  $form['filter']['single_file_names']['auditfiles_merge_file_references_show_single_file_names'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show files without duplicate names'),
    '#default_value' => variable_get('auditfiles_merge_file_references_show_single_file_names', 0),
    '#suffix' => '<div>' . t("Use this button to reset this report's variables and load the page anew.") . '</div>',
  );

  // Add the button to reset the record selection.
  $form['reset_records'] = array(
    '#type' => 'submit',
    '#value' => t('Reset file list'),
    '#suffix' => '<div>' . t("Use this button to reset this report's variables and load it anew. This is also useful, if you have loaded data via the \"Load all files\" button and want to clear it.") . '</div>',
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
    '#header' => _auditfiles_merge_file_references_get_header(),
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
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Merge selected items'),
    );

    // Add the pager.
    $form['pager'] = array('#markup' => theme('pager'));
  }

  return $form;
}

/**
 * Validate handler for the auditfiles_merge_file_references_form form.
 */
function auditfiles_merge_file_references_form_validate($form, &$form_state) {
  if (isset($form_state['values']['op'])) {
    if ($form_state['values']['op'] == t('Merge selected items')) {
      // Make sure at least one file was chosen before starting.
      $counter = 0;
      foreach ($form_state['values']['files'] as $file) {
        if (!empty($file)) {
          $counter++;
        }
      }
      if ($counter == 0) {
        form_set_error(
          'files',
          t('At least one file name must be selected in order to merge the file IDs. No changes were made.')
        );
      }
    }
    elseif ($form_state['values']['op'] == t('Next step')) {
      // Make sure at least two files were chosen before continuing.
      $counter = 0;
      foreach ($form_state['values']['files_being_merged'] as $file) {
        if (!empty($file)) {
          $counter++;
        }
      }
      if ($counter < 2) {
        form_set_error(
          'files_being_merged',
          t('At least two file IDs must be selected in order to merge them.')
        );
      }
    }
  }
}

/**
 * Submit handler for the auditfiles_merge_file_references_form form.
 */
function auditfiles_merge_file_references_form_submit($form, &$form_state) {
  if (isset($form_state['values']['auditfiles_merge_file_references_show_single_file_names'])) {
    variable_set('auditfiles_merge_file_references_show_single_file_names', $form_state['values']['auditfiles_merge_file_references_show_single_file_names']);
  }

  // Check if an operation was performed.
  if (!empty($form_state['values']['op'])) {
    // Check which operation was performed and start the batch process.
    if ($form_state['values']['op'] == t('Load all files')) {
      // Clear the variable, so subsequent pages will load the correct data.
      variable_del('auditfiles_merge_file_references_files_to_display');
      // Prepare and set the batch.
      batch_set(_auditfiles_merge_file_references_batch_display_create_batch());
    }
    elseif ($form_state['values']['op'] == t('Reset file list')) {
      // Reset all the variables for this report, so subsequent pages loads will
      // load and use the correct data.
      db_delete('variable')
        ->condition('name', 'auditfiles_merge_file_references_%', 'LIKE')
        ->execute();
      cache_clear_all('variables', 'cache_bootstrap');
    }
    elseif ($form_state['values']['op'] == t('Merge selected items')) {
      if (!empty($form_state['values']['files'])) {
        foreach ($form_state['values']['files'] as $file_name) {
          if (!empty($file_name)) {
            // At least one file was selected, and the operation has not been
            // confirmed, so modify the data to display the confirmation form.
            $form_state['storage']['files'] = $form_state['values']['files'];
            $form_state['storage']['op'] = $form_state['values']['op'];
            $form_state['storage']['stage'] = 'preconfirm';
            $form_state['rebuild'] = TRUE;
            return TRUE;
          }
        }
      }
    }
    elseif ($form_state['values']['op'] == t('Next step')) {
      if (!empty($form_state['values']['files_being_merged'])) {
        foreach ($form_state['values']['files_being_merged'] as $file_name) {
          if (!empty($file_name)) {
            // At least one file was selected, and the operation has not been
            // confirmed, so modify the data to display the confirmation form.
            $form_state['storage']['files'] = $form_state['values']['files_being_merged'];
            $form_state['storage']['op'] = $form_state['values']['op'];
            $form_state['storage']['stage'] = 'confirm';
            $form_state['rebuild'] = TRUE;
            return TRUE;
          }
        }

        drupal_set_message(t('No items were selected to merge.'));
      }
    }
    elseif ($form_state['values']['op'] == t('Confirm')) {
      if ($form_state['values']['operation'] == 'merge') {
        // Prepare and set the batch.
        batch_set(
          _auditfiles_merge_file_references_batch_merge_create_batch(
            $form_state['values']['file_being_kept'],
            $form_state['storage']['files_being_merged']
          )
        );
        unset($form_state['storage']['stage']);
      }
    }
  }
}

/**
 * The following are functions that are common for all batches in this file.
 */

/**
 * Adds values to a batch definition that are common to all batches in the file.
 *
 * @return array
 *   The beginning of the batch definition.
 */
function _auditfiles_merge_file_references_batch_set_common_values() {
  return array(
    'error_message' => t('One or more errors were encountered processing the files.'),
    'file' => drupal_get_path('module', 'auditfiles') . '/auditfiles.mergefilereferences.inc',
    'finished' => '_auditfiles_merge_file_references_batch_finish_batch',
    'progress_message' => t('Completed @current of @total operations.'),
  );
}

/**
 * The function that is called when the batch is complete.
 */
function _auditfiles_merge_file_references_batch_finish_batch($success, $results, $operations) {
  if ($success) {
    if (!empty($results['files_to_display'])) {
      // Save the gathered data for display.
      variable_set('auditfiles_merge_file_references_files_to_display', $results['files_to_display']);
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
function _auditfiles_merge_file_references_batch_display_create_batch() {
  $batch = _auditfiles_merge_file_references_batch_set_common_values();
  $batch['title'] = t('Loading file audit data');
  $batch['operations'] = _auditfiles_merge_file_references_batch_display_get_operations();
  return $batch;
}

/**
 * Configures the operations for the batch process.
 *
 * @return array
 *   The operations to execute.
 */
function _auditfiles_merge_file_references_batch_display_get_operations() {
  $operations = array();
  $operations[] = array(
    '_auditfiles_merge_file_references_batch_display_get_files',
    array(variable_get('auditfiles_merge_file_references_show_single_file_names', 0)),
  );
  $operations[] = array(
    '_auditfiles_merge_file_references_batch_display_process_files',
    array(variable_get('auditfiles_report_options_date_format', 'long')),
  );
  return $operations;
}

/**
 * The batch process operation for getting the files.
 *
 * @param bool $show_single_file_names
 *   TRUE if the list of files should include filenames that only have one file
 *   ID associated with them.
 * @param array $context
 *   Used by the Batch API to keep track of and pass data from one operation to
 *   the next.
 */
function _auditfiles_merge_file_references_batch_display_get_files($show_single_file_names, array &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox'] = array();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_file'] = '';
    // Get the count of available records to operate on.
    if ($show_single_file_names) {
      $query = 'SELECT COUNT(DISTINCT filename) FROM {file_managed}';
      $record_count = db_query($query)->fetchField();
    }
    else {
      $query = 'SELECT COUNT(filename)
        FROM (SELECT COUNT(fid) AS file_count, filename
          FROM {file_managed}
          GROUP BY filename
          HAVING file_count > 1
        ) AS filename_count';
      $record_count = db_query($query)->fetchField();
    }
    // Set the number of records to operate on.
    $batch_size = variable_get('auditfiles_report_options_batch_size', 1000);
    if ($batch_size > 0 && $record_count > $batch_size) {
      $context['sandbox']['max'] = $batch_size;
    }
    else {
      $context['sandbox']['max'] = $record_count;
    }
  }
  if (empty($context['results']['file_list'])) {
    $context['results']['file_list'] = array();
  }

  if ($show_single_file_names) {
    // Get the file data from the database.
    $query = 'SELECT DISTINCT filename
      FROM {file_managed}
      WHERE filename > :filename';
  }
  else {
    $query = '
      SELECT COUNT(fid) AS file_count, filename
      FROM file_managed
      WHERE filename > :filename
      GROUP BY filename
      HAVING file_count > 1';
  }
  // This cannot be sorted any other way here, or the results are not complete.
  $query .= ' ORDER BY filename ASC';
  $query .= ' LIMIT 20';

  $files = db_query($query, array(':filename' => $context['sandbox']['current_file']))->fetchAll();

  foreach ($files as $file) {
    $context['results']['file_list'][$file->filename] = $file->filename;

    // Update the progress information.
    $context['sandbox']['progress']++;
    $context['sandbox']['current_file'] = $file->filename;
    $context['message'] = t(
      'Getting the list of files. Processed file @num1 of @num2. Last file processed: !file_name.',
      array(
        '@num1' => $context['sandbox']['progress'],
        '@num2' => $context['sandbox']['max'],
        '!file_name' => $file->filename,
      )
    );
  }

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = ($context['sandbox']['progress'] >= $context['sandbox']['max']);
  }
}

/**
 * The batch process operation for formatting the files for display on the page.
 *
 * @param string $date_format
 *   The format to display time/date values in.
 * @param array $context
 *   Used by the Batch API to keep track of and pass data from one operation to
 *   the next.
 */
function _auditfiles_merge_file_references_batch_display_process_files($date_format, array &$context) {
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
  }
  if (empty($context['results']['files_to_display'])) {
    $context['results']['files_to_display'] = array();
  }

  if (!empty($context['results']['file_list'])) {
    $file_list = array_slice($context['results']['file_list'], 0, 20, TRUE);

    foreach ($file_list as $file_name) {
      $context['results']['files_to_display'][$file_name] = _auditfiles_merge_file_references_get_file_data($file_name, $date_format);
      unset($context['results']['file_list'][$file_name]);

      // Update the progress information.
      $context['sandbox']['progress']++;
      $context['message'] = t(
        'Processing the file list. Processed file @num1 of @num2. Last file processed: !file_name.',
        array(
          '@num1' => $context['sandbox']['progress'],
          '@num2' => $context['sandbox']['max'],
          '!file_name' => $file_name,
        )
      );
    }
  }

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = ($context['sandbox']['progress'] >= $context['sandbox']['max']);
  }
}

/**
 * The following are functions for the batch delete operation.
 */

/**
 * Presents a confirmation form to verify the user wants to complete the action.
 *
 * @param array $form
 *   The form definition.
 * @param array $form_state
 *   The current state of the form.
 *
 * @return array
 *   A form array for a confirmation form.
 */
function _auditfiles_merge_file_references_pre_confirm_operation(array $form, array &$form_state) {
  // Prepare the list of items to present to the user.
  if (!empty($form_state['values']['files'])) {
    $header = array(
      'filename' => array(
        'data' => t('Filename'),
      ),
      'fileid' => array(
        'data' => t('File ID'),
      ),
      'fileuri' => array(
        'data' => t('URI'),
      ),
      'filesize' => array(
        'data' => t('Size'),
      ),
      'timestamp' => array(
        'data' => t('Time uploaded'),
      ),
    );

    $date_format = variable_get('auditfiles_report_options_date_format', 'long');

    $files = array();
    foreach ($form_state['values']['files'] as $file_name) {
      if (!empty($file_name)) {
        $query = 'SELECT fid
          FROM {file_managed}
          WHERE filename = :file_name
          ORDER BY uri ASC';
        $results = db_query($query, array(':file_name' => $file_name))->fetchAll();
        if (!empty($results)) {
          foreach ($results as $result) {
            $file = file_load($result->fid);
            if (!empty($file)) {
              $files[$result->fid] = array(
                'filename' => $file_name,
                'fileid' => $result->fid,
                'fileuri' => $file->uri,
                'filesize' => number_format($file->filesize),
                'timestamp' => format_date($file->timestamp, $date_format),
              );
            }
            else {
              drupal_set_message(t('A file object was not found for file ID @fid.', array('@fid' => $result->fid)));
            }
          }
        }
      }
      else {
        // Unsetting the unprocessed files prevents confirm_submit from dealing
        // with them.
        unset($form_state['values']['files'][$file_name]);
      }
    }
  }

  $form['files_being_merged'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $files,
    '#empty' => t('No items found.'),
  );

  if (!empty($files)) {
    $form['actions'] = array(
      '#type' => 'actions',
      'submit' => array(
        '#type' => 'submit',
        '#value' => t('Next step'),
      ),
    );
  }

  return $form;
}

/**
 * Presents a confirmation form to verify the user wants to complete the action.
 *
 * @param array $form
 *   The form definition.
 * @param array $form_state
 *   The current state of the form.
 *
 * @return array
 *   A form array for a confirmation form.
 */
function _auditfiles_merge_file_references_confirm_operation(array $form, array &$form_state) {
  // Prepare the list of items to present to the user.
  if (!empty($form_state['values']['files_being_merged'])) {
    $header = array(
      'origname' => array(
        'data' => t('Filename'),
      ),
      'fileid' => array(
        'data' => t('File ID'),
      ),
      'fileuri' => array(
        'data' => t('URI'),
      ),
      'filesize' => array(
        'data' => t('Size'),
      ),
      'timestamp' => array(
        'data' => t('Time uploaded'),
      ),
    );

    $date_format = variable_get('auditfiles_report_options_date_format', 'long');

    $files = array();
    foreach ($form_state['values']['files_being_merged'] as $file_id) {
      if (!empty($file_id)) {
        $file = file_load($file_id);
        if (!empty($file)) {
          $files[$file_id] = array(
            'origname' => $file->filename,
            'fileid' => $file_id,
            'fileuri' => $file->uri,
            'filesize' => number_format($file->filesize),
            'timestamp' => format_date($file->timestamp, $date_format),
          );
        }
        else {
          drupal_set_message(t('A file object was not found for file ID @fid.', array('@fid' => $file_id)));
        }
      }
      else {
        // Remove files that were not selected.
        unset($form_state['values']['files_being_merged'][$file_id]);
      }
    }

    // Save the selected items for later use.
    $form_state['storage']['files_being_merged'] = $files;
  }

  $form['operation'] = array(
    '#type' => 'hidden',
    '#value' => 'merge',
  );

  // Tell the submit handler to process the confirmation.
  $form['process'] = array(
    '#type' => 'hidden',
    '#value' => 'TRUE',
  );
  // Go back to the main form, when done with this one.
  $form['destination'] = array(
    '#type' => 'hidden',
    '#value' => 'admin/reports/auditfiles/mergefilereferences',
  );

  $form['file_being_kept'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $files,
    '#default_value' => key($files),
    '#empty' => t('No items found.'),
    '#multiple' => FALSE,
  );

  return confirm_form(
    $form,
    t('Which file will be the one the others are merged into?'),
    'admin/reports/auditfiles/mergefilereferences',
    '<div><strong>' . t('This action cannot be undone.') . '</strong></div>',
    t('Confirm'),
    t('Cancel')
  );
}

/**
 * Creates the batch for merging files.
 *
 * @param int $file_being_kept
 *   The file ID of the file to merge the others into.
 * @param array $files_being_merged
 *   The list of file IDs to be processed.
 *
 * @return array
 *   The definition of the batch.
 */
function _auditfiles_merge_file_references_batch_merge_create_batch($file_being_kept, array $files_being_merged) {
  $batch = _auditfiles_merge_file_references_batch_set_common_values();
  $batch['title'] = t('Merging files');
  $operations = array();
  // Remove all the empty values from the array.
  $file_ids = array();
  foreach ($files_being_merged as $file_id => $file_info) {
    if ($file_id != 0) {
      $file_ids[] = $file_id;
    }
  }
  // Fill in the $operations variable.
  foreach ($file_ids as $file_id) {
    if ($file_id != $file_being_kept) {
      $operations[] = array(
        '_auditfiles_merge_file_references_batch_merge_process_batch',
        array(
          $file_being_kept,
          $file_id,
        ),
      );
    }
  }
  $batch['operations'] = $operations;
  return $batch;
}

/**
 * The batch process for deleting the file.
 *
 * @param int $file_being_kept
 *   The file ID of the file to merge the other into.
 * @param int $file_being_merged
 *   The file ID of the file to merge.
 * @param array $context
 *   Used by the Batch API to keep track of and pass data from one operation to
 *   the next.
 */
function _auditfiles_merge_file_references_batch_merge_process_batch($file_being_kept, $file_being_merged, array &$context) {
  // Process the current file.
  _auditfiles_merge_file_references_batch_merge_process_file($file_being_kept, $file_being_merged);
  // The contents of 'results' are available as $results in the 'finished'
  // function.
  $context['results'][] = $file_being_merged;
  // Set a progress message.
  $context['message'] = t(
    'Merged file ID %file_being_merged into file ID %file_being_kept.',
    array(
      '%file_being_kept' => $file_being_kept,
      '%file_being_merged' => $file_being_merged,
    )
  );
}

/**
 * Deletes the specified file from the file_managed table.
 *
 * @param int $file_being_kept
 *   The file ID of the file to merge the other into.
 * @param int $file_being_merged
 *   The file ID of the file to merge.
 */
function _auditfiles_merge_file_references_batch_merge_process_file($file_being_kept, $file_being_merged) {
  // Get the usage data for the file being kept.
  $file_being_kept_results = db_select('file_usage', 'fu')
    ->fields('fu', array('module', 'type', 'id', 'count'))
    ->condition('fid', $file_being_kept)
    ->execute()
    ->fetchAll();
  if (empty($file_being_kept_results)) {
    $message = t('There was no file usage data found for the file you choose to keep. No changes were made.');
    drupal_set_message($message, 'warning');
    return;
  }
  $file_being_kept_data = reset($file_being_kept_results);
  // Also get the filename for the file being kept.
  $file_being_kept_name_results = db_select('file_managed', 'fm')
    ->fields('fm', array('filename'))
    ->condition('fid', $file_being_kept)
    ->execute()
    ->fetchAll();
  $file_being_kept_name = reset($file_being_kept_name_results);

  // Get the usage data for the file being merged.
  $file_being_merged_results = db_select('file_usage', 'fu')
    ->fields('fu', array('module', 'type', 'id', 'count'))
    ->condition('fid', $file_being_merged)
    ->execute()
    ->fetchAll();
  if (empty($file_being_merged_results)) {
    $message = t(
      'There was an error retrieving the file usage data from the database for file ID !fid. Please check the files in one of the other reports. No changes were made for this file.',
      array('!fid' => $file_being_merged)
    );
    drupal_set_message($message, 'warning');
    return;
  }
  $file_being_merged_data = reset($file_being_merged_results);
  // Also get the URI for the file being merged.
  $file_being_merged_uri_results = db_select('file_managed', 'fm')
    ->fields('fm', array('uri'))
    ->condition('fid', $file_being_merged)
    ->execute()
    ->fetchAll();
  $file_being_merged_uri = reset($file_being_merged_uri_results);

  // Compare the content ID of the file being merged with the content ID of the
  // file being kept.
  if ($file_being_kept_data->id == $file_being_merged_data->id) {
    // The IDs match, so update the kept file and delete the one being merged.
    $file_being_kept_data->count += $file_being_merged_data->count;
    // Delete the unnecessary entry from the file_usage table.
    db_delete('file_usage')
      ->condition('fid', $file_being_merged)
      ->execute();
    // Update the entry for the file being kept.
    db_update('file_usage')
      ->fields(array('count' => $file_being_kept_data->count))
      ->condition('fid', $file_being_kept)
      ->condition('module', $file_being_kept_data->module)
      ->condition('type', $file_being_kept_data->type)
      ->condition('id', $file_being_kept_data->id)
      ->execute();
  }
  else {
    // The IDs do not match, so update the file being merged, by making the file
    // usage of the file being merged point to the fid of the file being kept.
    db_update('file_usage')
      ->fields(array('fid' => $file_being_kept))
      ->condition('fid', $file_being_merged)
      ->condition('module', $file_being_merged_data->module)
      ->condition('type', $file_being_merged_data->type)
      ->condition('id', $file_being_merged_data->id)
      ->execute();
    // Update any fields that might be pointing to the file being merged.
    _auditfiles_merge_file_references_update_file_fields($file_being_kept, $file_being_merged);
  }

  // Delete the unnecessary entries from the file_managed table.
  db_delete('file_managed')
    ->condition('fid', $file_being_merged)
    ->execute();

  // Delete the duplicate file.
  if (!empty($file_being_merged_uri->uri)) {
    file_unmanaged_delete($file_being_merged_uri->uri);
  }

  // Remove the deleted files from the list of files to display.
  $rows = variable_get('auditfiles_merge_file_references_files_to_display', array());
  unset($rows[$file_being_kept_name->filename]);
  variable_set('auditfiles_merge_file_references_files_to_display', $rows);
}

/**
 * Updates any fields that might be pointing to the file being merged.
 *
 * @param int $file_being_kept
 *   The file ID of the file to merge the other into.
 * @param int $file_being_merged
 *   The file ID of the file to merge.
 */
function _auditfiles_merge_file_references_update_file_fields($file_being_kept, $file_being_merged) {
  // Get any fields that might be referencing this file being merged.
  $file_being_merged_fields = file_get_file_references(file_load($file_being_merged));

  // If the variable is empty, there are no fields that reference this file.
  if (empty($file_being_merged_fields)) {
    return;
  }

  // Copied from file.module and modified as necessary.
  // Maybe something like this should be a separate function, so it can be
  // called by other modules.
  // Loop through all references of this file.
  foreach ($file_being_merged_fields as $field_name => $field_references) {
    foreach ($field_references as $entity_type => $type_references) {
      foreach ($type_references as $id => $reference) {
        // Try to load $entity and $field.
        $entity = entity_load($entity_type, array($id));
        $entity = reset($entity);
        if ($entity) {
          // Load all field items for that entity.
          $field_items = field_get_items($entity_type, $entity, $field_name);
          // Find the field item with the matching file ID.
          foreach ($field_items as $item_id => $item) {
            if ($item['fid'] == $file_being_merged) {
              $file_object_being_kept = file_load($file_being_kept);

              // The file data on the entity is stored as an array, like this:
              // $entity->{$field_name}[LANGUAGE_NONE][$delta][$key] => $value;
              foreach ($entity->{$field_name}[LANGUAGE_NONE][$item_id] as $key => $value) {
                if (!empty($file_object_being_kept->{$key})
                  && $entity->{$field_name}[LANGUAGE_NONE][$item_id][$key] != $file_object_being_kept->{$key}) {
                  $entity->{$field_name}[LANGUAGE_NONE][$item_id][$key] = $file_object_being_kept->{$key};
                }
              }

              field_attach_update($entity_type, $entity);
              // This is being done outside of an entity save operation, so the
              // cache needs to be cleared for the entity:
              entity_get_controller($entity_type)->resetCache(array($id));
              break;
            }
          }
        }
      }
    }
  }
}

/**
 * The following are functions for retrieving and processing the file data.
 */

/**
 * Retrieves the file IDs to operate on.
 *
 * @return array
 *   The file IDs.
 */
function _auditfiles_merge_file_references_get_file_list() {
  $result_set = array();

  // Get all the file IDs in the file_managed table.
  $query = 'SELECT fid, filename
    FROM {file_managed}
    ORDER BY filename ASC';

  // If record limit has been configured, only use those records within that
  // specification.
  $maximum_records = variable_get('auditfiles_report_options_maximum_records', 250);
  if ($maximum_records > 0) {
    $query .= ' LIMIT ' . $maximum_records;
  }

  $files = db_query($query)->fetchAllKeyed();

  $show_single_file_names = variable_get('auditfiles_merge_file_references_show_single_file_names', 0);
  foreach ($files as $file_id => $file_name) {
    if ($show_single_file_names) {
      // Show all files, whether there are duplicates of the filename, or not.
      $result_set[] = $file_name;
    }
    else {
      // Only show files where there are duplicates of the filename.
      // Check to see if there are any duplicates.
      $query2 = 'SELECT COUNT(fid) count
        FROM {file_managed}
        WHERE filename = :filename
          AND fid != :fid';
      $results2 = db_query(
        $query2,
        array(
          ':filename' => $file_name,
          ':fid' => $file_id,
        )
      )->fetchField();

      if ($results2 > 0) {
        // There are duplicates of this file, so record its file name.
        $result_set[] = $file_name;
      }
    }
  }

  return array_unique($result_set);
}

/**
 * Retrieves information about an individual file from the database.
 *
 * @param int $file_name
 *   The ID of the file to prepare for display.
 *
 * @return array
 *   The row for the table on the report, with the file's information formatted
 *   for display.
 */
function _auditfiles_merge_file_references_get_file_data($file_name, $date_format) {
  // Get all file IDs for those files whose names match the provided one.
  $fid_query = 'SELECT fid
    FROM {file_managed}
    WHERE filename = :filename';
  $fid_results = db_query($fid_query, array(':filename' => $file_name))->fetchAll();

  if (count($fid_results) > 0) {
    $fid_header = array(
      t('File ID'),
      t('URI'),
      t('Size (in bytes)'),
      t('Date'),
    );

    $fid_rows = array();
    foreach ($fid_results as $fid_result) {
      // Get the file object.
      $file = file_load($fid_result->fid);

      // Add the data to the collective.
      $fid_rows[] = array(
        $file->fid,
        $file->uri,
        number_format($file->filesize),
        format_date($file->timestamp, $date_format),
      );
    }

    // Theme the table.
    $references = theme(
      'table',
      array(
        'header' => $fid_header,
        'rows' => $fid_rows,
      )
    );
    return array(
      'filename' => $file_name,
      'references' => $references,
    );
  }
}

/**
 * Converts file usage data into a themed table for display.
 *
 * @param array $fu_results
 *   An array of objects representing the file usages of a file.
 *
 * @return array
 *   The table of file usages, themed for display.
 */
function _auditfiles_merge_file_references_get_file_usage_data(array $fu_results) {
  // Add the file usages to the display record.
  $fu_header = array(
    t('Module'),
    t('Type'),
    t('Content ID'),
    t('Count'),
  );

  $fu_rows = array();
  foreach ($fu_results as $fu_result) {
    // Add the data to the collective.
    $fu_rows[] = array(
      $fu_result->module,
      $fu_result->type,
      ($fu_result->type == 'node') ? l($fu_result->id, 'node/' . $fu_result->id) : $fu_result->id,
      $fu_result->count,
    );
  }

  // Theme the table.
  return theme(
    'table',
    array(
      'header' => $fu_header,
      'rows' => $fu_rows,
    )
  );
}

/**
 * The following are helper functions.
 */

/**
 * Returns the header to use for the display table.
 *
 * @return array
 *   The header to use.
 */
function _auditfiles_merge_file_references_get_header() {
  return array(
    'filename' => array(
      'data' => t('Name'),
    ),
    'references' => array(
      'data' => t('File IDs using the filename'),
    ),
  );
}
