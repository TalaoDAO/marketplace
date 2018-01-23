<?php
/**
 * @file
 * Integrates with features.
 */

/**
 * Implements hook_features_api().
 */
function config_pages_features_api() {
  return array(
    'config_pages' => array(
      'name' => t('ConfigPages Data'),
      'default_hook' => 'config_pages_default_data',
      'default_file' => FEATURES_DEFAULTS_INCLUDED,
      'feature_source' => TRUE
    ),
  );
}

/**
 * Implements hook_features_export_options().
 */
function config_pages_features_export_options() {
  $options = array();

  // Load all configuration pages.
  $list = config_pages_load_entity('', NULL, TRUE);
  foreach ($list as $item) {
    $config_type = config_pages_get_types($item->type);
    if ($config_type) {
      $options[$item->type . '-' . $item->context] = $config_type->label . ' (' . config_pages_context_label($item->context) . ')';
    }
  }
  return $options;
}

/**
 * Implements hook_features_export().
 */
function config_pages_features_export($data, &$export, $module_name = '') {
  $args = func_get_args();
  $pipe = array();

  $export['dependencies']['features'] = 'features';


  foreach ($data as $name) {

    // Add config_types to dependencies pipe.
    $type_name = current(explode('-', $name));
    $type = config_pages_get_types($type_name);
    $pipe['config_pages_type'][] = $type_name;

    // Add config to feature.
    $export['features']['config_pages'][$name] = $name;
  }
  return $pipe;
}

/**
 * Extract_fields from given entity.
 */
function _config_pages_features_export_data($entity_type, $bundle, $entity) {

  // Convert to array.
  $entity = get_object_vars($entity);

  // Build list of supported fields.
  $allowed_modules = variable_get('config_pages_features_allowed_modules', array('text', 'number', 'list', 'link'));
  $allowed_fields = variable_get('config_pages_features_allowed_fields', array('context', 'data', 'type', 'link_field'));
  $fields = field_info_instances($entity_type, $bundle);

  foreach ($fields as $field_name => $field_data) {
    if (in_array($field_data['widget']['module'], $allowed_modules)) {
      $allowed_fields[] = $field_name;
    }
  }

  // Export only allowed fields.
  $export = array();
  foreach ($entity as $key => $value) {
    // Field_collections have special treatement.
    if (!empty($fields[$key]) && ($fields[$key]['widget']['type'] == 'field_collection_embed') && !empty($value)) {
      // We do not support translation by design.
      $fc_key = 'field_collection_item:' . $key;
      foreach ($value[LANGUAGE_NONE] as $delta => $fcitem) {
        $field_collection_item = field_collection_item_load($fcitem['value']);
        if ($field_collection_item) {
          $export[$fc_key][$delta] = _config_pages_features_export_data('field_collection_item', $key, $field_collection_item);
        }
      }
    }
    elseif (in_array($key, $allowed_fields)) {
      $export[$key] = $value;
    }
  }

  // Sort for concistency.
  ksort($export);

  // Return allowed entity export fields.
  return $export;
}

/**
 * Implements hook_features_export_render().
 */
function config_pages_features_export_render($module, $data, $export = NULL) {
  $args = func_get_args();

  $code = array();
  $code[] = '  $config_pages = array();';
  $code[] = '';

  foreach ($data as $name) {
    $data = explode('-', $name);
    $type = array_shift($data);
    $context = implode('-', $data);
    if ($config = config_pages_load_entity($type, $context)) {
      $export = _config_pages_features_export_data('config_pages', $type, $config);

      // Allow other modules to add support for complex data.
      drupal_alter('config_pages_features_export', $export, $config);

      $config_export = features_var_export($export, '  ');
      $config_identifier = features_var_export($name);
      $code[] = "  // Exported format: {$name}.";
      $code[] = "  \$config_pages[{$config_identifier}] = {$config_export};";
      $code[] = "";
    }
  }

  $code[] = '  return $config_pages;';
  $code = implode("\n", $code);
  $result = array('config_pages_default_data' => $code);

  return $result;
}

/**
 * Implements hook_features_revert().
 */
function config_pages_features_revert($module) {
  return config_pages_features_rebuild($module);
}

/**
 * Update field collection field on an entity.
 */
function _config_pages_features_import_data($entity_type, $entity, $import) {

  // Replace old values with new ones.
  foreach ($import as $field => $value) {
    // Embeded field collections have special treatement.
    if (strpos($field, 'field_collection_item:') === 0) {
      $key = str_replace('field_collection_item:', '', $field);

      foreach ($value as $delta => $item) {
        $field_collection_item = NULL;
        // Load existing field collection.
        if (!empty($entity->{$key}[LANGUAGE_NONE][$delta])) {
          $field_collection_item = field_collection_item_load($entity->{$key}[LANGUAGE_NONE][$delta]['value']);
        }
        // Or create a fresh one.
        if (empty($field_collection_item)) {
          $field_collection_item = entity_create('field_collection_item', array('field_name' => $key));
          $field_collection_item->setHostEntity($entity_type, $entity);
          $entity->{$key}[LANGUAGE_NONE][$delta]['value'] = $field_collection_item->item_id;
          $entity->{$key}[LANGUAGE_NONE][$delta]['revision_id'] = $field_collection_item->revision_id;
        }
        $field_collection_item = _config_pages_features_import_data('field_collection_item', $field_collection_item, $item);
        $field_collection_item->save();
      }
    }
    else {
      $entity->{$field} = $value;
    }
  }

  return $entity;
}

/**
 * Implements hook_features_rebuild().
 */
function config_pages_features_rebuild($module) {

  // Load all defaults for this config.
  if ($defaults = features_get_default('config_pages', $module)) {
    foreach ($defaults as $key => $default) {
      $data = explode('-', $key);
      $type = array_shift($data);
      $context = implode('-', $data);

      // Prepare destination config.
      $config = config_pages_load_entity($type, $context);
      if (empty($config)) {
        $config = config_pages_create(array('type' => $type));
      }

      // Replace old values with new ones.
      $config = _config_pages_features_import_data('config_pages', $config, $default);

      // Allow other modules to add support for complex data.
      drupal_alter('config_pages_features_rebuild', $config, $default);

      // Update config.
      config_pages_save($config);
    }
  }
}
