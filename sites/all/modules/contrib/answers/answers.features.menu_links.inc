<?php
/**
 * @file
 * answers.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function answers_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-using-answers:node/add/question
  $menu_links['menu-using-answers:node/add/question'] = array(
    'menu_name' => 'menu-using-answers',
    'link_path' => 'node/add/question',
    'router_path' => 'node/add/question',
    'link_title' => 'Ask a new question',
    'options' => array(
      'attributes' => array(
        'title' => 'Enter a new question (without first searching for others)',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-using-answers:questions/search
  $menu_links['menu-using-answers:questions/search'] = array(
    'menu_name' => 'menu-using-answers',
    'link_path' => 'questions/search',
    'router_path' => 'questions/search',
    'link_title' => 'Search for a question',
    'options' => array(
      'attributes' => array(
        'title' => 'Search for questions containing keywords or phrases',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-using-answers:questions/start_ask
  $menu_links['menu-using-answers:questions/start_ask'] = array(
    'menu_name' => 'menu-using-answers',
    'link_path' => 'questions/start_ask',
    'router_path' => 'questions/start_ask',
    'link_title' => 'Ask a new question (after searching)',
    'options' => array(
      'attributes' => array(
        'title' => 'First search if a similar question exists, then add yours if not',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Ask a new question');
  t('Ask a new question (after searching)');
  t('Search for a question');


  return $menu_links;
}
