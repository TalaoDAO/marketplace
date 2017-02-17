<?php

/**
 * @file
 * Code for eMindHub circles pages feature.
 */

function emh_circles_instructions_page($nid) {
  $node = node_load($nid);

  $instructions_content = '';
  if (!empty(field_get_items('node', $node, 'field_circle_instructions'))) {
    $instructions_content = field_view_field('node', $node, 'field_circle_instructions', array('label' => 'hidden'));
  }

  $qa_content = '';
  if (!empty(field_get_items('node', $node, 'field_circle_qa'))) {
    $qa_content = field_view_field('node', $node, 'field_circle_qa', array('label' => 'hidden'));
  }

  return theme('emh_circles_instructions_page', array(
    'instructions' => $instructions_content,
    'qa' => $qa_content,
  ));
}

function emh_circles_instructions_page_access($nid) {
  global $user;

  return (node_load($nid)->type == 'circle' && (og_is_member('node', $nid, 'user', $user))) ? TRUE : FALSE;
}
