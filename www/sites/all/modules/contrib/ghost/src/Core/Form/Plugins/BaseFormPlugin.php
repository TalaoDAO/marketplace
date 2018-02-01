<?php

/**
 * @file
 * Contains a BaseFormPlugin
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 * @copyright Copyright(c) 2015 Christopher Skene
 */

namespace Drupal\ghost\Core\Form\Plugins;

use Drupal\ghost\Core\Form\BaseForm;

/**
 * Class BaseFormPlugin
 *
 * @package Drupal\ghost\Core\Form
 */
abstract class BaseFormPlugin extends BaseForm {

  /**
   * Plugin settings
   *
   * @var array
   */
  protected $settings;

  /**
   * Used by the form plugin initializer to load the class.
   *
   * @param array $form
   *   The form array
   * @param array $form_state
   *   The form state array
   *
   * @return static
   *   An instance of FormInterface
   * @static
   */
  static public function process($form, $form_state) {

    $form_handler = new static();
    $form_handler->loadSettings($form_state['build_info']['form_id']);

    $form_handler->buildForm($form, $form_state);

    $form['ghost'] = array(
      '#type' => 'hidden',
      '#value' => $form_state['build_info']['form_id'],
    );
    $form['ghost_type'] = array(
      '#type' => 'hidden',
      '#value' => 'plugin',
    );

    $form['#attributes']['id'] = drupal_html_id($form_state['build_info']['form_id']);
    $form['#attributes']['class'][] = 'ghost-form';

    $form['#validate'] = array('ghost_form_validate');
    $form['#submit'] = array('ghost_form_submit');

    return $form;
  }

  /**
   * Returns a unique string identifying the form.
   *
   * @return string
   *   The unique string identifying the form.
   */
  public function getFormId() {

    return $this->settings['name'];
  }

  /**
   * Setter for settings.
   *
   * @param string $form_id
   *   The form ID.
   */
  public function loadSettings($form_id) {

    $this->settings = FormPluginFactory::init()->loadPluginDefinition($form_id);
  }
}
