<?php
/**
 * @file
 * Logic functions.
 */

/**
 * Return default display settings.
 */
function _config_pages_get_internal_default_panelizer($bundle, $view_mode) {
  ctools_include('export');
  $load_name = implode(':', array('config_pages', $bundle, 'default'));
  $panelizer = ctools_export_crud_new('panelizer_defaults');
  $panelizer->name = $load_name;
  // Attach the view mode to the name, which is specially generated
  // to ignore the specialty "page_manager" view mode.
  if ($view_mode != 'page_manager') {
    $panelizer->name .= ':' . $view_mode;
  }

  // This is a straight up empty display.
  $display = panels_new_display();
  $display->layout = 'flexible';

  $panelizer->panelizer_type = 'config_pages';
  $panelizer->panelizer_key = $bundle;
  $panelizer->view_mode = $view_mode;
  $panelizer->display = $display;
  $panelizer->api_version = 1;
  $panelizer->title = t('Default');

  return $panelizer;
}

/**
 * Fetch config value.
 *
 * @param $field_name
 *   (str) field name.
 * @param $delta
 *   (int/array) specify which deltas to return.
 * @param $default
 *   (any) will be returned if config missing
 * @param $key
 *   (string) inner field key, like 'value' or 'target_id', if not provided - result is based on field common usage.
 * @param $context
 *   (sting) specify context string, if not provided will use default context.
 */
function config_pages_get($type, $field_name, $default = NULL, $delta = 0, $key = NULL, $context = NULL) {

  $instance = field_info_instance('config_pages', $field_name, $type);

  // Load config.
  if ($context === NULL) {
    $context = config_pages_context_get($type);
  }
  $config = config_pages_load_entity($type, $context);

  // Get field info.
  if (empty($key) && !is_array($key)) {
    $keys_known = array(
      'number' => 'value',
      'text' => 'value',
      'list' => 'value',
      'image' => array(),
    );
    $field = field_info_field($field_name);
    if (!empty($keys_known[$field['module']])) {
      $key = $keys_known[$field['module']];
    }
    else {
      $key = array();
    }
  }

  // Load items.
  if (!empty($config)) {
    $items = field_get_items('config_pages', $config, $field_name);
  }
  else {
    // Default field values used.
    $items = !empty($instance['default_value'])
      ? $instance['default_value']
      : array();
  }
  $deltas = is_array($delta) ? $delta : array($delta);
  if (empty($deltas)) {
    $deltas = is_array($items)
      ? array_keys($items)
      : array();
  }

  // Fetch info for given deltas.
  $result = array();
  foreach ($deltas as $_delta) {
    $result[$_delta] = isset($items[$_delta]) ? $items[$_delta] : $default;
    if (is_array($result[$_delta]) && !empty($key) && !is_array($key)) {
      $result[$_delta] = isset($result[$_delta][$key]) ? $result[$_delta][$key] : $default;
    }
  }

  return (is_array($delta))
    ? $result
    : $result[$delta];

}

/**
 * Returns config pages metawrapper.
 */
function config_pages_config($type, $context = NULL) {
  $config_entity = config_pages_load_entity($type, $context);
  if ($config_entity) {
    $wrapper = entity_metadata_wrapper('config_pages', $config_entity);
  }
  else {
    $wrapper = NULL;
  }
  return $wrapper;
}

/**
 * Theme specified config.
 *
 * Since config is just an entity it can be themed.
 */
function config_pages_render($type, $context = NULL, $view_mode = 'full', $render = TRUE) {

  // Load config.
  if ($context === NULL) {
    $context = config_pages_context_get($type);
  }
  $config = config_pages_load_entity($type, $context);
  if (empty($config)) {
    return '';
  }

  // Build entity content.
  $content = entity_view('config_pages', array($config), $view_mode);

  // Return result.
  return !empty($render)
    ? drupal_render($content)
    : $content;

}

/**
 * Theme specified config.
 *
 * Since config is just an entity it can be themed.
 */
function config_pages_render_field($type, $filed_name, $delta = 0, $context = NULL, $view_mode = 'full', $render = TRUE) {

  // Load config.
  if ($context === NULL) {
    $context = config_pages_context_get($type);
  }
  $config = config_pages_load_entity($type, $context);
  if (empty($config)) {
    return '';
  }

  // Build fields content.
  $content = array();
  $items = config_pages_get($type, $filed_name, NULL, $delta, array(), $context);
  if (is_array($delta) && is_array($items)) {
    foreach ($items as $item) {
      $content[] = field_view_value('config_pages', $config, $filed_name, $item, $view_mode);
    }
  }
  else {
    $content = field_view_value('config_pages', $config, $filed_name, $items, $view_mode);
  }

  // Return result.
  return !empty($render)
    ? drupal_render($content)
    : $content;

}

/**
 * Get available context groups.
 */
function config_pages_context_groups($type = FALSE) {
  $list = module_invoke_all('config_pages_context_groups');
  drupal_alter('config_pages_context_groups', $list);

  // Filter groups by given type.
  if (!empty($type) && $config_type = config_pages_get_types($type)) {
    $groups = array_filter($config_type->data['context']['group']);
    $list = array_intersect_key($list, $groups);
  }
  return $list;
}

/**
 * Return current context based on groups.
 */
function config_pages_context_get($type) {
  $context = array();

  // Check which context groups applicable to this config.
  $groups = array_keys(config_pages_context_groups($type));

  if (!empty($groups)) {

    // Sort array to keep context persistent.
    sort($groups);

    // Get context values for each group.
    foreach ($groups as $group) {
      list($module, $key) = explode(':', $group);
      $value = module_invoke($module, 'config_pages_context_value', $key);
      $value = strtr($value, array(':' => '', ';' => '', '=' => ''));
      if (!empty($value)) {
        $context[$group] = $value;
      }
    }
  }

  // Allow modules to alter context.
  drupal_alter('config_pages_context_get', $context, $type);

  // Plain groups
  foreach ($context as $group => $value) {
    $context[$group] = $group . '=' . $value;
  }

  // Return context string.
  return implode(';', $context);
}

/**
 * Return human readable representation of the context.
 */
function config_pages_context_label($context) {
  if (empty($context)) {
    return t('Global');
  }
  $label = array();
  $context = explode(';', $context);
  foreach ($context as $item) {
    list($group, $value) = explode('=', $item);
    list($module, $key) = explode(':', $group);
    $item = module_invoke($module, 'config_pages_context_label', $key, $value);
    if (empty($item)) {
      $item = $key . '=' . $value;
    }
    $label[] = $item;
  }
  return implode('; ', $label);
}

/**
 * Load configuration entity.
 */
function config_pages_load_entity($type = '', $context = NULL, $all = FALSE) {

  $conditions = array();

  // Build conditions.
  if (!empty($type)) {
    $conditions['type'] = $type;

    // Get current context if NULL.
    if (!$all && $context === NULL) {
      $context = config_pages_context_get($type);
    }
    if (!$all) {
      $conditions['context'] = $context;
    }
  }

  $list = entity_load('config_pages', FALSE, $conditions);

  return $all
    ? $list
    : current($list);
}