<?php

/**
 * @file
 * EMH Users Views integration.
 */

/**
 * Implements hook_views_data().
 * @ingroup views
 */
function emh_user_views_data() {
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

  // Custom user cartouche.
  $data['users']['emh_user_cartouche'] = array(
    'group' => t('User'),
    'real field' => 'uid',
    'help' => 'EMH User cartouche',
    'title' => 'EMH User cartouche',
    'field' => array(
      'handler' => 'views_handler_field_emh_user_cartouche',
    ),
  );

  return $data;
}
