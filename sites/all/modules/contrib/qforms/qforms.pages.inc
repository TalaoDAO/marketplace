<?php

/**
 * @file
 * Various menu callbacks for the qforms module.
 */

/**
 * Page for showing submission results for given node.
 */
function qforms_results_submissions($node) {
  $entity_id = $node->nid;
  $output = '';

  // Create select statement for qforms submissions.
  $select = db_select('qforms_submission', 's')->extend('PagerDefault');

  // Show submissions just for this entity id.
  $select->condition('s.nid', $entity_id);

  // Join the users table, so we can get the entry creator's username.
  $select->join('users', 'u', 's.uid = u.uid');

  // Select these specific fields for the output.
  $select->addField('s', 'sid');
  $select->addField('s', 'time');
  $select->addField('u', 'name');
  $select->addField('u', 'uid');

  $rows = $select->execute()->fetchAll(PDO::FETCH_ASSOC);
  if (!empty($rows)) {

    // Number of results selector and all results count.
    $count = $select->getCountQuery()->execute()->fetchField();
    $output .= '<div class="qforms-results-per-page">' . t('!20 | !all results per page. !count results total.',
      array(
        '!20' => l('20', 'node/' . $entity_id . '/qforms-results', array('query' => array('results' => 20))),
        '!all' => l(t('All'), 'node/' . $entity_id . '/qforms-results', array('query' => array('results' => 0))),
        '!count' => $count,
      )) . '</div>';

    $output .= l(t('Export results to csv file'), 'node/' . $entity_id . '/qforms-results/export');

    // How many results to show per page.
    if (!isset($_GET['results']) || $_GET['results'] !== '0') {
      $select->limit(20);
    }

    foreach ($rows as &$row) {
      $row['time'] = format_date($row['time']);

      $account = new stdClass();
      $account->uid = $row['uid'];
      $account->name = $row['name'];
      $row['name'] = theme('username', array('account' => $account, 'name' => check_plain($row['name'])));
      unset($row['uid']);

      $row['actions'] = l(t('View'), 'node/' . $entity_id . '/qforms-result/' . $row['sid']) . ' | ' .
        l(t('Delete'), 'node/' . $entity_id . '/qforms-result/' . $row['sid'] . '/delete');
    }

    // Make a table for them.
    $header = array(t('Id'), t('Time'), t('Submited by'), t('Actions'));
    $output .= theme('table', array('header' => $header, 'rows' => $rows));

    $output .= theme('pager', array('quantity' => 1));
  }
  else {
    $output .= 'No submission results.';
  }

  return $output;
}

/**
 * Single submission result view page.
 */
function qforms_submission_page($node, $sid) {
  global $base_path;

  // Set usable breadcrumb.
  drupal_set_breadcrumb(array(
    l(t('Home'), '<front>'),
    l($node->title, 'node/' . $node->nid),
    l(t('Submission results'), 'node/' . $node->nid . '/qforms-results'),
  ));

  drupal_set_title(t('Submission result'));

  return drupal_get_form('qforms_submit_view_form', $node->nid, $sid);
}

/**
 * Page callback for submission deletion.
 */
function qforms_submission_confirm_delete_page($entity_id, $sid) {
  if ($submission = qforms_db_load_submission($sid)) {
    return drupal_get_form('qforms_submission_confirm_delete', $submission);
  }
  return MENU_NOT_FOUND;
}

/**
 * Builds the confirmation form for deleting a single submission.
 */
function qforms_submission_confirm_delete($form, &$form_state, $submission) {
  $form['#submission'] = $submission;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['sid'] = array(
    '#type' => 'value',
    '#value' => $submission->sid,
  );
  return confirm_form(
    $form,
    t('Are you sure you want to delete the submission %sid?', array('%sid' => $submission->sid)),
    'node/' . $submission->nid . '/qforms-result/' . $submission->sid,
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel'),
    'submission_confirm_delete'
  );
}

/**
 * Process qforms_submission_confirm_delete form submissions.
 */
function qforms_submission_confirm_delete_submit($form, &$form_state) {
  $submission = $form['#submission'];
  qforms_db_delete_submission($submission->sid);

  drupal_set_message(t('Submission has been deleted.'));
  watchdog('qforms', 'Deleted submission !sid.', array('!sid' => $submission->sid));

  $form_state['redirect'] = 'node/' . $submission->nid . '/qforms-results';
}
