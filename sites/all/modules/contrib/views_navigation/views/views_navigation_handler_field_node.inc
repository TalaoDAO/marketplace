<?php

class views_navigation_handler_field_node extends views_handler_field_node {

  function render_link($data, $values) {
    $data = parent::render_link($data, $values);
    if (!empty($this->options['link_to_node'])) {
      module_load_include('inc', 'views_navigation');
      $this->options['alter']['path'] = _views_navigation_build_url($this->get_value($values, 'nid'), $this->view);
    }
    return $data;
  }

}
