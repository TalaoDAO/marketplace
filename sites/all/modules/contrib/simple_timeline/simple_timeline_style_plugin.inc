<?php
/**
 * @file
 * Contains the simple timeline style plugin.
 * Created by JetBrains PhpStorm.
 * User: alan
 */

/**
 * Style plugin to render each item on a simple timeline.
 *
 * @ingroup views_style_plugins
 */
class simple_timeline_style_plugin extends views_plugin_style_list {

  /**
   * Modifies the default options inherited by this plugin.
   *
   * @return array
   *   The list of options provided by this plugin.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['wrapper_class'] = array('default' => 'item-list simple_timeline');
    return $options;
  }

  /**
   * Modifies the options form inherited by this plugin.
   *
   * @param array $form
   *   The form being generated.
   * @param array $form_state
   *   The state that the form has been posted in.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['type']['#type'] = 'hidden';
    $form['wrapper_class']['#type'] = 'hidden';
  }

  /**
   * Renders the data provided to this plugin.
   *
   * @return string
   *   The rendered html.
   */
  public function render() {
    drupal_add_css(drupal_get_path('module', 'simple_timeline') . '/simple_timeline.css', 'file');
    return parent::render();
  }

  /**
   * Validate whether this plugin is configured correctly.
   *
   * @return array
   *   The list of errors to be displayed.
   */
  public function validate() {
    $errors = array();

    $row_plugin = get_class($this->row_plugin);
    if (!in_array($row_plugin, array(
        'views_plugin_row_node_view',
        'panels_views_plugin_row_fields',
        'simple_timeline_row_plugin',
    ))
    ) {
      $errors[] = t('You have not selected an appropriate row plugin. your timeline will break');
    }
    return $errors;
  }
}
