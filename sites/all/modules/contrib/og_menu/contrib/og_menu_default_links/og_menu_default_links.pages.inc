<?php
/**
 * @file
 * Implements the administration interface for default links.
 */

/**
 * Form callback for OG Menu configuration.
 */
function og_menu_default_links_config_form($form, &$form_state) {
  drupal_set_title('OG Menu Default Links');

  $bundles = og_get_all_group_bundle();
  // Add a field for each bundle.
  if ($bundles) {
    foreach ($bundles as $entity_type => $entity_bundles) {
      foreach ($entity_bundles as $bundle => $bundle_label) {
        $group_type = strtolower('_' . $bundle);
        $form['og_menu_default_link_bundles']['og_menu_default_links_' . $entity_type . $group_type] = array(
          '#type' => 'textarea',
          '#title' => t("%bundle Bundle", array('%bundle' => $bundle_label)),
          '#default_value' => variable_get('og_menu_default_links_' . $entity_type . $group_type, FALSE),
          '#description' => t("These links will be added to automatically created OG Menus from %bundle groups. Enter one value per line, in the format 'label|path/to/page'.", array('%bundle' => $bundle_label)),
        );
      }
    }
  }

  if (module_exists('token')) {
    $form['token_help'] = array(
      '#title' => t('Replacement patterns'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#description' => t('Prefer raw-text replacements for text to avoid problems with HTML entities!'),
    );

    $form['token_help']['help'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('node'),
    );
  }

  return system_settings_form($form);
}

/**
 * Implements hook_form_validate().
 *
 * Validation of the patterns entered in the administration form above.
 */
function og_menu_default_links_config_form_validate(&$form, &$form_state) {
  foreach ($form_state['values'] as $field => $value) {
    if (preg_match('/^og_menu_default_links_(.*?)_(.*)/', $field, $matches)) {
      $links = og_menu_default_links_extract_links($value, TRUE);
      if (!is_array($links)) {
        form_set_error($field, t('The link (%link) did not match the pattern.', array('%link' => $links)));
      }
    }
  }
}
