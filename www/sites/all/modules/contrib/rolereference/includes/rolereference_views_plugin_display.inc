<?php
// $Id$

/**
 * @file
 * Handler for node_reference_views_plugin_display.
 */
class rolereference_views_plugin_display extends views_plugin_display {
  function execute() {
    return $this->view->render($this->display->id);
  }

  function render() {
    return !empty($this->view->result) || !empty($this->view->style_plugin->definition['even empty']) ? $this->view->style_plugin->render($this->view->result) : '';
  }

  function uses_exposed() {
    return FALSE;
  }

  function query() {
    $options = $this->get_option('rolereference_options');

    if ($options['string'] !== '') {
      $like = db_driver() == 'pgsql' ? "ILIKE" : "LIKE";
      $match_clauses = array(
        'contains' => array(
          'operator' => $like,
          'value' => '%' . $options['string'] . '%',
        ),
        'equals' => array(
          'operator' => '=',
          'value' => $options['string'],
        ),
        'starts_with' => array(
          'operator' => $like,
          'value' => $options['string'] . '%',
        ),
      );
      $clause = isset($match_clauses[$options['match']]) ? $match_clauses[$options['match']] : $match_clauses['contains'];
      $alias = $this->view->query->ensure_table($options['table']);
      $this->view->query->add_where(NULL, "$alias.$options[field_string]", $clause['value'], $clause['operator']);
    }
    elseif ($options['ids']) {
      $alias = $this->view->query->ensure_table($options['table']);
      $this->view->query->add_where(NULL, "$alias.$options[field_id]", $options['ids'], 'IN');
    }
  }
}