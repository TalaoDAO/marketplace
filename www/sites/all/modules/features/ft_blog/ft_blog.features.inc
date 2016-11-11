<?php
/**
 * @file
 * ft_blog.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ft_blog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ft_blog_image_default_styles() {
  $styles = array();

  // Exported image style: publication_full.
  $styles['publication_full'] = array(
    'label' => 'Publication_full',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 790,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
