<?php
/**
 *
 */

class views_dependent_filters_handler_filter_dependent extends views_handler_filter {
  /**
   * The list of filters subsequent to ourselves that we should remove.
   * An array of keys of $this->view->filter.
   */
  var $filters_kill = array();

  /**
   * Disable the filters we control.
   */
  function filters_disable() {
    // This hacks subsequent handlers' options so they are no longer exposed.
    // Incoming values from these on submit will be simply ignored.
    foreach ($this->filters_kill as $filter_id) {
      $this->view->filter[$filter_id]->options['exposed'] = FALSE;
    }
  }

  /**
   * Enable the filters we control.
   */
  function filters_enable() {
    foreach ($this->filters_kill as $filter_id) {
      $this->view->filter[$filter_id]->options['exposed'] = TRUE;
    }
  }

  function option_definition() {
    $options = parent::option_definition();

    // Override the exposed default. This makes no sense not exposed.
    $options['exposed'] = array('default' => TRUE);

    $options['controller_filter'] = array('default' => NULL);
    $options['controller_values'] = array('default' => NULL);
    $options['dependent_filters'] = array('default' => array());


    return $options;
  }

  /**
   * Helper function to provide form options for lists of filters.
   *
   * @param $type
   *  One of 'controller' or 'dependent'.
   *
   * @return
   *  An array of filters suitable for use as Form API options.
   */
  function get_filter_options($type) {
    // Due to http://drupal.org/node/1426094 we can't just go looking in the
    // handlers array on the display.
    $filters = $this->view->display_handler->get_handlers('filter');

    // Get the unique id of this handler (ie allow more than one of this handler).
    $this_id = $this->options['id'];
    $filters_controller = array();
    $filters_dependent  = array();
    $seen = FALSE;
    // Build up the options from all the fields up to this one but no further.
    foreach ($filters as $filter_id => $handler) {
      // Skip non-exposed filters.
      if (!$handler->is_exposed()) {
        continue;
      }
      // Required filters can't be dependent.
      if ($type == 'dependent' && $handler->options['expose']['required']) {
        continue;
      }
      // Note if we get to ourselves and skip.
      if ($filter_id == $this_id) {
        $seen = TRUE;
        continue;
      }
      // Skip other instances of this filter.
      if ($handler->definition['handler'] == 'views_dependent_filters_handler_filter_dependent') {
        continue;
      }

      $label = $handler->ui_name(TRUE);

      // All filters may be controllers, but to simplify things we just allow
      // the ones that come before us.
      if (!$seen) {
        $filters_controller[$filter_id] = $label;
      }
      // Only filters that follow us in the order may be dependent.
      if ($seen) {
        $filters_dependent[$filter_id] = $label;
      }
    }

    switch ($type) {
      case 'controller':
        return $filters_controller;
      case 'dependent':
        return $filters_dependent;
    }
  }

  /**
   * Provide the basic form which calls through to subforms.
   * If overridden, it is best to call through to the parent,
   * or to at least make sure all of the functions in this form
   * are called.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Lock the exposed checkbox.
    $form['expose_button']['checkbox']['checkbox']['#disabled'] = TRUE;
    $form['expose_button']['checkbox']['checkbox']['#description'] = t('This filter is always exposed.');

    // Not sure what the 'expose' button is for as there's the checkbox, but
    // it's not wanted here.
    unset($form['expose_button']['markup']);
    unset($form['expose_button']['button']);

    $filters = $this->view->display_handler->handlers['filter'];

    if (isset($this->options['controller_filter'])) {
      // Get the handler for the controller filter.
      $controller_filter = $filters[$this->options['controller_filter']];

      // Take copies of the form arrays to pass to the other handler.
      $form_copy = $form;
      $form_state_copy = $form_state;

      // Fixup the form so the handler is fooled.
      // For some reason we need to add this for non-ajax admin operation.
      $form_copy['operator']['#type'] = '';

      // Get the value form from the filter handler.
      $controller_filter->value_form($form_copy, $form_state);
      $controller_values_element = $form_copy['value'];

      // Clean up the form element.
      if ($controller_values_element['#type'] == 'checkboxes') {
        // We have to unset the 'select all' option on checkboxes.
        unset($controller_values_element['#options']['all']);
        // Force multiple.
        $controller_values_element['#multiple'] = TRUE;
      }

      // Add it to our own form element in the real form.
      $form['controller_values'] = array(
        '#title' => t('Controller values'),
        '#description' => t('The values on the controller filter that will cause the dependent filters to be visible.'),
        '#default_value' => isset($this->options['controller_values']) ? $this->options['controller_values'] : array(),
      ) + $controller_values_element;
    }

    $options = $this->get_filter_options('dependent');
    $form['dependent_filters'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Dependent filters'),
      '#options' => $options,
      '#default_value' => isset($this->options['dependent_filters']) ? $this->options['dependent_filters'] : array(),
      '#description' => t('The filters which should only be visible and active when the controller filter has the given values.'),
    );
    if (empty($options)) {
      $form['dependent_filters']['#description'] .= ' ' . t('This filter needs other filters to be placed below it in the order to use as dependents.');
    }
  }

  function has_extra_options() { return TRUE; }

  /**
   * Provide defaults for the handler.
   */
  function extra_options(&$option) { }

