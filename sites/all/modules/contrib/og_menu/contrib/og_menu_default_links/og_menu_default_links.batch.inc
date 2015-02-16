<?php
/**
 * @file
 * Implements batch handling for default menu links.
 */

/**
 * Process Batch request and update all specified menus.
 */
function og_menu_default_links_batch_default_links_process($menus, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_menu'] = 0;
    $context['sandbox']['max'] = count($menus);
    $context['sandbox']['menus'] = $menus;
  }

  // For this example, we decide that we can safely process
  // 5 nodes at a time without a timeout.
  $limit = 5;

  // With each pass through the callback, retrieve the next group of nids.
  $slice = array_slice($context['sandbox']['menus'], $context['sandbox']['progress'], $limit, TRUE);

  foreach ($slice as $key => $menu) {
    _og_menu_default_links_set_default_links($menu, 'update');

    // Store some result for post-processing in the finished callback.
    $context['results'][] = $menu;

    // Update our progress information.
    $context['sandbox']['progress']++;
    $context['sandbox']['current_menu'] = $menu;
    $context['message'] = t('Now processing %menu', array('%menu' => $menu));
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Batch Finished callback.
 */
function og_menu_default_links_batch_default_links_finished($success, $results, $operations) {
  if ($success) {
    // Here we do something meaningful with the results.
    $message = count($results) . ' processed.';
    $message .= theme('item_list', $results);
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments',
      array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
  }
  drupal_set_message($message);
}
