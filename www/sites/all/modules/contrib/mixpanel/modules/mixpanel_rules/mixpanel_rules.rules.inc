<?php

/**
 * @file
 * Contains all the Rules info hooks.
 */

/**
 * Implements hook_rules_file_info().
 */
function mixpanel_rules_rules_file_info() {
  return array('mixpanel_rules.eval');
}

/**
 * Implements hook_rules_data_info().
 */
function mixpanel_rules_rules_data_info() {
  return array(
    'mixpanel_properties' => array(
      'label' => t('Mixpanel properties'),
      'group' => t('Mixpanel'),
      'ui class' => 'MixpanelRulesPropertiesUI',
    ),
  );
}

/**
 * Implements hook_rules_action_info().
 */
function mixpanel_rules_rules_action_info() {
  $actions = array();
  $actions['mixpanel_rules_track'] = array(
    'label' => t('Track event on Mixpanel'),
    'group' => t('Mixpanel'),
    'parameter' => array(
      'event' => array(
        'type' => 'text',
        'label' => t('Event name'),
        'default mode' => 'input',
      ),
      'account' => array(
        'type' => 'user',
        'label' => t('User'),
        'description' => t('The user who will be recorded as triggering the event'),
        'default mode' => 'selector',
      ),
    ),
  );

  for ($i = 1; $i <= MIXPANEL_RULES_PROPERTIES_MAX; $i++) {
    $base_name = sprintf('property_%02d', $i);
    $actions['mixpanel_rules_track']['parameter'][$base_name . '_name'] = array(
      'type' => 'text',
      'label' => t('Property #!num name', array('!num' => $i)),
      'default mode' => 'input',
      'optional' => TRUE,
    );
    $actions['mixpanel_rules_track']['parameter'][$base_name . '_value'] = array(
      'type' => 'text',
      'label' => t('Property #!num value', array('!num' => $i)),
      'default mode' => 'selector',
      'optional' => TRUE,
    );
  }

  return $actions;
}

/**
 * Implements hook_mixpanel_rules_track_form_alter().
 */
function mixpanel_rules_track_form_alter(&$form, &$form_state) {
  // Event name is a simple string.
  $form['parameter']['event']['settings']['event']['#type'] = 'textfield';

  // For some reason 'default value' doesn't set the selector widget
  // (only the direct input widget), so we do it manually here.
  if (empty($form['parameter']['account']['settings']['account:select']['#default_value'])) {
    $form['parameter']['account']['settings']['account:select']['#default_value'] = 'site:current-user';
  }

  // Loop through the properties and customize them.
  for ($i = 1; $i <= MIXPANEL_RULES_PROPERTIES_MAX; $i++) {
    $base_name = sprintf('property_%02d', $i);

    // Make the name a simple textfield, without the help or switch button.
    $name_element =& $form['parameter'][$base_name . '_name'];
    $name_element['settings'][$base_name . '_name']['#type'] = 'textfield';
    unset($name_element['settings']['help']);
    unset($name_element['switch_button']);
  }

  // Turns the properties into a table.
  $form['parameter']['#theme'] = 'mixpanel_rules_track_parameter_form';
}
