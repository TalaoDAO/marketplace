<?php

/**
 * @file
 * EMH Earnings helper functions.
 */

/**
 * Helper function for commissions and monetizations.
 *
 * @array $parent_txn Parent transaction.
 * @stdClass $source Source for those children transactions.
 */
function _emh_points_earnings_commission_and_monetize($parent_txn, $source) {
  $parent_context = $parent_txn['context'];

  // If the transaction context implies monetization:
  if (in_array($parent_context, EMH_POINTS_EARNINGS_CONTEXTS)) {

    // Load EMH account:
    $emindhub = user_load(1);
    // Get EMH commission rates.
    $commissions = variable_get('emh_points_earnings_commissions');
    // Before commission, the total amount of credits are monetizable:
    $monetizable_credits = $total_credits = $parent_txn['points'];
    // What is EMH's commission?
    $commission = floatval($commissions[$parent_context]);

    /*
     * Commission.
     */

    // If there is a valid commission rate:
    if ($commission > 0 && $commission < 1) {

      // Compute EMH's commission.
      $commission_credits = $total_credits * $commission;
      // Move commission credits from user to EMH:
      $parent_txn_id = $parent_txn['txn_id'];
      emh_points_move_points($source, $emindhub, $commission_credits, EMH_POINTS_EARNINGS_COMMISSION_CONTEXT, $parent_txn_id);
      // Ajust monetizable amount of credits.
      $monetizable_credits = $total_credits - $commission_credits;
    }

    /*
     * Monetization.
     */

    // 1) Move the credits back to EMH.
    // TODO: Validate in the specs that we are moving the credits back to EMH.
    // Another solution would be to destroy the credits when creating earnings.
    $parent_txn_id = $parent_txn['txn_id'];
    emh_points_move_points($source, $emindhub, $monetizable_credits, EMH_POINTS_EARNINGS_MONETIZATION_CONTEXT, $parent_txn_id);

    // 2) Add the earnings to the user.
    // Wrapp user into an entity.
    $source_entity = emh_points_build_entity_for_points($source);
    // Currency conversion: credits => earnings.
    $earnings = $monetizable_credits * EMH_POINTS_EARNINGS_RATE;
    // Add earnings.
    _emh_points_earnings_add_earnings($source_entity, $earnings);
  }
}

/**
 * Add earnings to an entity.
 */
function _emh_points_earnings_add_earnings($entity, $earnings) {

  // To add earning, there are almost no functional checks.
  if (!is_numeric($earnings) || (int) $earnings < 0) {
    watchdog('emh_points_earnings', 'Amount of earnings has to be a positive integer');
    return;
  }
  if (empty($entity)) {
    watchdog('emh_points_earnings', 'You should only add earnings to a valid entity');
    return;
  }
  // Add earnings.
  db_insert('emh_points_earnings')
    ->fields(array(
      'entity_id' => $entity->id,
      'entity_type' => $entity->type,
      'bundle' => $entity->bundle,
      'earnings' => $earnings,
      'last_update' => REQUEST_TIME,
    ))
    ->execute();
  // Raise Rules event.
  if ($entity->type == 'user') {
    $account = user_load($entity->id);
    rules_invoke_event('emh_points_earnings_new_earnings', $earnings, $account);
  }
  // Empty cache to reload the emh_points_earnings.
  entity_get_controller($entity->type)->resetCache(array($entity->id));
}

/**
 * Helper callback to load earnings on a single entity.
 */
function _emh_points_earnings_entity_load_single($entity, $type) {

  $wrapper = entity_metadata_wrapper('user', $entity);
  if (empty($wrapper)) {
    return;
  }

  $query = db_select('emh_points_earnings', 'e')
    ->condition('e.entity_type', $type)
    ->condition('e.entity_id', $wrapper->getIdentifier());
  $query->addExpression('SUM(e.earnings)');
  $earnings = $query->execute()->fetchField();
  if (!empty($earnings)) {
    $entity->emh_earnings = (int) $earnings;
  }
  else {
    $entity->emh_earnings = 0;
  }
}
