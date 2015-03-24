<?php
// $Id: mb_content.admin.inc,v 1.1.2.2 2010/11/28 12:01:27 quiptime Exp $

/*
 * @file
 * Function file to administer the MB Content module settings.
 */

/**
 * Provides the central MB Content settings form.
 */
function mb_content_admin() {
  $module = 'mb_content';
  $mb_content_mappings = mb_get_mappings($module);

  $form['#mappings'] = $mb_content_mappings;

  foreach ($mb_content_mappings as $type => $v) {
    // It makes no sense to use the MB Content module with the content type panel.
    if ($type == 'panel') {
      continue;
    }

    // Provide "Cancel" button setting.
    $form[$module][$type][$module . '_cancel_' . $type] = array(
      '#type' => 'select',
      '#options' => mb_cancel_button_positions(),
      '#default_value' => variable_get($module . '_cancel_' . $type, 0),
    );
    // Provide "Save and continue" button setting.
    $form[$module][$type][$module . '_sac_' . $type] = array(
      '#type' => 'select',
      '#options' => mb_save_button_positions($module),
      '#default_value' => variable_get($module . '_sac_' . $type, 0)
    );
    // Provide the "Create new" setting.
    $form[$module][$type][$module . '_tabcn_' . $type] = array(
      '#type' => 'select',
      '#options' => mb_create_new_options(),
      '#default_value' => variable_get($module . '_tabcn_' . $type, 0)
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
 * Display a central MB Content settings form page.
 *
 * @return
 *   The complete HTML formatted administer page.
 */
function theme_mb_content_admin($variables) {
  _mb_load_css('admin');

  $module = 'mb_content';
  $mappings = array();
  $output  = '';
  $extra_info = '';
  $rows = array();

  $form = drupal_get_form($module . '_admin');
  $mappings = $form['#mappings'];

  $output  = '<h3>' . t('Content settings') . '</h3>';
  $output .= '<p>' . t('Which %module functions are used by different content type pages.', array('%module' => t('More Buttons Content'))) . '</p>';

  $header = array(t('Cancel'), t('Save and continue'), t('Create new'));

  $i = 1;
  foreach ($mappings as $type => $maps) {
    // It makes no sense to use the MB Content module with the content type panel.
    if ($type == 'panel') {
      // Define an additional information.
      $extra_info .= '<p>' . t('For the content type %type no settings can be made.', array('%type' => t($mappings['panel']['name']))) . '</p>';
      continue;
    }

    // Convert underscores in the machine redeable type names to hyphen for right path building.
    $parsed_type = str_replace('_', '-', $type);

    // Provide own odd/even functionality.
    $evenodd = $i % 2 ? 'odd-mb' : 'even-mb';
    $evenodd = $i & 1 ? 'odd-mb' : 'even-mb';

    $type_link = 'admin/structure/types/manage/' . $parsed_type;
    $link = l($maps['name'], $type_link, array('query' => array('destination' => 'admin/config/mb/buttons/more-buttons-content'), 'attributes' => array('title' => t('Edit this content type'))));

    // The content type row; Include an link to directly edit the MB Content settings in the content type.
    $rows[] = array('data' => array($link, array('colspan' => 3)), 'class' => array($evenodd . ' ' . $evenodd . '-type'));

    // The row contains the form elements.
    $rows[] = array(
      'data' => array(
        drupal_render($form[$module][$type][$module . '_cancel_' . $type]),
        drupal_render($form[$module][$type][$module . '_sac_' . $type]),
        drupal_render($form[$module][$type][$module . '_tabcn_' . $type])
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
function mb_content_admin_submit($form, &$form_state) {
  $module = 'mb_content';
  $mappings = $form['#mappings'];

  if ($form_state['clicked_button']['#id'] == 'edit-save') {
    // Save the MB Content button and tab settings.
    foreach ($mappings as $type => $maps) {
      if ($type == 'panel') {
        continue;
      }
      variable_set($module . '_cancel_' . $type, $form_state['values'][$module . '_cancel_' . $type]);
      variable_set($module . '_sac_' . $type, $form_state['values'][$module . '_sac_' . $type]);
      variable_set($module . '_tabcn_' . $type, $form_state['values'][$module . '_tabcn_' . $type]);
    }

    drupal_set_message(t('The %module settings have been saved.', array('%module' => t('More Buttons Content'))), 'status');
  }
  elseif ($form_state['clicked_button']['#id'] == 'edit-reset') {
    $form_state['redirect'] = 'admin/config/mb/buttons/more-buttons-content/reset';
  }
}

/**
 * Menu callback to define the confirm form output.
 *
 * @return
 *   The confirm form.
 */
function mb_content_reset() {
  $question = t('Are you sure you want to reset all %module settings?', array('%module' => t('More Buttons Content')));

  $information = '<p>' . t('This action disables the settings for all buttons and the tab. This action cannot be undone.') . '</p>';

  return confirm_form(array(),
    $question,
    array('path' => 'admin/config/mb/buttons/more-buttons-content', 'attributes' => array('class' => 'button')), $information,
    t('Reset'),
    t('Cancel')
  );
}

/**
 * Resave all system variables of the MB Content module to reset the module settings.
 */
function mb_content_reset_submit($form, &$form_state) {
  // Resave variables.
  $node_types = array_keys(node_type_get_types());
  foreach ($node_types as $type) {
    variable_set('mb_content_cancel_' . $type, 0);
    variable_set('mb_content_sac_' . $type, 0);
    variable_set('mb_content_tabcn_' . $type, 0);
  }

  drupal_set_message(t('The %module settings have been set back.', array('%module' => t('More Buttons Content'))), 'status');
  watchdog('More Buttons Content', 'The %module settings have been set back.', array('%module' => t('More Buttons Content')), WATCHDOG_NOTICE, l(t('view'), 'admin/config/mb/buttons/more-buttons-content'));

  $form_state['redirect'] = 'admin/config/mb/buttons/more-buttons-content';
}