  /**
   * Extra settings form: select the controller filter.
   *
   * Selecting the controller filter here allows us to nicely show its value
   * form in the regular options form.
   */
  function extra_options_form(&$form, &$form_state) {
    $options = $this->get_filter_options('controller');
    $form['controller_filter'] = array(
      '#type' => 'radios',
      '#title' => t('Controller filter'),
      '#options' => $options,
      '#default_value' => isset($this->options['controller_filter']) ? $this->options['controller_filter'] : '',
      '#description' => t('The exposed filter whose values will be used to control dependent filters. Only filters that are prior to this one in the order are allowed.'),
    );
  }

  /**
   * Override the options form exposed options subform to show nothing, as the
   * options here don't make sense for us.
   */
  function expose_form(&$form, &$form_state) { return; }

  /**
   * Display the filter on the administrative summary.
   */
  function admin_summary() {
    $controller_filter = $this->options['controller_filter'];
    $dependent_filters = implode(', ', array_filter($this->options['dependent_filters']));

    return t("@controller controlling @dependents", array(
      '@controller' => $controller_filter,
      '@dependents' => $dependent_filters,
    ));
  }

  /**
   * Make our changes to the form but don't return anything ourselves.
   */
  function exposed_form(&$form, &$form_state) {
    $filters = $this->view->display_handler->get_handlers('filter');

    // Build an array of dependency info.
    $dependency_info = array(
      // An array keyed by controller filter IDs, where the values are arrays
      // of their possible values.
      // In practice there is only one controller filter, but technically there
      // could be several. The problem is that the admin UI to set them up
      // would become a nightmare, and there's the matter of whether to combine
      // them with AND or OR. Hence one for later, if ever required.
      'controllers' => array(),
      // An array of dependent filter IDs.
      'dependents'  => array(),
      // A lookup of filter IDs to filter URL identifiers.
      'identifiers' => array(),
    );
    if (!empty($this->options['controller_filter'])) {
      $controller_filter = $this->options['controller_filter'];
      $dependency_info['controllers'][$controller_filter] = array();
      if (!empty($this->options['controller_values'])) {
        if (is_array($this->options['controller_values'])) {
          // Filter out the crud from Form API checkboxes and get rid of the
          // keys to avoid confusion: we compare on values further down.
          $controller_values = array_values(array_filter($this->options['controller_values']));
        }
        else {
          $controller_values = array($this->options['controller_values']);
        }

        $dependency_info['controllers'][$controller_filter] = $controller_values;

        $identifier = $filters[$controller_filter]->options['expose']['identifier'];
        $dependency_info['identifiers'][$controller_filter] = $identifier;
      }
    }
    $dependency_info['dependents'] = array_values(array_filter($this->options['dependent_filters']));
    // Populate the identifiers lookup with our dependent filters.
    foreach ($dependency_info['dependents'] as $dependent_filter_id) {
      $identifier = $filters[$dependent_filter_id]->options['expose']['identifier'];
      $dependency_info['identifiers'][$dependent_filter_id] = $identifier;
    }

    //dsm($form_state['input'], 'input');
    $filters = $this->view->display_handler->get_handlers('filter');
    foreach ($dependency_info['controllers'] as $filter_id => $controller_values) {
      // Get the form identifier.
      $identifier = $filters[$filter_id]->options['expose']['identifier'];
      // Get the input for this filter.
      $input = $form_state['input'][$identifier];
      // Convert values for non-multiple filters to an array.
      if (!$this->view->filter[$filter_id]->options['expose']['multiple']) {
        $input = array($input);
      }
      $intersection = array_intersect($input, $controller_values);
      if (!count($intersection)) {
        $this->filters_kill = $dependency_info['dependents'];
      }
    }

    // We can kill the dependent filters now.
    // $this->filters_disable();

    // ...alternatively, leave them there so their form is shown, but prevent
    // them from collecting input.
    // This means the form element can be subject to CTools dependent visiblity
    // and means the user can refine their filtering without an interim
    // submission of the form.
    // @todo: Allow this as an option, ie have a 'no js' version which would
    // just kill dependent filters now.

    // To make the dependent filters change their visibility we need to add a
    // CTools dependent property, but we can't do that here as the form
    // elements for these don't exist yet.
    // Only way to do this is to register an #after_build on the whole form
    // which lives in module code rather than in this handler.
    // Add our settings to the form state as an array, as we need to account
    // for the possiblity that more than one copy of this handler may be
    // playing at once!
    $form_state['dependent_exposed_filters'][] = $dependency_info;
    $form['#after_build'] = array('views_dependent_filters_exposed_form_after_build');

    // Some clean-up for things that come later.
    // Mark ourselves not being exposed now we've done our work. This isn't
    // necessary for Views itself, but allows compatibility with the
    // better_exposed_filters module whose exposed_form_alter() tries to work
    // with all exposed filters.
    $this->options['exposed'] = FALSE;

    // We do nada to the form ourselves.
    return;
  }

  /**
   * Doctor this so the whole form doesn't add our element to $form['#info'].
   *
   * @see views_exposed_form().
   */
  function exposed_info() {
    return;
  }

  /**
   * Prevent the view from accepting input from ourselves and dependents.
   */
  function accept_exposed_input($input) {
    // Disable our dependent filters just before they have a chance to act
    // on exposed input.
    $this->filters_disable();

    // Doctor this so the whole form doesn't go looking for our exposed input.
    return TRUE;
  }

  function value_form(&$form, &$form_state) {
    // Return nothing for the value form.
    $form['value'] = array();
  }

  function query() {
    // Do nothing: fake filter.
  }
}
