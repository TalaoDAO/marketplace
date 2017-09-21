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
      $commission_credits = round($total_credits * $commission);
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

/**
 * Check integrity of earnings and credits.
 */
function _emh_points_earnings_integrity() {

  $header = array(
    t('User'),
    t('+ Bought credits'),
    t('+ Received credits'),
    t('- Spent credits'),
    t('- Monetized credits'),
    t('- Monetization commissions'),
    t('- Expired credits'),
    t('= TOTAL CREDITS'),
    t('Checksum'),
    t('UID'),
  );

  $rows = array();

  $results = db_select('users', 'u')
    ->fields('u', array('uid', 'name'))
    ->condition('u.uid', 0, '<>')
    ->condition('u.uid', 1, '<>')
    ->execute()
    ->fetchAllAssoc('uid', PDO::FETCH_ASSOC);

  foreach ($results as $uid => $user) {

    // Total credits of the user.
    $user['points'] = db_select('emh_points_total', 't')
      ->fields('t', array('total_points'))
      ->condition('t.entity_id', $uid, '=')
      ->execute()
      ->fetchField();

    // Init the other values.
    $user['bought'] = $user['received'] = $user['spent'] = $user['expired'] = $user['monetized'] = $user['commissions'] = 0;

    // Get the user transactions.
    $transactions = db_select('emh_points_txn', 't')
      ->fields('t')
      ->condition(
        db_or()
          ->condition('source_id', $uid, '=')
          ->condition('dest_id', $uid, '=')
      )
      ->execute()
      ->fetchAll();

    // For each transaction:
    foreach ($transactions as $transaction) {

      // Depending on the context:
      switch ($transaction->context) {

        // Bought credits:
        case EMH_POINTS_TXN_CONTEXT_ADMIN_MANAGE_USER:
          // Double-check.
          if ($transaction->source_id == 1 && $transaction->dest_id == $uid && $transaction->source_type == 'user' && $transaction->dest_type == 'user') {
            // Bought = Given by admin - taken by admin.
            $user['bought'] = ($transaction->operation == POINTS_ADDITION) ? $user['bought'] + $transaction->points : $user['bought'] - $transaction->points;
          }
          break;

        // Received credits by admin bulk.
        case EMH_POINTS_TXN_CONTEXT_ADMIN_MANAGE_USER_BULK:
          // Double-check.
          if ($transaction->uid == 1 && $transaction->source_id == 1 && $transaction->dest_id == $uid && $transaction->source_type == 'user' && $transaction->dest_type == 'user') {
            // Received by admin bulk = Given - Taken.
            $user['received'] = ($transaction->operation == POINTS_ADDITION) ? $user['received'] + $transaction->points : $user['received'] - $transaction->points;
          }
          break;

        // Profile buy: received or spent.
        case EMH_USER_PROFILE_PURCHASE_TXN_CONTEXT:
          // Double-check.
          if ($transaction->operation == POINTS_TRANSFERT && $transaction->source_type == 'user' && $transaction->dest_type == 'user') {
            if ($transaction->dest_id == $uid) {
              $user['received'] += $transaction->points;
            }
            elseif ($transaction->source_id == $uid) {
              $user['spent'] += $transaction->points;
            }
          }
          break;

        // Received for a user sponsor.
        case EMH_VIRALITY_TXN_CONTEXT_USER_SPONSOR:
          // Double-check.
          if ($transaction->operation == POINTS_ADDITION && $transaction->source_id == 1 && $transaction->dest_id == $uid && $transaction->source_type == 'user' && $transaction->dest_type == 'user') {
            $user['received'] += $transaction->points;
          }
          break;

        // Requests.
        case 'request':
        case 'request+anonymous':
        case 'request+private':
        case 'request+private+anonymous':
          // Double-check.
          if ($transaction->operation == POINTS_TRANSFERT && $transaction->uid == $uid && $transaction->source_id == $uid && $transaction->dest_id == 1 && $transaction->source_type == 'user' && $transaction->dest_type == 'user') {
            $user['spent'] += $transaction->points;
          }
          break;

        // Expiration.
        case EMH_POINTS_TXN_CONTEXT_CRON:
          // Double-check.
          if ($transaction->operation == POINTS_EXPIRATION && $transaction->uid == 1 && $transaction->source_id == 1 && $transaction->dest_id == $uid && $transaction->source_type == 'user' && $transaction->dest_type == 'user') {
            $user['expired'] += $transaction->points;
          }
          break;

        // Commission.
        case EMH_POINTS_EARNINGS_COMMISSION_CONTEXT:
          // Double-check.
          if ($transaction->operation == POINTS_TRANSFERT && $transaction->uid == 0 && $transaction->source_id == $uid && $transaction->dest_id == 1 && $transaction->source_type == 'user' && $transaction->dest_type == 'user') {
            $user['commissions'] += $transaction->points;
          }
          break;

        // Monetization.
        case EMH_POINTS_EARNINGS_MONETIZATION_CONTEXT:
          // Double-check.
          if ($transaction->operation == POINTS_TRANSFERT && $transaction->uid == 0 && $transaction->source_id == $uid && $transaction->dest_id == 1 && $transaction->source_type == 'user' && $transaction->dest_type == 'user') {
            $user['monetized'] += $transaction->points;
          }
          break;

        // Deprecated.
        case EMH_POINTS_TXN_CONTEXT_DEPRECATED:
          // Double-check.
          if ($transaction->operation == POINTS_TRANSFERT) {
            if ($transaction->uid == $uid && $transaction->source_id == $uid && $transaction->source_type == 'user' && $transaction->dest_type == 'node') {
              $user['spent'] += $transaction->points;
            }
            elseif ($transaction->dest_id == $uid && $transaction->source_type == 'node' && $transaction->dest_type == 'user') {
              $user['received'] += $transaction->points;
            }
          }
          break;

        default:
          break;
      }
    }

    // Checksum.
    $user['check'] = ($user['points'] == $user['bought'] + $user['received'] - $user['spent'] - $user['monetized'] - $user['commissions'] - $user['expired']) ? TRUE : FALSE;

    // Prepare the row.
    $rows[] = array(
      $user['name'],
      $user['bought'],
      $user['received'],
      $user['spent'],
      $user['monetized'],
      $user['commissions'],
      $user['expired'],
      $user['points'],
      $user['check'] ? 'OK' : 'Bad checksum',
      $uid,
    );
  }

  return theme('table', array('header' => $header, 'rows' => $rows));
}
