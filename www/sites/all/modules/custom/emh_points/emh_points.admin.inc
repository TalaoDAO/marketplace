<?php

/**
 * @file
 * Administration screens for EMH Credit management module.
 */

const EMH_POINTS_TXN_CONTEXT_ADMIN_MANAGE_USER = 'admin_manage_user';

/**
 * Admin form for EMH Credit management settings.
 */
function emh_points_admin_form() {
  $form = array();

  $form['emh_points_expiration'] = array(
    '#title' => t('Credits expiration default time'),
    '#type' => 'textfield',
    '#description' => t('Default expiration of the credit, expressed in PHP strtotime string, see !link', array('!link' => l('this link', 'http://php.net/manual/fr/datetime.formats.relative.php'))),
    '#default_value'=> variable_get('emh_points_expiration', '+ 1 year'),
  );

  $form = system_settings_form($form);
  $form['actions']['#weight'] = 1000;

  return $form;
}

/**
 * Main credit management form
 */
function emh_points_manage_form() {
  $entities = entity_get_info(NULL);
  $options = array();
  foreach($entities as $name => $entity) {
    $options[$name] = $entity['label'];
  }
  $form = array();
  $form['entity_type'] = array(
    '#title' => t('Entity type'),
    '#type' => 'select',
    '#options' => $options,
    '#chosen' => FALSE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Credit management form for users.
 */
function emh_points_manage_users_form() {
  $options = array();
  $query = db_select('users', 'u');
  $query->innerjoin('field_data_field_first_name', 'fn', 'fn.entity_id = u.uid');
  $query->innerjoin('field_data_field_last_name', 'ln', 'ln.entity_id = u.uid');
  $query->fields('u', array('uid', 'name'));
  $query->fields('fn', array('field_first_name_value'));
  $query->fields('ln', array('field_last_name_value'));
  $users = $query->execute();
  foreach($users as $user) {
    $options[$user->uid] = $user->field_first_name_value . ' ' . $user->field_last_name_value . ' (' . $user->name . ')';
  }
  $form = array();
  $form['uid'] = array(
    '#title' => t('Select user'),
    '#type' => 'select',
    '#options' => $options,
  );
  $form['points'] = array(
    '#title' => t('Credits'),
    '#type' => 'textfield',
    '#default_value' => '100',
  );
  $form['operation'] = array(
    '#title' => 'Operation',
    '#type' => 'select',
    '#options' => array(POINTS_ADDITION => POINTS_ADDITION, POINTS_REMOVAL => POINTS_REMOVAL),
    '#chosen' => FALSE,
  );
  $form['log'] = array(
    '#title' => t('Log message'),
    '#type' => 'textarea',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Validation callback for the form.
 */
function emh_points_manage_users_form_validate($form, $form_state) {
  $values = $form_state['values'];
  if (!is_numeric($values['points']) || (int)$values['points'] <= 0) {
    form_set_error('points', t('Credits should be a positive integer'));
  }
}

/**
 * Submit callback for the form.
 */
function emh_points_manage_users_form_submit($form, $form_state) {
  $values = $form_state['values'];
  $entity = new StdClass();
  $entity->id = $values['uid'];
  $entity->type = 'user';
  $entity->bundle = 'user';
  switch($values['operation']) {
  case POINTS_REMOVAL:
    emh_points_delete_points($entity, $values['points']);
    // Compute transaction.
    global $user;
    db_insert('emh_points_txn')
      ->fields(array(
        'uid' => $user->uid,
        'points'=> (int)$values['points'],
        'time_stamp' => REQUEST_TIME,
        'description' => $values['log'],
        'source_type' => 'user',
        'source_id' => 1,
        'dest_type' => $entity->type,
        'dest_id' => $entity->id,
        'operation' => POINTS_REMOVAL,
        'context' => EMH_POINTS_TXN_CONTEXT_ADMIN_MANAGE_USER,
      ))
      ->execute();
    break;
  case POINTS_ADDITION:
    emh_points_add_points($entity, $values['points']);
    // Create transaction.
    global $user;
    db_insert('emh_points_txn')
      ->fields(array(
        'uid' => $user->uid,
        'points'=> (int)$values['points'],
        'time_stamp' => REQUEST_TIME,
        'description' => $values['log'],
        'source_type' => 'user',
        'source_id' => 1,
        'dest_type' => $entity->type,
        'dest_id' => $entity->id,
        'operation' => POINTS_ADDITION,
        'context' => EMH_POINTS_TXN_CONTEXT_ADMIN_MANAGE_USER,
      ))
      ->execute();
    break;
  default: // Nothing to do.
    break;
  }
}

/**
 * Integrity check for credits.
 */
function emh_points_integrity_check() {
  // Global total
  $query = db_select('emh_points', 'p');
  $query->addExpression('SUM(p.points)');
  $sum_points = $query->execute()->fetchField();
  $query = db_select('emh_points_total', 'p');
  $query->addExpression('SUM(p.total_points)');
  $sum_total = $query->execute()->fetchField();
  if ($sum_points != $sum_total) {
    drupal_set_message(t('Totals are not equal : @count1 credits and @count2 total credits', array('@count1' => $sum_points, '@count2' => $sum_total)), 'error');
  } else {
    drupal_set_message(t('Everything checks out !'));
  }
  drupal_goto('admin/emindhub/credits');
}
