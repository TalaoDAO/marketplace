<?php
/**
 * @file
 * This is where the administrative settings configuration is.
 */

/**
 * Creates page for configuring the administrative settings.
 */
function auditfiles_admin_settings($form, &$form_state) {
  $form['auditfiles_file_system_paths'] = array(
    '#type' => 'fieldset',
    '#title' => t('File system paths'),
    '#collapsible' => TRUE,
  );
  // Show the file system path select list.
  $file_system_paths = file_get_stream_wrappers();
  $options = array();
  foreach ($file_system_paths as $file_system_path_id => $file_system_path) {
    $options[$file_system_path_id] = $file_system_path['name'] . ': '
      . variable_get('file_' . $file_system_path_id . '_path', conf_path() . '/files')
      . ' (' . $file_system_path['description'] . ')';
  }
  $form['auditfiles_file_system_paths']['auditfiles_file_system_path'] = array(
    '#type' => 'select',
    '#title' => 'File system path',
    '#default_value' => variable_get('auditfiles_file_system_path', 'public'),
    '#options' => $options,
    '#description' => t('Select the file system path to use when searching for
      and comparing files.<br />
      File system paths can be modified on the system !file_system settings
      page.', array('!file_system' => l(t('File system'), 'admin/config/media/file-system'))),
  );

  $form['auditfiles_exclusions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Exclusions'),
    '#collapsible' => TRUE,
  );
  $form['auditfiles_exclusions']['auditfiles_exclude_files'] = array(
    '#type' => 'textfield',
    '#title' => t('Exclude these files'),
    '#default_value' => trim(variable_get('auditfiles_exclude_files', '.htaccess')),
    '#description' => t('Enter a list of files to exclude, each separated by the
      semi-colon character (;).'),
  );
  $form['auditfiles_exclusions']['auditfiles_exclude_extensions'] = array(
    '#type' => 'textfield',
    '#title' => t('Exclude these extensions'),
    '#default_value' => trim(variable_get('auditfiles_exclude_extensions', '')),
    '#description' => t('Enter a list of extensions to exclude, each separated
      by the semi-colon character (;). Do not include the leading dot.'),
  );
  $form['auditfiles_exclusions']['auditfiles_exclude_paths'] = array(
    '#type' => 'textfield',
    '#title' => t('Exclude these paths'),
    '#default_value' => trim(variable_get('auditfiles_exclude_paths', 'color;css;ctools;js')),
    '#description' => t('Enter a list of paths to exclude, each separated by the
      semi-colon character (;). Do not include the leading slash.'),
  );

  $form['auditfiles_domains'] = array(
    '#type' => 'fieldset',
    '#title' => t('Domains'),
    '#collapsible' => TRUE,
  );
  $form['auditfiles_domains']['auditfiles_include_domains'] = array(
    '#type' => 'textfield',
    '#title' => t('Include references to these domains'),
    '#default_value' => trim(variable_get('auditfiles_include_domains', '')),
    '#size' => 80,
    '#maxlength' => 1024,
    '#description' => t('Enter a list of domains (e.g., www.example.com)
      pointing to your website, each separated by the semi-colon character (;).
      <br />When scanning content for file references (such as &lt;img&gt;
      tags), any absolute references using these domains will be included and
      rewritten to use relative references. Absolute references to domains not
      in this list will be considered to be external references and will not be
      audited or rewritten.'),
  );

  $form['auditfiles_report_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Report options'),
    '#collapsible' => TRUE,
  );
  // Show date format select list.
  $date_types = system_get_date_types();
  $options = array();
  foreach ($date_types as $date_type) {
    $options[$date_type['type']] = $date_type['title'];
  }
  $form['auditfiles_report_options']['auditfiles_report_options_date_format'] = array(
    '#type' => 'select',
    '#title' => 'Date format',
    '#default_value' => variable_get('auditfiles_report_options_date_format', ''),
    '#options' => $options,
    '#description' => t('Select the date format to use when displaying file
      dates in the reports.<br />
      Date types and formats can be modified in the system !datetime settings
      pages.', array('!datetime' => l(t('Date and time'), 'admin/config/regional/date-time'))),
  );
  $form['auditfiles_report_options']['auditfiles_report_options_items_per_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of items per page'),
    '#default_value' => variable_get('auditfiles_report_options_items_per_page', 50),
    '#size' => 10,
    '#description' => t('Enter an integer representing the number of items to
      display on each page of a report.<br />
      If there are more than this number on a page, then a pager will be used to
      display the additional items.<br />
      Set this to 0 to show all items on a single page.'),
  );

  $form['auditfiles_report_options']['auditfiles_report_options_maximum_records'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum records'),
    '#default_value' => variable_get('auditfiles_report_options_maximum_records', 250),
    '#size' => 10,
    '#description' => t('Enter an integer representing the maximum number of
      records to return for each report.<br />
      If any of the reports are timing out, set this to some positive integer to
      limit the number of records that are queried in the database. For reports
      where the limit is reached, a button to batch process the loading of the
      page will be available that will allow all records to be retrieved without
      timing out.<br />
      Set this to 0 for no limit.'),
  );
  $form['auditfiles_report_options']['auditfiles_report_options_batch_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Batch size'),
    '#default_value' => variable_get('auditfiles_report_options_batch_size', 1000),
    '#size' => 10,
    '#description' => t('If you have a lot of files (100,000+), it will take an
      exponentially longer amount of time and memory to retrieve file data the
      longer it goes through the batch process. Decreasing the the number of
      files loaded, by setting this to a positive, non-zero integer, will keep
      the batch process down to a reasonable amount of time.<br />
      Set this to 0 for no limit.'),
  );

  return system_settings_form($form);
}

/**
 * Validates some user input for auditfiles_admin_settings().
 */
function auditfiles_admin_settings_validate($form, &$form_state) {
  $fields = array(
    'auditfiles_report_options_items_per_page' => t('Number of items per page'),
    'auditfiles_report_options_maximum_records' => t('Maximum records'),
    'auditfiles_report_options_batch_size' => t('Batch set size'),
  );
  foreach ($fields as $field => $label) {
    if (!is_numeric($form_state['values'][$field])) {
      form_set_error($field, t('You must enter zero or a positive integer for !label.', array('!label' => $label)));
    }
    elseif (!is_int($form_state['values'][$field] + 0) || $form_state['values'][$field] < 0) {
      form_set_error($field, t('!label must be zero or a positive integer.', array('!label' => $label)));
    }
  }
}
