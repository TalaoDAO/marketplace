<?php

/**
 * @file
 * Provide views data and handlers.
 */

/**
 * Implements of hook_views_data().
 */
function admin_users_views_data() {
  $data['users']['table']['default_relationship'][] = array(
    'comment' => array(
      'table' => 'comment',
      'field' => 'uid',
    ),
  );

  $data['users']['uid_comments'] = array(
    'relationship' => array(
      'title' => t('Comment authored'),
      'label'  => t('comments'),
      'help' => t('Relate comment to the user who created it. This relationship will create one record for each comment item created by the user.'),
      'handler' => 'views_handler_relationship',
      'base' => 'comment',
      'base field' => 'uid',
      'field' => 'uid',
    ),
  );

  return $data;
}
