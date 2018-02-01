<?php

/**
 * @file
 * API information for Ghost.
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 *
 * @author Chris Skene chris dot skene at xtfer dot com
 *
 * @copyright Copyright(c) 2016 Christopher Skene
 */

/**
 * Return a list of Services.
 */
function hook_ghost_services() {
  return array(
    'foo' => array(
      // The handling class (required), which must implement the
      // ServiceInterface.
      'handler' => '\Drupal\module\AnotherNamespace\ClassName',
      // A Type (optional) as described by hook_ghost_service_types().
      'type' => 'baz',
      // Title (optional)
      'name' => t('Foo service'),
      // Description (optional).
      'description' => t('Provides foo'),
    ),
  );
}

/**
 * Return a list of Service types.
 *
 * @return array
 *   An array of types keyed by machine name.
 */
function hook_ghost_service_types() {
  return array(
    'baz' => array(
      // We only support Name currently.
      'name' => t('Baz'),
    ),
  );
}
