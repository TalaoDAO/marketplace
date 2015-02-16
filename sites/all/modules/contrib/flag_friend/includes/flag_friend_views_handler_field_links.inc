<?php

/**
 * @file
 * Contains the flag friend Ops field handler.
 */

/**
 * Views field handler for the Flag friend operations link when a user has requested
 * to be the friend of the logged in user.
 *
 * From flag_friend.module
 * FLAG_FRIEND_BOTH 0 - Users are friends
 * FLAG_FRIEND_FLAGGED 1 - Users are friends
 * FLAG_FRIEND_UNFLAGGED 2 - Neither user is flagged as a friend
 * FLAG_FRIEND_APPROVAL 3 - User has been flagged, pending their approval
 * FLAG_FRIEND_PENDING 4 - 1 user has flagged the other user
 *
 * @ingroup views
 */
class flag_friend_views_handler_field_links extends flag_handler_field_ops {
  function render($values) {
    global $user;
    $flag = flag_get_flag('friend');
    $entity_id = $values->uid;
    // what's the status?
    $status = flag_friend_determine_friend_status($flag, $entity_id, $user->uid);

    $link = NULL;
    if ($status == FLAG_FRIEND_APPROVAL) {
      // flagged, waiting for your approval
      $link = $flag->theme('flag', $entity_id);
      $link .= str_replace(t('Approve'), t('Deny'), $flag->theme('unflag', $entity_id));
    }
    elseif ($status == FLAG_FRIEND_PENDING) {
      // flagged, waiting for their approval
      $link = $flag->theme('unflag', $entity_id);
    }
    elseif ($status == FLAG_FRIEND_UNFLAGGED) {
      // not friends
      $link = $flag->theme('flag', $entity_id);
    }
    elseif ($status == FLAG_FRIEND_FLAGGED || $status == FLAG_FRIEND_BOTH) {
      // friends
      $link = $flag->theme('unflag', $entity_id);
    }
    return $link;
  }
}
