<?php

/**
 * @file
 * EMH Earnings deprecated code.
 */

/**
 * Retroactive commissions and monetizations.
 */
function _emh_points_earnings_retroactive() {
  $points = 0;
  // For all monetizable transactions contexts:
  foreach (EMH_POINTS_EARNINGS_CONTEXTS as $context) {
    // Get the old transactions to work on.
    $result = db_select('emh_points_txn', 't')
      ->fields('t')
      ->condition('t.context', $context, '=')
      ->condition('t.time_stamp', '1506081600', '<') // 2017/09/22 - 14:00
      ->execute()
      ->fetchAllAssoc('txn_id', PDO::FETCH_ASSOC);

    // For each of those transactions:
    foreach ($result as $txn_id => $txn) {
      watchdog('info', 'Retroactive monetise transaction '.$txn['txn_id']);
      // The user who got credits,
      // becomes the source of the commission and monetization transactions.
      $uid = $txn['dest_id'];
      $user = user_load($uid);
      $points += $txn['points'];
      // Commission and monetize.
      _emh_points_earnings_commission_and_monetize($txn, $user);
    }
  }
  echo "Monetized $points points\n";
}
