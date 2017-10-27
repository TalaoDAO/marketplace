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
    _emh_points_earnings_add_earnings($source_entity, $earnings, $parent_txn_id);
  }
}

/**
 * Add earnings to an entity.
 */
function _emh_points_earnings_add_earnings($entity, $earnings, $parent_txn_id) {

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
      'parent_txn_id' => $parent_txn_id,
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
function _emh_points_earnings_integrity_log($uid) {

  $header = array(
    t('UID'),
    t('Source type'),
    t('Source ID'),
    t('Dest type'),
    t('Dest ID'),
    t('Points'),
    t('Operation'),
    t('Context'),
    t('Description'),
    t('Timestamp'),
    t('TXID'),
  );

  $rows = array();

  $results = db_select('emh_points_txn', 't')
    ->fields('t', array('uid', 'txn_id', 'description', 'source_id', 'dest_id', 'operation', 'context', 'points', 'time_stamp', 'source_type', 'dest_type'))
    ->condition(db_or()
      ->condition('t.source_id', $uid, '=')
      ->condition('t.dest_id', $uid, '=')
      ->condition('t.uid', $uid, '='))
    ->orderBy('time_stamp')
    ->execute()
    ->fetchAll();

  foreach ($results as $txn) {
    $rows[] = array(
      $txn->uid,
      $txn->source_type,
      $txn->source_id,
      $txn->dest_type,
      $txn->dest_id,
      $txn->points,
      $txn->operation,
      $txn->context,
      $txn->description,
      format_date($txn->time_stamp),
      l($txn->txn_id,'http://emh.box.local/adminer.php?username=root&db=emh&select=emh_points_txn&where%5B0%5D%5Bcol%5D=txn_id&where%5B0%5D%5Bop%5D=%3D&where%5B0%5D%5Bval%5D='.$txn->txn_id),
    );
  }
  $result = l('User', '/user/'.$uid.'/credits');
  $result .= '<br>';
  $result .= theme('table', array('header' => $header, 'rows' => $rows));
  return $result;
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
    t('Earnings'),
    t('Validity'),
  );

  $rows = array();

  $results = db_select('users', 'u')
    ->fields('u', array('uid', 'name'))
    ->condition('u.uid', 0, '<>')
    ->condition('u.uid', 1, '<>')
    ->execute()
    ->fetchAllAssoc('uid', PDO::FETCH_ASSOC);

  $tc = 0;
  $txs = [];
  foreach ($results as $uid => $user) {

    // Total credits of the user.
    $user['points'] = db_select('emh_points_total', 't')
      ->fields('t', array('total_points'))
      ->condition('t.entity_type', 'user', '=')
      ->condition('t.entity_id', $uid, '=')
      ->execute()
      ->fetchField();

    // Earnings of the user : get the sum of all earnings.
    $query = db_select('emh_points_earnings', 'e')
      ->condition('e.entity_type', 'user', '=')
      ->condition('e.entity_id', $uid, '=');
    $query  ->addExpression('SUM(e.earnings)');
    $earnings = $query
      ->execute()
      ->fetchField();
    $user['earnings']=!empty($earnings)?$earnings:0;

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
            $tc++; $txs[] = $transaction->txn_id;
          }
          break;

        // Received credits by admin bulk.
        case EMH_POINTS_TXN_CONTEXT_ADMIN_MANAGE_USER_BULK:
          // Double-check.
          if ($transaction->uid == 1 && $transaction->source_id == 1 && $transaction->dest_id == $uid && $transaction->source_type == 'user' && $transaction->dest_type == 'user') {
            // Received by admin bulk = Given - Taken.
            $user['received'] = ($transaction->operation == POINTS_ADDITION) ? $user['received'] + $transaction->points : $user['received'] - $transaction->points;
            $tc++; $txs[] = $transaction->txn_id;
          }
          break;

        // Profile buy: received or spent.
        case EMH_USER_PROFILE_PURCHASE_TXN_CONTEXT:
          // Double-check.
          if ($transaction->operation == POINTS_TRANSFERT && $transaction->source_type == 'user' && $transaction->dest_type == 'user') {
            if ($transaction->dest_id == $uid) {
              $user['received'] += $transaction->points;
              $tc++; $txs[] = $transaction->txn_id;
            }
            elseif ($transaction->source_id == $uid) {
              $user['spent'] += $transaction->points;
              $tc++; $txs[] = $transaction->txn_id;
            }
          }
          break;

        // Received for a user sponsor.
        case EMH_VIRALITY_TXN_CONTEXT_USER_SPONSOR:
          // Double-check.
          if ($transaction->operation == POINTS_ADDITION && $transaction->source_id == 1 && $transaction->dest_id == $uid && $transaction->source_type == 'user' && $transaction->dest_type == 'user') {
            $user['received'] += $transaction->points;
            $tc++; $txs[] = $transaction->txn_id;
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
            $tc++; $txs[] = $transaction->txn_id;
          }
          break;

        // Expiration.
        case EMH_POINTS_TXN_CONTEXT_CRON:
          // Double-check.
          if ($transaction->operation == POINTS_EXPIRATION && $transaction->uid == 1 && $transaction->source_id == 1 && $transaction->dest_id == $uid && $transaction->source_type == 'user' && $transaction->dest_type == 'user') {
            $user['expired'] += $transaction->points;
            $tc++; $txs[] = $transaction->txn_id;
          } 
          break;

        // Commission.
        case EMH_POINTS_EARNINGS_COMMISSION_CONTEXT:
          // Double-check.
          // TODO : check with guillame uid==0
          if ($transaction->operation == POINTS_TRANSFERT /*&& $transaction->uid == 0*/ && $transaction->source_id == $uid && $transaction->dest_id == 1 && $transaction->source_type == 'user' && $transaction->dest_type == 'user') {
            $user['commissions'] += $transaction->points;
            $tc++; $txs[] = $transaction->txn_id;
          }
          break;

        // Monetization.
        case EMH_POINTS_EARNINGS_MONETIZATION_CONTEXT:
          // Double-check.
          // TODO : check with guillame uid==0
          if ($transaction->operation == POINTS_TRANSFERT /*&& ($transaction->uid == 0 || $transaction->uid == $uid)*/ && $transaction->source_id == $uid && $transaction->dest_id == 1 && $transaction->source_type == 'user' && $transaction->dest_type == 'user') {
            $user['monetized'] += $transaction->points;
            $tc++; $txs[] = $transaction->txn_id;
          }
          break;

        // Deprecated.
        case EMH_POINTS_TXN_CONTEXT_DEPRECATED:
          // Double-check.
          if ($transaction->operation == POINTS_TRANSFERT) {
            //if ($transaction->uid == $uid && $transaction->source_id == $uid && $transaction->source_type == 'user' && $transaction->dest_type == 'node') {
            if (/*$transaction->uid == $uid &&*/ $transaction->source_id == $uid && $transaction->source_type == 'user' && $transaction->dest_type == 'node') {
              $user['spent'] += $transaction->points;
              $tc++; $txs[] = $transaction->txn_id;
            }
            elseif ($transaction->dest_id == $uid && $transaction->source_type == 'node' && $transaction->dest_type == 'user') {
              $user['received'] += $transaction->points;
              $tc++; $txs[] = $transaction->txn_id;
            } /* else {
              drupal_set_message(l('Unsuported transaction '.$transaction->txn_id.' for user '.$uid, 'http://emh.box.local/adminer.php?username=root&db=emh&select=emh_points_txn&where%5B0%5D%5Bcol%5D=txn_id&where%5B0%5D%5Bop%5D=%3D&where%5B0%5D%5Bval%5D='.$transaction->txn_id));
            }*/
          }
          break;

        default:
          break;
      }
    }

    $diff = $user['bought'] + $user['received'] - $user['spent'] - $user['monetized'] - $user['commissions'] - $user['expired'];
    // Checksum.
    $user['check'] = $user['points'] == $diff && $user['monetized'] == $user['earnings'] ? TRUE : FALSE;

    // Prepare the row.
    if (!$user['check'] || arg(5)=='all') {
      $rows[] = array(
        l($user['name'], 'admin/emindhub/credits/earnings/integrity/log/'.$uid),
        $user['bought'],
        $user['received'],
        $user['spent'],
        $user['monetized'],
        $user['commissions'],
        $user['expired'],
        $user['points'],
        $user['points'] == $diff ? 'OK' : l('Bad checksum ('.$diff.')', 'http://emh.box.local/adminer.php?username=root&db=emh&select=emh_points_total&where%5B0%5D%5Bcol%5D=entity_id&where%5B0%5D%5Bop%5D=%3D&where%5B0%5D%5Bval%5D='.$uid),
        $uid,
        $user['earnings'],
        $user['monetized'] == $user['earnings'] ? 'OK' : l('Bad checksum('.($user['earnings'] - $user['monetized']).')', 'http://emh.box.local/adminer.php?username=root&db=emh&select=emh_points_earnings&where%5B0%5D%5Bop%5D=%3D&where%5B0%5D%5Bval%5D=user&where%5B1%5D%5Bcol%5D=entity_id&where%5B1%5D%5Bop%5D=%3D&where%5B1%5D%5Bval%5D='.$uid)
      );
    }
  }
  $output = "";
  $tcount = db_select('emh_points_txn')->fields(NULL, array('field'))->countQuery()->execute()->fetchField();
  if ($tcount <> $tc) {
    $dups = array_intersect($txs, array_unique(array_diff_key($txs, array_unique($txs))));
    $dc = count($dups) / 2;
    if ($dc > 0) {
      drupal_set_message('Duplicates (should all be profile_buy) : '.$dc);
      $output .= l('Duplicates transactions', 'http://emh.box.local/adminer.php?username=root&db=emh&select=emh_points_txn&where%5B0%5D%5Bcol%5D=txn_id&where%5B0%5D%5Bop%5D=IN&where%5B0%5D%5Bval%5D='.implode('%2C+', $dups));
      $output .= '<br>';
    }

    $tx_list = db_select('emh_points_txn', 'e')->fields('e', array('txn_id'))->execute()->fetchAllAssoc('txn_id', PDO::FETCH_ASSOC);
    $txl = [];
    foreach ($tx_list as $tx)
      $txl[] = $tx['txn_id'];
    sort($txl); sort($txs);
    $diff = array_diff($txl, $txs);
    $missing = implode('%2C+', $diff);
    $output .= l('Missing transactions', 'http://emh.box.local/adminer.php?username=root&db=emh&select=emh_points_txn&where%5B0%5D%5Bcol%5D=txn_id&where%5B0%5D%5Bop%5D=IN&where%5B0%5D%5Bval%5D='.$missing);
    $output .= '<br>';
    drupal_set_message("Missing transactions (should all be either on user 1, either node expiration) $tcount - $tc + $dc =" . ($tcount + $dc - $tc));
  }
  else drupal_set_message('All transactions checked');
  if (count($rows) > 0)
    $output .= theme('table', array('header' => $header, 'rows' => $rows));
  else {
    drupal_set_message('Everything OK ! Good job.');
  }
  return $output;
}
