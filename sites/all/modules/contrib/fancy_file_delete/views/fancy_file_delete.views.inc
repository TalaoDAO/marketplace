<?php
/**
 * @file
 * Fancy File Delete Views Settings.
 */

/**
 * Implements hook_views_data_alter().
 */
function fancy_file_delete_views_data_alter(&$data) {
  // Add Orphan File Filter.
  $data['file_managed']['orphan_delete']['title'] = 'Orphan File Delete';
  $data['file_managed']['orphan_delete']['help'] = 'Filter by Orphan Files.';
  $data['file_managed']['orphan_delete']['filter']['handler'] = 'fancy_file_delete_orphan_file_filter';
}
