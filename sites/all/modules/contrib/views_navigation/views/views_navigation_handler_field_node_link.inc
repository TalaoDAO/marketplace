<?php

class views_navigation_handler_field_node_link extends views_handler_field_node_link {

  function render_link($node, $values) {
    $text = parent::render_link($node, $values);
    module_load_include('inc', 'views_navigation');
    $this->options['alter']['path'] = _views_navigation_build_url($node->nid, $this->view);
    return $text;
  }

}
