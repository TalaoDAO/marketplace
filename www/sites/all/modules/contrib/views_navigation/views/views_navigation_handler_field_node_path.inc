<?php

class views_navigation_handler_field_node_path extends views_handler_field_node_path {

  function render($values) {
    module_load_include('inc', 'views_navigation');
    return _views_navigation_build_url($this->get_value($values, 'nid'), $this->view, array('absolute' => $this->options['absolute']));
  }

}
