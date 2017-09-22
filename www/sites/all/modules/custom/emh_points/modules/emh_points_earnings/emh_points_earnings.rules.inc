<?php

/**
 * @file
 * Rules integration hooks.
 */

/**
 * Implements hook_rules_event_info().
 */
function emh_points_earnings_rules_event_info() {
  $events = array();

  $events['emh_points_earnings_new_earnings'] = array(
    'label' => t('Earnings are added'),
    'module' => 'emh_points_earnings',
    'group' => t('Credits'),
    'variables' => array(
      'earnings' => array('type' => 'integer', 'label' => t('Number of earnings that have been transfered')),
      'owner' => array('type' => 'user', 'label' => t('Owner of the earnings')),
    ),
  );

  return $events;
}
