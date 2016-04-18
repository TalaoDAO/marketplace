<?php

class views_navigation_plugin_entity_row_entity_view extends entity_views_plugin_row_entity_view {

 public function render($values) {
  if ($this->entity_type == 'node' && isset($this->view->views_navigation_cid)) {
   foreach ($this->entities as $node) {
    // The only way we found: look for the alias in the rendered HTML...
    $alias = drupal_get_path_alias('node/' . $node->nid);
    $this->_alter_markups_recursive($this->rendered_content, $alias, $node->nid);
   }
  }
  return parent::render($values);
 }

 private function _alter_markups_recursive(&$element, $alias, $nid) {
   global $base_url;
  if (isset($element['#markup'])) {
   $pattern ='@href="(' . $base_url . ')?/' . trim($alias) . '"@';
   if (preg_match($pattern, $element['#markup'])) {
    module_load_include('inc', 'views_navigation');
    $url = _views_navigation_build_url($nid, $this->view, array('absolute' => FALSE));
    $element['#markup'] = preg_replace($pattern, 'href="' . $url . '"', $element['#markup']);
   }
  }
  foreach(element_children($element) as $key) {
   $this->_alter_markups_recursive($element[$key], $alias, $nid);
  }
 }

}