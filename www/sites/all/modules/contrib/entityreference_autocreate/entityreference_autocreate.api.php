<?php
/**
 * @file
 * Hooks provided by the entityreference_autocreate module.
 */

/**
 * Allows modules to interact with the entity that is being created.
 *
 * Using this function it's also possible to support your own entities.
 *
 * @param object $entity
 *   The entity object. This could also be NULL if the entity type is not known.
 * @param array $field_info
 *   The field info of the entityreference field.
 * @param string $title
 *   The title / name of the new entity that needs te be created.
 */
function hook_entityreference_autocreate_new_entity_alter(&$entity, $field_info, $title) {
  // Make automatic entries owned by anonymous.
  $entity->uid = 0;
}
