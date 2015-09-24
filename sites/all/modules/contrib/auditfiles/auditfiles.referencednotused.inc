<?php
/**
 * @file
 * Generates report showing files referenced by content, but not in file_usage.
 */

/**
 * The following are functions for displaying the list of files on the page.
 */

/**
 * Generates the report.
 *
 * @param array $form
 *   The form definition.
 * @param array $form_state
 *   The current state of the form.
 *
 * @return array
 *   The form definition.
 */
function auditfiles_referenced_not_used_form(array $form, array &$form_state) {
  // Check to see if the confirmation form needs to be displayed instead of the
  // normal form.
  if (isset($form_state['storage']['confirm'])) {
    return _auditfiles_referenced_not_used_confirm_operation($form, $form_state);
  }

  $output = '<p>' . t('Listed here are file references in content which do not
    have references in the file_usage table.') . '</p>';
  $output .= t('The files in this list are using the %scheme scheme and are
    relative to the files directory path, located at %path.',
    array(
      '%scheme' => file_default_scheme(),
      '%path' => variable_get('file_' . file_default_scheme() . '_path', conf_path() . '/files'),
    )
  ) . '</p>';
  $form['introduction'] = array(
    '#markup' => $output,
  );

  // Get the records to display.
  // Check to see if the data has been stored.
  if (!empty($form_state['storage']['saved_rows'])) {
    // The data is currently saved, so use that.
    $rows = unserialize($form_state['storage']['saved_rows']);
  }
  else {
    // Check to see if the batch operation was just run. If so, use that data.
    $rows = variable_get('auditfiles_referenced_not_used_files_to_display', array());
    if (empty($rows)) {
      // The data is not saved and the batch operation has not been run, so get
      // the data using the default options.
      $file_data = _auditfiles_referenced_not_used_get_file_list();
      if (!empty($file_data)) {
        foreach ($file_data as $reference_id => $row_data) {
          $rows[$reference_id] = _auditfiles_referenced_not_used_get_file_data($reference_id, $row_data);
        }
      }
    }
  }
  // Save the data for later retrieval.
  $form['saved_rows'] = array(
    '#type' => 'hidden',
    '#value' => serialize($rows),
  );

  // Set up the pager.
  if (!empty($rows)) {
    $items_per_page = variable_get('auditfiles_report_options_items_per_page', 50);
    if (!empty($items_per_page)) {
      $current_page = pager_default_initialize(count($rows), $items_per_page);
      // Break the total data set into page sized chunks.
      $pages = array_chunk($rows, $items_per_page, TRUE);
    }
  }

  // Get any specified record selection limiters.
  $record_limiters = _auditfiles_referenced_not_used_get_record_limiters();
  $record_selection = $record_limiters['record_selection'];
  $maximum_records = $record_limiters['maximum_records'];

  // Define the form.
  // Setup the record count and related messages.
  if (!empty($rows)) {
    if ($record_selection == 'batch_sets') {
      $file_count_message = 'Found @count files referenced in content that are not in the file_usage table.';
    }
    elseif ($maximum_records > 0) {
      $file_count_message = 'Found at least @count files referenced in content that are not in the file_usage table.';
    }
    else {
      $file_count_message = 'Found @count files referenced in content that are not in the file_usage table.';
    }
    $form_count = format_plural(
      count($rows),
      'Found 1 file referenced in content that is not in the file_usage table.',
      $file_count_message
    );
  }
  else {
    $form_count = 'Found no files referenced in content that are not in the file_usage table.';
  }

  // Add the button to batch process the list of results.
  if ($record_selection == 'limited') {
    $batch_size = variable_get('auditfiles_report_options_batch_size', 0);
    if ($batch_size > 0) {
      $form['batch_process'] = array(
        '#type' => 'submit',
        '#value' => t('Load first batch set'),
      );
    }
    else {
      $form['batch_process'] = array(
        '#type' => 'submit',
        '#value' => t('Load all records'),
      );
    }
  }
  elseif ($record_selection == 'batch_sets') {
    // Add the button to load the previous batch set.
    $form['batch_process_prev'] = array(
      '#type' => 'submit',
      '#value' => t('Load previous batch set'),
    );
    // Add the button to load the next batch set.
    $form['batch_process_next'] = array(
      '#type' => 'submit',
      '#value' => t('Load next batch set'),
    );
  }
  // Add the button to reset the record selection.
  if ($record_selection != 'normal') {
    $form['reset_records'] = array(
      '#type' => 'submit',
      '#value' => t('Reset record selection'),
    );
  }

  $form['files'] = array(
    '#type' => 'tableselect',
    '#header' => _auditfiles_referenced_not_used_get_header(),
    '#empty' => t('No items found.'),
    '#prefix' => '<div><em>' . $form_count . '</em></div>',
  );

  if (!empty($rows) && !empty($pages)) {
    $form['files']['#options'] = $pages[$current_page];
  }
  elseif (!empty($rows)) {
    $form['files']['#options'] = $rows;
  }
  else {
    $form['files']['#options'] = array();
  }

  if (!empty($rows)) {
    $form['actions'] = array('#type' => 'actions');
    $form['actions']['add'] = array(
      '#type' => 'submit',
      '#value' => t('Add selected items to the file_usage table'),
    );
    $form['actions']['markup'] = array(
      '#markup' => '&nbsp;' . t('or') . '&nbsp;',
    );
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete selected references'),
    );

    $form['pager'] = array('#markup' => theme('pager'));
  }

  return $form;
}

