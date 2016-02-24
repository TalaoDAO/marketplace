<?php
/**
 * @file
 * Admin stuff for the Mail Logger module.
 */

/**
 * Mail Logger admin form.
 */
function mail_logger_admin_settings_form($form, &$form_state) {
  $options_log_maximum_age = array(
    0 => t('Never'),
  );
  $time_intervals = array(
    0,
    86400,
    604800,
    1209600,
    2592000,
    7776000,
    15552000,
    31536000,
  );
  $options_log_maximum_age += drupal_map_assoc($time_intervals, 'format_interval');
  $form['mail_logger_log_maximum_age'] = array(
    '#type' => 'select',
    '#title' => t('Discard mail logs older than'),
    '#default_value' => variable_get('mail_logger_log_maximum_age', 0),
    '#options' => $options_log_maximum_age,
    '#description' => t('Older log entries will be automatically discarded during cron. Requires a correctly configured <a href="@cron">cron maintenance task</a>. Choose "Never" if you don\'t want logs to be deleted.', array('@cron' => url('admin/reports/status'))),
  );

  $date_types = array();
  foreach (system_get_date_types() as $name => $info) {
    $date_types[$name] = $info['title'] . ' <small>(' . format_date(REQUEST_TIME, $name) . ')</small>';
  }
  $form['mail_logger_log_date_format'] = array(
    '#type' => 'radios',
    '#options' => $date_types,
    '#title' => t('Date format'),
    '#default_value' => variable_get('mail_logger_log_date_format', 'short'),
    '#description' => t('This format will be used in the log display page.'),
    );

  $form['mail_logger_log_lines_per_page'] = array(
    '#type' => 'radios',
    '#options' => array(10 => 10, 20 => 20, 30 => 30, 40 => 40, 50 => 50, 75 => 75, 100 => 100),
    '#title' => t('Lines per page'),
    '#default_value' => variable_get('mail_logger_log_lines_per_page', 50),
    '#description' => t('This is the number of lines that will appear on the log display page.'),
    );

  $form = system_settings_form($form);
  return $form;
}
