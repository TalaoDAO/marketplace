<?php

/**
 * @file
 * Form function for Ghost
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2014 Christopher Skene
 */

use Drupal\ghost\Core\Form\Plugins\FormPluginManager;
use Drupal\ghost\Exception\InvalidFormException;


/**
 * Implements hook_forms().
 */
function ghost_forms($form_id, $args) {
  return FormPluginManager::init()->getForms($form_id, $args);
}

/**
 * Form validation handler.
 *
 * @param array $form
 *   The form.
 * @param array $form_state
 *   The form state.
 *
 * @throws Drupal\ghost\Exception\InvalidFormException
 * @return mixed
 *   Result of the validateForm operation.
 */
function ghost_form_validate($form, &$form_state) {
  return FormPluginManager::init()->validate($form, $form_state);
}

/**
 * Form submit handler.
 *
 * @param array $form
 *   The form.
 * @param array $form_state
 *   The form state.
 *
 * @throws Drupal\ghost\Exception\InvalidFormException
 * @return mixed
 *   Result of the submitForm operation.
 */
function ghost_form_submit($form, &$form_state) {
  return FormPluginManager::init()->submit($form, $form_state);
}

/**
 * Custom form builder.
 *
 * @deprecated
 * While this works in individual instances, multiple forms on the same page
 * will share the same callback and caching space, which can lead to errors
 * and erratic behaviour. It is recommended to use the Form Plugin API
 * instead.
 *
 * @code
 * $form = drupal_get_form('ghost_form', '\Drupal\ghost\ExampleForm');
 * @code
 *
 * @param array $form
 *   (optional) The form.
 * @param array $form_state
 *   (optional) The form state.
 * @param string $form_handler
 *   The form handling class name.
 *
 * @throws Drupal\ghost\Exception\InvalidFormException
 * @return array
 *   Result of the buildForm operation.
 */
function ghost_form($form, &$form_state, $form_handler) {

  $form_class = ghost_get_form_handler($form_handler);

  $form_class->buildForm($form, $form_state);

  $form['ghost'] = array(
    '#type' => 'hidden',
    '#value' => $form_handler,
  );

  $form['#attributes']['id'] = $form_class->getFormId();
  $form['#attributes']['class'][] = 'ghost_form';

  $form['#validate'] = array('ghost_form_validate');
  $form['#submit'] = array('ghost_form_submit');

  return $form;
}

/**
 * Construct a form handler.
 *
 * @deprecated
 * Use the Form Plugin API instead.
 *
 * @param string $form_handler
 *   Name of the form handler.
 *
 * @throws Drupal\ghost\Exception\InvalidFormException
 * @return \Drupal\ghost\Core\Form\FormInterface
 *   A Form object.
 */
function ghost_get_form_handler($form_handler) {

  if (!class_exists($form_handler)) {
    throw new InvalidFormException('Could not find form handler class.');
  }

  $form_handler = new $form_handler();

  if (!$form_handler instanceof \Drupal\ghost\Core\Form\FormInterface) {
    throw new InvalidFormException('The provided form handler class was not an instance of FormInterface.');
  }

  return $form_handler;
}
