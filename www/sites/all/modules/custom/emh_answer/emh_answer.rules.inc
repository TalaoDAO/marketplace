<?php

/**
 * @file
 * Functions for rules integration.
 */

/**
 * Implements of hook_rules_event_info().
 * @ingroup rules
 */
function emh_answer_rules_event_info() {
  ddl('coucou 3');
  return array(
    'emh_answer_submit_as_draft' => array(
      'label' => t('After a webform has been saved as draft'),
      'group' => t('Webform'),
      'variables' => _emh_answer_event_variables(),
      'access callback' => 'rules_node_integration_access',
    ),
    'emh_answer_submit' => array(
      'label' => t('After a webform has been submitted'),
      'group' => t('Webform'),
      'variables' => _emh_answer_event_variables(),
      'access callback' => 'rules_node_integration_access',
    ),
    'emh_answer_insert' => array(
      'label' => t('After a submission draft has been submitted'),
      'group' => t('Webform'),
      'variables' => _emh_answer_event_variables(),
      'access callback' => 'rules_node_integration_access',
    ),
    'emh_answer_update' => array(
      'label' => t('After a webform submission has been updated'),
      'group' => t('Webform'),
      'variables' => _emh_answer_event_variables(),
      'access callback' => 'rules_node_integration_access',
    ),
    'emh_answer_delete' => array(
      'label' => t('After a webform submission has been deleted'),
      'group' => t('Webform'),
      'variables' => _emh_answer_event_variables(),
      'access callback' => 'rules_node_integration_access',
    ),
  );
}

/**
 * Implementation of hook_condition_info().
 */
function emh_answer_rules_condition_info() {
  ddl('coucou 4');
  return array(
    'webform_has_id' => array(
      'label' => t('Webform has name'),
      'parameter' => array(
        'form_id' => array(
          'type' => 'text',
          'label' => t('The form id of the submitted form'),
        ),
        'selected_webform' => array(
          'type' => 'list<text>',
          'label' => t('Webforms'),
          'options list' => 'emh_answer_get_webforms_as_options',
          'description' => t('The name of the webform to check for.'),
          'restriction' => 'input',
        ),
      ),
      'help' => t('This condition compares the id of the submitted form with the selected value(s).'),
      'group' => t('Webform'),
      'base' => 'emh_answer_condition_webform_has_id',
    ),
    'node_is_webform' => array(
      'label' => t('Content is webform-enabled'),
      'parameter' => array(
      'node' => array(
        'type' => 'node',
        'label' => t('Content'),
        'description' => t('The content to verify.'),
      ),
      ),
      'help' => t('This condition verifies a node contains a webform.'),
      'group' => t('Webform'),
      'base' => 'emh_answer_condition_node_is_webform',
    ),
  );
}

/**
 * Implements hook_rules_action_info().
 *
 */
function emh_answer_rules_action_info() {
  ddl('coucou 5');
  $defaults = array(
    'group' => t('Webform'),
    'access callback' => 'rules_node_admin_access',
    'parameter' => array(
      'entity' => array(
        'type' => 'node',
        'label' => t('Webform'),
        'description' => t('A webform-enabled node.'),
        'save' => TRUE,
        'optional' => TRUE,
      ),
      'selected_webform' => array(
        'type' => 'list<text>',
        'label' => t('Webforms'),
        'options list' => 'emh_answer_get_webforms_as_options',
        'description' => t('List of webforms to open.'),
        'restriction' => 'input',
        'optional' => TRUE,
      ),
    ),
    'callbacks' => array(
      'validate' => 'emh_answer_webform_statuschange_validate',
    ),
  );
  $actions = array(
    'webform_open' => $defaults + array(
      'label' => t('Open webforms'),
      'base' => 'emh_answer_webform_open',
    ),
    'webform_close' => $defaults + array(
      'label' => t('Close webforms'),
      'base' => 'emh_answer_webform_close',
    ),
    'webform_submissions_load' => array(
      'label' => t('Fetch webform submissions'),
      'base' => t('emh_answer_submissions_load'),
      'group' => t('Webform'),
      'access callback' => 'rules_node_admin_access',
      'parameter' => array(
        'nid' => array(
          'type' => 'integer',
          'label' => t('Node ID'),
          'description' => t('The ID of the webform node to load the submission for.'),
        ),
        'sid' => array(
          'type' => 'integer',
          'label' => t('Submission ID'),
          'description' => t('The ID of a webform submission. If omitted all submissions of the specified node ID will be fetched.'),
          'optional' => TRUE,
        ),
      ),
      'provides' => array(
        'submissions' => array(
          'label' => t('Fetched submissions'),
          'type' => 'list<list>',
        ),
      ),
    ),
  );

  // Modify description of closing action.
  $actions['webform_close']['parameter']['selected_webform']['description'] = t('The name of the webforms to close.');

  return $actions;
}

/**
 * Implements hook_rules_data_info().
 */
