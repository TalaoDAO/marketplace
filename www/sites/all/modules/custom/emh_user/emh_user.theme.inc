<?php

/**
 * Helper function to get user cartouche.
 *
 * @param stdClass|integer $account
 *  A user account object or an uid
 * @param stdClass|boolean $context
 *  A context, such as 'author'
 * @return string
 *  The user's cartouche
 */
function emh_user_cartouche_view($account = NULL, $context = NULL) {
  global $user;
  $uid1 = $user->uid;

  if ($account == NULL) {
    $u2_account = user_load($uid1);
  } else {
    $uid2 = is_object($account) ? $account->uid : (int) $account;
    $u2_account = is_object($account) ? $account : user_load($uid2);
  }

  $node = '';
  if (arg(0) === 'node') {
    $node = !empty(menu_get_object()) ? menu_get_object() : node_load(arg(1));
  }

	// Identity
  $identity = (!empty($node) && $context == 'author' && emh_request_has_option($node, 'anonymous') && $node->field_hide_name[LANGUAGE_NONE][0]['value'] == true) ? t('Anonymous') : format_username($u2_account);

  // Photo
  if (emh_access_user_can_see_full_user($uid1, $uid2)) {
    $photo = field_view_field('user', $u2_account, 'field_photo', array('label'=>'hidden'));
    $photo = render($photo);
  } else {
    $instance = field_info_instance('user', 'field_photo', 'user');
    if (!empty($instance) && isset($instance['settings']['default_image']) && $instance['settings']['default_image'] > 0) {
      $photo_fid = $instance['settings']['default_image'];
      $photo = file_load($photo_fid);
      $photo = array(
        'path' => $photo->uri,
        'alt' => $identity,
        'title' => '',
        'width' => '110px',
        'height' => '110px',
        'attributes' => array(),
      );
      $photo = theme_image($photo);
    }
  }

  // Profile link
  $user_profile_link = '';
  if ((emh_access_user_can_see_full_user($uid1, $uid2) && !(!empty($node) && emh_request_has_option($node, 'anonymous') && $node->field_hide_name[LANGUAGE_NONE][0]['value'] == true)) || (emh_access_user_can_see_full_user($uid1, $uid2) && !empty($node))) {
    $user_profile_link = url('user/' . $uid2);
  }

  // Organisation
  $organisation = '';
	$organisation = field_get_items('user', $u2_account, 'field_entreprise');
  if (!empty($organisation)) {
    if (
          ($context == 'author' && !(emh_request_has_option($node, 'anonymous')))
      ||  ($context == 'author' && (emh_request_has_option($node, 'anonymous') && ($node->field_hide_organisation[LANGUAGE_NONE][0]['value'] == false)))
      ||  ($context != 'author' && (emh_access_user_can_see_full_user($uid1, $uid2)))
    ) {
      $organisation = field_view_field('user', $u2_account, 'field_entreprise', array('label'=>'hidden'));
    }
  }

  // Activity
  $activity = '';
  if (!empty($node)) {
    $entity_type = 'node'; $entity = $node; $field_name = 'field_activity';
  } else {
    $entity_type = 'user'; $entity = $u2_account; $field_name = 'field_titre_metier';
  }
  $activity = field_get_items($entity_type, $entity, $field_name);
  if (($context == 'author') && emh_request_has_option($node, 'anonymous') && !empty($activity)) {
    $activity = field_view_field($entity_type, $entity, $field_name, array('label'=>'hidden'));
  }

  // Address
  $address = '';
  if (empty($node)) {
    $address = field_view_field('user', $u2_account, 'field_address', array('label'=>'hidden'));
  }

  // Mail
  $mail = '';
  if (empty($node)) {
    $mail = field_view_field('user', $u2_account, 'field_mail', array('label'=>'hidden'));
  }

	// Buy profile access
  $user_purchase_link = '';
	if (module_exists('emh_user_profile_purchase') && !emh_access_user_can_see_full_user($uid1, $uid2) && !($context == 'author')) {
    $amount = (int) variable_get('emh_user_profile_purchase_amount', 100);
    if (!empty($node)) {
      $user_purchase_link = url('user/' . $uid2 . '/purchase') . '?destination=node/' . $node->nid;
    }
    else {
      $user_purchase_link = url('user/' . $uid2 . '/purchase');
    }
	}

  // Submissions count
  $submission_count = '';
  if (module_exists('emh_request_submission') && $context !== 'author') {
    $submission_count = emh_request_submission_get_user_submission_count($uid2);
  }

  // Profile purchased count
  $purchased_count = '';
	if (module_exists('emh_user_profile_purchase') && !($context == 'author')) {
    $purchased_count = emh_user_profile_purchase_get_count($u2_account);
	}

  return theme('emh_user_cartouche', array(
    'user_profile_link' => $user_profile_link,
    'identity' => $identity,
    'photo' => $photo,
    'organisation' => $organisation,
    'activity' => $activity,
    'address' => $address,
    'mail' => $mail,
    'user_purchase_link' => $user_purchase_link,
    'amount' => $amount,
    'submission_count' => $submission_count,
    'purchased_count' => $purchased_count,
  ));
}
