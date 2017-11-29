<?php
/**
 * @file
 * Class definition of LogProcessor.
 */

/**
 * Creates logs from feed items.
 */
class LogProcessor extends FeedsProcessor {

  /**
   * Define entity type.
   */
  public function entityType() {
    return 'log';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Logs');
    return $info;
  }

  /**
   * Creates a new log in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {

    // If an author is not defined, set the author to the current user.
    $uid = $this->config['author'];
    global $user;
    if (empty($uid) && !empty($user->uid)) {
      $uid = $user->uid;
    }

    // Assemble and return the entity.
    $values = array(
      'type' => $this->bundle(),
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
      'uid' => $uid,
      'is_new' => TRUE,
    );
    return entity_create('log', $values);
  }

  /**
   * Loads an existing log.
   *
   * If the update existing method is not FEEDS_UPDATE_EXISTING, only the
   * log table will be loaded, foregoing the log_load API for
   * better performance.
   */
  protected function entityLoad(FeedsSource $source, $id) {
    $log = parent::entityLoad($source, $id);

    if ($this->config['update_existing'] != FEEDS_UPDATE_EXISTING) {
      $log->uid = $this->config['author'];
    }

    return $log;
  }

  /**
   * Check that the user has permission to save a log.
   */
  protected function entitySaveAccess($entity) {

    // The check will be skipped for anonymous logs.
    if ($this->config['authorize'] && !empty($entity->uid)) {

      $author = user_load($entity->uid);

      // If the uid was mapped directly, rather than by email or username, it
      // could be invalid.
      if (!$author) {
        $message = 'User %uid is not a valid user.';
        throw new FeedsAccessException(t($message, array('%uid' => $entity->uid)));
      }

      if (empty($entity->id) || !empty($entity->is_new)) {
        $op = 'create';
        $access = log_access($op, $entity->type, $author);
      }
      else {
        $op = 'update';
        $access = log_access($op, $entity, $author);
      }

      if (!$access) {
        $message = t('The user %name is not authorized to %op logs of type %content_type. To import this item, either the user "@name" (author of the item) must be given the permission to @op logs of type @content_type, or the option "Authorize" on the log processor settings must be turned off.', array(
          '%name' => $author->name,
          '%op' => $op,
          '%content_type' => $entity->type,
          '@name' => $author->name,
          '@op' => $op,
          '@content_type' => $entity->type,
        ));
        throw new FeedsAccessException($message);
      }
    }
  }

  /**
   * Validates a log.
   */
  protected function entityValidate($entity) {
    parent::entityValidate($entity);

    if (!isset($entity->uid) || !is_numeric($entity->uid)) {
      $entity->uid = $this->config['author'];
    }
  }

  /**
   * Save a log.
   */
  public function entitySave($entity) {
    log_save($entity);
  }

  /**
   * Delete a series of logs.
   */
  protected function entityDeleteMultiple($ids) {
    log_delete_multiple($ids);
  }

  /**
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
        'author' => 0,
        'authorize' => TRUE,
      ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);

    $author = user_load($this->config['author']);
    $form['author'] = array(
      '#type' => 'textfield',
      '#title' => t('Author'),
      '#description' => t('Select the author of the logs to be created. If this is left empty, they will be assigned to the user running the import, or "anonymous" in the case of automated imports.'),
      '#autocomplete_path' => 'user/autocomplete',
      '#default_value' => empty($author->name) ?  '' : check_plain($author->name),
    );
    $form['authorize'] = array(
      '#type' => 'checkbox',
      '#title' => t('Authorize'),
      '#description' => t('Check that the author has permission to create the log.'),
      '#default_value' => $this->config['authorize'],
    );
    return $form;
  }

  /**
   * Override parent::configFormValidate().
   */
  public function configFormValidate(&$values) {
    if ($author = user_load_by_name($values['author'])) {
      $values['author'] = $author->uid;
    }
    else {
      $values['author'] = 0;
    }
  }

  /**
   * Override setTargetElement to operate on a target item that is a log.
   */
  public function setTargetElement(FeedsSource $source, $target_log, $target_element, $value) {
    switch ($target_element) {
      case 'created':
        $target_log->created = feeds_to_unixtime($value, REQUEST_TIME);
        break;
      case 'changed':
        // The 'changed' value will be set on the log in log_entity_presave().
        // This is because log_save() always overwrites this value (though
        // before invoking hook_entity_presave()).
        $target_log->feeds_item->log_changed = feeds_to_unixtime($value, REQUEST_TIME);
        break;
      case 'user_name':
        if ($user = user_load_by_name($value)) {
          $target_log->uid = $user->uid;
        }
        break;
      case 'user_mail':
        if ($user = user_load_by_mail($value)) {
          $target_log->uid = $user->uid;
        }
        break;
      default:
        parent::setTargetElement($source, $target_log, $target_element, $value);
        break;
    }
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    $targets = parent::getMappingTargets();
    $targets['id'] = array(
      'name' => t('Log ID'),
      'description' => t('The id of the log. NOTE: use this feature with care, log ids are usually assigned by Drupal.'),
      'optional_unique' => TRUE,
    );
    $targets['name'] = array(
      'name' => t('Name'),
      'description' => t('The name of the log.'),
    );
    $targets['timestamp'] = array(
      'name' => t('Timestamp'),
      'description' => t('The UNIX time that represents when the log occurred.'),
    );
    $targets['uid'] = array(
      'name' => t('Author user ID'),
      'description' => t('The user ID of the log author.'),
    );
    $targets['user_name'] = array(
      'name' => t('Author username'),
      'description' => t('The username of the log author.'),
    );
    $targets['user_mail'] = array(
      'name' => t('Author user email'),
      'description' => t('The email address of the log author.'),
    );
    $targets['created'] = array(
      'name' => t('Created date'),
      'description' => t('The UNIX time when a log has been created.'),
    );
    $targets['changed'] = array(
      'name' => t('Updated date'),
      'description' => t('The Unix timestamp when a log has been last updated.'),
    );
    $targets['done'] = array(
      'name' => t('Done'),
      'description' => t('Whether a log is done or not. 1 stands for done, 0 for not done.'),
    );

    $this->getHookTargets($targets);

    return $targets;
  }

  /**
   * Get id of an existing feed item log if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($id = parent::existingEntityId($source, $result)) {
      return $id;
    }

    // Iterate through all unique targets and test whether they do already
    // exist in the database.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      switch ($target) {
        case 'id':
          $id = db_query("SELECT id FROM {log} WHERE id = :id", array(':id' => $value))->fetchField();
          break;
      }
      if (!empty($id)) {
        // Return with the first id found.
        return $id;
      }
    }
    return 0;
  }

}
