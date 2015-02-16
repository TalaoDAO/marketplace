<?php

/**
 * @file
 * Definition of flag_friend_views_handler_filter_status.
 */

/**
 * Filter friends based on relationship status
 *
 * From flag_friend.module
 * FLAG_FRIEND_BOTH 0 - Users are friends
 * FLAG_FRIEND_FLAGGED 1 - Users are friends
 * FLAG_FRIEND_UNFLAGGED 2 - Neither user is flagged as a friend
 * FLAG_FRIEND_APPROVAL 3 - User has been flagged, pending their approval
 * FLAG_FRIEND_PENDING 4 - 1 user has flagged the other user
 *
 * @ingroup views_filter_handlers
 */
class flag_friend_views_handler_filter_status extends views_handler_filter {
  function option_definition() {
    $options = parent::option_definition();
    unset($options['value']);
    $options['value']['default'] = 1;
    return $options;
  }

  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);
    $form['value'] = array(
      '#type' => 'radios',
      '#title' => t('Relationship Status'),
      '#options' => array(
        '1' => t('Friends'),
        '2' => t('Not Friends'),
        '4' => t('Pending Friends'),
      ),
      '#default_value' => !empty($this->value['type']) ? $this->value['type'] : 1,
    );
  }
}