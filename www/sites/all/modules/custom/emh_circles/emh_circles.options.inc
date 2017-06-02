<?php
/**
 * @file
 * Implementations of hooks related to request options.
 */


/**
 * Implements hook_emh_request_options_costs_alter().
 * Alters options costs in function of circles.
 */
function emh_circles_emh_request_options_costs_alter(&$costs, $node) {
  $AJAX = (!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest');
  if ($AJAX) { return;  }

  $circle_items = field_get_items('node', $node, 'og_group_ref');

  if ($circle_items) {
    // Loads circles of the request
    $circle_ids = array();

    foreach ($circle_items as $item) {
      $circle_ids[] = $item['target_id'];
    }

    $circles = node_load_multiple($circle_ids);

    if ($circles) {
      // Compares circles options costs and keeps the highest of each option
      $overwriting = field_get_items('node', reset($circles), 'field_options_costs');

      if (!$overwriting) {
        $overwriting = array();
      } else {
        $overwriting = emh_circles_restructure_option_cost_modifier_items($overwriting);
      }

      while ($circle = next($circles)) {
        $circle_costs = field_get_items('node', $circle, 'field_options_costs');

        if (!$circle_costs) {
          continue;
        }

        foreach ($circle_costs as $cost) {
          if (!isset($overwriting[$cost['option']]) || ($overwriting[$cost['option']] < $cost['cost'])) {
            $overwriting[$cost['option']] = $cost['cost'];
          }
        }
      }

      // Overwrites costs of the request's options with ones provided by circles
      foreach ($costs as $option => &$cost) {
        if (isset($overwriting[$option])) {
          $cost = $overwriting[$option];
        }
      }
    }
  }
}
