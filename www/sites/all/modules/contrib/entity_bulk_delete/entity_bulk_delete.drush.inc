<?php

/**
 * @file
 * Drush integration for the Entity Bulk Delete module.
 */

/**
 * Implements hook_drush_command().
 */
function entity_bulk_delete_drush_command() {
  $items['entity-bulk-delete'] = array(
    'description' => dt("Bulk delete entities."),
    'aliases' => array('ebd'),
    'arguments' => array(
      'entity-type' => dt("The entity type."),
    ),
    'options' => array(
      'bundles' => dt('A comma-separated list of bundles.'),
      'limit' => dt('Limit on the number of items of each deletion process. Default is 25.'),
      'queue' => dt('Instead of deleting immediately, puts the entities in a deletion queue to be run later.'),
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'examples' => array(
      'drush entity-bulk-delete node' => dt('Deletes all nodes'),
      'drush entity-bulk-delete node --limit=50' => dt('Delete all nodes, 50 at a time'),
      'drush entity-bulk-delete node --bundles=article,page --queue' => dt('Queues all article and page nodes for deletion.'),
    ),
  );

  return $items;
}

/**
 * Command callback for drush entity-bulk-delete
 *
 * @param string $entity_type
 *   The entity type.
 */
function drush_entity_bulk_delete($entity_type) {
  $info = entity_get_info($entity_type);
  if (empty($info) || empty($info['base table']) || empty($info['entity keys']['id'])) {
    return drush_set_error('ENTITY_BULK_DELETE_INVALID_ENTITY_TYPE', dt("Invalid entity type @type.", array('@type' => $entity_type)));
  }

  $bundles = drush_get_option('bundles', '');
  $bundles = !empty($bundles) ? explode(',', $bundles) : array();
  if (!empty($bundles)) {
    if ($invalid_bundles = array_diff($bundles, array_keys($info['bundles']))) {
      return drush_set_error('ENTITY_BULK_DELETE_INVALID_BUNDLES', dt("Invalid bundles for entity type @type: @bundles", array('@type' => $entity_type, '@bundles' => implode(', ', $invalid_bundles))));
    }
  }

  $limit = (int) drush_get_option('limit', 25);
  $queue = (bool) drush_get_option('queue');
  $query = _entity_bulk_delete_query($entity_type, $bundles);
  $count_query = clone $query;
  $count = $count_query->count()->execute();

  if (empty($count)) {
    return dt("There are no possible @type entities to delete.", array('@type' => $entity_type));
  }
  else {
    if ($queue) {
      if (!drush_confirm(dt("You are about to queue @count @type entities for deletion. Are you sure?", array('@count' => $count, '@type' => $entity_type)))) {
        return drush_user_abort();
      }
    }
    else {
      if (!drush_confirm(dt("You are about to delete @count @type entities. Are you sure?", array('@count' => $count, '@type' => $entity_type)))) {
        return drush_user_abort();
      }
    }
  }

  $batch = array(
    'operations' => array(
      array('_entity_bulk_delete_batch', array($query, $limit, $queue)),
    ),
  );
  batch_set($batch);
  drush_backend_batch_process();

  if ($queue) {
    drush_log("Queued $count $entity_type entities for deletion.", 'success');
  }
  else {
    drush_log("Deleted $count $entity_type entities.", 'success');
  }
}

/**
 * Batch callback to bulk delete entities.
 *
 * @param EntityFieldQuery $query
 *   The EntityFieldQuery object to retrieve the entities to delete.
 * @param int $limit
 *   The amount of entities to delete at once.
 * @param bool $queue
 *   If TRUE will queue the entities for deletion. If FALSE will immediately
 *   delete the entities.
 * @param array $context
 *   The batch context.
 */
function _entity_bulk_delete_batch(EntityFieldQuery $query, $limit, $queue, &$context) {
  // Initialize context with progress information.
  if (!isset($context['sandbox']['last_entity_id'])) {
    $context['sandbox']['last_entity_id'] = 0;
  }

  $query->entityCondition('entity_id', $context['sandbox']['last_entity_id'], '>');
  $query->range(0, $limit * ($queue ? 50 : 10));
  $results = $query->execute();

  if (empty($results)) {
    $context['finished'] = TRUE;
    return;
  }

  foreach ($results as $entity_type => $entities) {
    $chunks = array_chunk(array_keys($results[$entity_type]), $limit);
    foreach ($chunks as $chunk) {
      entity_bulk_delete($entity_type, $chunk, $queue);
    }

    $context['sandbox']['last_entity_id'] = max(array_keys($results[$entity_type]));
  }

  $context['finished'] = FALSE;
}