function emh_answer_data_info() {
  ddl('coucou 6');
  return array(
    'answer_data' => array(
      'label' => t('webform data Answer'),
      'group' => t('Webform'),
      'token type' => 'answer',
      'property info' => array(),
    ),
  );
}

/**
 * Validation callback for actions 'emh_answer_webform_open' and
 * 'emh_answer_webform_close'.
 */
function emh_answer_webform_statuschange_validate($element) {
  ddl('coucou 7');
  if (empty($element->settings['entity:select']) && empty($element->settings['selected_webform'])) {
    throw new RulesIntegrityException(t('At least one parameter needs to be set.'), array($element, 'parameter', 'node'));
  }
}

/**
 * Function to compare the form id of the submitted webform with the selected
 * form.
 */
function emh_answer_condition_webform_has_id($form_id, $selected_webform) {
  ddl($form_id, 'coucou 7');
  if (is_array($selected_webform)) {
    return in_array($form_id, $selected_webform);
  }
  elseif (is_string($selected_webform)) {
    return $form_id == $selected_webform;
  }
  return FALSE;
}

/**
 * Condition callback to determine whether a node contains a webform.
 */
function emh_answer_condition_node_is_webform($node) {
  ddl($node, 'coucou 8');
  // Get a list of all nodes that are configured to use a webform.
  $query = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('n.nid', $node->nid);
  // Join to limit result list to node that really have a webform.
  $query->join('webform', 'w', 'n.nid = w.nid');
  // Join {webform_component} to prevent listing unconfigured webforms.
  $query->join('webform_component', 'c', 'n.nid = c.nid');
  // Get the result list.
  if ($query->execute()->rowCount() > 0) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Rules action callback to open webforms.
 */
function emh_answer_webform_open($entity = FALSE, $selected_webforms = array()) {
  _emh_answer_webform_set_status($entity, $selected_webforms);
}

/**
 * Rules action callback to close webforms.
 */
function emh_answer_webform_close($entity = FALSE, $selected_webforms = array()) {
  _emh_answer_webform_set_status($entity, $selected_webforms, FALSE);
}

/**
 * Helper method to update the status of a webform.
 */
function _emh_answer_webform_set_status($entity = FALSE, $selected_webforms = array(), $open = TRUE) {
  ddl('coucou 9');
  if (!empty($entity->nid) && emh_answer_condition_node_is_webform($entity)) {
    // Set new status.
    $entity->webform['status'] = ($open == TRUE) ? 1 : 0;
  }
  module_load_include('inc', 'rules', 'modules/entity.eval');
  // Try to close all selected webforms.
  foreach ($selected_webforms as $form_id) {
    // Try to get node id from form_id.
    $nid = str_replace('webform-client-form-', '', $form_id);
    // Load the node object.
    $result = rules_action_entity_fetch('node', $nid, NULL);
    $webform = $result['entity_fetched'];
    if (!empty($webform->nid) && emh_answer_condition_node_is_webform($webform)) {
      // Set new status.
      $webform->webform['status'] = ($open == TRUE) ? 1 : 0;
      // Save the webform node. Maybe we can find a better way how to save?
      node_save($webform);
    }
  }
}

/**
 * Rules action to load a list of webform submissions.
 *
 * @param int $nid
 *   ID of node to load the submissions for.
 * @param int $sid
 *   (optional) Submission ID.
 *
 * @return array
 *   List of loaded webform submissions.
 */
function emh_answer_submissions_load($nid, $sid = NULL) {
  ddl($nid, 'nid 1');
  ddl($sid, 'sid 1');
  // Make sure the needed functions are available.
  module_load_include('inc', 'webform', 'includes/webform.submissions');
  $filters = array(
    'nid' => $nid,
  );
  if (!empty($sid)) {
    $filters['sid'] = $sid;
  }
  // Fetch submissions.
  $submissions = webform_get_submissions($filters);

  return array('submissions' => $submissions);
}

/**
 * Helper function for event variables.
 *
 * @return
 *   All available variables for the rules events provided by emh_answer.
 */
function _emh_answer_event_variables() {
  ddl('coucou 2');
  return array(
    'user' => array(
      'type' => 'user',
      'label' => t('User, who submitted the webform'),
    ),
    'node' => array(
      'type' => 'node',
      'label' => t('The webform node'),
    ),
    'answer' => array(
      'type' => 'answer',
      'label' => t('The submitted answer webform data'),
    ),
    'form_id' => array(
      'type' => 'text',
      'label' => t('The form id of the submitted form'),
      'hidden' => TRUE,
    ),
    'selected_webform' => array(
      'type' => 'list<text>',
      'label' => t('Webforms'),
      'options list' => 'emh_answer_get_webforms_as_options',
      'description' => t('The name of the webform to check for.'),
      'restriction' => 'input',
      'hidden' => TRUE,
      'optional' => TRUE,
    ),
   
  );
}

