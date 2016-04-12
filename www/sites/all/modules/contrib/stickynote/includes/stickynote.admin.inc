<?php
/**
 * @file
 * Defines the admin page for the stickynote module
 */

/**
 * Admin page callback function.
 *
 * @return string
 */
function stickynote_info() {
  $notes_per_page = 20;
  $header = array(
    array(
      'data' => 'snid',
      'field' => 's.snid',
    ),
    array(
      'data' => 'Note',
      'field' => 's.note',
    ),
    array(
      'data' => 'URL',
      'field' => 's.url',
    ),
    array(
      'data' => 'User',
      'field' => 's.uid',
    ),
    array(
      'data' => 'Created',
      'field' => 's.created',
      'sort' => 'desc',
    ),
  );
  $query = db_select('stickynote', 's')->extend('PagerDefault')->extend('TableSort');
  $query
    ->fields('s')
    ->orderByHeader($header)
    ->limit($notes_per_page);

  $result = $query->execute();

  $notes = array();
  foreach ($result as $key => $row) {
    $user = user_load($row->uid, FALSE);
    $user_name = $user->uid == 0 ? 'Anon' :  l($user->name, 'user/' . $user->uid);
    $notes[] = array(
      'data' => array(
        'snid' => l($row->snid, 'stickynote/' . $row->snid),
        'note' => $row->note,
        'url' => l($row->url, $row->url),
        'user' => $user_name,
        'created' => date('n/j/Y - G:i', $row->created),
      )
    );
  }

  $build['stickynotes_table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $notes,
    '#prefix' => t('This table lists all existing stickynotes and their respective data.'),
    '#empty' => t('There are currently no stickynotes.')
  );
  $build['stickynotes_pager'] = array('#theme' => 'pager');

  return $build;
}

/**
 * Stickynote configuration options
 */
function stickynote_config() {
  $form = array();
  $date_formats = system_get_date_types();

  foreach ($date_formats as $format) {
    $options[$format['type']] = $format['title'];
  }

  $form['stickynote_date_format'] = array(
    '#type' => 'select',
    '#title' => t('Stickynote Date Format'),
    '#options' => $options,
    '#default_value' => variable_get('stickynote_date_format', 'short'),
    '#description' => t('Select a date format that will apply to stickynotes across the site.'),
  );

  return system_settings_form($form);
}
