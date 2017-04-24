<?php

/**
 * @file
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @defgroup pet Previewable email templates module integrations.
 *
 * Module integrations with the Previewable email templates module.
 */

/**
 * @defgroup pet_hooks Previewable email templates hooks
 * @{
 * Hooks that can be implemented by other modules in order to extend Previewable email templates.
 */

/**
 * Add custom token objects.
 *
 * Modules can implement this hook to provide additional token objects for 
 * substitution by PET during an email send.
 */
function hook_pet_substitutions_alter(&$substitutions, $params) {
  // Make my tokens available to PET
  if (isset($params['node']) && $params['node']->type == 'something_or_other') {
    $substitutions['something_or_other_extra_tokens'] = MY_MODULE_something_or_other_extra_tokens($params['node']);
  }
}

/**
 * Implementation of hook_default_ENTITY_TYPE.
 *
 * @return
 *   An array of default previewable email templates, keyed by machine names.
 *
 * @see hook_default_pet_alter()
 */
function hook_default_pet() {
  $defaults['some_default_pet'] = entity_create('pet', array(
    'name' => 'some_default_pet',
    'title' => 'some default pet title',
    'subject' => 'subject',
    'mail_body' => 'body default',
    'from_override' => NULL,
    'cc_default' => 'cc@example.com',
    'bcc_default' => 'bcc@example.com',
    'recipient_callback' => 'MY_MODULE_recipients_callback',
  ));
  return $defaults;
}

/**
 * Sample email recipient callback.
 *
 * In practice this would likely look up emails based on the node info.
 */
function MY_MODULE_recipients_callback($node = NULL) {
  return array(
    'allie@example.com',
    'bob@example.com',
  );
}


