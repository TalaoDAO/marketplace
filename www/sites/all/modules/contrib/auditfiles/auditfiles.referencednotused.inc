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
function auditfiles_referenced_not_used_form(array $form, array &$form_state) {
  // Check to see if the confirmation form needs to be displayed instead of the
  // normal form.
  if (isset($form_state['storage']['confirm'])) {
    return _auditfiles_referenced_not_used_confirm_operation($form, $form_state);
  }

  // Get the records to display.
  // Check to see if there is saved data, and if so, use that.
  $rows = variable_get('auditfiles_referenced_not_used_files_to_display', array());
  if (empty($rows)) {
    // The data is not saved and the batch operation has not been run, so get
    // the data using the default options.
    $file_data = _auditfiles_referenced_not_used_get_file_list();
    if (!empty($file_data)) {
      foreach ($file_data as $reference_id => $row_data) {
        $rows[$reference_id] = _auditfiles_referenced_not_used_get_file_data($row_data);
      }
    }

    // Save the data for persistant use.
    variable_set('auditfiles_referenced_not_used_files_to_display', $rows);
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
    '#header' => _auditfiles_referenced_not_used_get_header(),
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
      '#value' => t('Add selected items to the file_usage table'),
    );
    $form['actions']['markup'] = array(
      '#markup' => '&nbsp;' . t('or') . '&nbsp;',
    );
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete selected references'),
    );

    // Add the pager.
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
    if ($form_state['values']['op'] == t('Load all files')) {
      // Clear the variable, so subsequent pages will load the correct data.
      variable_del('auditfiles_referenced_not_used_files_to_display');
      // Prepare and set the batch.
      batch_set(_auditfiles_referenced_not_used_batch_display_create_batch());
    }
    elseif ($form_state['values']['op'] == t('Reset file list')) {
      // Reset all the variables for this report, so subsequent pages loads will
      // load and use the correct data.
      db_delete('variable')
        ->condition('name', 'auditfiles_referenced_not_used%', 'LIKE')
        ->execute();
      cache_clear_all('variables', 'cache_bootstrap');
    }
    elseif (($form_state['values']['op'] == t('Add selected items to the file_usage table')
      || $form_state['values']['op'] == t('Delete selected references'))
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
        batch_set(_auditfiles_referenced_not_used_batch_add_create_batch($form_state['values']['changelist']));
      }
      elseif ($form_state['values']['operation'] == 'delete') {
        // Prepare and set the batch.
        batch_set(_auditfiles_referenced_not_used_batch_delete_create_batch($form_state['values']['changelist']));
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
      variable_set('auditfiles_referenced_not_used_files_to_display', $results['files_to_display']);
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
  // Get and save the field data, so this is only done once for the entire batch
  // process.
  $file_fields = array();
  // Get a list of all fields on the site.
  $fields = field_info_fields();
  foreach ($fields as $field_name => $field) {
    // @todo
    // Consider adding a setting to allow the administrator the ability for
    // spcifying the field types.
    if (!empty($field['type']) && ($field['type'] == 'file' || $field['type'] == 'image')) {
      // Get the database table name for the field.
      $table = key($field['storage']['details']['sql']['FIELD_LOAD_CURRENT']);
      $field['table'] = $table;
      // Get the column name in the database table for the field.
      $column = $field['storage']['details']['sql']['FIELD_LOAD_CURRENT'][$table]['fid'];
      $field['column'] = $column;
      // Save the data for use in the operation.
      $file_fields[$field_name] = $field;
    }
  }

  $operations = array();
  $operations[] = array(
    '_auditfiles_referenced_not_used_batch_display_get_files',
    array($file_fields),
  );
  $operations[] = array(
    '_auditfiles_referenced_not_used_batch_display_process_files',
    array(),
  );

  return $operations;
}

/**
 * Retrieves the file IDs to operate on.
 *
 * @param array $file_fields
 *   The list of file fields to search for files in.
 * @param array $context
 *   Used by the Batch API to keep track of and pass data from one operation to
 *   the next.
 */
