<?php

class views_navigation_handler_entity_field_field extends entity_views_handler_field_field {

  /**
   * Invoked by EntityFieldHandlerHelper::render_entity_link().
   */
  function render_entity_link($value, $values) {
    return _views_navigation_render_entity_link($this, $value, $values);
  }

}
