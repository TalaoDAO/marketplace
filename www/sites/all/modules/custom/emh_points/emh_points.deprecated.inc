<?php

/**
 * @file
 * Deprecated code of the eMindHub points feature.
 */

const EMH_POINTS_TXN_CONTEXT_DEPRECATED = 'deprecated';

/**
 * Main repartition form.
 */
function emh_points_arrange_form($form, &$form_state, $points, $type_source, $id_source, $type_dest, $dests) {
  // Access control.
  global $user;
  switch ($type_source) {
    case 'user':
      if ($user->uid != $id_source) {
        drupal_access_denied();
        drupal_exit();
      }
      drupal_set_title(emh_points_format_entity($user));
      break;

    case 'node':
      $node = node_load($id_source);
      if (!user_access('execute emh_points_arrange_node_points')) {
        drupal_access_denied();
        drupal_exit();
      }
      if (empty($node) || ($user->uid != 1 && $user->uid != $node->uid)) {
        drupal_access_denied();
        drupal_exit();
      }
      // Free circle without credits.
      if ($points == 0) {
        // Just close the node and return it.
        emh_points_close_node($id_source);
        drupal_goto('node/' . $id_source);
      }
      drupal_set_title($node->title);
      break;

    default:
      drupal_access_denied();
      drupal_exit();
      break;
  }
  // @TODO : verify that users/nodes have enough credits.
  $form = array();
  $dests = explode(',', $dests);
  $default_points = floor($points / count($dests));
  $form['points'] = array(
    '#type' => 'value',
    '#default_value' => $points,
  );
  $form['type_source'] = array(
    '#type' => 'value',
    '#default_value' => $type_source,
  );
  $form['id_source'] = array(
    '#type' => 'value',
    '#default_value' => $id_source,
  );
  $form['type_dest'] = array(
    '#type' => 'value',
    '#default_value' => $type_dest,
  );
  foreach ($dests as $dest) {
    if (empty($dest)) {
      continue;
    }
    switch ($type_dest) {
      case 'node':
        $entity = node_load($dest);
        break;

      case 'user':
        $entity = user_load($dest);
        break;

      case 'comment':
        $entity = comment_load($dest);
        break;

      case 'webform_submission':
        module_load_include('inc', 'webform', 'includes/webform.submissions');
        $entity = webform_get_submission($id_source, $dest);
        break;

    }
    $form[$dest] = array(
      '#type' => 'fieldset',
      '#collapsible' => FALSE,
    );
    $form[$dest]['source'] = array(
      '#type' => 'markup',
      '#markup' => emh_points_format_entity($entity),
      '#prefix' => '<div class="answer-author">',
      '#suffix' => '</div>',
    );
    if (in_array($type_dest, array('comment', 'webform_submission'))) {
      $markup = emh_request_get_answer($entity, $type_dest);
      $form[$dest]['answer'] = array(
        '#type' => 'markup',
        '#markup' => $markup,
        '#prefix' => '<div class="answer">',
        '#suffix' => '</div>',
      );
    }
    if ($dest === end($dests)) {
      $default_points = $points - ($default_points * (count($dests) - 1));
    }
    $form[$dest]['dest_' . $dest] = array(
      '#type' => 'textfield',
      '#title' => t('Credits for @dest', array('@dest' => emh_points_format_entity($entity))),
      '#default_value' => $default_points,
      '#element_validate' => array('element_validate_integer_positive'),
    );
    // Free circle without credits.
    if ($points == 0) {
      $form[$dest]['dest_' . $dest]['#type'] = 'value';
    }
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Validate distribution'),
  );
  if ($type_source == 'node' && in_array($node->type, array(
    'challenge',
    'question1',
    'webform',
  ))) {
    // Free circle without credits.
    if ($points == 0) {
      $form['submit']['#value'] = t('Close the request');
    }
    else {
      $form['submit']['#value'] = t('Validate distribution and close the request');
      $form['baseline'] = array(
        '#markup' => '<p class="emh-title-baseline">' . t('Distribute <strong>@count credits</strong> to best experts', array('@count' => $points)) . '</p>',
        '#weight' => -100,
      );
    }
  }
  return $form;
}

/**
 * Validation callback to the form above.
 */
function emh_points_arrange_form_validate(&$form, &$form_state) {
  $points = $form_state['values']['points'];
  $total = 0;
  $elements = array();
  foreach ($form_state['values'] as $key => $value) {
    if (substr($key, 0, 5) == 'dest_') {
      $elements[] = $key;
      $total += $value;
    }
  }
  if ($points > $total) {
    form_set_error(implode('][', $elements), t('You should assign all the @points credits!', array('@points' => $points)));
  }
  if ($points < $total) {
    form_set_error(implode('][', $elements), t('Please distribute no more and no less than @points credits.', array('@points' => $points)));
  }
}

