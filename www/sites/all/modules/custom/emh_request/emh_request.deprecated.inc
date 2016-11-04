<?php
/**
 * @file
 * Deprecated code of the eMindHub request feature.
 */

/**
 * Implements hook_node_access().
 */
//function emh_request_node_access($node, $op, $account) {
//  if ($op == 'update') {
//    switch ($node->type) {
//      case 'question1':
//      case 'webform':
//      case 'challenge':
//        /*
//        $count = emh_request_count_answers($node->nid);
//        if ($count > 0) {
//          return NODE_ACCESS_DENY;
//        }
//         */
//        break;
//      default:
//        break;
//    }
//  }
//  return NODE_ACCESS_IGNORE;
//}


/**
 * Implements hook_block_info().
 */
function emh_request_block_info() {
  $blocks = array();

  $request_types = emh_request_get_types();
  foreach ($request_types as $type) {

    $blocks["request_help_$type"] = array(
      'info' => t("Add $type - Help"),
      'cache' => DRUPAL_CACHE_PER_ROLE,
      'weight' => -100,
      'status' => 1,
      'region' => 'sidebar_second',
      'visibility' => BLOCK_VISIBILITY_LISTED,
      'pages' => "node/add/$type",
    );

  }

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function emh_request_block_view($delta = '') {
  $block = array();

  $request_types = emh_request_get_types();
  foreach ($request_types as $type) {

    switch ($delta) {

      case 'request_help_' . $type:
        $data = variable_get("emh_block_request_help_$type", array('value' => '', 'format' => 'filtered_html'));
        $block = array(
          'subject' => '<none>',
          'content' => array(
            'text' => array(
              '#markup' => check_markup($data['value'], $data['format']),
            ),
          ),
        );
        break;
    }

  }

  return $block;
}

/**
 * Implements hook_block_configure().
 */
function emh_request_block_configure($delta='') {
  $form = array();

  $request_types = emh_request_get_types();
  foreach ($request_types as $type) {

    switch($delta) {
      case 'request_help_' . $type:

        $data = variable_get("emh_block_request_help_$type", array('value' => '', 'format' => 'filtered_html'));
        $form['text'] = array(
          '#type' => 'text_format',
          '#title' => t('Block text'),
          '#default_value' => $data['value'],
          '#format' => $data['format'],
        );
        break;
    }

  }

  return $form;
}

/**
 * Implements hook_block_save().
 */
function emh_request_block_save($delta = '', $edit = array()) {
  $request_types = emh_request_get_types();
  foreach ($request_types as $type) {

    switch($delta) {
      case 'request_help_' . $type:
        variable_set("emh_block_request_help_$type", $edit['text']);
        break;

    }
  }
}


/**
 * Implements hook_views_api().
 */
function emh_request_views_api() {
  return array(
    'api' => 3,
    'path' => drupal_get_path('module', 'emh_request') . '/views',
  );
}


/**
 * Helper function to retrieve an answer, depending on the status.
 */
function emh_request_get_answer($entity, $type) {
  $output = '';

  switch ($type) {
    case 'comment':
      if (empty($entity->field_private_comment)) {
        // No status => body field.
        $output = $entity->comment_body[LANGUAGE_NONE]['0']['value'];
      } else {
        switch($entity->field_private_comment[LANGUAGE_NONE]['0']['value']) {
          case 0:
            $output = $entity->comment_body[LANGUAGE_NONE]['0']['value'];
            break;
          case 1:
            $output = $entity->field_private_comment_body[LANGUAGE_NONE]['0']['value'];
            break;
        }
      }
      break;
    case 'webform_submission':
      foreach ($entity->data as $answer) {
        $output .= $answer[0] . '&nbsp;';
      }
      break;
  }

  return strip_tags(views_trim_text(
    array(
      'max_length' => 100,
      'word_boundary' => TRUE,
      'ellipsis' => TRUE,
      'html' => TRUE,
    ),
    $output
  ));
}

/**
 * Helper function to retrieve the list of request types.
 */
function emh_request_get_types() {
  return array('request', 'question1', 'webform', 'challenge');
}

/**
 * Helper function to retrieve the status of a request.
 * draft / open / selection / closed
 */
function emh_request_get_status($node = null) {
  if ($node === null) {
    $node = menu_get_object();
  }
  elseif (is_numeric($node)) {
    $node = node_load($node);
  }

  $workflow = array();
  $today = '';
  $deadline = '';

  if ($node->status == 0) {
    $workflow = array( 'status' => 'draft', 'label' => t('Draft') );
  }
  else {
    if (!emh_points_get_points_closed_status($node->nid)) {
      $today = date('Y-m-d H:i:s');
      $items = field_get_items('node', $node, 'field_expiration_date');
      $deadline = isset($items[0]['value']) ? $items[0]['value'] : '';
      $deadline = date('Y-m-d H:i:s', strtotime("$deadline +1 day"));

      if ($today < $deadline) {
        $workflow = array( 'status' => 'open', 'label' => t('Open') );
      } else {
        $workflow = array( 'status' => 'selection', 'label' => t('Selection') );
      }
    }
    else {
      $workflow = array( 'status' => 'closed', 'label' => t('Closed') );
    }
  }

	return $workflow;
}

/**
 * Helper function to retrieve answers count.
 */
function emh_request_count_answers($node) {
  if (is_numeric($node)) {
    $node = node_load($node);
  }

	$count = 0;

  if (!empty($node)) {
    switch ($node->type) {
      case 'request':
      case 'webform':
        include_once(drupal_get_path('module', 'webform') . '/includes/webform.submissions.inc');
        $count = webform_get_submission_count($node->nid);
        break;

      case 'question1':
      case 'challenge':
        if (isset($node->comment_count)) {
          $count = $node->comment_count;
        }
        break;
    }
  }

	return $count;
}

/**
 * Helper function to check if node has credits.
 */
function emh_request_has_points($nid) {
  $node = node_load($nid);
  return (!empty($node) && !empty($node->emh_points));
}


/**
 * Helper function to notify people.
 */
function emh_request_try_to_notify($node) {
  // Validate pre-requisites.
  if (empty($node->field_domaine) || empty($node->og_group_ref)) {
    return;
  }
  // Get all user from groups.
  $users = array();
  $domains = array();
  $mails = array();
  foreach($node->og_group_ref[LANGUAGE_NONE] as $delta => $group) {
    $query = new EntityFieldQuery();
    $query
      ->entityCondition('entity_type', 'og_membership')
      ->propertyCondition('group_type', 'node', '=')
      ->propertyCondition('gid', $group['target_id'], '=')
      ->propertyCondition('entity_type', 'user', '=');
    $result = $query->execute();
    if (!empty($result['og_membership'])) {
      $og_memberships = og_membership_load_multiple(array_keys($result['og_membership']));
      foreach ($og_memberships as $og_membership) {
        $users[] = $og_membership->etid;
      }
    }
  }
  // Get all domains from node.
  foreach($node->field_domaine[LANGUAGE_NONE] as $delta => $term) {
    $domains[] = $term['tid'];
  }
  // Load users.
  $users = user_load_multiple($users);
  // For each user of each group, check domain.
  foreach($users as $user) {
    // If user has the right role(s) and wants to be notified.
    if (
      (
        ($node->type == 'question1' && user_access('question1: comment on any question1 content', $user))
          || ($node->type == 'webform' && user_access('edit own webform submissions', $user))
          || ($node->type == 'request' && user_access('edit own webform submissions', $user))
          || ($node->type == 'challenge' && user_access('challenge: comment on any challenge content', $user))
      )
      && !empty($user->field_notification_frequency[LANGUAGE_NONE]) && $user->field_notification_frequency[LANGUAGE_NONE][0]['tid'] == 48
    ) {
      $queue = DrupalQueue::get('emh_request_request_email_notification');
      $item = array('nid' => $node->nid, 'uid' => $user->uid);
      // Check multidomains option
      // drush vset --yes emh_request_send_notification_email_all_domains FALSE
      $multidomains_option = variable_get('emh_request_send_notification_email_all_domains', 0);
      if ($multidomains_option == TRUE) {
        // Notify every expert within the Organic Group
        $queue->createItem($item);
        continue;
      } else {
        foreach($user->field_domaine[LANGUAGE_NONE] as $delta => $term) {
          // If right domain && notification authorized.
          if (in_array($term['tid'], $domains)) {
            $queue->createItem($item);
            continue;
          }
        }
      }
    }
  }
  // Webmaster copy
  // rules_invoke_event('emh_request_notify_webmaster_new_request', $node);
}

/**
 * Implements hook_cron_queue_info()
 */
function emh_request_cron_queue_info() {
  $queues['emh_request_request_email_notification'] = array(
    'worker callback' => 'emh_request_queue_process',
    'time' => 30,
  );
  return $queues;
}

/**
 * Worker callback defined in hook_cron_queue_info()
 */
function emh_request_queue_process($item) {
  $node = node_load($item['nid']);
  $user = user_load($item['uid']);
  rules_invoke_event('emh_request_notify_new_request', $node, $user);
}
