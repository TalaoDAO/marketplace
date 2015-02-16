<?php

/**
 * @file
 * Definition of flag_friend_views_handler_field.
 */

/**
 * A handler to render the appropriate relationship name as defined by
 * the user.
 *
 * From flag_friend.module
 * FLAG_FRIEND_BOTH 0 - Users are friends
 * FLAG_FRIEND_FLAGGED 1 - Users are friends
 * FLAG_FRIEND_UNFLAGGED 2 - Neither user is flagged as a friend
 * FLAG_FRIEND_APPROVAL 3 - User has been flagged, pending their approval
 * FLAG_FRIEND_PENDING 4 - 1 user has flagged the other user
 *
 * @ingroup views_field_handlers
 */
class flag_friend_views_handler_field_status extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();

    $options['friends'] = array('default' => 'Friends');
    $options['not_friends'] = array('default' => 'Not friends');
    $options['pending_approval'] = array('default' => 'Pending Approval');
    $options['pending_requests'] = array('default' => 'Pending Requests');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['friends'] = array(
      '#type' => 'textfield',
      '#title' => 'Approved relationship name',
      '#default_value' => $this->options['friends'],
    );

    $form['not_friends'] = array(
      '#type' => 'textfield',
      '#title' => 'No relationship name',
      '#default_value' => $this->options['not_friends'],
    );

    $form['pending_approval'] = array(
      '#type' => 'textfield',
      '#title' => 'Pending approval name',
      '#default_value' => $this->options['pending_approval'],
    );

    $form['pending_requests'] = array(
      '#type' => 'textfield',
      '#title' => 'Pending requests name',
      '#default_value' => $this->options['pending_requests'],
    );

    parent::options_form($form, $form_state);
  }

  function render($values) {
    global $user;
    $flag = flag_get_flag('friend');
    $entity_id = $values->uid;
    $status = flag_friend_determine_friend_status($flag, $entity_id, $user->uid);

    switch ($status) {
      case '0' :
      case '1' :
        return check_plain($this->options['friends']);
        break;
      case '2' :
        return check_plain($this->options['not_friends']);
        break;
      case '3' :
        return check_plain($this->options['pending_approval']);
        break;
      case '4' :
        return check_plain($this->options['pending_requests']);
        break;
    }
  }
}