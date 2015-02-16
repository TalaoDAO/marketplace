<?php

/**
 * @file
 *
 */

/**
 * Processes every batch item.
 *
 * @param $items
 * @param $function
 * @param $context
 */
function bootstrap_optimizer_batch_process_item($items, $function, &$context) {
  $limit = 1;
  if (empty($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($items);
  }
  if(empty($context['sandbox']['items'])) {
    $context['sandbox']['items'] = $items;
  }
  $counter = 0;
  if(!empty($context['sandbox']['items'])) {
    if ($context['sandbox']['progress'] != 0) {
      array_splice($context['sandbox']['items'], 0, $limit);
    }
    foreach ($context['sandbox']['items'] as $item) {
      if ($counter != $limit) {
        $counter++;
        $function($item, $context);
        $context['message'] = t('Checking %filename file.', array('%filename' => $item));
        $context['sandbox']['progress']++;
        $context['results']['processed'] = $context['sandbox']['progress'];
      }
    }
  }

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Finish callback after successfull batch operations.
 *
 * @param $success
 * @param $results
 * @param $operations
 */
function bootstrap_optimizer_batch_finished($success, $results, $operations) {
  if ($success && !empty($results['processed'])) {
    $message = format_plural($results['processed'], 'One file anylized.', '@count files anylized.');

    // Print all missing files.
    if (!empty($results['missing_files'])) {
      $broken_files = implode("<br/>", $results['missing_files']);
      drupal_set_message(t("Found !count missing files: <br/> !files", array('!count' => count($results['missing_files']), '!files' => $broken_files)), 'warning');
    }

    // Print all missing files that was just removed from {system} table.
    if (!empty($results['removed_files'])) {
      $broken_files = implode("<br/>", $results['removed_files']);
      drupal_set_message(t("Removed files: <br/> !files", array('!files' => $broken_files)));
    }

    // Print message if no missing files.
    if (empty($results['removed_files']) && empty($results['missing_files'])) {
      drupal_set_message(t('There are no missing files.'));
    }
  }
  else {
    $message = t('Finished with an error.');
  }

  drupal_set_message($message);
}
