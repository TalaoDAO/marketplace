<?php

/**
 * @file
 * Provides Flag Friend data to Views.
 */

/**
 * Implements hook_views_data().
 */
function flag_friend_views_data() {
  $data = array();

  // flag_friend table
  $data['flag_friend']['table']['group'] = t('Flag friend');

  $data['flag_friend']['table']['join']['flagging'] = array(
    'left_field' => 'flagging_id',
    'field' => 'flagging_id',
    'type' => 'INNER',
  );

  $data['flag_friend']['status'] = array(
    'title' => t('Relationship Status'),
    'help' => t('Display the status of the relationship, whether pending or approved'),
    'field' => array(
      'handler' => 'flag_friend_views_handler_field_status',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'flag_friend_views_handler_filter_status',
    ),
  );

  $data['flag_friend']['friend_link'] = array(
    'title' => t('Friend Link'),
    'help' => t('Flag Friend Link. Only used for creating links for users who have been flagged as by a friend'),
    'field' => array(
      'handler' => 'flag_friend_views_handler_field_links',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
    ),
  );

  // field, sort, filter, argument
  $data['flag_friend']['created'] = array(
    'title' => t('Relationship created time'),
    'help' => t('Display the time the relationship was approved.'),
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
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  );
/*
  // flag_friend_message table
  $data['flag_friend_message']['table']['group'] = t('Flag friend');
  $data['flag_friend_message']['table']['join'] = array(
    'flag_content' => array(
      'left_field' => 'fcid',
      'field' => 'fcid',
    ),
  );

  // field
  $data['flag_friend_message']['message'] = array(
    'title' => t('Message'),
    'help' => t('Display the message for any friend flags. (Only useful for a list of pending friend requests.)'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
  );*/

  // Add the flag relationship.
  // This basically just changes the 'base field' while reusing Flag's
  // relationship handler. In effect, we can display the user who flagged
  // the content we specify, instead of the user who is flagged.
  $data['users']['flag_friend_content_rel'] = array(
    'group' => t('Flag Friend'),
    'title' => t('User flag'),
    'help' => t('Limit results to only those users flagged by a certain flag; Displays the user who flagged this content.'),
    'relationship' => array(
      'flag type' => 'user',
      'handler' => 'flag_handler_relationship_content',
      'label' => t('flag friend'),
      'base' => 'flagging',
      'base field' => 'entity_id',
      'relationship field' => 'uid',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function flag_friend_views_data_alter(&$data) {
  if (module_exists('apachesolr_views')) {
    $data['apachesolr']['friends'] = array(
      'title' => t('Friends of'),
      'help' => t('Retrieve the friends of the user id given.'),
      'argument' => array(
        'handler' => 'flag_friend_handler_argument_apachesolr_friend',
        'field' => 'uid',
      ),
    );
  }
}

/**
 * Implements hook_views_plugins
 */
function flag_friend_views_plugins() {
  return array(
    'access' => array(
      'flag_friend' => array(
        'title' => t('Restrict Flag Friend Pending and Requests Access'),
        'help' => t('Creates a custom access check to see if a user is looking at their own account.'),
        'handler' => 'flag_friend_plugin_access_pending_requested',
      ),
    ),
  );
}