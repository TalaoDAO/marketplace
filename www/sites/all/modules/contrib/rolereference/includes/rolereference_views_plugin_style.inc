<?php
// $Id$

/**
 * @file
 * Handler for node_reference_views_plugin_style.
 */
class rolereference_views_plugin_style extends views_plugin_style {
  function render() {
    $results = array();

    // Group the rows according to the grouping field, if specified.
    $sets = $this->render_grouping($this->view->result, $this->options['grouping']);

    $base_field = $this->view->base_field;
    $title_field = $this->display->display_options['node_reference_title_field'];
    $title_field_alias = $this->view->field[$title_field]->field_alias;

    // TODO : We don't display grouping info for now.
    // Could be useful for select widget, though.
    $this->view->row_index = 0;
    foreach ($sets as $title => $records) {
      foreach ($records as $label => $row) {
        $results[$row->{$base_field}] = array(
          'title' => check_plain($row->{$title_field_alias}),
          'rendered' => $this->row_plugin->render($row),
        );
        $this->view->row_index++;
      }
    }
    unset($this->view->row_index);
    return $results;
  }
}
