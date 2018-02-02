<?php

/**
 * @file
 * Contains a
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2014 Christopher Skene
 */

namespace Drupal\ghost_examples\Form;

use Drupal\ghost\Core\Form\BaseForm;
use Drupal\ghost\Core\Form\FormInterface;

/**
 * Class ExampleForm
 * @package Drupal\ghost_examples\Form
 */
class ExampleForm extends \Drupal\ghost\Core\Form\BaseForm implements FormInterface {

  /**
   * {@inheritdoc}
   */
  public function buildForm(array &$form, array &$form_state) {

    $form['my_field'] = array(
      '#type' => 'textfield',
      '#title' => t('My field'),
      '#default_value' => t('Some default value'),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save'),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm(array &$form, array &$form_state) {

    // Do any validation...
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, array &$form_state) {

    // Do something with the form here...
    drupal_set_message('Save complete!');
  }
}