/**
 * Submit callback for the form above.
 */
function emh_points_arrange_form_submit(&$form, &$form_state) {
  switch ($form_state['values']['type_source']) {
    case 'node':
      $source = node_load($form_state['values']['id_source']);
      break;

    case 'user':
      $source = user_load($form_state['values']['id_source']);
      break;

  }
  foreach ($form_state['values'] as $key => $value) {
    if (substr($key, 0, 5) == 'dest_') {
      $id = substr($key, 5);
      switch ($form_state['values']['type_dest']) {
        case 'node':
          $dest = node_load($id);
          break;

        case 'user':
          $dest = user_load($id);
          break;

        case 'comment':
          $comment = comment_load($id);
          $dest = user_load($comment->uid);
          // Historise comment credits.
          db_insert('emh_points_answers')
            ->fields(array(
              'nid' => $comment->nid,
              'uid' => $comment->uid,
              'answer_id' => $id,
              'points' => $value,
            ))
            ->execute();
          if ($form_state['values']['type_source'] == 'node') {
            emh_points_notify_rewarded_answer_author($source, $dest, $value);
          }
          break;

        case 'webform_submission':
          module_load_include('inc', 'webform', 'includes/webform.submissions');
          $entity = webform_get_submission($form_state['values']['id_source'], $id);
          $dest = user_load($entity->uid);
          // Historise submission credits.
          db_insert('emh_points_answers')
            ->fields(array(
              'nid' => $entity->nid,
              'uid' => $entity->uid,
              'answer_id' => $id,
              'points' => $value,
            ))
            ->execute();
          if ($form_state['values']['type_source'] == 'node') {
            emh_points_notify_rewarded_answer_author($source, $dest, $value);
          }
          break;
      }
      emh_points_move_points($source, $dest, $value, EMH_POINTS_TXN_CONTEXT_DEPRECATED);
    }
  }
  switch ($form_state['values']['type_source']) {
    case 'node':
      // Credits have been distributed, we should close the request.
      emh_points_close_node($form_state['values']['id_source']);
      // And notify unrewarded answers.
      $unrewarded_answers = emh_points_get_unrewarded_answers($form_state['values']['id_source']);
      $node = node_load($form_state['values']['id_source']);
      foreach ($unrewarded_answers as $unrewarded_answer => $uid) {
        $author = user_load($uid);
        emh_points_notify_unrewarded_answer_author($node, $author);
      }
      $form_state['redirect'] = 'node/' . $form_state['values']['id_source'];
      break;

    case 'user':
    default:
      $form_state['redirect'] = '<front>';
      break;
  }
  if ($form_state['values']['type_source'] == 'node') {
    $node = node_load($form_state['values']['id_source']);
    $points = $form_state['values']['points'];
    // Free circle without credits.
    if ($points == 0) {
      drupal_set_message(t('Request @title has been closed.', array('@title' => $node->title)));
    }
    else {
      drupal_set_message(t('Request @title has been closed. All the credits have been distributed.', array('@title' => $node->title)));
    }
  }
  else {
    drupal_set_message(t('All the credits have been distributed.'));
  }
}

/**
 * Close a node if needed.
 */
function emh_points_close_node($nid) {
  $node = node_load($nid);
  if (!empty($node)) {
    switch ($node->type) {
      case 'webform':
        $node->webform['status'] = 0;
        node_save($node);
        break;

      case 'question1':
        $node->comment = COMMENT_NODE_CLOSED;
        node_save($node);
        break;

      case 'challenge':
        $node->comment = COMMENT_NODE_CLOSED;
        node_save($node);
        break;

      default:
        // Nothing to do.
        break;
    }
  }
}

/**
 * TODO: needs com.
 */
function emh_points_get_points_closed_status($nid) {
  $node = node_load($nid);
  if (!empty($node)) {
    switch ($node->type) {
      case 'webform':
        return ($node->webform['status'] == 0);

      case 'question1':
      case 'challenge':
        return ($node->comment == COMMENT_NODE_CLOSED);

      default:
        // Nothing to do.
        break;
    }
  }
}

/**
 * TODO: needs com.
 */
