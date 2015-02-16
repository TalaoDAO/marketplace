<?php

/**
 * @file
 * Contains the i18n page display plugin.
 */

/**
 * The plugin that handles a full page.
 *
 * @ingroup views_display_plugins
 */
class views_plugin_display_i18n_page extends views_plugin_display {
  /**
   * The page display has a path.
   */
  function has_path() { return TRUE; }
  function uses_breadcrumb() { return TRUE; }

  function option_definition() {
    $options = parent::option_definition();

    $languages = locale_language_list();
    foreach ($languages as $langcode => $langname) {
      $options['path_' . $langcode] = array('default' => '');
    }

    return $options;
  }

  /**
   * Add this display's path information to Drupal's menu system.
   */
  function execute_hook_menu($callbacks) {
    $items = array();
    // Replace % with the link to our standard views argument loader
    // views_arg_load -- which lives in views.module

    $languages = locale_language_list();
    foreach ($languages as $langcode => $langname) {
      $bits = explode('/', $this->get_option('path_' . $langcode));
      $page_arguments = array($this->view->name, $this->display->id);

      // Replace % with %views_arg for menu autoloading and add to the
      // page arguments so the argument actually comes through.
      foreach($bits as $pos => $bit) {
        if ($bit == '%') {
          $bits[$pos] = '%views_arg';
          $page_arguments[] = $pos;
        }
      }

      $path = implode('/', $bits);

      $access_plugin = $this->get_plugin('access');
      if (!isset($access_plugin)) {
        $access_plugin = views_get_plugin('access', 'none');
      }
      
      if ($path) {
        $items[$path] = array(
          // default views page entry
          'page callback' => 'views_page',
          'page arguments' => $page_arguments,
          // Default access check (per display)
          'access callback' => 'views_access',
          'access arguments' => array($access_plugin->get_access_callback()),
          // Identify URL embedded arguments and correlate them to a handler
          'load arguments'  => array($this->view->name, $this->display->id, '%index'),
        );
        $menu = array('type' => 'none');
        $items[$path]['type'] = MENU_CALLBACK;
      }
    }

    return $items;
  }

  /**
   * The display page handler returns a normal view, but it also does
   * a drupal_set_title for the page, and does a views_set_page_view
   * on the view.
   */
  function execute() {
    // Let the world know that this is the page view we're using.
    views_set_page_view($this->view);

    // Prior to this being called, the $view should already be set to this
    // display, and arguments should be set on the view.
    $this->view->build();
    if (!empty($this->view->build_info['fail'])) {
      return drupal_not_found();
    }

    $this->view->get_breadcrumb(TRUE);

    // And the title, which is much easier.
    drupal_set_title(filter_xss_admin($this->view->get_title()), PASS_THROUGH);

    // And now render the view.
    return $this->view->render();
  }

  /**
   * Provide the summary for page options in the views UI.
   *
   * This output is returned as an array.
   */
  function options_summary(&$categories, &$options) {
    // It is very important to call the parent function here:
    parent::options_summary($categories, $options);

    $categories['page'] = array(
      'title' => t('Page settings'),
      'column' => 'second',
      'build' => array(
        '#weight' => -10,
      ),
    );

    $languages = locale_language_list();
    foreach ($languages as $langcode => $langname) {
      $path = strip_tags($this->get_option('path_' . $langcode));
      if (empty($path)) {
        $path = t('None');
      }

      $options['path_' . $langcode] = array(
        'category' => 'page',
        'title' => t('Path in %language', array('%language' => $langname)),
        'value' => views_ui_truncate($path, 24),
      );
    }
  }

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_form($form, $form_state);
    
    $key = $form_state['section'];

    if (stristr($key, 'path_') === FALSE)
      return;

    $form['#title'] .= t('The menu path or URL of this view');
    $form['#help_topic'] = 'path';
    
    $form[$key] = array(
      '#type' => 'textfield',
      '#description' => t('This view will be displayed by visiting this path on your site. You may use "%" in your URL to represent values that will be used for arguments: For example, "node/%/feed".'),
      '#default_value' => $this->get_option($key),
      '#field_prefix' => '<span dir="ltr">' . url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
      '#field_suffix' => '</span>&lrm;',
      '#attributes' => array('dir'=>'ltr'),
    );
  }

  function options_validate(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_validate($form, $form_state);
    $key = $form_state['section'];

    if (stristr($key, 'path_') === FALSE) {
      return;
    }

    if (strpos($form_state['values'][$key], '$arg') !== FALSE) {
      form_error($form[$key], t('"$arg" is no longer supported. Use % instead.'));
    }

    if (strpos($form_state['values'][$key], '%') === 0) {
      form_error($form[$key], t('"%" may not be used for the first segment of a path.'));
    }

    // automatically remove '/' from path.
    $form_state['values'][$key] = trim($form_state['values'][$key], '/');

  }

  function options_submit(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_submit($form, $form_state);
    $key = $form_state['section'];

    $this->set_option($key, $form_state['values'][$key]);
  }

  function validate() {
    $errors = parent::validate();

    $languages = locale_language_list();
    foreach ($languages as $langcode => $langname) {
      if (!$this->get_option('path_'. $langcode)) {
        return $errors;
      }
    }
  }
  
  /**
   * Return the base path to use for this display based on language interface
   */
  function get_path() {
    global $language;
    
    if ($this->has_path()) {
      return $this->get_option('path_' . $language->language);
    }

    $display_id = $this->get_link_display();
    if ($display_id && !empty($this->view->display[$display_id]) && is_object($this->view->display[$display_id]->handler)) {
      return $this->view->display[$display_id]->handler->get_path();
    }
  }
}
