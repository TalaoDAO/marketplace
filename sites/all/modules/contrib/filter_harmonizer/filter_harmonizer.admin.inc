<?php
/**
 * @file
 * filter_harmonizer.admin.module
 *
 * Configuration form for global and advanced filter harmonizer settings.
 */

/**
 * Menu callback for admin settings.
 */
function filter_harmonizer_admin_config() {
  $form['filter_harmonizer_settings_global'] = array(
    '#type' => 'fieldset',
    '#title' => t('Filter Harmonizer global settings'),
  );
  $form['filter_harmonizer_settings_global']['filter_harmonizer_always'] = array(
    '#type' => 'checkbox',
    '#title' => t('<em>After</em> initial page load, ignore <strong>any</strong> <em>contextual</em> filter that also has a companion <em>exposed</em> filter for the same field'),
    '#default_value' => variable_get('filter_harmonizer_always', FALSE),
    '#description' => t("If checked, the equivalent per-field check boxes on the contextual and exposed filter configuration pages <em>won't</em> appear for any field."),
  );
  $form['filter_harmonizer_settings_global']['filter_harmonizer_merge_filter_values'] = array(
    '#type' => 'checkbox',
    '#title' => t('At initial page load, merge contextual filter value(s) into the exposed filter'),
    '#default_value' => variable_get('filter_harmonizer_merge_filter_values', FALSE),
    '#description' => t('Applies only to exposed filters that have <strong>Allow multiple selections</strong> checked.'),
  );
  $form['filter_harmonizer_settings_global']['filter_harmonizer_fill_exposed'] = array(
    '#type' => 'checkbox',
    '#title' => t('At initial page load, auto-fill the exposed filter form with the contextual filter value(s) applied to the page'),
    '#default_value' => variable_get('filter_harmonizer_fill_exposed', TRUE),
    '#description' => t('While not affecting the filter behaviour itself, this is useful visual feedback as to what is happening.'),
  );
  return system_settings_form($form);
}
