<?php
/**
 * @file
 * Feeds integration for Addressfield Phone module.
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see FeedsNodeProcessor::getMappingTargets().
 */
function addressfield_phone_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {

  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);
    if ($info['type'] == 'addressfield') {
      $targets[$name . ':phone_number'] = array(
        'name' => $instance['label'] . ': Phone',
        'callback' => 'addressfield_phone_feeds_set_target',
        'description' => t('The Phone field of the address.'),
      );
      $targets[$name . ':phone_number_extension'] = array(
        'name' => $instance['label'] . ': Phone Extension',
        'callback' => 'addressfield_phone_feeds_set_target',
        'description' => t('The Phone Extension field of the address.'),
      );
      $targets[$name . ':mobile_number'] = array(
        'name' => $instance['label'] . ': Mobile Number',
        'callback' => 'addressfield_phone_feeds_set_target',
        'description' => t('The Mobile Number field of the address.'),
      );
      $targets[$name . ':fax_number'] = array(
        'name' => $instance['label'] . ': Fax Number',
        'callback' => 'addressfield_phone_feeds_set_target',
        'description' => t('The Fax Number field of the address.'),
      );
    }
  }
}

/**
 * Callback for mapping. Here is where the actual mapping happens.
 *
 * When the callback is invoked, $target contains the name of the field the
 * user has decided to map to and $value contains the value of the feed item
 * element the user has picked as a source.
 */
function addressfield_phone_feeds_set_target($source, $entity, $target, $value) {
 list($field_name, $sub_field) = explode(':', $target, 2);

  // If the field is already set on the given entity, update the existing value
  // array. Otherwise start with a fresh field value array.
  $field = isset($entity->$field_name) ? $entity->$field_name : array();

  if (isset($field[LANGUAGE_NONE][0]['data'])) {
      $data = unserialize($field[LANGUAGE_NONE][0]['data']);
  }
  $data[$sub_field] = $value;
  $field[LANGUAGE_NONE][0]['data'] = serialize($data);

  $entity->$field_name = $field;
}