function _auditfiles_referenced_not_used_batch_display_get_files(array $file_fields, array &$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox'] = array();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_id'] = 0;

    // Set the number of records to operate on for this batch process.
    $context['sandbox']['max'] = 1;
    $batch_size = variable_get('auditfiles_report_options_batch_size', 1000);
    if ($batch_size > 0) {
      $context['sandbox']['max'] = $batch_size;
    }

    // Set up the field data to use to query the database with.
    $context['sandbox']['file_fields'] = array();
    $context['sandbox']['table'] = '';
    $context['sandbox']['column'] = '';
    if (!empty($file_fields)) {
      $context['sandbox']['file_fields'] = $file_fields;
      $file_field = array_shift($context['sandbox']['file_fields']);
      // Get the database table name for the field.
      $context['sandbox']['table'] = key($file_field['storage']['details']['sql']['FIELD_LOAD_CURRENT']);
      // Get the column name in the database table for the field.
      $context['sandbox']['column'] = $file_field['storage']['details']['sql']['FIELD_LOAD_CURRENT'][$context['sandbox']['table']]['fid'];
    }
  }
  if (!isset($context['results']['file_list'])) {
    $context['results']['file_list'] = array();
  }

  // Get the next set of records.
  // This cannot be sorted any other way here, or the results are not complete.
  $query = 'SELECT entity_id, entity_type, ' . $context['sandbox']['column'] . '
    FROM {' . $context['sandbox']['table'] . '}
    WHERE entity_id > ' . $context['sandbox']['current_id'] . '
      AND ' . $context['sandbox']['column'] . ' NOT IN (SELECT DISTINCT fid FROM {file_usage})
    ORDER BY entity_id ASC
    LIMIT 20';
  $results = db_query($query)->fetchAll();

  // Check the data to see what needs to be done next.
  if (empty($results)) {
    // There are no more records for the current field, so get the next field.
    if (empty($context['sandbox']['file_fields'])) {
      // There are no more fields to process, so set the exit condition.
      $context['sandbox']['progress'] = $context['sandbox']['max'];
    }
    else {
      $file_field = array_shift($context['sandbox']['file_fields']);
      // Get the database table name for the field.
      $context['sandbox']['table'] = key($file_field['storage']['details']['sql']['FIELD_LOAD_CURRENT']);
      // Get the column name in the database table for the field.
      $context['sandbox']['column'] = $file_field['storage']['details']['sql']['FIELD_LOAD_CURRENT'][$context['sandbox']['table']]['fid'];
    }
  }
  else {
    // Save the data in the data store.
    foreach ($results as $result) {
      $reference_id = $context['sandbox']['table'] . '.' . $context['sandbox']['column'] . '.' . $result->entity_id . '.' . $result->entity_type . '.' . $result->{$context['sandbox']['column']};
      $context['results']['file_list'][$reference_id] = array(
        'table' => $context['sandbox']['table'],
        'column' => $context['sandbox']['column'],
        'entity_id' => $result->entity_id,
        'file_id' => $result->{$context['sandbox']['column']},
      );

      if ($context['sandbox']['max'] > 1
        && count($context['results']['file_list']) >= $context['sandbox']['max']) {
        // The maximum number of records has been reached, so set the exit
        // condition.
        $context['sandbox']['progress'] = $context['sandbox']['max'];
        break;
      }
    }

    // Update the progress information.
    $context['sandbox']['current_id'] = $result->entity_id;
    $context['message'] = t(
      'Getting the list of files. Last ID processed: !entity_id.',
      array(
        '!entity_id' => $result->entity_id,
      )
    );
  }

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = ($context['sandbox']['progress'] >= $context['sandbox']['max']);
  }
}

/**
 * Retrieves information about an individual file from the database.
 *
 * @param array $context
 *   Used by the Batch API to keep track of and pass data from one operation to
 *   the next.
 */
