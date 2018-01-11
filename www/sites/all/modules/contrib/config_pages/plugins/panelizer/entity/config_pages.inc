<?php
/**
 * @file
 * Definition of the paragraphs item plugin.
 */

$plugin = array(
  'handler' => 'PanelizerEntityConfigPages',
  'entity path' => NULL,
  'hooks' => array(
    'menu' => TRUE,
    'admin_paths' => TRUE,
    'permission' => TRUE,
    'panelizer_defaults' => TRUE,
    'form_alter' => TRUE,
  ),
);
