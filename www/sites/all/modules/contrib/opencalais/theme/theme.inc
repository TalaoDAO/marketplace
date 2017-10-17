<?php

/**
 * @file
 * Various theme functions.
 */

/**
 * Theme our presets form.
 */
function theme_opencalais_preset_form($vars) {
  $path = drupal_get_path('module', 'opencalais');
  drupal_add_library('system', 'ui.slider');
  drupal_add_js($path . '/theme/opencalais.admin.js');
  drupal_add_css($path . '/theme/opencalais.admin.css');

  $buttons = drupal_render($vars['form']['buttons']);
  $enabled_desc = NULL;
  $threshold_desc = NULL;
  $rows = array();
  foreach (element_children($vars['form']['info']['config']['entities']) as $entity) {
    $settings = $vars['form']['info']['config']['entities'][$entity];
    $enabled_desc = $settings['enabled']['#description'];
    $threshold_desc = $settings['threshold']['#description'];
    unset($settings['enabled']['#description']);
    unset($settings['threshold']['#description']);
    $rows[] = array(
      opencalais_make_camel_case_readable($entity),
      drupal_render($settings['enabled']),
      drupal_render($settings['threshold']),
    );
  }

  $help = array('path' => 'misc/help.png', 'alt' => 'Help');
  $header = array(
    t('Category'),
    t('Enabled?') . theme('image', array_merge($help, array('title' => $enabled_desc))),
    t('Threshold') . theme('image', array_merge($help, array('title' => $threshold_desc))),
  );

  $entity_table = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => 'opencalais_entities'),
  ));
  unset($vars['form']['info']['config']['entities']);

  $output = drupal_render_children($vars['form']);
  $output .= $entity_table;
  $output .= $buttons;
  return $output;
}

/**
 * Theme the form that adds field to entities.
 */
function theme_opencalais_add_fields_entities($vars) {
  $path = drupal_get_path('module', 'opencalais');
  drupal_add_library('system', 'ui.slider');
  drupal_add_js($path . '/theme/opencalais.admin.js');
  drupal_add_css($path . '/theme/opencalais.admin.css');

  $enabled_desc = NULL;
  $threshold_desc = NULL;
  $rows = array();
  foreach (element_children($vars['info']['config']['entities']) as $entity) {
    $settings = $vars['info']['config']['entities'][$entity];
    $enabled_desc = $settings['enabled']['#description'];
    $threshold_desc = $settings['threshold']['#description'];
    unset($settings['enabled']['#description']);
    unset($settings['threshold']['#description']);
    $rows[] = array(
      drupal_render($settings['existing']) . drupal_render($settings['enabled']) . '<span class="opencalais_tag">' . opencalais_make_camel_case_readable($entity) . '</span>',
      drupal_render($settings['threshold']),
    );
  }


  $help = array('path' => 'misc/help.png', 'alt' => 'Help');
  $header = array(
    t('Category') . theme('image', array_merge($help, array('title' => $enabled_desc))),
    t('Threshold') . theme('image', array_merge($help, array('title' => $threshold_desc))),
  );

  $entity_table = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => 'opencalais_entities'),
  ));

  return $entity_table;
}


