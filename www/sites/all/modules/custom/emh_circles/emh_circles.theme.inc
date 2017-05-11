<?php

function emh_circles_get_circle_logo($node = null) {
  global $base_url;

  if ($node === null) {
		$node = menu_get_object();
	}
	elseif (is_numeric($node)) {
		$node = node_load($node);
	}

	if (empty($node) || $node->type !== 'circle') return;

  $circle_logo = field_get_items('node', $node, 'field_circle_logo');
  $circle_logo_file = empty($circle_logo) ? '' : file_load($circle_logo['0']['fid']);
  $circle_logo_file_uri = empty($circle_logo) ? $base_url . '/' . drupal_get_path('module', 'emh_circles') . '/images/community.svg' : file_create_url($circle_logo_file->uri);
  $circle_logo_width = empty($circle_logo) ? '100' : $circle_logo['0']['image_dimensions']['width'];
  $circle_logo_height = empty($circle_logo) ? '100' : $circle_logo['0']['image_dimensions']['height'];

  return '<img src="' . $circle_logo_file_uri . '" width="' . $circle_logo_width . '" height="' . $circle_logo_height . '" alt="' . $node->title . '" title="' . $node->title . '" />';
}

function emh_circles_show_membership_state_info($node, $account = NULL) {
  if ($account == NULL) {
    global $user;
    $account = user_load($user);
  }

  $og_states = array(
    OG_STATE_ACTIVE,
    OG_STATE_PENDING,
    OG_STATE_BLOCKED
  );

  foreach ($og_states as $og_state) {
    $state = og_is_member('node', $node->nid, 'user', $account, array($og_state)) ? $og_state : '0';
    switch ($state) {
      // Active
      case '1':
        break;
      // Pending
      case '2':
        return t('Your request is pending.');
        break;
      // Blocked
      case '3':
        break;
      default:
        break;
    }
  }
}