/**
 * Submit handler for the auditfiles_referenced_not_used_form form.
 */
function auditfiles_referenced_not_used_form_submit($form, &$form_state) {
  // Check if an operation was performed.
  if (!empty($form_state['values']['op'])) {
    // Check which operation was performed and start the batch process.
    if ($form_state['values']['op'] == 'Load all records' || $form_state['values']['op'] == 'Load first batch set') {
      // Clear the variable, so subsequent pages will load the correct data.
      variable_del('auditfiles_files_to_display');
      $batch_size = variable_get('auditfiles_report_options_batch_size', 0);
      if ($batch_size > 0) {
        // Set appropriate variables for this operation.
        variable_set('auditfiles_referenced_not_used_record_selection', 'batch_sets');
      }
      else {
        // Set appropriate variables for this operation.
        variable_set('auditfiles_referenced_not_used_record_selection', 'batched');
      }
      // Prepare and set the batch.
      batch_set(_auditfiles_referenced_not_used_batch_display_create_batch());
    }
    elseif ($form_state['values']['op'] == 'Load previous batch set') {
      // Clear the variable, so subsequent pages will load the correct data.
      variable_del('auditfiles_files_to_display');
      // Set appropriate variables for this operation.
      $batch_size = variable_get('auditfiles_report_options_batch_size', 0);
      $batch_offset = variable_get('auditfiles_referenced_not_used_batch_offset', 0);
      variable_set('auditfiles_referenced_not_used_batch_offset', $batch_offset - $batch_size);
      variable_set('auditfiles_referenced_not_used_record_selection', 'batch_sets');
      // Prepare and set the batch.
      batch_set(_auditfiles_referenced_not_used_batch_display_create_batch());
    }
    elseif ($form_state['values']['op'] == 'Load next batch set') {
      // Clear the variable, so subsequent pages will load the correct data.
      variable_del('auditfiles_files_to_display');
      // Set appropriate variables for this operation.
      $batch_size = variable_get('auditfiles_report_options_batch_size', 0);
      $batch_offset = variable_get('auditfiles_referenced_not_used_batch_offset', 0);
      variable_set('auditfiles_referenced_not_used_batch_offset', $batch_offset + $batch_size);
      variable_set('auditfiles_referenced_not_used_record_selection', 'batch_sets');
      // Prepare and set the batch.
      batch_set(_auditfiles_referenced_not_used_batch_display_create_batch());
    }
    elseif ($form_state['values']['op'] == 'Reset record selection') {
      // Clear the variable, so subsequent pages will load the correct data.
      variable_del('auditfiles_files_to_display');
      // Set appropriate variables for this operation.
      unset($form_state['values']['saved_rows']);
      variable_set('auditfiles_referenced_not_used_record_selection', 'normal');
      variable_del('auditfiles_referenced_not_used_batch_offset');
    }
    elseif (($form_state['values']['op'] == 'Add selected items to the file_usage table'
      || $form_state['values']['op'] == 'Delete selected references')
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
    elseif ($form_state['values']['op'] == 'Yes') {
      if ($form_state['values']['operation'] == 'add') {
        // Prepare and set the batch.
        batch_set(_auditfiles_referenced_not_used_batch_add_create_batch($form_state['values']['changelist']));
      }
      elseif ($form_state['values']['operation'] == 'delete') {
        // Prepare and set the batch.
        batch_set(_auditfiles_referenced_not_used_batch_delete_create_batch($form_state['values']['changelist']));
      }
    }
  }

  if (!empty($form_state['values']['saved_rows'])) {
    $form_state['storage']['saved_rows'] = $form_state['values']['saved_rows'];
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
function _auditfiles_referenced_not_used_batch_set_common_values() {
  return array(
    'error_message' => t('One or more errors were encountered processing the files.'),
    'file' => drupal_get_path('module', 'auditfiles') . '/auditfiles.referencednotused.inc',
    'finished' => '_auditfiles_referenced_not_used_batch_finish_batch',
    'progress_message' => t('Completed @current of @total operations.'),
  );
}

/**
 * The function that is called when the batch is complete.
 */
function _auditfiles_referenced_not_used_batch_finish_batch($success, $results, $operations) {
  if ($success) {
    if (!empty($results['files_to_display'])) {
      // Save the gathered data for display.
      variable_set('auditfiles_files_to_display', $results['files_to_display']);
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
function _auditfiles_referenced_not_used_batch_display_create_batch() {
  $batch = _auditfiles_referenced_not_used_batch_set_common_values();
  $batch['title'] = t('Loading file audit data');
  $batch['operations'] = _auditfiles_referenced_not_used_batch_display_get_operations();
  return $batch;
}

/**
 * Configures the operations for the batch process.
 *
 * @return array
 *   The operations to execute.
 */
function _auditfiles_referenced_not_used_batch_display_get_operations() {
  $operations = array();
  $file_data = _auditfiles_referenced_not_used_get_file_list();
  foreach ($file_data as $reference_id => $row_data) {
    $operations[] = array(
      '_auditfiles_referenced_not_used_batch_display_process_operation',
      array($reference_id, $row_data),
    );
  }
  return $operations;
}

/**
 * The batch process for displaying the files.
 *
 * @param string $reference_id
 *   The ID for keeping track of the reference.
 * @param array $row_data
 *   The data to use for creating the row.
 * @param array $context
 *   Used by the Batch API to keep track of and pass data from one operation to
 *   the next.
 */
function _auditfiles_referenced_not_used_batch_display_process_operation($reference_id, array $row_data, array &$context) {
  // Process the current file.
  $file = _auditfiles_referenced_not_used_get_file_data($reference_id, $row_data);
  // The contents of 'results' are available as $results in the 'finished'
  // function.
  $context['results']['files_to_display'][$reference_id] = $file;
  // Set a progress message.
  $context['message'] = t('Processed reference ID %reference_id.', array('%reference_id' => $reference_id));
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
function _auditfiles_referenced_not_used_confirm_operation(array $form, array &$form_state) {
  $values = $form_state['values'];

  $form['changelist'] = array(
    '#prefix' => '<ul>',
    '#suffix' => '</ul>',
    '#tree' => TRUE,
  );

  // Prepare the list of items to present to the user.
  if (!empty($values['files'])) {
    foreach ($values['files'] as $reference_id) {
      if (!empty($reference_id)) {
        $reference_id_parts = explode('.', $reference_id);
        $file = file_load($reference_id_parts[4]);
        if (!empty($file)) {
          if ($values['op'] == 'Add selected items to the file_usage table') {
            $message = t('will be added to the file_usage table.');
          }
          elseif ($values['op'] == 'Delete selected references') {
            $message = t('will be deleted from the content.');
          }
          $form['changelist'][$reference_id] = array(
            '#type' => 'hidden',
            '#value' => $reference_id,
            '#prefix' => '<li><strong>' . $file->filename . '</strong> ' . $message,
            '#suffix' => "</li>\n",
          );
        }
      }
      else {
        // Unsetting the unprocessed files prevents confirm_submit from dealing
        // with them.
        unset($form_state['values']['files'][$reference_id]);
      }
    }
  }

  $form['operation'] = array(
    '#type' => 'hidden',
  );
  if ($values['op'] == 'Add selected items to the file_usage table') {
    $form['operation']['#value'] = 'add';
    $confirm_question = t('Add these files to the file_usage table?');
    $confirm_description = '';
  }
  elseif ($values['op'] == 'Delete selected references') {
    $form['operation']['#value'] = 'delete';
    $confirm_question = t('Delete these references from their content?');
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
    '#value' => 'admin/reports/auditfiles/referencednotused',
  );

  return confirm_form(
    $form,
    $confirm_question,
    'admin/reports/auditfiles/referencednotused',
    $confirm_description,
    t('Yes'),
    t('No')
  );
}

/**
 * Creates the batch for adding files to the file_usage table.
 *
 * @param array $referenceids
 *   The list of IDs to be processed.
 *
 * @return array
 *   The definition of the batch.
 */
function _auditfiles_referenced_not_used_batch_add_create_batch(array $referenceids) {
  $batch = _auditfiles_referenced_not_used_batch_set_common_values();
  $batch['title'] = t('Adding files to the file_usage table');
  $operations = array();
  // Remove all the empty values from the array.
  $reference_ids = array();
  foreach ($referenceids as $reference_id) {
    if (!empty($reference_id)) {
      $reference_ids[] = $reference_id;
    }
  }
  // Fill in the $operations variable.
  foreach ($reference_ids as $reference_id) {
    $operations[] = array(
      '_auditfiles_referenced_not_used_batch_add_process_batch',
      array($reference_id),
    );
  }
  $batch['operations'] = $operations;
  return $batch;
}

/**
 * The batch process for adding the file.
 *
 * @param int $reference_id
 *   The ID of a file to add to the file_usage table.
 * @param array $context
 *   Used by the Batch API to keep track of and pass data from one operation to
 *   the next.
 */
function _auditfiles_referenced_not_used_batch_add_process_batch($reference_id, array &$context) {
  // Process the current file.
  _auditfiles_referenced_not_used_batch_add_process_file($reference_id);
  // The contents of 'results' are available as $results in the 'finished'
  // function.
  $context['results'][] = $reference_id;
  // Set a progress message.
  $context['message'] = t('Processed reference ID %file_id.', array('%file_id' => $reference_id));
}

/**
 * Adds the specified file to the file_usage table.
 *
 * @param string $reference_id
 *   The ID for keeping track of the reference.
 */
function _auditfiles_referenced_not_used_batch_add_process_file($reference_id) {
  $reference_id_parts = explode('.', $reference_id);
  $data = array(
    'fid' => $reference_id_parts[4],

    // @todo
    // This is hard coded for now, but need to determine how to figure out which
    // module needs to be here.
    'module' => 'file',
    'type' => $reference_id_parts[3],
    'id' => $reference_id_parts[2],
    'count' => 1,
  );
  $results = db_insert('file_usage')
    ->fields($data)
    ->execute();
  if (empty($results)) {
    drupal_set_message(
      t(
        'There was a problem adding the record with file ID %fid to the file_usage table. Check the logs for more information.',
        array('%fid' => $reference_id_parts[4])
      ),
      'warning'
    );
  }
  else {
    // Remove the files from the list of files to display.
    $rows = variable_get('auditfiles_referenced_not_used_files_to_display', array());
    unset($rows[$reference_id]);
    variable_set('auditfiles_referenced_not_used_files_to_display', $rows);
  }
}

/**
 * Creates the batch for deleting file references from their content.
 *
 * @param array $referenceids
 *   The list of IDs to be processed.
 *
 * @return array
 *   The definition of the batch.
 */
function _auditfiles_referenced_not_used_batch_delete_create_batch(array $referenceids) {
  $batch = _auditfiles_referenced_not_used_batch_set_common_values();
  $batch['title'] = t('Deleting file references from their content');
  $operations = array();
  // Remove all the empty values from the array.
  $reference_ids = array();
  foreach ($referenceids as $reference_id) {
    if ($reference_id != '') {
      $reference_ids[] = $reference_id;
    }
  }
  // Fill in the $operations variable.
  foreach ($reference_ids as $reference_id) {
    $operations[] = array(
      '_auditfiles_referenced_not_used_batch_delete_process_batch',
      array($reference_id),
    );
  }
  $batch['operations'] = $operations;
  return $batch;
}

/**
 * The batch process for deleting the file.
 *
 * @param string $reference_id
 *   The ID for keeping track of the reference.
 * @param array $context
 *   Used by the Batch API to keep track of and pass data from one operation to
 *   the next.
 */
function _auditfiles_referenced_not_used_batch_delete_process_batch($reference_id, array &$context) {
  // Process the current file.
  _auditfiles_referenced_not_used_batch_delete_process_file($reference_id);
  // The contents of 'results' are available as $results in the 'finished'
  // function.
  $context['results'][] = $reference_id;
  // Set a progress message.
  $context['message'] = t('Processed reference ID %file_id.', array('%file_id' => $reference_id));
}

/**
 * Deletes the specified file from the database.
 *
 * @param string $reference_id
 *   The ID for keeping track of the reference.
 */
function _auditfiles_referenced_not_used_batch_delete_process_file($reference_id) {
  $reference_id_parts = explode('.', $reference_id);
  $num_rows = db_delete($reference_id_parts[0])
    ->condition($reference_id_parts[1], $reference_id_parts[4])
    ->execute();
  if (empty($num_rows)) {
    drupal_set_message(
      t(
        'There was a problem deleting the reference to file ID %fid in the %entity_type with ID %eid. Check the logs for more information.',
        array(
          '%fid' => $reference_id_parts[4],
          '%entity_type' => $reference_id_parts[3],
          '%eid' => $reference_id_parts[2],
        )
      ),
      'warning'
    );
  }
  else {
    // Remove the deleted files from the list of files to display.
    $rows = variable_get('auditfiles_referenced_not_used_files_to_display', array());
    unset($rows[$reference_id]);
    variable_set('auditfiles_referenced_not_used_files_to_display', $rows);
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
function _auditfiles_referenced_not_used_get_file_list() {
  $file_references = array();
  $files_referenced = array();
  // If record limition has been configured, only use those records within that
  // specification.
  $record_limiters = _auditfiles_referenced_not_used_get_record_limiters();
  $maximum_records = $record_limiters['maximum_records'];

  // Get a list of all files that are referenced in content.
  $fields = field_info_fields();
  foreach ($fields as $field) {

    // @todo
    // Add an setting to allow the administrator the ability for spcifying the
    // field types.
    if (!empty($field['type']) && ($field['type'] == 'file' || $field['type'] == 'image')) {
      // Get the database table name for the field.
      $table = key($field['storage']['details']['sql']['FIELD_LOAD_CURRENT']);
      // Get the column name in the database table for the field.
      $column = $field['storage']['details']['sql']['FIELD_LOAD_CURRENT'][$table]['fid'];

      // Get the records from the specified field table.
      $query = "SELECT entity_id, entity_type, $column FROM {$table}";
      $query .= " WHERE ${column} NOT IN (SELECT DISTINCT(fid) FROM {file_usage})";
      if ($maximum_records > 0) {
        $query .= " LIMIT $maximum_records";
        // Set the offest.
        $query .= " OFFSET " . variable_get('auditfiles_referenced_not_used_batch_offset', 0);
      }
      else {
        variable_set('auditfiles_referenced_not_used_batch_offset', 0);
      }
      $file_references = db_query($query)->fetchAll();

      // Construct an array of records to use as the ultimate data store.
      foreach ($file_references as $file_reference) {
        $reference_id = $table . '.' . $column . '.' . $file_reference->entity_id . '.' . $file_reference->entity_type . '.' . $file_reference->{$column};
        $files_referenced[$reference_id] = array(
          'table' => $table,
          'column' => $column,
          'entity_id' => $file_reference->entity_id,
          'file_id' => $file_reference->{$column},
        );
      }
    }
  }

  return $files_referenced;
}

/**
 * Retrieves information about an individual file from the database.
 *
 * @param string $reference_id
 *   The ID for keeping track of the reference.
 * @param array $row_data
 *   The data to use for creating the row.
 *
 * @return array
 *   The row for the table on the report, with the file's information formatted
 *   for display.
 */
function _auditfiles_referenced_not_used_get_file_data($reference_id, array $row_data) {
  $row = array();
  // Get the data for this record.
  $query = "SELECT * FROM {" . $row_data['table'] . "} WHERE " . $row_data['column'] . " = " . $row_data['file_id'];
  $result = db_query($query)->fetchAll();
  $result = reset($result);

  if ($result->entity_type == 'node') {
    $entity_id_display = l('node/' . $result->entity_id, 'node/' . $result->entity_id);
  }
  else {
    $entity_id_display = $result->entity_id;
  }

  // Add the initial data to the row.
  $row = array(
    'file_id' => $result->{$row_data['column']},
    'entity_type' => $result->entity_type,
    'bundle' => array('data' => $result->bundle, 'hidden' => TRUE),
    'entity_id' => array('data' => $result->entity_id, 'hidden' => TRUE),
    'entity_id_display' => $entity_id_display,
    'field' => $row_data['table'] . '.' . $row_data['column'],
    'table' => array('data' => $row_data['table'], 'hidden' => TRUE),
    'uri' => 'No file object exists for this reference.',
    'filename' => array('data' => '', 'hidden' => TRUE),
    'filemime' => '--',
    'filesize' => '--',
  );

  // If there is a file in the file_managed table, add some of that
  // information to the row, too.
  $file_managed = file_load($result->{$row_data['column']});
  if (!empty($file_managed)) {
    $row['uri'] = $file_managed->uri;
    $row['filename'] = array('data' => $file_managed->filename, 'hidden' => TRUE);
    $row['filemime'] = $file_managed->filemime;
    $row['filesize'] = $file_managed->filesize;
  }

  return $row;
}


/****************************************************************************
 *
 * The following code is from the old method of looking for files in content.
 * It includes searching body fields for files referenced in HTML.
 *
 ****************************************************************************/


  // Start at 1; $files checkboxes shouldn't have a 0 key
//  $match_id = 1;
//  $files = array();
//  $single_match = 0;
//  $multi_match = 0;
//  $no_match = 0;
//  $external_domains = array();
//
//  $patterns = array(
//    // Get src attributes from img tags (assumes ")
//    '(?:<img [^>]*src[ ]*=[ ]*"([^"]*)")',
//    // Get href attributes from a tags (assumes ")
//    '(?:<a [^>]*href[ ]*=[ ]*"([^"]*)")',
//    // Get window.open argument (assumes ')
//    "(?:window.open[ ]*\([ ]*'([^\']*)')",
//  );
//  $reg_pattern = '/' . implode('|', $patterns) . '/';
//
//  // Stuff not likely to represent local file references.
//  $ignore_patterns = array(
//    'window\.open',
//    '^mailto:',
//    '\.html?($|\?)',
//    '^#',
//    '^javascript:void\(0\)',
//    '^ftp:\/\/',
//  );
//  // Add references to our own home page(s)
//  $domains = variable_get('auditfiles_include_domains', '');
//  if (!empty($domains)) {
//    $domains = explode(';', $domains);
//    foreach ($domains as $domain) {
//      $ignore_patterns[] = "^https?:\/\/$domain\/?$";
//    }
//  }
//  $ignore_pattern = '/' . implode('|', $ignore_patterns) . '/';
//
//  // Get a list of nodes that might have a file reference in them.
//  // @TODO Please convert this statement to the D7 database API syntax.
//  $result = db_query(
//    "SELECT n.nid, n.title, b.body_value
//    FROM {node} n
//    INNER JOIN {node_revision} nr ON n.vid = nr.vid
//    INNER JOIN {field_data_body} b ON b.revision_id = nr.vid
//    WHERE b.body_value LIKE '%img%'
//       OR b.body_value LIKE '%window.open%'
//       OR b.body_value LIKE '%href%'
//    ORDER BY n.nid DESC
//    LIMIT 100"
//  );
//  // Process each node found with a potential file reference.
//  foreach ($result as $node) {
//    $node_link = l($node->title, 'node/' . $node->nid);
//
//    // Pull all the matches together.
//    preg_match_all($reg_pattern, $node->body_value, $file_match_groups);
//    $file_matches = array();
//    for ($i = 1; $i < count($patterns) + 1; $i++) {
//      $file_matches = array_merge($file_matches, $file_match_groups[$i]);
//    }
//
//    // Process each potential file reference.
//    for ($i = 0; $i < count($file_matches); $i++) {
//      $source = trim($file_matches[$i]);
//      // Don't process any empty strings created as a result of the previous
//      // merging.
//      if (!$source) {
//        continue;
//      }
//      // Don't process any strings that are likely external to this system.
//      if (preg_match($ignore_pattern, $source)) {
//        continue;
//      }
//
//      // If we've got a full URL, and the domain is not in our list of "local"
//      // domains, assume it's a valid external URL and leave it be.
//      // Search the source for a URI indicator.
//      $domain_found = preg_match('@^https?://([^/$]+)@', $source, $matches);
//      $local = FALSE;
//      if (!$domain_found) {
//        // The file reference is local to this system.
//        $local = TRUE;
//      }
//      else {
//        // If local domains have been specified, search them to see if the
//        // current string is one of them.
//        if (!empty($domains)) {
//          $source_domain = $matches[1];
//          foreach ($domains as $domain) {
//            if ($domain == $source_domain) {
//              $local = TRUE;
//              break;
//            }
//          }
//        }
//      }
//      // If the domain is not local, add it to a list of external domains and
//      // stop processing the file reference.
//      if (!$local) {
//        $external_domains[$matches[0]]++;
//        continue;
//      }
//
//      // Fix up encoded spaces.
//      $decode_source = str_replace('%20', ' ', $source);
//
//      $file_dir_path = drupal_realpath('public://');
//
//      // If there is an exact match on path and an exact match on that path in
//      // the {file_usage} table, we don't have to go farther.
//
//      // Search the file tables for the file reference to see if it is there.
//      // We need to compare {file_managed}.uri with $decode_source, which are in
//      // different formats. {file_managed}.uri is like "scheme://path/to/file.nam" and $decode_source may be like "http://domainname.com/
//      $query = "SELECT fu.id
//        FROM {file_usage} fu
//        INNER JOIN {file_managed} fm ON fm.fid = fu.fid
//        WHERE fu.id = :fu_nid
//        AND fm.uri = :fm_uri";
//      $hit = db_query(
//        $query,
//        array(
//          ':fu_nid' => $node->nid,
//          ':fm_uri' => $decode_source,
//        )
//      )->fetchField();
//
//      // The file reference is not exactly matched in the file tables, so
//      // include it in the list for the user to see.
//      if (!$hit) {
//        $num_matches = 0;
//        $decode_base = basename($decode_source);
//        $query = "SELECT fm.fid, fm.filename, fu.id
//          FROM {file_managed} fm
//          LEFT JOIN {file_usage} fu ON fm.fid = fu.fid
//          WHERE fu.id = :fu_id
//          AND fm.filename = :fm_filename";
//        $file_result = db_query(
//          $query,
//          array(
//            ':fu_id' => $node->nid,
//            ':fm_filename' => $decode_base,
//          )
//        );
//
//        while ($file = $file_result->fetch()) {
//          $num_matches++;
//          // Visible fields first
//          $form['titles'][$match_id] = array('#value' => $node_link);
//          $form['sources'][$match_id] = array('#value' => $source);
//          $form['fids'][$match_id] = array('#value' => $file->fid);
//
//          // Strip the Drupal file path, and make the link
//          $filepath = preg_replace('@^' . preg_quote($file_dir_path) . '/@', '', $file->filepath);
//          $filelink = l($filepath, $GLOBALS['base_url'] . '/' . $file_dir_path . '/' . str_replace('\\', '/', $filepath));
//          $form['paths'][$match_id] = array('#value' => $filelink);
//          $files[$match_id] = '';
//
//          // Fields passed through form submission
//          $form['nid_values'][$match_id] = array(
//            '#type' => 'value',
//            '#value' => $node->nid,
//          );
//          $form['source_values'][$match_id] = array(
//            '#type' => 'value',
//            '#value' => $source,
//          );
//          $form['fid_values'][$match_id] = array(
//            '#type' => 'value',
//            '#value' => $file->fid,
//          );
//          $form['path_values'][$match_id] = array(
//            '#type' => 'value',
//            '#value' => $file->filepath,
//          );
//
//          if (!$file->nid) {
//            $form['no_upload'][$match_id] = array(
//              '#type' => 'value',
//              '#value' => TRUE,
//            );
//          }
//
//          $match_id++;
//        }
//
//        if ($num_matches == 0) {
//          $no_match++;
//
//          $form['titles'][$match_id] = array('#value' => $node_link);
//          $form['sources'][$match_id] = array('#value' => $source);
//          $form['fids'][$match_id] = array('#value' => '');
//          $form['paths'][$match_id] = array('#value' => '');
//
//          $files[$match_id] = '';
//
//          $form['nid_values'][$match_id] = array(
//            '#type' => 'value',
//            '#value' => $node->nid,
//          );
//          $form['source_values'][$match_id] = array(
//            '#type' => 'value',
//            '#value' => $source,
//          );
//          $form['no_upload'][$match_id] = array(
//            '#type' => 'value',
//            '#value' => TRUE,
//          );
//
//          $match_id++;
//        }
//        elseif ($num_matches == 1) {
//          $single_match++;
//
//          $form['unique'][$match_id - 1] = array(
//            '#type' => 'value',
//            '#value' => TRUE,
//          );
//        }
//        else {
//          $multi_match++;
//        }
//      }
//    }
//  }
//
//  if (count($external_domains) > 0) {
//    $form['external_domains'] = array(
//      '#type' => 'fieldset',
//      '#title' => 'External domains referenced',
//      '#collapsible' => TRUE,
//      '#collapsed' => TRUE,
//    );
//
//    arsort($external_domains);
//
//    foreach ($external_domains as $domain => $count) {
//      $form['domains'][$domain] = array('#value' => $domain);
//      $form['domain_counts'][$domain] = array('#value' => $count);
//    }
//  }
//
//  // Remember, we started at 1 instead of 0...
//  if ($match_id > 1) {
//    $broken = $no_match + $single_match + $multi_match;
//    $total = format_plural($broken, '1 broken reference found:', '@count broken references found:');
//    $unmatched = "$no_match with no matches";
//    $unique_match = "$single_match with a unique match";
//    $multi_matches = "$multi_match with multiple matches";
//    $form['count'] = array(
//      '#value' => "<div>$total<br />$unmatched<br />$unique_match<br />$multi_matches</div>",
//    );
//  }

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
function _auditfiles_referenced_not_used_get_record_limiters() {
  $record_selection = variable_get('auditfiles_referenced_not_used_record_selection', 'normal');
  $maximum_records = 0;
  if ($record_selection == 'batch_sets') {
    $maximum_records = variable_get('auditfiles_report_options_batch_size', 0);
  }
  elseif ($record_selection != 'batched') {
    $maximum_records = variable_get('auditfiles_report_options_maximum_records', 0);
    if ($maximum_records > 0) {
      $record_selection = 'limited';
      variable_set('auditfiles_referenced_not_used_record_selection', 'limited');
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
function _auditfiles_referenced_not_used_get_header() {
  return array(
    'file_id' => array(
      'data' => t('File ID'),
    ),
    'entity_type' => array(
      'data' => t('Referencing entity type'),
    ),
    'entity_id_display' => array(
      'data' => t('Referencing entity ID'),
    ),
    'field' => array(
      'data' => t('Field referenced in'),
    ),
    'uri' => array(
      'data' => t('URI'),
    ),
    'filemime' => array(
      'data' => t('MIME'),
    ),
    'filesize' => array(
      'data' => t('Size (in bytes)'),
    ),
  );
}
