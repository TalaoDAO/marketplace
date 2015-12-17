<?php

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
  $form = system_settings_form($form);
  return $form;
}
