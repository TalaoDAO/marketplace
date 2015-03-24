<?php
// $Id: mb.admin.inc,v 1.1.2.1 2010/11/27 13:30:52 quiptime Exp $

/*
 * @file
 * Function file to administer the MB module settings.
 */

/**
 * Provides the MB button values settings form.
 */
function mb_admin() {
  $module = 'mb';
  $mb_default_values = mb_default_values($module);
  $mb_values = mb_get_values($module);

  // Provide customizable button and tab values.
  // Don't make default value strings translatable here!
  $form['values'] = array(
    '#type' => 'fieldset',
    '#title' => t('Button and tab values'),
    '#description' => t('Use your own names for the buttons and the tab. These names are translatable with the translation interface. Do not enter translated texts here.'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );
  $form['values'][$module . '_value_cancel'] = array(
    '#type' => 'textfield',
    '#title' => t('Cancel button'),
    '#size' => 20,
    '#maxlength' => 50,
    '#default_value' => isset($mb_values['cancel']) ? $mb_values['cancel'] : $mb_default_values['cancel'],
    '#required' => TRUE,
    '#prefix' => '<div class="' . $module . '-values-first, ' . $module . '-values-first">'
  );
  $form['values'][$module . '_value_sac'] = array(
    '#type' => 'textfield',
    '#title' => t('Save and continue button'),
    '#size' => 20,
    '#maxlength' => 50,
    '#default_value' => isset($mb_values['sac']) ? $mb_values['sac'] : $mb_default_values['sac'],
    '#required' => TRUE,
    '#suffix' => '</div>'
  );
  $form['values'][$module . '_value_sacn'] = array(
    '#type' => 'textfield',
    '#title' => t('Save and create new button'),
    '#size' => 20,
    '#maxlength' => 50,
    '#default_value' => isset($mb_values['sacn']) ? $mb_values['sacn'] : $mb_default_values['sacn'],
    '#required' => TRUE,
    '#prefix' => '<div class="' . $module . '-values-last, ' . $module . '-values-last">'
  );
  $form['values'][$module . '_value_tabcn'] = array(
    '#type' => 'textfield',
    '#title' => t('Create new tab'),
    '#description' => t('This tab are displayed in addition to the content %edit tab.', array('%edit' => t('Edit'))),
    '#size' => 20,
    '#maxlength' => 50,
    '#default_value' => isset($mb_values['tabcn']) ? $mb_values['tabcn'] : $mb_default_values['tabcn'],
    '#required' => TRUE,
    '#suffix' => '</div>'
  );

  $form['submit']['save'] = array(
    '#type' => 'submit',
    '#name' => 'save',
    '#value' => t('Save')
  );
  $form['submit']['reset'] = array(
    '#type' => 'submit',
    '#name' => 'reset',
    '#value' => t('Reset to defaults')
  );

  return $form;
}

/**
 * Display the MB button values settings form page.
 *
 * @return
 *   The complete HTML formatted administer page.
 */
function theme_mb_admin($variables) {
  $form = drupal_get_form('mb_admin');

  $output = drupal_render($output);
  $output .= drupal_render_children($form);

  $output .= '<p style="text-align: right">' . t('Module development by <a href="@development-url">Quiptime Group</a>.', array('@development-url' => url('http://www.quiptime.com'))) . '</p>';

  return $output;
}

/**
 * Save settings from the admin form.
 */
function mb_admin_submit($form, &$form_state) {
  $module = 'mb';
  $mb_values = array();

  $mb_default_values = mb_default_values($module);

  if ($form_state['clicked_button']['#id'] == 'edit-save') {
    // Save the MB button value settings.
    // Don't make value strings translatable here!
    $mb_values = array(
      'cancel' => isset($form_state['values'][$module . '_value_cancel']) ? trim($form_state['values'][$module . '_value_cancel']) : $mb_default_values['cancel'],
      'sac' => isset($form_state['values'][$module . '_value_sac']) ? trim($form_state['values'][$module . '_value_sac']) : $mb_default_values['sac'],
      'sacn' => isset($form_state['values'][$module . '_value_sacn']) ? trim($form_state['values'][$module . '_value_sacn']) : $mb_default_values['sacn'],
      'tabcn' => isset($form_state['values'][$module . '_value_tabcn']) ? trim($form_state['values'][$module . '_value_tabcn']) : $mb_default_values['tabcn']
    );
    variable_set($module . '_values', $mb_values);

    drupal_set_message(t('The %module settings have been saved.', array('%module' => t('More Buttons'))), 'status');
  }
  elseif ($form_state['clicked_button']['#id'] == 'edit-reset') {
    $form_state['redirect'] = 'admin/config/mb/buttons/reset';
  }
}

/**
 * Menu callback. Define the confirm form output.
 *
 * @return
 *   The confirm form.
 */
function mb_reset() {
  $question = t('Are you sure you want to reset all %module settings to their default values?', array('%module' => t('More Buttons')));

  $variables = array(
   'items' => mb_default_values('mb'),
   'title' => 'Default values'
  );
  
  $information = theme('item_list', $variables);
  $information .= '<p>' . t('This action cannot be undone.') . '</p>';

  return confirm_form(array(),
    $question,
    array('path' => 'admin/config/mb/buttons', 'attributes' => array('class' => 'button')), $information,
    t('Reset'),
    t('Cancel')
  );
}

/**
 * Resave all system variables with their default values to reset the module settings.
 */
function mb_reset_submit($form, &$form_state) {
  // Resave variables.
  $mb_default_values = mb_default_values('mb');
  variable_set('mb_values', $mb_default_values);

  drupal_set_message(t('The %module settings have been set back.', array('%module' => t('More Buttons'))), 'status');
  watchdog('More Buttons', 'The %module settings have been set back.', array('%module' => t('More Buttons')), WATCHDOG_NOTICE, l(t('view'), 'admin/config/mb/buttons'));

  $form_state['redirect'] = 'admin/config/mb/buttons';
}
