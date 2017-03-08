<?php

/**
 * Settings form.
 */
function autodialog_settings_form($form, &$form_state) {
  $form['autodialog_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Paths'),
    '#description' => t('Paths which will work autodialog'),
    '#default_value' => variable_get('autodialog_paths'),
  );

  $form['autodialog_default_options'] = array(
    '#type' => 'textarea',
    '#title' => t('Default options'),
    '#description' => t('jQUery UI Dialog default options in JSON format. Example: <code>{"width":"auto", "resizable":false}</code>'),
    '#default_value' => variable_get('autodialog_default_options'),
  );

  $form['autodialog_source'] = array(
    '#type' => 'radios',
    '#title' => t('Dialog content source'),
    '#options' => array(
      'region' => t('Region "content"'),
      'block' => t('Block "system_main"'),
    ),
    '#default_value' => variable_get('autodialog_source', 'block'),
  );

  $form['autodialog_scrollfix'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fix scrolling'),
    '#description' => t('Attach plugin jquery.ui.dialog.scrollfix.js which fix body scroll. Require jQuery Update module with jQuery 1.7+ and jQuery UI 1.10.2.'),
    '#default_value' => variable_get('autodialog_scrollfix'),
  );

  return system_settings_form($form);
}
