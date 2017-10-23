<?php

/**
 * @file
 * Provides utility functions for opencalais - mainly relating to adding and removing fields
 * Included into the main module file
 */

/**
 *  Add a field to a content_type - creates a taxonomy field
 *  @param content_type should be the string machine name of a content type
 *  @param field_name should be the string name of the field
 *  @param taxonomy_name should be the machine name of the taxonomy you want to add a linked field to
 *  Some settings cannot be specified through this function - this is really just a utility wrapper for the fields api
 */
function opencalais_add_field($content_type, $field_name, $taxonomy_name, $title, $description = '', $threshold = 0) {
  node_types_rebuild();

  //since opencalais fields are taxonomy term references
  $taxonomy_field = taxonomy_field_info();
  $taxonomy_widget = taxonomy_field_widget_info();

  $taxonomy_widget = key($taxonomy_widget);

  // Create all the fields we are adding to our content type.
  // http://api.drupal.org/api/function/field_create_field/7
  $field['field_name'] = strtolower(str_ireplace(' ', '_', $field_name));

  $field['type'] = key($taxonomy_field);
  $field['cardinality'] = FIELD_CARDINALITY_UNLIMITED;
  //limit to the proper taxonomy name
  $field['settings']['allowed_values'][0] = array(
    'vocabulary' => _opencalais_make_machine_name($taxonomy_name),
    'parent' => 0,
  );

  // Handle any fieldexceptions that occur by just setting and error message and returning.
  try{
    if (!field_read_field($field['field_name'], array('include_inactive' => TRUE))) {
      field_create_field($field);
    }
  } catch (FieldException $f) {
    drupal_set_message($f->getMessage(), 'error');
    return;
  }
  $instance = current($taxonomy_field);

  // Create all the instances for our fields.
  // http://api.drupal.org/api/function/field_create_instance/7
  $instance['field_name'] = $field['field_name'];
  $instance['title'] = $title ? $title : $field['field_name'];
  $instance['label'] = $title;
  $instance['description'] = $description;

  $instance['widget'] = array(
    'type' => $taxonomy_widget,
    'settings' => array(),
    'module' => 'taxonomy'
  );
  $instance['entity_type'] = 'node';
  $instance['bundle'] = $content_type;
  $instance['settings']['threshold'] = $threshold;
  
  // Flag so we can know which fields belong to this module.
  $instance['settings']['opencalais'] = _opencalais_make_machine_name($taxonomy_name); 

  // Handle any fieldexceptions that occur by just setting and error message and returning.
  try {
    if (!field_read_instance('node', $instance['field_name'], $content_type)) {
      field_create_instance($instance);
    }
    else {
      // If the field already exists then we should just update it
      field_update_instance($instance);
    }
  } catch (FieldException $f) {
    drupal_set_message($f->getMessage(), 'error');
    return;
  }
}

/**
 * Create a new vocabulary with the OpenCalais key as the machine name.
 */
function opencalais_create_vocabulary($entity) {
  $readable = opencalais_make_camel_case_readable($entity);
  $machine = _opencalais_make_machine_name($entity);
  $vocabulary = taxonomy_vocabulary_machine_name_load($machine);

  if (empty($vocabulary)) {
    $vocabulary = (object) array(
      'name' => $readable,
      'description' => t('Tags sourced from OpenCalais about @name.', array('@name' => $readable)),
      'machine_name' => $machine,
      'module' => 'opencalais',
    );
    taxonomy_vocabulary_save($vocabulary);

    //Try to persist vocabs even if their machine name changes.
    $vocabs = variable_get('opencalais_vocab_mapping', array());
    //map the vid to the machine name for easy lookup
    $vocabs[$vocabulary->vid] = $machine;
    variable_set('opencalais_vocab_mapping', $vocabs);


    /* Add extra fields for vocabularies that have disabiguation information associated
     * with them. We want to do this even for existing fields in case we add more fields
     * in the future ... that way there won't be an issue.
     */
    $extra = opencalais_get_extra_fields($entity);
    if ($extra) {

      $size = count($extra);
      for ($i = 0; $i < $size; $i++) {
        $e = $extra[$i];

        //we just need to add these as text fields for right now
        $text_field = text_field_info();

        // Create all the fields we are adding to our taxonomy term
        // http://api.drupal.org/api/function/field_create_field/7
        $field['field_name'] = strtolower(str_ireplace(' ', '_', $e));

        $field['type'] = 'text';
        $field['cardinality'] = 1;

        // Handle any fieldexceptions that occur by just setting and error message and returning.
        try {
          if (!field_read_field($e, array('include_inactive' => TRUE))) {
            field_create_field($field);
          }
        } catch (FieldException $f) {
          drupal_set_message(t('Error creating MetaData Field: ' . $f->getMessage()), 'error');
        }
        $instance = current($text_field);

        // Create all the instances for our fields.
        // http://api.drupal.org/api/function/field_create_instance/7
        $instance['field_name'] = $field['field_name'];
        $instance['title'] = $e;
        $instance['label'] = 'OpenCalais Metadata: ' . $e;
        $instance['description'] = $vocabulary->description;

        $instance['widget'] = array(
          'type' => 'text_textfield',
          'settings' => array(),
          'module' => 'text'
        );
        $instance['entity_type'] = 'taxonomy_term';
        $instance['bundle'] = $machine;
        // Handle any fieldexceptions that occur by just setting and error message and returning.
        // Other messaging isn't necessary and, quite frankly, confusing. So it has been removed.
        try {
          if (!field_read_instance('taxonomy_term', $instance['field_name'], $machine)) {
            field_create_instance($instance);
          }
          else {
            // If the field already exists then we should just update it
            field_update_instance($instance);
          }
        } catch (FieldException $f) {
          drupal_set_message(t('Error creating MetaData Field: ' . $f->getMessage()), 'error');
        }
      }
    }
  }
}

