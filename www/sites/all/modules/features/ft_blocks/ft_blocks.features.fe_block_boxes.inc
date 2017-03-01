<?php
/**
 * @file
 * ft_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function ft_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Welcome';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'hp_welcome';
  $fe_block_boxes->body = 'Contenu géré dans le template.';

  $export['hp_welcome'] = $fe_block_boxes;

  return $export;
}