function emh_points_get_answers($nid) {
  $answers = array();
  $node = node_load($nid);
  if (!empty($node)) {
    switch ($node->type) {
      case 'webform':
        include_once drupal_get_path('module', 'webform') . '/includes/webform.submissions.inc';
        $submissions = webform_get_submissions($nid);
        if (!empty($submissions)) {
          foreach ($submissions as $submission) {
            $answers[$submission->sid] = $submission->uid;
          }
        }
        break;

      case 'question1':
      case 'challenge':
        $answers = db_select('comment', 'c')
                    ->condition('nid', $nid)
                    ->fields('c', array('cid'))
                    ->fields('c', array('uid'))
                    ->orderBy('cid', 'ASC')
                    ->execute()
                    ->fetchAllKeyed(0, 1);
        break;

      default:
        // Nothing to do.
        break;
    }
  }
  return $answers;
}

/**
 * Transfert credits to an entity.
 */
function emh_points_transfert_points(&$entity, $context) {
  global $user;
  $points = $context['points'];
  emh_points_move_points($user, $entity, $points, EMH_POINTS_TXN_CONTEXT_DEPRECATED);
}

/**
 * Arrange credits between users.
 */
function emh_points_arrange_points(&$entities, $context) {
  $points = $context['points'];
  $output = '';
  $type = 'user';
  foreach ($entities as $id => $entity) {
    if (!empty($entity->type)) {
      $type = 'node';
    }
    if (!empty($entity->cid)) {
      $type = 'comment';
    }
    if (!empty($entity->sid)) {
      $type = 'webform_submission';
    }
    $output .= $id;
    $output .= ',';
  }
  $output = substr($output, 0, -1);
  global $user;
  drupal_goto('arrange/' . $points . '/user/' . $user->uid . '/' . $type . '/' . $output);
}

/**
 * Arrange group credits between users.
 */
function emh_points_arrange_group_points(&$entities, $context) {
  $points = $context['points'];
  $group = arg(1);
  $output = '';
  $type = 'user';
  foreach ($entities as $id => $entity) {
    $output .= $id;
    $output .= ',';
  }
  $output = substr($output, 0, -1);
  drupal_goto('arrange/' . $points . '/node/' . $group . '/' . $type . '/' . $output);
}

/**
 * Arrange node credits between users.
 */
function emh_points_arrange_node_points(&$entities, $context) {
  $node = arg(1);
  $node = node_load($node);
  $output = '';
  $type = 'user';
  foreach ($entities as $id => $entity) {
    $output .= $id;
    $output .= ',';
    if (!empty($entity->cid)) {
      $type = 'comment';
    }
    if (!empty($entity->sid)) {
      $type = 'webform_submission';
    }
  }
  $output = substr($output, 0, -1);
  drupal_goto('arrange/' . $node->emh_points . '/node/' . $node->nid . '/' . $type . '/' . $output);
}

/**
 * Configuration form for transfering credits.
 */
function emh_points_transfert_points_form($settings, &$form_state) {
  $form = array();
  $form['points'] = array(
    '#type' => 'textfield',
    '#title' => t('Credits'),
    '#required' => TRUE,
    '#default_value' => '100',
    '#element_validate' => array('element_validate_integer_positive'),
  );
  return $form;
}

/**
 * Submit callback for the form above.
 */
function emh_points_transfert_points_submit($form, &$form_state) {
  $return = array();
  $return['points'] = $form_state['values']['points'];
  return $return;
}

/**
 * Configuration for arranging credits.
 */
function emh_points_arrange_points_form($settings, &$form_state) {
  $form = array();
  $form['points'] = array(
    '#type' => 'textfield',
    '#title' => t('Credits'),
    '#required' => TRUE,
    '#default_value' => '100',
    '#element_validate' => array('element_validate_integer_positive'),
  );
  return $form;
}

/**
 * Submit callback for the form above.
 */
function emh_points_arrange_points_submit($form, &$form_state) {
  $return = array();
  $return['points'] = $form_state['values']['points'];
  return $return;
}

/**
 * Configuration for arranging credits.
 */
function emh_points_arrange_group_points_form($settings, &$form_state) {
  $group = arg(1);
  $group = node_load($group);
  $form = array();
  $form['points'] = array(
    '#type' => 'textfield',
    '#title' => t('Credits'),
    '#required' => TRUE,
    '#default_value' => $group->emh_points,
    '#element_validate' => array('element_validate_integer_positive', 'emh_points_validate_group_points'),
  );
  return $form;
}

/**
 * Validate callback for the form above.
 */
function emh_points_validate_group_points($element, &$form_state, $form) {
  $points = $element['#value'];
  $group = arg(1);
  $group = node_load($group);
  if ((int) $points > (int) $group->emh_points) {
    form_error($element, t("You don't have enough credits (@points).", array('@points' => $group->emh_points)));
  }
}

/**
 * Submit callback for the form above.
 */
function emh_points_arrange_group_points_submit($form, &$form_state) {
  $return = array();
  $return['points'] = $form_state['values']['points'];
  return $return;
}
