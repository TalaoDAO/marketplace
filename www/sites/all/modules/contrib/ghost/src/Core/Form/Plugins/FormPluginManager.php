<?php

/**
 * @file
 * Contains a FormPluginManager
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Core\Form\Plugins;

use Drupal\ghost\Traits\InitialiserTrait;
use Drupal\ghost\Exception\InvalidFormException;

/**
 * Class FormPluginManager
 *
 * @package Drupal\ghost\Core\Form\Plugins
 */
class FormPluginManager {

  use InitialiserTrait;

  /**
   * Return information for a hook_forms() implementation.
   *
   * @param string $form_id
   *   The form identifier
   * @param array $args
   *   Any arguments
   *
   * @return array
   *   An array of form information
   */
  public function getForms($form_id, $args) {
    $forms = array();
    $form_plugin_manager = FormPluginFactory::init();
    $plugin_definition = $form_plugin_manager->loadPluginDefinition($form_id);

    if (!is_null($plugin_definition)) {

      $forms[$form_id] = array(
        'callback' => $plugin_definition['class'] . '::process',
        'callback arguments' => $args,
        'wrapper_callback' => isset($plugin_definition['wrapper']) ? $plugin_definition['wrapper'] : NULL,
      );
    }

    return $forms;
  }

  /**
   * Form validation handler.
   *
   * @param array $form
   *   The form.
   * @param array $form_state
   *   The form state.
   *
   * @return mixed
   *   Result of the validateForm operation.
   * @throws \Drupal\ghost\Exception\InvalidFormException
   */
  public function validate($form, &$form_state) {
    if (!isset($form['ghost'])) {

      throw new InvalidFormException('The submitted Ghost form did not specify a Ghost form handler.');
    }

    if (isset($form_state['input']['form_id']) && $form_state['input']['form_id'] == $form_state['complete form']['ghost']['#value']) {
      $form_state['triggering_element'] = $form_state['buttons'][0];

      // If there was no specific triggering button detected,
      // try to find submitted element by name in POST data.
      $triggering_element = $form_state['buttons'][0];
      foreach ($form_state['buttons'] as $button_element) {
        if (isset($button_element['#name']) && !empty($form_state['input'][$button_element['#name']])) {
          $triggering_element = $button_element;
          break;
        }
      }
      $form_state['triggering_element'] = $triggering_element;

      if (isset($form['ghost_type']) && $form['ghost_type']['#value'] == 'plugin') {
        $form_handler = FormPluginFactory::init()->loadPlugin($form['ghost']['#value']);
      }
      else {
        $form_handler = ghost_get_form_handler($form['ghost']['#value']);
      }

      return $form_handler->validateForm($form, $form_state);
    }
  }

  /**
   * Form submit handler.
   *
   * @param array $form
   *   The form.
   * @param array $form_state
   *   The form state.
   *
   * @return mixed
   *   Result of the submitForm operation.
   * @throws \Drupal\ghost\Exception\InvalidFormException
   */
  public function submit($form, &$form_state) {

    if (!isset($form['ghost'])) {

      throw new InvalidFormException('The submitted form used Ghost did not specify a Ghost form handler.');
    }

    if (isset($form_state['input']['ghost']) && $form_state['input']['ghost'] == $form_state['complete form']['ghost']['#value']) {

      if (isset($form['ghost_type']) && $form['ghost_type']['#value'] == 'plugin') {
        $form_handler = FormPluginFactory::init()->loadPlugin($form['ghost']['#value']);
      }
      else {
        $form_handler = ghost_get_form_handler($form['ghost']['#value']);
      }

      return $form_handler->submitForm($form, $form_state);
    }
  }
}
