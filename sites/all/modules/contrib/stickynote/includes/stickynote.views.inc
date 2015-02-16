<?php

/**
 * Implements hook_views_data().
 */
function stickynote_views_data() {
  $data['stickynote']['table']['group'] = t('Stickynote Table');

  $data['stickynote']['table']['base'] = array(
    'field' => 'snid',
    'title' => t('Stickynote'),
    'help' => t("Stickynote table contains stickynote content for given paths."),
    'weight' => -10,
  );

  $data['stickynote']['snid'] = array(
    'title' => t('Stickynote ID'),
    'help' => t('Stickynote ID'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['stickynote']['note'] = array(
    'title' => t('Note'),
    'help' => t('Stickynote contents'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['stickynote']['uid'] = array(
    'title' => t('Stickynote Author'),
    'help' => t('Stickynote author'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['stickynote']['url'] = array(
    'title' => t('URL'),
    'help' => t('URL stickynote is saved on.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );


  $data['stickynote']['created'] = array(
    'title' => t('Created time'),
    'help' => t('Created timestamp'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['stickynote']['updated'] = array(
    'title' => t('Updated timed'),
    'help' => t('Updated timestamp'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}
