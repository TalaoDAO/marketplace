<?php
/**
 * @file
 * Deprecated code of the eMindHub request feature.
 */

/**
 * Implements hook_node_access().
 */
function emh_request_node_access($node, $op, $account) {
  if ($op == 'update') {
    switch ($node->type) {
      case 'question1':
      case 'webform':
      case 'challenge':
        /*
        $count = emh_request_count_answers($node->nid);
        if ($count > 0) {
          return NODE_ACCESS_DENY;
        }
         */
        break;
      default:
        break;
    }
  }
  return NODE_ACCESS_IGNORE;
}

/**
 * Implements hook_form_alter().
 * node/add/type
 * node/$ID/edit
 */
function emh_request_form_node_form_alter(&$form, &$form_state, $form_id) {

  switch ($form['#node']->type) {

    case 'question1':
    case 'webform':
    case 'challenge':

      // Actions : Save as draft + Publish / Save
      $form['actions']['draft']['#value'] = t('Save draft');
      $form['actions']['submit']['#value'] = t('Publish');
      if ($form['type']['#value'] == 'webform' && !isset($form['#node']->nid)) {
        $form['actions']['draft']['#value'] = t('Save draft and continue');
      }
      // If nid not empty, we're in the edit page
      if ( !empty($form['nid']['#value']) && $form['#node']->status == NODE_PUBLISHED) {
        $form['actions']['draft']['#access'] = FALSE;
        $form['actions']['submit']['#value'] = t('Save');

        // If node is published on a free circle, we can close the request.
        $nid = $form['nid']['#value'];
        $status = emh_points_get_points_closed_status($nid);
        $circles = $form['#node']->og_group_ref[LANGUAGE_NONE];
        $free = TRUE;
        foreach($circles as $delta => $circle) {
          $loaded_circle = node_load($circle['target_id']); // TODO : PERF ISSUE : use node_load_all instead
          if ($loaded_circle->field_free_circle[LANGUAGE_NONE]['0']['value'] === '0') {
            // Paying circle
            $free = FALSE;
            break;
          }
        }
        if ($free && !$status) {
          $form['actions']['close'] = array(
            '#type' => 'submit',
            '#value' => 'Close the request',
            '#submit' => array('emh_request_form_node_close'),
          );
        }
      }

      // If node is published & there are some answers, only some updates are possible.
      // #575, 576
      $count = emh_request_count_answers($form['nid']['#value']);
      if ($form['#node']->status && $count > 0) {
        // Prevent domain & circle update.
        $form['field_domaine']['#disabled'] = TRUE;
        $form['field_request_circle']['#disabled'] = TRUE;
        $form['og_group_ref']['#disabled'] = TRUE;
      }

      // Hide node access
      $form['group_content_access']['#access'] =  FALSE;

      // Load only circles which user is member of
      global $user;
      $groups = og_get_groups_by_user($user, 'node');
      $user_groups = array();
      foreach ($groups as $group) {
        $node = node_load($group);
        $user_groups[$group] = $node->title;
      }
      $form['og_group_ref'][LANGUAGE_NONE]['#options'] = $user_groups;

      break;

    default:
      break;
  }

}

/**
 * Close callback for the form above.
 */
function emh_request_form_node_close(&$form, &$form_state) {
  $nid = $form['nid']['#value'];
  emh_points_close_node($nid);
  drupal_goto('node/' . $nid);
}

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
  $types = array( 'question1', 'webform', 'challenge' );
  return $types;
}

/**
 * Helper function to retrieve the status of a request.
 * draft / open / selection / closed
 */
function emh_request_get_status($nid) {

  if (empty($nid)) {
    $arg0 = arg(0);
    $arg1 = arg(1);
    $arg2 = arg(2);
    if ($arg0 == 'node' && empty($arg2)) {
      $node = node_load($arg1);
    }
  }
  $node = node_load($nid);
  $workflow = array();
  $today = '';
  $deadline = '';

  if ($node->status == 0) {
    $workflow = array( 'status' => 'draft', 'label' => t('Draft') );
  }
  else {
    if (!emh_points_get_points_closed_status($nid)) {
      $today = date('Y-m-d H:i:s');
      $items = field_get_items('node',$node,'field_expiration_date');
      $deadline = isset($items[0]['value']) ? $items[0]['value'] : '';
      $deadline = date('Y-m-d H:i:s', strtotime("$deadline +1 day"));
      if ($today < $deadline) {
        $workflow = array( 'status' => 'open', 'label' => t('Open') );
      }
      else {
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
function emh_request_count_answers($nid) {

  $node = node_load($nid);

	$count = 0;
  if (!empty($node)) {
    switch($node->type) {
    case 'webform':
      include_once(drupal_get_path('module', 'webform') . '/includes/webform.submissions.inc');
      $count = webform_get_submission_count($node->nid);
      break;
    case 'question1':
    case 'challenge':
      if (isset($node->comment_count)) $count = $node->comment_count;
      break;
    default:
      // Nothing to do.
      break;
    }
  }

	return $count;

}

/**
 * Helper function to check if node has points.
 */
function emh_request_has_points($nid) {
  $node = node_load($nid);
  if (!empty($node) && !empty($node->emh_points)) return TRUE;
}

/**
 * Implements hook_node_insert().
 */
function emh_request_node_insert($node) {
  if ($node->status == NODE_PUBLISHED) {
    emh_request_try_to_notify($node);
  }
}

/**
 * Implements hook_node_update().
 */
function emh_request_node_update($node) {
  if ($node->status == NODE_PUBLISHED && $node->original->status == NODE_NOT_PUBLISHED) {
    emh_request_try_to_notify($node);
  }
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
          || ($node->type == 'challenge' && user_access('challenge: comment on any challenge content', $user))
      )
      && !empty($user->field_notification_frequency[LANGUAGE_NONE]) && $user->field_notification_frequency[LANGUAGE_NONE][0]['tid'] == 48
    ) {
      // Check multidomains option
      // drush vset --yes emh_request_send_notification_email_all_domains FALSE
      $multidomains_option = variable_get('emh_request_send_notification_email_all_domains', 0);
      if ($multidomains_option == TRUE) {
        // Notify every expert within the Organic Group
        rules_invoke_event('emh_request_notify_new_request', $node, $user);
        continue;
      } else {
        foreach($user->field_domaine[LANGUAGE_NONE] as $delta => $term) {
          // If right domain && notification authorized.
          if (in_array($term['tid'], $domains)) {
            rules_invoke_event('emh_request_notify_new_request', $node, $user);
            continue;
          }
        }
      }
    }
  }
  // Webmaster copy
  // rules_invoke_event('emh_request_notify_webmaster_new_request', $node);
}
