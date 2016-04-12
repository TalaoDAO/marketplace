<?php

/**
 * Form function, called by drupal_get_form()
 * in dbtng_migrator_menu().
 */
function dbtng_migrator_check_form($form, &$form_state) {
  $form = dbtng_migrator_settings($form, $form_state);
  $form['description']['#markup'] = t('Below are the database connections defined in Drupal. You can use this interface to check the schema against a database to another assuming it is a Drupal database.');

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Check'),
    '#access' => $form['migrate_submit']['#access'],
  );
  unset($form['migrate_submit']);
  return $form;
}

/**
 * Validation callback for dbtng_migrator_check_form().
 */
function dbtng_migrator_check_form_validate($form, &$form_state) {
  $origin = $form_state['values']['migrate_origin'];
  $dest   = $form_state['values']['migrate_destination'];

  // Test connectivity.
  try {
    $test_connection = "migrate_origin";
    db_set_active($origin);
    db_query('SELECT 1');
    $test_connection = "migrate_destination";
    db_set_active($dest);
    db_query('SELECT 1');
  }
  catch (Exception $e) {
    db_set_active($origin);
    form_set_error($test_connection, t("Unable to connect to database: @message", array(
      '@message' => $e->getMessage(),
    )));
    return;
  }

  // Connect to the origin and generate a list of tables in the database.
  db_set_active($origin);
  $modules = module_list(TRUE);
  foreach ($modules as $module) {
    db_set_active($origin);
    $schema = drupal_get_schema_unprocessed($module);
    _drupal_schema_initialize($schema, $module, TRUE);

    // Some modules won't actually have a schema.
    if (!is_array($schema)) {
      continue;
    }

    db_set_active($dest);

    try {

      // Iterate over the schema and assert the origin's schema exists
      // on the destination.
      foreach ($schema as $table => $info) {
        if (!db_table_exists($table)) {
          form_set_error('migrate_destination', t('@table does not existing in @db_key', array('@table' => $table, '@db_key' => $dest)));
          continue;
        }
        foreach ($info['fields']  as $name => $column) {
          if (!db_field_exists($table, $name)) {
            form_set_error('migrate_destination', t('@table does not contain field @column in @db_key', array(
              '@table' => $table,
              '@column' => $name,
              '@db_key' => $dest
            )));
          }
        }
        if (isset($info['indexes'])) {
          foreach ($info['indexes'] as $name => $columns) {
            if (!db_index_exists($table, $name)) {
              form_set_error('migrate_destination', t('@table does not contain index @index in @db_key', array('@table' => $table, '@index' => $name, '@db_key' => $dest)));
            }
            foreach ($columns as $col) {
              if (is_array($col)) {
                $col = $col[0];
              }
              if (!db_field_exists($table, $col)) {
                throw new Exception(t('Index check failure: @table does not contain field @column in @db_key', array(
                  '@table' => $table,
                  '@column' => $col,
                  '@db_key' => $dest
                )));
              }
            }
          }
        }
      }
    }
    catch (Exception $e) {
      form_set_error('migrate_destination', $e->getMessage());
    }
  }
  db_set_active('default');
}

/**
 * Submission handler for dbtng_migrator_check_form
 */
function dbtng_migrator_check_form_submit($form, &$form_state) {
  // This is only ever called if the validation hook passes all checks
  // so there is nothing to do here but state that the check was successful.
  drupal_set_message("Database check was successful.");
}

/**
 * Form function, called by drupal_get_form()
 * in dbtng_migrator_menu().
 */
