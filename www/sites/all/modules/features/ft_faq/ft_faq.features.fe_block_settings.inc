<?php
/**
 * @file
 * ft_faq.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ft_faq_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  return $export;
}
