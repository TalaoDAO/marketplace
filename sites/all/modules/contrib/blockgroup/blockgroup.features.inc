<?php
/**
 * @file
 * Features integration for Block Group module.
 */

/**
 * Implements [component]_features_export_options().
 */
function blockgroup_features_export_options() {
  return blockgroup_list();
}

/**
 * Implements [component]_features_export().
 */
function blockgroup_features_export($data, &$export, $module_name = '') {
  $pipe = array();
  $blockgroups = blockgroup_list();

  $export['dependencies']['features'] = 'features';
  $export['dependencies']['blockgroup'] = 'blockgroup';

  foreach ($data as $delta) {
    if (isset($blockgroups[$delta])) {
      $export['features']['blockgroup'][$delta] = $delta;
    }
  }

  return $pipe;
}

/**
 * Implements hook_features_pipe_COMPONENT_alter().
 */
function blockgroup_features_pipe_fe_block_settings_alter(&$pipe, $data, $export) {
  foreach ($data as $block_id) {
    // Add blockgroup if a block settings for a block group are about to be
    // exported.
    if (strpos($block_id, 'blockgroup-') === 0) {
      $delta = substr($block_id, strlen('blockgroup-'));
      $pipe['blockgroup'][$delta] = $delta;
    }
  }
}

/**
 * Implements [component]_features_export_render().
 */
function blockgroup_features_export_render($module, $data) {
  $blockgroups = blockgroup_list();
  $code = array();

  foreach ($data as $delta) {
    if (isset($blockgroups[$delta])) {
      $code[$delta] = $blockgroups[$delta];
    }
  }

  $code = "  return " . features_var_export($code, '  ') . ";";
  return array('default_blockgroups' => $code);
}

/**
 * Implements [component]_features_revert().
 */
function blockgroup_features_revert($module) {
  blockgroup_features_rebuild($module);
}

/**
 * Implements [component]_features_rebuild().
 */
function blockgroup_features_rebuild($module) {
  $blockgroups = blockgroup_list();
  $default_blockgroups = module_invoke($module, 'default_blockgroups');

  foreach ($default_blockgroups as $delta => $title) {
    $blockgroup = blockgroup_load($delta);

    if (!$blockgroup) {
      $blockgroup = (object) array(
        'title' => $title,
        'delta' => $delta,
      );
      blockgroup_add($blockgroup);
    }
  }
}

/**
 * Implements hook_post_features_revert().
 */
function blockgroup_post_features_revert($component) {
  blockgroup_post_features_rebuild($component);
}

/**
 * Implements hook_post_features_rebuild().
 */
function blockgroup_post_features_rebuild($component) {
  if ($component == 'blockgroup') {
    blockgroup_rebuild_data();
  }
}
