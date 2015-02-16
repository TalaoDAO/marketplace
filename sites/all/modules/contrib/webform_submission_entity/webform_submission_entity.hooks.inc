<?php
/**
 * @file
 * Hooks provided by this module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Acts on Webform Submissions being loaded from the database.
 *
 * This hook is invoked during Webform submission loading, which is handled by
 * entity_load(), via the EntityCRUDController.
 *
 * @param array $entities
 *   An array of Webform submission entities being loaded, keyed by id.
 *
 * @see hook_entity_load()
 */
function hook_webform_submission_entity_load(array $entities) {
  $result = db_query('SELECT pid, foo FROM {mytable} WHERE pid IN(:ids)', array(':ids' => array_keys($entities)));
  foreach ($result as $record) {
    $entities[$record->pid]->foo = $record->foo;
  }
}

/**
 * Responds when a Webform submission is inserted.
 *
 * This hook is invoked after the Webform submission is inserted into the database.
 *
 * @param WebformSubmissionEntity $entity
 *   The Webform submission that is being inserted.
 *
 * @see hook_entity_insert()
 */
function hook_webform_submission_entity_insert(WebformSubmissionEntity $entity) {
  db_insert('mytable')
    ->fields(array(
      'id' => entity_id('webform_submission_entity', $entity),
      'extra' => print_r($entity, TRUE),
    ))
    ->execute();
}

/**
 * Acts on a Webform submission being inserted or updated.
 *
 * This hook is invoked before the Webform submission is saved to the database.
 *
 * @param WebformSubmissionEntity $entity
 *   The Webform submission that is being inserted or updated.
 *
 * @see hook_entity_presave()
 */
function hook_webform_submission_entity_presave(WebformSubmissionEntity $entity) {
  $entity->name = 'foo';
}

/**
 * Responds to a Webform submission being updated.
 *
 * This hook is invoked after the Webform submission has been updated in the database.
 *
 * @param WebformSubmissionEntity $entity
 *   The Webform submission that is being updated.
 *
 * @see hook_entity_update()
 */
function hook_webform_submission_entity_update(WebformSubmissionEntity $entity) {
  db_update('mytable')
    ->fields(array('extra' => print_r($entity, TRUE)))
    ->condition('id', entity_id('webform_submission_entity', $entity))
    ->execute();
}

/**
 * Responds to Webform submission deletion.
 *
 * This hook is invoked after the Webform submission has been removed from the database.
 *
 * @param WebformSubmissionEntity $entity
 *   The Webform submission that is being deleted.
 *
 * @see hook_entity_delete()
 */
function hook_webform_submission_entity_delete(WebformSubmissionEntity $entity) {
  db_delete('mytable')
    ->condition('pid', entity_id('webform_submission_entity', $entity))
    ->execute();
}

/**
 * @}
 */