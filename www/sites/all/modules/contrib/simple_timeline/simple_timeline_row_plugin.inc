<?php
/**
 * @file
 * Contains the simple timeline row plugin.
 * Created by JetBrains PhpStorm.
 * User: alan
 */

/**
 * Row plugin to render each item on a simple timeline.
 *
 * @ingroup views_row_plugins
 */
class simple_timeline_row_plugin extends views_plugin_row {

  /**
   * Extends the default options inherited by this plugin.
   *
   * @return array
   *   The list of options provided by this plugin.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['simple_timeline_date'] = array('default' => array());
    $options['simple_timeline_date_separator'] = array('default' => array());
    $options['simple_timeline_text'] = array('default' => array());
    $options['simple_timeline_text_separator'] = array('default' => array());
    $options['simple_timeline_image'] = array('default' => array());
    return $options;
  }

  /**
   * Extends the options form inherited by this plugin.
   *
   * @param array $form
   *   The form being generated.
   * @param array $form_state
   *   The state that the form has been posted in.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['simple_timeline_date'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Timeline Date fields'),
      '#options' => $this->display->handler->get_field_labels(),
      '#default_value' => $this->options['simple_timeline_date'],
      '#description' => t('Selected fields will be displayed next to each other in the Date section.'),
    );

    $form['simple_timeline_date_separator'] = array(
      '#title' => t('Date Separator'),
      '#type' => 'textfield',
      '#size' => 10,
      '#default_value' => $this->options['simple_timeline_date_separator'],
      '#description' => t('The separator may be placed between inline fields to keep them from squishing up next to each other. You can use HTML in this field.'),
    );

    $form['simple_timeline_text'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Timeline Text fields'),
      '#options' => $this->display->handler->get_field_labels(),
      '#default_value' => $this->options['simple_timeline_text'],
      '#description' => t('Selected fields will be displayed next to each other in the Text section'),
    );

    $form['simple_timeline_text_separator'] = array(
      '#title' => t('Text Separator'),
      '#type' => 'textfield',
      '#size' => 10,
      '#default_value' => $this->options['simple_timeline_text_separator'],
      '#description' => t('The separator may be placed between inline fields to keep them from squishing up next to each other. You can use HTML in this field.'),
    );

    $form['simple_timeline_image'] = array(
      '#type' => 'radios',
      '#title' => t('Timeline Image field'),
      '#options' => $this->display->handler->get_field_labels(),
      '#default_value' => $this->options['simple_timeline_image'],
      '#description' => t('The image to be displayed with each item'),
    );
  }
}
