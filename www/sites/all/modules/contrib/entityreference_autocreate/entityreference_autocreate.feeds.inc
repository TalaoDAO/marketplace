<?php

/**
 * @file
 * Feeds mapping implementation for the Entity reference module.
 *
 * OVERRIDE the one provided by entityreference to allow lookup by string title
 * and autocreate if new.
 *
 * Fully stolen from entityreference/entityreference.feeds.inc
 *
 * Not only is this available to feeds, but as raw_mapper also uses Feeds for
 * CRUD, it should work there too.
 *
 * This will only work if the field settings have the
 * "Autocreate target if not found" option seleted in the UI as well.
 */

/**
 * Announce that we know how to set data on an entityreference field.
 *
 * Given a list of target fields, find any entityreferences and attach
 * ourselves as a handler callback for setting values.
 *
 * If the entityreference widget settings have this option on already, that is.
 *
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see FeedsNodeProcessor::getMappingTargets()
 */
function entityreference_autocreate_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  // This only ever gets called when you visit the UI
  // admin/structure/feeds/{feed_name}/mapping
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $field_info = field_info_field($name);
    if ($field_info['type'] == 'entityreference') {
      // Check if the UI option is on also.
      if (empty($instance['widget']['settings']['entityreference_autocreate'])) {
        continue;
      }

      $targets[$name] = array(
        'name'        => t('!label by title lookup (creating if needed)', array('!label' => check_plain($instance['label']))),
        'callback'    => 'entityreference_autocreate_feeds_set_target',
        'description' => t('The field instance @label of @id', array(
          '@label' => $instance['label'],
          '@id'    => $name,
        )),
      );
    }
  }
}

/**
 * Entity reference callback for mapping.
 *
 * When the callback is invoked, $target contains the name of the field the
 * user has decided to map to and $value contains the value of the feed item
 * element the user has picked as a source.
 *
 * @param StdClass $source
 *   A FeedsSource object.
 * @param StdClass $entity
 *   The entity to map to.
 * @param string $target
 *   The target key on $entity to map to.
 * @param array $value
 *   The value to map. MUST be an array.
 * @param array $mapping
 *   Array of mapping settings for current value.
 * @param bool $input_format
 *   TRUE if an input format should be applied.
 */
function entityreference_autocreate_feeds_set_target($source, $entity, $target, $value, $mapping = array(), $input_format = FALSE) {

  // Don't do anything if we weren't given any data.
  if (empty($value)) {
    return;
  }

  // Assume that the passed in value could really be any number of values.
  if (is_array($value)) {
    $values = $value;
  }
  else {
    $values = array($value);
  }

  // Get some useful field information.
  $field_info = field_info_field($target);

  // Set the language of the field depending on the mapping.
  $language = isset($mapping['language']) ? $mapping['language'] : LANGUAGE_NONE;

  // Iterate over all values.
  $iterator = 0;
  // Re-use the existing field data if it's set.
  $field = isset($entity->$target) ? $entity->$target : array();

  foreach ($values as $value) {

    // Only process if this value was set for this instance.
    if ($value) {

      // Use the same processes that autocomplete would,
      // scan for a nid inside ()
      // or look for an exact text mach
      // or if not found, make one up.
      // Abort if more than one exact match was returned.
      //
      // If the widget is tags style, the title string may need exploding,
      // and we may create more than one entry.
      // ASSUME this may need to happen each time, as it's really hard to tell
      // if it really should. tags is a widget setting and we know nothing
      // about the widget.
      //
      $titles = drupal_explode_tags($value);
      // Will at least be an array of 1.
      foreach ($titles as $title) {
        if ($target_id = entityreference_autocreate_get_entity_by_title($field_info, $title)) {
          $field[$language][$iterator]['target_id'] = $target_id;
          $iterator++;
        }
        else {
          // Failed to create the target for some reason.
        }
      }

    }

    // Break out of the loop if this field is single-valued.
    if ($field_info['cardinality'] == 1) {
      break;
    }
  }
  // Add the field to the entity definition.
  $entity->{$target} = $field;

}
