<?php
// $Id: mb_extra.admin.inc,v 1.1.2.2 2010/11/27 13:30:52 quiptime Exp $

/*
 * @file
 * Function file to administer the MB Extra module settings.
 */

/**
 * Provides the MB Extra settings form.
 */
function mb_extra_admin() {
  $module = 'mb_extra';
  $form = array();

  $description_tabs_destination = '<p>' . t('Use the node local task links with destination parameter.') . '</p>';
  $description_tabs_destination .= '<p>' . t('If activated the %overlay module is not available this feature.', array('%overlay' => t('Overlay'))) . '</p>';

  $form[$module]['tabs_destination'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content local tasks'),
    '#description' => $description_tabs_destination,
    '#collapsible' => false,
    '#collapsed' => false,
    '#tree' => true
  );
  $form[$module]['tabs_destination'][$module . '_destination_tabs'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable node tab links with destination parameter.'),
    '#default_value' => variable_get($module . '_destination_tabs', 0)
  );

  $form[$module]['confirm_cancel'] = array(
    '#type' => 'fieldset',
    '#title' => t('Confirm cancel'),
    '#description' => '<p>' . t('Alter the confirm form cancel link to display it as button.') . '</p>',
    '#collapsible' => false,
    '#collapsed' => false,
    '#tree' => true
  );
  $form[$module]['confirm_cancel'][$module . '_confirm_cancel'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display link as button'),
    '#default_value' => variable_get($module . '_confirm_cancel', 0)
  );

  $form['submit']['save'] = array(
    '#type' => 'submit',
    '#name' => 'save',
    '#value' => t('Save')
  );
  $form['submit']['reset'] = array(
    '#type' => 'submit',
    '#name' => 'reset',
    '#value' => t('Reset to defaults'),
  );

  return $form;
}

/**
 * Display the MB Extra settings form page.
 *
 * @return
 *   The complete HTML formatted administer page.
 */
function theme_mb_extra_admin($variables) {
  _mb_load_css('admin');

  $module = 'mb_extra';
  $output  = '';

  $form = drupal_get_form($module . '_admin');

  $output .= drupal_render($output);

  return $output;
}

/**
 * Save settings from admin form.
 */
function mb_extra_admin_submit($form, &$form_state) {
  $module = 'mb_extra';

  if ($form_state['clicked_button']['#id'] == 'edit-save') {
    variable_set($module . '_destination_tabs', $form_state['values']['tabs_destination'][$module . '_destination_tabs']);
    variable_set($module . '_confirm_cancel', $form_state['values']['confirm_cancel'][$module . '_confirm_cancel']);

    drupal_set_message(t('The %module settings have been saved.', array('%module' => t('More Buttons Extra'))), 'status');
  }
  elseif ($form_state['clicked_button']['#id'] == 'edit-reset') {
    $form_state['redirect'] = 'admin/config/mb/buttons/more-buttons-extra/reset';
  }
}

/**
 * Menu callback to define the confirm form output.
 *
 * @return
 *   The confirm form.
 */
function mb_extra_reset() {
  $question = t('Are you sure you want to reset all %module settings?', array('%module' => t('More Buttons Extra')));

  $information = '<p>' . t('This action disables the extra settings. This action cannot be undone.') . '</p>';

  return confirm_form(array(),
    $question,
    array('path' => 'admin/config/mb/buttons/more-buttons-extra', 'attributes' => array('class' => 'button')), $information,
    t('Reset'),
    t('Cancel')
  );
}

/**
 * Resave extras system variables of the MB Content module to reset the module extra settings.
 */
function mb_extra_reset_submit($form, &$form_state) {
  // Resave variables.
  variable_set('mb_extra_destination_tabs', 0);
  variable_set('mb_extra_confirm_cancel', 0);

  drupal_set_message(t('The %module settings have been set back.', array('%module' => t('More Buttons Extra'))), 'status');
  watchdog('More Buttons Extra', 'The %module settings have been set back.', array('%module' => t('More Buttons Extra')), WATCHDOG_NOTICE, l(t('view'), 'admin/config/mb/buttons/more-buttons-extra'));

  $form_state['redirect'] = 'admin/config/mb/buttons/more-buttons-extra';
}
