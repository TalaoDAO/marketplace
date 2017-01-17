<?php
/**
 * @file
 * ft_request.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function ft_request_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Create a request';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hp_challenge';
  $fe_block_boxes->body = '<p>Contenu géré dans le template.</p>
';

  $export['hp_challenge'] = $fe_block_boxes;

  return $export;
}