function dbtng_migrator_settings($form, &$form_state) {
  $form['description']['#markup'] = t('Below are the database connections defined in Drupal. You can use this interface to migrate database to another assuming it is a Drupal database.');
  global $databases;
  foreach (array_keys($databases) as $key) {
    $connection_info = Database::getConnectionInfo($key);
    $info = $connection_info['default'];

    // Make the information display safe.
    $rows[] = array(check_plain($key), check_plain($info['driver']), check_plain($info['database']));
    $options[$key] = $key;
  }

  if (count($options) < 2) {
    drupal_set_message(t('You must specify more than one database connection in the settings.php file.'), 'error');
  }

  $form['how_to'] = array(
    '#title' => 'Instructions',
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['how_to']['details'] = array(
    '#markup' => '<p>' . t('To migrate this Drupal install to another database you\'ll 
                    need to add the database connection creditials to your settings.php file. Below is an example:') . '</p>',
  );
  $form['how_to']['example']['#markup'] = '<pre>
  &lt;?php
    // Settings.php contents above....

    // You\'re new database to migrate to. This will appear as "example" in the Migrator admin UI.
    $databases[\'example\'][\'default\'] = array(
      \'driver\' => \'mysql\',
      \'database\' => \'databasename\',
      \'username\' => \'username\',
      \'password\' => \'password\',
      \'host\' => \'localhost\',
      \'prefix\' => \'\',
    );
  ?&gt;
</pre>';

  $headers = array('Key', 'Driver', 'Database');
  $form['databases']['#markup'] = theme('table', array('header' => $headers, 'rows' => $rows));
  $form['migrate_origin'] = array(
    '#title' => 'Origin Database',
    '#type' => 'select',
    '#options' => $options,
    '#description' => t('The database the data will be replicated from.'),
    '#disabled' => count($options) < 2,
  );
  $form['migrate_destination'] = array(
    '#title' => 'Destination Database',
    '#type' => 'select',
    '#options' => $options,
    '#description' => t('The database the origin data will be replicated too.'),
    '#access' => count($options) > 1,
    '#default_value' => $key,
  );
  $form['migrate_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Migrate'),
    '#access' => count($options) > 1,
  );
  return $form;
}

/**
 * Validation handler for form dbtng_migrator_settings.
 */
function dbtng_migrator_settings_validate($form, $form_state) {
  if ($form_state['values']['migrate_destination'] == $form_state['values']['migrate_origin']) {
    form_set_error('migrate_destination', t('Migration origin cannot be the same as the destination.'));
    return;
  }

  $origin = $form_state['values']['migrate_origin'];
  $dest   = $form_state['values']['migrate_destination'];

  // Connect to the origin and generate a list of tables in the database.
  db_set_active($origin);
  $modules = module_list(TRUE);
  $tables  = array();
  foreach ($modules as $module) {
    $schema = drupal_get_schema_unprocessed($module);
    _drupal_schema_initialize($schema, $module, TRUE);

    // Some modules won't actually have a schema.
    if (!is_array($schema)) {
      continue;
    }
    foreach ($schema as $table => $info) {
      $tables[] = $table;
    }
  }

  // Check that those tables don't already exists in the destination.
  db_set_active($dest);
  foreach ($tables as $table) {
    if (db_table_exists($table)) {
      form_set_error('migrate_destination', t('%table already exists in destination database. DBTNG Migrator will not override existing data', array('%table' => $table)));
    }
  }
  db_set_active('default');
}

/**
 * Submission handler for form dbtng_migrator_settings.
 */
function dbtng_migrator_settings_submit($form, $form_state) {
  $batch = array(
    'title' => t("Replicating Database"),
    'operations' => array(
      array('dbtng_migrator_batch_initialise_destination', array($form_state['values']['migrate_destination'])),
      array('dbtng_migrator_batch_install_schema', array($form_state['values']['migrate_origin'], $form_state['values']['migrate_destination'])),
      array('dbtng_migrator_batch_migrate_table', array($form_state['values']['migrate_origin'], $form_state['values']['migrate_destination'])),
    ),
    'finished' => 'dbtng_migrator_batch_report',
    'file' => drupal_get_path('module', 'dbtng_migrator') . '/dbtng_migrator.batch.inc',
  );
  batch_set($batch);
}
