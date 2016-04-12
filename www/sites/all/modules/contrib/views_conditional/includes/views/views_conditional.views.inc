<?php

/**
 * @file
 * Include file for defining views handlers and data.
 */

/**
 * Implements hook_views_data().
 */
function views_conditional_views_data() {
  $data['views_conditional']['table']['group'] = t('Views');
  $data['views_conditional']['table']['join'] = array(
    '#global' => array(),
  );

  $data['views_conditional']['views_conditional'] = array(
    'title' => t('Views Conditional'),
    'help' => t('Output data based off of certain criteria'),
    'field' => array(
      'handler' => 'ViewsConditionalHandler',
    ),
  );

  return $data;
}
