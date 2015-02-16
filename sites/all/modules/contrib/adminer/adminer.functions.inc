<?php

/**
 * @file
 * Helper functions for Adminer module.
 */

/**
 * Returns all installed Adminer versions.
 */
function adminer_get_all_php() {
  static $files = NULL;
  if (NULL === $files) {
    $adminer_path = drupal_get_path('module', 'adminer') . '/adminer';
    $adminer_files = file_scan_directory($adminer_path, '/adminer-([0-9]+)\.([0-9]+)\.([0-9]+)\.php$/');
    $files = array();
    foreach ($adminer_files as $file) {
      $files[$file->uri] = $file->filename;
    }
  }
  return $files;
}

/**
 * Returns current Adminer.php file path.
 */
function adminer_get_php() {
  static $php = NULL;
  if (NULL === $php) {
    $php = variable_get('adminer_php', '');
    if (!$php) {
      $files = adminer_get_all_php();
      $php = reset(array_keys($files));
      variable_set('adminer_php', $php);
    }
  }
  return $php;
}

/**
 * Returns all available Adminer styles.
 */
function adminer_get_all_css() {
  static $files = NULL;
  if (NULL === $files) {
    $css_path = drupal_get_path('module', 'adminer') . '/adminer/styles';
    $css_files = file_scan_directory($css_path, '/[a-zA-Z0-9\-\_\ \.]\.css$/');
    $files = array();
    foreach ($css_files as $file) {
      $files[$file->uri] = $file->filename;
    }
  }
  return $files;
}

/**
 * Returns current style.
 */
function adminer_get_css() {
  static $css = NULL;
  if (NULL === $css) {
    $css = variable_get('adminer_css', '');
    if (!$css) {
      $files = adminer_get_all_css();
      $css = reset(array_keys($files));
      variable_set('adminer_css', $css);
    }
    if (!file_exists($css)) {
      $css = '';
    }
  }
  return $css;
}

/**
 * Returns all supported Adminer plugins.
 */
function adminer_get_all_plugins() {
  $module_path = drupal_get_path('module', 'adminer') . '/';
  $plugins_path = $module_path . 'adminer/plugins/';
  return array(
    'plugin' => array(
      'path' => $plugins_path . 'plugin.php',
      'description' => t('Required to run any plugin'),
      'url' => 'https://raw.github.com/vrana/adminer/master/plugins/plugin.php',
      'required' => TRUE,
    ),
    'frames' => array(
      'path' => $plugins_path . 'frames.php',
      'class' => 'AdminerFrames',
      'description' => t('Allow using Adminer inside a frame'),
      'url' => 'https://raw.github.com/vrana/adminer/master/plugins/frames.php',
      'required' => TRUE,
    ),
    'version-noverify' => array(
      'path' => $plugins_path . 'version-noverify.php',
      'class' => 'AdminerVersionNoverify',
      'description' => t('Disable version checker'),
      'url' => 'https://raw.github.com/vrana/adminer/master/plugins/version-noverify.php',
      'required' => TRUE,
    ),
    'edit-textarea' => array(
      'path' => $plugins_path . 'edit-textarea.php',
      'class' => 'AdminerEditTextarea',
      'description' => t('Use <textarea> for char and varchar'),
      'url' => 'https://raw.github.com/vrana/adminer/master/plugins/edit-textarea.php',
    ),
    'enum-option' => array(
      'path' => $plugins_path . 'enum-option.php',
      'class' => 'AdminerEnumOption',
      'description' => t('Use <select><option> for enum edit instead of <input type="radio">'),
      'url' => 'https://raw.github.com/vrana/adminer/master/plugins/enum-option.php',
    ),
    'drupal' => array(
      'path' => $module_path . 'adminer.plugin.inc',
      'class' => 'AdminerDrupal',
      'description' => t('Required to run Adminer with Drupal'),
      'required' => TRUE,
    ),
  );
}

/**
 * Returns installed plugins.
 */
function adminer_get_plugins() {
  static $plugins = NULL;
  if (NULL === $plugins) {
    $all_plugins = adminer_get_all_plugins();
    foreach ($all_plugins as $name => $plugin) {
      if (file_exists($plugin['path'])) {
        $plugins[$name] = $name;
      }
    }
  }
  return $plugins;
}

/**
 * Check all required components.
 */
function adminer_check_components() {
  $params = array('!settings' => l(t('settings'), 'admin/config/development/adminer/settings'));
  $php = adminer_get_php();
  if (!file_exists($php)) {
    drupal_set_message(filter_xss_admin(t('Adminer not installed. Please check !settings', $params)), 'error');
    return FALSE;
  }
  $plugins = adminer_get_plugins();
  if (!isset($plugins['plugin']) || !isset($plugins['frames']) || !isset($plugins['version-noverify'])) {
    drupal_set_message(filter_xss_admin(t('Required plugin(s) not installed. Please check !settings', $params)), 'error');
    return FALSE;
  }
  return TRUE;
}
