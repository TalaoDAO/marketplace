<?php
/**
 * @file
 * Variable default definitions
 */

/**
 * Implements hook_variable_group_info().
 */
function rmets_cpd_accreditation_variable_group_info() {
  $groups['auto_assign_role'] = array(
    'title' => t('Auto Assign Role'),
    'description' => t('Administer descriptions for Auto Assign Role.'),
    'access' => 'administer site configuration',
  );

  return $groups;
}

/**
 * Implements hook_variable_info().
 */
function autoassignrole_variable_info($options) {
  $variables['autoassignrole_user_fieldset_title'] = array(
    'group' => 'auto_assign_role',
    'type' => 'text',
    'title' => t('User Role Fieldset Title'),
    'description' => t('The title of the fieldset that contains role options.'),
  );

  $variables['autoassignrole_user_title'] = array(
    'group' => 'auto_assign_role',
    'type' => 'text',
    'title' => t('User Role Title'),
    'description' => t('The title of the field that contains the role options the end user sees during registration.'),
  );

  $variables['autoassignrole_user_description'] = array(
    'group' => 'auto_assign_role',
    'type' => 'text_format',
    'title' => t('User Role Description'),
    'description' => t('The description displayed to the end user when they are selecting their role during registration.'),
  );

  return $variables;
}
