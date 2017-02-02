<?php

/**
 * Implements hook_block_info().
 */
function emh_circles_block_info() {
  $blocks = array();

  $blocks['membership-infos'] = array(
    'info' => t('Circle - Membership infos'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
    'weight' => 0,
    'status' => 1,
    'region' => 'title_right',
  );

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function emh_circles_block_view($delta = '') {
  $block = array();

  switch ($delta) {
    case 'membership-infos':
      $block = array(
        'subject' => '',
        'content' => emh_circles_block_membership_infos(),
      );
      break;
  }

  return $block;
}

/**
 * Return content for 'membership-infos' block.
 */
function emh_circles_block_membership_infos() {
  $group = og_context();

  $group_node = node_load($group['gid']);

  $state = (!empty($group['gid'])) ? emh_circles_show_membership_state_info($group) : '';
  $subscribe_link = (!empty($group['gid'])) ? og_extras_subscribe($group['group_type'], $group_node) : '';

  return theme('emh_circles_membership_infos__block', array(
    'state' => $state,
    'subscribe_link' => $subscribe_link,
  ));
}
