<?php

/**
 * @file
 * Settings forms
 */

/**
 * Create settings form in drupal configuration setings section for module.
 */
function node_authored_select_admin_settings() {
  $roles = user_roles();
  $node_types = node_type_get_types();
  $options_nodes = array();
  foreach ($node_types as $node_type) {
    $options_nodes[$node_type->type] = $node_type->name;
  }

  $form['node_authored_select'] = array(
    '#type' => 'fieldset',
    '#title' => t('Node "Authored by" select Settings'),
    '#collapsible' => TRUE,
  );

  $form['node_authored_select']['node_authored_select_role'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Choose role'),
    '#default_value' => variable_get('node_authored_select_role', 3),
    '#options' => $roles,
  );

  $form['node_authored_select']['node_authored_select_node_type'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Choose node types'),
    '#default_value' => variable_get('node_authored_select_node_type', array()),
    '#options' => $options_nodes,
  );

  return system_settings_form($form, TRUE);
}
