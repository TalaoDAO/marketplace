<?php

/**
 * Colorize buttons based on the text value.
 *
 * @param string $text
 *   Button text to search against.
 *
 * @return string
 *   The specific button class to use or FALSE if not matched.
 */
function _emindhub_colorize_button($text) {
  // Text values containing these specific strings, which are matched first.
  $specific_strings = array(
    'btn-primary' => array(
      t('Save as draft'),
    ),
    // 'btn-primary' => array(
    //   t('Download feature'),
    // ),
    // 'btn-success' => array(
    //   t('Add effect'),
    //   t('Add and configure'),
    // ),
    // 'btn-info' => array(
    //   t('Save and add'),
    //   t('Add another item'),
    //   t('Update style'),
    // ),
  );
  // Text values containing these generic strings, which are matches last.
  $generic_strings = array(
    'btn-default' => array(
      // t('Save'),
      // t('Confirm'),
      // t('Submit'),
      // t('Search'),
    ),
    'btn-primary' => array(
      // t('Save'),
      // t('Confirm'),
      // t('Submit'),
      // t('Search'),
      t('Access profile'),
      t('Continue'),
      t('E-mail new password'),
      t('Join'),
      t('Log in'),
      t('Publish'),
      t('Send'),
      t('Upload'),
      t('Yes'),
    ),
    'btn-success' => array(
      // t('Add'),
      // t('Create'),
      // t('Write'),
    ),
    'btn-warning' => array(
      // t('Export'),
      // t('Import'),
      // t('Restore'),
      // t('Rebuild'),
    ),
    'btn-info' => array(
      // t('Apply'),
      // t('Update'),
    ),
    'btn-danger' => array(
      // t('Delete'),
      // t('Remove'),
      t('Cancel'),
    ),
  );
  // Specific matching first.
  foreach ($specific_strings as $class => $strings) {
    foreach ($strings as $string) {
      if (strpos(drupal_strtolower($text), drupal_strtolower($string)) !== FALSE) {
        return $class;
      }
    }
  }
  // Generic matching last.
  foreach ($generic_strings as $class => $strings) {
    foreach ($strings as $string) {
      if (strpos(drupal_strtolower($text), drupal_strtolower($string)) !== FALSE) {
        return $class;
      }
    }
  }
  return FALSE;
}
