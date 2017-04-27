<?php

/**
 * @file
 * Contains all the theme functions.
 */

/**
 * Returns HTML for the paramaters on the action form for mixpanel_rules_track.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: The element representing the name/value textfields.
 *
 * @ingroup themeable
 */
function theme_mixpanel_rules_track_parameter_form($variables) {
  $element = $variables['element'];
  $html = '';

  // Render the static parameters first.
  $html .= drupal_render($element['event']);
  $html .= drupal_render($element['account']);

  $help_html = drupal_render($element['property_01_value']['settings']['help']);

  // Loop through the properties, adding them to the table's $rows.
  $rows = array();
  for ($i = 1; $i <= MIXPANEL_RULES_PROPERTIES_MAX; $i++) {
    $base_name = sprintf('property_%02d', $i);

    $row = array();
    foreach (array('name', 'value') as $name) {
      // Clean-up the form elements so they fit nicer on the table.
      unset($element[$base_name . '_' . $name]['#type']);
      unset($element[$base_name . '_' . $name]['#title']);
      unset($element[$base_name . '_' . $name]['#theme_wrappers']);
      unset($element[$base_name . '_' . $name]['settings'][$base_name . '_value:select']['#description']);
      unset($element[$base_name . '_' . $name]['settings'][$base_name . '_name']['#title']);
      unset($element[$base_name . '_' . $name]['settings']['help']);
      unset($element[$base_name . '_' . $name]['settings']['types_help']);
      $row[] = drupal_render($element[$base_name . '_' . $name]);
    }

    $rows[] = $row;
  }

  // Render the table.
  $fieldset = array(
    '#type' => 'fieldset',
    '#title' => t('Properties'),
    '#description' => t("The name/value pairs that will be sent to Mixpanel as the event's properties."),
    'table' => array(
      '#markup' => theme('table', array(
        'header' => array(t('Name'), t('Value')),
        'rows' => $rows,
      )) . $help_html,
    ),
  );
  $html .= drupal_render($fieldset);

  // Render whatever is left over.
  $html .= drupal_render_children($element);

  return $html;
}
