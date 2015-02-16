<?php

/**
 * @file
 * Handle the 'webform submission view' override task.
 *
 * This plugin overrides webform-submissions/%webform_entity_pages_submission and reroutes it to the page manager, where
 * a list of tasks can be used to service this request based upon criteria
 * supplied by access plugins.
 */

/**
 * Specialized implementation of hook_page_manager_task_tasks(). See api-task.html for
 * more information.
 */
function webform_entity_pages_webform_submission_view_page_manager_tasks() {
  return array(
    // This is a 'page' task and will fall under the page admin UI
    'task type' => 'page',
    'title' => t('Webform Submission template'),
    'admin title' => t('Webform Submission template'),
    'admin path' => 'webform-submission/%webform_entity_pages_submission',
    'admin description' => t('When enabled, this overrides the default Drupal behavior for displaying a Webform Submission at <em>webform-submission/%webform_entity_pages_submission</em>.'),

    // Menu hooks so that we can alter the webform-submission/%webform_entity_pages_submission menu entry to point to us.
    'hook menu' => 'webform_entity_pages_webform_submission_view_menu',
    'hook menu alter' => 'webform_entity_pages_webform_submission_view_menu_alter',

    // This is task uses 'context' handlers and must implement these to give the
    // handler data it needs.
    'handler type' => 'context',
    'get arguments' => 'webform_entity_pages_webform_submission_view_get_arguments',
    'get context placeholders' => 'webform_entity_pages_webform_submission_view_get_contexts',

    // Allow this to be enabled or disabled:
    'disabled' => variable_get('webform_entity_pages_webform_submission_view_disabled', TRUE),
    'enable callback' => 'webform_entity_pages_webform_submission_view_enable',
  );
}

/**
 * Callback defined by webform_entity_pages_webform_submission_view_page_manager_tasks().
 *
 * Alter the webform submission view input so that webform submission view comes to us rather than the
 * normal webform submission view process.
 */
function webform_entity_pages_webform_submission_view_menu_alter(&$items, $task) {
  if (variable_get('webform_entity_pages_webform_submission_view_disabled', TRUE)) {
    return;
  }

  // Override the webform submision view handler for our purpose.
  $callback = $items['webform-submission/%webform_entity_pages_submission']['page callback'];
  if ($callback == 'webform_entity_pages_webform_submission_page' || variable_get('webform_entity_pages_override_anyway', FALSE)) {
    $items['webform-submission/%webform_entity_pages_submission']['page callback'] = 'webform_entity_pages_webform_submission_view_page';
    $items['webform-submission/%webform_entity_pages_submission']['file path'] = $task['path'];
    $items['webform-submission/%webform_entity_pages_submission']['file'] = $task['file'];
  }
  else {
    // automatically disable this task if it cannot be enabled.
    variable_set('webform_entity_pages_webform_submission_view_disabled', TRUE);
    if (!empty($GLOBALS['webform_entity_pages_enabling_webform_submission_view'])) {
      drupal_set_message(t('Page manager module is unable to enable "webform-submission/%webform_entity_pages_submission" because some other module already has overridden with %callback.', array('%callback' => $callback)), 'error');
    }
  }
}

/**
 * Entry point for our overridden webform submission view.
 *
 * This function asks its assigned handlers who, if anyone, would like
 * to run with it. If no one does, it passes through to Drupal core's
 * webform submission view, which is webform_entity_pages_webform_submission_page().
 */
function webform_entity_pages_webform_submission_view_page($submission) {
  // Load my task plugin
  $task = page_manager_get_task('webform_submission_view');

  // Load the submission into a context.
  ctools_include('context');
  ctools_include('context-task-handler');
  $contexts = ctools_context_handler_get_task_contexts($task, '', array($submission->sid));
  $output = ctools_context_handler_render($task, '', $contexts, array($submission));
  if ($output != FALSE) {
    return $output;
  }

  $function = 'webform_entity_pages_webform_submission_page';
  foreach (module_implements('webform_entity_pages_override') as $module) {
    $call = $module . '_webform_entity_pages_override';
    if (($rc = $call('webform_submission_view')) && function_exists($rc)) {
      $function = $rc;
      break;
    }
  }

  // Otherwise, fall back.
  return $function($submission);
}

/**
 * Callback to get arguments provided by this task handler.
 *
 * Since this is the webform submission view and there is no UI on the arguments, we
 * create dummy arguments that contain the needed data.
 */
function webform_entity_pages_webform_submission_view_get_arguments($task, $subtask_id) {
  return array(
    array(
      'keyword' => 'webform_submission_entity',
      'identifier' => t('Webform Submission being viewed'),
      'id' => 1,
      'name' => 'entity_id:webform_submission_entity',
      'settings' => array(),
    ),
  );
}

/**
 * Callback to get context placeholders provided by this handler.
 */
function webform_entity_pages_webform_submission_view_get_contexts($task, $subtask_id) {
  return ctools_context_get_placeholders_from_argument(webform_entity_pages_webform_submission_view_get_arguments($task, $subtask_id));
}

/**
 * Callback to enable/disable the page from the UI.
 */
function webform_entity_pages_webform_submission_view_enable($cache, $status) {
  variable_set('webform_entity_pages_webform_submission_view_disabled', $status);
  // Set a global flag so that the menu routine knows it needs
  // to set a message if enabling cannot be done.
  if (!$status) {
    $GLOBALS['webform_entity_pages_enabling_webform_submission_view'] = TRUE;
  }
}
