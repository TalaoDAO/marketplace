<?php

/**
 * @file
 * Log classes.
 */

/**
 * Log class.
 */
class Log extends Entity {

  /**
   * {@inheritdoc}
   */
  protected function defaultLabel() {
    if (!empty($this->name)) {
      return $this->name;
    }
    else {
      return 'Log';
    }
  }

  /**
   * {@inheritdoc}
   */
  protected function defaultUri() {
    return array('path' => 'log/' . $this->identifier());
  }

}

/**
 * Log controller class.
 */
class LogController extends EntityAPIController {

  /**
   * {@inheritdoc}
   */
  public function create(array $values = array()) {
    global $user;
    $values += array(
      'id' => NULL,
      'name' => '',
      'type' => '',
      'uid' => $user->uid,
      'timestamp' => REQUEST_TIME,
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
      'done' => FALSE,
    );
    return parent::create($values);
  }

  /**
   * {@inheritdoc}
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {

    // Set the changed timestamp when a log entity is saved.
    $entity->changed = REQUEST_TIME;
    return parent::save($entity, $transaction);
  }

}

/**
 * Log Type class.
 */
class LogType extends Entity {
  public $type;
  public $label;
  public $weight = 0;

  /**
   * {@inheritdoc}
   */
  public function __construct($values = array()) {
    parent::__construct($values, 'log_type');
  }

  /**
   * {@inheritdoc}
   */
  public function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }

}

/**
 * Log type controller class.
 */
class LogTypeController extends EntityAPIControllerExportable {

  /**
   * {@inheritdoc}
   */
  public function create(array $values = array()) {
    $values += array(
      'id' => NULL,
      'type' => '',
      'label' => '',
      'name_pattern' => '',
      'name_edit' => FALSE,
      'done' => FALSE,
    );
    return parent::create($values);
  }

}

/**
 * UI controller for Log Type.
 */
class LogTypeUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage log types.';
    return $items;
  }

}
