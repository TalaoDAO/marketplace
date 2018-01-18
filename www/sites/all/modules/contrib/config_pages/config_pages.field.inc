<?php
/**
 * @file
 * Containt hooks and field API logic.
 */

/**
 * Implements hook_field_widget_info().
 */
function config_pages_field_widget_info() {
  $widgets['config_pages_config_page_select'] = array(
    'label' => t('Config Page Select'),
    'field types' => array('text'),
    'settings' => array(),
  );

  return $widgets;
}

/**
 * Implements hook_field_widget_settings_form().
 */
function config_pages_field_widget_settings_form($field, $instance) {
  $form = array();
  return $form;
}

/**
 * Implements hook_field_widget_form().
 */
function config_pages_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  if ($instance['widget']['type'] == 'config_pages_config_page_select') {


    // Generate bundle list.
    $entity = entity_get_info('config_pages');
    $bundle_options = array();
    foreach ($entity['bundles'] as $bundle => $option) {
      $bundle_options[$bundle] = $option['label'];
    }

    // Set deafult value.
    $value = isset($items[$delta]['value']) ? $items[$delta]['value'] : NULL;

    // Set field label.
    $title = isset($instance['label']) ? $instance['label'] : t('Config Page');

    $element['value'] = array(
      '#type' => 'select',
      '#title' => check_plain($title),
      '#options' => $bundle_options,
      '#default_value' => $value,
      '#required' => $instance['required'],
    );
    return $element;
  }
}
