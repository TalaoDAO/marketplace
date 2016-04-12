<?php

/**
 * @file
 *   Admin configuration pages
 */

/**
 * The admin settings form
 */
function og_features_admin_settings($form, &$form_state) {
  // Fetch the feature registry
  $registry = og_features_get_registry();

  // If the registy is empty, there is nothing to configure
  if (empty($registry)) {
    return array(
      'empty' => array(
        '#type' => 'item',
        '#markup' => t('There are currently no features to configure.'),
      ),
    );
  }
  
  // Fetch all available group types
  $types = array();
  foreach (entity_get_info() as $entity_type => $entity_value) {
    foreach ($entity_value['bundles'] as $bundle => $bundle_value) {
      if (og_is_group_type($entity_type, $bundle)) {
        $types[$entity_type][$bundle] = check_plain($bundle_value['label']) . " ({$entity_type})";
      }
    }
  }
  
  // Make sure we have at least one group type
  if (empty($types)) {
    return array(
      'empty' => array(
        '#type' => 'item',
        '#markup' => t('There are currently no group types to configure.'),
      ),
    );
  }
  
  // Provide a configuration for each group
  foreach ($types as $entity_type => $bundle) {
    foreach ($bundle as $bundle_name => $bundle_label) {
      // Generate a key
      $key = "{$entity_type}--{$bundle_name}";
      // Build the fieldset for this node type
      $form[$key] = array(
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#title' => $bundle_label,
      );
    
      // Attempt to load the defaults for this entity type
      $defaults = og_features_get_entity_type_settings($entity_type, $bundle_name);
    
      foreach ($registry as $id => $feature) {
        $form[$key]["{$key}--{$id}"] = array(
          '#type' => 'radios',
          '#title' => $feature->name,
          '#description' => $feature->description,
          '#default_value' => isset($defaults[$id]) ? $defaults[$id] : OG_FEATURES_ADMIN_TOGGLE_ENABLED,
          '#options' => array(
            OG_FEATURES_ADMIN_TOGGLE_ENABLED => t('Toggle (Enabled by default)'),
            OG_FEATURES_ADMIN_TOGGLE_DISABLED => t('Toggle (Disabled by default)'),
            OG_FEATURES_ADMIN_ENABLED => t('Always enabled'),
            OG_FEATURES_ADMIN_DISABLED => t('Always disabled'),
          ),
        );
      }
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );
  
  return $form;
}

/**
 * Submit handler for the admin settings form
 */
function og_features_admin_settings_submit(&$form, &$form_state) {
  $types = array();

  // Iterate the form values
  foreach ($form_state['values'] as $key => $value) {
    // See if this is a value we are looking for
    if (strstr($key, '--')) {
      // Split the values
      list($entity_type, $bundle_name, $feature) = explode('--', $key);
      // Store the setting
      $types[$entity_type][$bundle_name][$feature] = $value;
    }
  }
  
  // Iterate over the group entity types
  foreach ($types as $entity_type => $bundles) {
    foreach ($bundles as $bundle => $settings) {
      // Save a variable for each
      variable_set("og_features_settings_{$entity_type}_{$bundle}", $settings);
    }
  }
  
  // Status message
  drupal_set_message(t('Your settings have been saved.'));
}
