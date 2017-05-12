<?php
/**
 * @file
 * Deprecated code of the eMindHub request feature.
 */

/**
 * Implements hook_block_info().
 */
function emh_request_block_info() {
  $blocks = array();

  $request_types = emh_request_get_types();
  foreach ($request_types as $type) {

    $blocks["request_help_$type"] = array(
      'info' => t("Add $type - Help"),
      'cache' => DRUPAL_CACHE_PER_ROLE,
      'weight' => -100,
      'status' => 1,
      'region' => 'sidebar_second',
      'visibility' => BLOCK_VISIBILITY_LISTED,
      'pages' => "node/add/$type",
    );

  }

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function emh_request_block_view($delta = '') {
  $block = array();

  $request_types = emh_request_get_types();
  foreach ($request_types as $type) {

    switch ($delta) {

      case 'request_help_' . $type:
        $data = variable_get("emh_block_request_help_$type", array('value' => '', 'format' => 'filtered_html'));
        $block = array(
          'subject' => '<none>',
          'content' => array(
            'text' => array(
              '#markup' => check_markup($data['value'], $data['format']),
            ),
          ),
        );
        break;
    }

  }

  return $block;
}

/**
 * Implements hook_block_configure().
 */
function emh_request_block_configure($delta='') {
  $form = array();

  $request_types = emh_request_get_types();
  foreach ($request_types as $type) {

    switch($delta) {
      case 'request_help_' . $type:

        $data = variable_get("emh_block_request_help_$type", array('value' => '', 'format' => 'filtered_html'));
        $form['text'] = array(
          '#type' => 'text_format',
          '#title' => t('Block text'),
          '#default_value' => $data['value'],
          '#format' => $data['format'],
        );
        break;
    }

  }

  return $form;
}

/**
 * Implements hook_block_save().
 */
function emh_request_block_save($delta = '', $edit = array()) {
  $request_types = emh_request_get_types();
  foreach ($request_types as $type) {

    switch($delta) {
      case 'request_help_' . $type:
        variable_set("emh_block_request_help_$type", $edit['text']);
        break;

    }
  }
}

/**
 * Helper function to retrieve an answer, depending on the status.
 */
function emh_request_get_answer($entity, $type) {
  $output = '';

  switch ($type) {
    case 'comment':
      if (empty($entity->field_private_comment)) {
        // No status => body field.
        $output = $entity->comment_body[LANGUAGE_NONE]['0']['value'];
      } else {
        switch($entity->field_private_comment[LANGUAGE_NONE]['0']['value']) {
          case 0:
            $output = $entity->comment_body[LANGUAGE_NONE]['0']['value'];
            break;
          case 1:
            $output = $entity->field_private_comment_body[LANGUAGE_NONE]['0']['value'];
            break;
        }
      }
      break;
    case 'webform_submission':
      foreach ($entity->data as $answer) {
        $output .= $answer[0] . '&nbsp;';
      }
      break;
  }

  return strip_tags(views_trim_text(
    array(
      'max_length' => 100,
      'word_boundary' => TRUE,
      'ellipsis' => TRUE,
      'html' => TRUE,
    ),
    $output
  ));
}

/**
 * Helper function to retrieve the list of request types.
 */
function emh_request_get_types() {
  return array('request', 'question1', 'webform', 'challenge');
}
