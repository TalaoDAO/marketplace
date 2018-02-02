<?php

/**
 * @file
 * Formatter functionality for Ghost.
 *
 * @license GPL v2 http://www.fsf.org/licensing/licenses/gpl.html
 * @author Chris Skene chris at xtfer dot com
 */

/**
 * Implements hook_field_formatter_info().
 */
function ghost_field_formatter_info() {

  return \Drupal\ghost\Core\Formatters\FormatterManager::init()->fieldFormatterInfo();
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function ghost_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {

  return \Drupal\ghost\Core\Formatters\FormatterManager::init()->fieldFormatterSettingsForm($field, $instance, $view_mode, $form, $form_state);
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function ghost_field_formatter_settings_summary($field, $instance, $view_mode) {

  return \Drupal\ghost\Core\Formatters\FormatterManager::init()->fieldFormatterSettingsSummary($field, $instance, $view_mode);
}

/**
 * Implements hook_field_formatter_view().
 */
function ghost_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {

  return \Drupal\ghost\Core\Formatters\FormatterManager::init()->fieldFormatterView($entity_type, $entity, $field, $instance, $langcode, $items, $display);
}
