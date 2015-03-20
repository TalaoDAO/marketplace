<?php

class views_navigation_plugin_display_extender_views_navigation extends views_plugin_display_extender {

  function options_definition_alter(&$options) {
    $options['views_navigation'] = array(
      'default' => FALSE,
      'translatable' => FALSE,
      'bool' => TRUE,
    );

    $options['views_navigation_cycle'] = array(
      'default' => TRUE,
      'translatable' => FALSE,
      'bool' => TRUE,
    );

    $options['views_navigation_back'] = array(
      'default' => FALSE,
      'translatable' => FALSE,
      'bool' => TRUE,
    );

    $options['views_navigation_title'] = array(
      'default' => FALSE,
      'translatable' => FALSE,
      'bool' => TRUE,
    );

    $options['views_navigation_seo_first'] = array(
      'default' => FALSE,
      'translatable' => FALSE,
      'bool' => TRUE,
    );
  }

  function options_form(&$form, &$form_state) {
    switch ($form_state['section']) {
      case 'views_navigation' :
        $form['#title'] .= t('Views navigation');
        $form['views_navigation'] = array(
          '#type' => 'checkbox',
          '#title' => t('Add navigation links on node pages accessed from this view'),
          '#default_value' => $this->display->get_option('views_navigation'),
        );
        $views_navigation_selector = ':input[name="views_navigation"]';
        $views_navigation_states = array('invisible' => array($views_navigation_selector => array('checked' => FALSE)));
        $form['views_navigation_cycle'] = array(
          '#type' => 'checkbox',
          '#title' => t('Cycling navigation (link to the first on the last node)'),
          '#default_value' => $this->display->get_option('views_navigation_cycle'),
          '#states' => $views_navigation_states,
        );
        $form['views_navigation_back'] = array(
          '#type' => 'checkbox',
          '#title' => t('Add a back link on node pages accessed from this view'),
          '#default_value' => $this->display->get_option('views_navigation_back'),
        );
        $views_navigation_back_selector = ':input[name="views_navigation_back"]';
        $views_navigation_back_states = array('invisible' => array($views_navigation_back_selector => array('checked' => FALSE)));

        $form['views_navigation_title'] = array(
          '#type' => 'checkbox',
          '#title' => t("Use the view's title in back link text"),
          '#default_value' => $this->display->get_option('views_navigation_title'),
          '#states' => $views_navigation_back_states,
        );
        $form['views_navigation_seo_first'] = array(
          '#type' => 'checkbox',
          '#title' => t('Improve SEO at the cost of performance'),
          '#description' => t('This will notably use node titles for link texts. Can be SQL-greedy, to be avoided for big result sets.'),
          '#default_value' => $this->display->get_option('views_navigation_seo_first'),
          '#states' => $views_navigation_states,
        );
        break;
    }
  }

  function options_submit(&$form, &$form_state) {
    switch ($form_state['section']) {
      case 'views_navigation' :
        $this->display->set_option('views_navigation', $form_state['values']['views_navigation']);
        $this->display->set_option('views_navigation_cycle', $form_state['values']['views_navigation_cycle']);
        $this->display->set_option('views_navigation_back', $form_state['values']['views_navigation_back']);
        $this->display->set_option('views_navigation_title', $form_state['values']['views_navigation_title']);
        $this->display->set_option('views_navigation_seo_first', $form_state['values']['views_navigation_seo_first']);
        break;
    }
  }

  function options_summary(&$categories, &$options) {
    $options['views_navigation'] = array(
      'category' => 'other',
      'title' => t('Views navigation'),
      'desc' => t('Add navigation links on node pages accessed from this view.'),
    );
    if ($this->display->get_option('views_navigation')) {
      if ($this->display->get_option('views_navigation_cycle')) {
        $value = t('Cycling navigation');
      }
      else {
        $value = t('Linear navigation');
      }
      if ($this->display->get_option('views_navigation_seo_first')) {
        $value .= ', ' . t('SEO first');
      }
      else {
        $value .= ', ' . t('performance first');
      }
      if ($this->display->get_option('views_navigation_back')) {
        $value .= ' + ' . t('Back link');
        if ($this->display->get_option('views_navigation_title')) {
          $value .= t(" with view's title");
        }
      }
    }
    else {
      if ($this->display->get_option('views_navigation_back')) {
        $value = t('Back link');
        if ($this->display->get_option('views_navigation_title')) {
          $value .= t(" with view's title");
        }
      }
      else {
        $value = t('None');
      }
    }

    $options['views_navigation']['value'] = $value;
  }

}