function _auditfiles_referenced_not_used_batch_display_process_files(array &$context) {
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
    foreach ($file_list as $reference_id => $file) {
      // Get the data for this record.
      $query = 'SELECT * FROM {' . $file['table'] . '} WHERE ' . $file['column'] . ' = ' . $file['file_id'];
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
        'file_id' => $result->{$file['column']},
        'entity_type' => $result->entity_type,
        'bundle' => array('data' => $result->bundle, 'hidden' => TRUE),
        'entity_id' => array('data' => $result->entity_id, 'hidden' => TRUE),
        'entity_id_display' => $entity_id_display,
        'field' => $file['table'] . '.' . $file['column'],
        'table' => array('data' => $file['table'], 'hidden' => TRUE),
        'uri' => 'No file object exists for this reference.',
        'filename' => array('data' => '', 'hidden' => TRUE),
        'filemime' => '--',
        'filesize' => '--',
      );

      // If there is a file in the file_managed table, add some of that
      // information to the row, too.
      $file_managed = file_load($result->{$file['column']});
      if (!empty($file_managed)) {
        $row['uri'] = $file_managed->uri;
        $row['filename'] = array('data' => $file_managed->filename, 'hidden' => TRUE);
        $row['filemime'] = $file_managed->filemime;
        $row['filesize'] = $file_managed->filesize;
      }

      $context['results']['files_to_display'][$reference_id] = $row;

      // Update the progress information.
      $context['sandbox']['progress']++;
      $context['message'] = t(
        'Processing the file list. Processed file @num1 of @num2. Last file ID processed: !file_id.',
        array(
          '@num1' => $context['sandbox']['progress'],
          '@num2' => $context['sandbox']['max'],
          '!file_id' => $file['file_id'],
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
        if ($values['op'] == t('Add selected items to the file_usage table')) {
          $message = t('will be added to the file_usage table.');
        }
        elseif ($values['op'] == t('Delete selected references')) {
          $message = t('will be deleted from the content.');
        }
        $form['changelist'][$reference_id] = array(
          '#type' => 'hidden',
          '#value' => $reference_id,
          '#prefix' => '<li>' . t('File ID') . ' <strong>' . $reference_id_parts[4] . '</strong> ' . $message,
          '#suffix' => "</li>\n",
        );
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
  if ($values['op'] == t('Add selected items to the file_usage table')) {
    $form['operation']['#value'] = 'add';
    $confirm_question = t('Add these files to the file_usage table?');
    $confirm_description = '';
  }
  elseif ($values['op'] == t('Delete selected references')) {
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
    // @todo This is hard coded for now, but need to determine how to figure out
    // which module needs to be here.
    'module' => 'file',
    'type' => $reference_id_parts[3],
    'id' => $reference_id_parts[2],
    'count' => 1,
  );

  // Make sure the file is not already in the database.
  $query = 'SELECT fid FROM file_usage
    WHERE fid = :fid AND module = :module AND type = :type AND id = :id';
  $existing_file = db_query(
    $query,
    array(
      ':fid' => $data['fid'],
      ':module' => $data['module'],
      ':type' => $data['type'],
      ':id' => $data['id'],
    )
  )->fetchAll();
  if (empty($existing_file)) {
    // The file is not already in the database, so add it.
    db_insert('file_usage')
      ->fields($data)
      ->execute();

    // Remove the files from the list of files to display.
    $rows = variable_get('auditfiles_referenced_not_used_files_to_display', array());
    unset($rows[$reference_id]);
    variable_set('auditfiles_referenced_not_used_files_to_display', $rows);
  }
  else {
    drupal_set_message(
      t(
        'The file is already in the file_usage table (file id: "@fid", module: "@module", type: "@type", entity id: "@id").',
        array(
          '@fid' => $data['fid'],
          '@module' => $data['module'],
          '@type' => $data['type'],
          '@id' => $data['id'],
        )
      ),
      'error'
    );
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
      $query = 'SELECT entity_id, entity_type, ' . $column . ' FROM {' . $table . '}';
      $query .= ' WHERE ' . $column . ' NOT IN (SELECT DISTINCT fid FROM {file_usage})';

      // If record limition has been configured, only use those records within
      // that specification.
      $maximum_records = variable_get('auditfiles_report_options_maximum_records', 250);
      if ($maximum_records > 0) {
        $query .= ' LIMIT ' . $maximum_records;
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
 * @param array $row_data
 *   The data to use for creating the row.
 *
 * @return array
 *   The row for the table on the report, with the file's information formatted
 *   for display.
 */
function _auditfiles_referenced_not_used_get_file_data(array $row_data) {
  // Get the data for this record.
  $query = 'SELECT * FROM {' . $row_data['table'] . '} WHERE ' . $row_data['column'] . ' = ' . $row_data['file_id'];
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


//  // Start at 1; $files checkboxes shouldn't have a 0 key
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
