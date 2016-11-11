<?php
/**
 * @file
 * ft_front.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function ft_front_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Profitez des avantages des communautés privées';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'emh_hp_community';
  $fe_block_boxes->body = '<p>Contenu géré dans le template.</p>
';

  $export['emh_hp_community'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Domains of expertise';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'emh_hp_domains';
  $fe_block_boxes->body = '<p>Contenu géré dans le template.</p>
';

  $export['emh_hp_domains'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - How it works?';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'emh_hp_how';
  $fe_block_boxes->body = '<p>Contenu géré dans le template.</p>
';

  $export['emh_hp_how'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Persona';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'emh_hp_persona';
  $fe_block_boxes->body = '<p>Contenu géré dans le template.</p>
';

  $export['emh_hp_persona'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'HP - Ils nous ont fait confiance';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'emh_hp_references';
  $fe_block_boxes->body = '<p>Contenu géré dans le template.</p>
';

  $export['emh_hp_references'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Login & connexion modal';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'emh_login_connexion';
  $fe_block_boxes->body = '<p>Contenu géré dans le template.</p>
';

  $export['emh_login_connexion'] = $fe_block_boxes;

  return $export;
}
