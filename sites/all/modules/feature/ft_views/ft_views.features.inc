<?php
/**
 * @file
 * ft_views.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ft_views_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_homebox().
 */
function ft_views_homebox() {
  $homeboxes = array();

  $homeboxes['mybox'] = array(
    'regions' => 2,
    'cache' => 0,
    'color' => 1,
    'colors' => array(
      0 => '#E4F0F8',
      1 => '#E4F0F8',
      2 => '#E4F0F8',
      3 => '#E4F0F8',
      4 => '#E4F0F8',
      5 => '#E4F0F8',
    ),
    'blocks' => array(
      'blog_recent' => array(
        'module' => 'blog',
        'delta' => 'recent',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -33,
      ),
      'views_mes_articles-block' => array(
        'module' => 'views',
        'delta' => 'mes_articles-block',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -32,
      ),
      'views_my_drafts-block_1' => array(
        'module' => 'views',
        'delta' => 'my_drafts-block_1',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -32,
      ),
      'forum_active' => array(
        'module' => 'forum',
        'delta' => 'active',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -31,
      ),
      'views_r_f_rents_list-block' => array(
        'module' => 'views',
        'delta' => 'r_f_rents_list-block',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -31,
      ),
      'comment_recent' => array(
        'module' => 'comment',
        'delta' => 'recent',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -30,
      ),
      'user_new' => array(
        'module' => 'user',
        'delta' => 'new',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -30,
      ),
      'views_mes_contributions-block' => array(
        'module' => 'views',
        'delta' => 'mes_contributions-block',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -29,
      ),
      'views_expert_challenges-block' => array(
        'module' => 'views',
        'delta' => 'expert_challenges-block',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => 'My Recommended Challenges',
        'weight' => -28,
      ),
    ),
    'widths' => array(),
    'title' => 'My Box',
    'path' => 'mybox',
    'menu' => 1,
    'enabled' => 1,
    'auto_save' => 1,
    'full' => 0,
    'roles' => array(
      0 => 'authenticated user',
    ),
  );


  return $homeboxes;
}
