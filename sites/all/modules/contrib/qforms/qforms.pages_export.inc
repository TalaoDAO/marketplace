<?php

/**
 * @file
 * Export menu callbacks for the qforms module.
 */

/**
 * Page for exporting submission results for given node.
 */
function qforms_results_submissions_export($node) {
  $exported_results = qforms_results_submissions_export_base($node);
  if ($exported_results === '') {
    return '';
  }
  else {
    header('Content-Type: "application/octet-stream; charset=utf-8"');
    header('Content-Disposition: attachment; filename="' . $exported_results['file_name'] . '"');
    print $exported_results['file_content'];
    exit();
  }
}

/**
 * Callback for submissions results export to csv file.
 *
 * This function is also used for testing.
 *
 * @param $node
 * @return
 *   array that contain file name and file content
 */
function qforms_results_submissions_export_base($node) {
  $entity_id = $node->nid;

  // Create select statement for qforms submissions.
  $select = db_select('qforms_submission', 's');

  // Show submissions just for this entity id.
  $select->condition('s.nid', $entity_id);

  // Join the users table, so we can get the entry creator's username.
  $select->join('users', 'u', 's.uid = u.uid');
  $select->join('node', 'n', 'n.nid = s.nid');

  // Select these specific fields for the output.
  $select->addField('s', 'sid');
  $select->addField('s', 'time');
  $select->addField('s', 'data');
  $select->addField('u', 'name', 'username');
  $select->addField('n', 'title', 'node_title');

  $rows = $select->execute()->fetchAll(PDO::FETCH_ASSOC);

  if (!empty($rows)) {
    $first_row = current($rows);
    $file_name = t('@title - Submission results.csv', array('@title' => $first_row['node_title']));

    $csv_array = array();
    $csv_array[0] = array(t('Id'), t('Time'), t('Submited by'));

    // Get form definition.
    $qform = qforms_db_load_form($node->nid);
    $form_definition = $qform['form_definition'];

    foreach ($form_definition as $element) {
      // @TODO - this part should be plugable if form elements wants to do anything special for csv export.
      // This old peace of code will stay here until we create qforms_grid module.
//      if ($form_structure['type'] == 'grid') {
//        $fsv = $form_structure['values'];
//        reset($fsv);
//        while (next($fsv) != FALSE) {
//          $grid_item = current($fsv);
//          $grid_item_title = current($grid_item);
//          $csv_array[0][] = check_plain($form_structure['title']) . ' - ' . current($grid_item_title);
//        }
//      }
//      else {
      if (is_array($element) && $element['visible'] && isset($element['title'])) {
          $csv_array[0][] = check_plain($element['title']);
        }
//      }
    }

    foreach ($rows as &$row) {
      $csv_row_data = array($row['sid'], format_date($row['time']), check_plain($row['username']));

      // Get user submission data.
      $elements_data = unserialize($row['data']);

      foreach ($form_definition as $element_id => $element) {
        if (is_array($element)) {
          if (isset($form_definition[$element_id]) && $qcall = qforms_get_callback('prepare_for_csv_export', $form_definition[$element_id]['type'])) {
            call_user_func_array($qcall, array(&$elements_data, $element_id));
          }
          if (isset($elements_data[$element_id]) && $element['visible']) {
            $csv_row_data[] = $elements_data[$element_id];
          }
        }
      }
      $csv_array[] = $csv_row_data;
    }

    // CSV generation.
    $fp = fopen('php://temp', 'r+');
    foreach ($csv_array as $fields) {
      fputcsv($fp, $fields);
    }

    rewind($fp);
    $csv_output = '';
    while ($line = fgets($fp)) {
      $csv_output .= $line;
    }

    fclose($fp);

    return array('file_name' => $file_name, 'file_content' => $csv_output);
  }
  else {
    drupal_set_message(t('No submission results.'));
    return '';
  }

}
