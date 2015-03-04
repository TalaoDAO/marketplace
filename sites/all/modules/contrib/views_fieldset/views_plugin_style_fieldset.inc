<?php

/**
 * @file
 * Contains views_plugin_style_fieldset.
 */

/**
 * Defines a style plugin that renders the full view as fieldset.
 *
 * @ingroup views_style_plugins
 */
class views_plugin_style_fieldset extends views_plugin_style_default {

  /**
   * Overrides views_plugin_style::options_definition().
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['collapsible'] = array('default' => TRUE, 'bool' => TRUE);
    $options['collapsed'] = array('default' => FALSE, 'bool' => TRUE);
    $options['title'] = array('default' => '');
    $options['description'] = array('default' => '');

    return $options;
  }

  /**
   * Overrides views_plugin_style::options_form().
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['collapsible'] = array(
      '#title' => t('Collapsible fieldset'),
      '#type' => 'checkbox',
      '#description' => t('Check to make fieldset collapsible.'),
      '#default_value' => $this->options['collapsible'],
      '#weight' => -50,
    );

    $form['collapsed'] = array(
      '#title' => t('Collapsed by default'),
      '#type' => 'checkbox',
      '#description' => t('Check to show fieldset collapsed.'),
      '#default_value' => $this->options['collapsed'],
      '#weight' => -49,
    );
    $options = array('' => t('- None -'));
    $field_labels = $this->display->handler->get_field_labels(TRUE);
    $options += $field_labels;

    $form['title'] = array(
      '#type' => 'select',
      '#title' => t('Fieldset Title'),
      '#options' => $options,
      '#default_value' => $this->options['title'],
      '#description' => t('Choose the title of fieldset.'),
      '#weight' => -48,
    );

    $form['description'] = array(
      '#type' => 'select',
      '#title' => t('Fieldset Description'),
      '#options' => $options,
      '#default_value' => $this->options['description'],
      '#description' => t('Optional fieldset description.'),
      '#weight' => -47,
    );
  }

}
