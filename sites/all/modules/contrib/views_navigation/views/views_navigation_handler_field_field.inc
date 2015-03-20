<?php

class views_navigation_handler_field_field extends views_handler_field_field {

  function render_item($count, $item) {
    if ($this->base_table == 'node' && $this->options['type'] == 'image' && $this->options['settings']['image_link'] == 'content' && !$this->options['alter']['make_link']) {
      $query = &$item['rendered']['#path']['options']['query'];
      if (!isset($query)) {
        $query = array();
      }
      module_load_include('inc', 'views_navigation');
      $query = _views_navigation_build_query($item['rendered']['#path']['options']['entity']->nid, $this->view, $query);
    }
    return parent::render_item($count, $item);
  }

}