/**
 *  Returns an array of opencalais entities which already have a field on a given content type
 *  @param content_type - the machine name of the content type to find the fields for
 */
function opencalais_get_fields_for_content_type($content_type) {
  $fields = field_info_instances('node', $content_type);

  $entities = opencalais_get_all_entities();
  foreach ($entities as $key => $item) $entities[$key] = _opencalais_make_machine_name($item);
  $existing = array();

  //fields will be an empty array if no instances are found
  foreach ($fields as $field_name => $field) {
    if (isset($field['settings']['opencalais'])) {
      $opencalais_type = $field['settings']['opencalais'];
      $existing[$opencalais_type] = array('field' => $field_name, 'threshold' => $field['settings']['threshold']);
    }
  }

  return $existing;
}

/**
 *  Create all the fields for a content type
 *  All fields will be named 'opencalais_<vocab_name>_tags
 *  see opencalais_create_vocabulary for more information on machine name creation
 *
 *  @param content_type - the string name of the content type
 *  @param vocabs - an array of vocab names, if specified this will limit the vocabularies to those in the list
 */
function opencalais_create_fields($content_type, $vocabs = array(), $all = FALSE) {
  if (!$vocabs && $all) {
    $vocabs = opencalais_get_all_entities();
  }

  foreach ($vocabs as $vname => $vocab) {
    // add the field
    opencalais_create_vocabulary($vname);
    $name = substr($vname, 0, 15);
    opencalais_add_field($content_type, 'opencalais_' . $name . '_tags', $vname, $vname, '', $vocab['threshold']);
  }
}

/**
 *  Remove fields from a content type (actually removes instances)
 *  @param content_type - the string name of the content type
 *  @param vocabs - an array of vocab names to remove
 */
function opencalais_remove_fields($content_type, $fields) {
  foreach ($fields as $vname => $vocab) {
    $name = substr($vname, 0, 15);
    $instance['field_name'] = 'opencalais_' . $name . '_tags';
    $instance['bundle'] = $content_type;
    $instance['entity_type'] = 'node';
    field_delete_instance($instance);
  }
}

/**
 * A Utility function used to turn any (mainly CamelCase) string into a valid machine name
 */
function _opencalais_make_machine_name($name) {
  $name = str_replace(' ', '_', $name);
  $name = preg_replace('/([a-z])([A-Z])/', '$1_$2', $name);
  $name = strtolower($name);
  return $name;
}

/**
 * Just used to filter out disabled fields
 */
function _opencalais_filter($item) {
  return $item['enabled'];
}

/**
 * Get all the items to be deleted
 */
function _opencalais_delete_filter($item) {
  return !$item['enabled'] && $item['existing'];
}

/**
 *  Takes an array of suggestions and turns them into values appropriate for putting into a taxonomy autocomplete field
 */
function _opencalais_make_field_values($suggestions) {
  if (is_array($suggestions)) {
    return implode(',', array_keys($suggestions));
  }
  else {
    return '';
  }
}

/**
 * A Utility function to take a numericly keyed array and make it value => value for use
 * with forms api
 */
function _opencalais_make_keys(&$array) {
  $new_array = array();
  foreach ($array as $key => $value) {
    $new_array[$value] = $value;
  }
  $array = $new_array;
}

/**
 *  Utility Function to get all the content types
 */
function _opencalais_get_content_types() {
  $nodes = entity_get_info('node');
  return $nodes['bundles'];
}

/**
 *  Tests to see whether any opencalais fields exist on the node and have values
 *  Returns a boolean - does not modify node
 */
function _opencalais_already_tagged($node) {
  $fields = opencalais_get_fields_for_content_type($node->type);

  foreach ($fields as $label => $field) {
    $name = $field['field'];
    if (isset($node->{$name}) && $node->{$name}) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Save taxonomy terms for attaching to the node
 */
function _opencalais_create_term($term, $field, $node, $meta=array()) {
  $lang = $node->language;

  $vocabularies = array();
  foreach ($field['settings']['allowed_values'] as $tree) {
    if ($vocabulary = taxonomy_vocabulary_machine_name_load($tree['vocabulary'])) {
      $vocabularies[$vocabulary->vid] = $vocabulary;
    }
  }
  if ($possibilities = taxonomy_term_load_multiple(array(), array('name' => trim($term), 'vid' => array_keys($vocabularies)))) {
    $term = array_pop($possibilities);
  }
  else {
    $vocabulary = reset($vocabularies);
    $term = array(
      'tid' => 'autocreate',
      'vid' => $vocabulary->vid,
      'name' => $term,
      'vocabulary_machine_name' => $vocabulary->machine_name,
    );

    if (is_array($meta['extra'])) {
      $extra = $meta['extra'];
      foreach ($extra as $name => $value) {
        $term[$name] = array(
          $lang => array(
            array('value' => $value)
          )
        );
      }
    }
  }
  return (array) $term;
}

/**
 * Takes a 'CamelCase' word and adds spaces to make it 'Camel Case'
 *
 * @return an formated string
 */
function opencalais_make_camel_case_readable($camel_case) {
  return preg_replace('/(.*?[a-z]{1})([A-Z]{1}.*?)/', '${1} ${2}', $camel_case);
}
