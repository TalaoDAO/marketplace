<?php

/**
 * Rules integration hooks.
 */

/**
 * Implements hook_rules_event_info().
 * @ingroup rules
 */
function emh_points_rules_event_info() {
  $events = array();
  $events['emh_points_points_will_expire'] = array(
    'label' => t('Credits will expire in month'),
    'module' => 'emh_points',
    'group' => t('Credits'),
    'variables' => array(
      'points' => array('type' => 'integer', 'label' => t('Number of credits that will expire')),
      'owner' => array('type' => 'user', 'label' => t('Owner of the credits')),
    ),
  );
  $events['emh_points_new_points'] = array(
    'label' => t('Credits are added'),
    'module' => 'emh_points',
    'group' => t('Credits'),
    'variables' => array(
      'points' => array('type' => 'integer', 'label' => t('Number of credits that have been transfered')),
      'owner' => array('type' => 'user', 'label' => t('Owner of the credits')),
    ),
  );
  return $events;
}

/**
 * Implements hook_rules_condition_info().
 * @ingroup rules
 */
function emh_points_rules_condition_info() {
  $conditions = array();
  $conditions['emh_points_user_has_enough_points'] = array(
    'label' => t('User has enough credits'),
    'module' => 'emh_points',
    'group' => t('Credits'),
    'parameter' => array(
      'owner' => array('type' => 'user', 'label' => t('Owner of the credits')),
      'points' => array('type' => 'integer', 'label' => t('Number of credits to validate')),
    ),
  );
  return $conditions;
}

/**
 * Callback for some Rules condition.
 */
function emh_points_user_has_enough_points($user, $points) {
  $current_points = 0;
  $query = db_select('emh_points', 'p')
    ->condition('p.entity_type', 'user')
    ->condition('p.entity_id', $user->uid);
  $query->addExpression('SUM(p.points)');
  $current_points = $query->execute()->fetchField();
  return ($current_points >= $points);
}

/**
 * Implements hook_rules_action_info().
 * @ingroup rules
 */
function emh_points_rules_action_info() {
  $actions = array();
  $actions['move_points'] = array(
    'label' => t('Move credits'),
    'group' => t('Credits'),
    'base' => 'emh_points_move_points',
    'parameter' => array(
      'source' => array('label' => t('Source'), 'type' => 'entity'),
      'destination' => array('label' => t('Destination'), 'type' => 'entity'),
      'points' => array('label' => t('Number of credits to move'), 'type' => 'integer'),
    ),
  );
  return $actions;
}
