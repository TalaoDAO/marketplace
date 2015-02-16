<?php

/**
 * @file
 * contextual_range_filter.admin.inc
 */

/**
 * Menu callback for selecting which filters should become range filters.
 *
 * From a UI perspective it would make sense to simply have a tick-box on the
 * the Views contextual filter configuration panel. The problem is that at that
 * point the argument handler class has already been selected and instantiated.
 * This is why we make the user define the contextual filter first, then have
 * them select on this page which contextual filters need to be converted to
 * range filters.
 */
function contextual_range_filter_config_form() {

  $range_fields = array(
    // For created & updated date properties on nodes, as opposed to Date field.
    'date_field_names' => array(),
    // List keys must be integers.
    'list_field_names' => array(),
    // Includes properties like nid.
    'numeric_field_names' => array(),
    // Includes properties like node:title.
    'string_field_names' => array(),
  );
  foreach (views_get_all_views() as $view) {
    foreach ($view->display as $display_id => $display) {

      if ($view->set_display($display_id)) {

        $items = $view->get_items('argument', $display_id);

        foreach ($items as $item) {

          $table_data = views_fetch_data($item['table']);
          $field_data = $table_data[$item['field']];

          if (isset($field_data['argument']['handler'])) {

            // All handler classes are identified by their names (i.e. string),
            // so we cannot use instanceof. This means that this code requires
            // PHP 5.3.9
            // @see http://php.net/manual/en/function.is-a.php
            $handler = $field_data['argument']['handler'];

            $is_date_handler = @is_a($handler, 'views_handler_argument_date', TRUE);
            $is_list_handler = @is_a($handler, 'views_handler_argument_field_list', TRUE) || @is_a($handler, 'views_handler_argument_field_list_string', TRUE);
            $is_string_handler = @is_a($handler, 'views_handler_argument_string', TRUE);
            // Numeric covers taxonomy tids, but note:
            // views_handler_argument_term_node_tid_depth and
            // views_handler_argument_term_node_tid_depth_modifier extend
            // views_handler_argument, so aren't covered
            $is_numeric_handler = @is_a($handler, 'views_handler_argument_numeric', TRUE) || @is_a($handler, 'views_handler_argument_comment_user_uid', TRUE);

            if ($is_date_handler || $is_list_handler || $is_numeric_handler || $is_string_handler) {

              // We get one field for every $display_id.
              // Should we allow selection per field AND per display?
              // If not, then we can simplify these nested loops...
              // Currently we find but don't add any additional instances.
              $title = $field_data['title'];
              $full_name = $item['table'] . ':' . $item['field'];
              $view_name = empty($view->human_name) ? $view->name : $view->human_name;
              if (views_view_is_disabled($view)) {
                $view_name .= ' (' . t('disabled') . ')';
              }
              if ($is_date_handler) {
                _contextual_range_filter_add_to_range_fields($range_fields['date_field_names'][$full_name], $title, $view_name);
              }
              elseif ($is_list_handler) {
                _contextual_range_filter_add_to_range_fields($range_fields['list_field_names'][$full_name], $title, $view_name);
              }
              elseif ($is_numeric_handler) {
                _contextual_range_filter_add_to_range_fields($range_fields['numeric_field_names'][$full_name], $title, $view_name);
              }
              elseif ($is_string_handler) {
                _contextual_range_filter_add_to_range_fields($range_fields['string_field_names'][$full_name], $title, $view_name);
              }
            }
          }
        }
      }
    }
  }
  $form['field_names'] = array(
    '#type' => 'fieldset',
    '#title' => t('Select contextual filters to be converted to contextual range filters'),
  );
  $labels = array(t('date'), t('list'), t('numeric'), t('string'));
  $label = reset($labels);
  foreach ($range_fields as $type => $data) {
    $options = array();
    foreach ($data as $full_name => $view_names) {
      $options[$full_name] = t('%field in view: @views', array(
        '%field' => reset($view_names), '@views' => implode(', ', array_slice($view_names, 1))));
      $form['#view_names'][$full_name] = array_slice($view_names, 1);
    }
    $form['field_names']["contextual_range_filter_$type"] = array(
      '#type' => 'checkboxes',
      '#title' => t('Select which of the below contextual <em>@label</em> filters should be converted to <em>@label range</em> filters:', array('@label' => $label)),
      '#default_value' => variable_get("contextual_range_filter_$type", array()),
      '#options' => $options,
    );
    $label = next($labels);
  }
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save contextual filter conversions'),
  );
  $form['#submit'][] = 'contextual_range_filter_config_form_submit';

  $form['#theme'] = 'system_settings_form';
  return $form;
}

/**
 * Execute contextual_range_filter_config_form.
 */
function contextual_range_filter_config_form_submit($form, &$form_state) {

  // Clear out stuff we're not interested with.
  form_state_values_clean($form_state);

  foreach ($form_state['values'] as $type => $filters) {
    // Clear out the unticked boxes.
    $filters = array_filter($form_state['values'][$type]);

    $prev_filters = variable_get($type, array());
    $added_filters = array_diff($filters, $prev_filters);
    $removed_filters = array_diff($prev_filters, $filters);
    $changed_filters = array_merge($added_filters, $removed_filters);

    if (empty($changed_filters)) {
      continue;
    }
    variable_set($type, $filters);

    // Find corresponding Views and save them.
    $changed_view_names = array();
    foreach ($changed_filters as $filter_name) {
      if (isset($form['#view_names'][$filter_name])) {
        $changed_view_names = array_merge($changed_view_names, $form['#view_names'][$filter_name]);
      }
    }
    foreach (views_get_all_views() as $view) {
      $view_name = empty($view->human_name) ? $view->name : $view->human_name;
      if (in_array($view_name, $changed_view_names)) {
        drupal_set_message(t('Saving view %view_name.', array('%view_name' => $view_name)));
        // At this point contextual_range_filter_views_data_alter() has already
        // been called and the new contextual filter handler set.
        $view->save();
      }
    }
  }
  drupal_set_message(t('The contextual range filters have been saved and their corresponding views updated where necessary.'));
}

/**
 * Add to range fields.
 */
function _contextual_range_filter_add_to_range_fields(&$range_field_view_names, $title, $view_name) {
  if (!isset($range_field_view_names)) {
    $range_field_view_names = array($title);
  }
  if (!in_array($view_name, $range_field_view_names)) {
    $range_field_view_names[] = $view_name;
  }
}
