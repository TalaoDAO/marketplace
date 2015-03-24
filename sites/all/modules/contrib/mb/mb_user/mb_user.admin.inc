<?php
// $Id: mb_user.admin.inc,v 1.1.2.1 2010/11/27 13:30:52 quiptime Exp $

/*
 * @file
 * Function file to administer the MB User module settings.
 */

/**
 * Provides the MB User settings form.
 */
function mb_user_admin() {
  $module = 'mb_user';

  $mb_user_mappings = mb_get_mappings($module);
  $mb_user_values = mb_get_values($module);

  $form['#mappings'] = $mb_user_mappings;

  foreach ($mb_user_mappings as $type => $v) {
    // Provide "Cancel" button settings.
    $form[$module][$type][$module . '_cancel_' . $type] = array(
      '#type' => 'select',
      '#options' => mb_cancel_button_positions(),
      '#default_value' => variable_get($module . '_cancel_' . $type, 0),
    );
    // Provide "Save and continue" button settings.
    $form[$module][$type][$module . '_sac_' . $type] = array(
      '#type' => 'select',
      '#options' => mb_save_button_positions($module),
      '#default_value' => variable_get($module . '_sac_' . $type, 0)
    );
    // Provide "Save and create new" button settings.
    $form[$module][$type][$module . '_sacn_' . $type] = array(
      '#type' => 'select',
      '#options' => mb_save_button_positions($module),
      '#default_value' => variable_get($module . '_sacn_' . $type, 0)
    );
  }

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
 * Display the MB User settings form page.
 *
 * @return
 *   The complete HTML formatted administer page.
 */
function theme_mb_user_admin($variables) {
  _mb_load_css('admin');

  $module = 'mb_user';
  $mappings = array();
  $output  = '';
  $extra_info = '';
  $rows = array();

  $form = drupal_get_form($module . '_admin');
  $mappings = $form['#mappings'];

  $output  = '<h3>' . t('User settings') . '</h3>';
  $output .= '<p>' . t('Which %module functions are used by different user pages.', array('%module' => t('More Buttons User'))) . '</p>';

  $header = array(t('Cancel'), t('Save and continue'), t('Save and create new'));

  $i = 1;
  foreach ($mappings as $type => $maps) {
    // Provide own odd/even functionality.
    $evenodd = $i % 2 ? 'odd-mb' : 'even-mb';
    $evenodd = $i & 1 ? 'odd-mb' : 'even-mb';

    $rows[] = array('data' => array($maps['name'], array('colspan' => 2)), 'class' => array($evenodd . ' ' . $evenodd . '-type'));

    // The row contains the form elements.
    $rows[] = array(
      'data' => array(
        drupal_render($form[$module][$type][$module . '_cancel_' . $type]),
        drupal_render($form[$module][$type][$module . '_sac_' . $type]),
        drupal_render($form[$module][$type][$module . '_sacn_' . $type])
      ),
      'class' => array($evenodd . ' ' . $evenodd . '-elements')
    );

    unset($form[$module][$type]);
    ++$i;
  }

  $output .= theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('class' => array('mb-admin-table', $module . '-admin-table'))
  ));

  // Display additional informations.
  if ($extra_info != '') {
    $output .= $extra_info;
  }

  $output .= drupal_render($output);
  $output .= drupal_render_children($form);
  $output .= '<p style="text-align: right">' . t('Module development by <a href="@development-url">Quiptime Group</a>.', array('@development-url' => url('http://www.quiptime.com'))) . '</p>';

  return $output;
}

/**
 * Save settings from admin form.
 */
function mb_user_admin_submit($form, &$form_state) {
  $module = 'mb_user';
  $mappings = $form['#mappings'];

  if ($form_state['clicked_button']['#id'] == 'edit-save') {
    // Save the MB User button settings.
    foreach ($mappings as $type => $maps) {
      variable_set($module . '_cancel_' . $type, $form_state['values'][$module . '_cancel_' . $type]);
      variable_set($module . '_sac_' . $type, $form_state['values'][$module . '_sac_' . $type]);
      variable_set($module . '_sacn_' . $type, $form_state['values'][$module . '_sacn_' . $type]);
    }

    drupal_set_message(t('Your changes have been saved.'), 'status');
  }
  elseif ($form_state['clicked_button']['#id'] == 'edit-reset') {
    $form_state['redirect'] = 'admin/config/mb/buttons/more-buttons-user/reset';
  }
}

/**
 * Menu callback to define the confirm form output.
 *
 * @return
 *   The confirm form.
 */
function mb_user_reset() {
  $question = t('Are you sure you want to reset all %module settings?', array('%module' => t('More Buttons User')));

  $information = '<p>' . t('This action disables the settings for all buttons. This action cannot be undone.') . '</p>';

  return confirm_form(array(),
    $question,
    array('path' => 'admin/config/mb/buttons/more-buttons-user', 'attributes' => array('class' => 'button')), $information,
    t('Reset'),
    t('Cancel')
  );
}

/**
 * Resave all system variables of the MB User module to reset the module settings.
 */
function mb_user_reset_submit($form, &$form_state) {
  // Resave variables.
  $page_types = array_keys(mb_user_type_get_types());

  foreach ($page_types as $type) {
    variable_set('mb_user_cancel_' . $type, 0);
    variable_set('mb_user_sac_' . $type, 0);
    variable_set('mb_user_sacn_' . $type, 0);
  }

  drupal_set_message(t('The %module settings have been set back.', array('%module' => t('More Buttons User'))), 'status');
  watchdog('More Buttons User', 'The %module settings have been set back.', array('%module' => t('More Buttons User')), WATCHDOG_NOTICE, l(t('view'), 'admin/config/mb/buttons/more-buttons-user'));

  $form_state['redirect'] = 'admin/config/mb/buttons/more-buttons-user';
}
