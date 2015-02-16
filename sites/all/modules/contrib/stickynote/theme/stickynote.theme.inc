<?php

/**
 * Get notes for referring_url/current url and
 * return as list including edit/delete etc...
 *
 * @param $variables -> contains:
 *             $variables['referring_url'] = url for notes
 *             $variables['notes'] = an array of all notes for referring url
 * @TODO: Customize include better themeing for listing.
 */
function theme_stickynote_list($variables) {
  $output = '';
  $notes = array();

  $header = array();
  $header[] = t('Note');
  $header[] = t('Author');
  $header[] = t('Edit');
  $header[] = t('Delete');
  $header[] = t('Date');

  if (isset($variables['notes'])) {
    $table['header'] = $header;

    // build rows for list
    foreach ($variables['notes'] as $key => $stickynote) {
      if (_stickynote_view_access($stickynote)) {
        $note_class = 'note-' . $stickynote->snid;
        $account = user_load($stickynote->uid);
        $notes[$stickynote->snid] = array(
          'data' => array(
            'note' => array(
              'data' => nl2br(filter_xss($stickynote->note)),
              'class' => $note_class,
            ),
            'author' => array(
              'data' => l(t($account->name), 'user/' . $stickynote->uid),
              'class' => $note_class,
            ),
            'edit' => array(
              'data' => l(t('edit'), 'stickynote/' . $stickynote->snid . '/edit', array('attributes' => array('class' => array('use-ajax')))),
              'class' => $note_class,
            ),
            'delete' => array(
              'data' => l(t('delete'), 'stickynote/' . $stickynote->snid . '/delete_confirm', array('attributes' => array('class' => array('use-ajax')))),
              'class' => $note_class,
            ),
            'created' => array(
              'data' => format_date($stickynote->created, variable_get('stickynote_date_format', 'short')),
              'class' => $note_class,
            ),
          ),
          'id' => 'note-' . $stickynote->snid,
        );

        // If user doesn't have access, don't show edit link.
        if (!_stickynote_edit_access($stickynote)) {
          $notes[$stickynote->snid]['data']['edit'] = NULL;
        }

        // If user doesn't have access don't show delete link.
        if (!_stickynote_delete_access($stickynote)) {
          $notes[$stickynote->snid]['data']['delete'] = NULL;
        }
      }
    }

    $table['rows'] = $notes;

    $output = theme('table', $table);
  }

  return $output;
}

/**
 * Return confirmation links for deletion
 *
 * @param $variables
 */
function theme_stickynote_confirm($variables) {
  $stickynote = $variables['stickynote'];
  $token = drupal_get_token($stickynote->snid);

  $output = '';
  $output .= '<td colspan="5" id="note-' . $stickynote->snid . '">';
  $output .= '<div id="confirm-delete-' . $sitckynote->snid . '" style="text-align: center;">';
  $output .= 'Are you sure?</br>';
  $output .= l(t('Delete'), 'stickynote/' . $stickynote->snid . '/delete', array(
    'attributes' => array('class' => array('use-ajax')),
    'query' => array('token' => $token),
  ));
  $output .= '&nbsp;&nbsp;&nbsp;&nbsp;';
  $output .= l(t('Cancel'), 'stickynote/' . $stickynote->snid . '/cancel', array('attributes' => array('class' => array('use-ajax'))));
  $output .= '</div>';


  $output .= '</td>';


  return $output;
}
