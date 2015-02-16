<?php
/**
 * @file
 * Batch processing functions.
 */

/**
 * Initialize the database with any environmentals needed.
 */
function dbtng_migrator_batch_initialise_destination($destination) {
  include_once DRUPAL_ROOT . '/includes/install.inc';

  // The Drupal database driver installer specifically uses the
  // default target and key from the $databases global variable.
  // Therefore, we'll need to rename the default connection and
  // destination keys so we can initialize the destination
  // database.
  Database::renameConnection('default', 'dbtngmTmp');
  Database::renameConnection($destination, 'default');
  db_run_tasks(Database::getConnection()->driver());
  Database::renameConnection('default', $destination);
  Database::renameConnection('dbtngmTmp', 'default');
}

/**
 * Install database schema into destination database.
 */
function dbtng_migrator_batch_install_schema($origin, $destination) {
  include_once DRUPAL_ROOT . '/includes/install.inc';

  // Load install files to expose hook_schema_alter hooks.
  drupal_load_updates();

  db_set_active($origin);
  $modules = module_list(TRUE);

  foreach ($modules as $module) {
    db_set_active($origin);
    $schema = drupal_get_schema_unprocessed($module);
    _drupal_schema_initialize($schema, $module, FALSE);
    // Next, prepare to call hook_schema_alter on our unprocessed schema.
    // There are some modules that add fields to tables owned by other modules;
    // for example, the uuid module (which is used by the features module) adds
    // a uuid field to several tables, including the node table. Adding these
    // in will insure that our destination table has the same set of fields as
    // the source table.  However, it may also happen that hook_schema_alter
    // might add new tables to the schema; we do not want to create these
    // tables, because they are not always unique. Skipping them works.
    $original_schema_table_list = array_keys($schema);
    drupal_alter('schema', $schema);

    foreach ($original_schema_table_list as $name) {
      $table = $schema[$name];
      db_set_active($destination);
      db_create_table($name, $table);
      $success = db_table_exists($name);

      // So that the locale module doesn't try query the new and
      // incomplete database during t(), we have to revert back to
      // the default database momentarily.
      db_set_active('default');
      if ($success) {
        drupal_set_message(t("@table was successfully created.", array('@table' => $name)));
      }
      else {
        drupal_set_message(t("@table could not be created.", array('@table' => $name)), 'error');
      }
    }
  }

  // Set connection back to the default Drupal connection.
  db_set_active('default');
}

/**
 * Migrate data from origin to destination one table at a time.
 */
function dbtng_migrator_batch_migrate_table($origin, $destination, &$context) {
  if (empty($context['results'])) {
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
    $context['sandbox']['unprocessed_tables'] = $tables;
    $context['sandbox']['max'] = count($tables);
    $context['sandbox']['progress'] = 0;
    $context['results'] = array();
  }

  $table = array_shift($context['sandbox']['unprocessed_tables']);
  db_set_active($origin);

  $schema = drupal_get_schema($table);

  // Set a default sort as range queries must have sorts.
  $order_by = key($schema['fields']);
  if (isset($schema['primary key'])) {
    $order_by = current($schema['primary key']);
  }


  try {
    // We have to revert to the default database to process a t() function call.
    // Even though its likely $origin is the default database,
    // we can't assume it.
    db_set_active('default');
    $context['message'] = t("Processing @table successful", array('@table' => $table));
    db_set_active($origin);

    // Fix this to make work with non-SQL databases.
    $total = db_select($table)->countQuery()->execute()->fetchField();
    $count = 0;
    $limit = 500;

    while ($count < $total) {
      db_set_active($origin);
      $rows = db_select($table, 't')
                ->fields('t', array_keys($schema['fields']))
                ->orderBy($order_by)
                ->range($count, $limit)
                ->execute();

      // No need to generate insert queries that don't insert anything.
      if (!count($rows)) {
        continue;
      }

      db_set_active($destination);
      $insert = db_insert($table)->fields(array_keys($schema['fields']));
      foreach ($rows as $row) {
        $insert->values((array) $row);
      }
      $insert->execute();
      $count += $limit;
    }
  }
  catch(Exception $e) {
    db_set_active('default');
    drupal_set_message($e->getMessage(), 'error');
    $context['message'] = t("Processing @table failed.", array('@table' => $table));
  }
  $context['results'][] = $table;

  $context['finished'] = empty($context['sandbox']['unprocessed_tables']);
  db_set_active('default');
}

/**
 * Generate batch report of migration.
 */
function dbtng_migrator_batch_report($success, $results) {
  if (!$success) {
    drupal_set_message("Migrator failed to successfully migrate data to destination database", 'error');
  }
  foreach ($results as $result) {
    drupal_set_message("$result successfully migrated.");
  }
}
