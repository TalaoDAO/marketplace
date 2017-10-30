<?php 
/**
 * Test if tags already exist into the node.
 * @param unknown $node
 * @param unknown $val
 * @return boolean
 */
function emh_opencalais_term_is_on_field($node, $val) {
  foreach ($node->field_tags['und'] as $key => $value) {
    foreach ($value as $key_tid => $value_tid) {
      if(!strcmp($val, $value_tid)){
         return TRUE;
      }       
    }
  }
  return FALSE;
}