<?php
/**
 * @file
 * ft_blocks.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ft_blocks_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-beta'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'machine_name' => 'beta',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -46,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['block-expert_avantages'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'expert_avantages',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'expert/register',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -40,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'What are the main benefits for experts?',
    'visibility' => 1,
  );

  $export['block-experts_points_info'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'machine_name' => 'experts_points_info',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'expert' => 4,
      'référent' => 7,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -36,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['block-home_register'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'home_register',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>
expert/register
business/register
freetrial',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -43,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Registration',
    'visibility' => 0,
  );

  $export['block-hp_baseline'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_baseline',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -49,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['block-hp_challenge'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_challenge',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'top',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -47,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['block-hp_expertise'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_expertise',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -49,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['block-hp_experts'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_experts',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -35,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Our value proposition',
    'visibility' => 1,
  );

  $export['block-hp_experts_picto'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_experts_picto',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -48,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'You are',
    'visibility' => 1,
  );

  $export['block-hp_experts_text'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_experts_text',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -47,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['block-hp_mobilize'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_mobilize',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -47,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['block-hp_question'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_question',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'top',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -49,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['block-hp_request'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_request',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -49,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['block-hp_survey'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_survey',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'top',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -48,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['block-hp_welcome'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_welcome',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'title',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -45,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['block-hp_why'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_why',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -48,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'You are',
    'visibility' => 1,
  );

  $export['block-hp_why_quality'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_why_quality',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -34,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Quality',
    'visibility' => 1,
  );

  $export['block-hp_why_rapidity'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_why_rapidity',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -33,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Rapidity',
    'visibility' => 1,
  );

  $export['block-hp_why_security'] = array(
    'cache' => -1,
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'machine_name' => 'hp_why_security',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -37,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Confidentiality',
    'visibility' => 1,
  );

  $export['bootstrap_languages-language'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'language',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'bootstrap_languages',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -43,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['emh_request-request_help_challenge'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'request_help_challenge',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'emh_request',
    'node_types' => array(),
    'pages' => 'node/add/challenge',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -46,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -100,
      ),
    ),
    'title' => 'Help_challenges',
    'visibility' => 1,
  );

  $export['emh_request-request_help_question1'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'request_help_question1',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'emh_request',
    'node_types' => array(),
    'pages' => 'node/add/question1',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -45,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -100,
      ),
    ),
    'title' => 'Help_questions',
    'visibility' => 1,
  );

  $export['emh_request-request_help_webform'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'request_help_webform',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'emh_request',
    'node_types' => array(),
    'pages' => 'node/add/webform',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -44,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -100,
      ),
    ),
    'title' => 'Help_surveys',
    'visibility' => 1,
  );

  $export['menu-menu-burger-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-burger-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -47,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Shortcuts',
    'visibility' => 0,
  );

  $export['menu-menu-footer-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -45,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-networks'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-networks',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -44,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-top'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-top',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['menu-menu-top-anonymous'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-top-anonymous',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['og_extras-node_links'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'node_links',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'og_extras',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -44,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Participate to the Challenge',
    'visibility' => 0,
  );

  $export['pcp-pcp_profile_percent_complete'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'pcp_profile_percent_complete',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'pcp',
    'node_types' => array(),
    'pages' => '<front>
my-responses
my-selections
requests',
    'roles' => array(
      'expert' => 4,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'highlighted',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Complete your profile and get launched!',
    'visibility' => 1,
  );

  $export['progress_tracker-progress_tracker'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'progress_tracker',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'progress_tracker',
    'node_types' => array(
      0 => 'challenge',
      1 => 'question1',
      2 => 'webform',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -49,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'administrator' => 3,
      'webmaster' => 6,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -12,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => -10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-help'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'help',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -41,
      ),
      'seven' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -39,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -46,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -40,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -23,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user-menu',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'topmenu',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -40,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'anonymous user' => 1,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'topmenu',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -39,
      ),
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -39,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['user_alert-user_alert'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user_alert',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'user_alert',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -48,
      ),
      'seven' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'seven',
        'weight' => -42,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-01297140ea5ccce8d24f3c703da2aaa3'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '01297140ea5ccce8d24f3c703da2aaa3',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/300',
    'roles' => array(
      'expert' => 4,
      'référent' => 7,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -38,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-7d0e01b6bec26eb141930d321747febd'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => '7d0e01b6bec26eb141930d321747febd',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/300',
    'roles' => array(
      'expert' => 4,
      'référent' => 7,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -40,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-d5d704bbc8904420c5b32361a0446d81'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'd5d704bbc8904420c5b32361a0446d81',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/300',
    'roles' => array(
      'expert' => 4,
      'référent' => 7,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -36,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-entreprise_list-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'entreprise_list-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => -13,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Scope of services in aerospace',
    'visibility' => 1,
  );

  $export['views-my_responses_calls3-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'my_responses_calls3-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/300',
    'roles' => array(
      'administrator' => 3,
      'business' => 5,
      'webmaster' => 6,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -39,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-my_responses_challenges-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'my_responses_challenges-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/300',
    'roles' => array(
      'administrator' => 3,
      'business' => 5,
      'webmaster' => 6,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -37,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-my_responses_questions1-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'my_responses_questions1-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/300',
    'roles' => array(
      'administrator' => 3,
      'business' => 5,
      'webmaster' => 6,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -41,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-news_thread-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'news_thread-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'bottom',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -42,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['views-og_members-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'og_members-block_1',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -42,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-query_list-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'query_list-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'homepage
node
node/323
fr
fr/homepage
fr/node
fr/node/323',
    'roles' => array(
      'administrator' => 3,
      'expert' => 4,
      'référent' => 7,
      'webmaster' => 6,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -45,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-query_list-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'query_list-block_1',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'homepage
node
node/323
fr
fr/homepage
fr/node
fr/node/323',
    'roles' => array(
      'business' => 5,
    ),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -44,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['views-sponsors-partners_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'sponsors-partners_block',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/267',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -43,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Partners',
    'visibility' => 1,
  );

  $export['views-sponsors-sponsors_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'sponsors-sponsors_block',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'node/267',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'emindhub',
        'weight' => -42,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Sponsors',
    'visibility' => 1,
  );

  $export['views-users_list-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'users_list-block_2',
    'i18n_block_language' => array(),
    'i18n_mode' => 1,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'emindhub' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'emindhub',
        'weight' => 1,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'They are experts in eMindHub',
    'visibility' => 1,
  );

  return $export;
}
