<?php

/**
 * @file
 * EMH Users Views integration.
 */

/**
 * Implements hook_views_data().
 * @ingroup views
 */
function emh_users_views_data() {
  $data = array();

  // Pseudo-field on comment.
  $data['comment']['emh_author'] = array(
    'group' => 'Comment',
    'real field' => 'cid',
    'help' => 'Beautiful author',
    'title' => 'EMH Author',
    'field' => array(
      'handler' => 'views_handler_field_emh_comment_author',
    ),
  );
  // Pseudo-field on webform submissions.
  $data['webform_submissions']['emh_author'] = array(
    'group' => t('Webform submissions'),
    'real field' => 'sid',
    'help' => 'Beautiful author',
    'title' => 'EMH Author',
    'field' => array(
      'handler' => 'views_handler_field_emh_webform_author',
    ),
  );

  return $data;
}
