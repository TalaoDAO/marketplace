<?php
/**
 * @file
 * Batch function.
 *
 * This perfoms all the fun batch ops for the module.
 */

/**
 * Batch function.
 */
function fancy_file_delete_batch($fid, $force, &$context) {
  // Update our progress information.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
  }
  $context['sandbox']['progress']++;

  // Manual / Orphan Delete.
  if (is_numeric($fid)) {
    $file = file_load($fid);

    if ($file) {
      if ($force) {
        db_delete('file_managed')->condition('fid', $file->fid)->execute();
        db_delete('file_usage')->condition('fid', $file->fid)->execute();
        file_unmanaged_delete($file->uri);
      }
      else {
        file_delete($file);
      }
      $context['results'][] = $fid;
    }
  }
  // Delete unmanaged.
  else {
    db_delete('unmanaged_files')
    ->condition('path', $fid)
    ->execute();
    file_unmanaged_delete($fid);
    $context['results'][] = $fid;
  }
  // @todo Probably need to add some logic in case there were failures, etc.
  $context['message'] = t('Now cleansing the system of fid#%fid', array('%fid' => $fid));
}

/**
 * Batch finished.
 */
function fancy_file_delete_batch_finished($success, $results, $operations) {
  if ($success) {
    // Reset the cache
    entity_get_controller('file')->resetCache();
    $message = format_plural(count($results), 'One file cleansed.', '@count files cleansed.');
  }
  else {
    $message = t('Assimilation was futile!');
  }

  drupal_set_message($message);

  drupal_goto('admin/config/content/fancy_file_delete');
}
