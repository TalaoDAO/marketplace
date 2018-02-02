<?php

/**
 * @file
 * Contains a FormPluginExample
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost_examples\FormPlugin;

use Drupal\ghost\Core\Form\Plugins\BaseFormPlugin;

$plugin = array(
  // This will be used as the key in drupal_get_form()
  'name' => 'ghost_examples_form_plugin_example',
  // Human readable title.
  'title' => t('Example Plugin Form'),
  // Human readable description.
  'description' => t('Demonstrates how to write a Form Plugin'),
  // Full class path.
  'class' => 'Drupal\ghost_examples\FormPlugin\FormPluginExample',
);

/**
 * Class FormPluginExample
 *
 * @package Drupal\ghost_examples\FormPlugin
 */
class FormPluginExample extends BaseFormPlugin {

  /**
   * Form constructor.
   *
   * @param array $form
   *   An associative array containing the structure of the form.
   * @param array $form_state
   *   An associative array containing the current state of the form.
   *
   * @return array
   *   The form structure.
   */
  public function buildForm(array &$form, array &$form_state) {

    $form['item'] = array(
      '#type' => 'textfield',
      '#title' => t('Sample textfield'),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save'),
    );
  }

}
