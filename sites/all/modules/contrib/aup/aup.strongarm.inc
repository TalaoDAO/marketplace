<?php
/**
 * @file
 * aup.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function aup_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rate_widgets';
  $strongarm->value = array(
    1 => (object) array(
      'name' => 'answers_rating_widget',
      'tag' => 'answers_vote',
      'title' => 'Answers Rating Widget',
      'node_types' => array(
        0 => 'answer',
        1 => 'question',
      ),
      'comment_types' => array(),
      'options' => array(
        0 => array(
          0 => 1,
          1 => '+1',
        ),
        1 => array(
          0 => -1,
          1 => '-1',
        ),
      ),
      'template' => 'number_up_down',
      'node_display' => '2',
      'teaser_display' => TRUE,
      'comment_display' => '2',
      'node_display_mode' => '1',
      'teaser_display_mode' => '1',
      'comment_display_mode' => '1',
      'roles' => array(
        2 => '2',
        3 => 0,
        1 => 0,
      ),
      'allow_voting_by_author' => 1,
      'noperm_behaviour' => '3',
      'displayed' => '1',
      'displayed_just_voted' => '2',
      'description' => '',
      'description_in_compact' => TRUE,
      'value_type' => 'points',
      'theme' => 'rate_template_number_up_down',
      'css' => 'sites/all/modules/rate/templates/number-up-down/number-up-down.css',
      'translate' => FALSE,
      'use_source_translation' => TRUE,
    ),
  );
  $export['rate_widgets'] = $strongarm;

  return $export;
}
