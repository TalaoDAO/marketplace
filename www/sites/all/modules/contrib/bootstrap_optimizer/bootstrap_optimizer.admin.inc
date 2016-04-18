<?php

/**
 * @file
 * Administrative form for BOOTSTRAP OPTIMIZER module.
 */

/**
 * Provides administrative form.
 */
function bootstrap_optimizer_admin_form($form, &$form_state) {

  $form['page_load'] = array(
    '#type' => 'fieldset',
    '#title' => t('Page load time'),
  );

  // Get current page load time.
  $timer = timer_read('page') / 1000;
  $form['page_load']['page_load_time'] = array(
    '#markup' => t('@time seconds.', array('@time' => number_format($timer, 2))),
  );

  $form['actions'] = array(
    '#type' => 'action',
  );

  $form['actions']['analyze'] = array(
    '#type' => 'submit',
    '#value' => t('Analyze files'),
  );

  $form['actions']['remove'] = array(
    '#type' => 'submit',
    '#value' => t('Remove missing files'),
  );

  return $form;
}

/**
 * Submit callback for bootstrap optimizer administrative form.
 */
function bootstrap_optimizer_admin_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  // Load all files from {system} table.
  $result = db_select('system', 's')
    ->fields('s', array('filename'))
    ->condition('s.status', 1)
    ->execute();
  $files = array();
  foreach ($result as $item) {
    $files[] = $item->filename;
  }

  // Check if user wants only to analyze system table.
  if ($values['op'] == $form['actions']['analyze']['#value']) {
    bootstrap_optimizer_set_batch($files, 'bootstrap_optimizer_analyze_broken_files');
  }
  elseif ($values['op'] == $form['actions']['remove']['#value']) {
    bootstrap_optimizer_set_batch($files, 'bootstrap_optimizer_remove_broken_files');
  }
}
