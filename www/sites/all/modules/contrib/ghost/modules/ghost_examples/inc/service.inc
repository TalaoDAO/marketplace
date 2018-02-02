<?php
/**
 * @file
 * Example usage of the Service container.
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 *
 * @author Chris Skene chris dot skene at xtfer dot com
 *
 * @copyright Copyright(c) 2016 Christopher Skene
 */

use Drupal\ghost_examples\Service\ExampleServiceFactory;

/**
 * How to use a service factory.
 */
function ghost_examples_call_service() {

  $service_container = ExampleServiceFactory::init();

  $example_service = $service_container->getFooService('foo');

  $example_service->baz();

  $service_container->addService('foo', array(
    'class' => '\Some\Other\Class',
  ));

  // Calls Baz on Some Other Class.
  $example_service->baz();

}
